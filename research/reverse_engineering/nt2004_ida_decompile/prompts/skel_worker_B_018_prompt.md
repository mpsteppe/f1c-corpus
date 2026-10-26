# SKELETON FILL — Worker B chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A5D0_0045a5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A5D0_0045a5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A5D0_0045a5d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A5E0_0045a5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A5E0_0045a5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A5E0_0045a5e0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45A66A_0045a66a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45A66A_0045a66a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45A66A_0045a66a.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45AA70_0045aa70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45AA70_0045aa70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45AA70_0045aa70.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45AAE0_0045aae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45AAE0_0045aae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45AAE0_0045aae0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45AB60_0045ab60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45AB60_0045ab60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45AB60_0045ab60.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C060_0045c060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C060_0045c060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C060_0045c060.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C1B0_0045c1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C1B0_0045c1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C1B0_0045c1b0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_29_0045c560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_29_0045c560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_29_0045c560.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_78_0045c5b3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_78_0045c5b3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_78_0045c5b3.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C5C0_0045c5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C5C0_0045c5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C5C0_0045c5c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C680_0045c680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C680_0045c680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C680_0045c680.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C6C0_0045c6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C6C0_0045c6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C6C0_0045c6c0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C7A0_0045c7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C7A0_0045c7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C7A0_0045c7a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45C830_0045c830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45C830_0045c830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45C830_0045c830.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CB10_0045cb10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CB10_0045cb10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CB10_0045cb10.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CE00_0045ce00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CE00_0045ce00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CE00_0045ce00.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CE40_0045ce40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CE40_0045ce40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CE40_0045ce40.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CF08_0045cf08.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CF08_0045cf08.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CF08_0045cf08.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CF30_0045cf30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CF30_0045cf30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CF30_0045cf30.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CF90_0045cf90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CF90_0045cf90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CF90_0045cf90.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CFC0_0045cfc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CFC0_0045cfc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CFC0_0045cfc0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45CFF0_0045cff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45CFF0_0045cff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45CFF0_0045cff0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D270_0045d270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D270_0045d270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D270_0045d270.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D290_0045d290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D290_0045d290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D290_0045d290.md
