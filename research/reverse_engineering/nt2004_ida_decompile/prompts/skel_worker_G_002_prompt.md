# SKELETON FILL — Worker G chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55071E_0055071e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55071E_0055071e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55071E_0055071e.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_550B64_00550b64.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_550B64_00550b64.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_550B64_00550b64.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_550C66_00550c66.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_550C66_00550c66.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_550C66_00550c66.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_550C6B_00550c6b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_550C6B_00550c6b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_550C6B_00550c6b.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_552296_00552296.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_552296_00552296.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_552296_00552296.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5534C4_005534c4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5534C4_005534c4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5534C4_005534c4.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_554160_00554160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_554160_00554160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_554160_00554160.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5557B6_005557b6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5557B6_005557b6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5557B6_005557b6.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555842_00555842.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555842_00555842.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555842_00555842.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555B62_00555b62.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555B62_00555b62.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555B62_00555b62.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555CB7_00555cb7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555CB7_00555cb7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555CB7_00555cb7.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555F5D_00555f5d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555F5D_00555f5d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555F5D_00555f5d.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5562D4_005562d4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5562D4_005562d4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5562D4_005562d4.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_9_00556303.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_9_00556303.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_9_00556303.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_556954_00556954.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_556954_00556954.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_556954_00556954.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55964D_0055964d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55964D_0055964d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55964D_0055964d.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55A799_0055a799.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55A799_0055a799.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55A799_0055a799.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55AF37_0055af37.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55AF37_0055af37.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55AF37_0055af37.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55D220_0055d220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55D220_0055d220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55D220_0055d220.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_563EF2_00563ef2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_563EF2_00563ef2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_563EF2_00563ef2.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_565D42_00565d42.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_565D42_00565d42.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_565D42_00565d42.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_108_00569ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_108_00569ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_108_00569ce0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_110_00569d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_110_00569d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_110_00569d20.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_569E16_00569e16.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_569E16_00569e16.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_569E16_00569e16.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_112_00569e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_112_00569e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_112_00569e60.md
