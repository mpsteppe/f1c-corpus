# SKELETON FILL — Worker G chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595C90_00595c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595C90_00595c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595C90_00595c90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_596D40_00596d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_596D40_00596d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_596D40_00596d40.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_596EC0_00596ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_596EC0_00596ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_596EC0_00596ec0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_596FA0_00596fa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_596FA0_00596fa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_596FA0_00596fa0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597020_00597020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597020_00597020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597020_00597020.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597090_00597090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597090_00597090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597090_00597090.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5971C0_005971c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5971C0_005971c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5971C0_005971c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597290_00597290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597290_00597290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597290_00597290.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5972A0_005972a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5972A0_005972a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5972A0_005972a0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597300_00597300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597300_00597300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597300_00597300.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5973D0_005973d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5973D0_005973d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5973D0_005973d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5974A0_005974a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5974A0_005974a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5974A0_005974a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597500_00597500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597500_00597500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597500_00597500.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597540_00597540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597540_00597540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597540_00597540.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597590_00597590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597590_00597590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597590_00597590.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5975F0_005975f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5975F0_005975f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5975F0_005975f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597680_00597680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597680_00597680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597680_00597680.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597730_00597730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597730_00597730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597730_00597730.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5978A0_005978a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5978A0_005978a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5978A0_005978a0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597960_00597960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597960_00597960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597960_00597960.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597AE0_00597ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597AE0_00597ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597AE0_00597ae0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597B20_00597b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597B20_00597b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597B20_00597b20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597BA0_00597ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597BA0_00597ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597BA0_00597ba0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597C00_00597c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597C00_00597c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597C00_00597c00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597C70_00597c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597C70_00597c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597C70_00597c70.md
