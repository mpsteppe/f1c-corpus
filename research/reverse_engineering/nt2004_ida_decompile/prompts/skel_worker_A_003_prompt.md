# SKELETON FILL — Worker A chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E8670_004e8670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E8670_004e8670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E8670_004e8670.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF7E0_004ef7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF7E0_004ef7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF7E0_004ef7e0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F4150_004f4150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F4150_004f4150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F4150_004f4150.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F4880_004f4880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F4880_004f4880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F4880_004f4880.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7AE0_004f7ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7AE0_004f7ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7AE0_004f7ae0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8C90_004f8c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8C90_004f8c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8C90_004f8c90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FCB90_004fcb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FCB90_004fcb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FCB90_004fcb90.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500A20_00500a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500A20_00500a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500A20_00500a20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504920_00504920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504920_00504920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504920_00504920.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505E80_00505e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505E80_00505e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505E80_00505e80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506D40_00506d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506D40_00506d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506D40_00506d40.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_507620_00507620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_507620_00507620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_507620_00507620.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50E070_0050e070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50E070_0050e070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50E070_0050e070.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C290_0051c290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C290_0051c290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C290_0051c290.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528280_00528280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528280_00528280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528280_00528280.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54CE1B_0054ce1b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54CE1B_0054ce1b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54CE1B_0054ce1b.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_578A30_00578a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_578A30_00578a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_578A30_00578a30.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A1870_005a1870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A1870_005a1870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A1870_005a1870.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA7B0_005ba7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA7B0_005ba7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA7B0_005ba7b0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC220_005bc220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC220_005bc220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC220_005bc220.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__I10_OUTPUT_005cec08.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__I10_OUTPUT_005cec08.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__I10_OUTPUT_005cec08.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406190_00406190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406190_00406190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406190_00406190.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409E80_00409e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409E80_00409e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409E80_00409e80.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A8A0_0040a8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A8A0_0040a8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A8A0_0040a8a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40B330_0040b330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40B330_0040b330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40B330_0040b330.md
