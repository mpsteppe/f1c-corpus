# SKELETON FILL — Worker E chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED760_004ed760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED760_004ed760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED760_004ed760.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED790_004ed790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED790_004ed790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED790_004ed790.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED7B0_004ed7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED7B0_004ed7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED7B0_004ed7b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED7D0_004ed7d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED7D0_004ed7d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED7D0_004ed7d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED7F0_004ed7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED7F0_004ed7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED7F0_004ed7f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED810_004ed810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED810_004ed810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED810_004ed810.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED830_004ed830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED830_004ed830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED830_004ed830.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED850_004ed850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED850_004ed850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED850_004ed850.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED870_004ed870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED870_004ed870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED870_004ed870.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED8A0_004ed8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED8A0_004ed8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED8A0_004ed8a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED8C0_004ed8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED8C0_004ed8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED8C0_004ed8c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED8E0_004ed8e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED8E0_004ed8e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED8E0_004ed8e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED9A0_004ed9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED9A0_004ed9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED9A0_004ed9a0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDA70_004eda70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDA70_004eda70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDA70_004eda70.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDAD0_004edad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDAD0_004edad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDAD0_004edad0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDB70_004edb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDB70_004edb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDB70_004edb70.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDBE0_004edbe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDBE0_004edbe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDBE0_004edbe0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDC60_004edc60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDC60_004edc60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDC60_004edc60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDCB0_004edcb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDCB0_004edcb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDCB0_004edcb0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDD70_004edd70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDD70_004edd70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDD70_004edd70.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDDA0_004edda0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDDA0_004edda0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDDA0_004edda0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDDB0_004eddb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDDB0_004eddb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDDB0_004eddb0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDDD0_004eddd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDDD0_004eddd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDDD0_004eddd0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDE00_004ede00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDE00_004ede00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDE00_004ede00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EDED0_004eded0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EDED0_004eded0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EDED0_004eded0.md
