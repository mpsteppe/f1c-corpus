# SKELETON FILL — Worker F chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5203F0_005203f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5203F0_005203f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5203F0_005203f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_520450_00520450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_520450_00520450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_520450_00520450.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5205C9_005205c9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5205C9_005205c9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5205C9_005205c9.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5210A0_005210a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5210A0_005210a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5210A0_005210a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524050_00524050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524050_00524050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524050_00524050.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524180_00524180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524180_00524180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524180_00524180.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5241E0_005241e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5241E0_005241e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5241E0_005241e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524210_00524210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524210_00524210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524210_00524210.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5242B0_005242b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5242B0_005242b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5242B0_005242b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524340_00524340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524340_00524340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524340_00524340.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5243B0_005243b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5243B0_005243b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5243B0_005243b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524400_00524400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524400_00524400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524400_00524400.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524490_00524490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524490_00524490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524490_00524490.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524520_00524520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524520_00524520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524520_00524520.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524870_00524870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524870_00524870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524870_00524870.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524960_00524960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524960_00524960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524960_00524960.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524970_00524970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524970_00524970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524970_00524970.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_525900_00525900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_525900_00525900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_525900_00525900.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_525B60_00525b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_525B60_00525b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_525B60_00525b60.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_525C50_00525c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_525C50_00525c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_525C50_00525c50.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_525CA0_00525ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_525CA0_00525ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_525CA0_00525ca0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526050_00526050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526050_00526050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526050_00526050.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526140_00526140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526140_00526140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526140_00526140.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5261A0_005261a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5261A0_005261a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5261A0_005261a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5262A0_005262a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5262A0_005262a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5262A0_005262a0.md
