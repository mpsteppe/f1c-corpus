# SKELETON FILL — Worker H chunk 13/23 (f1c-ida-skeleton), 25 functions

Your system prompt (WORKER_IDA_SKELETON.md) defines the rules. In short:
fill ONLY the `[LLM]` / `[LLM: ...]` placeholders; never change any filled
fact (offsets, hex, R/W, literals, addresses). Every claim must trace to
the provided `.c`.

For EACH item below, in order:
1. Read SKEL (the pre-filled skeleton) and C (the decompiled source).
2. Produce the completed skeleton: identical text except placeholders replaced.
3. Write it to OUT immediately — one function, one write, then the next item.
   Never write to SKEL or C. Never batch.

If a placeholder cannot be resolved from the code, write `unknown` — do not guess.

## ITEMS

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_TranslatorGuardHandler__YA_AW4_EXCEPTION_DISPOSITION__PAUEHExceptionRecord__PAUTranslatorGuardRN__PAX2_Z_005c1795.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_TranslatorGuardHandler__YA_AW4_EXCEPTION_DISPOSITION__PAUEHExceptionRecord__PAUTranslatorGuardRN__PAX2_Z_005c1795.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_TranslatorGuardHandler__YA_AW4_EXCEPTION_DISPOSITION__PAUEHExceptionRecord__PAUTranslatorGuardRN__PAX2_Z_005c1795.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__GetRangeOfTrysToCheck__YAPBU_s_TryBlockMapEntry__PBU_s_FuncInfo__HHPAI1_Z_005c180a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__GetRangeOfTrysToCheck__YAPBU_s_TryBlockMapEntry__PBU_s_FuncInfo__HHPAI1_Z_005c180a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__GetRangeOfTrysToCheck__YAPBU_s_TryBlockMapEntry__PBU_s_FuncInfo__HHPAI1_Z_005c180a.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_malloc_005c1a4e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_malloc_005c1a4e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_malloc_005c1a4e.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__EH_prolog_005c1db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__EH_prolog_005c1db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__EH_prolog_005c1db0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___M_YGXPAXIHP6EX0_Z_Z_005c1dcf.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___M_YGXPAXIHP6EX0_Z_Z_005c1dcf.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___M_YGXPAXIHP6EX0_Z_Z_005c1dcf.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___ArrayUnwind__YGXPAXIHP6EX0_Z_Z_005c1e4f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___ArrayUnwind__YGXPAXIHP6EX0_Z_Z_005c1e4f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___ArrayUnwind__YGXPAXIHP6EX0_Z_Z_005c1e4f.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__setjmp3_005c1fc4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__setjmp3_005c1fc4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__setjmp3_005c1fc4.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__aullshr_005c2040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__aullshr_005c2040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__aullshr_005c2040.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__finite_005c205f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__finite_005c205f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__finite_005c205f.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_memset_005c2450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_memset_005c2450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_memset_005c2450.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strrchr_005c24b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strrchr_005c24b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strrchr_005c24b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5C258B_005c258b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5C258B_005c258b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5C258B_005c258b.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_clock_005c28c5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_clock_005c28c5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_clock_005c28c5.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__setdefaultprecision_005c2d5a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__setdefaultprecision_005c2d5a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__setdefaultprecision_005c2d5a.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ms_p5_test_fdiv_005c2d6c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ms_p5_test_fdiv_005c2d6c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ms_p5_test_fdiv_005c2d6c.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___initstdio_005c31f9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___initstdio_005c31f9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___initstdio_005c31f9.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__lock_file2_005c32e4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__lock_file2_005c32e4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__lock_file2_005c32e4.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__unlock_file_005c3307.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__unlock_file_005c3307.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__unlock_file_005c3307.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__unlock_file2_005c3336.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__unlock_file2_005c3336.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__unlock_file2_005c3336.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_get_int_arg_005c406f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_get_int_arg_005c406f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_get_int_arg_005c406f.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_get_int64_arg_005c407c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_get_int64_arg_005c407c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_get_int64_arg_005c407c.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_get_short_arg_005c408c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_get_short_arg_005c408c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_get_short_arg_005c408c.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__allmul_005c4110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__allmul_005c4110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__allmul_005c4110.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\zerotoxdone_005c4a47.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\zerotoxdone_005c4a47.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\zerotoxdone_005c4a47.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_expbigret_005c4a92.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_expbigret_005c4a92.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_expbigret_005c4a92.md
