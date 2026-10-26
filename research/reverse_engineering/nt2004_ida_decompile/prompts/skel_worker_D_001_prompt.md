# SKELETON FILL — Worker D chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490A60_00490a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490A60_00490a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490A60_00490a60.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490B5A_00490b5a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490B5A_00490b5a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490B5A_00490b5a.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490DC0_00490dc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490DC0_00490dc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490DC0_00490dc0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490DD0_00490dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490DD0_00490dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490DD0_00490dd0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490E40_00490e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490E40_00490e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490E40_00490e40.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4915D0_004915d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4915D0_004915d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4915D0_004915d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_491888_00491888.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_491888_00491888.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_491888_00491888.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_491FE0_00491fe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_491FE0_00491fe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_491FE0_00491fe0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_492AA0_00492aa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_492AA0_00492aa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_492AA0_00492aa0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_492B30_00492b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_492B30_00492b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_492B30_00492b30.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_492CF0_00492cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_492CF0_00492cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_492CF0_00492cf0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493360_00493360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493360_00493360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493360_00493360.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493410_00493410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493410_00493410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493410_00493410.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493590_00493590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493590_00493590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493590_00493590.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493600_00493600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493600_00493600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493600_00493600.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493680_00493680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493680_00493680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493680_00493680.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493A60_00493a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493A60_00493a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493A60_00493a60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493B10_00493b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493B10_00493b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493B10_00493b10.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_493B20_00493b20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_493B20_00493b20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_493B20_00493b20.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_95_00493be0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_95_00493be0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_95_00493be0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49526B_0049526b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49526B_0049526b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49526B_0049526b.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_495298_00495298.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_495298_00495298.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_495298_00495298.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4952C5_004952c5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4952C5_004952c5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4952C5_004952c5.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4952F2_004952f2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4952F2_004952f2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4952F2_004952f2.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49539B_0049539b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49539B_0049539b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49539B_0049539b.md
