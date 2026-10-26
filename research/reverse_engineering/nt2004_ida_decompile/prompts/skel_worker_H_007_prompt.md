# SKELETON FILL — Worker H chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA0E0_005ba0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA0E0_005ba0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA0E0_005ba0e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA120_005ba120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA120_005ba120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA120_005ba120.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA160_005ba160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA160_005ba160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA160_005ba160.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_GetGroup_HardwareAffinity_details_Concurrency__QAEGXZ_005ba210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_GetGroup_HardwareAffinity_details_Concurrency__QAEGXZ_005ba210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_GetGroup_HardwareAffinity_details_Concurrency__QAEGXZ_005ba210.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA220_005ba220.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA220_005ba220.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA220_005ba220.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA28C_005ba28c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA28C_005ba28c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA28C_005ba28c.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA350_005ba350.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA350_005ba350.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA350_005ba350.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA4C0_005ba4c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA4C0_005ba4c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA4C0_005ba4c0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA500_005ba500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA500_005ba500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA500_005ba500.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5A0_005ba5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5A0_005ba5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5A0_005ba5a0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5B0_005ba5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5B0_005ba5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5B0_005ba5b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5C0_005ba5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5C0_005ba5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5C0_005ba5c0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5D0_005ba5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5D0_005ba5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5D0_005ba5d0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5E0_005ba5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5E0_005ba5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5E0_005ba5e0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA5F0_005ba5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA5F0_005ba5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA5F0_005ba5f0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA600_005ba600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA600_005ba600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA600_005ba600.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA8B0_005ba8b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA8B0_005ba8b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA8B0_005ba8b0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA970_005ba970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA970_005ba970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA970_005ba970.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BA9E0_005ba9e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BA9E0_005ba9e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BA9E0_005ba9e0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BAB40_005bab40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BAB40_005bab40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BAB40_005bab40.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BAB70_005bab70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BAB70_005bab70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BAB70_005bab70.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_149_005bab9c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_149_005bab9c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_149_005bab9c.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BABA0_005baba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BABA0_005baba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BABA0_005baba0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BAC00_005bac00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BAC00_005bac00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BAC00_005bac00.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BAF50_005baf50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BAF50_005baf50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BAF50_005baf50.md
