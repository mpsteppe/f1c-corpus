# SKELETON FILL — Worker C chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4781B0_004781b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4781B0_004781b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4781B0_004781b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478210_00478210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478210_00478210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478210_00478210.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4782B0_004782b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4782B0_004782b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4782B0_004782b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478330_00478330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478330_00478330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478330_00478330.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478850_00478850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478850_00478850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478850_00478850.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478EA0_00478ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478EA0_00478ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478EA0_00478ea0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_478FB0_00478fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_478FB0_00478fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_478FB0_00478fb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_88_00479505.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_88_00479505.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_88_00479505.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_479510_00479510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_479510_00479510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_479510_00479510.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4798EC_004798ec.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4798EC_004798ec.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4798EC_004798ec.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_479A40_00479a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_479A40_00479a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_479A40_00479a40.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47A040_0047a040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47A040_0047a040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47A040_0047a040.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47A140_0047a140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47A140_0047a140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47A140_0047a140.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B380_0047b380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B380_0047b380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B380_0047b380.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B3D0_0047b3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B3D0_0047b3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B3D0_0047b3d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B690_0047b690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B690_0047b690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B690_0047b690.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B830_0047b830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B830_0047b830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B830_0047b830.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B9D0_0047b9d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B9D0_0047b9d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B9D0_0047b9d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_89_0047ba37.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_89_0047ba37.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_89_0047ba37.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BA45_0047ba45.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BA45_0047ba45.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BA45_0047ba45.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BB00_0047bb00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BB00_0047bb00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BB00_0047bb00.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BB20_0047bb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BB20_0047bb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BB20_0047bb20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BB90_0047bb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BB90_0047bb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BB90_0047bb90.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BC70_0047bc70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BC70_0047bc70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BC70_0047bc70.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BCC0_0047bcc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BCC0_0047bcc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BCC0_0047bcc0.md
