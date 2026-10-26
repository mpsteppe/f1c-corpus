# SKELETON FILL — Worker H chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0CAF_005d0caf.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0CAF_005d0caf.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0CAF_005d0caf.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0CB9_005d0cb9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0CB9_005d0cb9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0CB9_005d0cb9.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0CC3_005d0cc3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0CC3_005d0cc3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0CC3_005d0cc3.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0CDC_005d0cdc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0CDC_005d0cdc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0CDC_005d0cdc.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0CE6_005d0ce6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0CE6_005d0ce6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0CE6_005d0ce6.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D0B_005d0d0b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D0B_005d0d0b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D0B_005d0d0b.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D2A_005d0d2a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D2A_005d0d2a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D2A_005d0d2a.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D4F_005d0d4f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D4F_005d0d4f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D4F_005d0d4f.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D6E_005d0d6e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D6E_005d0d6e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D6E_005d0d6e.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D93_005d0d93.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D93_005d0d93.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D93_005d0d93.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0D9D_005d0d9d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0D9D_005d0d9d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0D9D_005d0d9d.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0DC2_005d0dc2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0DC2_005d0dc2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0DC2_005d0dc2.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0_Winit_std__QAE_XZ_005d0dcc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0_Winit_std__QAE_XZ_005d0dcc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0_Winit_std__QAE_XZ_005d0dcc.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0F4D_005d0f4d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0F4D_005d0f4d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0F4D_005d0f4d.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0F90_005d0f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0F90_005d0f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0F90_005d0f90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D0FFA_005d0ffa.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D0FFA_005d0ffa.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D0FFA_005d0ffa.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1059_005d1059.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1059_005d1059.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1059_005d1059.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D1064_005d1064.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D1064_005d1064.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D1064_005d1064.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D10CC_005d10cc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D10CC_005d10cc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D10CC_005d10cc.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D112B_005d112b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D112B_005d112b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D112B_005d112b.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D118B_005d118b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D118B_005d118b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D118B_005d118b.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D132B_005d132b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D132B_005d132b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D132B_005d132b.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_192_005d16db.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_192_005d16db.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_192_005d16db.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_193_005d17b8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_193_005d17b8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_193_005d17b8.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5D17F0_005d17f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5D17F0_005d17f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5D17F0_005d17f0.md
