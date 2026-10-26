# SKELETON FILL — Worker H chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB260_005bb260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB260_005bb260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB260_005bb260.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB340_005bb340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB340_005bb340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB340_005bb340.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB390_005bb390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB390_005bb390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB390_005bb390.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB5D0_005bb5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB5D0_005bb5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB5D0_005bb5d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB620_005bb620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB620_005bb620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB620_005bb620.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB7F0_005bb7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB7F0_005bb7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB7F0_005bb7f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB890_005bb890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB890_005bb890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB890_005bb890.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BB8E0_005bb8e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BB8E0_005bb8e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BB8E0_005bb8e0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBB20_005bbb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBB20_005bbb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBB20_005bbb20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBB50_005bbb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBB50_005bbb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBB50_005bbb50.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBB80_005bbb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBB80_005bbb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBB80_005bbb80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBBD0_005bbbd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBBD0_005bbbd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBBD0_005bbbd0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBBF3_005bbbf3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBBF3_005bbbf3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBBF3_005bbbf3.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBC00_005bbc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBC00_005bbc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBC00_005bbc00.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBC19_005bbc19.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBC19_005bbc19.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBC19_005bbc19.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBD90_005bbd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBD90_005bbd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBD90_005bbd90.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBDD0_005bbdd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBDD0_005bbdd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBDD0_005bbdd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBE90_005bbe90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBE90_005bbe90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBE90_005bbe90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBF60_005bbf60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBF60_005bbf60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBF60_005bbf60.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBFA3_005bbfa3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBFA3_005bbfa3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBFA3_005bbfa3.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BBFB0_005bbfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BBFB0_005bbfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BBFB0_005bbfb0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC020_005bc020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC020_005bc020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC020_005bc020.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC080_005bc080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC080_005bc080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC080_005bc080.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC0A0_005bc0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC0A0_005bc0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC0A0_005bc0a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC0E0_005bc0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC0E0_005bc0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC0E0_005bc0e0.md
