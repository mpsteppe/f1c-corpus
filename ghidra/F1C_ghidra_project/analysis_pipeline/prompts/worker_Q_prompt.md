# WORKER Q — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker Q of 20, items 3089–3281.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_Q.md

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

## STEP 3 — YOUR FILES (193 functions)

3089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f6f2__thunk_FUN_00516959.c
   [category: Memory/Cleanup | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Thunk: call vtable dtor + null fields]
3090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005514a0__FUN_005514a0.c
   [category: Data/FlagUpdate | target: docs/20-math-utilities.md | lines: 13 | prior triage: Flag update with cascade]
3091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553310__FUN_00553310.c
   [category: Game/Resource | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Conditional resource cleanup]
3092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005550c0__FUN_005550c0.c
   [category: UI/Call | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Single vtable call getter]
3093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005575f0__FUN_005575f0.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Flag check with conditional path dispatch]
3094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb50__FUN_0055bb50.c
   [category: Data/FieldSet | target: docs/20-math-utilities.md | lines: 14 | prior triage: Dual field set to same value]
3095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d4f0__FUN_0055d4f0.c
   [category: UI/Property | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Set UI property group with chain update]
3096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561620__FUN_00561620.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Recursive tree node traversal]
3097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563020__FUN_00563020.c
   [category: System | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Multi-stage initialization chain with error checking]
3098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564740__FUN_00564740.c
   [category: Audio/Cleanup | target: docs/21-audio-network-internals.md | lines: 22 | prior triage: Destroy audio array, free elements then container]
3099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668b0__FUN_005668b0.c
   [category: Data/Init | target: docs/20-math-utilities.md | lines: 18 | prior triage: Zero-init small struct fields]
3100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568560__FUN_00568560.c
   [category: Text/Sanitize | target: docs/20-math-utilities.md | lines: 38 | prior triage: Replace special chars with underscore/hyphen]
3101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569a20__FUN_00569a20.c
   [category: Physics | target: docs/18-physics-dynamics.md | lines: 33 | prior triage: 3D angular momentum/torque accumulation with cross product]
3102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a1e0__FUN_0057a1e0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 18 | prior triage: Small struct field init (6 fields)]
3103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a8c0__FUN_0057a8c0.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Virtual dispatch wrapper]
3104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b780__FUN_0057b780.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Object init with vtable + field set]
3105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581750__FUN_00581750.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Handle close with cleanup]
3106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005833e0__FUN_005833e0.c
   [category: Memory/Cleanup | target: docs/01-engine-architecture.md | lines: 29 | prior triage: Walk linked list, call destructor, free nodes]
3107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585380__FUN_00585380.c
   [category: Engine/VTableCall | target: docs/01-engine-architecture.md | lines: 19 | prior triage: VTable dispatch with conditional call]
3108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586240__FUN_00586240.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 39 | prior triage: Linked-list destruction with SEH + alloc cleanup]
3109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f70__FUN_00586f70.c
   [category: Algo/BitOp | target: docs/20-math-utilities.md | lines: 22 | prior triage: Bit set/clear operation]
3110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876f0__FUN_005876f0.c
   [category: IO/CharWrite | target: docs/08-file-formats.md | lines: 14 | prior triage: Buffered char I/O wrapper]
3111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884e0__FUN_005884e0.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 15 | prior triage: TLS field setter]
3112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a163__FUN_0058a163.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 19 | prior triage: File write wrapper with lock]
3113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ab31__FUN_0058ab31.c
   [category: Threading/Lock | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Lock release by index]
3114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c38e__FUN_0058c38e.c
   [category: Sys/Handle | target: docs/20-math-utilities.md | lines: 44 | prior triage: Handle close with error reporting]
3115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e0c7__FUN_0058e0c7.c
   [category: Sys/TLS | target: docs/20-math-utilities.md | lines: 34 | prior triage: TLS value retrieval with init]
3116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e66__FUN_00591e66.c
   [category: Math/FPU | target: docs/20-math-utilities.md | lines: 13 | prior triage: Return FPU control word]
3117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005952e9__FUN_005952e9.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 20 | prior triage: 4-int copy]
3118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597fac__FUN_00597fac.c
   [category: System | target: docs/01-engine-architecture.md | lines: 31 | prior triage: WideChar→MultiByte string conversion with alloc loop]
3119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c4a__FUN_00598c4a.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Counter increment thread-safe]
3120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005994bc__FUN_005994bc.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 35 | prior triage: Object initialization with buffer/bounds setup]
3121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599933__FUN_00599933.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
3122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a473__FUN_0059a473.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Object init with buffer/data pointer assignment]
3123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ad3d__FUN_0059ad3d.c
   [category: Memory/Free | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Free callback registered cleanup]
3124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bf56__FUN_0059bf56.c
   [category: String/Copy | target: docs/20-math-utilities.md | lines: 29 | prior triage: Strlen + alloc + copy constructor pattern]
3125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c52c__Unwind_0059c52c.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c65c__Unwind_0059c65c.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
3127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d8__Unwind_0059c7d8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c910__Unwind_0059c910.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb40__Unwind_0059cb40.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cceb__Unwind_0059cceb.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x10]
3131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cec9__Unwind_0059cec9.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
3132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d02e__Unwind_0059d02e.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
3133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d190__Unwind_0059d190.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3a8__Unwind_0059d3a8.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: --]
3135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d580__Unwind_0059d580.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
3136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403540__FUN_00403540.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 55 | prior triage: short computation]
3137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404e60__FUN_00404e60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 47 | prior triage: short computation]
3138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b50__FUN_00405b50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407070__FUN_00407070.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 45 | prior triage: short computation]
3140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408280__FUN_00408280.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ad60__FUN_0040ad60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 27 | prior triage: short computation]
3142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cdd0__FUN_0040cdd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1c0__FUN_0040e1c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f130__FUN_0040f130.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 35 | prior triage: short computation]
3145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411650__FUN_00411650.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414420__FUN_00414420.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 40 | prior triage: short computation]
3147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418970__FUN_00418970.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041efe0__FUN_0041efe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 36 | prior triage: short computation]
3149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004218d0__FUN_004218d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423459__FUN_00423459.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 25 | prior triage: short computation]
3151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004526c0__FUN_004526c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
3152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560c0__FUN_004560c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004594d0__FUN_004594d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 34 | prior triage: short computation]
3154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb60__FUN_0045bb60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c780__FUN_0045c780.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045eb00__FUN_0045eb00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461db0__FUN_00461db0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004627c0__FUN_004627c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: unidentified]
3159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004646c0__FUN_004646c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464ee0__FUN_00464ee0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662c0__FUN_004662c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469880__FUN_00469880.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c750__FUN_0046c750.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
3164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ee60__FUN_0046ee60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified]
3165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004706f0__FUN_004706f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004726c0__FUN_004726c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473fd0__FUN_00473fd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476030__FUN_00476030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004780b0__FUN_004780b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479690__FUN_00479690.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479bd0__FUN_00479bd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a580__FUN_0047a580.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0a0__FUN_0047c0a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
3174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f3d0__FUN_0047f3d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485960__FUN_00485960.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified]
3176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486540__FUN_00486540.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487400__FUN_00487400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified]
3178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488180__FUN_00488180.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489530__FUN_00489530.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048bbe0__FUN_0048bbe0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified]
3181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3a0__FUN_0048d3a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e860__FUN_0048e860.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fdb0__FUN_0048fdb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: unidentified]
3184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490940__FUN_00490940.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 95 | prior triage: unidentified]
3185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004918d0__FUN_004918d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
3186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494470__FUN_00494470.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495190__FUN_00495190.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 75 | prior triage: unidentified]
3188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004967d0__FUN_004967d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified]
3189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979e0__FUN_004979e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498df0__FUN_00498df0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 30 | prior triage: short computation]
3191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004993d0__FUN_004993d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 63 | prior triage: unidentified]
3192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ae0__FUN_00499ae0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e80__FUN_00499e80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a460__FUN_0049a460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afb0__FUN_0049afb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e490__FUN_0049e490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 33 | prior triage: short computation]
3197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049fdb0__FUN_0049fdb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
3198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11e0__FUN_004a11e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a27d0__FUN_004a27d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40e0__FUN_004a40e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004aa1b0__FUN_004aa1b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1ab0__FUN_004b1ab0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2800__FUN_004b2800.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2bf0__FUN_004b2bf0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4460__FUN_004b4460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5630__FUN_004b5630.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
3207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d00__FUN_004b9d00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba900__FUN_004ba900.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb400__FUN_004bb400.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd760__FUN_004bd760.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf630__FUN_004bf630.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2830__FUN_004c2830.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3020__FUN_004c3020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c10__FUN_004c7c10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85d0__FUN_004c85d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9310__FUN_004c9310.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb540__FUN_004cb540.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0040__FUN_004d0040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4800__FUN_004d4800.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7800__FUN_004d7800.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7f60__FUN_004d7f60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9290__FUN_004d9290.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
3223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc0b0__FUN_004dc0b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
3224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcda0__FUN_004dcda0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd9f0__FUN_004dd9f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
3226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2540__FUN_004e2540.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified logic]
3227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed7b0__FUN_004ed7b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6d90__FUN_004f6d90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
3229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d10__FUN_004f8d10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f60__FUN_004f9f60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd7e0__FUN_004fd7e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050070d__FUN_0050070d.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
3233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503659__FUN_00503659.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005064bf__FUN_005064bf.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae92__FUN_0050ae92.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b75f__FUN_0050b75f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2e3__FUN_0050c2e3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: unidentified logic]
3238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d615__FUN_0050d615.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified logic]
3239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e2ab__FUN_0050e2ab.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fab7__FUN_0050fab7.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005118c1__FUN_005118c1.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b12__FUN_00513b12.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515927__FUN_00515927.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516883__FUN_00516883.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
3245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f04__FUN_00517f04.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c653__FUN_0051c653.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified logic]
3247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521895__FUN_00521895.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified logic]
3248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529000__FUN_00529000.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 41 | prior triage: unidentified logic]
3249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e170__FUN_0052e170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005352d0__FUN_005352d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537eb0__FUN_00537eb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b200__FUN_0053b200.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c360__FUN_0053c360.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: unidentified logic]
3254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d260__FUN_0053d260.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005401a0__FUN_005401a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: unidentified logic]
3256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542490__FUN_00542490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00545020__FUN_00545020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005471c0__FUN_005471c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487e0__FUN_005487e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549440__FUN_00549440.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c030__FUN_0054c030.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
3262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc40__FUN_0054fc40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553620__FUN_00553620.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: Setter: writes param_2 to struct+0x10, returns 0]
3264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005597c0__FUN_005597c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 47 | prior triage: Binary tree search — walking +0x1c link, 2-byte compare]
3265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d230__FUN_0055d230.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 37 | prior triage: Struct initializer with float defaults (1.0f, -1.0f)]
3266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564810__FUN_00564810.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: Malloc 0x18-byte struct with params, alloc inner buffer]
3267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a30__FUN_00567a30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: Linked list destructor with memory free]
3268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a330__FUN_0057a330.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: Struct field serializer/packer into buffer]
3269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6b0__FUN_0057b6b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: returns param_1 + 0x20]
3270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585cc0__FUN_00585cc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter at +0x78]
3271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587500__FUN_00587500.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: struct field setter: zero at +0x8]
3272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005888a6____local_unwind2.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 41 | prior triage: __local_unwind2 — MSVCRT SEH frame unwinder]
3273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058afcf__FUN_0058afcf.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: calls FUN_0058e0c7() + 8]
3274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590616__FUN_00590616.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 21 | prior triage: Count alphabetical chars in string]
3275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059567d__FUN_0059567d.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 48 | prior triage: Float80-to-float64 unpack — denorm/norm/NaN branch]
3276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987d0__FUN_005987d0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static arg]
3277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d31__uflow.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: --]
3278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c414__Unwind_0059c414.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
3279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c980__Unwind_0059c980.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581880]
3280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d058__Unwind_0059d058.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00583650]
3281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059da3a__FUN_0059da3a.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper]

---

## FULL ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: filename.cpp | Confidence: high/medium/low
One-line summary of what this function does.

**Key logic:**
- What it does step by step
- All constants, thresholds, formulas with exact values
- All branches and what triggers each path
- For math: name the algorithm (dot product, cross product, lerp, clamp, normalize,
  matrix multiply, quaternion op, euler angles, bezier, PID, etc.)
- For wrappers: what CRT/Win32/library function is wrapped and why

**Struct offsets (param_1):**
| Offset | Field name (from docs/13 if known) | Type | Notes |
|--------|-------------------------------------|------|-------|
| +0xXXX | VehicleStruct.FieldName or unknown  | float/int/double | purpose |

**Globals:**
- `DAT_007c56a4` (SessionType) — read/written [use known name from docs/12]

**Calls:**
- FUN_00AAAAAA — [look up in triage index or docs/; cite name if known] what it does
- FUN_00BBBBBB — what it does

**Used by system:** docs/XX-name.md — [which documented game system likely calls this;
  infer from: what the function does, what globals/structs it touches, what it calls,
  and what nearby documented functions (same address range) belong to]

**Algorithm family:** [math_util only] e.g. "3D vector math", "quaternion ops",
  "matrix transform", "spline/bezier", "PID controller", "audio DSP", "collision geometry"

**Moddability:** configurable | hardcoded | hookable
```

---

## SOURCE FILE INFERENCE

Functions compiled from the same .cpp file cluster in consecutive address ranges.
To infer source file for a function at address 0x00XXXXXX:
1. Check for assert strings in the code — they contain the real source path directly.
2. Look at nearby documented functions (same 0x00XX__ prefix) in docs/ or the triage
   index — if they have a known source, this function likely shares it.
3. Use what the function does + what it calls to guess the module
   (tire math → tire_model.cpp, network packet → NetSocket.cpp, etc.).
4. If none of the above: write `Source: unknown`.

---

## RULES BY PRIOR CATEGORY

`math_util` — Name the algorithm. Document input/output types and all constants.
  Even "returns param_1 + 100": what is 100? An offset? A bias? An enum base?
  Tag the algorithm family so related functions can be clustered later.

`unknown` — Read the code mechanically. List every struct access, every called function,
  every constant. Write what you observe. Include a confidence level. Even "unknown purpose,
  reads +0x3C and +0x40 from param_1, multiplies by 0.5" is valuable for consensus.

`crt_util` / library wrappers — Name the wrapped function. Note calling convention,
  parameter forwarding, and why this wrapper exists at this address in the binary.

Thunks (unconditional jmp to another function):
```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Thunk to FUN_YYYYYYYY

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_YYYYYYYY. No local logic.

**Key logic:**
- Single jmp instruction; address 0x00XXXXXX appears in a vtable, IAT, or call stub
- Call target: FUN_YYYYYYYY [look up its name in docs/ or triage index if available]

**Calls:** FUN_YYYYYYYY (target — [name if known])

**Used by system:** [infer from what FUN_YYYYYYYY does]

**Moddability:** hardcoded
```

Empty stubs (body is return only):
```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Empty Stub

Source: unknown | Confidence: high
Returns immediately with no logic. Placeholder or stripped virtual method.

**Key logic:**
- No operations — bare return
- Address 0x00XXXXXX is referenced somewhere (vtable slot, callback registration)
- Likely a virtual method that was never implemented or was stripped at link time

**Used by system:** [infer from address range neighbors]

**Moddability:** hardcoded
```

Non-standard category labels (GameLogic, Render, Physics, Entity, etc.):
treat as the equivalent standard category.

---

## GHIDRA PATTERN DECODING

- `*(double *)(ptr + 0x1330)` → offset +0x1330, type double — check docs/13
- `param_1[0x4a]` → int-indexed: byte offset = 0x4a × 4 = 0x128 — check docs/13
- `unaff_EBX` / `unaff_ESI` / `unaff_EBP` → register-allocated `this` pointer
- `goto` chains → MSVC loop artifact — ignore the goto, document the loop logic
- `thunk_FUN_XXXXXX` → trampoline wrapper — document as thunk
- `DAT_XXXXXXXX` → global variable — resolve name from docs/12 before writing

---

## TARGET ROUTING

Use the suggested target in your file list. Override only if the code clearly
belongs to a different system:
- game_logic / entity / engine → docs/01 through 10 (match the system)
- collision → docs/17-physics-collision.md
- physics_math / dynamics → docs/18-physics-dynamics.md
- renderer / graphics → docs/19-renderer.md
- math_util / unknown / CRT / misc → docs/20-math-utilities.md
- audio / network → docs/21-audio-network-internals.md
- file I/O / formats → docs/08-file-formats.md

---

## RULES

0. NEVER move, rename, or delete .c files.
1. Read docs/12, docs/13, and the triage index BEFORE processing any function.
2. Write a full ## FUN_ entry for EVERY file — no exceptions, no one-liners.
3. Write `<!-- target: docs/XX-name.md -->` before EVERY `## FUN_` block.
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_Q.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
