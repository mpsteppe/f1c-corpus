# SKELETON FILL — Worker G chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5791A0_005791a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5791A0_005791a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5791A0_005791a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579200_00579200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579200_00579200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579200_00579200.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579430_00579430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579430_00579430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579430_00579430.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5794F0_005794f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5794F0_005794f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5794F0_005794f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5795E0_005795e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5795E0_005795e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5795E0_005795e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579930_00579930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579930_00579930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579930_00579930.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579B50_00579b50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579B50_00579b50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579B50_00579b50.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579C10_00579c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579C10_00579c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579C10_00579c10.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579CD0_00579cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579CD0_00579cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579CD0_00579cd0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_579D90_00579d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_579D90_00579d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_579D90_00579d90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A650_0057a650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A650_0057a650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A650_0057a650.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A690_0057a690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A690_0057a690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A690_0057a690.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A6C0_0057a6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A6C0_0057a6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A6C0_0057a6c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A6D0_0057a6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A6D0_0057a6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A6D0_0057a6d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A700_0057a700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A700_0057a700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A700_0057a700.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A760_0057a760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A760_0057a760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A760_0057a760.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A7A0_0057a7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A7A0_0057a7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A7A0_0057a7a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A800_0057a800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A800_0057a800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A800_0057a800.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A810_0057a810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A810_0057a810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A810_0057a810.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A8C0_0057a8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A8C0_0057a8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A8C0_0057a8c0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A9D0_0057a9d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A9D0_0057a9d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A9D0_0057a9d0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57AE50_0057ae50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57AE50_0057ae50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57AE50_0057ae50.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57AF60_0057af60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57AF60_0057af60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57AF60_0057af60.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57B170_0057b170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57B170_0057b170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57B170_0057b170.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57B340_0057b340.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57B340_0057b340.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57B340_0057b340.md
