# SKELETON FILL — Worker A chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC910_004bc910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC910_004bc910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC910_004bc910.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458620_00458620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458620_00458620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458620_00458620.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_410150_00410150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_410150_00410150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_410150_00410150.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_436470_00436470.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_436470_00436470.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_436470_00436470.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_44E2B0_0044e2b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_44E2B0_0044e2b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_44E2B0_0044e2b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458590_00458590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458590_00458590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458590_00458590.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4625E0_004625e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4625E0_004625e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4625E0_004625e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_462770_00462770.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_462770_00462770.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_462770_00462770.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC7A0_004bc7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC7A0_004bc7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC7A0_004bc7a0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D2790_004d2790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D2790_004d2790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D2790_004d2790.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E8260_004e8260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E8260_004e8260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E8260_004e8260.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56D580_0056d580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56D580_0056d580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56D580_0056d580.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_402940_00402940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_402940_00402940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_402940_00402940.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_41D0F0_0041d0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_41D0F0_0041d0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_41D0F0_0041d0f0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42E3A0_0042e3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42E3A0_0042e3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42E3A0_0042e3a0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_436C00_00436c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_436C00_00436c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_436C00_00436c00.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43DA60_0043da60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43DA60_0043da60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43DA60_0043da60.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_458380_00458380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_458380_00458380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_458380_00458380.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_45D570_0045d570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_45D570_0045d570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_45D570_0045d570.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4895E0_004895e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4895E0_004895e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4895E0_004895e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B750_0048b750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B750_0048b750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B750_0048b750.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B75A0_004b75a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B75A0_004b75a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B75A0_004b75a0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6000_004e6000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6000_004e6000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6000_004e6000.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E6E00_004e6e00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E6E00_004e6e00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E6E00_004e6e00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E8880_004e8880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E8880_004e8880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E8880_004e8880.md
