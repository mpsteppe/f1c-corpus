# SKELETON FILL — Worker H chunk 9/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC130_005bc130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC130_005bc130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC130_005bc130.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC560_005bc560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC560_005bc560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC560_005bc560.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC5B0_005bc5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC5B0_005bc5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC5B0_005bc5b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC5D0_005bc5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC5D0_005bc5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC5D0_005bc5d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC630_005bc630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC630_005bc630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC630_005bc630.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC8F0_005bc8f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC8F0_005bc8f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC8F0_005bc8f0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC930_005bc930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC930_005bc930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC930_005bc930.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BC9A0_005bc9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BC9A0_005bc9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BC9A0_005bc9a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCA10_005bca10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCA10_005bca10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCA10_005bca10.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCBF4_005bcbf4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCBF4_005bcbf4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCBF4_005bcbf4.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCC00_005bcc00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCC00_005bcc00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCC00_005bcc00.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCF30_005bcf30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCF30_005bcf30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCF30_005bcf30.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BCFC0_005bcfc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BCFC0_005bcfc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BCFC0_005bcfc0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD0D0_005bd0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD0D0_005bd0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD0D0_005bd0d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD140_005bd140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD140_005bd140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD140_005bd140.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD1D0_005bd1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD1D0_005bd1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD1D0_005bd1d0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD3E8_005bd3e8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD3E8_005bd3e8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD3E8_005bd3e8.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD4F0_005bd4f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD4F0_005bd4f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD4F0_005bd4f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD600_005bd600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD600_005bd600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD600_005bd600.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD790_005bd790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD790_005bd790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD790_005bd790.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD820_005bd820.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD820_005bd820.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD820_005bd820.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD908_005bd908.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD908_005bd908.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD908_005bd908.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD910_005bd910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD910_005bd910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD910_005bd910.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD940_005bd940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD940_005bd940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD940_005bd940.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BD9A0_005bd9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BD9A0_005bd9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BD9A0_005bd9a0.md
