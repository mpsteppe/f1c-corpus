# SKELETON FILL — Worker H chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8770_005b8770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8770_005b8770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8770_005b8770.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B87A0_005b87a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B87A0_005b87a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B87A0_005b87a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8850_005b8850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8850_005b8850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8850_005b8850.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B88F0_005b88f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B88F0_005b88f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B88F0_005b88f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8900_005b8900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8900_005b8900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8900_005b8900.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8910_005b8910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8910_005b8910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8910_005b8910.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8D40_005b8d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8D40_005b8d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8D40_005b8d40.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8F70_005b8f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8F70_005b8f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8F70_005b8f70.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9BC0_005b9bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9BC0_005b9bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9BC0_005b9bc0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9C40_005b9c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9C40_005b9c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9C40_005b9c40.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9C60_005b9c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9C60_005b9c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9C60_005b9c60.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9D70_005b9d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9D70_005b9d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9D70_005b9d70.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9D90_005b9d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9D90_005b9d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9D90_005b9d90.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9EE0_005b9ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9EE0_005b9ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9EE0_005b9ee0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9F20_005b9f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9F20_005b9f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9F20_005b9f20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9F40_005b9f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9F40_005b9f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9F40_005b9f40.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9F60_005b9f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9F60_005b9f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9F60_005b9f60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9F80_005b9f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9F80_005b9f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9F80_005b9f80.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9F90_005b9f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9F90_005b9f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9F90_005b9f90.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9FC0_005b9fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9FC0_005b9fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9FC0_005b9fc0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9FF0_005b9ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9FF0_005b9ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9FF0_005b9ff0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA040_005ba040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA040_005ba040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA040_005ba040.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA050_005ba050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA050_005ba050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA050_005ba050.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA070_005ba070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA070_005ba070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA070_005ba070.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA0C0_005ba0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA0C0_005ba0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA0C0_005ba0c0.md
