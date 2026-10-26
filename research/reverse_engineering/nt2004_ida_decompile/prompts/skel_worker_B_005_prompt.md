# SKELETON FILL — Worker B chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F6B0_0041f6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F6B0_0041f6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F6B0_0041f6b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F800_0041f800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F800_0041f800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F800_0041f800.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41FB50_0041fb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41FB50_0041fb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41FB50_0041fb50.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421970_00421970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421970_00421970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421970_00421970.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421B60_00421b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421B60_00421b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421B60_00421b60.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421CA0_00421ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421CA0_00421ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421CA0_00421ca0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421EF0_00421ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421EF0_00421ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421EF0_00421ef0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_423380_00423380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_423380_00423380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_423380_00423380.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_423790_00423790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_423790_00423790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_423790_00423790.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_424BC0_00424bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_424BC0_00424bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_424BC0_00424bc0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_19_00424c25.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_19_00424c25.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_19_00424c25.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_424C30_00424c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_424C30_00424c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_424C30_00424c30.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_424C60_00424c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_424C60_00424c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_424C60_00424c60.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_425DE0_00425de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_425DE0_00425de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_425DE0_00425de0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_426340_00426340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_426340_00426340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_426340_00426340.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427140_00427140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427140_00427140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427140_00427140.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4271B0_004271b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4271B0_004271b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4271B0_004271b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427260_00427260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427260_00427260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427260_00427260.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4272D0_004272d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4272D0_004272d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4272D0_004272d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427540_00427540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427540_00427540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427540_00427540.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4276F0_004276f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4276F0_004276f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4276F0_004276f0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427A00_00427a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427A00_00427a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427A00_00427a00.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427B50_00427b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427B50_00427b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427B50_00427b50.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_20_00427b8f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_20_00427b8f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_20_00427b8f.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427B90_00427b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427B90_00427b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427B90_00427b90.md
