# SKELETON FILL — Worker B chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C70_00459c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C70_00459c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C70_00459c70.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C90_00459c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C90_00459c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C90_00459c90.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459CA0_00459ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459CA0_00459ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459CA0_00459ca0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459CB0_00459cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459CB0_00459cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459CB0_00459cb0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459CC0_00459cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459CC0_00459cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459CC0_00459cc0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459CD0_00459cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459CD0_00459cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459CD0_00459cd0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459CE0_00459ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459CE0_00459ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459CE0_00459ce0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D30_00459d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D30_00459d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D30_00459d30.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D40_00459d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D40_00459d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D40_00459d40.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D60_00459d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D60_00459d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D60_00459d60.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D70_00459d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D70_00459d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D70_00459d70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D80_00459d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D80_00459d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D80_00459d80.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459D90_00459d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459D90_00459d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459D90_00459d90.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459F30_00459f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459F30_00459f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459F30_00459f30.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459F60_00459f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459F60_00459f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459F60_00459f60.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A1D0_0045a1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A1D0_0045a1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A1D0_0045a1d0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A1F0_0045a1f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A1F0_0045a1f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A1F0_0045a1f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A2B0_0045a2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A2B0_0045a2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A2B0_0045a2b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_77_0045a514.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_77_0045a514.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_77_0045a514.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A570_0045a570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A570_0045a570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A570_0045a570.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A580_0045a580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A580_0045a580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A580_0045a580.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A590_0045a590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A590_0045a590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A590_0045a590.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A5A0_0045a5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A5A0_0045a5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A5A0_0045a5a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A5B0_0045a5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A5B0_0045a5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A5B0_0045a5b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A5C0_0045a5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A5C0_0045a5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A5C0_0045a5c0.md
