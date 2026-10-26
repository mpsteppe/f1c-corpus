# SKELETON FILL — Worker B chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BDD0_0041bdd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BDD0_0041bdd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BDD0_0041bdd0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BE00_0041be00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BE00_0041be00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BE00_0041be00.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BE60_0041be60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BE60_0041be60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BE60_0041be60.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C050_0041c050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C050_0041c050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C050_0041c050.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C110_0041c110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C110_0041c110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C110_0041c110.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C320_0041c320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C320_0041c320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C320_0041c320.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C460_0041c460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C460_0041c460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C460_0041c460.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C830_0041c830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C830_0041c830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C830_0041c830.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C880_0041c880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C880_0041c880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C880_0041c880.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C8B0_0041c8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C8B0_0041c8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C8B0_0041c8b0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C8C0_0041c8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C8C0_0041c8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C8C0_0041c8c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C910_0041c910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C910_0041c910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C910_0041c910.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C930_0041c930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C930_0041c930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C930_0041c930.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CEB0_0041ceb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CEB0_0041ceb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CEB0_0041ceb0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CED0_0041ced0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CED0_0041ced0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CED0_0041ced0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CEF0_0041cef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CEF0_0041cef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CEF0_0041cef0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CF10_0041cf10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CF10_0041cf10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CF10_0041cf10.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CF30_0041cf30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CF30_0041cf30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CF30_0041cf30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CF50_0041cf50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CF50_0041cf50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CF50_0041cf50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CF70_0041cf70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CF70_0041cf70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CF70_0041cf70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CF90_0041cf90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CF90_0041cf90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CF90_0041cf90.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CFB0_0041cfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CFB0_0041cfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CFB0_0041cfb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CFD0_0041cfd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CFD0_0041cfd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CFD0_0041cfd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41CFF0_0041cff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41CFF0_0041cff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41CFF0_0041cff0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D010_0041d010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D010_0041d010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D010_0041d010.md
