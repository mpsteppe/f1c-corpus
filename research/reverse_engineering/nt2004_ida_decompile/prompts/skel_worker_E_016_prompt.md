# SKELETON FILL — Worker E chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DF3E0_004df3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DF3E0_004df3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DF3E0_004df3e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DF420_004df420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DF420_004df420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DF420_004df420.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DFED0_004dfed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DFED0_004dfed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DFED0_004dfed0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DFF10_004dff10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DFF10_004dff10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DFF10_004dff10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DFF80_004dff80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DFF80_004dff80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DFF80_004dff80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_72_004dff90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_72_004dff90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_72_004dff90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_73_004dffb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_73_004dffb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_73_004dffb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DFFE0_004dffe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DFFE0_004dffe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DFFE0_004dffe0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E0B30_004e0b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E0B30_004e0b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E0B30_004e0b30.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E0CD0_004e0cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E0CD0_004e0cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E0CD0_004e0cd0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E0EC0_004e0ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E0EC0_004e0ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E0EC0_004e0ec0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E0EF0_004e0ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E0EF0_004e0ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E0EF0_004e0ef0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E14C0_004e14c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E14C0_004e14c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E14C0_004e14c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E1500_004e1500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E1500_004e1500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E1500_004e1500.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E1690_004e1690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E1690_004e1690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E1690_004e1690.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E17F0_004e17f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E17F0_004e17f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E17F0_004e17f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E1D40_004e1d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E1D40_004e1d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E1D40_004e1d40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E1E60_004e1e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E1E60_004e1e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E1E60_004e1e60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E2190_004e2190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E2190_004e2190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E2190_004e2190.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E22F0_004e22f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E22F0_004e22f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E22F0_004e22f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E2570_004e2570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E2570_004e2570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E2570_004e2570.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E29B0_004e29b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E29B0_004e29b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E29B0_004e29b0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E2DB0_004e2db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E2DB0_004e2db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E2DB0_004e2db0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3090_004e3090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3090_004e3090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3090_004e3090.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E3126_004e3126.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E3126_004e3126.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E3126_004e3126.md
