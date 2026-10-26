# SKELETON FILL — Worker H chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD9E0_005bd9e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD9E0_005bd9e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD9E0_005bd9e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDA10_005bda10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDA10_005bda10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDA10_005bda10.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDA20_005bda20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDA20_005bda20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDA20_005bda20.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDA60_005bda60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDA60_005bda60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDA60_005bda60.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDAA0_005bdaa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDAA0_005bdaa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDAA0_005bdaa0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDDD0_005bddd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDDD0_005bddd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDDD0_005bddd0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDE70_005bde70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDE70_005bde70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDE70_005bde70.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDE90_005bde90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDE90_005bde90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDE90_005bde90.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDEB0_005bdeb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDEB0_005bdeb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDEB0_005bdeb0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDED0_005bded0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDED0_005bded0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDED0_005bded0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDF40_005bdf40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDF40_005bdf40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDF40_005bdf40.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BDFF0_005bdff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BDFF0_005bdff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BDFF0_005bdff0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE020_005be020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE020_005be020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE020_005be020.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE070_005be070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE070_005be070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE070_005be070.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE0C0_005be0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE0C0_005be0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE0C0_005be0c0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE190_005be190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE190_005be190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE190_005be190.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE1C0_005be1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE1C0_005be1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE1C0_005be1c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE2D0_005be2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE2D0_005be2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE2D0_005be2d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE2F0_005be2f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE2F0_005be2f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE2F0_005be2f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE320_005be320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE320_005be320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE320_005be320.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE4C0_005be4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE4C0_005be4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE4C0_005be4c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE500_005be500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE500_005be500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE500_005be500.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE5C0_005be5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE5C0_005be5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE5C0_005be5c0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE660_005be660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE660_005be660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE660_005be660.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE770_005be770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE770_005be770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE770_005be770.md
