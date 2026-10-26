# SKELETON FILL — Worker F chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51DD00_0051dd00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51DD00_0051dd00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51DD00_0051dd00.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51DEC0_0051dec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51DEC0_0051dec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51DEC0_0051dec0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E0F0_0051e0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E0F0_0051e0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E0F0_0051e0f0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E210_0051e210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E210_0051e210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E210_0051e210.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E230_0051e230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E230_0051e230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E230_0051e230.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E380_0051e380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E380_0051e380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E380_0051e380.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E3B0_0051e3b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E3B0_0051e3b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E3B0_0051e3b0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E440_0051e440.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E440_0051e440.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E440_0051e440.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E470_0051e470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E470_0051e470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E470_0051e470.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E4A0_0051e4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E4A0_0051e4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E4A0_0051e4a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E6B0_0051e6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E6B0_0051e6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E6B0_0051e6b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E730_0051e730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E730_0051e730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E730_0051e730.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E770_0051e770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E770_0051e770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E770_0051e770.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E7C0_0051e7c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E7C0_0051e7c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E7C0_0051e7c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51E820_0051e820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51E820_0051e820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51E820_0051e820.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F0F0_0051f0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F0F0_0051f0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F0F0_0051f0f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F160_0051f160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F160_0051f160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F160_0051f160.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F1A0_0051f1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F1A0_0051f1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F1A0_0051f1a0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F3D0_0051f3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F3D0_0051f3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F3D0_0051f3d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F580_0051f580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F580_0051f580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F580_0051f580.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F5B0_0051f5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F5B0_0051f5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F5B0_0051f5b0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_98_0051f5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_98_0051f5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_98_0051f5c0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F5E0_0051f5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F5E0_0051f5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F5E0_0051f5e0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51FE70_0051fe70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51FE70_0051fe70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51FE70_0051fe70.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_520000_00520000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_520000_00520000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_520000_00520000.md
