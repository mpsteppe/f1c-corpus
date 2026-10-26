# SKELETON FILL — Worker H chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D182B_005d182b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D182B_005d182b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D182B_005d182b.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_init___basic_ios_GU__char_traits_G_std___std__IAEXPAV__basic_streambuf_GU__char_traits_G_std___2__N_Z_005d1863.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_init___basic_ios_GU__char_traits_G_std___std__IAEXPAV__basic_streambuf_GU__char_traits_G_std___2__N_Z_005d1863.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_init___basic_ios_GU__char_traits_G_std___std__IAEXPAV__basic_streambuf_GU__char_traits_G_std___2__N_Z_005d1863.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_194_005d18e2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_194_005d18e2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_194_005d18e2.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_195_005d18f6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_195_005d18f6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_195_005d18f6.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_close___basic_filebuf_GU__char_traits_G_std___std__QAEPAV12_XZ_005d1906.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_close___basic_filebuf_GU__char_traits_G_std___std__QAEPAV12_XZ_005d1906.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_close___basic_filebuf_GU__char_traits_G_std___std__QAEPAV12_XZ_005d1906.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D19AD_005d19ad.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D19AD_005d19ad.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D19AD_005d19ad.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__1_Lockit_std__QAE_XZ_005d1a61.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__1_Lockit_std__QAE_XZ_005d1a61.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__1_Lockit_std__QAE_XZ_005d1a61.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1B76_005d1b76.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1B76_005d1b76.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1B76_005d1b76.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1B83_005d1b83.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1B83_005d1b83.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1B83_005d1b83.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_197_005d1ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_197_005d1ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_197_005d1ba0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1BDD_005d1bdd.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1BDD_005d1bdd.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1BDD_005d1bdd.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1BF9_005d1bf9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1BF9_005d1bf9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1BF9_005d1bf9.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_198_005d1c56.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_198_005d1c56.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_198_005d1c56.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1C93_005d1c93.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1C93_005d1c93.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1C93_005d1c93.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1CB0_005d1cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1CB0_005d1cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1CB0_005d1cb0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1CCC_005d1ccc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1CCC_005d1ccc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1CCC_005d1ccc.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__1ios_base_std__UAE_XZ_005d1ce4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__1ios_base_std__UAE_XZ_005d1ce4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__1ios_base_std__UAE_XZ_005d1ce4.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___Gios_base_std__UAEPAXI_Z_005d1d34.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___Gios_base_std__UAEPAXI_Z_005d1d34.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___Gios_base_std__UAEPAXI_Z_005d1d34.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Tidy_ios_base_std__AAEXXZ_005d1df8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Tidy_ios_base_std__AAEXXZ_005d1df8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Tidy_ios_base_std__AAEXXZ_005d1df8.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1F10_005d1f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1F10_005d1f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1F10_005d1f10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1F27_005d1f27.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1F27_005d1f27.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1F27_005d1f27.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_199_005d20be.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_199_005d20be.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_199_005d20be.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D21A9_005d21a9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D21A9_005d21a9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D21A9_005d21a9.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D227F_005d227f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D227F_005d227f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D227F_005d227f.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_201_005d229c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_201_005d229c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_201_005d229c.md
