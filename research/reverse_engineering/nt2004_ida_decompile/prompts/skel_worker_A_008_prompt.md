# SKELETON FILL — Worker A chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4368C0_004368c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4368C0_004368c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4368C0_004368c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_436AB0_00436ab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_436AB0_00436ab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_436AB0_00436ab0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4380C0_004380c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4380C0_004380c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4380C0_004380c0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_438580_00438580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_438580_00438580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_438580_00438580.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4414C0_004414c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4414C0_004414c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4414C0_004414c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4418F0_004418f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4418F0_004418f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4418F0_004418f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4419C0_004419c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4419C0_004419c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4419C0_004419c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_444E60_00444e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_444E60_00444e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_444E60_00444e60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_449620_00449620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_449620_00449620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_449620_00449620.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4519A0_004519a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4519A0_004519a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4519A0_004519a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458310_00458310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458310_00458310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458310_00458310.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4584C0_004584c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4584C0_004584c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4584C0_004584c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458E00_00458e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458E00_00458e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458E00_00458e00.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A950_0045a950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A950_0045a950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A950_0045a950.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D440_0045d440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D440_0045d440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D440_0045d440.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45DFA0_0045dfa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45DFA0_0045dfa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45DFA0_0045dfa0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E2F0_0045e2f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E2F0_0045e2f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E2F0_0045e2f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45E3D0_0045e3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45E3D0_0045e3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45E3D0_0045e3d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460970_00460970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460970_00460970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460970_00460970.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461A10_00461a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461A10_00461a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461A10_00461a10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461B10_00461b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461B10_00461b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461B10_00461b10.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462430_00462430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462430_00462430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462430_00462430.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462A30_00462a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462A30_00462a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462A30_00462a30.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463560_00463560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463560_00463560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463560_00463560.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464290_00464290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464290_00464290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464290_00464290.md
