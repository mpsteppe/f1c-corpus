# SKELETON FILL — Worker D chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1380_004b1380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1380_004b1380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1380_004b1380.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B13D0_004b13d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B13D0_004b13d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B13D0_004b13d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B14E0_004b14e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B14E0_004b14e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B14E0_004b14e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1500_004b1500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1500_004b1500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1500_004b1500.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1520_004b1520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1520_004b1520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1520_004b1520.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1540_004b1540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1540_004b1540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1540_004b1540.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1590_004b1590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1590_004b1590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1590_004b1590.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1740_004b1740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1740_004b1740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1740_004b1740.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_47_004b1770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_47_004b1770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_47_004b1770.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1780_004b1780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1780_004b1780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1780_004b1780.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1790_004b1790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1790_004b1790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1790_004b1790.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_48_004b17e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_48_004b17e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_48_004b17e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B17F0_004b17f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B17F0_004b17f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B17F0_004b17f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_104_004b1800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_104_004b1800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_104_004b1800.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_105_004b1820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_105_004b1820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_105_004b1820.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1840_004b1840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1840_004b1840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1840_004b1840.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1A80_004b1a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1A80_004b1a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1A80_004b1a80.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1BF0_004b1bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1BF0_004b1bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1BF0_004b1bf0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1C30_004b1c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1C30_004b1c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1C30_004b1c30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1C50_004b1c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1C50_004b1c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1C50_004b1c50.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1C70_004b1c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1C70_004b1c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1C70_004b1c70.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1CF0_004b1cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1CF0_004b1cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1CF0_004b1cf0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1F30_004b1f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1F30_004b1f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1F30_004b1f30.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1F80_004b1f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1F80_004b1f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1F80_004b1f80.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B25B0_004b25b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B25B0_004b25b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B25B0_004b25b0.md
