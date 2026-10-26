# SKELETON FILL — Worker PC chunk 3/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DDB70_004ddb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DDB70_004ddb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DDB70_004ddb70.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECCB0_004eccb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECCB0_004eccb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECCB0_004eccb0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50FDB0_0050fdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50FDB0_0050fdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50FDB0_0050fdb0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B1D0_0052b1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B1D0_0052b1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B1D0_0052b1d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D4D0_0059d4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D4D0_0059d4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D4D0_0059d4d0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409650_00409650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409650_00409650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409650_00409650.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_414FC0_00414fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_414FC0_00414fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_414FC0_00414fc0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4252A0_004252a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4252A0_004252a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4252A0_004252a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42B680_0042b680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42B680_0042b680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42B680_0042b680.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_442160_00442160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_442160_00442160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_442160_00442160.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_453D00_00453d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_453D00_00453d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_453D00_00453d00.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_467380_00467380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_467380_00467380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_467380_00467380.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_475BE0_00475be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_475BE0_00475be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_475BE0_00475be0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C520_0049c520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C520_0049c520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C520_0049c520.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A4AA0_004a4aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A4AA0_004a4aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A4AA0_004a4aa0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BB1A0_004bb1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BB1A0_004bb1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BB1A0_004bb1a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E0F70_004e0f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E0F70_004e0f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E0F70_004e0f70.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E9780_004e9780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E9780_004e9780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E9780_004e9780.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50A950_0050a950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50A950_0050a950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50A950_0050a950.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_516FF0_00516ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_516FF0_00516ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_516FF0_00516ff0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_525D30_00525d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_525D30_00525d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_525D30_00525d30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_543E7F_00543e7f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_543E7F_00543e7f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_543E7F_00543e7f.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573B50_00573b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573B50_00573b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573B50_00573b50.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593820_00593820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593820_00593820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593820_00593820.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__stat_005c0d23.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__stat_005c0d23.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__stat_005c0d23.md
