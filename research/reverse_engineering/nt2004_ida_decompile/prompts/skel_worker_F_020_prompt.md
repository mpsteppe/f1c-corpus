# SKELETON FILL — Worker F chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5365A0_005365a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5365A0_005365a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5365A0_005365a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5367E0_005367e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5367E0_005367e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5367E0_005367e0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536830_00536830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536830_00536830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536830_00536830.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5368C0_005368c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5368C0_005368c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5368C0_005368c0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5368E0_005368e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5368E0_005368e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5368E0_005368e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536910_00536910.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536910_00536910.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536910_00536910.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5369D0_005369d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5369D0_005369d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5369D0_005369d0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536C60_00536c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536C60_00536c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536C60_00536c60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536CE0_00536ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536CE0_00536ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536CE0_00536ce0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_536E20_00536e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_536E20_00536e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_536E20_00536e20.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5386B0_005386b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5386B0_005386b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5386B0_005386b0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53A0D0_0053a0d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53A0D0_0053a0d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53A0D0_0053a0d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53AEB0_0053aeb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53AEB0_0053aeb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53AEB0_0053aeb0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53B5B0_0053b5b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53B5B0_0053b5b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53B5B0_0053b5b0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_AIL_shutdown_0_0053c160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_AIL_shutdown_0_0053c160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_AIL_shutdown_0_0053c160.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53C170_0053c170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53C170_0053c170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53C170_0053c170.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53D7A1_0053d7a1.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53D7A1_0053d7a1.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53D7A1_0053d7a1.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53DD5A_0053dd5a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53DD5A_0053dd5a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53DD5A_0053dd5a.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53DDB3_0053ddb3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53DDB3_0053ddb3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53DDB3_0053ddb3.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53E4E5_0053e4e5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53E4E5_0053e4e5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53E4E5_0053e4e5.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53E502_0053e502.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53E502_0053e502.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53E502_0053e502.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53EEC5_0053eec5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53EEC5_0053eec5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53EEC5_0053eec5.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53EF08_0053ef08.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53EF08_0053ef08.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53EF08_0053ef08.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_53F7EB_0053f7eb.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_53F7EB_0053f7eb.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_53F7EB_0053f7eb.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_107_0053fa18.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_107_0053fa18.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_107_0053fa18.md
