# SKELETON FILL — Worker E chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8EC0_004b8ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8EC0_004b8ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8EC0_004b8ec0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_49_004b8ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_49_004b8ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_49_004b8ed0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_50_004b8ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_50_004b8ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_50_004b8ef0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8F00_004b8f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8F00_004b8f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8F00_004b8f00.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8F10_004b8f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8F10_004b8f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8F10_004b8f10.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_107_004b8f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_107_004b8f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_107_004b8f40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8F50_004b8f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8F50_004b8f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8F50_004b8f50.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_51_004b8f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_51_004b8f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_51_004b8f60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_52_004b8f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_52_004b8f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_52_004b8f80.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8F90_004b8f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8F90_004b8f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8F90_004b8f90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8FE0_004b8fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8FE0_004b8fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8FE0_004b8fe0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_53_004b900e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_53_004b900e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_53_004b900e.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9020_004b9020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9020_004b9020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9020_004b9020.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9070_004b9070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9070_004b9070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9070_004b9070.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_54_004b909e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_54_004b909e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_54_004b909e.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9130_004b9130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9130_004b9130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9130_004b9130.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9710_004b9710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9710_004b9710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9710_004b9710.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B99F0_004b99f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B99F0_004b99f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B99F0_004b99f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9AC0_004b9ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9AC0_004b9ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9AC0_004b9ac0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9F00_004b9f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9F00_004b9f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9F00_004b9f00.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9FF0_004b9ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9FF0_004b9ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9FF0_004b9ff0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA060_004ba060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA060_004ba060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA060_004ba060.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA080_004ba080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA080_004ba080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA080_004ba080.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA0E0_004ba0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA0E0_004ba0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA0E0_004ba0e0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA250_004ba250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA250_004ba250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA250_004ba250.md
