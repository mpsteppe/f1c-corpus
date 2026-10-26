# SKELETON FILL — Worker F chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5020C0_005020c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5020C0_005020c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5020C0_005020c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5020FB_005020fb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5020FB_005020fb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5020FB_005020fb.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502100_00502100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502100_00502100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502100_00502100.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502130_00502130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502130_00502130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502130_00502130.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5021C0_005021c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5021C0_005021c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5021C0_005021c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502280_00502280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502280_00502280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502280_00502280.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502350_00502350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502350_00502350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502350_00502350.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502566_00502566.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502566_00502566.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502566_00502566.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502570_00502570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502570_00502570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502570_00502570.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502730_00502730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502730_00502730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502730_00502730.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5027D0_005027d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5027D0_005027d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5027D0_005027d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502840_00502840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502840_00502840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502840_00502840.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502980_00502980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502980_00502980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502980_00502980.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502A10_00502a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502A10_00502a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502A10_00502a10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502A30_00502a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502A30_00502a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502A30_00502a30.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502A50_00502a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502A50_00502a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502A50_00502a50.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502E10_00502e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502E10_00502e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502E10_00502e10.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5030F0_005030f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5030F0_005030f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5030F0_005030f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503110_00503110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503110_00503110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503110_00503110.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503120_00503120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503120_00503120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503120_00503120.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5031C0_005031c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5031C0_005031c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5031C0_005031c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5035B0_005035b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5035B0_005035b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5035B0_005035b0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503DE0_00503de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503DE0_00503de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503DE0_00503de0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503F50_00503f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503F50_00503f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503F50_00503f50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504390_00504390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504390_00504390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504390_00504390.md
