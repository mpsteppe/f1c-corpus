# SKELETON FILL — Worker A chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407310_00407310.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407310_00407310.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407310_00407310.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4074F0_004074f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4074F0_004074f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4074F0_004074f0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407790_00407790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407790_00407790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407790_00407790.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4078F0_004078f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4078F0_004078f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4078F0_004078f0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407A60_00407a60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407A60_00407a60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407A60_00407a60.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407B40_00407b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407B40_00407b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407B40_00407b40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407BF0_00407bf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407BF0_00407bf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407BF0_00407bf0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407FB0_00407fb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407FB0_00407fb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407FB0_00407fb0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_408000_00408000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_408000_00408000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_408000_00408000.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_408040_00408040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_408040_00408040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_408040_00408040.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_408080_00408080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_408080_00408080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_408080_00408080.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_408CD0_00408cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_408CD0_00408cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_408CD0_00408cd0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_408FC0_00408fc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_408FC0_00408fc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_408FC0_00408fc0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409010_00409010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409010_00409010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409010_00409010.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_4_00409020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_4_00409020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_4_00409020.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_5_00409040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_5_00409040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_5_00409040.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409050_00409050.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409050_00409050.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409050_00409050.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409290_00409290.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409290_00409290.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409290_00409290.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4092A0_004092a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4092A0_004092a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4092A0_004092a0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409430_00409430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409430_00409430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409430_00409430.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409490_00409490.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409490_00409490.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409490_00409490.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409610_00409610.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409610_00409610.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409610_00409610.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_409BB0_00409bb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_409BB0_00409bb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_409BB0_00409bb0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A0D0_0040a0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A0D0_0040a0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A0D0_0040a0d0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40A148_0040a148.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40A148_0040a148.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40A148_0040a148.md
