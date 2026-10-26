# SKELETON FILL — Worker C chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DFB0_0046dfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DFB0_0046dfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DFB0_0046dfb0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DFC0_0046dfc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DFC0_0046dfc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DFC0_0046dfc0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E080_0046e080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E080_0046e080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E080_0046e080.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E1C0_0046e1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E1C0_0046e1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E1C0_0046e1c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E1E0_0046e1e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E1E0_0046e1e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E1E0_0046e1e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E230_0046e230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E230_0046e230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E230_0046e230.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E5A0_0046e5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E5A0_0046e5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E5A0_0046e5a0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E780_0046e780.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E780_0046e780.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E780_0046e780.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E7C0_0046e7c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E7C0_0046e7c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E7C0_0046e7c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E820_0046e820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E820_0046e820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E820_0046e820.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E8A0_0046e8a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E8A0_0046e8a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E8A0_0046e8a0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46EFD0_0046efd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46EFD0_0046efd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46EFD0_0046efd0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F020_0046f020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F020_0046f020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F020_0046f020.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F0E0_0046f0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F0E0_0046f0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F0E0_0046f0e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F670_0046f670.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F670_0046f670.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F670_0046f670.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_do_always_noconv_codecvt_base_std__MBE_NXZ_0046f6a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_do_always_noconv_codecvt_base_std__MBE_NXZ_0046f6a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_do_always_noconv_codecvt_base_std__MBE_NXZ_0046f6a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F6C0_0046f6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F6C0_0046f6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F6C0_0046f6c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F730_0046f730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F730_0046f730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F730_0046f730.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F750_0046f750.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F750_0046f750.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F750_0046f750.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FA10_0046fa10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FA10_0046fa10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FA10_0046fa10.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FAE0_0046fae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FAE0_0046fae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FAE0_0046fae0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FB20_0046fb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FB20_0046fb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FB20_0046fb20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FB30_0046fb30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FB30_0046fb30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FB30_0046fb30.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FB40_0046fb40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FB40_0046fb40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FB40_0046fb40.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46FB70_0046fb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46FB70_0046fb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46FB70_0046fb70.md
