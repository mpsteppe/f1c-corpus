# SKELETON FILL — Worker F chunk 5/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F83B0_004f83b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F83B0_004f83b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F83B0_004f83b0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F83E0_004f83e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F83E0_004f83e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F83E0_004f83e0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8410_004f8410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8410_004f8410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8410_004f8410.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8460_004f8460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8460_004f8460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8460_004f8460.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F84C0_004f84c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F84C0_004f84c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F84C0_004f84c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F87B0_004f87b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F87B0_004f87b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F87B0_004f87b0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8900_004f8900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8900_004f8900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8900_004f8900.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8A50_004f8a50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8A50_004f8a50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8A50_004f8a50.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8B20_004f8b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8B20_004f8b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8B20_004f8b20.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8D7C_004f8d7c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8D7C_004f8d7c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8D7C_004f8d7c.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8D80_004f8d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8D80_004f8d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8D80_004f8d80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8EF0_004f8ef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8EF0_004f8ef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8EF0_004f8ef0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8F10_004f8f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8F10_004f8f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8F10_004f8f10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8F50_004f8f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8F50_004f8f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8F50_004f8f50.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8F90_004f8f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8F90_004f8f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8F90_004f8f90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F9040_004f9040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F9040_004f9040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F9040_004f9040.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F9200_004f9200.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F9200_004f9200.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F9200_004f9200.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F93E0_004f93e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F93E0_004f93e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F93E0_004f93e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F95D0_004f95d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F95D0_004f95d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F95D0_004f95d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F9670_004f9670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F9670_004f9670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F9670_004f9670.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F99C0_004f99c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F99C0_004f99c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F99C0_004f99c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F9D90_004f9d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F9D90_004f9d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F9D90_004f9d90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F9F50_004f9f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F9F50_004f9f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F9F50_004f9f50.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA0D0_004fa0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA0D0_004fa0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA0D0_004fa0d0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FA1A0_004fa1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FA1A0_004fa1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FA1A0_004fa1a0.md
