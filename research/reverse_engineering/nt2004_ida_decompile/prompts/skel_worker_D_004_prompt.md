# SKELETON FILL — Worker D chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B460_0049b460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B460_0049b460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B460_0049b460.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B4A5_0049b4a5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B4A5_0049b4a5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B4A5_0049b4a5.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B4F6_0049b4f6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B4F6_0049b4f6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B4F6_0049b4f6.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B5D0_0049b5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B5D0_0049b5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B5D0_0049b5d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B600_0049b600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B600_0049b600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B600_0049b600.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B630_0049b630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B630_0049b630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B630_0049b630.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B660_0049b660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B660_0049b660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B660_0049b660.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B690_0049b690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B690_0049b690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B690_0049b690.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B740_0049b740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B740_0049b740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B740_0049b740.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B760_0049b760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B760_0049b760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B760_0049b760.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B780_0049b780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B780_0049b780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B780_0049b780.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B7B0_0049b7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B7B0_0049b7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B7B0_0049b7b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B7E0_0049b7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B7E0_0049b7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B7E0_0049b7e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49BED0_0049bed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49BED0_0049bed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49BED0_0049bed0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49BF10_0049bf10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49BF10_0049bf10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49BF10_0049bf10.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C0B0_0049c0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C0B0_0049c0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C0B0_0049c0b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C130_0049c130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C130_0049c130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C130_0049c130.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C170_0049c170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C170_0049c170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C170_0049c170.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C690_0049c690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C690_0049c690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C690_0049c690.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C780_0049c780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C780_0049c780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C780_0049c780.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C940_0049c940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C940_0049c940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C940_0049c940.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C960_0049c960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C960_0049c960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C960_0049c960.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C980_0049c980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C980_0049c980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C980_0049c980.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C9A0_0049c9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C9A0_0049c9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C9A0_0049c9a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C9C0_0049c9c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C9C0_0049c9c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C9C0_0049c9c0.md
