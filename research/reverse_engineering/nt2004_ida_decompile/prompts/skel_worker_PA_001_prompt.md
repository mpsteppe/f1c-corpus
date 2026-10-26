# SKELETON FILL — Worker PA chunk 1/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_511500_00511500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_511500_00511500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_511500_00511500.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4612C0_004612c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4612C0_004612c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4612C0_004612c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_509B10_00509b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_509B10_00509b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_509B10_00509b10.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B83D0_004b83d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B83D0_004b83d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B83D0_004b83d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5107B0_005107b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5107B0_005107b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5107B0_005107b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416E90_00416e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416E90_00416e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416E90_00416e90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45AC00_0045ac00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45AC00_0045ac00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45AC00_0045ac00.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_483AD0_00483ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_483AD0_00483ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_483AD0_00483ad0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BD350_004bd350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BD350_004bd350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BD350_004bd350.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5070_004d5070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5070_004d5070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5070_004d5070.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FCC70_004fcc70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FCC70_004fcc70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FCC70_004fcc70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528430_00528430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528430_00528430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528430_00528430.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_596220_00596220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_596220_00596220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_596220_00596220.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409CE0_00409ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409CE0_00409ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409CE0_00409ce0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437B30_00437b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437B30_00437b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437B30_00437b30.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468B10_00468b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468B10_00468b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468B10_00468b10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AAB60_004aab60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AAB60_004aab60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AAB60_004aab60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E2AD0_004e2ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E2AD0_004e2ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E2AD0_004e2ad0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50AAE0_0050aae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50AAE0_0050aae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50AAE0_0050aae0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_516570_00516570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_516570_00516570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_516570_00516570.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54193D_0054193d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54193D_0054193d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54193D_0054193d.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AFBB0_005afbb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AFBB0_005afbb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AFBB0_005afbb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41E340_0041e340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41E340_0041e340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41E340_0041e340.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_439110_00439110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_439110_00439110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_439110_00439110.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46A250_0046a250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46A250_0046a250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46A250_0046a250.md
