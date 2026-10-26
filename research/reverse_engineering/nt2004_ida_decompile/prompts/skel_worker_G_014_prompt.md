# SKELETON FILL — Worker G chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_590220_00590220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_590220_00590220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_590220_00590220.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_134_00590380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_134_00590380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_134_00590380.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_590400_00590400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_590400_00590400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_590400_00590400.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_135_00590410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_135_00590410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_135_00590410.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_136_00590420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_136_00590420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_136_00590420.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_139_00590450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_139_00590450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_139_00590450.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5905D0_005905d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5905D0_005905d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5905D0_005905d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0Iostream_init__QAE_XZ_0_00590820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0Iostream_init__QAE_XZ_0_00590820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0Iostream_init__QAE_XZ_0_00590820.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_140_00590920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_140_00590920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_140_00590920.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_141_00590930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_141_00590930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_141_00590930.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_590940_00590940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_590940_00590940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_590940_00590940.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_143_00591008.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_143_00591008.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_143_00591008.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591010_00591010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591010_00591010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591010_00591010.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5912C0_005912c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5912C0_005912c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5912C0_005912c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591400_00591400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591400_00591400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591400_00591400.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591650_00591650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591650_00591650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591650_00591650.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_155_00591750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_155_00591750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_155_00591750.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591790_00591790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591790_00591790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591790_00591790.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591800_00591800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591800_00591800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591800_00591800.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_156_00591810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_156_00591810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_156_00591810.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591830_00591830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591830_00591830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591830_00591830.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\j_unknown_libname_157_00591850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\j_unknown_libname_157_00591850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\j_unknown_libname_157_00591850.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_157_00591860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_157_00591860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_157_00591860.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591B70_00591b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591B70_00591b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591B70_00591b70.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_591C60_00591c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_591C60_00591c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_591C60_00591c60.md
