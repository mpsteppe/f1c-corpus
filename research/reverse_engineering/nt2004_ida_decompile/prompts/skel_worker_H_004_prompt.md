# SKELETON FILL — Worker H chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1DC0_005b1dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1DC0_005b1dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1DC0_005b1dc0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1EA0_005b1ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1EA0_005b1ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1EA0_005b1ea0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1F50_005b1f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1F50_005b1f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1F50_005b1f50.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B24B0_005b24b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B24B0_005b24b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B24B0_005b24b0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B3460_005b3460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B3460_005b3460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B3460_005b3460.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B3B20_005b3b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B3B20_005b3b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B3B20_005b3b20.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B3D50_005b3d50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B3D50_005b3d50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B3D50_005b3d50.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4020_005b4020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4020_005b4020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4020_005b4020.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4060_005b4060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4060_005b4060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4060_005b4060.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B40B0_005b40b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B40B0_005b40b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B40B0_005b40b0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B41C0_005b41c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B41C0_005b41c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B41C0_005b41c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B43F0_005b43f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B43F0_005b43f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B43F0_005b43f0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4550_005b4550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4550_005b4550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4550_005b4550.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4570_005b4570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4570_005b4570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4570_005b4570.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4590_005b4590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4590_005b4590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4590_005b4590.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4A00_005b4a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4A00_005b4a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4A00_005b4a00.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4BC0_005b4bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4BC0_005b4bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4BC0_005b4bc0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4BD0_005b4bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4BD0_005b4bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4BD0_005b4bd0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4BE0_005b4be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4BE0_005b4be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4BE0_005b4be0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4C69_005b4c69.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4C69_005b4c69.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4C69_005b4c69.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4C70_005b4c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4C70_005b4c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4C70_005b4c70.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4CC0_005b4cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4CC0_005b4cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4CC0_005b4cc0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4E60_005b4e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4E60_005b4e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4E60_005b4e60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5030_005b5030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5030_005b5030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5030_005b5030.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5090_005b5090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5090_005b5090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5090_005b5090.md
