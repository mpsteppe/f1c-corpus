# SKELETON FILL — Worker D chunk 8/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F690_0049f690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F690_0049f690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F690_0049f690.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F6B0_0049f6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F6B0_0049f6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F6B0_0049f6b0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F6F0_0049f6f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F6F0_0049f6f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F6F0_0049f6f0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49F8D0_0049f8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49F8D0_0049f8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49F8D0_0049f8d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FB50_0049fb50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FB50_0049fb50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FB50_0049fb50.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FB80_0049fb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FB80_0049fb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FB80_0049fb80.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FC20_0049fc20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FC20_0049fc20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FC20_0049fc20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FC60_0049fc60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FC60_0049fc60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FC60_0049fc60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FCC0_0049fcc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FCC0_0049fcc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FCC0_0049fcc0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FDB0_0049fdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FDB0_0049fdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FDB0_0049fdb0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FE70_0049fe70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FE70_0049fe70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FE70_0049fe70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FEC0_0049fec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FEC0_0049fec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FEC0_0049fec0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49FF10_0049ff10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49FF10_0049ff10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49FF10_0049ff10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0090_004a0090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0090_004a0090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0090_004a0090.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A00E0_004a00e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A00E0_004a00e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A00E0_004a00e0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0140_004a0140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0140_004a0140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0140_004a0140.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A04EA_004a04ea.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A04EA_004a04ea.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A04EA_004a04ea.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0640_004a0640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0640_004a0640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0640_004a0640.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A08E0_004a08e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A08E0_004a08e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A08E0_004a08e0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0C90_004a0c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0C90_004a0c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0C90_004a0c90.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A0CF0_004a0cf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A0CF0_004a0cf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A0CF0_004a0cf0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1040_004a1040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1040_004a1040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1040_004a1040.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1050_004a1050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1050_004a1050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1050_004a1050.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A105A_004a105a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A105A_004a105a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A105A_004a105a.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A1270_004a1270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A1270_004a1270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A1270_004a1270.md
