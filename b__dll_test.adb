pragma Ada_95;
pragma Source_File_Name (ada_main, Spec_File_Name => "b__dll_test.ads");
pragma Source_File_Name (ada_main, Body_File_Name => "b__dll_test.adb");
with Ada.Exceptions;

package body ada_main is
   pragma Warnings (Off);

   E018 : Short_Integer; pragma Import (Ada, E018, "system__soft_links_E");
   E012 : Short_Integer; pragma Import (Ada, E012, "system__exception_table_E");
   E082 : Short_Integer; pragma Import (Ada, E082, "ada__io_exceptions_E");
   E009 : Short_Integer; pragma Import (Ada, E009, "ada__strings_E");
   E050 : Short_Integer; pragma Import (Ada, E050, "ada__strings__maps_E");
   E053 : Short_Integer; pragma Import (Ada, E053, "ada__strings__maps__constants_E");
   E061 : Short_Integer; pragma Import (Ada, E061, "ada__tags_E");
   E075 : Short_Integer; pragma Import (Ada, E075, "ada__streams_E");
   E101 : Short_Integer; pragma Import (Ada, E101, "interfaces__c_E");
   E103 : Short_Integer; pragma Import (Ada, E103, "interfaces__c__strings_E");
   E022 : Short_Integer; pragma Import (Ada, E022, "system__secondary_stack_E");
   E077 : Short_Integer; pragma Import (Ada, E077, "system__finalization_root_E");
   E074 : Short_Integer; pragma Import (Ada, E074, "ada__finalization_E");
   E059 : Short_Integer; pragma Import (Ada, E059, "ada__strings__unbounded_E");
   E094 : Short_Integer; pragma Import (Ada, E094, "system__storage_pools_E");
   E086 : Short_Integer; pragma Import (Ada, E086, "ada__finalization__heap_management_E");
   E106 : Short_Integer; pragma Import (Ada, E106, "system__os_lib_E");
   E111 : Short_Integer; pragma Import (Ada, E111, "system__pool_global_E");
   E109 : Short_Integer; pragma Import (Ada, E109, "system__file_control_block_E");
   E099 : Short_Integer; pragma Import (Ada, E099, "system__file_io_E");
   E084 : Short_Integer; pragma Import (Ada, E084, "ada__text_io_E");
   E127 : Short_Integer; pragma Import (Ada, E127, "stdarg_E");
   E129 : Short_Integer; pragma Import (Ada, E129, "stdarg__impl_E");
   E123 : Short_Integer; pragma Import (Ada, E123, "win32_E");
   E133 : Short_Integer; pragma Import (Ada, E133, "win32__utils_E");
   E135 : Short_Integer; pragma Import (Ada, E135, "win32__winnt_E");
   E131 : Short_Integer; pragma Import (Ada, E131, "win32__windef_E");
   E125 : Short_Integer; pragma Import (Ada, E125, "win32__winbase_E");

   Local_Priority_Specific_Dispatching : constant String := "";
   Local_Interrupt_States : constant String := "";

   Is_Elaborated : Boolean := False;

   procedure finalize_library is
      LE_Set : Boolean;
      pragma Import (Ada, LE_Set, "__gnat_library_exception_set");
   begin
      E127 := E127 - 1;
      declare
         procedure F1;
         pragma Import (Ada, F1, "stdarg__finalize_spec");
      begin
         F1;
      end;
      declare
         procedure F2;
         pragma Import (Ada, F2, "ada__text_io__finalize_body");
      begin
         E084 := E084 - 1;
         F2;
      end;
      declare
         procedure F3;
         pragma Import (Ada, F3, "ada__text_io__finalize_spec");
      begin
         F3;
      end;
      declare
         procedure F4;
         pragma Import (Ada, F4, "system__file_io__finalize_body");
      begin
         E099 := E099 - 1;
         F4;
      end;
      declare
         procedure F5;
         pragma Import (Ada, F5, "system__file_control_block__finalize_spec");
      begin
         E109 := E109 - 1;
         F5;
      end;
      E111 := E111 - 1;
      declare
         procedure F6;
         pragma Import (Ada, F6, "system__pool_global__finalize_spec");
      begin
         F6;
      end;
      E086 := E086 - 1;
      declare
         procedure F7;
         pragma Import (Ada, F7, "ada__finalization__heap_management__finalize_spec");
      begin
         F7;
      end;
      E059 := E059 - 1;
      declare
         procedure F8;
         pragma Import (Ada, F8, "ada__strings__unbounded__finalize_spec");
      begin
         F8;
      end;
      E077 := E077 - 1;
      declare
         procedure F9;
         pragma Import (Ada, F9, "system__finalization_root__finalize_spec");
      begin
         F9;
      end;
      if LE_Set then
         declare
            LE : Ada.Exceptions.Exception_Occurrence;
            pragma Import (Ada, LE, "__gnat_library_exception");
            procedure Raise_From_Controlled_Operation (X : Ada.Exceptions.Exception_Occurrence;  From_Abort : Boolean);
            pragma Import (Ada, Raise_From_Controlled_Operation, "__gnat_raise_from_controlled_operation");
         begin
            Raise_From_Controlled_Operation (LE, False);
         end;
      end if;
   end finalize_library;

   procedure adafinal is
      procedure s_stalib_adafinal;
      pragma Import (C, s_stalib_adafinal, "system__standard_library__adafinal");
   begin
      if not Is_Elaborated then
         return;
      end if;
      Is_Elaborated := False;
      s_stalib_adafinal;
   end adafinal;

   type No_Param_Proc is access procedure;

   procedure adainit is
      Main_Priority : Integer;
      pragma Import (C, Main_Priority, "__gl_main_priority");
      Time_Slice_Value : Integer;
      pragma Import (C, Time_Slice_Value, "__gl_time_slice_val");
      WC_Encoding : Character;
      pragma Import (C, WC_Encoding, "__gl_wc_encoding");
      Locking_Policy : Character;
      pragma Import (C, Locking_Policy, "__gl_locking_policy");
      Queuing_Policy : Character;
      pragma Import (C, Queuing_Policy, "__gl_queuing_policy");
      Task_Dispatching_Policy : Character;
      pragma Import (C, Task_Dispatching_Policy, "__gl_task_dispatching_policy");
      Priority_Specific_Dispatching : System.Address;
      pragma Import (C, Priority_Specific_Dispatching, "__gl_priority_specific_dispatching");
      Num_Specific_Dispatching : Integer;
      pragma Import (C, Num_Specific_Dispatching, "__gl_num_specific_dispatching");
      Main_CPU : Integer;
      pragma Import (C, Main_CPU, "__gl_main_cpu");
      Interrupt_States : System.Address;
      pragma Import (C, Interrupt_States, "__gl_interrupt_states");
      Num_Interrupt_States : Integer;
      pragma Import (C, Num_Interrupt_States, "__gl_num_interrupt_states");
      Unreserve_All_Interrupts : Integer;
      pragma Import (C, Unreserve_All_Interrupts, "__gl_unreserve_all_interrupts");
      Zero_Cost_Exceptions : Integer;
      pragma Import (C, Zero_Cost_Exceptions, "__gl_zero_cost_exceptions");
      Detect_Blocking : Integer;
      pragma Import (C, Detect_Blocking, "__gl_detect_blocking");
      Default_Stack_Size : Integer;
      pragma Import (C, Default_Stack_Size, "__gl_default_stack_size");
      Leap_Seconds_Support : Integer;
      pragma Import (C, Leap_Seconds_Support, "__gl_leap_seconds_support");

      procedure Install_Handler;
      pragma Import (C, Install_Handler, "__gnat_install_handler");

      Handler_Installed : Integer;
      pragma Import (C, Handler_Installed, "__gnat_handler_installed");

      Finalize_Library_Objects : No_Param_Proc;
      pragma Import (C, Finalize_Library_Objects, "__gnat_finalize_library_objects");
   begin
      if Is_Elaborated then
         return;
      end if;
      Is_Elaborated := True;
      Main_Priority := -1;
      Time_Slice_Value := -1;
      WC_Encoding := 'b';
      Locking_Policy := ' ';
      Queuing_Policy := ' ';
      Task_Dispatching_Policy := ' ';
      Priority_Specific_Dispatching :=
        Local_Priority_Specific_Dispatching'Address;
      Num_Specific_Dispatching := 0;
      Main_CPU := -1;
      Interrupt_States := Local_Interrupt_States'Address;
      Num_Interrupt_States := 0;
      Unreserve_All_Interrupts := 0;
      Zero_Cost_Exceptions := 1;
      Detect_Blocking := 0;
      Default_Stack_Size := -1;
      Leap_Seconds_Support := 0;

      if Handler_Installed = 0 then
         Install_Handler;
      end if;

      Finalize_Library_Objects := finalize_library'access;

      System.Soft_Links'Elab_Spec;
      System.Exception_Table'Elab_Body;
      E012 := E012 + 1;
      Ada.Io_Exceptions'Elab_Spec;
      E082 := E082 + 1;
      Ada.Strings'Elab_Spec;
      E009 := E009 + 1;
      Ada.Strings.Maps'Elab_Spec;
      Ada.Strings.Maps.Constants'Elab_Spec;
      E053 := E053 + 1;
      Ada.Tags'Elab_Spec;
      Ada.Streams'Elab_Spec;
      E075 := E075 + 1;
      Interfaces.C'Elab_Spec;
      Interfaces.C.Strings'Elab_Spec;
      E103 := E103 + 1;
      E101 := E101 + 1;
      Ada.Tags'Elab_Body;
      E061 := E061 + 1;
      E050 := E050 + 1;
      System.Soft_Links'Elab_Body;
      E018 := E018 + 1;
      System.Secondary_Stack'Elab_Body;
      E022 := E022 + 1;
      System.Finalization_Root'Elab_Spec;
      E077 := E077 + 1;
      Ada.Finalization'Elab_Spec;
      E074 := E074 + 1;
      Ada.Strings.Unbounded'Elab_Spec;
      E059 := E059 + 1;
      System.Storage_Pools'Elab_Spec;
      E094 := E094 + 1;
      Ada.Finalization.Heap_Management'Elab_Spec;
      E086 := E086 + 1;
      System.Os_Lib'Elab_Body;
      E106 := E106 + 1;
      System.Pool_Global'Elab_Spec;
      E111 := E111 + 1;
      System.File_Control_Block'Elab_Spec;
      E109 := E109 + 1;
      System.File_Io'Elab_Body;
      E099 := E099 + 1;
      Ada.Text_Io'Elab_Spec;
      Ada.Text_Io'Elab_Body;
      E084 := E084 + 1;
      Stdarg'Elab_Spec;
      E127 := E127 + 1;
      Stdarg.Impl'Elab_Spec;
      E129 := E129 + 1;
      E123 := E123 + 1;
      E133 := E133 + 1;
      Win32.Winnt'Elab_Spec;
      Win32.Winnt'Elab_Body;
      E135 := E135 + 1;
      E131 := E131 + 1;
      E125 := E125 + 1;
   end adainit;

   procedure Ada_Main_Program;
   pragma Import (Ada, Ada_Main_Program, "_ada_dll_test");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer
   is
      procedure Initialize (Addr : System.Address);
      pragma Import (C, Initialize, "__gnat_initialize");

      procedure Finalize;
      pragma Import (C, Finalize, "__gnat_finalize");
      SEH : aliased array (1 .. 2) of Integer;

      Ensure_Reference : aliased System.Address := Ada_Main_Program_Name'Address;
      pragma Volatile (Ensure_Reference);

   begin
      gnat_argc := argc;
      gnat_argv := argv;
      gnat_envp := envp;

      Initialize (SEH'Address);
      adainit;
      Ada_Main_Program;
      adafinal;
      Finalize;
      return (gnat_exit_status);
   end;

--  BEGIN Object file/option list
   --   C:\Users\vic-b\Documents\Victors\Job\Astos\project\DLL\dll_test.o
   --   -LC:\Users\vic-b\Documents\Victors\Job\Astos\project\DLL\
   --   -LC:\GNAT\2011\lib\win32ada\static\
   --   -LC:/gnat/2011/lib/gcc/i686-pc-mingw32/4.5.3/adalib/
   --   -lwin32ada
   --   -luser32
   --   -lgdi32
   --   -lcomdlg32
   --   -static
   --   -lgnat
   --   -Wl,--stack=0x2000000
--  END Object file/option list   

end ada_main;
