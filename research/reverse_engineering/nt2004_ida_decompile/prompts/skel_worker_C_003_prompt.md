# SKELETON FILL — Worker C chunk 3/23 (f1c-ida-skeleton), 25 functions

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

1. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C5E0_0046c5e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C5E0_0046c5e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C5E0_0046c5e0.md
2. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C5F0_0046c5f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C5F0_0046c5f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C5F0_0046c5f0.md
3. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\unknown_libname_38_0046c620.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\unknown_libname_38_0046c620.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\unknown_libname_38_0046c620.md
4. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C640_0046c640.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C640_0046c640.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C640_0046c640.md
5. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C660_0046c660.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C660_0046c660.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C660_0046c660.md
6. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C710_0046c710.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C710_0046c710.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C710_0046c710.md
7. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C730_0046c730.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C730_0046c730.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C730_0046c730.md
8. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C7A0_0046c7a0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C7A0_0046c7a0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C7A0_0046c7a0.md
9. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C7E0_0046c7e0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C7E0_0046c7e0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C7E0_0046c7e0.md
10. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C830_0046c830.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C830_0046c830.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C830_0046c830.md
11. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C8D0_0046c8d0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C8D0_0046c8d0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C8D0_0046c8d0.md
12. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46C8F0_0046c8f0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46C8F0_0046c8f0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46C8F0_0046c8f0.md
13. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46CC10_0046cc10.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46CC10_0046cc10.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46CC10_0046cc10.md
14. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46CEE0_0046cee0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46CEE0_0046cee0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46CEE0_0046cee0.md
15. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46CFF0_0046cff0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46CFF0_0046cff0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46CFF0_0046cff0.md
16. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46D020_0046d020.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46D020_0046d020.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46D020_0046d020.md
17. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46D160_0046d160.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46D160_0046d160.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46D160_0046d160.md
18. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46D970_0046d970.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46D970_0046d970.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46D970_0046d970.md
19. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DAB0_0046dab0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DAB0_0046dab0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DAB0_0046dab0.md
20. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\nullsub_83_0046dce3.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\nullsub_83_0046dce3.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\nullsub_83_0046dce3.md
21. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DCF0_0046dcf0.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DCF0_0046dcf0.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DCF0_0046dcf0.md
22. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DD30_0046dd30.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DD30_0046dd30.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DD30_0046dd30.md
23. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DD50_0046dd50.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DD50_0046dd50.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DD50_0046dd50.md
24. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DD90_0046dd90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DD90_0046dd90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DD90_0046dd90.md
25. SKEL: %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons\sub_46DF90_0046df90.md
   C:    %USERPROFILE%\Desktop\nt2004_ida_decompile\functions\sub_46DF90_0046df90.c
   OUT:  %USERPROFILE%\Desktop\nt2004_ida_decompile\skeletons_filled\sub_46DF90_0046df90.md
