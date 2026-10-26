# SKELETON FILL — Worker E chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECA40_004eca40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECA40_004eca40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECA40_004eca40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECC60_004ecc60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECC60_004ecc60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECC60_004ecc60.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECE00_004ece00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECE00_004ece00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECE00_004ece00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECE50_004ece50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECE50_004ece50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECE50_004ece50.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECEA0_004ecea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECEA0_004ecea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECEA0_004ecea0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED270_004ed270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED270_004ed270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED270_004ed270.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED350_004ed350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED350_004ed350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED350_004ed350.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED430_004ed430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED430_004ed430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED430_004ed430.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED560_004ed560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED560_004ed560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED560_004ed560.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED570_004ed570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED570_004ed570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED570_004ed570.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED590_004ed590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED590_004ed590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED590_004ed590.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED5B0_004ed5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED5B0_004ed5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED5B0_004ed5b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED5C0_004ed5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED5C0_004ed5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED5C0_004ed5c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED5E0_004ed5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED5E0_004ed5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED5E0_004ed5e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED5F0_004ed5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED5F0_004ed5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED5F0_004ed5f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED610_004ed610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED610_004ed610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED610_004ed610.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED620_004ed620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED620_004ed620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED620_004ed620.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED640_004ed640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED640_004ed640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED640_004ed640.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED650_004ed650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED650_004ed650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED650_004ed650.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED670_004ed670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED670_004ed670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED670_004ed670.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED680_004ed680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED680_004ed680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED680_004ed680.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED6A0_004ed6a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED6A0_004ed6a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED6A0_004ed6a0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED6B0_004ed6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED6B0_004ed6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED6B0_004ed6b0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED710_004ed710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED710_004ed710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED710_004ed710.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ED740_004ed740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ED740_004ed740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ED740_004ed740.md
