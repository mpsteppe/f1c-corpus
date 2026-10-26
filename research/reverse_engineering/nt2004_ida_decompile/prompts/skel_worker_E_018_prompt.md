# SKELETON FILL — Worker E chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4C50_004e4c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4C50_004e4c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4C50_004e4c50.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4C60_004e4c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4C60_004e4c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4C60_004e4c60.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4ED0_004e4ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4ED0_004e4ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4ED0_004e4ed0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4F60_004e4f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4F60_004e4f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4F60_004e4f60.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4F70_004e4f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4F70_004e4f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4F70_004e4f70.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4FB0_004e4fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4FB0_004e4fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4FB0_004e4fb0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E55D0_004e55d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E55D0_004e55d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E55D0_004e55d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5630_004e5630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5630_004e5630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5630_004e5630.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5950_004e5950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5950_004e5950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5950_004e5950.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5EE0_004e5ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5EE0_004e5ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5EE0_004e5ee0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5FE0_004e5fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5FE0_004e5fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5FE0_004e5fe0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E61E0_004e61e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E61E0_004e61e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E61E0_004e61e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E61F0_004e61f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E61F0_004e61f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E61F0_004e61f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E63C0_004e63c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E63C0_004e63c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E63C0_004e63c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_74_004e63d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_74_004e63d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_74_004e63d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_75_004e63f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_75_004e63f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_75_004e63f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6400_004e6400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6400_004e6400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6400_004e6400.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_77_004e6430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_77_004e6430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_77_004e6430.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6440_004e6440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6440_004e6440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6440_004e6440.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_78_004e6450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_78_004e6450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_78_004e6450.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6480_004e6480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6480_004e6480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6480_004e6480.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6C90_004e6c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6C90_004e6c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6C90_004e6c90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6CD0_004e6cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6CD0_004e6cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6CD0_004e6cd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E7140_004e7140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E7140_004e7140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E7140_004e7140.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E7620_004e7620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E7620_004e7620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E7620_004e7620.md
