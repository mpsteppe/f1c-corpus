# SKELETON FILL — Worker G chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F2E0_0058f2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F2E0_0058f2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F2E0_0058f2e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F360_0058f360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F360_0058f360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F360_0058f360.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F3D0_0058f3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F3D0_0058f3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F3D0_0058f3d0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F550_0058f550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F550_0058f550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F550_0058f550.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F5C0_0058f5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F5C0_0058f5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F5C0_0058f5c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F5F0_0058f5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F5F0_0058f5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F5F0_0058f5f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F6D0_0058f6d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F6D0_0058f6d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F6D0_0058f6d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F6F0_0058f6f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F6F0_0058f6f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F6F0_0058f6f0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F7D0_0058f7d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F7D0_0058f7d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F7D0_0058f7d0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F810_0058f810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F810_0058f810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F810_0058f810.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F8A0_0058f8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F8A0_0058f8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F8A0_0058f8a0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F8C0_0058f8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F8C0_0058f8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F8C0_0058f8c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F930_0058f930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F930_0058f930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F930_0058f930.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58F940_0058f940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58F940_0058f940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58F940_0058f940.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FA10_0058fa10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FA10_0058fa10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FA10_0058fa10.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FB60_0058fb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FB60_0058fb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FB60_0058fb60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FBF0_0058fbf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FBF0_0058fbf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FBF0_0058fbf0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FC40_0058fc40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FC40_0058fc40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FC40_0058fc40.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FC70_0058fc70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FC70_0058fc70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FC70_0058fc70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FD30_0058fd30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FD30_0058fd30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FD30_0058fd30.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FDA0_0058fda0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FDA0_0058fda0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FDA0_0058fda0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FEA0_0058fea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FEA0_0058fea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FEA0_0058fea0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FED0_0058fed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FED0_0058fed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FED0_0058fed0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_58FF00_0058ff00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_58FF00_0058ff00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_58FF00_0058ff00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_590050_00590050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_590050_00590050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_590050_00590050.md
