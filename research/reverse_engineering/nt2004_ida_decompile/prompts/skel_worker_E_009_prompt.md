# SKELETON FILL — Worker E chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0500_004d0500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0500_004d0500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0500_004d0500.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0520_004d0520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0520_004d0520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0520_004d0520.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0530_004d0530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0530_004d0530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0530_004d0530.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0550_004d0550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0550_004d0550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0550_004d0550.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0560_004d0560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0560_004d0560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0560_004d0560.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0670_004d0670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0670_004d0670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0670_004d0670.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D06E0_004d06e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D06E0_004d06e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D06E0_004d06e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0720_004d0720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0720_004d0720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0720_004d0720.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0790_004d0790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0790_004d0790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0790_004d0790.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D07D0_004d07d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D07D0_004d07d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D07D0_004d07d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0810_004d0810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0810_004d0810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0810_004d0810.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0838_004d0838.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0838_004d0838.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0838_004d0838.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0840_004d0840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0840_004d0840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0840_004d0840.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D08E0_004d08e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D08E0_004d08e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D08E0_004d08e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0D00_004d0d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0D00_004d0d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0D00_004d0d00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1850_004d1850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1850_004d1850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1850_004d1850.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1890_004d1890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1890_004d1890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1890_004d1890.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D18B0_004d18b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D18B0_004d18b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D18B0_004d18b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D18F0_004d18f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D18F0_004d18f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D18F0_004d18f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1930_004d1930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1930_004d1930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1930_004d1930.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1940_004d1940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1940_004d1940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1940_004d1940.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D19F0_004d19f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D19F0_004d19f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D19F0_004d19f0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1A80_004d1a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1A80_004d1a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1A80_004d1a80.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1B50_004d1b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1B50_004d1b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1B50_004d1b50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1C70_004d1c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1C70_004d1c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1C70_004d1c70.md
