# SKELETON FILL — Worker E chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0AD0_004c0ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0AD0_004c0ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0AD0_004c0ad0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0B10_004c0b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0B10_004c0b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0B10_004c0b10.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0B60_004c0b60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0B60_004c0b60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0B60_004c0b60.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0BA0_004c0ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0BA0_004c0ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0BA0_004c0ba0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0BF0_004c0bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0BF0_004c0bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0BF0_004c0bf0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0C10_004c0c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0C10_004c0c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0C10_004c0c10.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0C40_004c0c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0C40_004c0c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0C40_004c0c40.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0C67_004c0c67.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0C67_004c0c67.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0C67_004c0c67.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0C70_004c0c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0C70_004c0c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0C70_004c0c70.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1710_004c1710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1710_004c1710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1710_004c1710.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1750_004c1750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1750_004c1750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1750_004c1750.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1790_004c1790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1790_004c1790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1790_004c1790.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1830_004c1830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1830_004c1830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1830_004c1830.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1900_004c1900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1900_004c1900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1900_004c1900.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1920_004c1920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1920_004c1920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1920_004c1920.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1940_004c1940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1940_004c1940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1940_004c1940.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1960_004c1960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1960_004c1960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1960_004c1960.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1970_004c1970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1970_004c1970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1970_004c1970.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C19D0_004c19d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C19D0_004c19d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C19D0_004c19d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1BA0_004c1ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1BA0_004c1ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1BA0_004c1ba0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C1CB0_004c1cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C1CB0_004c1cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C1CB0_004c1cb0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2000_004c2000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2000_004c2000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2000_004c2000.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2790_004c2790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2790_004c2790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2790_004c2790.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2BB0_004c2bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2BB0_004c2bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2BB0_004c2bb0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2C10_004c2c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2C10_004c2c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2C10_004c2c10.md
