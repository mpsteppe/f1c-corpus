# SKELETON FILL — Worker B chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FE40_0045fe40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FE40_0045fe40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FE40_0045fe40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460310_00460310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460310_00460310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460310_00460310.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460390_00460390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460390_00460390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460390_00460390.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460490_00460490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460490_00460490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460490_00460490.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4605C0_004605c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4605C0_004605c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4605C0_004605c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4608F0_004608f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4608F0_004608f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4608F0_004608f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460930_00460930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460930_00460930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460930_00460930.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460A50_00460a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460A50_00460a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460A50_00460a50.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460A60_00460a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460A60_00460a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460A60_00460a60.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_81_00460cc7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_81_00460cc7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_81_00460cc7.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460CD0_00460cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460CD0_00460cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460CD0_00460cd0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461DA0_00461da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461DA0_00461da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461DA0_00461da0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461DF0_00461df0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461DF0_00461df0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461DF0_00461df0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462380_00462380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462380_00462380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462380_00462380.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4623E0_004623e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4623E0_004623e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4623E0_004623e0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462428_00462428.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462428_00462428.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462428_00462428.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462550_00462550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462550_00462550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462550_00462550.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462B30_00462b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462B30_00462b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462B30_00462b30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462B90_00462b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462B90_00462b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462B90_00462b90.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462BD0_00462bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462BD0_00462bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462BD0_00462bd0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462C00_00462c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462C00_00462c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462C00_00462c00.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462C30_00462c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462C30_00462c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462C30_00462c30.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462C60_00462c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462C60_00462c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462C60_00462c60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462C90_00462c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462C90_00462c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462C90_00462c90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462CDC_00462cdc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462CDC_00462cdc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462CDC_00462cdc.md
