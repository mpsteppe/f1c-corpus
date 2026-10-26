# SKELETON FILL — Worker PB chunk 2/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9460_004b9460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9460_004b9460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9460_004b9460.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EADE0_004eade0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EADE0_004eade0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EADE0_004eade0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2650_004f2650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2650_004f2650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2650_004f2650.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527F30_00527f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527F30_00527f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527F30_00527f30.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_538750_00538750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_538750_00538750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_538750_00538750.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_423870_00423870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_423870_00423870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_423870_00423870.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44BEC0_0044bec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44BEC0_0044bec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44BEC0_0044bec0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464C60_00464c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464C60_00464c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464C60_00464c60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4753B0_004753b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4753B0_004753b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4753B0_004753b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A33D0_004a33d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A33D0_004a33d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A33D0_004a33d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9790_004b9790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9790_004b9790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9790_004b9790.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0D50_004d0d50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0D50_004d0d50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0D50_004d0d50.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50B4E0_0050b4e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50B4E0_0050b4e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50B4E0_0050b4e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51A8C0_0051a8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51A8C0_0051a8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51A8C0_0051a8c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595E00_00595e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595E00_00595e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595E00_00595e00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8280_005b8280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8280_005b8280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8280_005b8280.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A280_0040a280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A280_0040a280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A280_0040a280.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414650_00414650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414650_00414650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414650_00414650.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4303B0_004303b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4303B0_004303b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4303B0_004303b0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E640_0043e640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E640_0043e640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E640_0043e640.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458810_00458810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458810_00458810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458810_00458810.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468080_00468080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468080_00468080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468080_00468080.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A3710_004a3710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A3710_004a3710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A3710_004a3710.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BB930_004bb930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BB930_004bb930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BB930_004bb930.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CB410_004cb410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CB410_004cb410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CB410_004cb410.md
