# SKELETON FILL — Worker B chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_28_0044d7a8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_28_0044d7a8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_28_0044d7a8.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44EA10_0044ea10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44EA10_0044ea10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44EA10_0044ea10.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_27_0044ea20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_27_0044ea20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_27_0044ea20.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44EA50_0044ea50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44EA50_0044ea50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44EA50_0044ea50.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_0044ea60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_0044ea60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_0044ea60.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_29_0044eaa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_29_0044eaa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_29_0044eaa0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44EAB0_0044eab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44EAB0_0044eab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44EAB0_0044eab0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_0_0044eac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_0_0044eac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_0_0044eac0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_30_0044eb00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_30_0044eb00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_30_0044eb00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_1_0044eb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_1_0044eb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_1_0044eb20.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_2_0044eb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_2_0044eb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_2_0044eb80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_3_0044ebe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_3_0044ebe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_3_0044ebe0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_4_0044ec40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_4_0044ec40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_4_0044ec40.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_5_0044eca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_5_0044eca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_5_0044eca0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_6_0044ed00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_6_0044ed00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_6_0044ed00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_7_0044ed60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_7_0044ed60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_7_0044ed60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_8_0044edc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_8_0044edc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_8_0044edc0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_9_0044ee20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_9_0044ee20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_9_0044ee20.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_39_0044ee60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_39_0044ee60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_39_0044ee60.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_10_0044ee80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_10_0044ee80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_10_0044ee80.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_11_0044eee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_11_0044eee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_11_0044eee0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_41_0044ef20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_41_0044ef20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_41_0044ef20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_12_0044ef40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_12_0044ef40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_12_0044ef40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_13_0044efa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_13_0044efa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_13_0044efa0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_43_0044efe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_43_0044efe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_43_0044efe0.md
