# SKELETON FILL — Worker H chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CIasin_005c05d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CIasin_005c05d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CIasin_005c05d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_asin_005c05e4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_asin_005c05e4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_asin_005c05e4.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__snprintf_005c0777.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__snprintf_005c0777.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__snprintf_005c0777.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_toupper_0_005c09a6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_toupper_0_005c09a6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_toupper_0_005c09a6.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isalpha_005c0a72.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isalpha_005c0a72.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isalpha_005c0a72.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isdigit_005c0aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isdigit_005c0aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isdigit_005c0aa0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isxdigit_005c0ac8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isxdigit_005c0ac8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isxdigit_005c0ac8.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isspace_005c0af5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isspace_005c0af5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isspace_005c0af5.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isalnum_005c0b1d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isalnum_005c0b1d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isalnum_005c0b1d.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cinit_005c0b4b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cinit_005c0b4b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cinit_005c0b4b.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_exit_005c0b78.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_exit_005c0b78.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_exit_005c0b78.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__exit_005c0b89.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__exit_005c0b89.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__exit_005c0b89.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__lockexit_005c0c3f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__lockexit_005c0c3f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__lockexit_005c0c3f.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__unlockexit_005c0c48.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__unlockexit_005c0c48.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__unlockexit_005c0c48.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___dtoxmode_005c0c6b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___dtoxmode_005c0c6b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___dtoxmode_005c0c6b.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_IsRootUNCName_005c0fde.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_IsRootUNCName_005c0fde.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_IsRootUNCName_005c0fde.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strchr_005c1060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strchr_005c1060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strchr_005c1060.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5C1366_005c1366.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5C1366_005c1366.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5C1366_005c1366.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__amsg_exit_005c1556.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__amsg_exit_005c1556.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__amsg_exit_005c1556.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_fast_error_exit_005c157b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_fast_error_exit_005c157b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_fast_error_exit_005c157b.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__JumpToContinuation__YGXPAXPAUEHRegistrationNode___Z_005c159f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__JumpToContinuation__YGXPAXPAUEHRegistrationNode___Z_005c159f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__JumpToContinuation__YGXPAXPAUEHRegistrationNode___Z_005c159f.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5C15D3_005c15d3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5C15D3_005c15d3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5C15D3_005c15d3.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5C15DA_005c15da.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5C15DA_005c15da.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5C15DA_005c15da.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__UnwindNestedFrames__YGXPAUEHRegistrationNode__PAUEHExceptionRecord___Z_005c15e1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__UnwindNestedFrames__YGXPAUEHRegistrationNode__PAUEHExceptionRecord___Z_005c15e1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__UnwindNestedFrames__YGXPAUEHRegistrationNode__PAUEHExceptionRecord___Z_005c15e1.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CallSETranslator__YAHPAUEHExceptionRecord__PAUEHRegistrationNode__PAX2PBU_s_FuncInfo__H1_Z_005c16df.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CallSETranslator__YAHPAUEHExceptionRecord__PAUEHRegistrationNode__PAX2PBU_s_FuncInfo__H1_Z_005c16df.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CallSETranslator__YAHPAUEHExceptionRecord__PAUEHRegistrationNode__PAX2PBU_s_FuncInfo__H1_Z_005c16df.md
