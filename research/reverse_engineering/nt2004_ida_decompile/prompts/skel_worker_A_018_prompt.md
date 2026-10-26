# SKELETON FILL — Worker A chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A150_0040a150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A150_0040a150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A150_0040a150.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A1B0_0040a1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A1B0_0040a1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A1B0_0040a1b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A600_0040a600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A600_0040a600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A600_0040a600.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A660_0040a660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A660_0040a660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A660_0040a660.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A6C0_0040a6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A6C0_0040a6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A6C0_0040a6c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A730_0040a730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A730_0040a730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A730_0040a730.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A7D0_0040a7d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A7D0_0040a7d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A7D0_0040a7d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A820_0040a820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A820_0040a820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A820_0040a820.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40B9B0_0040b9b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40B9B0_0040b9b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40B9B0_0040b9b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BAB0_0040bab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BAB0_0040bab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BAB0_0040bab0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BB10_0040bb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BB10_0040bb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BB10_0040bb10.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BB40_0040bb40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BB40_0040bb40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BB40_0040bb40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BB80_0040bb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BB80_0040bb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BB80_0040bb80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BEC0_0040bec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BEC0_0040bec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BEC0_0040bec0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C3B0_0040c3b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C3B0_0040c3b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C3B0_0040c3b0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C3C0_0040c3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C3C0_0040c3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C3C0_0040c3c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C3D0_0040c3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C3D0_0040c3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C3D0_0040c3d0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C3E0_0040c3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C3E0_0040c3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C3E0_0040c3e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C3F0_0040c3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C3F0_0040c3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C3F0_0040c3f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C400_0040c400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C400_0040c400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C400_0040c400.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C410_0040c410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C410_0040c410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C410_0040c410.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C420_0040c420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C420_0040c420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C420_0040c420.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C430_0040c430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C430_0040c430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C430_0040c430.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C450_0040c450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C450_0040c450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C450_0040c450.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40C460_0040c460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40C460_0040c460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40C460_0040c460.md
