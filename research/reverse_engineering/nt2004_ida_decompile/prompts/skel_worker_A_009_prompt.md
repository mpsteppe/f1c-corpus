# SKELETON FILL — Worker A chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464350_00464350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464350_00464350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464350_00464350.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_464830_00464830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_464830_00464830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_464830_00464830.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_465920_00465920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_465920_00465920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_465920_00465920.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\DialogFunc_00466b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\DialogFunc_00466b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\DialogFunc_00466b30.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_467CE0_00467ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_467CE0_00467ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_467CE0_00467ce0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468960_00468960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468960_00468960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468960_00468960.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_476A50_00476a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_476A50_00476a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_476A50_00476a50.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47B6C0_0047b6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47B6C0_0047b6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47B6C0_0047b6c0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C920_0047c920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C920_0047c920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C920_0047c920.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47ED80_0047ed80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47ED80_0047ed80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47ED80_0047ed80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480D90_00480d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480D90_00480d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480D90_00480d90.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48CAD0_0048cad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48CAD0_0048cad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48CAD0_0048cad0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48DDC0_0048ddc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48DDC0_0048ddc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48DDC0_0048ddc0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48F970_0048f970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48F970_0048f970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48F970_0048f970.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4929D0_004929d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4929D0_004929d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4929D0_004929d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C8A0_0049c8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C8A0_0049c8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C8A0_0049c8a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D5B0_0049d5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D5B0_0049d5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D5B0_0049d5b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D770_0049d770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D770_0049d770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D770_0049d770.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D7F0_0049d7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D7F0_0049d7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D7F0_0049d7f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DBB0_0049dbb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DBB0_0049dbb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DBB0_0049dbb0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E100_0049e100.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E100_0049e100.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E100_0049e100.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49ED00_0049ed00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49ED00_0049ed00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49ED00_0049ed00.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F730_0049f730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F730_0049f730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F730_0049f730.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A3240_004a3240.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A3240_004a3240.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A3240_004a3240.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A6F20_004a6f20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A6F20_004a6f20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A6F20_004a6f20.md
