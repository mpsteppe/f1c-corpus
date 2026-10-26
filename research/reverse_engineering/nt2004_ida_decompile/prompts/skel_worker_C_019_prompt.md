# SKELETON FILL — Worker C chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489FE0_00489fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489FE0_00489fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489FE0_00489fe0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A040_0048a040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A040_0048a040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A040_0048a040.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A2D0_0048a2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A2D0_0048a2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A2D0_0048a2d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A320_0048a320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A320_0048a320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A320_0048a320.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A490_0048a490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A490_0048a490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A490_0048a490.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A630_0048a630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A630_0048a630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A630_0048a630.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A890_0048a890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A890_0048a890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A890_0048a890.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A8D0_0048a8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A8D0_0048a8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A8D0_0048a8d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A8E0_0048a8e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A8E0_0048a8e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A8E0_0048a8e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A950_0048a950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A950_0048a950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A950_0048a950.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A960_0048a960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A960_0048a960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A960_0048a960.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A9A0_0048a9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A9A0_0048a9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A9A0_0048a9a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48A9B0_0048a9b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48A9B0_0048a9b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48A9B0_0048a9b0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AA30_0048aa30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AA30_0048aa30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AA30_0048aa30.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AA70_0048aa70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AA70_0048aa70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AA70_0048aa70.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AF00_0048af00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AF00_0048af00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AF00_0048af00.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AF40_0048af40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AF40_0048af40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AF40_0048af40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AF90_0048af90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AF90_0048af90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AF90_0048af90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AFE0_0048afe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AFE0_0048afe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AFE0_0048afe0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AFF0_0048aff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AFF0_0048aff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AFF0_0048aff0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B0D0_0048b0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B0D0_0048b0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B0D0_0048b0d0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B110_0048b110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B110_0048b110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B110_0048b110.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B160_0048b160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B160_0048b160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B160_0048b160.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B530_0048b530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B530_0048b530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B530_0048b530.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B550_0048b550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B550_0048b550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B550_0048b550.md
