# SKELETON FILL — Worker D chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF290_004af290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF290_004af290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF290_004af290.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF2D0_004af2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF2D0_004af2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF2D0_004af2d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF2E0_004af2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF2E0_004af2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF2E0_004af2e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF2E5_004af2e5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF2E5_004af2e5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF2E5_004af2e5.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF330_004af330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF330_004af330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF330_004af330.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF3A0_004af3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF3A0_004af3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF3A0_004af3a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF450_004af450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF450_004af450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF450_004af450.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF4C0_004af4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF4C0_004af4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF4C0_004af4c0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF5B0_004af5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF5B0_004af5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF5B0_004af5b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF5C0_004af5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF5C0_004af5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF5C0_004af5c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF650_004af650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF650_004af650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF650_004af650.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF6E0_004af6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF6E0_004af6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF6E0_004af6e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF730_004af730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF730_004af730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF730_004af730.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF810_004af810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF810_004af810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF810_004af810.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_42_004af8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_42_004af8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_42_004af8d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_43_004af8f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_43_004af8f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_43_004af8f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFB23_004afb23.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFB23_004afb23.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFB23_004afb23.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFB30_004afb30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFB30_004afb30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFB30_004afb30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFB80_004afb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFB80_004afb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFB80_004afb80.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFC7C_004afc7c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFC7C_004afc7c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFC7C_004afc7c.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFC80_004afc80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFC80_004afc80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFC80_004afc80.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFCB0_004afcb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFCB0_004afcb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFCB0_004afcb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFD40_004afd40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFD40_004afd40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFD40_004afd40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFDB0_004afdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFDB0_004afdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFDB0_004afdb0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AFE40_004afe40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AFE40_004afe40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AFE40_004afe40.md
