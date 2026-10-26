# SKELETON FILL — Worker A chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B9DF0_005b9df0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B9DF0_005b9df0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B9DF0_005b9df0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA610_005ba610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA610_005ba610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA610_005ba610.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BAAD0_005baad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BAAD0_005baad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BAAD0_005baad0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BACC0_005bacc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BACC0_005bacc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BACC0_005bacc0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBAC0_005bbac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBAC0_005bbac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBAC0_005bbac0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBC20_005bbc20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBC20_005bbc20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBC20_005bbc20.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC150_005bc150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC150_005bc150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC150_005bc150.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC8A0_005bc8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC8A0_005bc8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC8A0_005bc8a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD220_005bd220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD220_005bd220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD220_005bd220.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_atol_005bebfe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_atol_005bebfe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_atol_005bebfe.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_setlocale_005bf960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_setlocale_005bf960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_setlocale_005bf960.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_floor_005c049b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_floor_005c049b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_floor_005c049b.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__lock_file_005c32b5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__lock_file_005c32b5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__lock_file_005c32b5.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__filbuf_005c3359.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__filbuf_005c3359.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__filbuf_005c3359.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__output_005c3890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__output_005c3890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__output_005c3890.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__sopen_005cd019.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__sopen_005cd019.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__sopen_005cd019.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___crtsetenv_005cf818.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___crtsetenv_005cf818.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___crtsetenv_005cf818.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_overflow___basic_filebuf_GU__char_traits_G_std___std__MAEGG_Z_005d1390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_overflow___basic_filebuf_GU__char_traits_G_std___std__MAEGG_Z_005d1390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_overflow___basic_filebuf_GU__char_traits_G_std___std__MAEGG_Z_005d1390.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1B12_005d1b12.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1B12_005d1b12.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1B12_005d1b12.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Init_locale_std__CAPAV_Locimp_12_XZ_005d1f31.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Init_locale_std__CAPAV_Locimp_12_XZ_005d1f31.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Init_locale_std__CAPAV_Locimp_12_XZ_005d1f31.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0_Locimp_locale_std__AAE__N_Z_005d2045.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0_Locimp_locale_std__AAE__N_Z_005d2045.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0_Locimp_locale_std__AAE__N_Z_005d2045.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__1_Locimp_locale_std__UAE_XZ_005d20f7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__1_Locimp_locale_std__UAE_XZ_005d20f7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__1_Locimp_locale_std__UAE_XZ_005d20f7.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D221B_005d221b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D221B_005d221b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D221B_005d221b.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D2750_005d2750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D2750_005d2750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D2750_005d2750.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_401A10_00401a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_401A10_00401a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_401A10_00401a10.md
