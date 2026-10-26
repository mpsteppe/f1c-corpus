# SKELETON FILL — Worker C chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485F80_00485f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485F80_00485f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485F80_00485f80.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486010_00486010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486010_00486010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486010_00486010.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486080_00486080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486080_00486080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486080_00486080.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4860F0_004860f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4860F0_004860f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4860F0_004860f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486200_00486200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486200_00486200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486200_00486200.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486270_00486270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486270_00486270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486270_00486270.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486330_00486330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486330_00486330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486330_00486330.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486400_00486400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486400_00486400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486400_00486400.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4864C0_004864c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4864C0_004864c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4864C0_004864c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486580_00486580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486580_00486580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486580_00486580.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486640_00486640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486640_00486640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486640_00486640.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486770_00486770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486770_00486770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486770_00486770.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4867C0_004867c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4867C0_004867c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4867C0_004867c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486890_00486890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486890_00486890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486890_00486890.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4868D0_004868d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4868D0_004868d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4868D0_004868d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486AC0_00486ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486AC0_00486ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486AC0_00486ac0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486E00_00486e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486E00_00486e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486E00_00486e00.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486F30_00486f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486F30_00486f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486F30_00486f30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486FD0_00486fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486FD0_00486fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486FD0_00486fd0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_486FF0_00486ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_486FF0_00486ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_486FF0_00486ff0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487010_00487010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487010_00487010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487010_00487010.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487080_00487080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487080_00487080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487080_00487080.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4870F0_004870f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4870F0_004870f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4870F0_004870f0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487180_00487180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487180_00487180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487180_00487180.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4871F0_004871f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4871F0_004871f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4871F0_004871f0.md
