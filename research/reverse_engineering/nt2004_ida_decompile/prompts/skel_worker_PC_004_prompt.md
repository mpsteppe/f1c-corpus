# SKELETON FILL — Worker PC chunk 4/4 (f1c-ida-skeleton-pro), 21 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4057C0_004057c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4057C0_004057c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4057C0_004057c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421970_00421970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421970_00421970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421970_00421970.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_424C60_00424c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_424C60_00424c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_424C60_00424c60.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427540_00427540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427540_00427540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427540_00427540.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CC80_0042cc80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CC80_0042cc80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CC80_0042cc80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43B590_0043b590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43B590_0043b590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43B590_0043b590.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E080_0046e080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E080_0046e080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E080_0046e080.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E500_0049e500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E500_0049e500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E500_0049e500.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA6E0_004aa6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA6E0_004aa6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA6E0_004aa6e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C19D0_004c19d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C19D0_004c19d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C19D0_004c19d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DBF80_004dbf80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DBF80_004dbf80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DBF80_004dbf80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E17F0_004e17f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E17F0_004e17f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E17F0_004e17f0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6480_004e6480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6480_004e6480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6480_004e6480.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE360_004ee360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE360_004ee360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE360_004ee360.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA900_004fa900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA900_004fa900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA900_004fa900.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E230_0051e230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E230_0051e230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E230_0051e230.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528C20_00528c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528C20_00528c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528C20_00528c20.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52D830_0052d830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52D830_0052d830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52D830_0052d830.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593010_00593010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593010_00593010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593010_00593010.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A78B0_005a78b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A78B0_005a78b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A78B0_005a78b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B3460_005b3460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B3460_005b3460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B3460_005b3460.md
