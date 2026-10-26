# SKELETON FILL — Worker B chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451B90_00451b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451B90_00451b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451B90_00451b90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_71_00451bf6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_71_00451bf6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_71_00451bf6.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451C00_00451c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451C00_00451c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451C00_00451c00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451FF0_00451ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451FF0_00451ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451FF0_00451ff0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_452270_00452270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_452270_00452270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_452270_00452270.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_454D10_00454d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_454D10_00454d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_454D10_00454d10.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_454D70_00454d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_454D70_00454d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_454D70_00454d70.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4556B0_004556b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4556B0_004556b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4556B0_004556b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455760_00455760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455760_00455760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455760_00455760.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455890_00455890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455890_00455890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455890_00455890.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455930_00455930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455930_00455930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455930_00455930.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455960_00455960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455960_00455960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455960_00455960.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455BD0_00455bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455BD0_00455bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455BD0_00455bd0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_456750_00456750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_456750_00456750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_456750_00456750.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_72_00456878.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_72_00456878.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_72_00456878.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_456880_00456880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_456880_00456880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_456880_00456880.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4571E8_004571e8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4571E8_004571e8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4571E8_004571e8.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_457200_00457200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_457200_00457200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_457200_00457200.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_457380_00457380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_457380_00457380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_457380_00457380.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_73_00457838.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_73_00457838.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_73_00457838.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4582E0_004582e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4582E0_004582e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4582E0_004582e0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458470_00458470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458470_00458470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458470_00458470.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458570_00458570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458570_00458570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458570_00458570.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4587E0_004587e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4587E0_004587e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4587E0_004587e0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458C10_00458c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458C10_00458c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458C10_00458c10.md
