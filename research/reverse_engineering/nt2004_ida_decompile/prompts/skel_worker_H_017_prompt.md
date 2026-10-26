# SKELETON FILL — Worker H chunk 17/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fptrap_005ccc53.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fptrap_005ccc53.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fptrap_005ccc53.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__fcloseall_005ccc5c.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__fcloseall_005ccc5c.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__fcloseall_005ccc5c.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__unlock_fhandle_005ccfe0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__unlock_fhandle_005ccfe0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__unlock_fhandle_005ccfe0.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__isatty_005cd2e8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__isatty_005cd2e8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__isatty_005cd2e8.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__aullrem_005cd3e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__aullrem_005cd3e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__aullrem_005cd3e0.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___crtGetStringTypeA_005cd455.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___crtGetStringTypeA_005cd455.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___crtGetStringTypeA_005cd455.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__lseeki64_005cd59e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__lseeki64_005cd59e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__lseeki64_005cd59e.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__allshl_005cdd60.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__allshl_005cdd60.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__allshl_005cdd60.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___crtGetStringTypeW_005cdf4e.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___crtGetStringTypeW_005cdf4e.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___crtGetStringTypeW_005cdf4e.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_xtoa_005ce140.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_xtoa_005ce140.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_xtoa_005ce140.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_CPtoLCID_005ce498.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_CPtoLCID_005ce498.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_CPtoLCID_005ce498.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_getenv_005ce695.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_getenv_005ce695.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_getenv_005ce695.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ismbblead_005ce712.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ismbblead_005ce712.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ismbblead_005ce712.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___CxxUnhandledExceptionFilter__YGJPAU_EXCEPTION_POINTERS___Z_005ce7dd.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___CxxUnhandledExceptionFilter__YGJPAU_EXCEPTION_POINTERS___Z_005ce7dd.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___CxxUnhandledExceptionFilter__YGJPAU_EXCEPTION_POINTERS___Z_005ce7dd.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CE823_005ce823.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CE823_005ce823.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CE823_005ce823.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CE834_005ce834.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CE834_005ce834.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CE834_005ce834.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ValidateRead__YAHPBXI_Z_005ce841.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ValidateRead__YAHPBXI_Z_005ce841.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ValidateRead__YAHPBXI_Z_005ce841.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ValidateWrite__YAHPAXI_Z_005ce85d.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ValidateWrite__YAHPAXI_Z_005ce85d.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ValidateWrite__YAHPAXI_Z_005ce85d.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\__ValidateExecute__YAHP6GHXZ_Z_005ce879.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\__ValidateExecute__YAHP6GHXZ_Z_005ce879.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\__ValidateExecute__YAHP6GHXZ_Z_005ce879.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_abort_005ce891.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_abort_005ce891.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_abort_005ce891.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\_raise_005ce8a8.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\_raise_005ce8a8.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\_raise_005ce8a8.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\___addl_005cea67.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\___addl_005cea67.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\___addl_005cea67.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB20_005cfb20.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB20_005cfb20.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB20_005cfb20.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB2A_005cfb2a.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB2A_005cfb2a.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB2A_005cfb2a.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_5CFB43_005cfb43.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_5CFB43_005cfb43.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_5CFB43_005cfb43.md
