# SKELETON FILL — Worker C chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465B70_00465b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465B70_00465b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465B70_00465b70.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465BA0_00465ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465BA0_00465ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465BA0_00465ba0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465BE0_00465be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465BE0_00465be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465BE0_00465be0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465C10_00465c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465C10_00465c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465C10_00465c10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465CC0_00465cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465CC0_00465cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465CC0_00465cc0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465D00_00465d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465D00_00465d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465D00_00465d00.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465D20_00465d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465D20_00465d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465D20_00465d20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465E00_00465e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465E00_00465e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465E00_00465e00.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466660_00466660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466660_00466660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466660_00466660.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4666D0_004666d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4666D0_004666d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4666D0_004666d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466960_00466960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466960_00466960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466960_00466960.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_33_00466970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_33_00466970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_33_00466970.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_34_00466990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_34_00466990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_34_00466990.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4669B0_004669b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4669B0_004669b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4669B0_004669b0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4669E0_004669e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4669E0_004669e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4669E0_004669e0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466A10_00466a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466A10_00466a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466A10_00466a10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466A40_00466a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466A40_00466a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466A40_00466a40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_35_00466aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_35_00466aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_35_00466aa0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466AB0_00466ab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466AB0_00466ab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466AB0_00466ab0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466B10_00466b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466B10_00466b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466B10_00466b10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_466E60_00466e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_466E60_00466e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_466E60_00466e60.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_467CC0_00467cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_467CC0_00467cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_467CC0_00467cc0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_467D20_00467d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_467D20_00467d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_467D20_00467d20.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4682F0_004682f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4682F0_004682f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4682F0_004682f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468380_00468380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468380_00468380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468380_00468380.md
