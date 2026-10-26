# SKELETON FILL — Worker E chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_67_004d1c80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_67_004d1c80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_67_004d1c80.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_68_004d1ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_68_004d1ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_68_004d1ca0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D1CF0_004d1cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D1CF0_004d1cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D1CF0_004d1cf0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D20A0_004d20a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D20A0_004d20a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D20A0_004d20a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2430_004d2430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2430_004d2430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2430_004d2430.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2510_004d2510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2510_004d2510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2510_004d2510.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_69_004d2520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_69_004d2520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_69_004d2520.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_70_004d2540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_70_004d2540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_70_004d2540.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2550_004d2550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2550_004d2550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2550_004d2550.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2560_004d2560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2560_004d2560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2560_004d2560.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D25F0_004d25f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D25F0_004d25f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D25F0_004d25f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2670_004d2670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2670_004d2670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2670_004d2670.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D26F0_004d26f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D26F0_004d26f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D26F0_004d26f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2780_004d2780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2780_004d2780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2780_004d2780.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2D80_004d2d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2D80_004d2d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2D80_004d2d80.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2EE0_004d2ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2EE0_004d2ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2EE0_004d2ee0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2F50_004d2f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2F50_004d2f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2F50_004d2f50.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3230_004d3230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3230_004d3230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3230_004d3230.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D33D0_004d33d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D33D0_004d33d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D33D0_004d33d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3400_004d3400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3400_004d3400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3400_004d3400.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_71_004d3430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_71_004d3430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_71_004d3430.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3550_004d3550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3550_004d3550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3550_004d3550.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3610_004d3610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3610_004d3610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3610_004d3610.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3650_004d3650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3650_004d3650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3650_004d3650.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3700_004d3700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3700_004d3700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3700_004d3700.md
