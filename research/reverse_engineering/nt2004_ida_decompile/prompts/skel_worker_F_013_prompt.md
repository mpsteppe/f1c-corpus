# SKELETON FILL — Worker F chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5140D0_005140d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5140D0_005140d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5140D0_005140d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5143A0_005143a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5143A0_005143a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5143A0_005143a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514440_00514440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514440_00514440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514440_00514440.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514590_00514590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514590_00514590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514590_00514590.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5149B0_005149b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5149B0_005149b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5149B0_005149b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514BB0_00514bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514BB0_00514bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514BB0_00514bb0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514EB0_00514eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514EB0_00514eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514EB0_00514eb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514EE0_00514ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514EE0_00514ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514EE0_00514ee0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514F70_00514f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514F70_00514f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514F70_00514f70.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_514FD0_00514fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_514FD0_00514fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_514FD0_00514fd0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_515510_00515510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_515510_00515510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_515510_00515510.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5155D0_005155d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5155D0_005155d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5155D0_005155d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5157A0_005157a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5157A0_005157a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5157A0_005157a0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_515BF0_00515bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_515BF0_00515bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_515BF0_00515bf0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_516FEA_00516fea.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_516FEA_00516fea.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_516FEA_00516fea.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5195F0_005195f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5195F0_005195f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5195F0_005195f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5196B0_005196b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5196B0_005196b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5196B0_005196b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5196E0_005196e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5196E0_005196e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5196E0_005196e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519720_00519720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519720_00519720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519720_00519720.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5197F0_005197f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5197F0_005197f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5197F0_005197f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519820_00519820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519820_00519820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519820_00519820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519850_00519850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519850_00519850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519850_00519850.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519990_00519990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519990_00519990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519990_00519990.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519A30_00519a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519A30_00519a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519A30_00519a30.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_123_00519c88.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_123_00519c88.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_123_00519c88.md
