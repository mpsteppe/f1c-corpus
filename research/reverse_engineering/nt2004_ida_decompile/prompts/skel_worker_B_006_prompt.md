# SKELETON FILL — Worker B chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427C20_00427c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427C20_00427c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427C20_00427c20.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427CB0_00427cb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427CB0_00427cb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427CB0_00427cb0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427F50_00427f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427F50_00427f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427F50_00427f50.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427F60_00427f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427F60_00427f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427F60_00427f60.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427F90_00427f90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427F90_00427f90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427F90_00427f90.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_21_00427fb6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_21_00427fb6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_21_00427fb6.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427FC0_00427fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427FC0_00427fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427FC0_00427fc0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427FE4_00427fe4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427FE4_00427fe4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427FE4_00427fe4.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_427FF0_00427ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_427FF0_00427ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_427FF0_00427ff0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428020_00428020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428020_00428020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428020_00428020.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428040_00428040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428040_00428040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428040_00428040.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428070_00428070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428070_00428070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428070_00428070.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428090_00428090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428090_00428090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428090_00428090.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4280C0_004280c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4280C0_004280c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4280C0_004280c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_428150_00428150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_428150_00428150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_428150_00428150.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4298D0_004298d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4298D0_004298d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4298D0_004298d0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42A130_0042a130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42A130_0042a130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42A130_0042a130.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42B090_0042b090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42B090_0042b090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42B090_0042b090.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42B320_0042b320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42B320_0042b320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42B320_0042b320.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42B430_0042b430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42B430_0042b430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42B430_0042b430.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42B5C0_0042b5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42B5C0_0042b5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42B5C0_0042b5c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42BD90_0042bd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42BD90_0042bd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42BD90_0042bd90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C000_0042c000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C000_0042c000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C000_0042c000.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C0B0_0042c0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C0B0_0042c0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C0B0_0042c0b0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C0D0_0042c0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C0D0_0042c0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C0D0_0042c0d0.md
