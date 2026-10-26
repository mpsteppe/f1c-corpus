# SKELETON FILL — Worker A chunk 12/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_506540_00506540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_506540_00506540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_506540_00506540.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5065C0_005065c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5065C0_005065c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5065C0_005065c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5099D0_005099d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5099D0_005099d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5099D0_005099d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50AF50_0050af50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50AF50_0050af50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50AF50_0050af50.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50F940_0050f940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50F940_0050f940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50F940_0050f940.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_511320_00511320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_511320_00511320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_511320_00511320.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_518510_00518510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_518510_00518510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_518510_00518510.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51BE20_0051be20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51BE20_0051be20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51BE20_0051be20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E4D0_0051e4d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E4D0_0051e4d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E4D0_0051e4d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5276C0_005276c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5276C0_005276c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5276C0_005276c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52DF70_0052df70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52DF70_0052df70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52DF70_0052df70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536120_00536120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536120_00536120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536120_00536120.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_539A10_00539a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_539A10_00539a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_539A10_00539a10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53FD37_0053fd37.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53FD37_0053fd37.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53FD37_0053fd37.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_542E09_00542e09.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_542E09_00542e09.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_542E09_00542e09.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5475CB_005475cb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5475CB_005475cb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5475CB_005475cb.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555A38_00555a38.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555A38_00555a38.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555A38_00555a38.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_555DA6_00555da6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_555DA6_00555da6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_555DA6_00555da6.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_55F151_0055f151.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_55F151_0055f151.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_55F151_0055f151.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5741A0_005741a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5741A0_005741a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5741A0_005741a0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_578220_00578220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_578220_00578220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_578220_00578220.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A0A0_0057a0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A0A0_0057a0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A0A0_0057a0a0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57A110_0057a110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57A110_0057a110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57A110_0057a110.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57ACC0_0057acc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57ACC0_0057acc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57ACC0_0057acc0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_57B040_0057b040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_57B040_0057b040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_57B040_0057b040.md
