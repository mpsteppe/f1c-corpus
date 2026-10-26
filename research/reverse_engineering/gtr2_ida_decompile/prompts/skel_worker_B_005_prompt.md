# SKELETON FILL — Worker B chunk 5/7 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DAC0_0040dac0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DAC0_0040dac0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DAC0_0040dac0.md
2. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DAE0_0040dae0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DAE0_0040dae0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DAE0_0040dae0.md
3. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DB40_0040db40.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DB40_0040db40.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DB40_0040db40.md
4. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DB60_0040db60.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DB60_0040db60.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DB60_0040db60.md
5. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DCE0_0040dce0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DCE0_0040dce0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DCE0_0040dce0.md
6. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DD00_0040dd00.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DD00_0040dd00.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DD00_0040dd00.md
7. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DDB0_0040ddb0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DDB0_0040ddb0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DDB0_0040ddb0.md
8. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DE3C_0040de3c.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DE3C_0040de3c.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DE3C_0040de3c.md
9. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40DEA0_0040dea0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40DEA0_0040dea0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40DEA0_0040dea0.md
10. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40E040_0040e040.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40E040_0040e040.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40E040_0040e040.md
11. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40E0D0_0040e0d0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40E0D0_0040e0d0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40E0D0_0040e0d0.md
12. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40E1A0_0040e1a0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40E1A0_0040e1a0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40E1A0_0040e1a0.md
13. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40E2C0_0040e2c0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40E2C0_0040e2c0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40E2C0_0040e2c0.md
14. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40F140_0040f140.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40F140_0040f140.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40F140_0040f140.md
15. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40F4E0_0040f4e0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40F4E0_0040f4e0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40F4E0_0040f4e0.md
16. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\__1strstreambuf_std__UAE_XZ_0_0040f6d0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\__1strstreambuf_std__UAE_XZ_0_0040f6d0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\__1strstreambuf_std__UAE_XZ_0_0040f6d0.md
17. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40F9F0_0040f9f0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40F9F0_0040f9f0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40F9F0_0040f9f0.md
18. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_40FC90_0040fc90.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_40FC90_0040fc90.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_40FC90_0040fc90.md
19. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\__1strstreambuf_std__UAE_XZ_1_0040fd00.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\__1strstreambuf_std__UAE_XZ_1_0040fd00.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\__1strstreambuf_std__UAE_XZ_1_0040fd00.md
20. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_410010_00410010.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_410010_00410010.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_410010_00410010.md
21. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_4102A0_004102a0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_4102A0_004102a0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_4102A0_004102a0.md
22. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_4103C0_004103c0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_4103C0_004103c0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_4103C0_004103c0.md
23. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_410640_00410640.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_410640_00410640.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_410640_00410640.md
24. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_4107C0_004107c0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_4107C0_004107c0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_4107C0_004107c0.md
25. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_4108F0_004108f0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_4108F0_004108f0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_4108F0_004108f0.md
