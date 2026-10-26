# SKELETON FILL — Worker G chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593D20_00593d20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593D20_00593d20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593D20_00593d20.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593D90_00593d90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593D90_00593d90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593D90_00593d90.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593DA0_00593da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593DA0_00593da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593DA0_00593da0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593EA0_00593ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593EA0_00593ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593EA0_00593ea0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593F10_00593f10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593F10_00593f10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593F10_00593f10.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593F30_00593f30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593F30_00593f30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593F30_00593f30.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_593F70_00593f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_593F70_00593f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_593F70_00593f70.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5943E0_005943e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5943E0_005943e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5943E0_005943e0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5944C0_005944c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5944C0_005944c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5944C0_005944c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_594600_00594600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_594600_00594600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_594600_00594600.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_145_00594625.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_145_00594625.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_145_00594625.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5946C0_005946c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5946C0_005946c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5946C0_005946c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5953E0_005953e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5953E0_005953e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5953E0_005953e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5954E0_005954e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5954E0_005954e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5954E0_005954e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595540_00595540.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595540_00595540.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595540_00595540.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5955B0_005955b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5955B0_005955b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5955B0_005955b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595A10_00595a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595A10_00595a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595A10_00595a10.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595A30_00595a30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595A30_00595a30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595A30_00595a30.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595A80_00595a80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595A80_00595a80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595A80_00595a80.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595AC0_00595ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595AC0_00595ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595AC0_00595ac0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595B30_00595b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595B30_00595b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595B30_00595b30.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595B70_00595b70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595B70_00595b70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595B70_00595b70.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595C00_00595c00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595C00_00595c00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595C00_00595c00.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595C40_00595c40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595C40_00595c40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595C40_00595c40.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_595C70_00595c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_595C70_00595c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_595C70_00595c70.md
