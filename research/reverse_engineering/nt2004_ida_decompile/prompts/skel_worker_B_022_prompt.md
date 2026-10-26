# SKELETON FILL — Worker B chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463DC0_00463dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463DC0_00463dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463DC0_00463dc0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463E00_00463e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463E00_00463e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463E00_00463e00.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463E50_00463e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463E50_00463e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463E50_00463e50.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463E70_00463e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463E70_00463e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463E70_00463e70.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464240_00464240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464240_00464240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464240_00464240.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464400_00464400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464400_00464400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464400_00464400.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464410_00464410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464410_00464410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464410_00464410.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4646E0_004646e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4646E0_004646e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4646E0_004646e0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464740_00464740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464740_00464740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464740_00464740.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464810_00464810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464810_00464810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464810_00464810.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464A00_00464a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464A00_00464a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464A00_00464a00.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464AF0_00464af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464AF0_00464af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464AF0_00464af0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464BA0_00464ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464BA0_00464ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464BA0_00464ba0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464C40_00464c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464C40_00464c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464C40_00464c40.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465190_00465190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465190_00465190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465190_00465190.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4651E0_004651e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4651E0_004651e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4651E0_004651e0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465200_00465200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465200_00465200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465200_00465200.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465260_00465260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465260_00465260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465260_00465260.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465270_00465270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465270_00465270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465270_00465270.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465320_00465320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465320_00465320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465320_00465320.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465330_00465330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465330_00465330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465330_00465330.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46536A_0046536a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46536A_0046536a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46536A_0046536a.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465790_00465790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465790_00465790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465790_00465790.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465840_00465840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465840_00465840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465840_00465840.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465860_00465860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465860_00465860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465860_00465860.md
