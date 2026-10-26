# SKELETON FILL — Worker G chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591C90_00591c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591C90_00591c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591C90_00591c90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591CC0_00591cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591CC0_00591cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591CC0_00591cc0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591D20_00591d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591D20_00591d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591D20_00591d20.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591DE0_00591de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591DE0_00591de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591DE0_00591de0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591F10_00591f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591F10_00591f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591F10_00591f10.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5922A0_005922a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5922A0_005922a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5922A0_005922a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592390_00592390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592390_00592390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592390_00592390.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592750_00592750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592750_00592750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592750_00592750.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592910_00592910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592910_00592910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592910_00592910.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592A60_00592a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592A60_00592a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592A60_00592a60.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592BA0_00592ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592BA0_00592ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592BA0_00592ba0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592C40_00592c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592C40_00592c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592C40_00592c40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592E41_00592e41.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592E41_00592e41.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592E41_00592e41.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592E50_00592e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592E50_00592e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592E50_00592e50.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592EB0_00592eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592EB0_00592eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592EB0_00592eb0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592F60_00592f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592F60_00592f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592F60_00592f60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_592FE0_00592fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_592FE0_00592fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_592FE0_00592fe0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593010_00593010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593010_00593010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593010_00593010.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593120_00593120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593120_00593120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593120_00593120.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593460_00593460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593460_00593460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593460_00593460.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5934A0_005934a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5934A0_005934a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5934A0_005934a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593580_00593580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593580_00593580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593580_00593580.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593730_00593730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593730_00593730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593730_00593730.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593AF0_00593af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593AF0_00593af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593AF0_00593af0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593B30_00593b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593B30_00593b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593B30_00593b30.md
