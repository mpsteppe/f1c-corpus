# SKELETON FILL — Worker B chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462CE0_00462ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462CE0_00462ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462CE0_00462ce0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462D10_00462d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462D10_00462d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462D10_00462d10.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462D30_00462d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462D30_00462d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462D30_00462d30.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4633A0_004633a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4633A0_004633a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4633A0_004633a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4633F0_004633f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4633F0_004633f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4633F0_004633f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463490_00463490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463490_00463490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463490_00463490.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4634A0_004634a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4634A0_004634a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4634A0_004634a0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4634D0_004634d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4634D0_004634d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4634D0_004634d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4634F0_004634f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4634F0_004634f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4634F0_004634f0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463520_00463520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463520_00463520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463520_00463520.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463780_00463780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463780_00463780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463780_00463780.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4637C0_004637c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4637C0_004637c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4637C0_004637c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4637F0_004637f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4637F0_004637f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4637F0_004637f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_82_00463a36.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_82_00463a36.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_82_00463a36.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463B50_00463b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463B50_00463b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463B50_00463b50.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463B60_00463b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463B60_00463b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463B60_00463b60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463B80_00463b80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463B80_00463b80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463B80_00463b80.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463BC0_00463bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463BC0_00463bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463BC0_00463bc0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463BD0_00463bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463BD0_00463bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463BD0_00463bd0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463C00_00463c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463C00_00463c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463C00_00463c00.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463C20_00463c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463C20_00463c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463C20_00463c20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463C50_00463c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463C50_00463c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463C50_00463c50.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463C80_00463c80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463C80_00463c80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463C80_00463c80.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463CD0_00463cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463CD0_00463cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463CD0_00463cd0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463D40_00463d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463D40_00463d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463D40_00463d40.md
