# SKELETON FILL — Worker G chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_144_005774e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_144_005774e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_144_005774e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577560_00577560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577560_00577560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577560_00577560.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577646_00577646.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577646_00577646.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577646_00577646.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5776C0_005776c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5776C0_005776c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5776C0_005776c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_145_005776e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_145_005776e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_145_005776e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577710_00577710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577710_00577710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577710_00577710.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_146_00577720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_146_00577720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_146_00577720.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_147_00577740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_147_00577740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_147_00577740.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577750_00577750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577750_00577750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577750_00577750.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_148_00577760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_148_00577760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_148_00577760.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_149_00577780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_149_00577780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_149_00577780.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577790_00577790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577790_00577790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577790_00577790.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_150_00577ab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_150_00577ab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_150_00577ab0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577AE0_00577ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577AE0_00577ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577AE0_00577ae0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_151_00577af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_151_00577af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_151_00577af0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_152_00577b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_152_00577b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_152_00577b10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577B20_00577b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577B20_00577b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577B20_00577b20.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_153_00577b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_153_00577b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_153_00577b30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_154_00577b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_154_00577b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_154_00577b50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_577DA0_00577da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_577DA0_00577da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_577DA0_00577da0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_129_00577e46.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_129_00577e46.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_129_00577e46.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_578800_00578800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_578800_00578800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_578800_00578800.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5788D0_005788d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5788D0_005788d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5788D0_005788d0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_578A26_00578a26.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_578A26_00578a26.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_578A26_00578a26.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579060_00579060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579060_00579060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579060_00579060.md
