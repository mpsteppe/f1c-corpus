# SKELETON FILL — Worker F chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5263B0_005263b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5263B0_005263b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5263B0_005263b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5265C0_005265c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5265C0_005265c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5265C0_005265c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5265C5_005265c5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5265C5_005265c5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5265C5_005265c5.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_99_005265d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_99_005265d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_99_005265d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5265E0_005265e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5265E0_005265e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5265E0_005265e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_100_005265f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_100_005265f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_100_005265f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526600_00526600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526600_00526600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526600_00526600.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_101_00526630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_101_00526630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_101_00526630.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5267C0_005267c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5267C0_005267c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5267C0_005267c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526830_00526830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526830_00526830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526830_00526830.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526A90_00526a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526A90_00526a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526A90_00526a90.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526AD0_00526ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526AD0_00526ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526AD0_00526ad0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526C08_00526c08.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526C08_00526c08.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526C08_00526c08.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\fptc_00526d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\fptc_00526d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\fptc_00526d80.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_102_005272f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_102_005272f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_102_005272f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527300_00527300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527300_00527300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527300_00527300.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527360_00527360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527360_00527360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527360_00527360.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5278E0_005278e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5278E0_005278e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5278E0_005278e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527910_00527910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527910_00527910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527910_00527910.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527940_00527940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527940_00527940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527940_00527940.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5279A0_005279a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5279A0_005279a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5279A0_005279a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527A00_00527a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527A00_00527a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527A00_00527a00.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527F00_00527f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527F00_00527f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527F00_00527f00.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528B50_00528b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528B50_00528b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528B50_00528b50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528B60_00528b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528B60_00528b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528B60_00528b60.md
