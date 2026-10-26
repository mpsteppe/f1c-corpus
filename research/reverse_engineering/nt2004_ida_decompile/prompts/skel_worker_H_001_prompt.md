# SKELETON FILL — Worker H chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8C40_005a8c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8C40_005a8c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8C40_005a8c40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8E30_005a8e30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8E30_005a8e30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8E30_005a8e30.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9070_005a9070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9070_005a9070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9070_005a9070.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9130_005a9130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9130_005a9130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9130_005a9130.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A91C0_005a91c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A91C0_005a91c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A91C0_005a91c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9360_005a9360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9360_005a9360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9360_005a9360.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A93B0_005a93b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A93B0_005a93b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A93B0_005a93b0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9590_005a9590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9590_005a9590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9590_005a9590.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A95E0_005a95e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A95E0_005a95e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A95E0_005a95e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A97A0_005a97a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A97A0_005a97a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A97A0_005a97a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9870_005a9870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9870_005a9870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9870_005a9870.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A98A0_005a98a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A98A0_005a98a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A98A0_005a98a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A98C0_005a98c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A98C0_005a98c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A98C0_005a98c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A98D0_005a98d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A98D0_005a98d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A98D0_005a98d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9920_005a9920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9920_005a9920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9920_005a9920.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A9AD0_005a9ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A9AD0_005a9ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A9AD0_005a9ad0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AA130_005aa130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AA130_005aa130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AA130_005aa130.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AA150_005aa150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AA150_005aa150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AA150_005aa150.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AA8A0_005aa8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AA8A0_005aa8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AA8A0_005aa8a0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AA930_005aa930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AA930_005aa930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AA930_005aa930.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AACC0_005aacc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AACC0_005aacc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AACC0_005aacc0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AAD80_005aad80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AAD80_005aad80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AAD80_005aad80.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AADD0_005aadd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AADD0_005aadd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AADD0_005aadd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AAED0_005aaed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AAED0_005aaed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AAED0_005aaed0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB000_005ab000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB000_005ab000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB000_005ab000.md
