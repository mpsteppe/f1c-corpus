# SKELETON FILL — Worker E chunk 20/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EABE0_004eabe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EABE0_004eabe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EABE0_004eabe0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EACE0_004eace0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EACE0_004eace0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EACE0_004eace0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EAD00_004ead00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EAD00_004ead00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EAD00_004ead00.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EAD30_004ead30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EAD30_004ead30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EAD30_004ead30.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB1C0_004eb1c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB1C0_004eb1c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB1C0_004eb1c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB530_004eb530.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB530_004eb530.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB530_004eb530.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB570_004eb570.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB570_004eb570.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB570_004eb570.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EB650_004eb650.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EB650_004eb650.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EB650_004eb650.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EBFE0_004ebfe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EBFE0_004ebfe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EBFE0_004ebfe0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC010_004ec010.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC010_004ec010.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC010_004ec010.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC230_004ec230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC230_004ec230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC230_004ec230.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC2E2_004ec2e2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC2E2_004ec2e2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC2E2_004ec2e2.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC2F0_004ec2f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC2F0_004ec2f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC2F0_004ec2f0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC3A0_004ec3a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC3A0_004ec3a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC3A0_004ec3a0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC450_004ec450.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC450_004ec450.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC450_004ec450.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC4A0_004ec4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC4A0_004ec4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC4A0_004ec4a0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC508_004ec508.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC508_004ec508.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC508_004ec508.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC510_004ec510.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC510_004ec510.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC510_004ec510.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC5D0_004ec5d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC5D0_004ec5d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC5D0_004ec5d0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC5E0_004ec5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC5E0_004ec5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC5E0_004ec5e0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC667_004ec667.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC667_004ec667.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC667_004ec667.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC740_004ec740.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC740_004ec740.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC740_004ec740.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC790_004ec790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC790_004ec790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC790_004ec790.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EC7D4_004ec7d4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EC7D4_004ec7d4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EC7D4_004ec7d4.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ECA34_004eca34.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ECA34_004eca34.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ECA34_004eca34.md
