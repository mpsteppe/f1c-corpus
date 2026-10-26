# SKELETON FILL — Worker A chunk 16/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_1_00405140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_1_00405140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_1_00405140.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_2_00405160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_2_00405160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_2_00405160.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405170_00405170.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405170_00405170.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405170_00405170.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4054B0_004054b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4054B0_004054b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4054B0_004054b0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4057B0_004057b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4057B0_004057b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4057B0_004057b0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4057C0_004057c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4057C0_004057c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4057C0_004057c0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4059E0_004059e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4059E0_004059e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4059E0_004059e0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4059F0_004059f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4059F0_004059f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4059F0_004059f0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405A00_00405a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405A00_00405a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405A00_00405a00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405A10_00405a10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405A10_00405a10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405A10_00405a10.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405A20_00405a20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405A20_00405a20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405A20_00405a20.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405B40_00405b40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405B40_00405b40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405B40_00405b40.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405C10_00405c10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405C10_00405c10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405C10_00405c10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405CC3_00405cc3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405CC3_00405cc3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405CC3_00405cc3.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_3_00405cd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_3_00405cd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_3_00405cd0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405CE0_00405ce0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405CE0_00405ce0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405CE0_00405ce0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_405D00_00405d00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_405D00_00405d00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_405D00_00405d00.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406494_00406494.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406494_00406494.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406494_00406494.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406550_00406550.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406550_00406550.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406550_00406550.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4067B0_004067b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4067B0_004067b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4067B0_004067b0.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406B10_00406b10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406B10_00406b10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406B10_00406b10.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_406F80_00406f80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_406F80_00406f80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_406F80_00406f80.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_Win95IsDebuggerPresent__YGHXZ_00407180.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_Win95IsDebuggerPresent__YGHXZ_00407180.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_Win95IsDebuggerPresent__YGHXZ_00407180.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_4071F0_004071f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_4071F0_004071f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_4071F0_004071f0.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_407210_00407210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_407210_00407210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_407210_00407210.md
