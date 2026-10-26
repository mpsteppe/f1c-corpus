# SKELETON FILL — Worker G chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D4B0_0058d4b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D4B0_0058d4b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D4B0_0058d4b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D500_0058d500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D500_0058d500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D500_0058d500.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D520_0058d520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D520_0058d520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D520_0058d520.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D560_0058d560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D560_0058d560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D560_0058d560.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D5A0_0058d5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D5A0_0058d5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D5A0_0058d5a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D600_0058d600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D600_0058d600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D600_0058d600.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D640_0058d640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D640_0058d640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D640_0058d640.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D6C1_0058d6c1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D6C1_0058d6c1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D6C1_0058d6c1.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D6D0_0058d6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D6D0_0058d6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D6D0_0058d6d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D6F0_0058d6f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D6F0_0058d6f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D6F0_0058d6f0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D720_0058d720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D720_0058d720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D720_0058d720.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D950_0058d950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D950_0058d950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D950_0058d950.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DAAA_0058daaa.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DAAA_0058daaa.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DAAA_0058daaa.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DAB0_0058dab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DAB0_0058dab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DAB0_0058dab0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DB00_0058db00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DB00_0058db00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DB00_0058db00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DB10_0058db10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DB10_0058db10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DB10_0058db10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DCD0_0058dcd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DCD0_0058dcd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DCD0_0058dcd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DD70_0058dd70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DD70_0058dd70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DD70_0058dd70.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DE40_0058de40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DE40_0058de40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DE40_0058de40.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58DFD0_0058dfd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58DFD0_0058dfd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58DFD0_0058dfd0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E000_0058e000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E000_0058e000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E000_0058e000.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E0A8_0058e0a8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E0A8_0058e0a8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E0A8_0058e0a8.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E0E0_0058e0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E0E0_0058e0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E0E0_0058e0e0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E0F0_0058e0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E0F0_0058e0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E0F0_0058e0f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E110_0058e110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E110_0058e110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E110_0058e110.md
