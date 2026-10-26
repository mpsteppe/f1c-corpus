# SKELETON FILL — Worker G chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5736F0_005736f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5736F0_005736f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5736F0_005736f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573700_00573700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573700_00573700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573700_00573700.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573AF0_00573af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573AF0_00573af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573AF0_00573af0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573B10_00573b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573B10_00573b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573B10_00573b10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_574D40_00574d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_574D40_00574d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_574D40_00574d40.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_574EA0_00574ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_574EA0_00574ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_574EA0_00574ea0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5750B0_005750b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5750B0_005750b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5750B0_005750b0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5751A0_005751a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5751A0_005751a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5751A0_005751a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_126_00575418.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_126_00575418.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_126_00575418.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_127_005755b3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_127_005755b3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_127_005755b3.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_575E70_00575e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_575E70_00575e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_575E70_00575e70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_130_00575e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_130_00575e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_130_00575e80.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_131_00575ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_131_00575ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_131_00575ea0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_575EB0_00575eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_575EB0_00575eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_575EB0_00575eb0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_132_00575ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_132_00575ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_132_00575ec0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_133_00575ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_133_00575ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_133_00575ee0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_575F10_00575f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_575F10_00575f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_575F10_00575f10.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576020_00576020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576020_00576020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576020_00576020.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576120_00576120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576120_00576120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576120_00576120.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5761F0_005761f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5761F0_005761f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5761F0_005761f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5762D0_005762d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5762D0_005762d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5762D0_005762d0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576320_00576320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576320_00576320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576320_00576320.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576460_00576460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576460_00576460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576460_00576460.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_134_00576590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_134_00576590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_134_00576590.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_576620_00576620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_576620_00576620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_576620_00576620.md
