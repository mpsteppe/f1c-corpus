# SKELETON FILL — Worker B chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_433C40_00433c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_433C40_00433c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_433C40_00433c40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4345D0_004345d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4345D0_004345d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4345D0_004345d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_434710_00434710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_434710_00434710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_434710_00434710.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4347A0_004347a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4347A0_004347a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4347A0_004347a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4347C0_004347c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4347C0_004347c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4347C0_004347c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4347E0_004347e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4347E0_004347e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4347E0_004347e0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435470_00435470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435470_00435470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435470_00435470.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435783_00435783.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435783_00435783.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435783_00435783.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435970_00435970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435970_00435970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435970_00435970.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435A40_00435a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435A40_00435a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435A40_00435a40.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435B70_00435b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435B70_00435b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435B70_00435b70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4365F0_004365f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4365F0_004365f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4365F0_004365f0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_436630_00436630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_436630_00436630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_436630_00436630.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437100_00437100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437100_00437100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437100_00437100.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437120_00437120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437120_00437120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437120_00437120.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437130_00437130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437130_00437130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437130_00437130.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4373B0_004373b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4373B0_004373b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4373B0_004373b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4373F0_004373f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4373F0_004373f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4373F0_004373f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437430_00437430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437430_00437430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437430_00437430.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437460_00437460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437460_00437460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437460_00437460.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437550_00437550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437550_00437550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437550_00437550.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4379D0_004379d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4379D0_004379d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4379D0_004379d0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437A30_00437a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437A30_00437a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437A30_00437a30.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_437A40_00437a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_437A40_00437a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_437A40_00437a40.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_24_00437a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_24_00437a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_24_00437a70.md
