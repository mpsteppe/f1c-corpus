# SKELETON FILL — Worker H chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_TypeMatch__YAHPBU_s_HandlerType__PBU_s_CatchableType__PBU_s_ThrowInfo___Z_005cac58.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_TypeMatch__YAHPBU_s_HandlerType__PBU_s_CatchableType__PBU_s_ThrowInfo___Z_005cac58.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_TypeMatch__YAHPBU_s_HandlerType__PBU_s_CatchableType__PBU_s_ThrowInfo___Z_005cac58.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_CatchIt__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__PBU_s_HandlerType__PBU_s_CatchableType__PBU_s_TryBlockMapEntry__H1E_Z_005cad53.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_CatchIt__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__PBU_s_HandlerType__PBU_s_CatchableType__PBU_s_TryBlockMapEntry__H1E_Z_005cad53.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_CatchIt__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__PBU_s_HandlerType__PBU_s_CatchableType__PBU_s_TryBlockMapEntry__H1E_Z_005cad53.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_CallCatchBlock__YAPAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PBU_s_FuncInfo__PAXHK_Z_005cadce.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_CallCatchBlock__YAPAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PBU_s_FuncInfo__PAXHK_Z_005cadce.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_CallCatchBlock__YAPAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PBU_s_FuncInfo__PAXHK_Z_005cadce.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_ExFilterRethrow__YAHPAU_EXCEPTION_POINTERS___Z_005caee9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_ExFilterRethrow__YAHPAU_EXCEPTION_POINTERS___Z_005caee9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_ExFilterRethrow__YAHPAU_EXCEPTION_POINTERS___Z_005caee9.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_BuildCatchObject__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PBU_s_HandlerType__PBU_s_CatchableType___Z_005caf13.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_BuildCatchObject__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PBU_s_HandlerType__PBU_s_CatchableType___Z_005caf13.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_BuildCatchObject__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PBU_s_HandlerType__PBU_s_CatchableType___Z_005caf13.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_184_005cb0d7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_184_005cb0d7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_184_005cb0d7.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_AdjustPointer__YAPAXPAXABUPMD___Z_005cb13e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_AdjustPointer__YAPAXPAXABUPMD___Z_005cb13e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_AdjustPointer__YAPAXPAXABUPMD___Z_005cb13e.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_terminate__YAXXZ_005cb1bc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_terminate__YAXXZ_005cb1bc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_terminate__YAXXZ_005cb1bc.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__callnewh_005cb273.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__callnewh_005cb273.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__callnewh_005cb273.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CB301_005cb301.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CB301_005cb301.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CB301_005cb301.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CC0CD_005cc0cd.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CC0CD_005cc0cd.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CC0CD_005cc0cd.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__rt_probe_read4_4_005cc4a2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__rt_probe_read4_4_005cc4a2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__rt_probe_read4_4_005cc4a2.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__aulldiv_005cc510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__aulldiv_005cc510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__aulldiv_005cc510.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__control87_005cc578.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__control87_005cc578.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__control87_005cc578.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__controlfp_005cc5ad.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__controlfp_005cc5ad.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__controlfp_005cc5ad.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__abstract_cw_005cc5c3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__abstract_cw_005cc5c3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__abstract_cw_005cc5c3.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__hw_cw_005cc655.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__hw_cw_005cc655.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__hw_cw_005cc655.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ZeroTail_005cc6de.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ZeroTail_005cc6de.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ZeroTail_005cc6de.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CopyMan_005cc809.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CopyMan_005cc809.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CopyMan_005cc809.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CCA44_005cca44.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CCA44_005cca44.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CCA44_005cca44.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CCA5A_005cca5a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CCA5A_005cca5a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CCA5A_005cca5a.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CCA70_005cca70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CCA70_005cca70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CCA70_005cca70.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CCA9D_005cca9d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CCA9D_005cca9d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CCA9D_005cca9d.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fltout2_005ccb41.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fltout2_005ccb41.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fltout2_005ccb41.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___dtold_005ccb9d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___dtold_005ccb9d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___dtold_005ccb9d.md
