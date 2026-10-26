# SKELETON FILL — Worker H chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADEA0_005adea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADEA0_005adea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADEA0_005adea0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADF00_005adf00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADF00_005adf00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADF00_005adf00.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADF40_005adf40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADF40_005adf40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADF40_005adf40.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AE110_005ae110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AE110_005ae110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AE110_005ae110.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AE860_005ae860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AE860_005ae860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AE860_005ae860.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AE8C0_005ae8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AE8C0_005ae8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AE8C0_005ae8c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AEA20_005aea20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AEA20_005aea20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AEA20_005aea20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AEA50_005aea50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AEA50_005aea50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AEA50_005aea50.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AEB50_005aeb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AEB50_005aeb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AEB50_005aeb50.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AED80_005aed80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AED80_005aed80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AED80_005aed80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AF100_005af100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AF100_005af100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AF100_005af100.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AF2B0_005af2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AF2B0_005af2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AF2B0_005af2b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AF360_005af360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AF360_005af360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AF360_005af360.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B0870_005b0870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B0870_005b0870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B0870_005b0870.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B0BD0_005b0bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B0BD0_005b0bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B0BD0_005b0bd0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B0DB0_005b0db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B0DB0_005b0db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B0DB0_005b0db0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1190_005b1190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1190_005b1190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1190_005b1190.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1240_005b1240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1240_005b1240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1240_005b1240.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B17B0_005b17b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B17B0_005b17b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B17B0_005b17b0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B19D0_005b19d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B19D0_005b19d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B19D0_005b19d0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B19E0_005b19e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B19E0_005b19e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B19E0_005b19e0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1A10_005b1a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1A10_005b1a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1A10_005b1a10.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1A70_005b1a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1A70_005b1a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1A70_005b1a70.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1CB0_005b1cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1CB0_005b1cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1CB0_005b1cb0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1D20_005b1d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1D20_005b1d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1D20_005b1d20.md
