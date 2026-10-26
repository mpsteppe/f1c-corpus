# SKELETON FILL — Worker G chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Destroy__RefCounter_details_Concurrency__MAEXXZ_005766a5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Destroy__RefCounter_details_Concurrency__MAEXXZ_005766a5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Destroy__RefCounter_details_Concurrency__MAEXXZ_005766a5.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5766B0_005766b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5766B0_005766b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5766B0_005766b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576730_00576730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576730_00576730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576730_00576730.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576780_00576780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576780_00576780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576780_00576780.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576830_00576830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576830_00576830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576830_00576830.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576A80_00576a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576A80_00576a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576A80_00576a80.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576A90_00576a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576A90_00576a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576A90_00576a90.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576B10_00576b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576B10_00576b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576B10_00576b10.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576B20_00576b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576B20_00576b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576B20_00576b20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_135_00576f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_135_00576f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_135_00576f20.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576F50_00576f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576F50_00576f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576F50_00576f50.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_136_00576f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_136_00576f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_136_00576f60.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_137_00576f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_137_00576f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_137_00576f80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576F90_00576f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576F90_00576f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576F90_00576f90.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_138_00576fa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_138_00576fa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_138_00576fa0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_139_00576fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_139_00576fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_139_00576fc0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577160_00577160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577160_00577160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577160_00577160.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_128_00577240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_128_00577240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_128_00577240.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5772E0_005772e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5772E0_005772e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5772E0_005772e0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_140_00577440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_140_00577440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_140_00577440.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577470_00577470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577470_00577470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577470_00577470.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_141_00577480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_141_00577480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_141_00577480.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_142_005774a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_142_005774a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_142_005774a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5774B0_005774b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5774B0_005774b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5774B0_005774b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_143_005774c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_143_005774c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_143_005774c0.md
