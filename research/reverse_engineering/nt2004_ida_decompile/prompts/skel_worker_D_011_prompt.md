# SKELETON FILL — Worker D chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A50B0_004a50b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A50B0_004a50b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A50B0_004a50b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A50C0_004a50c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A50C0_004a50c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A50C0_004a50c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A50D0_004a50d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A50D0_004a50d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A50D0_004a50d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5110_004a5110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5110_004a5110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5110_004a5110.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5180_004a5180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5180_004a5180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5180_004a5180.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A55D0_004a55d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A55D0_004a55d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A55D0_004a55d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A56D0_004a56d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A56D0_004a56d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A56D0_004a56d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5740_004a5740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5740_004a5740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5740_004a5740.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A57B0_004a57b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A57B0_004a57b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A57B0_004a57b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A57E0_004a57e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A57E0_004a57e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A57E0_004a57e0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5800_004a5800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5800_004a5800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5800_004a5800.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5810_004a5810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5810_004a5810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5810_004a5810.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5820_004a5820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5820_004a5820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5820_004a5820.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A58C0_004a58c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A58C0_004a58c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A58C0_004a58c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A58F0_004a58f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A58F0_004a58f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A58F0_004a58f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5920_004a5920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5920_004a5920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5920_004a5920.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A59F0_004a59f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A59F0_004a59f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A59F0_004a59f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5A60_004a5a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5A60_004a5a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5A60_004a5a60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5CE0_004a5ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5CE0_004a5ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5CE0_004a5ce0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5D40_004a5d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5D40_004a5d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5D40_004a5d40.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A5D60_004a5d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A5D60_004a5d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A5D60_004a5d60.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6040_004a6040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6040_004a6040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6040_004a6040.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A60F0_004a60f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A60F0_004a60f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A60F0_004a60f0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6150_004a6150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6150_004a6150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6150_004a6150.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A61C0_004a61c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A61C0_004a61c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A61C0_004a61c0.md
