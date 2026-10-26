# SKELETON FILL — Worker E chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DAEA2_004daea2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DAEA2_004daea2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DAEA2_004daea2.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DAFA0_004dafa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DAFA0_004dafa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DAFA0_004dafa0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB03C_004db03c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB03C_004db03c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB03C_004db03c.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB260_004db260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB260_004db260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB260_004db260.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB6E0_004db6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB6E0_004db6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB6E0_004db6e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB763_004db763.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB763_004db763.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB763_004db763.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB880_004db880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB880_004db880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB880_004db880.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DB980_004db980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DB980_004db980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DB980_004db980.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DBF10_004dbf10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DBF10_004dbf10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DBF10_004dbf10.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DBF80_004dbf80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DBF80_004dbf80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DBF80_004dbf80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC0B0_004dc0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC0B0_004dc0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC0B0_004dc0b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC0C0_004dc0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC0C0_004dc0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC0C0_004dc0c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC260_004dc260.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC260_004dc260.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC260_004dc260.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC2C0_004dc2c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC2C0_004dc2c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC2C0_004dc2c0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC390_004dc390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC390_004dc390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC390_004dc390.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC3F0_004dc3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC3F0_004dc3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC3F0_004dc3f0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC460_004dc460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC460_004dc460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC460_004dc460.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC580_004dc580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC580_004dc580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC580_004dc580.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC900_004dc900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC900_004dc900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC900_004dc900.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC9C0_004dc9c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC9C0_004dc9c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC9C0_004dc9c0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCA20_004dca20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCA20_004dca20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCA20_004dca20.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCA60_004dca60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCA60_004dca60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCA60_004dca60.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCA90_004dca90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCA90_004dca90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCA90_004dca90.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCC00_004dcc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCC00_004dcc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCC00_004dcc00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DCCA0_004dcca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DCCA0_004dcca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DCCA0_004dcca0.md
