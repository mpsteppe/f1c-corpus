# SKELETON FILL — Worker A chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413DB0_00413db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413DB0_00413db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413DB0_00413db0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413DD0_00413dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413DD0_00413dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413DD0_00413dd0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413E00_00413e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413E00_00413e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413E00_00413e00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413E60_00413e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413E60_00413e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413E60_00413e60.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_413ED0_00413ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_413ED0_00413ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_413ED0_00413ed0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414130_00414130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414130_00414130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414130_00414130.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414250_00414250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414250_00414250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414250_00414250.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414280_00414280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414280_00414280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414280_00414280.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4142A0_004142a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4142A0_004142a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4142A0_004142a0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4142C0_004142c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4142C0_004142c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4142C0_004142c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4142F0_004142f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4142F0_004142f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4142F0_004142f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414320_00414320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414320_00414320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414320_00414320.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414380_00414380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414380_00414380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414380_00414380.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4144C0_004144c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4144C0_004144c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4144C0_004144c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4145D0_004145d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4145D0_004145d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4145D0_004145d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414600_00414600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414600_00414600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414600_00414600.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414C70_00414c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414C70_00414c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414C70_00414c70.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414D60_00414d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414D60_00414d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414D60_00414d60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414E50_00414e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414E50_00414e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414E50_00414e50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414EB0_00414eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414EB0_00414eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414EB0_00414eb0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414EF0_00414ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414EF0_00414ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414EF0_00414ef0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414F50_00414f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414F50_00414f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414F50_00414f50.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415230_00415230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415230_00415230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415230_00415230.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4152A0_004152a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4152A0_004152a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4152A0_004152a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_7_004152d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_7_004152d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_7_004152d0.md
