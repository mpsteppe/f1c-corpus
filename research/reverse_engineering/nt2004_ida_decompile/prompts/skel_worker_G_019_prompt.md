# SKELETON FILL — Worker G chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59ABA0_0059aba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59ABA0_0059aba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59ABA0_0059aba0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59ABD0_0059abd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59ABD0_0059abd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59ABD0_0059abd0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59AC30_0059ac30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59AC30_0059ac30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59AC30_0059ac30.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59AD80_0059ad80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59AD80_0059ad80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59AD80_0059ad80.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59AE80_0059ae80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59AE80_0059ae80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59AE80_0059ae80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59BEC0_0059bec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59BEC0_0059bec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59BEC0_0059bec0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_158_0059cb00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_158_0059cb00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_158_0059cb00.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_159_0059cb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_159_0059cb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_159_0059cb10.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D3D0_0059d3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D3D0_0059d3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D3D0_0059d3d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D420_0059d420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D420_0059d420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D420_0059d420.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D5F0_0059d5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D5F0_0059d5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D5F0_0059d5f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D610_0059d610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D610_0059d610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D610_0059d610.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E0F0_0059e0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E0F0_0059e0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E0F0_0059e0f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E170_0059e170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E170_0059e170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E170_0059e170.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E1D0_0059e1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E1D0_0059e1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E1D0_0059e1d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E670_0059e670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E670_0059e670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E670_0059e670.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E690_0059e690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E690_0059e690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E690_0059e690.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59EA28_0059ea28.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59EA28_0059ea28.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59EA28_0059ea28.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59EA50_0059ea50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59EA50_0059ea50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59EA50_0059ea50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59EE70_0059ee70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59EE70_0059ee70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59EE70_0059ee70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59EED0_0059eed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59EED0_0059eed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59EED0_0059eed0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59EF10_0059ef10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59EF10_0059ef10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59EF10_0059ef10.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59F020_0059f020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59F020_0059f020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59F020_0059f020.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59F1B0_0059f1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59F1B0_0059f1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59F1B0_0059f1b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59F2A0_0059f2a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59F2A0_0059f2a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59F2A0_0059f2a0.md
