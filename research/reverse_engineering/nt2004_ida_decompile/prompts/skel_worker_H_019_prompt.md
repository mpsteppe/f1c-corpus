# SKELETON FILL — Worker H chunk 19/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_152_005d025d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_152_005d025d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_152_005d025d.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D026B_005d026b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D026B_005d026b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D026B_005d026b.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_186_005d05f5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_186_005d05f5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_186_005d05f5.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D06AE_005d06ae.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D06AE_005d06ae.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D06AE_005d06ae.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D06E9_005d06e9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D06E9_005d06e9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D06E9_005d06e9.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_append___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__QAEAAV12_ID_Z_005d0721.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_append___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__QAEAAV12_ID_Z_005d0721.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_append___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__QAEAAV12_ID_Z_005d0721.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_init___basic_ios_DU__char_traits_D_std___std__IAEXPAV__basic_streambuf_DU__char_traits_D_std___2__N_Z_005d081d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_init___basic_ios_DU__char_traits_D_std___std__IAEXPAV__basic_streambuf_DU__char_traits_D_std___2__N_Z_005d081d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_init___basic_ios_DU__char_traits_D_std___std__IAEXPAV__basic_streambuf_DU__char_traits_D_std___2__N_Z_005d081d.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_187_005d08b7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_187_005d08b7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_187_005d08b7.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_close___basic_filebuf_DU__char_traits_D_std___std__QAEPAV12_XZ_005d08c7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_close___basic_filebuf_DU__char_traits_D_std___std__QAEPAV12_XZ_005d08c7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_close___basic_filebuf_DU__char_traits_D_std___std__QAEPAV12_XZ_005d08c7.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Grow___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAE_NI_N_Z_005d0992.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Grow___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAE_NI_N_Z_005d0992.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Grow___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAE_NI_N_Z_005d0992.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_188_005d0a7c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_188_005d0a7c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_188_005d0a7c.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Copy___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAEXI_Z_005d0abe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Copy___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAEXI_Z_005d0abe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Copy___basic_string_DU__char_traits_D_std__V__allocator_D_2__std__AAEXI_Z_005d0abe.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0BF2_005d0bf2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0BF2_005d0bf2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0BF2_005d0bf2.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_12_005d0c0a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_12_005d0c0a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_12_005d0c0a.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C0B_005d0c0b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C0B_005d0c0b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C0B_005d0c0b.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C15_005d0c15.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C15_005d0c15.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C15_005d0c15.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C2B_005d0c2b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C2B_005d0c2b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C2B_005d0c2b.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C35_005d0c35.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C35_005d0c35.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C35_005d0c35.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C3F_005d0c3f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C3F_005d0c3f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C3F_005d0c3f.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C55_005d0c55.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C55_005d0c55.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C55_005d0c55.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C5F_005d0c5f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C5F_005d0c5f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C5F_005d0c5f.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C69_005d0c69.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C69_005d0c69.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C69_005d0c69.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C82_005d0c82.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C82_005d0c82.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C82_005d0c82.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C8C_005d0c8c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C8C_005d0c8c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C8C_005d0c8c.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0C96_005d0c96.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0C96_005d0c96.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0C96_005d0c96.md
