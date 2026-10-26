# SKELETON FILL — Worker F chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_519C90_00519c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_519C90_00519c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_519C90_00519c90.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51A720_0051a720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51A720_0051a720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51A720_0051a720.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51A820_0051a820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51A820_0051a820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51A820_0051a820.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51B7F0_0051b7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51B7F0_0051b7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51B7F0_0051b7f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51B960_0051b960.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51B960_0051b960.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51B960_0051b960.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BB70_0051bb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BB70_0051bb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BB70_0051bb70.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BBE0_0051bbe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BBE0_0051bbe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BBE0_0051bbe0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BCE0_0051bce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BCE0_0051bce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BCE0_0051bce0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BD20_0051bd20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BD20_0051bd20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BD20_0051bd20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BF90_0051bf90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BF90_0051bf90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BF90_0051bf90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BFD0_0051bfd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BFD0_0051bfd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BFD0_0051bfd0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C0E0_0051c0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C0E0_0051c0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C0E0_0051c0e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C180_0051c180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C180_0051c180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C180_0051c180.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C1A0_0051c1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C1A0_0051c1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C1A0_0051c1a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C630_0051c630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C630_0051c630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C630_0051c630.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C730_0051c730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C730_0051c730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C730_0051c730.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C7A0_0051c7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C7A0_0051c7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C7A0_0051c7a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51C900_0051c900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51C900_0051c900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51C900_0051c900.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51CA30_0051ca30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51CA30_0051ca30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51CA30_0051ca30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51CC60_0051cc60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51CC60_0051cc60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51CC60_0051cc60.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51CCB0_0051ccb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51CCB0_0051ccb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51CCB0_0051ccb0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51D650_0051d650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51D650_0051d650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51D650_0051d650.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51D720_0051d720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51D720_0051d720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51D720_0051d720.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51D8D0_0051d8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51D8D0_0051d8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51D8D0_0051d8d0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51DAE0_0051dae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51DAE0_0051dae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51DAE0_0051dae0.md
