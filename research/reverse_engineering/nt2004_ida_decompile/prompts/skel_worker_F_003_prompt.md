# SKELETON FILL — Worker F chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0E20_004f0e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0E20_004f0e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0E20_004f0e20.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0EB0_004f0eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0EB0_004f0eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0EB0_004f0eb0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_87_004f0ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_87_004f0ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_87_004f0ee0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0EF0_004f0ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0EF0_004f0ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0EF0_004f0ef0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0F50_004f0f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0F50_004f0f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0F50_004f0f50.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1140_004f1140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1140_004f1140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1140_004f1140.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1170_004f1170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1170_004f1170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1170_004f1170.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1720_004f1720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1720_004f1720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1720_004f1720.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1830_004f1830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1830_004f1830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1830_004f1830.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1860_004f1860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1860_004f1860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1860_004f1860.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F1880_004f1880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F1880_004f1880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F1880_004f1880.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2400_004f2400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2400_004f2400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2400_004f2400.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2A90_004f2a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2A90_004f2a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2A90_004f2a90.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2AE0_004f2ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2AE0_004f2ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2AE0_004f2ae0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2B40_004f2b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2B40_004f2b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2B40_004f2b40.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2B80_004f2b80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2B80_004f2b80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2B80_004f2b80.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3390_004f3390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3390_004f3390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3390_004f3390.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3B10_004f3b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3B10_004f3b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3B10_004f3b10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3D10_004f3d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3D10_004f3d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3D10_004f3d10.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3E50_004f3e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3E50_004f3e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3E50_004f3e50.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3F90_004f3f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3F90_004f3f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3F90_004f3f90.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F43E0_004f43e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F43E0_004f43e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F43E0_004f43e0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F44B0_004f44b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F44B0_004f44b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F44B0_004f44b0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F4D30_004f4d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F4D30_004f4d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F4D30_004f4d30.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F53B0_004f53b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F53B0_004f53b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F53B0_004f53b0.md
