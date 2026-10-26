# SKELETON FILL — Worker H chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__errcode_005c7f72.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__errcode_005c7f72.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__errcode_005c7f72.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__frnd_005c7f9f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__frnd_005c7f9f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__frnd_005c7f9f.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__set_exp_005c7fb1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__set_exp_005c7fb1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__set_exp_005c7fb1.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__sptype_005c7fda.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__sptype_005c7fda.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__sptype_005c7fda.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__statfp_005c80f5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__statfp_005c80f5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__statfp_005c80f5.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__clrfp_005c8103.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__clrfp_005c8103.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__clrfp_005c8103.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ctrlfp_005c8112.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ctrlfp_005c8112.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ctrlfp_005c8112.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__set_statfp_005c8135.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__set_statfp_005c8135.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__set_statfp_005c8135.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cintrindisp2_005c8190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cintrindisp2_005c8190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cintrindisp2_005c8190.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cintrindisp1_005c81ce.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cintrindisp1_005c81ce.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cintrindisp1_005c81ce.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\ctranexit_005c8253.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\ctranexit_005c8253.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\ctranexit_005c8253.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\cintrinexit_005c825a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\cintrinexit_005c825a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\cintrinexit_005c825a.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fload_005c83be.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fload_005c83be.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fload_005c83be.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_162_005c8400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_162_005c8400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_162_005c8400.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_163_005c8517.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_163_005c8517.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_163_005c8517.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_176_005c8c06.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_176_005c8c06.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_176_005c8c06.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_178_005c8ebe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_178_005c8ebe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_178_005c8ebe.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__mbsicmp_005c949c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__mbsicmp_005c949c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__mbsicmp_005c949c.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__mbsrchr_005c9631.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__mbsrchr_005c9631.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__mbsrchr_005c9631.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__mbspbrk_005c9806.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__mbspbrk_005c9806.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__mbspbrk_005c9806.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__setenvp_005ca1ca.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__setenvp_005ca1ca.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__setenvp_005ca1ca.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__NMSG_WRITE_005ca80d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__NMSG_WRITE_005ca80d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__NMSG_WRITE_005ca80d.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___InternalCxxFrameHandler_005ca960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___InternalCxxFrameHandler_005ca960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___InternalCxxFrameHandler_005ca960.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_FindHandler__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__EH1_Z_005ca9fb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_FindHandler__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__EH1_Z_005ca9fb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_FindHandler__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__EH1_Z_005ca9fb.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_FindHandlerForForeignException__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__HH1_Z_005cabae.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_FindHandlerForForeignException__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__HH1_Z_005cabae.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_FindHandlerForForeignException__YAXPAUEHExceptionRecord__PAUEHRegistrationNode__PAU_CONTEXT__PAXPBU_s_FuncInfo__HH1_Z_005cabae.md
