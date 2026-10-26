# SKELETON FILL — Worker F chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50CA00_0050ca00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50CA00_0050ca00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50CA00_0050ca00.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50CCE0_0050cce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50CCE0_0050cce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50CCE0_0050cce0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50CE30_0050ce30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50CE30_0050ce30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50CE30_0050ce30.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50D130_0050d130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50D130_0050d130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50D130_0050d130.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50DFE0_0050dfe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50DFE0_0050dfe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50DFE0_0050dfe0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50E010_0050e010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50E010_0050e010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50E010_0050e010.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50E3C0_0050e3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50E3C0_0050e3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50E3C0_0050e3c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50E400_0050e400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50E400_0050e400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50E400_0050e400.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50EC00_0050ec00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50EC00_0050ec00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50EC00_0050ec00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50EC40_0050ec40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50EC40_0050ec40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50EC40_0050ec40.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50ECB0_0050ecb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50ECB0_0050ecb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50ECB0_0050ecb0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50ED40_0050ed40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50ED40_0050ed40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50ED40_0050ed40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50ED80_0050ed80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50ED80_0050ed80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50ED80_0050ed80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50EDC0_0050edc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50EDC0_0050edc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50EDC0_0050edc0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50F760_0050f760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50F760_0050f760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50F760_0050f760.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50F890_0050f890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50F890_0050f890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50F890_0050f890.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50F920_0050f920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50F920_0050f920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50F920_0050f920.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50FD30_0050fd30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50FD30_0050fd30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50FD30_0050fd30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_510210_00510210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_510210_00510210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_510210_00510210.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5102E0_005102e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5102E0_005102e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5102E0_005102e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_510420_00510420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_510420_00510420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_510420_00510420.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_510540_00510540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_510540_00510540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_510540_00510540.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_510C10_00510c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_510C10_00510c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_510C10_00510c10.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_513FA0_00513fa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_513FA0_00513fa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_513FA0_00513fa0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514000_00514000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514000_00514000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514000_00514000.md
