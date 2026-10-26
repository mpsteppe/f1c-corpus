# SKELETON FILL — Worker C chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4757A0_004757a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4757A0_004757a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4757A0_004757a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475800_00475800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475800_00475800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475800_00475800.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475980_00475980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475980_00475980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475980_00475980.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475A00_00475a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475A00_00475a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475A00_00475a00.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475A80_00475a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475A80_00475a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475A80_00475a80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4764B0_004764b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4764B0_004764b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4764B0_004764b0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4764C0_004764c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4764C0_004764c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4764C0_004764c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476564_00476564.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476564_00476564.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476564_00476564.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476770_00476770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476770_00476770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476770_00476770.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476ED0_00476ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476ED0_00476ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476ED0_00476ed0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477040_00477040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477040_00477040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477040_00477040.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477070_00477070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477070_00477070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477070_00477070.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477170_00477170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477170_00477170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477170_00477170.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477B40_00477b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477B40_00477b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477B40_00477b40.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477B90_00477b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477B90_00477b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477B90_00477b90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477BC0_00477bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477BC0_00477bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477BC0_00477bc0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477CE1_00477ce1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477CE1_00477ce1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477CE1_00477ce1.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477D90_00477d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477D90_00477d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477D90_00477d90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477D98_00477d98.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477D98_00477d98.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477D98_00477d98.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477DA0_00477da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477DA0_00477da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477DA0_00477da0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_477EF0_00477ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_477EF0_00477ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_477EF0_00477ef0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478160_00478160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478160_00478160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478160_00478160.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478170_00478170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478170_00478170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478170_00478170.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_87_004781a3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_87_004781a3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_87_004781a3.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4781A9_004781a9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4781A9_004781a9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4781A9_004781a9.md
