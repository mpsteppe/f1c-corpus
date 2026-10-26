# SKELETON FILL — Worker C chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485110_00485110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485110_00485110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485110_00485110.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4851A0_004851a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4851A0_004851a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4851A0_004851a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485210_00485210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485210_00485210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485210_00485210.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485220_00485220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485220_00485220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485220_00485220.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485240_00485240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485240_00485240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485240_00485240.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4852A0_004852a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4852A0_004852a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4852A0_004852a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485420_00485420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485420_00485420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485420_00485420.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485490_00485490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485490_00485490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485490_00485490.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4854AA_004854aa.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4854AA_004854aa.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4854AA_004854aa.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485520_00485520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485520_00485520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485520_00485520.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4855F0_004855f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4855F0_004855f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4855F0_004855f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485600_00485600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485600_00485600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485600_00485600.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4856E0_004856e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4856E0_004856e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4856E0_004856e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485750_00485750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485750_00485750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485750_00485750.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4858A0_004858a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4858A0_004858a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4858A0_004858a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485960_00485960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485960_00485960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485960_00485960.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485A20_00485a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485A20_00485a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485A20_00485a20.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485AE0_00485ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485AE0_00485ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485AE0_00485ae0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485B00_00485b00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485B00_00485b00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485B00_00485b00.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485C10_00485c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485C10_00485c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485C10_00485c10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485E20_00485e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485E20_00485e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485E20_00485e20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485E50_00485e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485E50_00485e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485E50_00485e50.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485E60_00485e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485E60_00485e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485E60_00485e60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485F00_00485f00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485F00_00485f00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485F00_00485f00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_485F10_00485f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_485F10_00485f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_485F10_00485f10.md
