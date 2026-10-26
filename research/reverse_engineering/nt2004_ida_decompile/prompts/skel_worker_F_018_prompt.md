# SKELETON FILL — Worker F chunk 18/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528B80_00528b80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528B80_00528b80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528B80_00528b80.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528C20_00528c20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528C20_00528c20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528C20_00528c20.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_528FF0_00528ff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_528FF0_00528ff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_528FF0_00528ff0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529080_00529080.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529080_00529080.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529080_00529080.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5296C0_005296c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5296C0_005296c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5296C0_005296c0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5297B0_005297b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5297B0_005297b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5297B0_005297b0.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5299B0_005299b0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5299B0_005299b0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5299B0_005299b0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5299C0_005299c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5299C0_005299c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5299C0_005299c0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529A00_00529a00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529A00_00529a00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529A00_00529a00.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529AC0_00529ac0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529AC0_00529ac0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529AC0_00529ac0.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529BA0_00529ba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529BA0_00529ba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529BA0_00529ba0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529C60_00529c60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529C60_00529c60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529C60_00529c60.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_103_00529c70.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_103_00529c70.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_103_00529c70.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_104_00529c90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_104_00529c90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_104_00529c90.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_529CA0_00529ca0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_529CA0_00529ca0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_529CA0_00529ca0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52A580_0052a580.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52A580_0052a580.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52A580_0052a580.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52A980_0052a980.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52A980_0052a980.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52A980_0052a980.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52AC40_0052ac40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52AC40_0052ac40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52AC40_0052ac40.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52ACD0_0052acd0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52ACD0_0052acd0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52ACD0_0052acd0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52AD20_0052ad20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52AD20_0052ad20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52AD20_0052ad20.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B7C0_0052b7c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B7C0_0052b7c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B7C0_0052b7c0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B7E0_0052b7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B7E0_0052b7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B7E0_0052b7e0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B8D0_0052b8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B8D0_0052b8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B8D0_0052b8d0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52B930_0052b930.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52B930_0052b930.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52B930_0052b930.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_52C0C0_0052c0c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_52C0C0_0052c0c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_52C0C0_0052c0c0.md
