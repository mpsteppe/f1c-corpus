# SKELETON FILL — Worker PA chunk 3/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D98A0_004d98a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D98A0_004d98a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D98A0_004d98a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC870_004ec870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC870_004ec870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC870_004ec870.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FFBD0_004ffbd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FFBD0_004ffbd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FFBD0_004ffbd0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51EC00_0051ec00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51EC00_0051ec00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51EC00_0051ec00.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5969C0_005969c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5969C0_005969c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5969C0_005969c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4330_005a4330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4330_005a4330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4330_005a4330.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40E5E0_0040e5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40E5E0_0040e5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40E5E0_0040e5e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421180_00421180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421180_00421180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421180_00421180.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_426A80_00426a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_426A80_00426a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_426A80_00426a80.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C430_0042c430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C430_0042c430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C430_0042c430.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_446EB0_00446eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_446EB0_00446eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_446EB0_00446eb0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459440_00459440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459440_00459440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459440_00459440.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46CA50_0046ca50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46CA50_0046ca50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46CA50_0046ca50.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490FD0_00490fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490FD0_00490fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490FD0_00490fd0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2690_004a2690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2690_004a2690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2690_004a2690.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1850_004b1850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1850_004b1850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1850_004b1850.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8670_004d8670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8670_004d8670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8670_004d8670.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5A30_004e5a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5A30_004e5a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5A30_004e5a30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5870_004f5870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5870_004f5870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5870_004f5870.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_510EA0_00510ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_510EA0_00510ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_510EA0_00510ea0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519DE0_00519de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519DE0_00519de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519DE0_00519de0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526870_00526870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526870_00526870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526870_00526870.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_554050_00554050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_554050_00554050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_554050_00554050.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_588021_00588021.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_588021_00588021.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_588021_00588021.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B6060_005b6060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B6060_005b6060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B6060_005b6060.md
