# SKELETON FILL — Worker B chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_31_0044f660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_31_0044f660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_31_0044f660.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F6B0_0044f6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F6B0_0044f6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F6B0_0044f6b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_32_0044f6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_32_0044f6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_32_0044f6c0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_62_0044f700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_62_0044f700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_62_0044f700.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F710_0044f710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F710_0044f710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F710_0044f710.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_33_0044f720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_33_0044f720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_33_0044f720.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_63_0044f760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_63_0044f760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_63_0044f760.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F770_0044f770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F770_0044f770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F770_0044f770.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__cfltcvt_init_34_0044f780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__cfltcvt_init_34_0044f780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__cfltcvt_init_34_0044f780.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_65_0044f7c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_65_0044f7c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_65_0044f7c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F7D0_0044f7d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F7D0_0044f7d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F7D0_0044f7d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_67_0044f820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_67_0044f820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_67_0044f820.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F830_0044f830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F830_0044f830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F830_0044f830.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_69_0044f880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_69_0044f880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_69_0044f880.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44F890_0044f890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44F890_0044f890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44F890_0044f890.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_70_0044f8e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_70_0044f8e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_70_0044f8e0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451240_00451240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451240_00451240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451240_00451240.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451250_00451250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451250_00451250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451250_00451250.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451460_00451460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451460_00451460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451460_00451460.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4514A0_004514a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4514A0_004514a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4514A0_004514a0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4514D0_004514d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4514D0_004514d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4514D0_004514d0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451510_00451510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451510_00451510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451510_00451510.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451580_00451580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451580_00451580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451580_00451580.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451680_00451680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451680_00451680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451680_00451680.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_451960_00451960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_451960_00451960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_451960_00451960.md
