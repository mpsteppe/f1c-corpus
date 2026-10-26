# SKELETON FILL — Worker H chunk 14/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_isintTOSret_005c4b26.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_isintTOSret_005c4b26.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_isintTOSret_005c4b26.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\notanint_005c4b27.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\notanint_005c4b27.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\notanint_005c4b27.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\evenint_005c4b2e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\evenint_005c4b2e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\evenint_005c4b2e.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__rttosnpopde_005c4d29.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__rttosnpopde_005c4d29.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__rttosnpopde_005c4d29.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\chsifnegret_005c4d39.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\chsifnegret_005c4d39.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\chsifnegret_005c4d39.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__startTwoArgErrorHandling_005c4d40.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__startTwoArgErrorHandling_005c4d40.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__startTwoArgErrorHandling_005c4d40.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__twoToTOS_005c4da0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__twoToTOS_005c4da0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__twoToTOS_005c4da0.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__load_CW_005c4db5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__load_CW_005c4db5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__load_CW_005c4db5.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__convertTOStoQNaN_005c4dcc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__convertTOStoQNaN_005c4dcc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__convertTOStoQNaN_005c4dcc.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fload_withFB_005c4de5.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fload_withFB_005c4de5.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fload_withFB_005c4de5.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__checkTOS_withFB_005c4e28.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__checkTOS_withFB_005c4e28.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__checkTOS_withFB_005c4e28.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__check_overflow_exit_005c4e75.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__check_overflow_exit_005c4e75.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__check_overflow_exit_005c4e75.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__getptd_005c5128.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__getptd_005c5128.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__getptd_005c5128.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strlen_005c5210.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strlen_005c5210.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strlen_005c5210.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__mtinitlocks_005c528b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__mtinitlocks_005c528b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__mtinitlocks_005c528b.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__unlock_005c5315.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__unlock_005c5315.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__unlock_005c5315.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ioinit_005c532a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ioinit_005c532a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ioinit_005c532a.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__un_inc_005c6203.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__un_inc_005c6203.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__un_inc_005c6203.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strcpy_005c6f50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strcpy_005c6f50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strcpy_005c6f50.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strcat_005c6f60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strcat_005c6f60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strcat_005c6f60.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_LangCountryEnumProc_4_005c729c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_LangCountryEnumProc_4_005c729c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_LangCountryEnumProc_4_005c729c.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_IsThisWindowsNT_005c7771.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_IsThisWindowsNT_005c7771.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_IsThisWindowsNT_005c7771.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_LcidFromHexString_005c788d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_LcidFromHexString_005c788d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_LcidFromHexString_005c788d.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_GetPrimaryLen_005c78c6.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_GetPrimaryLen_005c78c6.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_GetPrimaryLen_005c78c6.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__raise_exc_005c79d3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__raise_exc_005c79d3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__raise_exc_005c79d3.md
