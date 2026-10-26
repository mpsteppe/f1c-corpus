# SKELETON FILL — Worker A chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_412200_00412200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_412200_00412200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_412200_00412200.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418E20_00418e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418E20_00418e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418E20_00418e20.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41C5A0_0041c5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41C5A0_0041c5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41C5A0_0041c5a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42F6C0_0042f6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42F6C0_0042f6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42F6C0_0042f6c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42FCC0_0042fcc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42FCC0_0042fcc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42FCC0_0042fcc0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_430BC0_00430bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_430BC0_00430bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_430BC0_00430bc0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435480_00435480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435480_00435480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435480_00435480.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_435E80_00435e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_435E80_00435e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_435E80_00435e80.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4417D0_004417d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4417D0_004417d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4417D0_004417d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4446C0_004446c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4446C0_004446c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4446C0_004446c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4464A0_004464a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4464A0_004464a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4464A0_004464a0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C910_0045c910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C910_0045c910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C910_0045c910.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D100_0045d100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D100_0045d100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D100_0045d100.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D8D0_0045d8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D8D0_0045d8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D8D0_0045d8d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461BC0_00461bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461BC0_00461bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461BC0_00461bc0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462160_00462160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462160_00462160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462160_00462160.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4628E0_004628e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4628E0_004628e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4628E0_004628e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463A40_00463a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463A40_00463a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463A40_00463a40.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_463F30_00463f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_463F30_00463f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_463F30_00463f30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4641B0_004641b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4641B0_004641b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4641B0_004641b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465D30_00465d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465D30_00465d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465D30_00465d30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468720_00468720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468720_00468720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468720_00468720.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46AF10_0046af10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46AF10_0046af10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46AF10_0046af10.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46BEE0_0046bee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46BEE0_0046bee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46BEE0_0046bee0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476050_00476050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476050_00476050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476050_00476050.md
