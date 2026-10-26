# SKELETON FILL — Worker AG chunk 6/7 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_681E57_00681e57.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_681E57_00681e57.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_681E57_00681e57.md
2. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_681EA6_00681ea6.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_681EA6_00681ea6.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_681EA6_00681ea6.md
3. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_681F34_00681f34.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_681F34_00681f34.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_681F34_00681f34.md
4. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_681F6F_00681f6f.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_681F6F_00681f6f.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_681F6F_00681f6f.md
5. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6821AC_006821ac.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6821AC_006821ac.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6821AC_006821ac.md
6. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6821ED_006821ed.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6821ED_006821ed.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6821ED_006821ed.md
7. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682246_00682246.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682246_00682246.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682246_00682246.md
8. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682274_00682274.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682274_00682274.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682274_00682274.md
9. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_68238B_0068238b.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_68238B_0068238b.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_68238B_0068238b.md
10. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682431_00682431.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682431_00682431.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682431_00682431.md
11. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682460_00682460.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682460_00682460.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682460_00682460.md
12. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682468_00682468.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682468_00682468.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682468_00682468.md
13. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6824D2_006824d2.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6824D2_006824d2.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6824D2_006824d2.md
14. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6824F1_006824f1.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6824F1_006824f1.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6824F1_006824f1.md
15. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682550_00682550.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682550_00682550.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682550_00682550.md
16. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682556_00682556.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682556_00682556.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682556_00682556.md
17. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682578_00682578.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682578_00682578.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682578_00682578.md
18. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6825A9_006825a9.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6825A9_006825a9.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6825A9_006825a9.md
19. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682608_00682608.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682608_00682608.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682608_00682608.md
20. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682643_00682643.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682643_00682643.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682643_00682643.md
21. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682854_00682854.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682854_00682854.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682854_00682854.md
22. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_6829EC_006829ec.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_6829EC_006829ec.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_6829EC_006829ec.md
23. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_682AEE_00682aee.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_682AEE_00682aee.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_682AEE_00682aee.md
24. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_683158_00683158.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_683158_00683158.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_683158_00683158.md
25. SKEL: %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons\sub_683235_00683235.md
   C:    %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\functions\sub_683235_00683235.c
   OUT:  %USERPROFILE%\Desktop\F1\research\reverse_engineering\gtr2_ida_decompile\skeletons_filled\sub_683235_00683235.md
