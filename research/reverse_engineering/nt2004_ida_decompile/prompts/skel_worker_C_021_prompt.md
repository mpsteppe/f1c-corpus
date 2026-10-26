# SKELETON FILL — Worker C chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C550_0048c550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C550_0048c550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C550_0048c550.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48CACA_0048caca.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48CACA_0048caca.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48CACA_0048caca.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48CCF0_0048ccf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48CCF0_0048ccf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48CCF0_0048ccf0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D130_0048d130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D130_0048d130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D130_0048d130.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D280_0048d280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D280_0048d280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D280_0048d280.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D3C0_0048d3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D3C0_0048d3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D3C0_0048d3c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D3E0_0048d3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D3E0_0048d3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D3E0_0048d3e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D440_0048d440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D440_0048d440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D440_0048d440.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D5B0_0048d5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D5B0_0048d5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D5B0_0048d5b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D5D0_0048d5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D5D0_0048d5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D5D0_0048d5d0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D5E0_0048d5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D5E0_0048d5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D5E0_0048d5e0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D730_0048d730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D730_0048d730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D730_0048d730.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D750_0048d750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D750_0048d750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D750_0048d750.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D760_0048d760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D760_0048d760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D760_0048d760.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D780_0048d780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D780_0048d780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D780_0048d780.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D78A_0048d78a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D78A_0048d78a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D78A_0048d78a.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D790_0048d790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D790_0048d790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D790_0048d790.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D7B0_0048d7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D7B0_0048d7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D7B0_0048d7b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D7C0_0048d7c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D7C0_0048d7c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D7C0_0048d7c0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D7E0_0048d7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D7E0_0048d7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D7E0_0048d7e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D7EA_0048d7ea.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D7EA_0048d7ea.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D7EA_0048d7ea.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D7F0_0048d7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D7F0_0048d7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D7F0_0048d7f0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D810_0048d810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D810_0048d810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D810_0048d810.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48D9F0_0048d9f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48D9F0_0048d9f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48D9F0_0048d9f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DA10_0048da10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DA10_0048da10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DA10_0048da10.md
