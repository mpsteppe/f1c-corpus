# SKELETON FILL — Worker C chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DB50_0048db50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DB50_0048db50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DB50_0048db50.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_94_0048db78.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_94_0048db78.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_94_0048db78.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DC40_0048dc40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DC40_0048dc40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DC40_0048dc40.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DC70_0048dc70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DC70_0048dc70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DC70_0048dc70.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DCA0_0048dca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DCA0_0048dca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DCA0_0048dca0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DCD0_0048dcd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DCD0_0048dcd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DCD0_0048dcd0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DD20_0048dd20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DD20_0048dd20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DD20_0048dd20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DF20_0048df20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DF20_0048df20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DF20_0048df20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E750_0048e750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E750_0048e750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E750_0048e750.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E770_0048e770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E770_0048e770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E770_0048e770.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E860_0048e860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E860_0048e860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E860_0048e860.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E86A_0048e86a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E86A_0048e86a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E86A_0048e86a.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E870_0048e870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E870_0048e870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E870_0048e870.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E890_0048e890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E890_0048e890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E890_0048e890.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E920_0048e920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E920_0048e920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E920_0048e920.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E94A_0048e94a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E94A_0048e94a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E94A_0048e94a.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48E980_0048e980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48E980_0048e980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48E980_0048e980.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48EA20_0048ea20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48EA20_0048ea20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48EA20_0048ea20.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48EC70_0048ec70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48EC70_0048ec70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48EC70_0048ec70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48F84C_0048f84c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48F84C_0048f84c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48F84C_0048f84c.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48F968_0048f968.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48F968_0048f968.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48F968_0048f968.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48FA20_0048fa20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48FA20_0048fa20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48FA20_0048fa20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48FAF0_0048faf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48FAF0_0048faf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48FAF0_0048faf0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48FB10_0048fb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48FB10_0048fb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48FB10_0048fb10.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48FB70_0048fb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48FB70_0048fb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48FB70_0048fb70.md
