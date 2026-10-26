# SKELETON FILL — Worker PC chunk 1/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_434FA0_00434fa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_434FA0_00434fa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_434FA0_00434fa0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CDC80_004cdc80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CDC80_004cdc80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CDC80_004cdc80.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E940_0045e940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E940_0045e940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E940_0045e940.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6570_004e6570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6570_004e6570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6570_004e6570.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56BAF0_0056baf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56BAF0_0056baf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56BAF0_0056baf0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4448C0_004448c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4448C0_004448c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4448C0_004448c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466190_00466190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466190_00466190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466190_00466190.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC690_004ac690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC690_004ac690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC690_004ac690.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C6680_004c6680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C6680_004c6680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C6680_004c6680.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EA010_004ea010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EA010_004ea010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EA010_004ea010.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_521110_00521110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_521110_00521110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_521110_00521110.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56C740_0056c740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56C740_0056c740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56C740_0056c740.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_404680_00404680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_404680_00404680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_404680_00404680.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40D150_0040d150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40D150_0040d150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40D150_0040d150.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_446620_00446620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_446620_00446620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_446620_00446620.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486B10_00486b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486B10_00486b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486B10_00486b10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6660_004d6660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6660_004d6660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6660_004d6660.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2E10_004f2e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2E10_004f2e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2E10_004f2e10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_515870_00515870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_515870_00515870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_515870_00515870.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52C610_0052c610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52C610_0052c610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52C610_0052c610.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A5A60_005a5a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A5A60_005a5a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A5A60_005a5a60.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8990_005b8990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8990_005b8990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8990_005b8990.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4300E0_004300e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4300E0_004300e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4300E0_004300e0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462FE0_00462fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462FE0_00462fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462FE0_00462fe0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8B20_004a8b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8B20_004a8b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8B20_004a8b20.md
