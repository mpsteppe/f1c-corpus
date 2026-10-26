# SKELETON FILL — Worker A chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57C010_0057c010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57C010_0057c010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57C010_0057c010.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58D780_0058d780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58D780_0058d780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58D780_0058d780.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5924D0_005924d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5924D0_005924d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5924D0_005924d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5932C0_005932c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5932C0_005932c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5932C0_005932c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599350_00599350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599350_00599350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599350_00599350.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5993C0_005993c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5993C0_005993c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5993C0_005993c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599420_00599420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599420_00599420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599420_00599420.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_599480_00599480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_599480_00599480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_599480_00599480.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59D750_0059d750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59D750_0059d750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59D750_0059d750.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59DBA0_0059dba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59DBA0_0059dba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59DBA0_0059dba0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59ED70_0059ed70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59ED70_0059ed70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59ED70_0059ed70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59F160_0059f160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59F160_0059f160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59F160_0059f160.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A0FE0_005a0fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A0FE0_005a0fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A0FE0_005a0fe0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A29F0_005a29f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A29F0_005a29f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A29F0_005a29f0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A3FF0_005a3ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A3FF0_005a3ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A3FF0_005a3ff0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A93C0_005a93c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A93C0_005a93c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A93C0_005a93c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A96B0_005a96b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A96B0_005a96b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A96B0_005a96b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC740_005ac740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC740_005ac740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC740_005ac740.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACEB0_005aceb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACEB0_005aceb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACEB0_005aceb0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADC80_005adc80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADC80_005adc80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADC80_005adc80.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B1850_005b1850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B1850_005b1850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B1850_005b1850.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B3E20_005b3e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B3E20_005b3e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B3E20_005b3e20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B4600_005b4600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B4600_005b4600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B4600_005b4600.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B47F0_005b47f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B47F0_005b47f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B47F0_005b47f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5B8C10_005b8c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5B8C10_005b8c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5B8C10_005b8c10.md
