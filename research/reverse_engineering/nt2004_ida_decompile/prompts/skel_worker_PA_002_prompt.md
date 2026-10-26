# SKELETON FILL — Worker PA chunk 2/4 (f1c-ida-skeleton-pro), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4AEA10_004aea10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4AEA10_004aea10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4AEA10_004aea10.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4D8DD0_004d8dd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4D8DD0_004d8dd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4D8DD0_004d8dd0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4F18E0_004f18e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4F18E0_004f18e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4F18E0_004f18e0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_524990_00524990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_524990_00524990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_524990_00524990.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5380B0_005380b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5380B0_005380b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5380B0_005380b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_40B4A0_0040b4a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_40B4A0_0040b4a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_40B4A0_0040b4a0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_449EA0_00449ea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_449EA0_00449ea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_449EA0_00449ea0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_461E20_00461e20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_461E20_00461e20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_461E20_00461e20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46F1B0_0046f1b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46F1B0_0046f1b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46F1B0_0046f1b0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_490320_00490320.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_490320_00490320.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_490320_00490320.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4B4990_004b4990.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4B4990_004b4990.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4B4990_004b4990.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CC3D0_004cc3d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CC3D0_004cc3d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CC3D0_004cc3d0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4FB270_004fb270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4FB270_004fb270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4FB270_004fb270.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_518070_00518070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_518070_00518070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_518070_00518070.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54E97C_0054e97c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54E97C_0054e97c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54E97C_0054e97c.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5AB3E0_005ab3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5AB3E0_005ab3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5AB3E0_005ab3e0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4090C0_004090c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4090C0_004090c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4090C0_004090c0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4115D0_004115d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4115D0_004115d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4115D0_004115d0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_42A1F0_0042a1f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_42A1F0_0042a1f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_42A1F0_0042a1f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_43B6B0_0043b6b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_43B6B0_0043b6b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_43B6B0_0043b6b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_457870_00457870.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_457870_00457870.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_457870_00457870.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_467E40_00467e40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_467E40_00467e40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_467E40_00467e40.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_49C1D0_0049c1d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_49C1D0_0049c1d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_49C1D0_0049c1d0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4ACB80_004acb80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4ACB80_004acb80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4ACB80_004acb80.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4CAA80_004caa80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4CAA80_004caa80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4CAA80_004caa80.md
