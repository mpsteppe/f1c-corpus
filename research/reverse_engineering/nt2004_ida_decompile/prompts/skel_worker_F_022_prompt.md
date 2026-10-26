# SKELETON FILL — Worker F chunk 22/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547C44_00547c44.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547C44_00547c44.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547C44_00547c44.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547C60_00547c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547C60_00547c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547C60_00547c60.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547D09_00547d09.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547D09_00547d09.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547D09_00547d09.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547F86_00547f86.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547F86_00547f86.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547F86_00547f86.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547FA2_00547fa2.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547FA2_00547fa2.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547FA2_00547fa2.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547FBE_00547fbe.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547FBE_00547fbe.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547FBE_00547fbe.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547FDA_00547fda.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547FDA_00547fda.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547FDA_00547fda.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_547FF6_00547ff6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_547FF6_00547ff6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_547FF6_00547ff6.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548012_00548012.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548012_00548012.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548012_00548012.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54802E_0054802e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54802E_0054802e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54802E_0054802e.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54814B_0054814b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54814B_0054814b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54814B_0054814b.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548150_00548150.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548150_00548150.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548150_00548150.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54816C_0054816c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54816C_0054816c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54816C_0054816c.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548188_00548188.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548188_00548188.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548188_00548188.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5481A4_005481a4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5481A4_005481a4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5481A4_005481a4.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5481C0_005481c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5481C0_005481c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5481C0_005481c0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5481DC_005481dc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5481DC_005481dc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5481DC_005481dc.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5481F8_005481f8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5481F8_005481f8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5481F8_005481f8.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548214_00548214.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548214_00548214.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548214_00548214.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548230_00548230.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548230_00548230.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548230_00548230.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54824C_0054824c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54824C_0054824c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54824C_0054824c.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5484F5_005484f5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5484F5_005484f5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5484F5_005484f5.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548511_00548511.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548511_00548511.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548511_00548511.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_54852D_0054852d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_54852D_0054852d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_54852D_0054852d.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_548549_00548549.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_548549_00548549.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_548549_00548549.md
