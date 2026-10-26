# SKELETON FILL — Worker A chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4157C0_004157c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4157C0_004157c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4157C0_004157c0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415800_00415800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415800_00415800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415800_00415800.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415950_00415950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415950_00415950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415950_00415950.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415970_00415970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415970_00415970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415970_00415970.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4159A0_004159a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4159A0_004159a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4159A0_004159a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4159E0_004159e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4159E0_004159e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4159E0_004159e0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415A80_00415a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415A80_00415a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415A80_00415a80.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415B20_00415b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415B20_00415b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415B20_00415b20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415C20_00415c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415C20_00415c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415C20_00415c20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415CC0_00415cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415CC0_00415cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415CC0_00415cc0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415D60_00415d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415D60_00415d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415D60_00415d60.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415FB0_00415fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415FB0_00415fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415FB0_00415fb0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416220_00416220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416220_00416220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416220_00416220.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4162B0_004162b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4162B0_004162b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4162B0_004162b0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416400_00416400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416400_00416400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416400_00416400.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416610_00416610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416610_00416610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416610_00416610.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4166B0_004166b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4166B0_004166b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4166B0_004166b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416750_00416750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416750_00416750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416750_00416750.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_416E70_00416e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_416E70_00416e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_416E70_00416e70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417960_00417960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417960_00417960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417960_00417960.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417AA0_00417aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417AA0_00417aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417AA0_00417aa0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417C10_00417c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417C10_00417c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417C10_00417c10.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417C30_00417c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417C30_00417c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417C30_00417c30.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417C50_00417c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417C50_00417c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417C50_00417c50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_417C70_00417c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_417C70_00417c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_417C70_00417c70.md
