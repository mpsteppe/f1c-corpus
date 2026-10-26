# SKELETON FILL — Worker PD chunk 1/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45EC80_0045ec80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45EC80_0045ec80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45EC80_0045ec80.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FC2C0_004fc2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FC2C0_004fc2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FC2C0_004fc2c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47CA00_0047ca00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47CA00_0047ca00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47CA00_0047ca00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E73E0_004e73e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E73E0_004e73e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E73E0_004e73e0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40CCF0_0040ccf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40CCF0_0040ccf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40CCF0_0040ccf0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_445FE0_00445fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_445FE0_00445fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_445FE0_00445fe0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4694C0_004694c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4694C0_004694c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4694C0_004694c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9210_004b9210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9210_004b9210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9210_004b9210.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CDA20_004cda20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CDA20_004cda20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CDA20_004cda20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FBE90_004fbe90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FBE90_004fbe90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FBE90_004fbe90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_526D90_00526d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_526D90_00526d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_526D90_00526d90.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5806C0_005806c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5806C0_005806c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5806C0_005806c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4051B0_004051b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4051B0_004051b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4051B0_004051b0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4127D0_004127d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4127D0_004127d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4127D0_004127d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466310_00466310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466310_00466310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466310_00466310.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A9940_004a9940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A9940_004a9940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A9940_004a9940.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7020_004d7020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7020_004d7020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7020_004d7020.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FEDA0_004feda0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FEDA0_004feda0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FEDA0_004feda0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_515C20_00515c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_515C20_00515c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_515C20_00515c20.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53F81B_0053f81b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53F81B_0053f81b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53F81B_0053f81b.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AF520_005af520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AF520_005af520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AF520_005af520.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406840_00406840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406840_00406840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406840_00406840.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_434B40_00434b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_434B40_00434b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_434B40_00434b40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_469050_00469050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_469050_00469050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_469050_00469050.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB5B0_004ab5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB5B0_004ab5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB5B0_004ab5b0.md
