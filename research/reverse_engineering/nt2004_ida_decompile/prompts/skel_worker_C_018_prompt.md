# SKELETON FILL — Worker C chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4892D0_004892d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4892D0_004892d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4892D0_004892d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489320_00489320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489320_00489320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489320_00489320.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489340_00489340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489340_00489340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489340_00489340.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4893B0_004893b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4893B0_004893b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4893B0_004893b0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489450_00489450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489450_00489450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489450_00489450.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_92_004895d3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_92_004895d3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_92_004895d3.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4897C0_004897c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4897C0_004897c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4897C0_004897c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489804_00489804.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489804_00489804.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489804_00489804.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489810_00489810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489810_00489810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489810_00489810.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489900_00489900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489900_00489900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489900_00489900.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489980_00489980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489980_00489980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489980_00489980.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489AF0_00489af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489AF0_00489af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489AF0_00489af0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489B20_00489b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489B20_00489b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489B20_00489b20.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489B70_00489b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489B70_00489b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489B70_00489b70.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489BC4_00489bc4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489BC4_00489bc4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489BC4_00489bc4.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489BD0_00489bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489BD0_00489bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489BD0_00489bd0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489C20_00489c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489C20_00489c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489C20_00489c20.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489C50_00489c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489C50_00489c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489C50_00489c50.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489D30_00489d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489D30_00489d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489D30_00489d30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489DD0_00489dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489DD0_00489dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489DD0_00489dd0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489E00_00489e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489E00_00489e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489E00_00489e00.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489EA0_00489ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489EA0_00489ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489EA0_00489ea0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489EF0_00489ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489EF0_00489ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489EF0_00489ef0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489F40_00489f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489F40_00489f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489F40_00489f40.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489F90_00489f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489F90_00489f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489F90_00489f90.md
