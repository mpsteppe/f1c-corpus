# SKELETON FILL — Worker D chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFF10_004aff10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFF10_004aff10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFF10_004aff10.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFF20_004aff20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFF20_004aff20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFF20_004aff20.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0090_004b0090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0090_004b0090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0090_004b0090.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B01D0_004b01d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B01D0_004b01d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B01D0_004b01d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B02C0_004b02c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B02C0_004b02c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B02C0_004b02c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B03B0_004b03b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B03B0_004b03b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B03B0_004b03b0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B03F0_004b03f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B03F0_004b03f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B03F0_004b03f0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B04D0_004b04d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B04D0_004b04d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B04D0_004b04d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0560_004b0560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0560_004b0560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0560_004b0560.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B067C_004b067c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B067C_004b067c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B067C_004b067c.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0680_004b0680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0680_004b0680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0680_004b0680.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B07C0_004b07c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B07C0_004b07c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B07C0_004b07c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0900_004b0900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0900_004b0900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0900_004b0900.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0930_004b0930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0930_004b0930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0930_004b0930.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0960_004b0960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0960_004b0960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0960_004b0960.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0AC0_004b0ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0AC0_004b0ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0AC0_004b0ac0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0B30_004b0b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0B30_004b0b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0B30_004b0b30.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0C50_004b0c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0C50_004b0c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0C50_004b0c50.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0DC0_004b0dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0DC0_004b0dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0DC0_004b0dc0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_44_004b0e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_44_004b0e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_44_004b0e30.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B0F90_004b0f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B0F90_004b0f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B0F90_004b0f90.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B1160_004b1160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B1160_004b1160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B1160_004b1160.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_45_004b1190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_45_004b1190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_45_004b1190.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B11A0_004b11a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B11A0_004b11a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B11A0_004b11a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B12B0_004b12b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B12B0_004b12b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B12B0_004b12b0.md
