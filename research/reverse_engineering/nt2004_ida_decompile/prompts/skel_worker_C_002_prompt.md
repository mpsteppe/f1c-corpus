# SKELETON FILL — Worker C chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468400_00468400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468400_00468400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468400_00468400.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4687D0_004687d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4687D0_004687d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4687D0_004687d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468880_00468880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468880_00468880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468880_00468880.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_468AD0_00468ad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_468AD0_00468ad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_468AD0_00468ad0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_36_00469360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_36_00469360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_36_00469360.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_469380_00469380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_469380_00469380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_469380_00469380.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_469EB0_00469eb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_469EB0_00469eb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_469EB0_00469eb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46AED0_0046aed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46AED0_0046aed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46AED0_0046aed0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B003_0046b003.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B003_0046b003.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B003_0046b003.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B010_0046b010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B010_0046b010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B010_0046b010.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B130_0046b130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B130_0046b130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B130_0046b130.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B200_0046b200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B200_0046b200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B200_0046b200.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B230_0046b230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B230_0046b230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B230_0046b230.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B930_0046b930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B930_0046b930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B930_0046b930.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46B970_0046b970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46B970_0046b970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46B970_0046b970.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46BA40_0046ba40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46BA40_0046ba40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46BA40_0046ba40.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46BB60_0046bb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46BB60_0046bb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46BB60_0046bb60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46BD20_0046bd20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46BD20_0046bd20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46BD20_0046bd20.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C080_0046c080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C080_0046c080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C080_0046c080.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C170_0046c170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C170_0046c170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C170_0046c170.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C1D0_0046c1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C1D0_0046c1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C1D0_0046c1d0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C260_0046c260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C260_0046c260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C260_0046c260.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C2E0_0046c2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C2E0_0046c2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C2E0_0046c2e0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\StartAddress_0046c3b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\StartAddress_0046c3b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\StartAddress_0046c3b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C5C0_0046c5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C5C0_0046c5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C5C0_0046c5c0.md
