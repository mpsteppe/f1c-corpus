# SKELETON FILL — Worker C chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4880B0_004880b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4880B0_004880b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4880B0_004880b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4881A0_004881a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4881A0_004881a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4881A0_004881a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488200_00488200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488200_00488200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488200_00488200.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488210_00488210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488210_00488210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488210_00488210.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4882D0_004882d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4882D0_004882d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4882D0_004882d0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488310_00488310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488310_00488310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488310_00488310.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488350_00488350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488350_00488350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488350_00488350.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4884A0_004884a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4884A0_004884a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4884A0_004884a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4888C0_004888c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4888C0_004888c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4888C0_004888c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488970_00488970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488970_00488970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488970_00488970.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488BA0_00488ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488BA0_00488ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488BA0_00488ba0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488CA0_00488ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488CA0_00488ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488CA0_00488ca0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488D00_00488d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488D00_00488d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488D00_00488d00.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488D10_00488d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488D10_00488d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488D10_00488d10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488DD0_00488dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488DD0_00488dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488DD0_00488dd0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488E10_00488e10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488E10_00488e10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488E10_00488e10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488E70_00488e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488E70_00488e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488E70_00488e70.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488E80_00488e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488E80_00488e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488E80_00488e80.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488F70_00488f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488F70_00488f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488F70_00488f70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488FB0_00488fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488FB0_00488fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488FB0_00488fb0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489010_00489010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489010_00489010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489010_00489010.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489020_00489020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489020_00489020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489020_00489020.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48909D_0048909d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48909D_0048909d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48909D_0048909d.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4891D0_004891d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4891D0_004891d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4891D0_004891d0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_489250_00489250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_489250_00489250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_489250_00489250.md
