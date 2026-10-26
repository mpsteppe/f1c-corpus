# SKELETON FILL — Worker B chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D030_0041d030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D030_0041d030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D030_0041d030.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D050_0041d050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D050_0041d050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D050_0041d050.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D070_0041d070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D070_0041d070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D070_0041d070.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D090_0041d090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D090_0041d090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D090_0041d090.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D0B0_0041d0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D0B0_0041d0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D0B0_0041d0b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D0D0_0041d0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D0D0_0041d0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D0D0_0041d0d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41E760_0041e760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41E760_0041e760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41E760_0041e760.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0041e7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0041e7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0041e7f0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41E800_0041e800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41E800_0041e800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41E800_0041e800.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0_0041e8e9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0_0041e8e9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_GetNumberOfBoundContexts_SchedulerBase_details_Concurrency__IBEKXZ_0_0041e8e9.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41ECB0_0041ecb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41ECB0_0041ecb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41ECB0_0041ecb0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41ECC0_0041ecc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41ECC0_0041ecc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41ECC0_0041ecc0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41ECE0_0041ece0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41ECE0_0041ece0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41ECE0_0041ece0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0TaskStack_details_Concurrency__QAE_XZ_0041ecf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0TaskStack_details_Concurrency__QAE_XZ_0041ecf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0TaskStack_details_Concurrency__QAE_XZ_0041ecf0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_12_0041f310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_12_0041f310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_12_0041f310.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_13_0041f330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_13_0041f330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_13_0041f330.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F340_0041f340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F340_0041f340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F340_0041f340.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F360_0041f360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F360_0041f360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F360_0041f360.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F3A0_0041f3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F3A0_0041f3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F3A0_0041f3a0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F3E0_0041f3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F3E0_0041f3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F3E0_0041f3e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F400_0041f400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F400_0041f400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F400_0041f400.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F410_0041f410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F410_0041f410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F410_0041f410.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F550_0041f550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F550_0041f550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F550_0041f550.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F560_0041f560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F560_0041f560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F560_0041f560.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41F6AC_0041f6ac.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41F6AC_0041f6ac.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41F6AC_0041f6ac.md
