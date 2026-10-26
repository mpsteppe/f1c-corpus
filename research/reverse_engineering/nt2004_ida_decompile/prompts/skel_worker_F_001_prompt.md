# SKELETON FILL — Worker F chunk 1/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE160_004ee160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE160_004ee160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE160_004ee160.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE280_004ee280.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE280_004ee280.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE280_004ee280.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE300_004ee300.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE300_004ee300.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE300_004ee300.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EE360_004ee360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EE360_004ee360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EE360_004ee360.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEA00_004eea00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEA00_004eea00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEA00_004eea00.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEAE0_004eeae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEAE0_004eeae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEAE0_004eeae0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEBA0_004eeba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEBA0_004eeba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEBA0_004eeba0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEC20_004eec20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEC20_004eec20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEC20_004eec20.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEC50_004eec50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEC50_004eec50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEC50_004eec50.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EECE0_004eece0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EECE0_004eece0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EECE0_004eece0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EED10_004eed10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EED10_004eed10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EED10_004eed10.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EED40_004eed40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EED40_004eed40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EED40_004eed40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EED80_004eed80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EED80_004eed80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EED80_004eed80.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EED90_004eed90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EED90_004eed90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EED90_004eed90.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEE20_004eee20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEE20_004eee20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEE20_004eee20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEE30_004eee30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEE30_004eee30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEE30_004eee30.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEE40_004eee40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEE40_004eee40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEE40_004eee40.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_82_004eee60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_82_004eee60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_82_004eee60.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEE70_004eee70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEE70_004eee70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEE70_004eee70.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_84_004eeea0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_84_004eeea0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_84_004eeea0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_85_004eeeb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_85_004eeeb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_85_004eeeb0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEEC0_004eeec0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEEC0_004eeec0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEEC0_004eeec0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_004eefe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_004eefe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_004eefe0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4EEFF0_004eeff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4EEFF0_004eeff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4EEFF0_004eeff0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_0_004ef089.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_0_004ef089.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__Release__NonReentrantLock_details_Concurrency__QAEXXZ_0_004ef089.md
