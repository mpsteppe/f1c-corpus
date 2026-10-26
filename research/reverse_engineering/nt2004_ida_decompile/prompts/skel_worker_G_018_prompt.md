# SKELETON FILL — Worker G chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597DD0_00597dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597DD0_00597dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597DD0_00597dd0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597DE0_00597de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597DE0_00597de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597DE0_00597de0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_597F30_00597f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_597F30_00597f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_597F30_00597f30.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598170_00598170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598170_00598170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598170_00598170.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598430_00598430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598430_00598430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598430_00598430.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598580_00598580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598580_00598580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598580_00598580.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598C90_00598c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598C90_00598c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598C90_00598c90.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599310_00599310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599310_00599310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599310_00599310.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5994E0_005994e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5994E0_005994e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5994E0_005994e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5995A0_005995a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5995A0_005995a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5995A0_005995a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599620_00599620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599620_00599620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599620_00599620.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5997B0_005997b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5997B0_005997b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5997B0_005997b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5997E0_005997e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5997E0_005997e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5997E0_005997e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599800_00599800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599800_00599800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599800_00599800.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599A70_00599a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599A70_00599a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599A70_00599a70.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599BF0_00599bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599BF0_00599bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599BF0_00599bf0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599C60_00599c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599C60_00599c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599C60_00599c60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599D20_00599d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599D20_00599d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599D20_00599d20.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A570_0059a570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A570_0059a570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A570_0059a570.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A5B0_0059a5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A5B0_0059a5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A5B0_0059a5b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A620_0059a620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A620_0059a620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A620_0059a620.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A660_0059a660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A660_0059a660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A660_0059a660.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A800_0059a800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A800_0059a800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A800_0059a800.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59A8A0_0059a8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59A8A0_0059a8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59A8A0_0059a8a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59AB10_0059ab10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59AB10_0059ab10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59AB10_0059ab10.md
