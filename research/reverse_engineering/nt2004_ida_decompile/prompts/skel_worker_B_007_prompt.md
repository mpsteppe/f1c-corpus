# SKELETON FILL — Worker B chunk 7/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C0F0_0042c0f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C0F0_0042c0f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C0F0_0042c0f0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42C120_0042c120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42C120_0042c120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42C120_0042c120.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CB20_0042cb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CB20_0042cb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CB20_0042cb20.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CBC0_0042cbc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CBC0_0042cbc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CBC0_0042cbc0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CC80_0042cc80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CC80_0042cc80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CC80_0042cc80.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42CFB0_0042cfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42CFB0_0042cfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42CFB0_0042cfb0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_22_0042d4f6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_22_0042d4f6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_22_0042d4f6.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D500_0042d500.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D500_0042d500.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D500_0042d500.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D590_0042d590.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D590_0042d590.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D590_0042d590.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D5C0_0042d5c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D5C0_0042d5c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D5C0_0042d5c0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D6E0_0042d6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D6E0_0042d6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D6E0_0042d6e0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D720_0042d720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D720_0042d720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D720_0042d720.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D790_0042d790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D790_0042d790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D790_0042d790.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D7C8_0042d7c8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D7C8_0042d7c8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D7C8_0042d7c8.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_14_0042d7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_14_0042d7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_14_0042d7e0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_15_0042d800.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_15_0042d800.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_15_0042d800.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42D810_0042d810.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42D810_0042d810.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42D810_0042d810.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42DAB0_0042dab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42DAB0_0042dab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42DAB0_0042dab0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42DBA0_0042dba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42DBA0_0042dba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42DBA0_0042dba0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42DBC0_0042dbc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42DBC0_0042dbc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42DBC0_0042dbc0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42DD60_0042dd60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42DD60_0042dd60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42DD60_0042dd60.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42DD90_0042dd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42DD90_0042dd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42DD90_0042dd90.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42E4B0_0042e4b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42E4B0_0042e4b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42E4B0_0042e4b0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42EC90_0042ec90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42EC90_0042ec90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42EC90_0042ec90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42EDE0_0042ede0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42EDE0_0042ede0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42EDE0_0042ede0.md
