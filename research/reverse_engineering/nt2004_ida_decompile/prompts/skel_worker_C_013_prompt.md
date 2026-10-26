# SKELETON FILL — Worker C chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484090_00484090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484090_00484090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484090_00484090.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4840DC_004840dc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4840DC_004840dc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4840DC_004840dc.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4840E0_004840e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4840E0_004840e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4840E0_004840e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4841D0_004841d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4841D0_004841d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4841D0_004841d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484240_00484240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484240_00484240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484240_00484240.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4842B0_004842b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4842B0_004842b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4842B0_004842b0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484360_00484360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484360_00484360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484360_00484360.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4845B0_004845b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4845B0_004845b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4845B0_004845b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484640_00484640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484640_00484640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484640_00484640.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484680_00484680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484680_00484680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484680_00484680.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484740_00484740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484740_00484740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484740_00484740.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4847E0_004847e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4847E0_004847e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4847E0_004847e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484850_00484850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484850_00484850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484850_00484850.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484960_00484960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484960_00484960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484960_00484960.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484A70_00484a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484A70_00484a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484A70_00484a70.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484A80_00484a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484A80_00484a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484A80_00484a80.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484B30_00484b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484B30_00484b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484B30_00484b30.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484C90_00484c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484C90_00484c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484C90_00484c90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484CE0_00484ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484CE0_00484ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484CE0_00484ce0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484D40_00484d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484D40_00484d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484D40_00484d40.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484DE0_00484de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484DE0_00484de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484DE0_00484de0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484E80_00484e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484E80_00484e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484E80_00484e80.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484EF0_00484ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484EF0_00484ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484EF0_00484ef0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_484F90_00484f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_484F90_00484f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_484F90_00484f90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485100_00485100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485100_00485100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485100_00485100.md
