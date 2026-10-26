# SKELETON FILL — Worker A chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_401DD0_00401dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_401DD0_00401dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_401DD0_00401dd0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_402390_00402390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_402390_00402390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_402390_00402390.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4024D0_004024d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4024D0_004024d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4024D0_004024d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403990_00403990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403990_00403990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403990_00403990.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403B70_00403b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403B70_00403b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403B70_00403b70.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403BE0_00403be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403BE0_00403be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403BE0_00403be0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403CE0_00403ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403CE0_00403ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403CE0_00403ce0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403D10_00403d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403D10_00403d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403D10_00403d10.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_403FD0_00403fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_403FD0_00403fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_403FD0_00403fd0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4040B0_004040b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4040B0_004040b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4040B0_004040b0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4042F0_004042f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4042F0_004042f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4042F0_004042f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404590_00404590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404590_00404590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404590_00404590.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4045E0_004045e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4045E0_004045e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4045E0_004045e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404630_00404630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404630_00404630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404630_00404630.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404860_00404860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404860_00404860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404860_00404860.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404B10_00404b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404B10_00404b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404B10_00404b10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404CA0_00404ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404CA0_00404ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404CA0_00404ca0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404D70_00404d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404D70_00404d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404D70_00404d70.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404E50_00404e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404E50_00404e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404E50_00404e50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404E90_00404e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404E90_00404e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404E90_00404e90.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404ED0_00404ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404ED0_00404ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404ED0_00404ed0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404F89_00404f89.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404F89_00404f89.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404F89_00404f89.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404F90_00404f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404F90_00404f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404F90_00404f90.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405080_00405080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405080_00405080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405080_00405080.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405130_00405130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405130_00405130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405130_00405130.md
