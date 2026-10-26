# SKELETON FILL — Worker H chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D22D9_005d22d9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D22D9_005d22d9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D22D9_005d22d9.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D22F5_005d22f5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D22F5_005d22f5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D22F5_005d22f5.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_202_005d2352.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_202_005d2352.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_202_005d2352.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D238F_005d238f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D238F_005d238f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D238F_005d238f.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D23AC_005d23ac.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D23AC_005d23ac.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D23AC_005d23ac.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D23C8_005d23c8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D23C8_005d23c8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D23C8_005d23c8.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_203_005d243a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_203_005d243a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_203_005d243a.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D2477_005d2477.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D2477_005d2477.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D2477_005d2477.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D2494_005d2494.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D2494_005d2494.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D2494_005d2494.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D24B0_005d24b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D24B0_005d24b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D24B0_005d24b0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D24F2_005d24f2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D24F2_005d24f2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D24F2_005d24f2.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Mbrtowc_lk_005d256d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Mbrtowc_lk_005d256d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Mbrtowc_lk_005d256d.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\ntohl_005d2734.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\ntohl_005d2734.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\ntohl_005d2734.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\gethostname_005d273a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\gethostname_005d273a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\gethostname_005d273a.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fileno_005d28ee.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fileno_005d28ee.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fileno_005d28ee.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fstat_005d28f6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fstat_005d28f6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fstat_005d28f6.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___Gtype_info__UAEPAXI_Z_005d2c62.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___Gtype_info__UAEPAXI_Z_005d2c62.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___Gtype_info__UAEPAXI_Z_005d2c62.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_fsetpos_005d2c7e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_fsetpos_005d2c7e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_fsetpos_005d2c7e.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_setvbuf_005d2c96.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_setvbuf_005d2c96.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_setvbuf_005d2c96.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D3093_005d3093.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D3093_005d3093.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D3093_005d3093.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_memcmp_005d31a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_memcmp_005d31a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_memcmp_005d31a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\retnull_0_005d31ec.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\retnull_0_005d31ec.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\retnull_0_005d31ec.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fseeki64_lk_005d32f6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fseeki64_lk_005d32f6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fseeki64_lk_005d32f6.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D3C1B_005d3c1b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D3C1B_005d3c1b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D3C1B_005d3c1b.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D3C49_005d3c49.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D3C49_005d3c49.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D3C49_005d3c49.md
