# WORKER K — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker K of 20, items 1931–2123.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_K.md

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

1931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdf9__thunk_FUN_0050cdec.c
   [category: Thunk | target: docs/20-math-utilities.md | lines: 16 | prior triage: Indirect jump via global function pointer]
1932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550800__FUN_00550800.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Dual field zero-init]
1933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005528f0__FUN_005528f0.c
   [category: UI/Cleanup | target: docs/01-engine-architecture.md | lines: 14 | prior triage: Conditional UI cleanup dispatch]
1934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005546a0__FUN_005546a0.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Multi-field setter dispatching to 7 sub-setters]
1935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556930__FUN_00556930.c
   [category: Game/Traversal | target: docs/01-engine-architecture.md | lines: 28 | prior triage: Recursive state traversal with flag check]
1936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559630__FUN_00559630.c
   [category: Data/LinkedList | target: docs/20-math-utilities.md | lines: 49 | prior triage: Linked list node search & allocation]
1937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055cee0__FUN_0055cee0.c
   [category: Graphics/Color | target: docs/19-renderer.md | lines: 20 | prior triage: RGB color space compaction to 16-bit]
1938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560ba0__FUN_00560ba0.c
   [category: Game/ObjInit | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Object init with parameter linking]
1939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562890__FUN_00562890.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Buffer zero-init with virtual method call]
1940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564530__FUN_00564530.c
   [category: Data/Compare | target: docs/20-math-utilities.md | lines: 35 | prior triage: String comparison with constant, dispatch]
1941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565d50__FUN_00565d50.c
   [category: Data/ListCleanup | target: docs/20-math-utilities.md | lines: 31 | prior triage: Enhanced list cleanup with sub-object delete]
1942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567980__FUN_00567980.c
   [category: Data/ListCount | target: docs/20-math-utilities.md | lines: 18 | prior triage: Linked list count]
1943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569670__FUN_00569670.c
   [category: Physics | target: docs/18-physics-dynamics.md | lines: 50 | prior triage: 3D vector cross-product rotation accumulation]
1944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a020__FUN_0057a020.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 23 | prior triage: Struct zero-init (4 + 8 words)]
1945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a750__FUN_0057a750.c
   [category: Dispatch | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
1946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b050__FUN_0057b050.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 49 | prior triage: Linked list node removal with memory free]
1947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dbb0__FUN_0057dbb0.c
   [category: UI | target: docs/01-engine-architecture.md | lines: 23 | prior triage: Vtable call + format disp + timer dispatch chain]
1948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582b10__FUN_00582b10.c
   [category: Data/LinkedList | target: docs/20-math-utilities.md | lines: 49 | prior triage: Linked list element removal with cleanup]
1949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584f30__FUN_00584f30.c
   [category: Threading/Sync | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Mutex-protected function call with wait]
1950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585f60__FUN_00585f60.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Mutex wait with success check]
1951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d00__FUN_00586d00.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Bitmap range occupancy test via bit ops]
1952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005874d0__FUN_005874d0.c
   [category: Memory/Alloc | target: docs/01-engine-architecture.md | lines: 15 | prior triage: operator new with result check]
1953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f59__FUN_00587f59.c
   [category: Dispatch | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
1954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d62__ExitProcess.c
   [category: Library | target: docs/20-math-utilities.md | lines: 14 | prior triage: ExitProcess stub]
1955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a6eb__FUN_0058a6eb.c
   [category: Except | target: docs/01-engine-architecture.md | lines: 28 | prior triage: N-time callback loop with SEH]
1956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bef0__FUN_0058bef0.c
   [category: Text/Format | target: docs/20-math-utilities.md | lines: 18 | prior triage: Int-to-string with sign + position draw]
1957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dce5____fload_withFB.c
   [category: Library | target: docs/20-math-utilities.md | lines: 22 | prior triage: __fload_withFB — float load with NaN check]
1958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059083b____ctrandisp1.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: --]
1959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c9c__FUN_00593c9c.c
   [category: Exception/SEH | target: docs/01-engine-architecture.md | lines: 30 | prior triage: SEH wrapper dispatching to handler function]
1960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597321__FUN_00597321.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: IsBadReadPtr wrapper]
1961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598aa0__FUN_00598aa0.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 28 | prior triage: Status check with error dispatch]
1962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992b7__FUN_005992b7.c
   [category: Data/Dtor | target: docs/20-math-utilities.md | lines: 15 | prior triage: Destructor with flag cleanup]
1963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059987c__FUN_0059987c.c
   [category: Locale/Call | target: docs/20-math-utilities.md | lines: 12 | prior triage: Locale function call wrapper]
1964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a3a9__FUN_0059a3a9.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 24 | prior triage: Stream creation with flag init]
1965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a9c2__FUN_0059a9c2.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
1966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bacc__FUN_0059bacc.c
   [category: Exception/Dtor | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Exception destructor with conditional free]
1967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4c8__Unwind_0059c4c8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
1968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c60c__Unwind_0059c60c.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +8]
1969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c706__Unwind_0059c706.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +8]
1970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c896__Unwind_0059c896.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
1971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca80__Unwind_0059ca80.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
1972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc6b__Unwind_0059cc6b.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
1973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce60__Unwind_0059ce60.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
1974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfbe__Unwind_0059cfbe.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
1975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d110__Unwind_0059d110.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
1976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2e4__Unwind_0059d2e4.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
1977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d508__Unwind_0059d508.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
1978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401030__FUN_00401030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
1979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404b50__FUN_00404b50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
1980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004056a0__FUN_004056a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 52 | prior triage: memory allocation]
1981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406a90__FUN_00406a90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
1982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004080f0__FUN_004080f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 51 | prior triage: short computation]
1983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
1984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c610__FUN_0040c610.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 26 | prior triage: short computation]
1985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dbc0__FUN_0040dbc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
1986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040eb30__FUN_0040eb30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 33 | prior triage: short computation]
1987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b20__FUN_00410b20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
1988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141a0__FUN_004141a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: short computation]
1989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415730__FUN_00415730.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 25 | prior triage: short computation]
1990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041a160__FUN_0041a160.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
1991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004212e0__FUN_004212e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 46 | prior triage: short computation]
1992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a90__FUN_00421a90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
1993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426330__FUN_00426330.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 48 | prior triage: short computation]
1994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455bd0__FUN_00455bd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
1995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457f90__FUN_00457f90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 44 | prior triage: unidentified]
1996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b9a0__FUN_0045b9a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
1997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c030__FUN_0045c030.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified]
1998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d730__FUN_0045d730.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 65 | prior triage: unidentified]
1999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461560__FUN_00461560.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: unidentified]
2000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004623b0__FUN_004623b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463ca0__FUN_00463ca0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464b40__FUN_00464b40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 25 | prior triage: float computation]
2003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466140__FUN_00466140.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00468090__FUN_00468090.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b580__FUN_0046b580.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e170__FUN_0046e170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470170__FUN_00470170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471970__FUN_00471970.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473c40__FUN_00473c40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475120__FUN_00475120.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004775f0__FUN_004775f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478690__FUN_00478690.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479940__FUN_00479940.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a190__FUN_0047a190.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bcf0__FUN_0047bcf0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 55 | prior triage: unidentified]
2016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047eff0__FUN_0047eff0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004856c0__FUN_004856c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004863c0__FUN_004863c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004870e0__FUN_004870e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified]
2020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487d70__FUN_00487d70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: unidentified]
2021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004893c0__FUN_004893c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
2022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b560__FUN_0048b560.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified]
2023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d0d0__FUN_0048d0d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified]
2024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e300__FUN_0048e300.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fb70__FUN_0048fb70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490390__FUN_00490390.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004916e0__FUN_004916e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e60__FUN_00491e60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004950c0__FUN_004950c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b30__FUN_00495b30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004977e0__FUN_004977e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
2032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988d0__FUN_004988d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified]
2033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499180__FUN_00499180.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499910__FUN_00499910.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 70 | prior triage: unidentified]
2035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e10__FUN_00499e10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2c0__thunk_FUN_00566650.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 42 | prior triage: trampoline/thunk]
2037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adb0__FUN_0049adb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d700__FUN_0049d700.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 46 | prior triage: unidentified]
2039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f070__FUN_0049f070.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0dc0__FUN_004a0dc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: system/OS API call]
2041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f80__FUN_004a1f80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3fe0__FUN_004a3fe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6ff0__FUN_004a6ff0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b19f0__FUN_004b19f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2420__FUN_004b2420.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b00__FUN_004b2b00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b41b0__FUN_004b41b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5040__FUN_004b5040.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9a10__FUN_004b9a10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba780__FUN_004ba780.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bafc0__FUN_004bafc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: memory allocation]
2052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2a0__FUN_004bc2a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
2053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdf90__FUN_004bdf90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1e40__FUN_004c1e40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 2 | prior triage: utility function]
2055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2dc0__FUN_004c2dc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: arithmetic/comparison]
2056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5db0__FUN_004c5db0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8350__FUN_004c8350.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9000__FUN_004c9000.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca3e0__FUN_004ca3e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cef30__FUN_004cef30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2e20__FUN_004d2e20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c40__FUN_004d5c40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7dd0__FUN_004d7dd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8a30__FUN_004d8a30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified logic]
2065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db9a0__FUN_004db9a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
2066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcb70__FUN_004dcb70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
2067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4d0__FUN_004dd4d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfbb0__FUN_004dfbb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea010__FUN_004ea010.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f3490__FUN_004f3490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c00__FUN_004f8c00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9ad0__FUN_004f9ad0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc870__FUN_004fc870.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500170__FUN_00500170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005029e5__FUN_005029e5.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050427d__FUN_0050427d.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 34 | prior triage: unidentified logic]
2077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab19__FUN_0050ab19.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b409__FUN_0050b409.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c0a6__FUN_0050c0a6.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0af__FUN_0050d0af.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050de19__FUN_0050de19.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f632__FUN_0050f632.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051166b__FUN_0051166b.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: arithmetic/comparison]
2084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005123e0__FUN_005123e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051512c__FUN_0051512c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051641e__FUN_0051641e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179e0__FUN_005179e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a794__FUN_0051a794.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2089. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ec40__FUN_0051ec40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
2090. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005276c5__FUN_005276c5.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2091. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052de40__FUN_0052de40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2092. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534d50__FUN_00534d50.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: unidentified logic]
2093. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536260__FUN_00536260.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2094. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b0d0__FUN_0053b0d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2095. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c190__FUN_0053c190.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2096. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cb20__FUN_0053cb20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2097. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ead0__FUN_0053ead0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: unidentified logic]
2098. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541cd0__FUN_00541cd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
2099. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543540__FUN_00543540.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2100. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546f70__FUN_00546f70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2101. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005477f0__FUN_005477f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2102. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549170__FUN_00549170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2103. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4a0__FUN_0054b4a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
2104. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eaf0__FUN_0054eaf0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: arithmetic/comparison]
2105. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005507a0__FUN_005507a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: Struct zero-initializer — zeros 7 fields, calls FUN_0053b490]
2106. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557280__FUN_00557280.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: Cleanup function — frees *(param_1+0x20c), calls FUN_004b0170]
2107. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c440__FUN_0055c440.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: stub returning 0]
2108. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563eb0__FUN_00563eb0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]
2109. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566f40__FUN_00566f40.c
   [category: Math | target: docs/20-math-utilities.md | lines: 46 | prior triage: 3x3 rotation matrix from quaternion]
2110. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056ec70__FUN_0056ec70.c
   [category: Math | target: docs/20-math-utilities.md | lines: 44 | prior triage: Matrix identity initialization (8-byte doubles)]
2111. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae00__FUN_0057ae00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_0057ae10)]
2112. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585020__FUN_00585020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: returns param_1 + 100]
2113. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587210__FUN_00587210.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter: byte at +0x18]
2114. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058803f__FUN_0058803f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: Thread-safe wrapper — lock (FUN_0058c1b1), call FUN_0058806e, unlock]
2115. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a88f__FUN_0058a88f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: NaN check: tests exponent bits 0x7ff0]
2116. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd28__FUN_0058dd28.c
   [category: Math | target: docs/20-math-utilities.md | lines: 14 | prior triage: Float exponent extract with NaN guard]
2117. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059525d__FUN_0059525d.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 35 | prior triage: Bit array — clear bit and zero-fill subsequent words]
2118. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986bf__FUN_005986bf.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static arg]
2119. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059985c__FUN_0059985c.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static arg]
2120. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b758__FUN_0059b758.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter at +0x10]
2121. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7fc__Unwind_0059c7fc.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_005822b0]
2122. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cef5__Unwind_0059cef5.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00586170]
2123. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d738__FUN_0059d738.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: Double subtraction via unaff_ESI — subtracts double at param_2+100 from ESI+0x28]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_K.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
