# SKELETON FILL — Worker F chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504480_00504480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504480_00504480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504480_00504480.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504556_00504556.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504556_00504556.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504556_00504556.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504560_00504560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504560_00504560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504560_00504560.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504630_00504630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504630_00504630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504630_00504630.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5046B0_005046b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5046B0_005046b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5046B0_005046b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5046F0_005046f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5046F0_005046f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5046F0_005046f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504750_00504750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504750_00504750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504750_00504750.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5047B0_005047b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5047B0_005047b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5047B0_005047b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504AD0_00504ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504AD0_00504ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504AD0_00504ad0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504C30_00504c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504C30_00504c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504C30_00504c30.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504C50_00504c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504C50_00504c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504C50_00504c50.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504C70_00504c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504C70_00504c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504C70_00504c70.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504C90_00504c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504C90_00504c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504C90_00504c90.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504DC0_00504dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504DC0_00504dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504DC0_00504dc0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505020_00505020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505020_00505020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505020_00505020.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505640_00505640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505640_00505640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505640_00505640.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5056F0_005056f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5056F0_005056f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5056F0_005056f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5057E0_005057e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5057E0_005057e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5057E0_005057e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_93_005057f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_93_005057f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_93_005057f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_94_00505810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_94_00505810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_94_00505810.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505820_00505820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505820_00505820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505820_00505820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_95_00505830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_95_00505830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_95_00505830.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_96_00505850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_96_00505850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_96_00505850.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_505860_00505860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_505860_00505860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_505860_00505860.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_97_00505870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_97_00505870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_97_00505870.md
