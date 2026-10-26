# SKELETON FILL — Worker E chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBFC0_004bbfc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBFC0_004bbfc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBFC0_004bbfc0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC030_004bc030.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC030_004bc030.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC030_004bc030.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC060_004bc060.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC060_004bc060.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC060_004bc060.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC080_004bc080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC080_004bc080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC080_004bc080.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_108_004bc0c8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_108_004bc0c8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_108_004bc0c8.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC0D0_004bc0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC0D0_004bc0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC0D0_004bc0d0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC280_004bc280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC280_004bc280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC280_004bc280.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC450_004bc450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC450_004bc450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC450_004bc450.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC4C0_004bc4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC4C0_004bc4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC4C0_004bc4c0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC570_004bc570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC570_004bc570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC570_004bc570.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC5F0_004bc5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC5F0_004bc5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC5F0_004bc5f0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_58_004bc6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_58_004bc6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_58_004bc6c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC6E0_004bc6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC6E0_004bc6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC6E0_004bc6e0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BC8D0_004bc8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BC8D0_004bc8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BC8D0_004bc8d0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BCDE0_004bcde0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BCDE0_004bcde0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BCDE0_004bcde0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BCED0_004bced0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BCED0_004bced0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BCED0_004bced0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BD140_004bd140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BD140_004bd140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BD140_004bd140.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BD160_004bd160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BD160_004bd160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BD160_004bd160.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BD290_004bd290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BD290_004bd290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BD290_004bd290.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BE0B0_004be0b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BE0B0_004be0b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BE0B0_004be0b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BE1C0_004be1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BE1C0_004be1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BE1C0_004be1c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BE390_004be390.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BE390_004be390.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BE390_004be390.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BE6A0_004be6a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BE6A0_004be6a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BE6A0_004be6a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BE8C0_004be8c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BE8C0_004be8c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BE8C0_004be8c0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BEB30_004beb30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BEB30_004beb30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BEB30_004beb30.md
