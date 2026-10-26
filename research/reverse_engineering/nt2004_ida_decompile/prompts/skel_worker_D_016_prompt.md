# SKELETON FILL — Worker D chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE870_004ae870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE870_004ae870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE870_004ae870.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE890_004ae890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE890_004ae890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE890_004ae890.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE8B0_004ae8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE8B0_004ae8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE8B0_004ae8b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE8D0_004ae8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE8D0_004ae8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE8D0_004ae8d0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE8F0_004ae8f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE8F0_004ae8f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE8F0_004ae8f0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE900_004ae900.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE900_004ae900.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE900_004ae900.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE978_004ae978.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE978_004ae978.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE978_004ae978.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AE980_004ae980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AE980_004ae980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AE980_004ae980.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEE60_004aee60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEE60_004aee60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEE60_004aee60.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEE80_004aee80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEE80_004aee80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEE80_004aee80.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEED0_004aeed0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEED0_004aeed0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEED0_004aeed0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEF30_004aef30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEF30_004aef30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEF30_004aef30.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEF80_004aef80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEF80_004aef80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEF80_004aef80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEFA0_004aefa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEFA0_004aefa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEFA0_004aefa0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF000_004af000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF000_004af000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF000_004af000.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF090_004af090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF090_004af090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF090_004af090.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF0A0_004af0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF0A0_004af0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF0A0_004af0a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF0B0_004af0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF0B0_004af0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF0B0_004af0b0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF110_004af110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF110_004af110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF110_004af110.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF120_004af120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF120_004af120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF120_004af120.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF12C_004af12c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF12C_004af12c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF12C_004af12c.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF130_004af130.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF130_004af130.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF130_004af130.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF160_004af160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF160_004af160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF160_004af160.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF1A0_004af1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF1A0_004af1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF1A0_004af1a0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AF230_004af230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AF230_004af230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AF230_004af230.md
