# SKELETON FILL — Worker A chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D650_0059d650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D650_0059d650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D650_0059d650.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB940_005bb940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB940_005bb940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB940_005bb940.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC800_005bc800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC800_005bc800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC800_005bc800.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCA40_005bca40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCA40_005bca40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCA40_005bca40.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD3F0_005bd3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD3F0_005bd3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD3F0_005bd3f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_atof_005bf239.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_atof_005bf239.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_atof_005bf239.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_clear_ios_base_std__QAEXH_N_Z_005d1a76.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_clear_ios_base_std__QAEXH_N_Z_005d1a76.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_clear_ios_base_std__QAEXH_N_Z_005d1a76.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Xlen_std__YAXXZ_005d21c1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Xlen_std__YAXXZ_005d21c1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Xlen_std__YAXXZ_005d21c1.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Xran_std__YAXXZ_005d23e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Xran_std__YAXXZ_005d23e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Xran_std__YAXXZ_005d23e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__dup_005d27e6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__dup_005d27e6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__dup_005d27e6.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_401360_00401360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_401360_00401360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_401360_00401360.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4065B0_004065b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4065B0_004065b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4065B0_004065b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406DE0_00406de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406DE0_00406de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406DE0_00406de0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406F10_00406f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406F10_00406f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406F10_00406f10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4118F0_004118f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4118F0_004118f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4118F0_004118f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414B10_00414b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414B10_00414b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414B10_00414b10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415570_00415570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415570_00415570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415570_00415570.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415E00_00415e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415E00_00415e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415E00_00415e00.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416060_00416060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416060_00416060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416060_00416060.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416480_00416480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416480_00416480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416480_00416480.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41BF30_0041bf30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41BF30_0041bf30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41BF30_0041bf30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42EBB0_0042ebb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42EBB0_0042ebb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42EBB0_0042ebb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F350_0042f350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F350_0042f350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F350_0042f350.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_434150_00434150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_434150_00434150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_434150_00434150.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_434F10_00434f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_434F10_00434f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_434F10_00434f10.md
