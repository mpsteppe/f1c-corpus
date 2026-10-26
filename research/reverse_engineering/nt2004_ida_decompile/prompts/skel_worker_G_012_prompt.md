# SKELETON FILL — Worker G chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E130_0058e130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E130_0058e130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E130_0058e130.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E1B0_0058e1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E1B0_0058e1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E1B0_0058e1b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E2B0_0058e2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E2B0_0058e2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E2B0_0058e2b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E3A0_0058e3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E3A0_0058e3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E3A0_0058e3a0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E4F0_0058e4f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E4F0_0058e4f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E4F0_0058e4f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E546_0058e546.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E546_0058e546.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E546_0058e546.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E570_0058e570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E570_0058e570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E570_0058e570.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E820_0058e820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E820_0058e820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E820_0058e820.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E930_0058e930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E930_0058e930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E930_0058e930.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58E970_0058e970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58E970_0058e970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58E970_0058e970.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EAB0_0058eab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EAB0_0058eab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EAB0_0058eab0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EB90_0058eb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EB90_0058eb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EB90_0058eb90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58ED00_0058ed00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58ED00_0058ed00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58ED00_0058ed00.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58ED70_0058ed70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58ED70_0058ed70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58ED70_0058ed70.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EDA0_0058eda0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EDA0_0058eda0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EDA0_0058eda0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EEE0_0058eee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EEE0_0058eee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EEE0_0058eee0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EF50_0058ef50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EF50_0058ef50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EF50_0058ef50.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58EF90_0058ef90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58EF90_0058ef90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58EF90_0058ef90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F020_0058f020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F020_0058f020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F020_0058f020.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F050_0058f050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F050_0058f050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F050_0058f050.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F0C0_0058f0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F0C0_0058f0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F0C0_0058f0c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F100_0058f100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F100_0058f100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F100_0058f100.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F150_0058f150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F150_0058f150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F150_0058f150.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F1D0_0058f1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F1D0_0058f1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F1D0_0058f1d0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F270_0058f270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F270_0058f270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F270_0058f270.md
