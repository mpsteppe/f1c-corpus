# SKELETON FILL — Worker F chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5470_004f5470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5470_004f5470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5470_004f5470.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F55C0_004f55c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F55C0_004f55c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F55C0_004f55c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5680_004f5680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5680_004f5680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5680_004f5680.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5C10_004f5c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5C10_004f5c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5C10_004f5c10.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5E80_004f5e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5E80_004f5e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5E80_004f5e80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F5EE0_004f5ee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F5EE0_004f5ee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F5EE0_004f5ee0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F6430_004f6430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F6430_004f6430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F6430_004f6430.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F78B0_004f78b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F78B0_004f78b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F78B0_004f78b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7C30_004f7c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7C30_004f7c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7C30_004f7c30.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_88_004f7c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_88_004f7c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_88_004f7c40.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7C60_004f7c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7C60_004f7c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7C60_004f7c60.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7CC0_004f7cc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7CC0_004f7cc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7CC0_004f7cc0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7CF0_004f7cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7CF0_004f7cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7CF0_004f7cf0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7D10_004f7d10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7D10_004f7d10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7D10_004f7d10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7D30_004f7d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7D30_004f7d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7D30_004f7d30.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7DC0_004f7dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7DC0_004f7dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7DC0_004f7dc0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7DF0_004f7df0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7DF0_004f7df0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7DF0_004f7df0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7E67_004f7e67.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7E67_004f7e67.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7E67_004f7e67.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7E70_004f7e70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7E70_004f7e70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7E70_004f7e70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7ED0_004f7ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7ED0_004f7ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7ED0_004f7ed0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F7F20_004f7f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F7F20_004f7f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F7F20_004f7f20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F80D0_004f80d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F80D0_004f80d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F80D0_004f80d0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F81A0_004f81a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F81A0_004f81a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F81A0_004f81a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8240_004f8240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8240_004f8240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8240_004f8240.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_119_004f83a3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_119_004f83a3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_119_004f83a3.md
