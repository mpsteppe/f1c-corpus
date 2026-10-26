# SKELETON FILL — Worker F chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52C170_0052c170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52C170_0052c170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52C170_0052c170.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52CDC0_0052cdc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52CDC0_0052cdc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52CDC0_0052cdc0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52D2E0_0052d2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52D2E0_0052d2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52D2E0_0052d2e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52D380_0052d380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52D380_0052d380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52D380_0052d380.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52D830_0052d830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52D830_0052d830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52D830_0052d830.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52DAB0_0052dab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52DAB0_0052dab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52DAB0_0052dab0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E5C0_0052e5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E5C0_0052e5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E5C0_0052e5c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E5D0_0052e5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E5D0_0052e5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E5D0_0052e5d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E630_0052e630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E630_0052e630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E630_0052e630.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E720_0052e720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E720_0052e720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E720_0052e720.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E740_0052e740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E740_0052e740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E740_0052e740.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E7F0_0052e7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E7F0_0052e7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E7F0_0052e7f0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E830_0052e830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E830_0052e830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E830_0052e830.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52E870_0052e870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52E870_0052e870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52E870_0052e870.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52EE00_0052ee00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52EE00_0052ee00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52EE00_0052ee00.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52EF20_0052ef20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52EF20_0052ef20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52EF20_0052ef20.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52F4A0_0052f4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52F4A0_0052f4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52F4A0_0052f4a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52F5C0_0052f5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52F5C0_0052f5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52F5C0_0052f5c0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52F6D0_0052f6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52F6D0_0052f6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52F6D0_0052f6d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52F820_0052f820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52F820_0052f820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52F820_0052f820.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\j_unknown_libname_105_0052fbd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\j_unknown_libname_105_0052fbd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\j_unknown_libname_105_0052fbd0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52FBD7_0052fbd7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52FBD7_0052fbd7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52FBD7_0052fbd7.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52FBF0_0052fbf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52FBF0_0052fbf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52FBF0_0052fbf0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_106_0052fc20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_106_0052fc20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_106_0052fc20.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536480_00536480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536480_00536480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536480_00536480.md
