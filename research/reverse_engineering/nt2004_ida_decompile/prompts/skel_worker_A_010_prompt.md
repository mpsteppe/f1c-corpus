# SKELETON FILL — Worker A chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A73B0_004a73b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A73B0_004a73b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A73B0_004a73b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8640_004a8640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8640_004a8640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8640_004a8640.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A9DB0_004a9db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A9DB0_004a9db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A9DB0_004a9db0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA390_004aa390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA390_004aa390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA390_004aa390.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB450_004ab450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB450_004ab450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB450_004ab450.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC390_004ac390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC390_004ac390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC390_004ac390.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE3F0_004ae3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE3F0_004ae3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE3F0_004ae3f0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B06B0_004b06b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B06B0_004b06b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B06B0_004b06b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B07E0_004b07e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B07E0_004b07e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B07E0_004b07e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5F70_004b5f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5F70_004b5f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5F70_004b5f70.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B60A0_004b60a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B60A0_004b60a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B60A0_004b60a0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6560_004b6560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6560_004b6560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6560_004b6560.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7A40_004b7a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7A40_004b7a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7A40_004b7a40.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7BC0_004b7bc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7BC0_004b7bc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7BC0_004b7bc0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA1A0_004ba1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA1A0_004ba1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA1A0_004ba1a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA430_004ba430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA430_004ba430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA430_004ba430.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEA40_004bea40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEA40_004bea40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEA40_004bea40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEB60_004beb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEB60_004beb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEB60_004beb60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BECA0_004beca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BECA0_004beca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BECA0_004beca0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1CF0_004c1cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1CF0_004c1cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1CF0_004c1cf0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CDED0_004cded0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CDED0_004cded0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CDED0_004cded0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CEA30_004cea30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CEA30_004cea30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CEA30_004cea30.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D3AB0_004d3ab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D3AB0_004d3ab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D3AB0_004d3ab0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4340_004d4340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4340_004d4340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4340_004d4340.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D4C00_004d4c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D4C00_004d4c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D4C00_004d4c00.md
