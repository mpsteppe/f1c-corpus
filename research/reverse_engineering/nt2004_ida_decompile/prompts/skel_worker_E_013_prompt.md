# SKELETON FILL — Worker E chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9AF0_004d9af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9AF0_004d9af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9AF0_004d9af0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_114_004d9c93.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_114_004d9c93.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_114_004d9c93.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9CA0_004d9ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9CA0_004d9ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9CA0_004d9ca0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9DF0_004d9df0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9DF0_004d9df0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9DF0_004d9df0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9E10_004d9e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9E10_004d9e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9E10_004d9e10.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9E20_004d9e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9E20_004d9e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9E20_004d9e20.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9E30_004d9e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9E30_004d9e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9E30_004d9e30.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9E40_004d9e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9E40_004d9e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9E40_004d9e40.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9EC0_004d9ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9EC0_004d9ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9EC0_004d9ec0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9EF0_004d9ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9EF0_004d9ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9EF0_004d9ef0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA080_004da080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA080_004da080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA080_004da080.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA130_004da130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA130_004da130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA130_004da130.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA27C_004da27c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA27C_004da27c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA27C_004da27c.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA2E0_004da2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA2E0_004da2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA2E0_004da2e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA4D0_004da4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA4D0_004da4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA4D0_004da4d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA510_004da510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA510_004da510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA510_004da510.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA570_004da570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA570_004da570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA570_004da570.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA590_004da590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA590_004da590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA590_004da590.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA5C0_004da5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA5C0_004da5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA5C0_004da5c0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA864_004da864.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA864_004da864.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA864_004da864.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DABE0_004dabe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DABE0_004dabe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DABE0_004dabe0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DACB0_004dacb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DACB0_004dacb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DACB0_004dacb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DAD00_004dad00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DAD00_004dad00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DAD00_004dad00.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DADA0_004dada0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DADA0_004dada0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DADA0_004dada0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DAE20_004dae20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DAE20_004dae20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DAE20_004dae20.md
