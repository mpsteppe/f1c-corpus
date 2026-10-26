# SKELETON FILL — Worker G chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A26A0_005a26a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A26A0_005a26a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A26A0_005a26a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A26B0_005a26b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A26B0_005a26b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A26B0_005a26b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A2740_005a2740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A2740_005a2740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A2740_005a2740.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A2870_005a2870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A2870_005a2870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A2870_005a2870.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A2B00_005a2b00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A2B00_005a2b00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A2B00_005a2b00.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3180_005a3180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3180_005a3180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3180_005a3180.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3200_005a3200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3200_005a3200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3200_005a3200.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A32F0_005a32f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A32F0_005a32f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A32F0_005a32f0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3330_005a3330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3330_005a3330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3330_005a3330.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3350_005a3350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3350_005a3350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3350_005a3350.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A36B0_005a36b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A36B0_005a36b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A36B0_005a36b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3A90_005a3a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3A90_005a3a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3A90_005a3a90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3CC0_005a3cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3CC0_005a3cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3CC0_005a3cc0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3EA0_005a3ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3EA0_005a3ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3EA0_005a3ea0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3F10_005a3f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3F10_005a3f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3F10_005a3f10.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3F40_005a3f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3F40_005a3f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3F40_005a3f40.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3F60_005a3f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3F60_005a3f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3F60_005a3f60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3FD0_005a3fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3FD0_005a3fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3FD0_005a3fd0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A41F0_005a41f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A41F0_005a41f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A41F0_005a41f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A45F0_005a45f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A45F0_005a45f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A45F0_005a45f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A46F0_005a46f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A46F0_005a46f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A46F0_005a46f0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4720_005a4720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4720_005a4720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4720_005a4720.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4740_005a4740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4740_005a4740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4740_005a4740.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4750_005a4750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4750_005a4750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4750_005a4750.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4770_005a4770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4770_005a4770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4770_005a4770.md
