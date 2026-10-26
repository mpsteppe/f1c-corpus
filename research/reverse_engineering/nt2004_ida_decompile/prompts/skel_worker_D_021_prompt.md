# SKELETON FILL — Worker D chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3630_004b3630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3630_004b3630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3630_004b3630.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3840_004b3840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3840_004b3840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3840_004b3840.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B39B0_004b39b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B39B0_004b39b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B39B0_004b39b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3AD0_004b3ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3AD0_004b3ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3AD0_004b3ad0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3B40_004b3b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3B40_004b3b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3B40_004b3b40.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3BC0_004b3bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3BC0_004b3bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3BC0_004b3bc0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3C20_004b3c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3C20_004b3c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3C20_004b3c20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3C90_004b3c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3C90_004b3c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3C90_004b3c90.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3D00_004b3d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3D00_004b3d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3D00_004b3d00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3D70_004b3d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3D70_004b3d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3D70_004b3d70.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3E30_004b3e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3E30_004b3e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3E30_004b3e30.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B3EF0_004b3ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B3EF0_004b3ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B3EF0_004b3ef0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4000_004b4000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4000_004b4000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4000_004b4000.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4600_004b4600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4600_004b4600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4600_004b4600.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B48F0_004b48f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B48F0_004b48f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B48F0_004b48f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4AC0_004b4ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4AC0_004b4ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4AC0_004b4ac0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4AF0_004b4af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4AF0_004b4af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4AF0_004b4af0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4BC0_004b4bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4BC0_004b4bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4BC0_004b4bc0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4CA0_004b4ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4CA0_004b4ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4CA0_004b4ca0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4D00_004b4d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4D00_004b4d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4D00_004b4d00.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4D40_004b4d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4D40_004b4d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4D40_004b4d40.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4D80_004b4d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4D80_004b4d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4D80_004b4d80.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4E70_004b4e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4E70_004b4e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4E70_004b4e70.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4F80_004b4f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4F80_004b4f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4F80_004b4f80.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5350_004b5350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5350_004b5350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5350_004b5350.md
