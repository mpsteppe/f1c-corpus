# SKELETON FILL — Worker F chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF090_004ef090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF090_004ef090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF090_004ef090.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF140_004ef140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF140_004ef140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF140_004ef140.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF1B0_004ef1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF1B0_004ef1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF1B0_004ef1b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF1C6_004ef1c6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF1C6_004ef1c6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF1C6_004ef1c6.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF200_004ef200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF200_004ef200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF200_004ef200.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF2C0_004ef2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF2C0_004ef2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF2C0_004ef2c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF302_004ef302.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF302_004ef302.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF302_004ef302.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF370_004ef370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF370_004ef370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF370_004ef370.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF7B0_004ef7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF7B0_004ef7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF7B0_004ef7b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EF8A0_004ef8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EF8A0_004ef8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EF8A0_004ef8a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFA70_004efa70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFA70_004efa70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFA70_004efa70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFA90_004efa90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFA90_004efa90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFA90_004efa90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFCF0_004efcf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFCF0_004efcf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFCF0_004efcf0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFD80_004efd80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFD80_004efd80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFD80_004efd80.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFDE0_004efde0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFDE0_004efde0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFDE0_004efde0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFE00_004efe00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFE00_004efe00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFE00_004efe00.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFFD0_004effd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFFD0_004effd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFFD0_004effd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0020_004f0020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0020_004f0020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0020_004f0020.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0140_004f0140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0140_004f0140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0140_004f0140.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F01B0_004f01b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F01B0_004f01b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F01B0_004f01b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0200_004f0200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0200_004f0200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0200_004f0200.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0320_004f0320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0320_004f0320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0320_004f0320.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F03B0_004f03b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F03B0_004f03b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F03B0_004f03b0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F04C0_004f04c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F04C0_004f04c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F04C0_004f04c0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F0A40_004f0a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F0A40_004f0a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F0A40_004f0a40.md
