# SKELETON FILL — Worker E chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6CF0_004d6cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6CF0_004d6cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6CF0_004d6cf0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7548_004d7548.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7548_004d7548.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7548_004d7548.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7550_004d7550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7550_004d7550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7550_004d7550.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7750_004d7750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7750_004d7750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7750_004d7750.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7C40_004d7c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7C40_004d7c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7C40_004d7c40.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7D40_004d7d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7D40_004d7d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7D40_004d7d40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7DA0_004d7da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7DA0_004d7da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7DA0_004d7da0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7F60_004d7f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7F60_004d7f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7F60_004d7f60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8080_004d8080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8080_004d8080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8080_004d8080.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D80F0_004d80f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D80F0_004d80f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D80F0_004d80f0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D81D0_004d81d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D81D0_004d81d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D81D0_004d81d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D82E0_004d82e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D82E0_004d82e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D82E0_004d82e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D83C0_004d83c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D83C0_004d83c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D83C0_004d83c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D83D0_004d83d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D83D0_004d83d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D83D0_004d83d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8430_004d8430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8430_004d8430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8430_004d8430.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8860_004d8860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8860_004d8860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8860_004d8860.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8960_004d8960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8960_004d8960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8960_004d8960.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D89D0_004d89d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D89D0_004d89d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D89D0_004d89d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D97E0_004d97e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D97E0_004d97e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D97E0_004d97e0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9810_004d9810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9810_004d9810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9810_004d9810.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9820_004d9820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9820_004d9820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9820_004d9820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9830_004d9830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9830_004d9830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9830_004d9830.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9870_004d9870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9870_004d9870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9870_004d9870.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9880_004d9880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9880_004d9880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9880_004d9880.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9AE0_004d9ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9AE0_004d9ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9AE0_004d9ae0.md
