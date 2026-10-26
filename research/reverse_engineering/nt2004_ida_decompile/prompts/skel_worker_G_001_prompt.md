# SKELETON FILL — Worker G chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5485B5_005485b5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5485B5_005485b5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5485B5_005485b5.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5485D1_005485d1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5485D1_005485d1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5485D1_005485d1.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5485D6_005485d6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5485D6_005485d6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5485D6_005485d6.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5485EE_005485ee.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5485EE_005485ee.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5485EE_005485ee.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548606_00548606.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548606_00548606.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548606_00548606.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54861E_0054861e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54861E_0054861e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54861E_0054861e.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548636_00548636.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548636_00548636.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548636_00548636.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54867F_0054867f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54867F_0054867f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54867F_0054867f.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548697_00548697.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548697_00548697.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548697_00548697.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5486AF_005486af.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5486AF_005486af.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5486AF_005486af.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548E27_00548e27.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548E27_00548e27.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548E27_00548e27.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548E43_00548e43.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548E43_00548e43.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548E43_00548e43.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54A82D_0054a82d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54A82D_0054a82d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54A82D_0054a82d.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54ADD0_0054add0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54ADD0_0054add0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54ADD0_0054add0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54AF13_0054af13.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54AF13_0054af13.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54AF13_0054af13.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54BBD8_0054bbd8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54BBD8_0054bbd8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54BBD8_0054bbd8.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54C44A_0054c44a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54C44A_0054c44a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54C44A_0054c44a.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54C59B_0054c59b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54C59B_0054c59b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54C59B_0054c59b.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54CCC2_0054ccc2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54CCC2_0054ccc2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54CCC2_0054ccc2.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E5FE_0054e5fe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E5FE_0054e5fe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E5FE_0054e5fe.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E7FC_0054e7fc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E7FC_0054e7fc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E7FC_0054e7fc.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E82F_0054e82f.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E82F_0054e82f.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E82F_0054e82f.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E854_0054e854.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E854_0054e854.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E854_0054e854.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54EAEF_0054eaef.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54EAEF_0054eaef.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54EAEF_0054eaef.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_550415_00550415.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_550415_00550415.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_550415_00550415.md
