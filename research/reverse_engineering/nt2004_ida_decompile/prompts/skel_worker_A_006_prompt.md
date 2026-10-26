# SKELETON FILL — Worker A chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E8A30_004e8a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E8A30_004e8a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E8A30_004e8a30.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E9CE0_004e9ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E9CE0_004e9ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E9CE0_004e9ce0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB370_004eb370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB370_004eb370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB370_004eb370.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EFEF0_004efef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EFEF0_004efef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EFEF0_004efef0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F2BC0_004f2bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F2BC0_004f2bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F2BC0_004f2bc0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F3200_004f3200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F3200_004f3200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F3200_004f3200.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500D60_00500d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500D60_00500d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500D60_00500d60.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_500FE0_00500fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_500FE0_00500fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_500FE0_00500fe0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_503A50_00503a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_503A50_00503a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_503A50_00503a50.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504B70_00504b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504B70_00504b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504B70_00504b70.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_504CB0_00504cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_504CB0_00504cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_504CB0_00504cb0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506750_00506750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506750_00506750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506750_00506750.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_507890_00507890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_507890_00507890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_507890_00507890.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_509660_00509660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_509660_00509660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_509660_00509660.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BC20_0051bc20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BC20_0051bc20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BC20_0051bc20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527460_00527460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527460_00527460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527460_00527460.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528970_00528970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528970_00528970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528970_00528970.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_537940_00537940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_537940_00537940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_537940_00537940.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E879_0054e879.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E879_0054e879.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E879_0054e879.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555BAC_00555bac.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555BAC_00555bac.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555BAC_00555bac.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56D860_0056d860.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56D860_0056d860.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56D860_0056d860.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56E0C0_0056e0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56E0C0_0056e0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56E0C0_0056e0c0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_581E90_00581e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_581E90_00581e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_581E90_00581e90.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598240_00598240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598240_00598240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598240_00598240.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_598D70_00598d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_598D70_00598d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_598D70_00598d70.md
