# SKELETON FILL — Worker C chunk 10/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47EAE0_0047eae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47EAE0_0047eae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47EAE0_0047eae0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47EAF0_0047eaf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47EAF0_0047eaf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47EAF0_0047eaf0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47ED60_0047ed60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47ED60_0047ed60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47ED60_0047ed60.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47EFE0_0047efe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47EFE0_0047efe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47EFE0_0047efe0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47F040_0047f040.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47F040_0047f040.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47F040_0047f040.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47F080_0047f080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47F080_0047f080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47F080_0047f080.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_91_0047f195.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_91_0047f195.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_91_0047f195.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47FBF0_0047fbf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47FBF0_0047fbf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47FBF0_0047fbf0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47FE40_0047fe40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47FE40_0047fe40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47FE40_0047fe40.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_47FF30_0047ff30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_47FF30_0047ff30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_47FF30_0047ff30.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480000_00480000.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480000_00480000.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480000_00480000.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480070_00480070.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480070_00480070.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480070_00480070.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480120_00480120.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480120_00480120.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480120_00480120.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480270_00480270.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480270_00480270.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480270_00480270.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480370_00480370.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480370_00480370.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480370_00480370.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4803B0_004803b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4803B0_004803b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4803B0_004803b0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480550_00480550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480550_00480550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480550_00480550.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4805E0_004805e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4805E0_004805e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4805E0_004805e0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4805F0_004805f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4805F0_004805f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4805F0_004805f0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480600_00480600.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480600_00480600.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480600_00480600.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480AE0_00480ae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480AE0_00480ae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480AE0_00480ae0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480B30_00480b30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480B30_00480b30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480B30_00480b30.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480B40_00480b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480B40_00480b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480B40_00480b40.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_480F70_00480f70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_480F70_00480f70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_480F70_00480f70.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_481560_00481560.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_481560_00481560.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_481560_00481560.md
