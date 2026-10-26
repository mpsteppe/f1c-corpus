# SKELETON FILL — Worker D chunk 13/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8410_004a8410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8410_004a8410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8410_004a8410.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8480_004a8480.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8480_004a8480.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8480_004a8480.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A84A0_004a84a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A84A0_004a84a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A84A0_004a84a0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A8520_004a8520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A8520_004a8520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A8520_004a8520.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A85A0_004a85a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A85A0_004a85a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A85A0_004a85a0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4A9700_004a9700.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4A9700_004a9700.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4A9700_004a9700.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA09C_004aa09c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA09C_004aa09c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA09C_004aa09c.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA0A0_004aa0a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA0A0_004aa0a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA0A0_004aa0a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA510_004aa510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA510_004aa510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA510_004aa510.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA640_004aa640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA640_004aa640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA640_004aa640.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA6C0_004aa6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA6C0_004aa6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA6C0_004aa6c0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AA6E0_004aa6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AA6E0_004aa6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AA6E0_004aa6e0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AAAF0_004aaaf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AAAF0_004aaaf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AAAF0_004aaaf0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AAE70_004aae70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AAE70_004aae70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AAE70_004aae70.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AAEF0_004aaef0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AAEF0_004aaef0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AAEF0_004aaef0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AAF50_004aaf50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AAF50_004aaf50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AAF50_004aaf50.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB0E0_004ab0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB0E0_004ab0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB0E0_004ab0e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB2E0_004ab2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB2E0_004ab2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB2E0_004ab2e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB320_004ab320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB320_004ab320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB320_004ab320.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB380_004ab380.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB380_004ab380.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB380_004ab380.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB3C0_004ab3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB3C0_004ab3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB3C0_004ab3c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB400_004ab400.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB400_004ab400.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB400_004ab400.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AB930_004ab930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AB930_004ab930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AB930_004ab930.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC050_004ac050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC050_004ac050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC050_004ac050.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AC110_004ac110.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AC110_004ac110.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AC110_004ac110.md
