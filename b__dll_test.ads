pragma Ada_95;
with System;
package ada_main is
   pragma Warnings (Off);

   gnat_argc : Integer;
   gnat_argv : System.Address;
   gnat_envp : System.Address;

   pragma Import (C, gnat_argc);
   pragma Import (C, gnat_argv);
   pragma Import (C, gnat_envp);

   gnat_exit_status : Integer;
   pragma Import (C, gnat_exit_status);

   GNAT_Version : constant String :=
                    "GNAT Version: GPL 2011 (20110428)" & ASCII.NUL;
   pragma Export (C, GNAT_Version, "__gnat_version");

   Ada_Main_Program_Name : constant String := "_ada_dll_test" & ASCII.NUL;
   pragma Export (C, Ada_Main_Program_Name, "__gnat_ada_main_program_name");

   procedure adainit;
   pragma Export (C, adainit, "adainit");

   procedure adafinal;
   pragma Export (C, adafinal, "adafinal");

   function main
     (argc : Integer;
      argv : System.Address;
      envp : System.Address)
      return Integer;
   pragma Export (C, main, "main");

   type Version_32 is mod 2 ** 32;
   u00001 : constant Version_32 := 16#5f064c4a#;
   pragma Export (C, u00001, "dll_testB");
   u00002 : constant Version_32 := 16#7d892fe9#;
   pragma Export (C, u00002, "system__standard_libraryB");
   u00003 : constant Version_32 := 16#b2760b05#;
   pragma Export (C, u00003, "system__standard_libraryS");
   u00004 : constant Version_32 := 16#3ffc8e18#;
   pragma Export (C, u00004, "adaS");
   u00005 : constant Version_32 := 16#12c24a43#;
   pragma Export (C, u00005, "ada__charactersS");
   u00006 : constant Version_32 := 16#833355f1#;
   pragma Export (C, u00006, "ada__characters__handlingB");
   u00007 : constant Version_32 := 16#3006d996#;
   pragma Export (C, u00007, "ada__characters__handlingS");
   u00008 : constant Version_32 := 16#051b1b7b#;
   pragma Export (C, u00008, "ada__characters__latin_1S");
   u00009 : constant Version_32 := 16#af50e98f#;
   pragma Export (C, u00009, "ada__stringsS");
   u00010 : constant Version_32 := 16#bc164b96#;
   pragma Export (C, u00010, "systemS");
   u00011 : constant Version_32 := 16#53547b86#;
   pragma Export (C, u00011, "system__exception_tableB");
   u00012 : constant Version_32 := 16#2d789733#;
   pragma Export (C, u00012, "system__exception_tableS");
   u00013 : constant Version_32 := 16#ff3fa16b#;
   pragma Export (C, u00013, "system__htableB");
   u00014 : constant Version_32 := 16#53c9e749#;
   pragma Export (C, u00014, "system__htableS");
   u00015 : constant Version_32 := 16#8b7dad61#;
   pragma Export (C, u00015, "system__string_hashB");
   u00016 : constant Version_32 := 16#9a8a9302#;
   pragma Export (C, u00016, "system__string_hashS");
   u00017 : constant Version_32 := 16#360d120c#;
   pragma Export (C, u00017, "system__soft_linksB");
   u00018 : constant Version_32 := 16#c254e109#;
   pragma Export (C, u00018, "system__soft_linksS");
   u00019 : constant Version_32 := 16#92dc3a55#;
   pragma Export (C, u00019, "system__parametersB");
   u00020 : constant Version_32 := 16#bfbc7097#;
   pragma Export (C, u00020, "system__parametersS");
   u00021 : constant Version_32 := 16#1907a5d3#;
   pragma Export (C, u00021, "system__secondary_stackB");
   u00022 : constant Version_32 := 16#a8786c38#;
   pragma Export (C, u00022, "system__secondary_stackS");
   u00023 : constant Version_32 := 16#ace32e1e#;
   pragma Export (C, u00023, "system__storage_elementsB");
   u00024 : constant Version_32 := 16#46db360e#;
   pragma Export (C, u00024, "system__storage_elementsS");
   u00025 : constant Version_32 := 16#08dd46b8#;
   pragma Export (C, u00025, "ada__exceptionsB");
   u00026 : constant Version_32 := 16#9b58bcb3#;
   pragma Export (C, u00026, "ada__exceptionsS");
   u00027 : constant Version_32 := 16#52aba3be#;
   pragma Export (C, u00027, "ada__exceptions__last_chance_handlerB");
   u00028 : constant Version_32 := 16#48e7b9e5#;
   pragma Export (C, u00028, "ada__exceptions__last_chance_handlerS");
   u00029 : constant Version_32 := 16#6a8a6a74#;
   pragma Export (C, u00029, "system__exceptionsB");
   u00030 : constant Version_32 := 16#2aa87202#;
   pragma Export (C, u00030, "system__exceptionsS");
   u00031 : constant Version_32 := 16#b012ff50#;
   pragma Export (C, u00031, "system__img_intB");
   u00032 : constant Version_32 := 16#becdab54#;
   pragma Export (C, u00032, "system__img_intS");
   u00033 : constant Version_32 := 16#dc8e33ed#;
   pragma Export (C, u00033, "system__tracebackB");
   u00034 : constant Version_32 := 16#dd919fe3#;
   pragma Export (C, u00034, "system__tracebackS");
   u00035 : constant Version_32 := 16#d6f717e0#;
   pragma Export (C, u00035, "system__unsigned_typesS");
   u00036 : constant Version_32 := 16#907d882f#;
   pragma Export (C, u00036, "system__wch_conB");
   u00037 : constant Version_32 := 16#03fd65ab#;
   pragma Export (C, u00037, "system__wch_conS");
   u00038 : constant Version_32 := 16#22fed88a#;
   pragma Export (C, u00038, "system__wch_stwB");
   u00039 : constant Version_32 := 16#2eec49aa#;
   pragma Export (C, u00039, "system__wch_stwS");
   u00040 : constant Version_32 := 16#5d4d477e#;
   pragma Export (C, u00040, "system__wch_cnvB");
   u00041 : constant Version_32 := 16#1d03e37d#;
   pragma Export (C, u00041, "system__wch_cnvS");
   u00042 : constant Version_32 := 16#f77d8799#;
   pragma Export (C, u00042, "interfacesS");
   u00043 : constant Version_32 := 16#75729fba#;
   pragma Export (C, u00043, "system__wch_jisB");
   u00044 : constant Version_32 := 16#49717869#;
   pragma Export (C, u00044, "system__wch_jisS");
   u00045 : constant Version_32 := 16#ada34a87#;
   pragma Export (C, u00045, "system__traceback_entriesB");
   u00046 : constant Version_32 := 16#ee37a5d7#;
   pragma Export (C, u00046, "system__traceback_entriesS");
   u00047 : constant Version_32 := 16#4f750b3b#;
   pragma Export (C, u00047, "system__stack_checkingB");
   u00048 : constant Version_32 := 16#1fb4f7ba#;
   pragma Export (C, u00048, "system__stack_checkingS");
   u00049 : constant Version_32 := 16#96e9c1e7#;
   pragma Export (C, u00049, "ada__strings__mapsB");
   u00050 : constant Version_32 := 16#24318e4c#;
   pragma Export (C, u00050, "ada__strings__mapsS");
   u00051 : constant Version_32 := 16#63c123de#;
   pragma Export (C, u00051, "system__bit_opsB");
   u00052 : constant Version_32 := 16#c30e4013#;
   pragma Export (C, u00052, "system__bit_opsS");
   u00053 : constant Version_32 := 16#7a69aa90#;
   pragma Export (C, u00053, "ada__strings__maps__constantsS");
   u00054 : constant Version_32 := 16#914b496f#;
   pragma Export (C, u00054, "ada__strings__fixedB");
   u00055 : constant Version_32 := 16#dc686502#;
   pragma Export (C, u00055, "ada__strings__fixedS");
   u00056 : constant Version_32 := 16#574e372d#;
   pragma Export (C, u00056, "ada__strings__searchB");
   u00057 : constant Version_32 := 16#b5a8c1d6#;
   pragma Export (C, u00057, "ada__strings__searchS");
   u00058 : constant Version_32 := 16#261c554b#;
   pragma Export (C, u00058, "ada__strings__unboundedB");
   u00059 : constant Version_32 := 16#762d3000#;
   pragma Export (C, u00059, "ada__strings__unboundedS");
   u00060 : constant Version_32 := 16#8332779a#;
   pragma Export (C, u00060, "ada__tagsB");
   u00061 : constant Version_32 := 16#02144d76#;
   pragma Export (C, u00061, "ada__tagsS");
   u00062 : constant Version_32 := 16#e6965fe6#;
   pragma Export (C, u00062, "system__val_unsB");
   u00063 : constant Version_32 := 16#c65ffadb#;
   pragma Export (C, u00063, "system__val_unsS");
   u00064 : constant Version_32 := 16#46a1f7a9#;
   pragma Export (C, u00064, "system__val_utilB");
   u00065 : constant Version_32 := 16#b7bbde89#;
   pragma Export (C, u00065, "system__val_utilS");
   u00066 : constant Version_32 := 16#b7fa72e7#;
   pragma Export (C, u00066, "system__case_utilB");
   u00067 : constant Version_32 := 16#110a2b1e#;
   pragma Export (C, u00067, "system__case_utilS");
   u00068 : constant Version_32 := 16#c4857ee1#;
   pragma Export (C, u00068, "system__compare_array_unsigned_8B");
   u00069 : constant Version_32 := 16#662dbd5b#;
   pragma Export (C, u00069, "system__compare_array_unsigned_8S");
   u00070 : constant Version_32 := 16#9d3d925a#;
   pragma Export (C, u00070, "system__address_operationsB");
   u00071 : constant Version_32 := 16#7c68a201#;
   pragma Export (C, u00071, "system__address_operationsS");
   u00072 : constant Version_32 := 16#86099d09#;
   pragma Export (C, u00072, "system__machine_codeS");
   u00073 : constant Version_32 := 16#6d616d1b#;
   pragma Export (C, u00073, "ada__finalizationB");
   u00074 : constant Version_32 := 16#a11701ff#;
   pragma Export (C, u00074, "ada__finalizationS");
   u00075 : constant Version_32 := 16#1358602f#;
   pragma Export (C, u00075, "ada__streamsS");
   u00076 : constant Version_32 := 16#f7ab51aa#;
   pragma Export (C, u00076, "system__finalization_rootB");
   u00077 : constant Version_32 := 16#bd6af943#;
   pragma Export (C, u00077, "system__finalization_rootS");
   u00078 : constant Version_32 := 16#e033c94e#;
   pragma Export (C, u00078, "system__atomic_countersB");
   u00079 : constant Version_32 := 16#4a8d2d3a#;
   pragma Export (C, u00079, "system__atomic_countersS");
   u00080 : constant Version_32 := 16#a6e358bc#;
   pragma Export (C, u00080, "system__stream_attributesB");
   u00081 : constant Version_32 := 16#e89b4b3f#;
   pragma Export (C, u00081, "system__stream_attributesS");
   u00082 : constant Version_32 := 16#b46168d5#;
   pragma Export (C, u00082, "ada__io_exceptionsS");
   u00083 : constant Version_32 := 16#7a8f4ce5#;
   pragma Export (C, u00083, "ada__text_ioB");
   u00084 : constant Version_32 := 16#e76e8bfb#;
   pragma Export (C, u00084, "ada__text_ioS");
   u00085 : constant Version_32 := 16#339a1fb2#;
   pragma Export (C, u00085, "ada__finalization__heap_managementB");
   u00086 : constant Version_32 := 16#b0f96d78#;
   pragma Export (C, u00086, "ada__finalization__heap_managementS");
   u00087 : constant Version_32 := 16#57a37a42#;
   pragma Export (C, u00087, "system__address_imageB");
   u00088 : constant Version_32 := 16#1dfad6ac#;
   pragma Export (C, u00088, "system__address_imageS");
   u00089 : constant Version_32 := 16#7268f812#;
   pragma Export (C, u00089, "system__img_boolB");
   u00090 : constant Version_32 := 16#49cf3a7d#;
   pragma Export (C, u00090, "system__img_boolS");
   u00091 : constant Version_32 := 16#d7aac20c#;
   pragma Export (C, u00091, "system__ioB");
   u00092 : constant Version_32 := 16#2254bcd9#;
   pragma Export (C, u00092, "system__ioS");
   u00093 : constant Version_32 := 16#d21112bd#;
   pragma Export (C, u00093, "system__storage_poolsB");
   u00094 : constant Version_32 := 16#a9b91ff2#;
   pragma Export (C, u00094, "system__storage_poolsS");
   u00095 : constant Version_32 := 16#7a48d8b1#;
   pragma Export (C, u00095, "interfaces__c_streamsB");
   u00096 : constant Version_32 := 16#40dd1af2#;
   pragma Export (C, u00096, "interfaces__c_streamsS");
   u00097 : constant Version_32 := 16#13cbc1ce#;
   pragma Export (C, u00097, "system__crtlS");
   u00098 : constant Version_32 := 16#efe3a128#;
   pragma Export (C, u00098, "system__file_ioB");
   u00099 : constant Version_32 := 16#b1614c7b#;
   pragma Export (C, u00099, "system__file_ioS");
   u00100 : constant Version_32 := 16#769e25e6#;
   pragma Export (C, u00100, "interfaces__cB");
   u00101 : constant Version_32 := 16#a0f6ad03#;
   pragma Export (C, u00101, "interfaces__cS");
   u00102 : constant Version_32 := 16#b3abd60c#;
   pragma Export (C, u00102, "interfaces__c__stringsB");
   u00103 : constant Version_32 := 16#603c1c44#;
   pragma Export (C, u00103, "interfaces__c__stringsS");
   u00104 : constant Version_32 := 16#a50435f4#;
   pragma Export (C, u00104, "system__crtl__runtimeS");
   u00105 : constant Version_32 := 16#9cd5d2c4#;
   pragma Export (C, u00105, "system__os_libB");
   u00106 : constant Version_32 := 16#a6d80a38#;
   pragma Export (C, u00106, "system__os_libS");
   u00107 : constant Version_32 := 16#4cd8aca0#;
   pragma Export (C, u00107, "system__stringsB");
   u00108 : constant Version_32 := 16#0bfc0152#;
   pragma Export (C, u00108, "system__stringsS");
   u00109 : constant Version_32 := 16#6329a5ac#;
   pragma Export (C, u00109, "system__file_control_blockS");
   u00110 : constant Version_32 := 16#ebb6b8da#;
   pragma Export (C, u00110, "system__pool_globalB");
   u00111 : constant Version_32 := 16#f2b3b4b1#;
   pragma Export (C, u00111, "system__pool_globalS");
   u00112 : constant Version_32 := 16#67335317#;
   pragma Export (C, u00112, "system__memoryB");
   u00113 : constant Version_32 := 16#769df783#;
   pragma Export (C, u00113, "system__memoryS");
   u00114 : constant Version_32 := 16#fd2ad2f1#;
   pragma Export (C, u00114, "gnatS");
   u00115 : constant Version_32 := 16#fe9eadfa#;
   pragma Export (C, u00115, "gnat__float_controlS");
   u00116 : constant Version_32 := 16#1b28662b#;
   pragma Export (C, u00116, "system__float_controlB");
   u00117 : constant Version_32 := 16#5cea08aa#;
   pragma Export (C, u00117, "system__float_controlS");
   u00118 : constant Version_32 := 16#1eab0e09#;
   pragma Export (C, u00118, "system__img_enum_newB");
   u00119 : constant Version_32 := 16#3b118066#;
   pragma Export (C, u00119, "system__img_enum_newS");
   u00120 : constant Version_32 := 16#194ccd7b#;
   pragma Export (C, u00120, "system__img_unsB");
   u00121 : constant Version_32 := 16#49032b17#;
   pragma Export (C, u00121, "system__img_unsS");
   u00122 : constant Version_32 := 16#d2da9fa7#;
   pragma Export (C, u00122, "win32B");
   u00123 : constant Version_32 := 16#827e156a#;
   pragma Export (C, u00123, "win32S");
   u00124 : constant Version_32 := 16#31c5d18c#;
   pragma Export (C, u00124, "win32__winbaseB");
   u00125 : constant Version_32 := 16#27ac2dcb#;
   pragma Export (C, u00125, "win32__winbaseS");
   u00126 : constant Version_32 := 16#94e1d790#;
   pragma Export (C, u00126, "stdargB");
   u00127 : constant Version_32 := 16#a988e931#;
   pragma Export (C, u00127, "stdargS");
   u00128 : constant Version_32 := 16#47f61fde#;
   pragma Export (C, u00128, "stdarg__implB");
   u00129 : constant Version_32 := 16#5118d42f#;
   pragma Export (C, u00129, "stdarg__implS");
   u00130 : constant Version_32 := 16#72185823#;
   pragma Export (C, u00130, "win32__windefB");
   u00131 : constant Version_32 := 16#5ff5afff#;
   pragma Export (C, u00131, "win32__windefS");
   u00132 : constant Version_32 := 16#b0a7d851#;
   pragma Export (C, u00132, "win32__utilsB");
   u00133 : constant Version_32 := 16#6578987b#;
   pragma Export (C, u00133, "win32__utilsS");
   u00134 : constant Version_32 := 16#ad94948d#;
   pragma Export (C, u00134, "win32__winntB");
   u00135 : constant Version_32 := 16#e7d9d1f4#;
   pragma Export (C, u00135, "win32__winntS");
   --  BEGIN ELABORATION ORDER
   --  ada%s
   --  ada.characters%s
   --  ada.characters.handling%s
   --  ada.characters.latin_1%s
   --  gnat%s
   --  interfaces%s
   --  system%s
   --  system.address_operations%s
   --  system.address_operations%b
   --  system.atomic_counters%s
   --  system.case_util%s
   --  system.case_util%b
   --  system.float_control%s
   --  system.float_control%b
   --  gnat.float_control%s
   --  system.htable%s
   --  system.img_bool%s
   --  system.img_bool%b
   --  system.img_enum_new%s
   --  system.img_enum_new%b
   --  system.img_int%s
   --  system.img_int%b
   --  system.io%s
   --  system.io%b
   --  system.machine_code%s
   --  system.atomic_counters%b
   --  system.parameters%s
   --  system.parameters%b
   --  system.crtl%s
   --  interfaces.c_streams%s
   --  interfaces.c_streams%b
   --  system.standard_library%s
   --  system.exceptions%s
   --  system.exceptions%b
   --  system.storage_elements%s
   --  system.storage_elements%b
   --  system.stack_checking%s
   --  system.stack_checking%b
   --  system.string_hash%s
   --  system.string_hash%b
   --  system.htable%b
   --  system.strings%s
   --  system.strings%b
   --  system.traceback_entries%s
   --  system.traceback_entries%b
   --  ada.exceptions%s
   --  system.soft_links%s
   --  system.unsigned_types%s
   --  system.img_uns%s
   --  system.img_uns%b
   --  system.val_uns%s
   --  system.val_util%s
   --  system.val_util%b
   --  system.val_uns%b
   --  system.wch_con%s
   --  system.wch_con%b
   --  system.wch_cnv%s
   --  system.wch_jis%s
   --  system.wch_jis%b
   --  system.wch_cnv%b
   --  system.wch_stw%s
   --  system.wch_stw%b
   --  ada.exceptions.last_chance_handler%s
   --  ada.exceptions.last_chance_handler%b
   --  system.address_image%s
   --  system.bit_ops%s
   --  system.bit_ops%b
   --  system.compare_array_unsigned_8%s
   --  system.compare_array_unsigned_8%b
   --  system.exception_table%s
   --  system.exception_table%b
   --  ada.io_exceptions%s
   --  ada.strings%s
   --  ada.strings.maps%s
   --  ada.strings.fixed%s
   --  ada.strings.maps.constants%s
   --  ada.strings.search%s
   --  ada.strings.search%b
   --  ada.tags%s
   --  ada.streams%s
   --  interfaces.c%s
   --  interfaces.c.strings%s
   --  system.crtl.runtime%s
   --  system.stream_attributes%s
   --  system.stream_attributes%b
   --  system.memory%s
   --  system.memory%b
   --  system.standard_library%b
   --  system.secondary_stack%s
   --  interfaces.c.strings%b
   --  interfaces.c%b
   --  ada.tags%b
   --  ada.strings.fixed%b
   --  ada.strings.maps%b
   --  system.soft_links%b
   --  ada.characters.handling%b
   --  system.secondary_stack%b
   --  system.address_image%b
   --  system.finalization_root%s
   --  system.finalization_root%b
   --  ada.finalization%s
   --  ada.finalization%b
   --  ada.strings.unbounded%s
   --  ada.strings.unbounded%b
   --  system.storage_pools%s
   --  system.storage_pools%b
   --  ada.finalization.heap_management%s
   --  ada.finalization.heap_management%b
   --  system.os_lib%s
   --  system.os_lib%b
   --  system.pool_global%s
   --  system.pool_global%b
   --  system.file_control_block%s
   --  system.file_io%s
   --  system.file_io%b
   --  system.traceback%s
   --  ada.exceptions%b
   --  system.traceback%b
   --  ada.text_io%s
   --  ada.text_io%b
   --  stdarg%s
   --  stdarg%b
   --  stdarg.impl%s
   --  stdarg.impl%b
   --  win32%s
   --  win32%b
   --  win32.utils%s
   --  win32.utils%b
   --  win32.winnt%s
   --  win32.winnt%b
   --  win32.windef%s
   --  win32.windef%b
   --  win32.winbase%s
   --  win32.winbase%b
   --  dll_test%b
   --  END ELABORATION ORDER


end ada_main;
