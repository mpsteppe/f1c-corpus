# SKELETON FILL — Worker D chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49582D_0049582d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49582D_0049582d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49582D_0049582d.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49585A_0049585a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49585A_0049585a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49585A_0049585a.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495887_00495887.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495887_00495887.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495887_00495887.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4958B4_004958b4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4958B4_004958b4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4958B4_004958b4.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4958E1_004958e1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4958E1_004958e1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4958E1_004958e1.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495978_00495978.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495978_00495978.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495978_00495978.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495B3C_00495b3c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495B3C_00495b3c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495B3C_00495b3c.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495BFB_00495bfb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495BFB_00495bfb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495BFB_00495bfb.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49717D_0049717d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49717D_0049717d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49717D_0049717d.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_96_0049a50c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_96_0049a50c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_96_0049a50c.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49A511_0049a511.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49A511_0049a511.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49A511_0049a511.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_99_0049aa44.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_99_0049aa44.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_99_0049aa44.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_100_0049acf4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_100_0049acf4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_100_0049acf4.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_16_0049afa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_16_0049afa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_16_0049afa0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49AFB0_0049afb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49AFB0_0049afb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49AFB0_0049afb0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B030_0049b030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B030_0049b030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B030_0049b030.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_5_0049b040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_5_0049b040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_5_0049b040.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B050_0049b050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B050_0049b050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B050_0049b050.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B060_0049b060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B060_0049b060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B060_0049b060.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B220_0049b220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B220_0049b220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B220_0049b220.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B310_0049b310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B310_0049b310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B310_0049b310.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B350_0049b350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B350_0049b350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B350_0049b350.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B400_0049b400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B400_0049b400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B400_0049b400.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B420_0049b420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B420_0049b420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B420_0049b420.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49B440_0049b440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49B440_0049b440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49B440_0049b440.md
