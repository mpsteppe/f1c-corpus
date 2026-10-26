# SKELETON FILL — Worker B chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_26_00437b08.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_26_00437b08.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_26_00437b08.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437B10_00437b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437B10_00437b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437B10_00437b10.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438AF0_00438af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438AF0_00438af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438AF0_00438af0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438B50_00438b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438B50_00438b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438B50_00438b50.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438BF0_00438bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438BF0_00438bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438BF0_00438bf0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438C10_00438c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438C10_00438c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438C10_00438c10.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438CE0_00438ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438CE0_00438ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438CE0_00438ce0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438EA0_00438ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438EA0_00438ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438EA0_00438ea0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43AA80_0043aa80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43AA80_0043aa80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43AA80_0043aa80.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43AB60_0043ab60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43AB60_0043ab60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43AB60_0043ab60.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43AB90_0043ab90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43AB90_0043ab90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43AB90_0043ab90.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43B590_0043b590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43B590_0043b590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43B590_0043b590.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43B810_0043b810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43B810_0043b810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43B810_0043b810.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E420_0043e420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E420_0043e420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E420_0043e420.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E440_0043e440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E440_0043e440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E440_0043e440.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E520_0043e520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E520_0043e520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E520_0043e520.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E550_0043e550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E550_0043e550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E550_0043e550.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E5A0_0043e5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E5A0_0043e5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E5A0_0043e5a0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43E5F0_0043e5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43E5F0_0043e5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43E5F0_0043e5f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_440D30_00440d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_440D30_00440d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_440D30_00440d30.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_440E20_00440e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_440E20_00440e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_440E20_00440e20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4410A0_004410a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4410A0_004410a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4410A0_004410a0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441680_00441680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441680_00441680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441680_00441680.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441A90_00441a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441A90_00441a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441A90_00441a90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_27_00441ba1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_27_00441ba1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_27_00441ba1.md
