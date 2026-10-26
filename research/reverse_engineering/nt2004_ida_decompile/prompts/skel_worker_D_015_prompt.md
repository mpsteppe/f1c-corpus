# SKELETON FILL — Worker D chunk 15/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AD970_004ad970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AD970_004ad970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AD970_004ad970.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADAF0_004adaf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADAF0_004adaf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADAF0_004adaf0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADBB0_004adbb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADBB0_004adbb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADBB0_004adbb0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADC00_004adc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADC00_004adc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADC00_004adc00.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADC50_004adc50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADC50_004adc50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADC50_004adc50.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_103_004adda6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_103_004adda6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_103_004adda6.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADDB0_004addb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADDB0_004addb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADDB0_004addb0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADDF0_004addf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADDF0_004addf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADDF0_004addf0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADEF0_004adef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADEF0_004adef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADEF0_004adef0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ADFB0_004adfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ADFB0_004adfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ADFB0_004adfb0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE080_004ae080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE080_004ae080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE080_004ae080.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE150_004ae150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE150_004ae150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE150_004ae150.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE230_004ae230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE230_004ae230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE230_004ae230.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE2C0_004ae2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE2C0_004ae2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE2C0_004ae2c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE330_004ae330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE330_004ae330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE330_004ae330.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE350_004ae350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE350_004ae350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE350_004ae350.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE370_004ae370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE370_004ae370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE370_004ae370.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE4C0_004ae4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE4C0_004ae4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE4C0_004ae4c0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE540_004ae540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE540_004ae540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE540_004ae540.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE67C_004ae67c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE67C_004ae67c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE67C_004ae67c.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE680_004ae680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE680_004ae680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE680_004ae680.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE700_004ae700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE700_004ae700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE700_004ae700.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE720_004ae720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE720_004ae720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE720_004ae720.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE730_004ae730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE730_004ae730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE730_004ae730.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE7A0_004ae7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE7A0_004ae7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE7A0_004ae7a0.md
