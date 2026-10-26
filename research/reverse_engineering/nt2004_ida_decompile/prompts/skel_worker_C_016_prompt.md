# SKELETON FILL — Worker C chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487260_00487260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487260_00487260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487260_00487260.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4872D0_004872d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4872D0_004872d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4872D0_004872d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487360_00487360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487360_00487360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487360_00487360.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4873E0_004873e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4873E0_004873e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4873E0_004873e0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487430_00487430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487430_00487430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487430_00487430.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487470_00487470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487470_00487470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487470_00487470.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487500_00487500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487500_00487500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487500_00487500.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487590_00487590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487590_00487590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487590_00487590.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487620_00487620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487620_00487620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487620_00487620.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4876C0_004876c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4876C0_004876c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4876C0_004876c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487730_00487730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487730_00487730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487730_00487730.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4877B0_004877b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4877B0_004877b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4877B0_004877b0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487840_00487840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487840_00487840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487840_00487840.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487890_00487890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487890_00487890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487890_00487890.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487940_00487940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487940_00487940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487940_00487940.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487990_00487990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487990_00487990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487990_00487990.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487A20_00487a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487A20_00487a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487A20_00487a20.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487D20_00487d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487D20_00487d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487D20_00487d20.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487D90_00487d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487D90_00487d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487D90_00487d90.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487E20_00487e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487E20_00487e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487E20_00487e20.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487E50_00487e50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487E50_00487e50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487E50_00487e50.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487EC0_00487ec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487EC0_00487ec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487EC0_00487ec0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487F10_00487f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487F10_00487f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487F10_00487f10.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_487F80_00487f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_487F80_00487f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_487F80_00487f80.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_488008_00488008.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_488008_00488008.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_488008_00488008.md
