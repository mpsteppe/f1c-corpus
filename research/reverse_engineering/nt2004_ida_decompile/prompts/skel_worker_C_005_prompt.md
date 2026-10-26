# SKELETON FILL — Worker C chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FBE0_0046fbe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FBE0_0046fbe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FBE0_0046fbe0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FC90_0046fc90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FC90_0046fc90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FC90_0046fc90.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FCB0_0046fcb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FCB0_0046fcb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FCB0_0046fcb0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FCD0_0046fcd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FCD0_0046fcd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FCD0_0046fcd0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FD30_0046fd30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FD30_0046fd30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FD30_0046fd30.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FD90_0046fd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FD90_0046fd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FD90_0046fd90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FF80_0046ff80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FF80_0046ff80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FF80_0046ff80.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FF90_0046ff90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FF90_0046ff90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FF90_0046ff90.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_470070_00470070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_470070_00470070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_470070_00470070.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4700C0_004700c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4700C0_004700c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4700C0_004700c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_470120_00470120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_470120_00470120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_470120_00470120.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_470330_00470330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_470330_00470330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_470330_00470330.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_470540_00470540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_470540_00470540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_470540_00470540.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_470560_00470560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_470560_00470560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_470560_00470560.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4705F0_004705f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4705F0_004705f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4705F0_004705f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4706C0_004706c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4706C0_004706c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4706C0_004706c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471050_00471050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471050_00471050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471050_00471050.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4710E0_004710e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4710E0_004710e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4710E0_004710e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471470_00471470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471470_00471470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471470_00471470.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471480_00471480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471480_00471480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471480_00471480.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471490_00471490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471490_00471490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471490_00471490.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471990_00471990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471990_00471990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471990_00471990.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_85_00471bd4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_85_00471bd4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_85_00471bd4.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471BE0_00471be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471BE0_00471be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471BE0_00471be0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471BF0_00471bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471BF0_00471bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471BF0_00471bf0.md
