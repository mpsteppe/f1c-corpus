# SKELETON FILL — Worker A chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C470_0040c470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C470_0040c470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C470_0040c470.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C480_0040c480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C480_0040c480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C480_0040c480.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C490_0040c490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C490_0040c490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C490_0040c490.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C4A0_0040c4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C4A0_0040c4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C4A0_0040c4a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C4B0_0040c4b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C4B0_0040c4b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C4B0_0040c4b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C4CA_0040c4ca.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C4CA_0040c4ca.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C4CA_0040c4ca.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C4D0_0040c4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C4D0_0040c4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C4D0_0040c4d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C5C0_0040c5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C5C0_0040c5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C5C0_0040c5c0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C730_0040c730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C730_0040c730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C730_0040c730.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CB90_0040cb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CB90_0040cb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CB90_0040cb90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CBE0_0040cbe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CBE0_0040cbe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CBE0_0040cbe0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CC00_0040cc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CC00_0040cc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CC00_0040cc00.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CC10_0040cc10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CC10_0040cc10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CC10_0040cc10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CC40_0040cc40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CC40_0040cc40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CC40_0040cc40.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40D5C0_0040d5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40D5C0_0040d5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40D5C0_0040d5c0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40E220_0040e220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40E220_0040e220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40E220_0040e220.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40E4C0_0040e4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40E4C0_0040e4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40E4C0_0040e4c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40E9D0_0040e9d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40E9D0_0040e9d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40E9D0_0040e9d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EB10_0040eb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EB10_0040eb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EB10_0040eb10.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EBD0_0040ebd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EBD0_0040ebd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EBD0_0040ebd0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EC30_0040ec30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EC30_0040ec30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EC30_0040ec30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EE60_0040ee60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EE60_0040ee60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EE60_0040ee60.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EFA0_0040efa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EFA0_0040efa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EFA0_0040efa0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40EFC0_0040efc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40EFC0_0040efc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40EFC0_0040efc0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40F050_0040f050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40F050_0040f050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40F050_0040f050.md
