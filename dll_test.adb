

with Ada.Characters.Handling; use Ada.Characters.Handling;
with Ada.Strings;             use Ada.Strings;
with Ada.Strings.Fixed;       use Ada.Strings.Fixed;
with Win32;
with Win32.Windef;            use Win32.Windef;
with Win32.Winbase;           use Win32.Winbase;
with Unchecked_Conversion;
with Ada.Text_IO;             use Ada.Text_IO;
with GNAT.Float_Control;
with System;                  use System;
with Interfaces.C; use Interfaces.C;
with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;

procedure dll_test is
   
   -- special interface and supporting routines to load DLLs
   DLL_LOADER_ERROR : exception;
   
   type Name_Decoration_Type is (Undecorated,
                                 Cdecl,           -- leading underscore
                                 Stdcall,         -- leading underscore, trailing @ symbol and decimal number of bytes of parameters
                                 Fastcall,        -- leading and trailing @ symbols followed by decimal number of bytes of parameters
                                 Vectorcall,      -- two trailing @@ symbols followed by decimal number of bytes of parameters
                                 Trailing_Underscore,
                                 Two_Trailing_Underscore,
                                 Upper_Case);

   type Decorate_Array is array (Name_Decoration_Type'Range) of Unbounded_String;
   Prefixes : constant Decorate_Array := (Cdecl      => To_Unbounded_String("_"),
                                          Stdcall    => To_Unbounded_String("_"),
                                          Fastcall   => To_Unbounded_String("@"),
                                          others     => To_Unbounded_String(""));

   Suffixes : constant Decorate_Array := (Stdcall                 => To_Unbounded_String("@"),
                                          Fastcall                => To_Unbounded_String("@"),
                                          Vectorcall              => To_Unbounded_String("@@"),
                                          Trailing_Underscore     => To_Unbounded_String("_"),
                                          Two_Trailing_Underscore => To_Unbounded_String("__"),
                                          others                  => To_Unbounded_String(""));

   
   type DLL_Handle is record
      Handle                : Win32.Windef.HINSTANCE := System.Null_Address;
      Name_Decoration       : Name_Decoration_Type := Undecorated;
      Name_Decoration_Found : Boolean := False;
   end record;

   Illegal_Handle : constant DLL_Handle := (Handle                => System.Null_Address,
                                            Name_Decoration       => Undecorated,
                                            Name_Decoration_Found => False);

   type C_Function_Ptr is access function return Interfaces.C.int;
   pragma Convention(C,C_Function_Ptr);
   
   -- Return pointer to C-String
   function CP
     (C_Str : char_array)
       return Win32.LPCSTR
   is
      function UC is new Unchecked_Conversion(System.Address,Win32.LPCSTR);
   begin
      return UC(C_Str(C_Str'First)'Address);
   end CP;

   -- Return pointer to C-Function
   pragma Warnings(Off, "conversion between pointers with different conventions");
   function To_C_Function_Ptr is new Unchecked_Conversion
     ( Source => FARPROC,
       Target => C_Function_Ptr);

   -- Open a DLL
   function DLL_Open
     (Filename : String)
       return DLL_Handle
   is
      C_Filename : aliased constant char_array := To_C(Filename);
      Result     : DLL_Handle;
   begin
      Result.Handle := LoadLibrary(CP(C_Filename));
      GNAT.Float_Control.Reset;

      if Result /= Illegal_Handle then
         return Result;
      else
         Put_Line(Current_Error, "DLL_Open: Cannot load library '"
                  & Filename & "' with system error code " & Win32.DWORD'Image(GetLastError));
         Flush(Current_Error);
         raise DLL_LOADER_ERROR;
      end if;
   end DLL_Open;

   -- Return pointer to Symbol inside DLL
   function DLL_Symbol
     (Handle : DLL_Handle;
      Symbol : String;
      Quiet  : Boolean := False)
       return C_Function_Ptr
   is
      C_Symbol : aliased constant char_array := To_C(Symbol);
      Result   : C_Function_Ptr;
   begin
      Result := To_C_Function_Ptr(GetProcAddress(Handle.Handle, CP(C_Symbol)));

      GNAT.Float_Control.Reset;

      if Result /= null then
         return Result;
      else
         if not Quiet then
            Put_Line(Current_Error,"DLL_Symbol: Cannot find function '"
                     & Symbol & "' in DLL, system error code is " & Win32.DWORD'Image(GetLastError));
            Flush(Current_Error);
         end if;
         raise DLL_LOADER_ERROR;
      end if;
   end DLL_Symbol;

   function Get_Naming_Convention
     (Handle : DLL_Handle)
       return String
   is
   begin
      return Name_Decoration_Type'Image(Handle.Name_Decoration);
   end Get_Naming_Convention;

   -- close DLL
   procedure DLL_Close
     (Handle : in out DLL_Handle)
   is
      Result : Win32.BOOL;
   begin
      if Handle /= Illegal_Handle then
         Result := FreeLibrary(Handle.Handle);
         GNAT.Float_Control.Reset;
         Handle := Illegal_Handle;
         if Win32."/="(Result , Win32.TRUE) then
            Put_Line(Current_Error, "DLL_Close: Error closing DLL with system error code " & Win32.DWORD'Image(GetLastError));
            Flush(Current_Error);
            raise DLL_LOADER_ERROR;
         end if;
      end if;
   end DLL_Close;   
   
   
   
   
   -- OWN DLL interface
   type DLL_Init_Ptr is access
     procedure
       (
        Base_path          :in System.Address;
        Atmos_File_Address  :in System.Address;
        Range_Ref_Path_Address         :in System.Address;
    
         
         Random_Scale_Address  :in System.Address;
         randomScaleWindHoriz :in System.Address;
         randomScaleWindVert  :in System.Address;

         solarFlux: in System.Address;
         solarFluxAv :in System.Address;
         geomagIdx  :in System.Address; 
         euvIndex  :in System.Address; 
         euvIndexAv  :in System.Address; 
         mgIndex  :in System.Address;
         mgIndexAv  :in System.Address;
         xRayIndex  :in System.Address; 
         xRayIndexAv  :in System.Address; 
         tempChange  :in System.Address;
         surfRough  :in System.Address;
               
         year  :in System.Address;
         month  :in System.Address;
         day  :in System.Address;
         hour  :in System.Address;
         min  :in System.Address;
         sec  :in System.Address

        );
   pragma Convention (C, DLL_Init_Ptr);

   type DLL_Compute_Ptr is access
     procedure
       (
        Atm_Database_Index : in System.Address;
        initonce  : in System.Address;
        hgt  : in System.Address;
        lat       : in System.Address;
        lon     : in System.Address;
        time     : in System.Address;

        dm  : in System.Address;
        pm  :in System.Address;
        tm : in System.Address;
        um : in System.Address;
        vm  : in System.Address;
        wm : in System.Address;

        dp : in System.Address;
        pp : in System.Address;
        tp : in System.Address;
        up : in System.Address;
        vp : in System.Address;
        wp : in System.Address;

        ds : in System.Address;
        ps : in System.Address;
        ts : in System.Address;
        us : in System.Address;
        vs : in System.Address;
        ws : in System.Address;

        dsm : in System.Address;
        psm : in System.Address;
        tsm : in System.Address;
        usm : in System.Address;
        vsm : in System.Address;
        wsm : in System.Address;

        sosm : in System.Address;
        sosp : in System.Address

      );
   pragma Convention (C, DLL_Compute_Ptr);

   type DLL_Finalize_Ptr is access procedure;
   pragma Convention (C, DLL_Finalize_Ptr);

   
   --RPA_Database_Index           : aliased Integer := 1;
   GRAM_Dll                      : DLL_Handle := Illegal_Handle;
   Dll_INIT                     : DLL_Init_Ptr;
   DLL_COMPUTE                  : DLL_Compute_Ptr;
   DLL_FINALIZE                 : DLL_Finalize_Ptr;

   function To_DLL_INIT_Ptr is new Unchecked_Conversion
     (Source => C_Function_Ptr,
      Target => DLL_Init_Ptr);

   function To_DLL_COMPUTE_Ptr is new Unchecked_Conversion
     (Source => C_Function_Ptr,
      Target => DLL_Compute_Ptr);

   function To_DLL_FINALIZE_Ptr is new Unchecked_Conversion
     (Source => C_Function_Ptr,
      Target => DLL_Finalize_Ptr);

begin
   put_line("Link DLL.");
   GRAM_Dll     := DLL_Open ("GRAM.dll");
   Dll_INIT     := To_DLL_INIT_Ptr (DLL_Symbol (GRAM_Dll, "createAtm"));
   DLL_COMPUTE  := To_DLL_COMPUTE_Ptr (DLL_Symbol (GRAM_Dll, "runAtm"));
   DLL_FINALIZE :=    To_DLL_FINALIZE_Ptr (DLL_Symbol (GRAM_Dll, "finalize"));

   put_line("Init DLL.");
    declare
        -- define all input and output variables as follows
        Base_path          : constant String := "C:\\Users\\vic-b\\Documents\\Victors\\Job\\Astos\\project\\EarthGRAM2016Version2\\EarthGRAM2016Version2.0\\";
        Atmos_File_Address         : constant String := "C:\\Users\\vic-b\\Documents\\Victors\\Job\\Astos\\project\\EarthGRAM2016Version2\\EarthGRAM2016Version2.0\\IOfiles\\";
        Range_Ref_Path_Address              : constant String := "C:\\Users\\vic-b\\Documents\\Victors\\Job\\Astos\\project\\EarthGRAM2016Version2\\EarthGRAM2016Version2.0\\RRAdata\\";

        Random_Scale_Address : aliased Integer := 1;
        randomScaleWindHoriz : aliased Integer := 1;
        randomScaleWindVert : aliased Integer := 1;




        solarFlux : aliased Long_Float :=  230.0;
        solarFluxAv :  aliased Long_Float := 230.0;  
        geomagIdx  : aliased Long_Float := 16.31; 
        euvIndex  : aliased Long_Float := 0.0; 
        euvIndexAv  : aliased Long_Float := 0.0; 
        mgIndex  : aliased Long_Float := 0.0;
        mgIndexAv  : aliased Long_Float := 0.0;
        xRayIndex  : aliased Long_Float := 0.0;
        xRayIndexAv : aliased Long_Float := 0.0;
        tempChange : aliased Long_Float := 0.0;
        surfRough  : aliased Long_Float := 0.0;
				
        year  :  aliased Integer := 2018;
	     month : aliased Integer := 1;
		  day  : aliased Integer := 1;
		  hour  :aliased Integer  := 0;
		  min  :aliased Integer := 0;
		  sec  :aliased Long_Float := 0.0;


   begin        

      Dll_INIT(    Interfaces.C.To_C(Base_path)'Address,
                   Interfaces.C.To_C(Atmos_File_Address)'Address,
                   Interfaces.C.To_C(Range_Ref_Path_Address)'Address,
                     Random_Scale_Address'Address,
                     randomScaleWindHoriz'Address,
                     randomScaleWindVert'Address,
                     solarFlux'Address,
                     solarFluxAv 'Address,
                     geomagIdx'Address,
                     euvIndex'Address,
                     euvIndexAv'Address,
                     mgIndex'Address,
                     mgIndexAv'Address,
                     xRayIndex'Address, 
                     xRayIndexAv'Address,
                     tempChange'Address,
                     surfRough'Address,
                           
                     year'Address,
                     month'Address,
                     day'Address,
                     hour'Address,
                     min'Address,
                     sec'Address
                   );
      GNAT.Float_Control.Reset;
   end;
   


   put_line("Compute DLL.");
   declare
      -- define all input and output variables as follows
      Atm_Database_Index          : aliased Integer := 0;
      initonce          : aliased Integer := 1;
      hgt  : aliased Long_Float := 50.0;
      lat              : aliased Long_Float := 10.0;
      lon              : aliased Long_Float := 10.0;
      time              : aliased Long_Float := 10.0;


      dm  : aliased Long_Float; 
      pm  : aliased Long_Float; 
      tm : aliased Long_Float;
      um : aliased Long_Float; 
      vm  : aliased Long_Float; 
      wm : aliased Long_Float;

      dp : aliased Long_Float;
      pp : aliased Long_Float;
      tp : aliased Long_Float;
      up : aliased Long_Float;
      vp : aliased Long_Float;
      wp : aliased Long_Float;

      ds : aliased Long_Float;
      ps : aliased Long_Float; 
      ts : aliased Long_Float;
      us : aliased Long_Float;
      vs : aliased Long_Float;
      ws : aliased Long_Float;

      dsm : aliased Long_Float;
      psm : aliased Long_Float;
      tsm : aliased Long_Float; 
	  usm : aliased Long_Float;
      vsm : aliased Long_Float; 
      wsm : aliased Long_Float;

      sosm : aliased Long_Float;
      sosp : aliased Long_Float;

   begin
      DLL_COMPUTE(
                  Atm_Database_Index'Address,
                  initonce'Address,
                  hgt'Address,
                  lat'Address,
                  lon'Address,
                  time'Address,

                  dm'Address,
                  pm'Address,
                  tm'Address,
                  um'Address,
                  vm'Address,
                  wm'Address,

                  dp'Address,
                  pp'Address,
                  tp'Address,
                  up'Address,
                  vp'Address,
                  wp'Address,

                  ds'Address,
                  ps'Address, 
                  ts'Address,
                  us'Address,
                  vs'Address,
                  ws'Address,

                  dsm'Address,
                  psm'Address,
                  tsm'Address,
                  usm'Address,
                  vsm'Address,
                  wsm'Address,
                  
                  sosm'Address,
                  sosp'Address                               
                  );
      GNAT.Float_Control.Reset;
      put_line("Compute Done.");
--put_line("compute End: " & C_Star'img);
   end;
   
   
   put_line("Close DLL.");
   DLL_Close (GRAM_Dll);
   
   put_line("Done.");
end dll_test;
