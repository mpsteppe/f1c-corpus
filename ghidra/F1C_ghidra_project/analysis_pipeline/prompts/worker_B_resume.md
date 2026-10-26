# WORKER B — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker B of 3, items 68–134.

These functions are the "tissue" connecting already-documented game systems. Even the
smallest utility becomes meaningful when linked back to the system that uses it.
Write a full entry for EVERY function. No exceptions. Nothing is too small.

---

## STEP 1 — LOAD REFERENCE FILES BEFORE STARTING

Read these files FIRST and keep them in context throughout your session:

1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Complete named global list. Every DAT_ address you encounter: look it up here.
     Use the known name in your entry, not the raw address.

2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md`
   — Known struct field names by offset. Every struct access you document: check here first.
     Write "VehicleStruct.TireSlipAngle (+0x48)" not just "+0x48".

3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\decompiled_full_index_final.md`
   — Master triage index. Use it to look up what called functions do (if they appear here).

These three files are your primary cross-reference tools. Use them for every entry.

---

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to:
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_B.md

Exact structure:

```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00AAAAAA — First Function Name
...
```

Leave `=== TRIAGE LINES ===` EMPTY — entries already exist in the master index.
Write `<!-- target: docs/XX-name.md -->` immediately before EVERY `## FUN_` block.
Write to disk after EVERY function. No batching.

---

## STEP 3 — YOUR FILES (59 functions — RESUME)

IMPORTANT: Worker B already wrote 9 entries to the output file. Do NOT rewrite them.
Append ONLY the following 59 functions. Start writing immediately after the last entry.

72. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c40a__Unwind_0059c40a.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
73. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c478__Unwind_0059c478.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
74. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4c8__Unwind_0059c4c8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
75. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c518__Unwind_0059c518.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x40]
76. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c56e__Unwind_0059c56e.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
77. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5c6__Unwind_0059c5c6.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
78. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c602__Unwind_0059c602.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
79. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c63e__Unwind_0059c63e.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +8]
81. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6ac__Unwind_0059c6ac.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
82. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6f2__Unwind_0059c6f2.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
83. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c710__Unwind_0059c710.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
84. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d8__Unwind_0059c7d8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
85. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c812__Unwind_0059c812.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
86. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c854__Unwind_0059c854.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
87. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c896__Unwind_0059c896.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
88. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c902__Unwind_0059c902.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
89. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c948__Unwind_0059c948.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
90. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9a0__Unwind_0059c9a0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
91. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca5e__Unwind_0059ca5e.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
92. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb20__Unwind_0059cb20.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
94. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cbe0__Unwind_0059cbe0.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
95. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc40__Unwind_0059cc40.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
96. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc80__Unwind_0059cc80.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
97. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cceb__Unwind_0059cceb.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x10]
98. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd48__Unwind_0059cd48.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
99. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cda0__Unwind_0059cda0.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce60__Unwind_0059ce60.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cead__Unwind_0059cead.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ceed__Unwind_0059ceed.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf3d__Unwind_0059cf3d.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfb0__Unwind_0059cfb0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d004__Unwind_0059d004.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d091__Unwind_0059d091.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0eb__Unwind_0059d0eb.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d118__Unwind_0059d118.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d190__Unwind_0059d190.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1e8__Unwind_0059d1e8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with exception cleanup call]
112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d26c__Unwind_0059d26c.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 17 | prior triage: SEH unwind handler conditional destroy]
113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2e4__Unwind_0059d2e4.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d368__Unwind_0059d368.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d414__Unwind_0059d414.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d470__Unwind_0059d470.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with ~exception destructor]
117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4f4__Unwind_0059d4f4.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d558__Unwind_0059d558.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with ~exception destructor]
120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004203d0__thunk_FUN_004201e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cba3__FUN_0050cba3.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679a0__thunk_FUN_0059d6a9.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: Null-check wrapper: returns 0 if param_1==0, else calls FUN_005679a5]
123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a7ec____setjmp3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 59 | prior triage: __setjmp3 — MSVCRT jmp_buf save (regs, EH chain)]
124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c414__Unwind_0059c414.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c620__Unwind_0059c620.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c730__Unwind_0059c730.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c830__Unwind_0059c830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581a20]
128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c980__Unwind_0059c980.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581880]
129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc88__Unwind_0059cc88.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00582f60]
130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce7e__Unwind_0059ce7e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00585f30]
131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf2f__Unwind_0059cf2f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581750]
132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d058__Unwind_0059d058.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00583650]
133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d358__Unwind_0059d358.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind with DAT_008d4400]
134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d524__Unwind_0059d524.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_0059a9c2]

## RULES (same as before)
0. NEVER move, rename, or delete .c files.
1. Read docs/12, docs/13, and the triage index BEFORE starting.
2. Full ## FUN_XXXXXXXX entry for EVERY function — use address from filename, no exceptions.
3. Write `<!-- target: docs/XX-name.md -->` before EVERY ## FUN_ block (no double .md).
4. Append to %USERPROFILE%/Desktop/F1C_ghidra_project/analysis_pipeline/output/worker_B.md — do NOT overwrite existing content.
5. Leave === TRIAGE LINES === untouched.
6. ALWAYS use ## FUN_XXXXXXXX heading format — never ## Unwind_... or ## thunk_...
