# SKELETON FILL — Worker D chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E330_0049e330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E330_0049e330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E330_0049e330.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E3A0_0049e3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E3A0_0049e3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E3A0_0049e3a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E4A0_0049e4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E4A0_0049e4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E4A0_0049e4a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E4D0_0049e4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E4D0_0049e4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E4D0_0049e4d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E500_0049e500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E500_0049e500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E500_0049e500.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EA00_0049ea00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EA00_0049ea00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EA00_0049ea00.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EA10_0049ea10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EA10_0049ea10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EA10_0049ea10.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EA70_0049ea70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EA70_0049ea70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EA70_0049ea70.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EAD0_0049ead0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EAD0_0049ead0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EAD0_0049ead0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EB20_0049eb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EB20_0049eb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EB20_0049eb20.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EB30_0049eb30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EB30_0049eb30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EB30_0049eb30.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EBA2_0049eba2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EBA2_0049eba2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EBA2_0049eba2.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EBB0_0049ebb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EBB0_0049ebb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EBB0_0049ebb0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EC10_0049ec10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EC10_0049ec10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EC10_0049ec10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EC20_0049ec20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EC20_0049ec20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EC20_0049ec20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49EC60_0049ec60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49EC60_0049ec60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49EC60_0049ec60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49ECE0_0049ece0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49ECE0_0049ece0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49ECE0_0049ece0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49ECF0_0049ecf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49ECF0_0049ecf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49ECF0_0049ecf0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F130_0049f130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F130_0049f130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F130_0049f130.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F3D9_0049f3d9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F3D9_0049f3d9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F3D9_0049f3d9.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F530_0049f530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F530_0049f530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F530_0049f530.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F5C0_0049f5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F5C0_0049f5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F5C0_0049f5c0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F5F0_0049f5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F5F0_0049f5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F5F0_0049f5f0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F640_0049f640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F640_0049f640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F640_0049f640.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F670_0049f670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F670_0049f670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F670_0049f670.md
