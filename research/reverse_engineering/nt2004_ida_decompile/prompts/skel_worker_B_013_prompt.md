# SKELETON FILL — Worker B chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_14_0044f000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_14_0044f000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_14_0044f000.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_15_0044f060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_15_0044f060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_15_0044f060.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_45_0044f0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_45_0044f0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_45_0044f0a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_16_0044f0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_16_0044f0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_16_0044f0c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_17_0044f120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_17_0044f120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_17_0044f120.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_47_0044f160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_47_0044f160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_47_0044f160.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F170_0044f170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F170_0044f170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F170_0044f170.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_18_0044f180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_18_0044f180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_18_0044f180.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_48_0044f1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_48_0044f1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_48_0044f1c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_19_0044f1e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_19_0044f1e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_19_0044f1e0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F230_0044f230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F230_0044f230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F230_0044f230.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_20_0044f240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_20_0044f240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_20_0044f240.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_50_0044f280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_50_0044f280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_50_0044f280.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_21_0044f2a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_21_0044f2a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_21_0044f2a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_22_0044f300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_22_0044f300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_22_0044f300.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_23_0044f360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_23_0044f360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_23_0044f360.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_24_0044f3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_24_0044f3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_24_0044f3c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_25_0044f420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_25_0044f420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_25_0044f420.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_26_0044f480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_26_0044f480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_26_0044f480.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_27_0044f4e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_27_0044f4e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_27_0044f4e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_28_0044f540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_28_0044f540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_28_0044f540.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F590_0044f590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F590_0044f590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F590_0044f590.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_29_0044f5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_29_0044f5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_29_0044f5a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_59_0044f5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_59_0044f5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_59_0044f5e0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_30_0044f600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_30_0044f600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_30_0044f600.md
