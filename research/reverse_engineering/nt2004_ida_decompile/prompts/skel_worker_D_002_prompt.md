# SKELETON FILL — Worker D chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4953C8_004953c8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4953C8_004953c8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4953C8_004953c8.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4953F5_004953f5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4953F5_004953f5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4953F5_004953f5.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495422_00495422.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495422_00495422.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495422_00495422.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49544F_0049544f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49544F_0049544f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49544F_0049544f.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49547C_0049547c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49547C_0049547c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49547C_0049547c.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4954A9_004954a9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4954A9_004954a9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4954A9_004954a9.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4954D6_004954d6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4954D6_004954d6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4954D6_004954d6.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495503_00495503.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495503_00495503.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495503_00495503.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495530_00495530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495530_00495530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495530_00495530.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49555D_0049555d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49555D_0049555d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49555D_0049555d.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49558A_0049558a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49558A_0049558a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49558A_0049558a.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4955B7_004955b7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4955B7_004955b7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4955B7_004955b7.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4955E4_004955e4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4955E4_004955e4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4955E4_004955e4.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495611_00495611.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495611_00495611.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495611_00495611.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49563E_0049563e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49563E_0049563e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49563E_0049563e.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49566B_0049566b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49566B_0049566b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49566B_0049566b.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495698_00495698.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495698_00495698.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495698_00495698.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4956C5_004956c5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4956C5_004956c5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4956C5_004956c5.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4956F2_004956f2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4956F2_004956f2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4956F2_004956f2.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49571F_0049571f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49571F_0049571f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49571F_0049571f.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49574C_0049574c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49574C_0049574c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49574C_0049574c.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495779_00495779.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495779_00495779.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495779_00495779.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4957A6_004957a6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4957A6_004957a6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4957A6_004957a6.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4957D3_004957d3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4957D3_004957d3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4957D3_004957d3.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495800_00495800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495800_00495800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495800_00495800.md
