# SKELETON FILL — Worker C chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482F20_00482f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482F20_00482f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482F20_00482f20.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482F60_00482f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482F60_00482f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482F60_00482f60.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482FE0_00482fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482FE0_00482fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482FE0_00482fe0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483050_00483050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483050_00483050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483050_00483050.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4830A0_004830a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4830A0_004830a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4830A0_004830a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4830E0_004830e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4830E0_004830e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4830E0_004830e0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4831F0_004831f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4831F0_004831f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4831F0_004831f0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4832D0_004832d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4832D0_004832d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4832D0_004832d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483330_00483330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483330_00483330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483330_00483330.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483380_00483380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483380_00483380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483380_00483380.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483420_00483420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483420_00483420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483420_00483420.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4834A0_004834a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4834A0_004834a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4834A0_004834a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483510_00483510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483510_00483510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483510_00483510.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483580_00483580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483580_00483580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483580_00483580.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4835F0_004835f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4835F0_004835f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4835F0_004835f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483660_00483660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483660_00483660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483660_00483660.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4836E0_004836e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4836E0_004836e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4836E0_004836e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483750_00483750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483750_00483750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483750_00483750.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4837C0_004837c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4837C0_004837c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4837C0_004837c0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483830_00483830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483830_00483830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483830_00483830.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4838B0_004838b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4838B0_004838b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4838B0_004838b0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483930_00483930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483930_00483930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483930_00483930.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4839A0_004839a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4839A0_004839a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4839A0_004839a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483A20_00483a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483A20_00483a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483A20_00483a20.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483A60_00483a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483A60_00483a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483A60_00483a60.md
