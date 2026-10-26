# SKELETON FILL — Worker PC chunk 2/3 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D6A80_004d6a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D6A80_004d6a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D6A80_004d6a80.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE5C0_004ee5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE5C0_004ee5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE5C0_004ee5c0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51CDC0_0051cdc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51CDC0_0051cdc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51CDC0_0051cdc0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52CAF0_0052caf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52CAF0_0052caf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52CAF0_0052caf0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_570EA0_00570ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_570EA0_00570ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_570EA0_00570ea0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43DFB0_0043dfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43DFB0_0043dfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43DFB0_0043dfb0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455D30_00455d30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455D30_00455d30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455D30_00455d30.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46A110_0046a110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46A110_0046a110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46A110_0046a110.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488580_00488580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488580_00488580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488580_00488580.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8870_004a8870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8870_004a8870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8870_004a8870.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B9C10_004b9c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B9C10_004b9c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B9C10_004b9c10.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D52D0_004d52d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D52D0_004d52d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D52D0_004d52d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_50BFD0_0050bfd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_50BFD0_0050bfd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_50BFD0_0050bfd0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F750_0051f750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F750_0051f750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F750_0051f750.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_59E210_0059e210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_59E210_0059e210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_59E210_0059e210.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\start_005c144e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\start_005c144e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\start_005c144e.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40AA00_0040aa00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40AA00_0040aa00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40AA00_0040aa00.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41FB90_0041fb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41FB90_0041fb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41FB90_0041fb90.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_430ED0_00430ed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_430ED0_00430ed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_430ED0_00430ed0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_447520_00447520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_447520_00447520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_447520_00447520.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_460630_00460630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_460630_00460630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_460630_00460630.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C930_0046c930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C930_0046c930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C930_0046c930.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB7B0_004ab7b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB7B0_004ab7b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB7B0_004ab7b0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C0CA0_004c0ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C0CA0_004c0ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C0CA0_004c0ca0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CB810_004cb810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CB810_004cb810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CB810_004cb810.md
