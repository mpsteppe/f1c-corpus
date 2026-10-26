# SKELETON FILL — Worker D chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B25D0_004b25d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B25D0_004b25d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B25D0_004b25d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2610_004b2610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2610_004b2610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2610_004b2610.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2620_004b2620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2620_004b2620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2620_004b2620.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2660_004b2660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2660_004b2660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2660_004b2660.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2790_004b2790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2790_004b2790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2790_004b2790.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B27A0_004b27a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B27A0_004b27a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B27A0_004b27a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B27E0_004b27e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B27E0_004b27e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B27E0_004b27e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2C70_004b2c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2C70_004b2c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2C70_004b2c70.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2D40_004b2d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2D40_004b2d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2D40_004b2d40.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2DC0_004b2dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2DC0_004b2dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2DC0_004b2dc0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2DE0_004b2de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2DE0_004b2de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2DE0_004b2de0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2EF0_004b2ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2EF0_004b2ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2EF0_004b2ef0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2F30_004b2f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2F30_004b2f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2F30_004b2f30.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2F70_004b2f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2F70_004b2f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2F70_004b2f70.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2FB0_004b2fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2FB0_004b2fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2FB0_004b2fb0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2FD0_004b2fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2FD0_004b2fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2FD0_004b2fd0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2FE0_004b2fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2FE0_004b2fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2FE0_004b2fe0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3000_004b3000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3000_004b3000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3000_004b3000.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3040_004b3040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3040_004b3040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3040_004b3040.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B30B0_004b30b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B30B0_004b30b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B30B0_004b30b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3200_004b3200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3200_004b3200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3200_004b3200.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3268_004b3268.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3268_004b3268.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3268_004b3268.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3310_004b3310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3310_004b3310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3310_004b3310.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3378_004b3378.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3378_004b3378.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3378_004b3378.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3470_004b3470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3470_004b3470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3470_004b3470.md
