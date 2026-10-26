# SKELETON FILL — Worker E chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEC30_004bec30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEC30_004bec30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEC30_004bec30.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEE40_004bee40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEE40_004bee40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEE40_004bee40.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEF30_004bef30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEF30_004bef30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEF30_004bef30.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF030_004bf030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF030_004bf030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF030_004bf030.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF160_004bf160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF160_004bf160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF160_004bf160.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_59_004bf170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_59_004bf170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_59_004bf170.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_60_004bf190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_60_004bf190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_60_004bf190.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF1A0_004bf1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF1A0_004bf1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF1A0_004bf1a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF1F0_004bf1f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF1F0_004bf1f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF1F0_004bf1f0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF240_004bf240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF240_004bf240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF240_004bf240.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_61_004bf260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_61_004bf260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_61_004bf260.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF270_004bf270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF270_004bf270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF270_004bf270.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF840_004bf840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF840_004bf840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF840_004bf840.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF870_004bf870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF870_004bf870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF870_004bf870.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BFC20_004bfc20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BFC20_004bfc20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BFC20_004bfc20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BFD80_004bfd80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BFD80_004bfd80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BFD80_004bfd80.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BFF30_004bff30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BFF30_004bff30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BFF30_004bff30.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BFFC0_004bffc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BFFC0_004bffc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BFFC0_004bffc0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C00C0_004c00c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C00C0_004c00c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C00C0_004c00c0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_110_004c0664.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_110_004c0664.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_110_004c0664.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0670_004c0670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0670_004c0670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0670_004c0670.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0700_004c0700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0700_004c0700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0700_004c0700.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0740_004c0740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0740_004c0740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0740_004c0740.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0840_004c0840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0840_004c0840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0840_004c0840.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0A80_004c0a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0A80_004c0a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0A80_004c0a80.md
