# SKELETON FILL — Worker E chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCE30_004dce30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCE30_004dce30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCE30_004dce30.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCEB0_004dceb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCEB0_004dceb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCEB0_004dceb0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD090_004dd090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD090_004dd090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD090_004dd090.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD0C0_004dd0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD0C0_004dd0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD0C0_004dd0c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD0F0_004dd0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD0F0_004dd0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD0F0_004dd0f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD120_004dd120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD120_004dd120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD120_004dd120.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD140_004dd140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD140_004dd140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD140_004dd140.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD150_004dd150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD150_004dd150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD150_004dd150.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD160_004dd160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD160_004dd160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD160_004dd160.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD1C0_004dd1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD1C0_004dd1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD1C0_004dd1c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DD350_004dd350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DD350_004dd350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DD350_004dd350.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DE880_004de880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DE880_004de880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DE880_004de880.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DE8F0_004de8f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DE8F0_004de8f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DE8F0_004de8f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DE920_004de920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DE920_004de920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DE920_004de920.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DE950_004de950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DE950_004de950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DE950_004de950.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DE9D0_004de9d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DE9D0_004de9d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DE9D0_004de9d0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEA70_004dea70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEA70_004dea70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEA70_004dea70.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEB10_004deb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEB10_004deb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEB10_004deb10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEB20_004deb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEB20_004deb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEB20_004deb20.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEB48_004deb48.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEB48_004deb48.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEB48_004deb48.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEB50_004deb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEB50_004deb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEB50_004deb50.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEB90_004deb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEB90_004deb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEB90_004deb90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEBD0_004debd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEBD0_004debd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEBD0_004debd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DEBE0_004debe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DEBE0_004debe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DEBE0_004debe0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DED40_004ded40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DED40_004ded40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DED40_004ded40.md
