# SKELETON FILL — Worker C chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471D90_00471d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471D90_00471d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471D90_00471d90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4723C0_004723c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4723C0_004723c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4723C0_004723c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4723E0_004723e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4723E0_004723e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4723E0_004723e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472410_00472410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472410_00472410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472410_00472410.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472420_00472420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472420_00472420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472420_00472420.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472510_00472510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472510_00472510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472510_00472510.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472670_00472670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472670_00472670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472670_00472670.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472690_00472690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472690_00472690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472690_00472690.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472850_00472850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472850_00472850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472850_00472850.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472860_00472860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472860_00472860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472860_00472860.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472A10_00472a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472A10_00472a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472A10_00472a10.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_472F40_00472f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_472F40_00472f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_472F40_00472f40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_473010_00473010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_473010_00473010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_473010_00473010.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_473070_00473070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_473070_00473070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_473070_00473070.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4731B0_004731b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4731B0_004731b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4731B0_004731b0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_473BE0_00473be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_473BE0_00473be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_473BE0_00473be0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_473E40_00473e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_473E40_00473e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_473E40_00473e40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_473EF0_00473ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_473EF0_00473ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_473EF0_00473ef0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4750F0_004750f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4750F0_004750f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4750F0_004750f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475100_00475100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475100_00475100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475100_00475100.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475110_00475110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475110_00475110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475110_00475110.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4751D0_004751d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4751D0_004751d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4751D0_004751d0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475280_00475280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475280_00475280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475280_00475280.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475350_00475350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475350_00475350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475350_00475350.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4753A0_004753a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4753A0_004753a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4753A0_004753a0.md
