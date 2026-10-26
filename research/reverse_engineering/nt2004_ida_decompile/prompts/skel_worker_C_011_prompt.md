# SKELETON FILL — Worker C chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4815D0_004815d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4815D0_004815d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4815D0_004815d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4815F0_004815f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4815F0_004815f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4815F0_004815f0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4816E0_004816e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4816E0_004816e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4816E0_004816e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4817F0_004817f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4817F0_004817f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4817F0_004817f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4818C0_004818c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4818C0_004818c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4818C0_004818c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_481940_00481940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_481940_00481940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_481940_00481940.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4819C0_004819c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4819C0_004819c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4819C0_004819c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_481A40_00481a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_481A40_00481a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_481A40_00481a40.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_481B30_00481b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_481B30_00481b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_481B30_00481b30.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_481CC0_00481cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_481CC0_00481cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_481CC0_00481cc0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_40_00482100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_40_00482100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_40_00482100.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482110_00482110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482110_00482110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482110_00482110.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482200_00482200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482200_00482200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482200_00482200.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482230_00482230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482230_00482230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482230_00482230.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482370_00482370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482370_00482370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482370_00482370.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4823F0_004823f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4823F0_004823f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4823F0_004823f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482480_00482480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482480_00482480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482480_00482480.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482890_00482890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482890_00482890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482890_00482890.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482B50_00482b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482B50_00482b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482B50_00482b50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482C70_00482c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482C70_00482c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482C70_00482c70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482CD0_00482cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482CD0_00482cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482CD0_00482cd0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482D60_00482d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482D60_00482d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482D60_00482d60.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482D70_00482d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482D70_00482d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482D70_00482d70.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482E30_00482e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482E30_00482e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482E30_00482e30.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_482EB0_00482eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_482EB0_00482eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_482EB0_00482eb0.md
