# SKELETON FILL — Worker D chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5400_004b5400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5400_004b5400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5400_004b5400.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5740_004b5740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5740_004b5740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5740_004b5740.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B59D0_004b59d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B59D0_004b59d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B59D0_004b59d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5AF0_004b5af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5AF0_004b5af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5AF0_004b5af0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5B40_004b5b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5B40_004b5b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5B40_004b5b40.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5D70_004b5d70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5D70_004b5d70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5D70_004b5d70.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5EF0_004b5ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5EF0_004b5ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5EF0_004b5ef0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B5F30_004b5f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B5F30_004b5f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B5F30_004b5f30.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B61C0_004b61c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B61C0_004b61c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B61C0_004b61c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6200_004b6200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6200_004b6200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6200_004b6200.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6220_004b6220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6220_004b6220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6220_004b6220.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6250_004b6250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6250_004b6250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6250_004b6250.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6450_004b6450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6450_004b6450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6450_004b6450.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6470_004b6470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6470_004b6470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6470_004b6470.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6DA0_004b6da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6DA0_004b6da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6DA0_004b6da0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B6FD0_004b6fd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B6FD0_004b6fd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B6FD0_004b6fd0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B70F0_004b70f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B70F0_004b70f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B70F0_004b70f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B74B0_004b74b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B74B0_004b74b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B74B0_004b74b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7880_004b7880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7880_004b7880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7880_004b7880.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B78E0_004b78e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B78E0_004b78e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B78E0_004b78e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7AB0_004b7ab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7AB0_004b7ab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7AB0_004b7ab0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7C00_004b7c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7C00_004b7c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7C00_004b7c00.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B7E60_004b7e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B7E60_004b7e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B7E60_004b7e60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8070_004b8070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8070_004b8070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8070_004b8070.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B8090_004b8090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B8090_004b8090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B8090_004b8090.md
