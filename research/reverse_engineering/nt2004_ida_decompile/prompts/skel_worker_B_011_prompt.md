# SKELETON FILL — Worker B chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441BB0_00441bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441BB0_00441bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441BB0_00441bb0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441CA0_00441ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441CA0_00441ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441CA0_00441ca0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441D90_00441d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441D90_00441d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441D90_00441d90.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441DB0_00441db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441DB0_00441db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441DB0_00441db0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_441DD0_00441dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_441DD0_00441dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_441DD0_00441dd0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_442060_00442060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_442060_00442060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_442060_00442060.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4420C0_004420c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4420C0_004420c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4420C0_004420c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_444560_00444560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_444560_00444560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_444560_00444560.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4445D0_004445d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4445D0_004445d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4445D0_004445d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_444740_00444740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_444740_00444740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_444740_00444740.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_444D80_00444d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_444D80_00444d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_444D80_00444d80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_445230_00445230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_445230_00445230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_445230_00445230.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_446E30_00446e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_446E30_00446e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_446E30_00446e30.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_449750_00449750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_449750_00449750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_449750_00449750.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4497B0_004497b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4497B0_004497b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4497B0_004497b0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_449840_00449840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_449840_00449840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_449840_00449840.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A1D0_0044a1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A1D0_0044a1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A1D0_0044a1d0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A230_0044a230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A230_0044a230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A230_0044a230.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A2D0_0044a2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A2D0_0044a2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A2D0_0044a2d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A390_0044a390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A390_0044a390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A390_0044a390.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A420_0044a420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A420_0044a420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A420_0044a420.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A530_0044a530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A530_0044a530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A530_0044a530.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44A630_0044a630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44A630_0044a630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44A630_0044a630.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_25_0044be2c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_25_0044be2c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_25_0044be2c.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_26_0044be50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_26_0044be50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_26_0044be50.md
