# SKELETON FILL — Worker PD chunk 2/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6E10_004d6e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6E10_004d6e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6E10_004d6e10.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF3F0_004ef3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF3F0_004ef3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF3F0_004ef3f0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5208C0_005208c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5208C0_005208c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5208C0_005208c0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_537C10_00537c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_537C10_00537c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_537C10_00537c10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5957F0_005957f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5957F0_005957f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5957F0_005957f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_445390_00445390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_445390_00445390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_445390_00445390.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45BA00_0045ba00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45BA00_0045ba00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45BA00_0045ba00.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46D190_0046d190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46D190_0046d190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46D190_0046d190.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E120_0048e120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E120_0048e120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E120_0048e120.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B20D0_004b20d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B20D0_004b20d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B20D0_004b20d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BACD0_004bacd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BACD0_004bacd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BACD0_004bacd0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E51B0_004e51b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E51B0_004e51b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E51B0_004e51b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50D370_0050d370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50D370_0050d370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50D370_0050d370.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52AE20_0052ae20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52AE20_0052ae20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52AE20_0052ae20.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4F00_005a4f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4F00_005a4f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4F00_005a4f00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_402C00_00402c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_402C00_00402c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_402C00_00402c00.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410E10_00410e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410E10_00410e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410E10_00410e10.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_422260_00422260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_422260_00422260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_422260_00422260.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43AF90_0043af90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43AF90_0043af90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43AF90_0043af90.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_449920_00449920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_449920_00449920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_449920_00449920.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460F00_00460f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460F00_00460f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460F00_00460f00.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477F70_00477f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477F70_00477f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477F70_00477f70.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ABA40_004aba40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ABA40_004aba40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ABA40_004aba40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C3180_004c3180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C3180_004c3180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C3180_004c3180.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8450_004d8450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8450_004d8450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8450_004d8450.md
