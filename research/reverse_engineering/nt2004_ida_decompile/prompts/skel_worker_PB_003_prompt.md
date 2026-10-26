# SKELETON FILL — Worker PB chunk 3/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA870_004da870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA870_004da870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA870_004da870.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECA90_004eca90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECA90_004eca90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECA90_004eca90.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501990_00501990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501990_00501990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501990_00501990.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529DB0_00529db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529DB0_00529db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529DB0_00529db0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598650_00598650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598650_00598650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598650_00598650.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B2000_005b2000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B2000_005b2000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B2000_005b2000.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40F2D0_0040f2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40F2D0_0040f2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40F2D0_0040f2d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421590_00421590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421590_00421590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421590_00421590.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428180_00428180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428180_00428180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428180_00428180.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42E720_0042e720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42E720_0042e720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42E720_0042e720.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_452530_00452530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_452530_00452530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_452530_00452530.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C2B0_0045c2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C2B0_0045c2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C2B0_0045c2b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E8B0_0046e8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E8B0_0046e8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E8B0_0046e8b0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C450_0049c450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C450_0049c450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C450_0049c450.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A4870_004a4870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A4870_004a4870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A4870_004a4870.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4210_004b4210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4210_004b4210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4210_004b4210.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD490_004dd490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD490_004dd490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD490_004dd490.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E7A70_004e7a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E7A70_004e7a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E7A70_004e7a70.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FF780_004ff780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FF780_004ff780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FF780_004ff780.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_513830_00513830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_513830_00513830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_513830_00513830.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F650_0051f650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F650_0051f650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F650_0051f650.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528A00_00528a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528A00_00528a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528A00_00528a00.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_554233_00554233.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_554233_00554233.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_554233_00554233.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591970_00591970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591970_00591970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591970_00591970.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B6930_005b6930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B6930_005b6930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B6930_005b6930.md
