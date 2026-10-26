# SKELETON FILL — Worker B chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F2C0_0042f2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F2C0_0042f2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F2C0_0042f2c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F2D0_0042f2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F2D0_0042f2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F2D0_0042f2d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F310_0042f310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F310_0042f310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F310_0042f310.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F530_0042f530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F530_0042f530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F530_0042f530.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_16_0042f540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_16_0042f540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_16_0042f540.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_17_0042f560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_17_0042f560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_17_0042f560.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F570_0042f570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F570_0042f570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F570_0042f570.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F640_0042f640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F640_0042f640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F640_0042f640.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F950_0042f950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F950_0042f950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F950_0042f950.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42FA50_0042fa50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42FA50_0042fa50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42FA50_0042fa50.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_18_0042fcb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_18_0042fcb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_18_0042fcb0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_430470_00430470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_430470_00430470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_430470_00430470.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_19_00430480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_19_00430480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_19_00430480.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4304A0_004304a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4304A0_004304a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4304A0_004304a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4304C0_004304c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4304C0_004304c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4304C0_004304c0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_430A90_00430a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_430A90_00430a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_430A90_00430a90.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_430DC0_00430dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_430DC0_00430dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_430DC0_00430dc0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431790_00431790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431790_00431790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431790_00431790.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431A30_00431a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431A30_00431a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431A30_00431a30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431A70_00431a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431A70_00431a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431A70_00431a70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431E20_00431e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431E20_00431e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431E20_00431e20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431E40_00431e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431E40_00431e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431E40_00431e40.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431E80_00431e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431E80_00431e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431E80_00431e80.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_25_00431ef4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_25_00431ef4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_25_00431ef4.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_431F00_00431f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_431F00_00431f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_431F00_00431f00.md
