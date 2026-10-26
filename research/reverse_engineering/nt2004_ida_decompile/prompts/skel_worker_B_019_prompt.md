# SKELETON FILL — Worker B chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D2E0_0045d2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D2E0_0045d2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D2E0_0045d2e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D320_0045d320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D320_0045d320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D320_0045d320.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D3A0_0045d3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D3A0_0045d3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D3A0_0045d3a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D700_0045d700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D700_0045d700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D700_0045d700.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D8A0_0045d8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D8A0_0045d8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D8A0_0045d8a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DB30_0045db30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DB30_0045db30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DB30_0045db30.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DBD0_0045dbd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DBD0_0045dbd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DBD0_0045dbd0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DCD0_0045dcd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DCD0_0045dcd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DCD0_0045dcd0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DD00_0045dd00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DD00_0045dd00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DD00_0045dd00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DD20_0045dd20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DD20_0045dd20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DD20_0045dd20.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DDD0_0045ddd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DDD0_0045ddd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DDD0_0045ddd0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DE70_0045de70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DE70_0045de70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DE70_0045de70.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E160_0045e160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E160_0045e160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E160_0045e160.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E390_0045e390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E390_0045e390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E390_0045e390.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E6F0_0045e6f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E6F0_0045e6f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E6F0_0045e6f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_3_0045e740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_3_0045e740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_3_0045e740.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_80_0045e7ed.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_80_0045e7ed.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_80_0045e7ed.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E840_0045e840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E840_0045e840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E840_0045e840.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E860_0045e860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E860_0045e860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E860_0045e860.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45EB60_0045eb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45EB60_0045eb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45EB60_0045eb60.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FD90_0045fd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FD90_0045fd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FD90_0045fd90.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FDB0_0045fdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FDB0_0045fdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FDB0_0045fdb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FDD0_0045fdd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FDD0_0045fdd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FDD0_0045fdd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FDF0_0045fdf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FDF0_0045fdf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FDF0_0045fdf0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45FE10_0045fe10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45FE10_0045fe10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45FE10_0045fe10.md
