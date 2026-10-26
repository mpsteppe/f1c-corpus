# SKELETON FILL — Worker G chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56F810_0056f810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56F810_0056f810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56F810_0056f810.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56FA59_0056fa59.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56FA59_0056fa59.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56FA59_0056fa59.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5718F0_005718f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5718F0_005718f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5718F0_005718f0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_571B40_00571b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_571B40_00571b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_571B40_00571b40.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_571C30_00571c30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_571C30_00571c30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_571C30_00571c30.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_571E90_00571e90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_571E90_00571e90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_571E90_00571e90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_571EF0_00571ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_571EF0_00571ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_571EF0_00571ef0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572120_00572120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572120_00572120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572120_00572120.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5721B0_005721b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5721B0_005721b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5721B0_005721b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5723B0_005723b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5723B0_005723b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5723B0_005723b0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572710_00572710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572710_00572710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572710_00572710.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5729A0_005729a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5729A0_005729a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5729A0_005729a0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572AA0_00572aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572AA0_00572aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572AA0_00572aa0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572B90_00572b90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572B90_00572b90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572B90_00572b90.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572DB0_00572db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572DB0_00572db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572DB0_00572db0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_129_00572f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_129_00572f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_129_00572f20.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_572FC0_00572fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_572FC0_00572fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_572FC0_00572fc0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5730B0_005730b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5730B0_005730b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5730B0_005730b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573330_00573330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573330_00573330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573330_00573330.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5733B0_005733b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5733B0_005733b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5733B0_005733b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573430_00573430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573430_00573430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573430_00573430.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573570_00573570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573570_00573570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573570_00573570.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_573660_00573660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_573660_00573660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_573660_00573660.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5736C0_005736c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5736C0_005736c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5736C0_005736c0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5736D0_005736d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5736D0_005736d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5736D0_005736d0.md
