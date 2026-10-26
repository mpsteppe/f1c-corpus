# SKELETON FILL — Worker A chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40F290_0040f290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40F290_0040f290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40F290_0040f290.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40F2B0_0040f2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40F2B0_0040f2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40F2B0_0040f2b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40FF80_0040ff80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40FF80_0040ff80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40FF80_0040ff80.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4100F0_004100f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4100F0_004100f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4100F0_004100f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410460_00410460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410460_00410460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410460_00410460.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410500_00410500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410500_00410500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410500_00410500.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410520_00410520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410520_00410520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410520_00410520.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410560_00410560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410560_00410560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410560_00410560.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_411F40_00411f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_411F40_00411f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_411F40_00411f40.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_412150_00412150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_412150_00412150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_412150_00412150.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_412520_00412520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_412520_00412520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_412520_00412520.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_412710_00412710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_412710_00412710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_412710_00412710.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_412CC0_00412cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_412CC0_00412cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_412CC0_00412cc0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_15_00413152.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_15_00413152.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_15_00413152.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413370_00413370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413370_00413370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413370_00413370.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413700_00413700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413700_00413700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413700_00413700.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4137C0_004137c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4137C0_004137c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4137C0_004137c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_17_00413a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_17_00413a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_17_00413a10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_18_00413a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_18_00413a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_18_00413a20.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413A30_00413a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413A30_00413a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413A30_00413a30.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413A40_00413a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413A40_00413a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413A40_00413a40.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413A60_00413a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413A60_00413a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413A60_00413a60.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413AC0_00413ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413AC0_00413ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413AC0_00413ac0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413AF0_00413af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413AF0_00413af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413AF0_00413af0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413CE0_00413ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413CE0_00413ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413CE0_00413ce0.md
