# SKELETON FILL — Worker F chunk 21/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53FA25_0053fa25.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53FA25_0053fa25.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53FA25_0053fa25.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53FA2E_0053fa2e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53FA2E_0053fa2e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53FA2E_0053fa2e.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_541446_00541446.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_541446_00541446.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_541446_00541446.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_541537_00541537.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_541537_00541537.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_541537_00541537.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_541739_00541739.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_541739_00541739.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_541739_00541739.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_541D60_00541d60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_541D60_00541d60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_541D60_00541d60.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5421F2_005421f2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5421F2_005421f2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5421F2_005421f2.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5422F2_005422f2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5422F2_005422f2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5422F2_005422f2.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5426D8_005426d8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5426D8_005426d8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5426D8_005426d8.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5431AB_005431ab.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5431AB_005431ab.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5431AB_005431ab.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54335A_0054335a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54335A_0054335a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54335A_0054335a.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_543772_00543772.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_543772_00543772.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_543772_00543772.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_543AD2_00543ad2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_543AD2_00543ad2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_543AD2_00543ad2.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_124_00543ae5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_124_00543ae5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_124_00543ae5.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_543DDF_00543ddf.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_543DDF_00543ddf.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_543DDF_00543ddf.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5444E8_005444e8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5444E8_005444e8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5444E8_005444e8.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_544504_00544504.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_544504_00544504.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_544504_00544504.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5474EB_005474eb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5474EB_005474eb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5474EB_005474eb.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5476C3_005476c3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5476C3_005476c3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5476C3_005476c3.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5478CB_005478cb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5478CB_005478cb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5478CB_005478cb.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5478E7_005478e7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5478E7_005478e7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5478E7_005478e7.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547903_00547903.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547903_00547903.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547903_00547903.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547BF0_00547bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547BF0_00547bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547BF0_00547bf0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547C0C_00547c0c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547C0C_00547c0c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547C0C_00547c0c.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547C28_00547c28.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547C28_00547c28.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547C28_00547c28.md
