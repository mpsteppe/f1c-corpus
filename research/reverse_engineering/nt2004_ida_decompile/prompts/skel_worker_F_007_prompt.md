# SKELETON FILL — Worker F chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FF6C0_004ff6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FF6C0_004ff6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FF6C0_004ff6c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FFA70_004ffa70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FFA70_004ffa70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FFA70_004ffa70.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FFAA0_004ffaa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FFAA0_004ffaa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FFAA0_004ffaa0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5004E0_005004e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5004E0_005004e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5004E0_005004e0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500CE0_00500ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500CE0_00500ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500CE0_00500ce0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500E50_00500e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500E50_00500e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500E50_00500e50.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_90_00500e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_90_00500e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_90_00500e60.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500E80_00500e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500E80_00500e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500E80_00500e80.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500F40_00500f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500F40_00500f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500F40_00500f40.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501040_00501040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501040_00501040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501040_00501040.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5012C0_005012c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5012C0_005012c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5012C0_005012c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501380_00501380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501380_00501380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501380_00501380.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501470_00501470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501470_00501470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501470_00501470.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_120_005014a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_120_005014a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_120_005014a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501510_00501510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501510_00501510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501510_00501510.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5015E0_005015e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5015E0_005015e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5015E0_005015e0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501610_00501610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501610_00501610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501610_00501610.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501810_00501810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501810_00501810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501810_00501810.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5018A0_005018a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5018A0_005018a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5018A0_005018a0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501960_00501960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501960_00501960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501960_00501960.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501CE0_00501ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501CE0_00501ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501CE0_00501ce0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501DD0_00501dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501DD0_00501dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501DD0_00501dd0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502040_00502040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502040_00502040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502040_00502040.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502060_00502060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502060_00502060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502060_00502060.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_502090_00502090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_502090_00502090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_502090_00502090.md
