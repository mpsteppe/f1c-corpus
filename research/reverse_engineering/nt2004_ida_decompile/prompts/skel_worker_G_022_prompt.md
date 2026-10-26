# SKELETON FILL — Worker G chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A47F0_005a47f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A47F0_005a47f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A47F0_005a47f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4830_005a4830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4830_005a4830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4830_005a4830.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A4A50_005a4a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A4A50_005a4a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A4A50_005a4a50.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A59C0_005a59c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A59C0_005a59c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A59C0_005a59c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A6150_005a6150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A6150_005a6150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A6150_005a6150.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A62C0_005a62c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A62C0_005a62c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A62C0_005a62c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A6610_005a6610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A6610_005a6610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A6610_005a6610.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A6C20_005a6c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A6C20_005a6c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A6C20_005a6c20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A6DF0_005a6df0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A6DF0_005a6df0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A6DF0_005a6df0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A6F80_005a6f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A6F80_005a6f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A6F80_005a6f80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A71D0_005a71d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A71D0_005a71d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A71D0_005a71d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A72D0_005a72d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A72D0_005a72d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A72D0_005a72d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7610_005a7610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7610_005a7610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7610_005a7610.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A78B0_005a78b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A78B0_005a78b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A78B0_005a78b0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7A40_005a7a40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7A40_005a7a40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7A40_005a7a40.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7A90_005a7a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7A90_005a7a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7A90_005a7a90.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7DD0_005a7dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7DD0_005a7dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7DD0_005a7dd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7F10_005a7f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7F10_005a7f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7F10_005a7f10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8020_005a8020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8020_005a8020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8020_005a8020.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A80E0_005a80e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A80E0_005a80e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A80E0_005a80e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8250_005a8250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8250_005a8250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8250_005a8250.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8470_005a8470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8470_005a8470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8470_005a8470.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A8480_005a8480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A8480_005a8480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A8480_005a8480.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A84A9_005a84a9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A84A9_005a84a9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A84A9_005a84a9.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A84B0_005a84b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A84B0_005a84b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A84B0_005a84b0.md
