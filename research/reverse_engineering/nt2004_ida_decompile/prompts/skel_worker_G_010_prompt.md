# SKELETON FILL — Worker G chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57BBF0_0057bbf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57BBF0_0057bbf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57BBF0_0057bbf0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57EB70_0057eb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57EB70_0057eb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57EB70_0057eb70.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57F060_0057f060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57F060_0057f060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57F060_0057f060.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57F2D0_0057f2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57F2D0_0057f2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57F2D0_0057f2d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_580060_00580060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_580060_00580060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_580060_00580060.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5801A0_005801a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5801A0_005801a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5801A0_005801a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_581700_00581700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_581700_00581700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_581700_00581700.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CD00_0058cd00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CD00_0058cd00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CD00_0058cd00.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CD0F_0058cd0f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CD0F_0058cd0f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CD0F_0058cd0f.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CDB0_0058cdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CDB0_0058cdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CDB0_0058cdb0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CDC0_0058cdc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CDC0_0058cdc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CDC0_0058cdc0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CE20_0058ce20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CE20_0058ce20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CE20_0058ce20.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CE60_0058ce60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CE60_0058ce60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CE60_0058ce60.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CF10_0058cf10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CF10_0058cf10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CF10_0058cf10.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58CF90_0058cf90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58CF90_0058cf90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58CF90_0058cf90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D010_0058d010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D010_0058d010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D010_0058d010.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D060_0058d060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D060_0058d060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D060_0058d060.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D0E0_0058d0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D0E0_0058d0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D0E0_0058d0e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D1C0_0058d1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D1C0_0058d1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D1C0_0058d1c0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D230_0058d230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D230_0058d230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D230_0058d230.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__mkgmtime_0058d320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__mkgmtime_0058d320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__mkgmtime_0058d320.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D340_0058d340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D340_0058d340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D340_0058d340.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D360_0058d360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D360_0058d360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D360_0058d360.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D410_0058d410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D410_0058d410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D410_0058d410.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D490_0058d490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D490_0058d490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D490_0058d490.md
