# SKELETON FILL — Worker A chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4EB0_004d4eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4EB0_004d4eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4EB0_004d4eb0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5820_004d5820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5820_004d5820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5820_004d5820.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D92D0_004d92d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D92D0_004d92d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D92D0_004d92d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D9BA0_004d9ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D9BA0_004d9ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D9BA0_004d9ba0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DBAC0_004dbac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DBAC0_004dbac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DBAC0_004dbac0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC690_004dc690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC690_004dc690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC690_004dc690.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCCC0_004dccc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCCC0_004dccc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCCC0_004dccc0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD970_004dd970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD970_004dd970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD970_004dd970.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E26F0_004e26f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E26F0_004e26f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E26F0_004e26f0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3B00_004e3b00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3B00_004e3b00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3B00_004e3b00.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E43D0_004e43d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E43D0_004e43d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E43D0_004e43d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4840_004e4840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4840_004e4840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4840_004e4840.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E58F0_004e58f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E58F0_004e58f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E58F0_004e58f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E8E50_004e8e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E8E50_004e8e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E8E50_004e8e50.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECF20_004ecf20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECF20_004ecf20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECF20_004ecf20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED0C0_004ed0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED0C0_004ed0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED0C0_004ed0c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF930_004ef930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF930_004ef930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF930_004ef930.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F00E0_004f00e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F00E0_004f00e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F00E0_004f00e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F4FA0_004f4fa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F4FA0_004f4fa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F4FA0_004f4fa0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FBD60_004fbd60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FBD60_004fbd60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FBD60_004fbd60.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501F60_00501f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501F60_00501f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501F60_00501f60.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502E90_00502e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502E90_00502e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502E90_00502e90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503880_00503880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503880_00503880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503880_00503880.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5044F0_005044f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5044F0_005044f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5044F0_005044f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504820_00504820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504820_00504820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504820_00504820.md
