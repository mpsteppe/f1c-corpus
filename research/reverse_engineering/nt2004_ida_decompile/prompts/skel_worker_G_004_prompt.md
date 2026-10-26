# SKELETON FILL — Worker G chunk 4/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56A9E0_0056a9e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56A9E0_0056a9e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56A9E0_0056a9e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_120_0056aaa0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_120_0056aaa0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_120_0056aaa0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56AAD0_0056aad0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56AAD0_0056aad0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56AAD0_0056aad0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_121_0056aae0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_121_0056aae0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_121_0056aae0.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_122_0056ab00.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_122_0056ab00.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_122_0056ab00.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56AB10_0056ab10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56AB10_0056ab10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56AB10_0056ab10.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_123_0056ab20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_123_0056ab20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_123_0056ab20.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_124_0056ab40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_124_0056ab40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_124_0056ab40.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56AB50_0056ab50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56AB50_0056ab50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56AB50_0056ab50.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_125_0056ab60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_125_0056ab60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_125_0056ab60.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_126_0056ab80.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_126_0056ab80.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_126_0056ab80.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56AB90_0056ab90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56AB90_0056ab90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56AB90_0056ab90.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_127_0056aba0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_127_0056aba0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_127_0056aba0.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_128_0056abc0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_128_0056abc0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_128_0056abc0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56AC20_0056ac20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56AC20_0056ac20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56AC20_0056ac20.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___Gfacet_locale_std__UAEPAXI_Z_0_0056acb0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___Gfacet_locale_std__UAEPAXI_Z_0_0056acb0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___Gfacet_locale_std__UAEPAXI_Z_0_0056acb0.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56B3E0_0056b3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56B3E0_0056b3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56B3E0_0056b3e0.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56B3F0_0056b3f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56B3F0_0056b3f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56B3F0_0056b3f0.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56B410_0056b410.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56B410_0056b410.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56B410_0056b410.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56B890_0056b890.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56B890_0056b890.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56B890_0056b890.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56C5F7_0056c5f7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56C5F7_0056c5f7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56C5F7_0056c5f7.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56E3C0_0056e3c0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56E3C0_0056e3c0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56E3C0_0056e3c0.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56E5A0_0056e5a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56E5A0_0056e5a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56E5A0_0056e5a0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_56E720_0056e720.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_56E720_0056e720.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_56E720_0056e720.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_125_0056ec43.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_125_0056ec43.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_125_0056ec43.md
