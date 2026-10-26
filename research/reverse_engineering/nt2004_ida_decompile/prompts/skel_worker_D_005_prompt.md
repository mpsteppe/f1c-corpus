# SKELETON FILL — Worker D chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C9E0_0049c9e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C9E0_0049c9e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C9E0_0049c9e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CA00_0049ca00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CA00_0049ca00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CA00_0049ca00.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_GetExecutionResourceId_VirtualProcessor_details_Concurrency__QBEIXZ_0049ca20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_GetExecutionResourceId_VirtualProcessor_details_Concurrency__QBEIXZ_0049ca20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_GetExecutionResourceId_VirtualProcessor_details_Concurrency__QBEIXZ_0049ca20.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CA40_0049ca40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CA40_0049ca40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CA40_0049ca40.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CB60_0049cb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CB60_0049cb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CB60_0049cb60.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CB80_0049cb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CB80_0049cb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CB80_0049cb80.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CC60_0049cc60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CC60_0049cc60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CC60_0049cc60.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CC70_0049cc70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CC70_0049cc70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CC70_0049cc70.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CCA0_0049cca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CCA0_0049cca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CCA0_0049cca0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CD60_0049cd60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CD60_0049cd60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CD60_0049cd60.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CF00_0049cf00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CF00_0049cf00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CF00_0049cf00.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CF70_0049cf70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CF70_0049cf70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CF70_0049cf70.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CFB0_0049cfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CFB0_0049cfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CFB0_0049cfb0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49CFF0_0049cff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49CFF0_0049cff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49CFF0_0049cff0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D030_0049d030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D030_0049d030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D030_0049d030.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D070_0049d070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D070_0049d070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D070_0049d070.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D0F0_0049d0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D0F0_0049d0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D0F0_0049d0f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D120_0049d120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D120_0049d120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D120_0049d120.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D150_0049d150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D150_0049d150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D150_0049d150.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D180_0049d180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D180_0049d180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D180_0049d180.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D1B0_0049d1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D1B0_0049d1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D1B0_0049d1b0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_101_0049d1cc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_101_0049d1cc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_101_0049d1cc.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D1F0_0049d1f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D1F0_0049d1f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D1F0_0049d1f0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D230_0049d230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D230_0049d230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D230_0049d230.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D330_0049d330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D330_0049d330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D330_0049d330.md
