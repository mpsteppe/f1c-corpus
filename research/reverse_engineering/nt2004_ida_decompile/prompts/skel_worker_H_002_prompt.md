# SKELETON FILL — Worker H chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB0A0_005ab0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB0A0_005ab0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB0A0_005ab0a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB160_005ab160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB160_005ab160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB160_005ab160.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB250_005ab250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB250_005ab250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB250_005ab250.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB360_005ab360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB360_005ab360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB360_005ab360.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB3A0_005ab3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB3A0_005ab3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB3A0_005ab3a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC040_005ac040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC040_005ac040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC040_005ac040.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC380_005ac380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC380_005ac380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC380_005ac380.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC5A0_005ac5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC5A0_005ac5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC5A0_005ac5a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC620_005ac620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC620_005ac620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC620_005ac620.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC680_005ac680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC680_005ac680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC680_005ac680.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AC8D0_005ac8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AC8D0_005ac8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AC8D0_005ac8d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACA90_005aca90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACA90_005aca90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACA90_005aca90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACAC0_005acac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACAC0_005acac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACAC0_005acac0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACB60_005acb60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACB60_005acb60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACB60_005acb60.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__0_ReaderWriterLock_details_Concurrency__QAE_XZ_005acb90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__0_ReaderWriterLock_details_Concurrency__QAE_XZ_005acb90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__0_ReaderWriterLock_details_Concurrency__QAE_XZ_005acb90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACBB0_005acbb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACBB0_005acbb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACBB0_005acbb0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ACC30_005acc30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ACC30_005acc30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ACC30_005acc30.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AD350_005ad350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AD350_005ad350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AD350_005ad350.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AD580_005ad580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AD580_005ad580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AD580_005ad580.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AD5F0_005ad5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AD5F0_005ad5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AD5F0_005ad5f0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AD940_005ad940.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AD940_005ad940.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AD940_005ad940.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADDC0_005addc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADDC0_005addc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADDC0_005addc0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADE10_005ade10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADE10_005ade10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADE10_005ade10.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADE40_005ade40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADE40_005ade40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADE40_005ade40.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5ADE90_005ade90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5ADE90_005ade90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5ADE90_005ade90.md
