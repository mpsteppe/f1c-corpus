# SKELETON FILL — Worker E chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3130_004e3130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3130_004e3130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3130_004e3130.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E31D0_004e31d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E31D0_004e31d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E31D0_004e31d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E32F0_004e32f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E32F0_004e32f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E32F0_004e32f0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_116_004e33b4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_116_004e33b4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_116_004e33b4.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E33C0_004e33c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E33C0_004e33c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E33C0_004e33c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E34F0_004e34f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E34F0_004e34f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E34F0_004e34f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3520_004e3520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3520_004e3520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3520_004e3520.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3570_004e3570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3570_004e3570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3570_004e3570.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3A90_004e3a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3A90_004e3a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3A90_004e3a90.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3BE0_004e3be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3BE0_004e3be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3BE0_004e3be0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3D70_004e3d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3D70_004e3d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3D70_004e3d70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3DC0_004e3dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3DC0_004e3dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3DC0_004e3dc0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3DE0_004e3de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3DE0_004e3de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3DE0_004e3de0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3E50_004e3e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3E50_004e3e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3E50_004e3e50.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3F00_004e3f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3F00_004e3f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3F00_004e3f00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4100_004e4100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4100_004e4100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4100_004e4100.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E44C0_004e44c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E44C0_004e44c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E44C0_004e44c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E46F0_004e46f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E46F0_004e46f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E46F0_004e46f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4800_004e4800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4800_004e4800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4800_004e4800.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E48E0_004e48e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E48E0_004e48e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E48E0_004e48e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4970_004e4970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4970_004e4970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4970_004e4970.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4980_004e4980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4980_004e4980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4980_004e4980.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4990_004e4990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4990_004e4990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4990_004e4990.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4A29_004e4a29.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4A29_004e4a29.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4A29_004e4a29.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4C30_004e4c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4C30_004e4c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4C30_004e4c30.md
