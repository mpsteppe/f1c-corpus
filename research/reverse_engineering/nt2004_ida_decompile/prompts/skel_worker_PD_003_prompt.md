# SKELETON FILL — Worker PD chunk 3/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DF490_004df490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DF490_004df490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DF490_004df490.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FB930_004fb930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FB930_004fb930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FB930_004fb930.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E840_0051e840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E840_0051e840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E840_0051e840.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B9A0_0052b9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B9A0_0052b9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B9A0_0052b9a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A2CE0_005a2ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A2CE0_005a2ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A2CE0_005a2ce0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CA30_0040ca30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CA30_0040ca30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CA30_0040ca30.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_420DA0_00420da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_420DA0_00420da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_420DA0_00420da0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_426770_00426770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_426770_00426770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_426770_00426770.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C150_0042c150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C150_0042c150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C150_0042c150.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_445010_00445010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_445010_00445010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_445010_00445010.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4586E0_004586e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4586E0_004586e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4586E0_004586e0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46A4A0_0046a4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46A4A0_0046a4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46A4A0_0046a4a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476B30_00476b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476B30_00476b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476B30_00476b30.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A01C0_004a01c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A01C0_004a01c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A01C0_004a01c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A4CF0_004a4cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A4CF0_004a4cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A4CF0_004a4cf0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C21B0_004c21b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C21B0_004c21b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C21B0_004c21b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E38E0_004e38e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E38E0_004e38e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E38E0_004e38e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EAAC0_004eaac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EAAC0_004eaac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EAAC0_004eaac0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50FB70_0050fb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50FB70_0050fb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50FB70_0050fb70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_518630_00518630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_518630_00518630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_518630_00518630.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526670_00526670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526670_00526670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526670_00526670.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_553F40_00553f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_553F40_00553f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_553F40_00553f40.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_586DA0_00586da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_586DA0_00586da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_586DA0_00586da0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A2C20_005a2c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A2C20_005a2c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A2C20_005a2c20.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_memcpy_005c2590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_memcpy_005c2590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_memcpy_005c2590.md
