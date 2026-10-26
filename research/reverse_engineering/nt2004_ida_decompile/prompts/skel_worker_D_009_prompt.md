# SKELETON FILL — Worker D chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1660_004a1660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1660_004a1660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1660_004a1660.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1720_004a1720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1720_004a1720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1720_004a1720.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1750_004a1750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1750_004a1750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1750_004a1750.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A17C0_004a17c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A17C0_004a17c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A17C0_004a17c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1860_004a1860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1860_004a1860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1860_004a1860.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1A90_004a1a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1A90_004a1a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1A90_004a1a90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1AC0_004a1ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1AC0_004a1ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1AC0_004a1ac0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1B90_004a1b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1B90_004a1b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1B90_004a1b90.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1BAE_004a1bae.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1BAE_004a1bae.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1BAE_004a1bae.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1BB0_004a1bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1BB0_004a1bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1BB0_004a1bb0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1E3A_004a1e3a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1E3A_004a1e3a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1E3A_004a1e3a.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1E46_004a1e46.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1E46_004a1e46.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1E46_004a1e46.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A22D0_004a22d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A22D0_004a22d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A22D0_004a22d0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2340_004a2340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2340_004a2340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2340_004a2340.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A24A0_004a24a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A24A0_004a24a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A24A0_004a24a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2630_004a2630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2630_004a2630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2630_004a2630.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2BA0_004a2ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2BA0_004a2ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2BA0_004a2ba0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2C40_004a2c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2C40_004a2c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2C40_004a2c40.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2C50_004a2c50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2C50_004a2c50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2C50_004a2c50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2C90_004a2c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2C90_004a2c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2C90_004a2c90.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2CF0_004a2cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2CF0_004a2cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2CF0_004a2cf0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2D80_004a2d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2D80_004a2d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2D80_004a2d80.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2EA0_004a2ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2EA0_004a2ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2EA0_004a2ea0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2F50_004a2f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2F50_004a2f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2F50_004a2f50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A2FD0_004a2fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A2FD0_004a2fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A2FD0_004a2fd0.md
