# SKELETON FILL — Worker E chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_66_004cf590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_66_004cf590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_66_004cf590.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF5A0_004cf5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF5A0_004cf5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF5A0_004cf5a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF6B0_004cf6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF6B0_004cf6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF6B0_004cf6b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF720_004cf720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF720_004cf720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF720_004cf720.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF950_004cf950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF950_004cf950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF950_004cf950.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFA90_004cfa90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFA90_004cfa90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFA90_004cfa90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFBA0_004cfba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFBA0_004cfba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFBA0_004cfba0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFC00_004cfc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFC00_004cfc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFC00_004cfc00.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFD10_004cfd10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFD10_004cfd10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFD10_004cfd10.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFD80_004cfd80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFD80_004cfd80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFD80_004cfd80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFDE0_004cfde0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFDE0_004cfde0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFDE0_004cfde0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFE90_004cfe90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFE90_004cfe90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFE90_004cfe90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFF40_004cff40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFF40_004cff40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFF40_004cff40.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CFF90_004cff90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CFF90_004cff90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CFF90_004cff90.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0130_004d0130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0130_004d0130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0130_004d0130.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D02B0_004d02b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D02B0_004d02b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D02B0_004d02b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0310_004d0310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0310_004d0310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0310_004d0310.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0340_004d0340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0340_004d0340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0340_004d0340.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0370_004d0370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0370_004d0370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0370_004d0370.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0390_004d0390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0390_004d0390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0390_004d0390.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D03B0_004d03b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D03B0_004d03b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D03B0_004d03b0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D03C0_004d03c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D03C0_004d03c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D03C0_004d03c0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D03F0_004d03f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D03F0_004d03f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D03F0_004d03f0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D0410_004d0410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D0410_004d0410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D0410_004d0410.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D04F0_004d04f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D04F0_004d04f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D04F0_004d04f0.md
