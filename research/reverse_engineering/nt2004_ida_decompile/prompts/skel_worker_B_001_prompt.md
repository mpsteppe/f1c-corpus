# SKELETON FILL — Worker B chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4186E0_004186e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4186E0_004186e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4186E0_004186e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_9_00418710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_9_00418710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_9_00418710.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418720_00418720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418720_00418720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418720_00418720.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418840_00418840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418840_00418840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418840_00418840.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4188C0_004188c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4188C0_004188c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4188C0_004188c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4189D0_004189d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4189D0_004189d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4189D0_004189d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418A30_00418a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418A30_00418a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418A30_00418a30.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_10_00418ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_10_00418ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_10_00418ae0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418AF0_00418af0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418AF0_00418af0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418AF0_00418af0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418B00_00418b00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418B00_00418b00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418B00_00418b00.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418C02_00418c02.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418C02_00418c02.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418C02_00418c02.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418CA0_00418ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418CA0_00418ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418CA0_00418ca0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418D00_00418d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418D00_00418d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418D00_00418d00.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418DB0_00418db0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418DB0_00418db0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418DB0_00418db0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_418F50_00418f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_418F50_00418f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_418F50_00418f50.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419110_00419110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419110_00419110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419110_00419110.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419130_00419130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419130_00419130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419130_00419130.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419160_00419160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419160_00419160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419160_00419160.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419190_00419190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419190_00419190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419190_00419190.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4191D0_004191d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4191D0_004191d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4191D0_004191d0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419200_00419200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419200_00419200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419200_00419200.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4192A0_004192a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4192A0_004192a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4192A0_004192a0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419330_00419330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419330_00419330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419330_00419330.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4193B0_004193b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4193B0_004193b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4193B0_004193b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_419450_00419450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_419450_00419450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_419450_00419450.md
