# SKELETON FILL — Worker F chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA450_004fa450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA450_004fa450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA450_004fa450.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA660_004fa660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA660_004fa660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA660_004fa660.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA7F0_004fa7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA7F0_004fa7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA7F0_004fa7f0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA900_004fa900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA900_004fa900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA900_004fa900.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FADA0_004fada0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FADA0_004fada0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FADA0_004fada0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FAE10_004fae10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FAE10_004fae10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FAE10_004fae10.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FAE50_004fae50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FAE50_004fae50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FAE50_004fae50.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FAE90_004fae90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FAE90_004fae90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FAE90_004fae90.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FAF90_004faf90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FAF90_004faf90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FAF90_004faf90.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FAFF0_004faff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FAFF0_004faff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FAFF0_004faff0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FB0B0_004fb0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FB0B0_004fb0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FB0B0_004fb0b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FB180_004fb180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FB180_004fb180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FB180_004fb180.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FB200_004fb200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FB200_004fb200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FB200_004fb200.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FBC40_004fbc40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FBC40_004fbc40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FBC40_004fbc40.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FCB50_004fcb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FCB50_004fcb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FCB50_004fcb50.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD5A0_004fd5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD5A0_004fd5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD5A0_004fd5a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD5B0_004fd5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD5B0_004fd5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD5B0_004fd5b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD5C0_004fd5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD5C0_004fd5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD5C0_004fd5c0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD60F_004fd60f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD60F_004fd60f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD60F_004fd60f.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD890_004fd890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD890_004fd890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD890_004fd890.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FE6A8_004fe6a8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FE6A8_004fe6a8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FE6A8_004fe6a8.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FE790_004fe790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FE790_004fe790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FE790_004fe790.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FEA60_004fea60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FEA60_004fea60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FEA60_004fea60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_89_004fea90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_89_004fea90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_89_004fea90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FF690_004ff690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FF690_004ff690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FF690_004ff690.md
