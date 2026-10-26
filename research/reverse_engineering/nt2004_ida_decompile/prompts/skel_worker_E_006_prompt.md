# SKELETON FILL — Worker E chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2DC0_004c2dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2DC0_004c2dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2DC0_004c2dc0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2E00_004c2e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2E00_004c2e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2E00_004c2e00.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C3070_004c3070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C3070_004c3070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C3070_004c3070.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_62_004c30a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_62_004c30a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_62_004c30a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C30E0_004c30e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C30E0_004c30e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C30E0_004c30e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C3170_004c3170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C3170_004c3170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C3170_004c3170.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C65E0_004c65e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C65E0_004c65e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C65E0_004c65e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CA8B0_004ca8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CA8B0_004ca8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CA8B0_004ca8b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CA8D0_004ca8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CA8D0_004ca8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CA8D0_004ca8d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CA940_004ca940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CA940_004ca940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CA940_004ca940.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CB220_004cb220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CB220_004cb220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CB220_004cb220.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CC230_004cc230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CC230_004cc230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CC230_004cc230.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CD640_004cd640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CD640_004cd640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CD640_004cd640.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CD760_004cd760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CD760_004cd760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CD760_004cd760.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CD7E0_004cd7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CD7E0_004cd7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CD7E0_004cd7e0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CD870_004cd870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CD870_004cd870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CD870_004cd870.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE420_004ce420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE420_004ce420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE420_004ce420.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE6E0_004ce6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE6E0_004ce6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE6E0_004ce6e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE720_004ce720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE720_004ce720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE720_004ce720.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE760_004ce760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE760_004ce760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE760_004ce760.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE820_004ce820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE820_004ce820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE820_004ce820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE920_004ce920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE920_004ce920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE920_004ce920.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE950_004ce950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE950_004ce950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE950_004ce950.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE990_004ce990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE990_004ce990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE990_004ce990.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE9E0_004ce9e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE9E0_004ce9e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE9E0_004ce9e0.md
