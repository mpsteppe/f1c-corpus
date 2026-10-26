# SKELETON FILL — Worker H chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B50F0_005b50f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B50F0_005b50f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B50F0_005b50f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5190_005b5190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5190_005b5190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5190_005b5190.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B58D0_005b58d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B58D0_005b58d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B58D0_005b58d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\j_nullsub_6_005b5940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\j_nullsub_6_005b5940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\j_nullsub_6_005b5940.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5950_005b5950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5950_005b5950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5950_005b5950.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5980_005b5980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5980_005b5980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5980_005b5980.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5990_005b5990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5990_005b5990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5990_005b5990.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B59B0_005b59b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B59B0_005b59b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B59B0_005b59b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5A70_005b5a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5A70_005b5a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5A70_005b5a70.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5A90_005b5a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5A90_005b5a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5A90_005b5a90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5AD0_005b5ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5AD0_005b5ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5AD0_005b5ad0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5B50_005b5b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5B50_005b5b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5B50_005b5b50.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5B80_005b5b80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5B80_005b5b80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5B80_005b5b80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5BA0_005b5ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5BA0_005b5ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5BA0_005b5ba0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5BE0_005b5be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5BE0_005b5be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5BE0_005b5be0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5C60_005b5c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5C60_005b5c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5C60_005b5c60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B5DC0_005b5dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B5DC0_005b5dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B5DC0_005b5dc0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_148_005b5f02.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_148_005b5f02.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_148_005b5f02.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B7170_005b7170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B7170_005b7170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B7170_005b7170.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B7210_005b7210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B7210_005b7210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B7210_005b7210.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B81A0_005b81a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B81A0_005b81a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B81A0_005b81a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8210_005b8210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8210_005b8210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8210_005b8210.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8270_005b8270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8270_005b8270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8270_005b8270.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8650_005b8650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8650_005b8650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8650_005b8650.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B86D0_005b86d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B86D0_005b86d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B86D0_005b86d0.md
