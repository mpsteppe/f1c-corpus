# SKELETON FILL — Worker AA chunk 7/7 (f1c-ida-skeleton), 13 functions

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

1. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62DF50_0062df50.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62DF50_0062df50.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62DF50_0062df50.md
2. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62DFC0_0062dfc0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62DFC0_0062dfc0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62DFC0_0062dfc0.md
3. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62E040_0062e040.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62E040_0062e040.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62E040_0062e040.md
4. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62E340_0062e340.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62E340_0062e340.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62E340_0062e340.md
5. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62E780_0062e780.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62E780_0062e780.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62E780_0062e780.md
6. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62F360_0062f360.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62F360_0062f360.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62F360_0062f360.md
7. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62F410_0062f410.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62F410_0062f410.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62F410_0062f410.md
8. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_62FB16_0062fb16.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_62FB16_0062fb16.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_62FB16_0062fb16.md
9. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_630000_00630000.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_630000_00630000.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_630000_00630000.md
10. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6300A0_006300a0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6300A0_006300a0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6300A0_006300a0.md
11. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_630370_00630370.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_630370_00630370.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_630370_00630370.md
12. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\j___2_YAPAXI_Z_00630734.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\j___2_YAPAXI_Z_00630734.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\j___2_YAPAXI_Z_00630734.md
13. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_63075D_0063075d.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_63075D_0063075d.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_63075D_0063075d.md
