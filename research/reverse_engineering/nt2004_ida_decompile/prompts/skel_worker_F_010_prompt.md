# SKELETON FILL — Worker F chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_122_00505890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_122_00505890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_122_00505890.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505990_00505990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505990_00505990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505990_00505990.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505AF0_00505af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505AF0_00505af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505AF0_00505af0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505C10_00505c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505C10_00505c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505C10_00505c10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505D00_00505d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505D00_00505d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505D00_00505d00.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505E40_00505e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505E40_00505e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505E40_00505e40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506060_00506060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506060_00506060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506060_00506060.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5060A0_005060a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5060A0_005060a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5060A0_005060a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506630_00506630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506630_00506630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506630_00506630.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506745_00506745.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506745_00506745.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506745_00506745.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506920_00506920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506920_00506920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506920_00506920.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5069A0_005069a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5069A0_005069a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5069A0_005069a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506AE0_00506ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506AE0_00506ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506AE0_00506ae0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506B20_00506b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506B20_00506b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506B20_00506b20.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506B30_00506b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506B30_00506b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506B30_00506b30.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506BA0_00506ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506BA0_00506ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506BA0_00506ba0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506C6C_00506c6c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506C6C_00506c6c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506C6C_00506c6c.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506C70_00506c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506C70_00506c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506C70_00506c70.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506C80_00506c80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506C80_00506c80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506C80_00506c80.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506D20_00506d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506D20_00506d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506D20_00506d20.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506D30_00506d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506D30_00506d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506D30_00506d30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5071F0_005071f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5071F0_005071f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5071F0_005071f0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5072A0_005072a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5072A0_005072a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5072A0_005072a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_507330_00507330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_507330_00507330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_507330_00507330.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_507540_00507540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_507540_00507540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_507540_00507540.md
