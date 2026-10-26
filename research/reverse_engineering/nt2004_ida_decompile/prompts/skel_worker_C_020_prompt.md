# SKELETON FILL — Worker C chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B5A0_0048b5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B5A0_0048b5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B5A0_0048b5a0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B5D0_0048b5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B5D0_0048b5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B5D0_0048b5d0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B600_0048b600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B600_0048b600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B600_0048b600.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B630_0048b630.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B630_0048b630.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B630_0048b630.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B660_0048b660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B660_0048b660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B660_0048b660.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B690_0048b690.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B690_0048b690.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B690_0048b690.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B6C0_0048b6c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B6C0_0048b6c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B6C0_0048b6c0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B6F0_0048b6f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B6F0_0048b6f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B6F0_0048b6f0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48B720_0048b720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48B720_0048b720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48B720_0048b720.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48BD00_0048bd00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48BD00_0048bd00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48BD00_0048bd00.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48BD70_0048bd70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48BD70_0048bd70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48BD70_0048bd70.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48BDB0_0048bdb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48BDB0_0048bdb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48BDB0_0048bdb0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48BE60_0048be60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48BE60_0048be60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48BE60_0048be60.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C0D7_0048c0d7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C0D7_0048c0d7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C0D7_0048c0d7.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C1C0_0048c1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C1C0_0048c1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C1C0_0048c1c0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C250_0048c250.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C250_0048c250.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C250_0048c250.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C2A0_0048c2a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C2A0_0048c2a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C2A0_0048c2a0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C2D0_0048c2d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C2D0_0048c2d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C2D0_0048c2d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C300_0048c300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C300_0048c300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C300_0048c300.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C320_0048c320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C320_0048c320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C320_0048c320.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C3F0_0048c3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C3F0_0048c3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C3F0_0048c3f0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C420_0048c420.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C420_0048c420.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C420_0048c420.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C450_0048c450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C450_0048c450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C450_0048c450.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C520_0048c520.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C520_0048c520.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C520_0048c520.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_48C537_0048c537.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_48C537_0048c537.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_48C537_0048c537.md
