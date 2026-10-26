# SKELETON FILL — Worker PD chunk 4/4 (f1c-ida-skeleton-pro), 20 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407BF0_00407bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407BF0_00407bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407BF0_00407bf0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_421CA0_00421ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_421CA0_00421ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_421CA0_00421ca0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_425DE0_00425de0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_425DE0_00425de0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_425DE0_00425de0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4276F0_004276f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4276F0_004276f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4276F0_004276f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CFB0_0042cfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CFB0_0042cfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CFB0_0042cfb0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_455BD0_00455bd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_455BD0_00455bd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_455BD0_00455bd0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46E230_0046e230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46E230_0046e230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46E230_0046e230.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A08E0_004a08e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A08E0_004a08e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A08E0_004a08e0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC840_004ac840.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC840_004ac840.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC840_004ac840.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4C2790_004c2790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4C2790_004c2790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4C2790_004c2790.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4DC0C0_004dc0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4DC0C0_004dc0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4DC0C0_004dc0c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4E1E60_004e1e60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4E1E60_004e1e60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4E1E60_004e1e60.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EA920_004ea920.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EA920_004ea920.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EA920_004ea920.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F8D80_004f8d80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F8D80_004f8d80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F8D80_004f8d80.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_501040_00501040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_501040_00501040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_501040_00501040.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_51F1A0_0051f1a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_51F1A0_0051f1a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_51F1A0_0051f1a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529080_00529080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529080_00529080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529080_00529080.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54824C_0054824c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54824C_0054824c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54824C_0054824c.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A06B0_005a06b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A06B0_005a06b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A06B0_005a06b0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5A7A90_005a7a90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5A7A90_005a7a90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5A7A90_005a7a90.md
