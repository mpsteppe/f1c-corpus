# SKELETON FILL — Worker D chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC120_004ac120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC120_004ac120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC120_004ac120.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC170_004ac170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC170_004ac170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC170_004ac170.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC270_004ac270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC270_004ac270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC270_004ac270.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC2D0_004ac2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC2D0_004ac2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC2D0_004ac2d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC330_004ac330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC330_004ac330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC330_004ac330.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC360_004ac360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC360_004ac360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC360_004ac360.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC400_004ac400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC400_004ac400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC400_004ac400.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC660_004ac660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC660_004ac660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC660_004ac660.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC840_004ac840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC840_004ac840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC840_004ac840.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC980_004ac980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC980_004ac980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC980_004ac980.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ACA70_004aca70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ACA70_004aca70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ACA70_004aca70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ACB20_004acb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ACB20_004acb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ACB20_004acb20.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD000_004ad000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD000_004ad000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD000_004ad000.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD050_004ad050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD050_004ad050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD050_004ad050.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD1D0_004ad1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD1D0_004ad1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD1D0_004ad1d0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD360_004ad360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD360_004ad360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD360_004ad360.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD380_004ad380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD380_004ad380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD380_004ad380.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD420_004ad420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD420_004ad420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD420_004ad420.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD760_004ad760.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD760_004ad760.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD760_004ad760.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD7F0_004ad7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD7F0_004ad7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD7F0_004ad7f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD820_004ad820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD820_004ad820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD820_004ad820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD840_004ad840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD840_004ad840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD840_004ad840.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD850_004ad850.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD850_004ad850.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD850_004ad850.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_102_004ad88c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_102_004ad88c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_102_004ad88c.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD890_004ad890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD890_004ad890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD890_004ad890.md
