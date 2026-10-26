# SKELETON FILL — Worker H chunk 11/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_atexit_005be81e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_atexit_005be81e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_atexit_005be81e.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE8AE_005be8ae.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE8AE_005be8ae.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE8AE_005be8ae.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ftol_005be8bc.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ftol_005be8bc.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ftol_005be8bc.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__2_YAPAXI_Z_005be8e3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__2_YAPAXI_Z_005be8e3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__2_YAPAXI_Z_005be8e3.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5BE8F8_005be8f8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5BE8F8_005be8f8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5BE8F8_005be8f8.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_fopen_005bea90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_fopen_005bea90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_fopen_005bea90.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_atoi_005bec89.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_atoi_005bec89.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_atoi_005bec89.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_fread_005bed9e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_fread_005bed9e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_fread_005bed9e.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__purecall_005bee86.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__purecall_005bee86.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__purecall_005bee86.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strncmp_005bee90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strncmp_005bee90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strncmp_005bee90.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_sprintf_005beec8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_sprintf_005beec8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_sprintf_005beec8.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CIpow_005bef20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CIpow_005bef20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CIpow_005bef20.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_pow_005bef39.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_pow_005bef39.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_pow_005bef39.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_srand_005bf360.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_srand_005bf360.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_srand_005bf360.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_sscanf_005bf71b.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_sscanf_005bf71b.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_sscanf_005bf71b.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__global_unwind2_005bf790.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__global_unwind2_005bf790.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__global_unwind2_005bf790.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__NLG_Notify1_005bf85d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__NLG_Notify1_005bf85d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__NLG_Notify1_005bf85d.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__NLG_Notify_005bf866.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__NLG_Notify_005bf866.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__NLG_Notify_005bf866.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__seh_longjmp_unwind_4_005bf945.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__seh_longjmp_unwind_4_005bf945.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__seh_longjmp_unwind_4_005bf945.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__expandlocale_005bfd7a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__expandlocale_005bfd7a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__expandlocale_005bfd7a.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_qsort_005bffd9.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_qsort_005bffd9.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_qsort_005bffd9.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_strtol_005c01a7.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_strtol_005c01a7.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_strtol_005c01a7.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CIacos_005c03d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CIacos_005c03d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CIacos_005c03d0.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_acos_005c03e4.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_acos_005c03e4.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_acos_005c03e4.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__CIfmod_005c057a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__CIfmod_005c057a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__CIfmod_005c057a.md
