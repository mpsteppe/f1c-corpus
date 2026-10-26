# SKELETON FILL — Worker A chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476570_00476570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476570_00476570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476570_00476570.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4768F0_004768f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4768F0_004768f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4768F0_004768f0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47DB00_0047db00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47DB00_0047db00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47DB00_0047db00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48BAC0_0048bac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48BAC0_0048bac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48BAC0_0048bac0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0650_004a0650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0650_004a0650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0650_004a0650.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1110_004a1110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1110_004a1110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1110_004a1110.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A44C0_004a44c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A44C0_004a44c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A44C0_004a44c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD5B0_004ad5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD5B0_004ad5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD5B0_004ad5b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B2890_004b2890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B2890_004b2890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B2890_004b2890.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5170_004b5170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5170_004b5170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5170_004b5170.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B69E0_004b69e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B69E0_004b69e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B69E0_004b69e0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B79C0_004b79c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B79C0_004b79c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B79C0_004b79c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7B50_004b7b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7B50_004b7b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7B50_004b7b50.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7C20_004b7c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7C20_004b7c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7C20_004b7c20.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8BC0_004b8bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8BC0_004b8bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8BC0_004b8bc0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B96C0_004b96c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B96C0_004b96c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B96C0_004b96c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BF8E0_004bf8e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BF8E0_004bf8e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BF8E0_004bf8e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CD8D0_004cd8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CD8D0_004cd8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CD8D0_004cd8d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2140_004d2140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2140_004d2140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2140_004d2140.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2A70_004d2a70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2A70_004d2a70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2A70_004d2a70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D7380_004d7380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D7380_004d7380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D7380_004d7380.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D78B0_004d78b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D78B0_004d78b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D78B0_004d78b0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8B50_004d8b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8B50_004d8b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8B50_004d8b50.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E4A30_004e4a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E4A30_004e4a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E4A30_004e4a30.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E5E20_004e5e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E5E20_004e5e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E5E20_004e5e20.md
