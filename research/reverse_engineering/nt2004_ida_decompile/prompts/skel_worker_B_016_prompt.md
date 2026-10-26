# SKELETON FILL — Worker B chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458C90_00458c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458C90_00458c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458C90_00458c90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458D90_00458d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458D90_00458d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458D90_00458d90.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4590A0_004590a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4590A0_004590a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4590A0_004590a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_74_004597b8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_74_004597b8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_74_004597b8.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4597C0_004597c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4597C0_004597c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4597C0_004597c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4599E0_004599e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4599E0_004599e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4599E0_004599e0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459A60_00459a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459A60_00459a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459A60_00459a60.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459AC0_00459ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459AC0_00459ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459AC0_00459ac0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459B20_00459b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459B20_00459b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459B20_00459b20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459B30_00459b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459B30_00459b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459B30_00459b30.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459B40_00459b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459B40_00459b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459B40_00459b40.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459B60_00459b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459B60_00459b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459B60_00459b60.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459B90_00459b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459B90_00459b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459B90_00459b90.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459BA0_00459ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459BA0_00459ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459BA0_00459ba0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459BC0_00459bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459BC0_00459bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459BC0_00459bc0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459BD0_00459bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459BD0_00459bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459BD0_00459bd0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459BE0_00459be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459BE0_00459be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459BE0_00459be0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459BF0_00459bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459BF0_00459bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459BF0_00459bf0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C00_00459c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C00_00459c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C00_00459c00.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C10_00459c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C10_00459c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C10_00459c10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C20_00459c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C20_00459c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C20_00459c20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C30_00459c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C30_00459c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C30_00459c30.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C40_00459c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C40_00459c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C40_00459c40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C50_00459c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C50_00459c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C50_00459c50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_459C60_00459c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_459C60_00459c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_459C60_00459c60.md
