# SKELETON FILL — Worker PB chunk 1/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42FAB0_0042fab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42FAB0_0042fab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42FAB0_0042fab0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B260_0046b260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B260_0046b260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B260_0046b260.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_433740_00433740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_433740_00433740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_433740_00433740.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0190_004c0190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0190_004c0190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0190_004c0190.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53EF14_0053ef14.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53EF14_0053ef14.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53EF14_0053ef14.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4329D0_004329d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4329D0_004329d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4329D0_004329d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465E80_00465e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465E80_00465e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465E80_00465e80.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8E80_004a8e80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8E80_004a8e80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8E80_004a8e80.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BDDB0_004bddb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BDDB0_004bddb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BDDB0_004bddb0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DA5E0_004da5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DA5E0_004da5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DA5E0_004da5e0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FD8A0_004fd8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FD8A0_004fd8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FD8A0_004fd8a0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52A110_0052a110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52A110_0052a110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52A110_0052a110.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B7620_005b7620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B7620_005b7620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B7620_005b7620.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40BEE0_0040bee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40BEE0_0040bee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40BEE0_0040bee0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_445700_00445700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_445700_00445700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_445700_00445700.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_471DA0_00471da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_471DA0_00471da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_471DA0_00471da0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CE0F0_004ce0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CE0F0_004ce0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CE0F0_004ce0f0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB6C0_004eb6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB6C0_004eb6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB6C0_004eb6c0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50E6D0_0050e6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50E6D0_0050e6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50E6D0_0050e6d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_527B50_00527b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_527B50_00527b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_527B50_00527b50.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_550831_00550831.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_550831_00550831.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_550831_00550831.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B2B20_005b2b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B2B20_005b2b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B2B20_005b2b20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42E180_0042e180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42E180_0042e180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42E180_0042e180.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_442AF0_00442af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_442AF0_00442af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_442AF0_00442af0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48AB00_0048ab00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48AB00_0048ab00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48AB00_0048ab00.md
