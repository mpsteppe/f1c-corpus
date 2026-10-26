# SKELETON FILL — Worker C chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BE40_0047be40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BE40_0047be40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BE40_0047be40.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BE50_0047be50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BE50_0047be50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BE50_0047be50.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BED0_0047bed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BED0_0047bed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BED0_0047bed0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BF20_0047bf20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BF20_0047bf20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BF20_0047bf20.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BF60_0047bf60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BF60_0047bf60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BF60_0047bf60.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BF70_0047bf70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BF70_0047bf70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BF70_0047bf70.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BFB0_0047bfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BFB0_0047bfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BFB0_0047bfb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47BFC0_0047bfc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47BFC0_0047bfc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47BFC0_0047bfc0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C030_0047c030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C030_0047c030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C030_0047c030.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C080_0047c080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C080_0047c080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C080_0047c080.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C0C0_0047c0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C0C0_0047c0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C0C0_0047c0c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C0D0_0047c0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C0D0_0047c0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C0D0_0047c0d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C180_0047c180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C180_0047c180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C180_0047c180.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C540_0047c540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C540_0047c540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C540_0047c540.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C890_0047c890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C890_0047c890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C890_0047c890.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C8B0_0047c8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C8B0_0047c8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C8B0_0047c8b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47C900_0047c900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47C900_0047c900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47C900_0047c900.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47CD44_0047cd44.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47CD44_0047cd44.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47CD44_0047cd44.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E060_0047e060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E060_0047e060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E060_0047e060.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E070_0047e070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E070_0047e070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E070_0047e070.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E080_0047e080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E080_0047e080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E080_0047e080.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_39_0047e160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_39_0047e160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_39_0047e160.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E170_0047e170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E170_0047e170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E170_0047e170.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E1C0_0047e1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E1C0_0047e1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E1C0_0047e1c0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47E7B0_0047e7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47E7B0_0047e7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47E7B0_0047e7b0.md
