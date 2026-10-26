# SKELETON FILL — Worker E chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEB40_004ceb40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEB40_004ceb40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEB40_004ceb40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEE30_004cee30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEE30_004cee30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEE30_004cee30.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEED0_004ceed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEED0_004ceed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEED0_004ceed0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEF90_004cef90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEF90_004cef90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEF90_004cef90.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEFD0_004cefd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEFD0_004cefd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEFD0_004cefd0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_112_004cf065.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_112_004cf065.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_112_004cf065.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF070_004cf070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF070_004cf070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF070_004cf070.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF1B0_004cf1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF1B0_004cf1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF1B0_004cf1b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF250_004cf250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF250_004cf250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF250_004cf250.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF2C0_004cf2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF2C0_004cf2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF2C0_004cf2c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF360_004cf360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF360_004cf360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF360_004cf360.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF370_004cf370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF370_004cf370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF370_004cf370.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_113_004cf423.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_113_004cf423.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_113_004cf423.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF430_004cf430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF430_004cf430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF430_004cf430.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF440_004cf440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF440_004cf440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF440_004cf440.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF48B_004cf48b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF48B_004cf48b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF48B_004cf48b.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF4B0_004cf4b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF4B0_004cf4b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF4B0_004cf4b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF4C0_004cf4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF4C0_004cf4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF4C0_004cf4c0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF4D0_004cf4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF4D0_004cf4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF4D0_004cf4d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF4F0_004cf4f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF4F0_004cf4f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF4F0_004cf4f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0Iostream_init__QAE_XZ_004cf500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0Iostream_init__QAE_XZ_004cf500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0Iostream_init__QAE_XZ_004cf500.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_6_004cf510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_6_004cf510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_6_004cf510.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF520_004cf520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF520_004cf520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF520_004cf520.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_64_004cf550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_64_004cf550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_64_004cf550.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CF560_004cf560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CF560_004cf560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CF560_004cf560.md
