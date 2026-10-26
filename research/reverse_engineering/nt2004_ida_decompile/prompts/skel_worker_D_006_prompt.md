# SKELETON FILL — Worker D chunk 6/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D3D0_0049d3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D3D0_0049d3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D3D0_0049d3d0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D430_0049d430.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D430_0049d430.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D430_0049d430.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D450_0049d450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D450_0049d450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D450_0049d450.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D460_0049d460.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D460_0049d460.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D460_0049d460.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D550_0049d550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D550_0049d550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D550_0049d550.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D690_0049d690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D690_0049d690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D690_0049d690.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D6E0_0049d6e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D6E0_0049d6e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D6E0_0049d6e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D71B_0049d71b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D71B_0049d71b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D71B_0049d71b.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D720_0049d720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D720_0049d720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D720_0049d720.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D870_0049d870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D870_0049d870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D870_0049d870.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D930_0049d930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D930_0049d930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D930_0049d930.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D950_0049d950.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D950_0049d950.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D950_0049d950.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D97B_0049d97b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D97B_0049d97b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D97B_0049d97b.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49D9A0_0049d9a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49D9A0_0049d9a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49D9A0_0049d9a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DA90_0049da90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DA90_0049da90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DA90_0049da90.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DB60_0049db60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DB60_0049db60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DB60_0049db60.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DDD0_0049ddd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DDD0_0049ddd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DDD0_0049ddd0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DDE0_0049dde0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DDE0_0049dde0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DDE0_0049dde0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DF40_0049df40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DF40_0049df40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DF40_0049df40.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DF50_0049df50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DF50_0049df50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DF50_0049df50.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49DFB0_0049dfb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49DFB0_0049dfb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49DFB0_0049dfb0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E090_0049e090.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E090_0049e090.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E090_0049e090.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E0E0_0049e0e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E0E0_0049e0e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E0E0_0049e0e0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E2E0_0049e2e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E2E0_0049e2e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E2E0_0049e2e0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49E320_0049e320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49E320_0049e320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49E320_0049e320.md
