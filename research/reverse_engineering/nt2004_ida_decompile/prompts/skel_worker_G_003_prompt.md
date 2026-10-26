# SKELETON FILL — Worker G chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_569E90_00569e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_569E90_00569e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_569E90_00569e90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A220_0056a220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A220_0056a220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A220_0056a220.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A280_0056a280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A280_0056a280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A280_0056a280.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A460_0056a460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A460_0056a460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A460_0056a460.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A490_0056a490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A490_0056a490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A490_0056a490.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A530_0056a530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A530_0056a530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A530_0056a530.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A540_0056a540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A540_0056a540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A540_0056a540.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A630_0056a630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A630_0056a630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A630_0056a630.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A63B_0056a63b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A63B_0056a63b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A63B_0056a63b.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A640_0056a640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A640_0056a640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A640_0056a640.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A650_0056a650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A650_0056a650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A650_0056a650.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A660_0056a660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A660_0056a660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A660_0056a660.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_113_0056a670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_113_0056a670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_113_0056a670.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_114_0056a690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_114_0056a690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_114_0056a690.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A6A0_0056a6a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A6A0_0056a6a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A6A0_0056a6a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_115_0056a6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_115_0056a6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_115_0056a6b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_116_0056a6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_116_0056a6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_116_0056a6d0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___Gfacet_locale_std__UAEPAXI_Z_0056a6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___Gfacet_locale_std__UAEPAXI_Z_0056a6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___Gfacet_locale_std__UAEPAXI_Z_0056a6e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_117_0056a700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_117_0056a700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_117_0056a700.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A730_0056a730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A730_0056a730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A730_0056a730.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_118_0056a740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_118_0056a740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_118_0056a740.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_119_0056a760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_119_0056a760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_119_0056a760.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A770_0056a770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A770_0056a770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A770_0056a770.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A7B0_0056a7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A7B0_0056a7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A7B0_0056a7b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A880_0056a880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A880_0056a880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A880_0056a880.md
