# SKELETON FILL — Worker D chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6220_004a6220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6220_004a6220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6220_004a6220.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6280_004a6280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6280_004a6280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6280_004a6280.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A62E0_004a62e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A62E0_004a62e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A62E0_004a62e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6400_004a6400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6400_004a6400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6400_004a6400.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6420_004a6420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6420_004a6420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6420_004a6420.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A64A0_004a64a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A64A0_004a64a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A64A0_004a64a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6520_004a6520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6520_004a6520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6520_004a6520.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A65D0_004a65d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A65D0_004a65d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A65D0_004a65d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6D90_004a6d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6D90_004a6d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6D90_004a6d90.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7120_004a7120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7120_004a7120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7120_004a7120.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7310_004a7310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7310_004a7310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7310_004a7310.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7560_004a7560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7560_004a7560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7560_004a7560.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7600_004a7600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7600_004a7600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7600_004a7600.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7830_004a7830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7830_004a7830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7830_004a7830.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A78A0_004a78a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A78A0_004a78a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A78A0_004a78a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A79D0_004a79d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A79D0_004a79d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A79D0_004a79d0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7A80_004a7a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7A80_004a7a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7A80_004a7a80.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7EA0_004a7ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7EA0_004a7ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7EA0_004a7ea0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7ED0_004a7ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7ED0_004a7ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7ED0_004a7ed0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A7F90_004a7f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A7F90_004a7f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A7F90_004a7f90.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A80A0_004a80a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A80A0_004a80a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A80A0_004a80a0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8120_004a8120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8120_004a8120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8120_004a8120.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8160_004a8160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8160_004a8160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8160_004a8160.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8220_004a8220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8220_004a8220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8220_004a8220.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8310_004a8310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8310_004a8310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8310_004a8310.md
