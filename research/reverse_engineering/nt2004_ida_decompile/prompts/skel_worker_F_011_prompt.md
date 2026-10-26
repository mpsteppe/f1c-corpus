# SKELETON FILL — Worker F chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__1TaskStack_details_Concurrency__QAE_XZ_00507590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__1TaskStack_details_Concurrency__QAE_XZ_00507590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__1TaskStack_details_Concurrency__QAE_XZ_00507590.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_507770_00507770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_507770_00507770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_507770_00507770.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_508930_00508930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_508930_00508930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_508930_00508930.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_509920_00509920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_509920_00509920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_509920_00509920.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50ADD0_0050add0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50ADD0_0050add0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50ADD0_0050add0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50AEE0_0050aee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50AEE0_0050aee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50AEE0_0050aee0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B020_0050b020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B020_0050b020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B020_0050b020.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B080_0050b080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B080_0050b080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B080_0050b080.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B100_0050b100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B100_0050b100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B100_0050b100.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B170_0050b170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B170_0050b170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B170_0050b170.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B1D0_0050b1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B1D0_0050b1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B1D0_0050b1d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B240_0050b240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B240_0050b240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B240_0050b240.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B320_0050b320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B320_0050b320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B320_0050b320.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B400_0050b400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B400_0050b400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B400_0050b400.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B490_0050b490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B490_0050b490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B490_0050b490.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50BCF0_0050bcf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50BCF0_0050bcf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50BCF0_0050bcf0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50BDD0_0050bdd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50BDD0_0050bdd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50BDD0_0050bdd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50BEB0_0050beb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50BEB0_0050beb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50BEB0_0050beb0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50BF70_0050bf70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50BF70_0050bf70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50BF70_0050bf70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C600_0050c600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C600_0050c600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C600_0050c600.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C6A0_0050c6a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C6A0_0050c6a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C6A0_0050c6a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C760_0050c760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C760_0050c760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C760_0050c760.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C800_0050c800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C800_0050c800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C800_0050c800.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C860_0050c860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C860_0050c860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C860_0050c860.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50C9A0_0050c9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50C9A0_0050c9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50C9A0_0050c9a0.md
