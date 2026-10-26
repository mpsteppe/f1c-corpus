# SKELETON FILL — Worker D chunk 32/33 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C1840_005c1840.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C1840_005c1840.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C1840_005c1840.md
2. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C18D0_005c18d0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C18D0_005c18d0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C18D0_005c18d0.md
3. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2180_005c2180.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2180_005c2180.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2180_005c2180.md
4. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C21F0_005c21f0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C21F0_005c21f0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C21F0_005c21f0.md
5. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C22D0_005c22d0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C22D0_005c22d0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C22D0_005c22d0.md
6. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C23D0_005c23d0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C23D0_005c23d0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C23D0_005c23d0.md
7. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C24A0_005c24a0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C24A0_005c24a0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C24A0_005c24a0.md
8. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C24B0_005c24b0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C24B0_005c24b0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C24B0_005c24b0.md
9. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2530_005c2530.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2530_005c2530.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2530_005c2530.md
10. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2630_005c2630.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2630_005c2630.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2630_005c2630.md
11. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C26A0_005c26a0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C26A0_005c26a0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C26A0_005c26a0.md
12. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2770_005c2770.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2770_005c2770.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2770_005c2770.md
13. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2810_005c2810.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2810_005c2810.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2810_005c2810.md
14. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2B30_005c2b30.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2B30_005c2b30.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2B30_005c2b30.md
15. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2BB0_005c2bb0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2BB0_005c2bb0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2BB0_005c2bb0.md
16. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2F70_005c2f70.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2F70_005c2f70.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2F70_005c2f70.md
17. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C2FB0_005c2fb0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C2FB0_005c2fb0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C2FB0_005c2fb0.md
18. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C3150_005c3150.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C3150_005c3150.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C3150_005c3150.md
19. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C32E0_005c32e0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C32E0_005c32e0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C32E0_005c32e0.md
20. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C3696_005c3696.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C3696_005c3696.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C3696_005c3696.md
21. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C3C50_005c3c50.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C3C50_005c3c50.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C3C50_005c3c50.md
22. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C3D10_005c3d10.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C3D10_005c3d10.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C3D10_005c3d10.md
23. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\__1ios_base_std__UAE_XZ_5_005c3db0.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\__1ios_base_std__UAE_XZ_5_005c3db0.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\__1ios_base_std__UAE_XZ_5_005c3db0.md
24. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_5C3E40_005c3e40.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_5C3E40_005c3e40.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_5C3E40_005c3e40.md
25. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\nullsub_216_005c3f04.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\nullsub_216_005c3f04.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\nullsub_216_005c3f04.md
