# SKELETON FILL — Worker A chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F37D0_004f37d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F37D0_004f37d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F37D0_004f37d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5061D0_005061d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5061D0_005061d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5061D0_005061d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5374C0_005374c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5374C0_005374c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5374C0_005374c0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_539830_00539830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_539830_00539830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_539830_00539830.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54EB0F_0054eb0f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54EB0F_0054eb0f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54EB0F_0054eb0f.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56DE40_0056de40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56DE40_0056de40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56DE40_0056de40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56FE30_0056fe30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56FE30_0056fe30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56FE30_0056fe30.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599F40_00599f40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599F40_00599f40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599F40_00599f40.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AA830_005aa830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AA830_005aa830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AA830_005aa830.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AE610_005ae610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AE610_005ae610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AE610_005ae610.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC450_005bc450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC450_005bc450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC450_005bc450.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC6D0_005bc6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC6D0_005bc6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC6D0_005bc6d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405A30_00405a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405A30_00405a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405A30_00405a30.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410A4A_00410a4a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410A4A_00410a4a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410A4A_00410a4a.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414BB0_00414bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414BB0_00414bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414BB0_00414bb0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4152E0_004152e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4152E0_004152e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4152E0_004152e0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_415860_00415860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_415860_00415860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_415860_00415860.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418900_00418900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418900_00418900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418900_00418900.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4412D0_004412d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4412D0_004412d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4412D0_004412d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464150_00464150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464150_00464150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464150_00464150.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464BD0_00464bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464BD0_00464bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464BD0_00464bd0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7320_004b7320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7320_004b7320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7320_004b7320.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4D60_004d4d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4D60_004d4d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4D60_004d4d60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D54F0_004d54f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D54F0_004d54f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D54F0_004d54f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4250_004e4250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4250_004e4250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4250_004e4250.md
