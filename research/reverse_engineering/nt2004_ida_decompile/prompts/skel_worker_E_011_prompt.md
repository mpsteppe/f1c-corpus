# SKELETON FILL — Worker E chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3760_004d3760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3760_004d3760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3760_004d3760.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D37A0_004d37a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D37A0_004d37a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D37A0_004d37a0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3D70_004d3d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3D70_004d3d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3D70_004d3d70.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3EA0_004d3ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3EA0_004d3ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3EA0_004d3ea0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3ED0_004d3ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3ED0_004d3ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3ED0_004d3ed0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3FE0_004d3fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3FE0_004d3fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3FE0_004d3fe0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4070_004d4070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4070_004d4070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4070_004d4070.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D47D0_004d47d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D47D0_004d47d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D47D0_004d47d0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4890_004d4890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4890_004d4890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4890_004d4890.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4A50_004d4a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4A50_004d4a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4A50_004d4a50.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4FE0_004d4fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4FE0_004d4fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4FE0_004d4fe0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5660_004d5660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5660_004d5660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5660_004d5660.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5920_004d5920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5920_004d5920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5920_004d5920.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5A00_004d5a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5A00_004d5a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5A00_004d5a00.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5A50_004d5a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5A50_004d5a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5A50_004d5a50.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D5C20_004d5c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D5C20_004d5c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D5C20_004d5c20.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D60A0_004d60a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D60A0_004d60a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D60A0_004d60a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6190_004d6190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6190_004d6190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6190_004d6190.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6280_004d6280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6280_004d6280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6280_004d6280.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D62E0_004d62e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D62E0_004d62e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D62E0_004d62e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6300_004d6300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6300_004d6300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6300_004d6300.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6360_004d6360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6360_004d6360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6360_004d6360.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6390_004d6390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6390_004d6390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6390_004d6390.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D63B0_004d63b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D63B0_004d63b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D63B0_004d63b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D63D0_004d63d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D63D0_004d63d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D63D0_004d63d0.md
