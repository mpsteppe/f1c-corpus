# SKELETON FILL — Worker B chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4195F0_004195f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4195F0_004195f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4195F0_004195f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419630_00419630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419630_00419630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419630_00419630.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4196A0_004196a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4196A0_004196a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4196A0_004196a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4196B0_004196b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4196B0_004196b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4196B0_004196b0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4197A0_004197a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4197A0_004197a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4197A0_004197a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4198A0_004198a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4198A0_004198a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4198A0_004198a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419CC0_00419cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419CC0_00419cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419CC0_00419cc0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419F80_00419f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419F80_00419f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419F80_00419f80.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419FE0_00419fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419FE0_00419fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419FE0_00419fe0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41A080_0041a080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41A080_0041a080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41A080_0041a080.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41AB40_0041ab40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41AB40_0041ab40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41AB40_0041ab40.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B080_0041b080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B080_0041b080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B080_0041b080.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B220_0041b220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B220_0041b220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B220_0041b220.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B3A0_0041b3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B3A0_0041b3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B3A0_0041b3a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B400_0041b400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B400_0041b400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B400_0041b400.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B490_0041b490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B490_0041b490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B490_0041b490.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B4E0_0041b4e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B4E0_0041b4e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B4E0_0041b4e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B5B0_0041b5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B5B0_0041b5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B5B0_0041b5b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_2_0041b5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_2_0041b5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_2_0041b5f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B600_0041b600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B600_0041b600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B600_0041b600.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41B810_0041b810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41B810_0041b810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41B810_0041b810.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BA10_0041ba10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BA10_0041ba10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BA10_0041ba10.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BB40_0041bb40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BB40_0041bb40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BB40_0041bb40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BBF0_0041bbf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BBF0_0041bbf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BBF0_0041bbf0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BD10_0041bd10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BD10_0041bd10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BD10_0041bd10.md
