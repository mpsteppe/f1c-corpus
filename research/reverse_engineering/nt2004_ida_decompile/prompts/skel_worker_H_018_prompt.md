# SKELETON FILL — Worker H chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB4D_005cfb4d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB4D_005cfb4d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB4D_005cfb4d.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB57_005cfb57.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB57_005cfb57.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB57_005cfb57.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB70_005cfb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB70_005cfb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB70_005cfb70.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB7A_005cfb7a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB7A_005cfb7a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB7A_005cfb7a.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB9F_005cfb9f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB9F_005cfb9f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB9F_005cfb9f.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFBBE_005cfbbe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFBBE_005cfbbe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFBBE_005cfbbe.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFBE3_005cfbe3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFBE3_005cfbe3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFBE3_005cfbe3.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC02_005cfc02.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC02_005cfc02.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC02_005cfc02.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC0C_005cfc0c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC0C_005cfc0c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC0C_005cfc0c.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC25_005cfc25.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC25_005cfc25.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC25_005cfc25.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC2F_005cfc2f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC2F_005cfc2f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC2F_005cfc2f.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC54_005cfc54.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC54_005cfc54.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC54_005cfc54.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC5E_005cfc5e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC5E_005cfc5e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC5E_005cfc5e.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFC83_005cfc83.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFC83_005cfc83.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFC83_005cfc83.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0Init_ios_base_std__QAE_XZ_005cfc8d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0Init_ios_base_std__QAE_XZ_005cfc8d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0Init_ios_base_std__QAE_XZ_005cfc8d.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFE0C_005cfe0c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFE0C_005cfe0c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFE0C_005cfe0c.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFE4F_005cfe4f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFE4F_005cfe4f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFE4F_005cfe4f.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFEB9_005cfeb9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFEB9_005cfeb9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFEB9_005cfeb9.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_185_005cff18.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_185_005cff18.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_185_005cff18.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFF62_005cff62.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFF62_005cff62.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFF62_005cff62.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFF6D_005cff6d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFF6D_005cff6d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFF6D_005cff6d.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFFD5_005cffd5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFFD5_005cffd5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFFD5_005cffd5.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0034_005d0034.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0034_005d0034.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0034_005d0034.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__1locale_std__QAE_XZ_005d00e8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__1locale_std__QAE_XZ_005d00e8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__1locale_std__QAE_XZ_005d00e8.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0139_005d0139.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0139_005d0139.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0139_005d0139.md
