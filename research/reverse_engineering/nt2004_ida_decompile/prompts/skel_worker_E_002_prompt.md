# SKELETON FILL — Worker E chunk 2/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA330_004ba330.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA330_004ba330.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA330_004ba330.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA410_004ba410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA410_004ba410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA410_004ba410.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA5B0_004ba5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA5B0_004ba5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA5B0_004ba5b0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA680_004ba680.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA680_004ba680.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA680_004ba680.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA6B0_004ba6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA6B0_004ba6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA6B0_004ba6b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA730_004ba730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA730_004ba730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA730_004ba730.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BA7F0_004ba7f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BA7F0_004ba7f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BA7F0_004ba7f0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BABB0_004babb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BABB0_004babb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BABB0_004babb0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BAC70_004bac70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BAC70_004bac70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BAC70_004bac70.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BB120_004bb120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BB120_004bb120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BB120_004bb120.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BB160_004bb160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BB160_004bb160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BB160_004bb160.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_55_004bb170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_55_004bb170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_55_004bb170.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_56_004bb190.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_56_004bb190.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_56_004bb190.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BB880_004bb880.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BB880_004bb880.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BB880_004bb880.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBB70_004bbb70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBB70_004bbb70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBB70_004bbb70.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_57_004bbba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_57_004bbba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_57_004bbba0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBBD0_004bbbd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBBD0_004bbbd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBBD0_004bbbd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBDC0_004bbdc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBDC0_004bbdc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBDC0_004bbdc0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBE30_004bbe30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBE30_004bbe30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBE30_004bbe30.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBE60_004bbe60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBE60_004bbe60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBE60_004bbe60.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBF10_004bbf10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBF10_004bbf10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBF10_004bbf10.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBF20_004bbf20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBF20_004bbf20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBF20_004bbf20.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBF40_004bbf40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBF40_004bbf40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBF40_004bbf40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBF50_004bbf50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBF50_004bbf50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBF50_004bbf50.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4BBF80_004bbf80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4BBF80_004bbf80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4BBF80_004bbf80.md
