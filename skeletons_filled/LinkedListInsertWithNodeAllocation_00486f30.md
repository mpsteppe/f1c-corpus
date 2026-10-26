## LinkedListInsertWithNodeAllocation_00486f30 — StringListInsertOrReplace

**Summary:** Manages a linked list of string nodes. If a3 ≤ 0, allocates a new string node and prepends it to the list. If a3 > 0, seeks to that index and replaces the string content at that position. Part of UI string list management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigObjectDestructor (00466a70), HTMLOutputSectionProcessor (00467f90), HTMLResultsStatsPageWorldChampionships (00468910), CareerModeDriverStatsReset (00468a00), PlayerStatsDisplayCleanup (00469d30), StandingsDisplay (0046a560), SessionEntryListCleanup (0046ae60), UIScreenConstructor (00470670), UIListOptionsConstructor (004706f0), SelectedSeasonUIInit (00470850), ObjectInitWithVTablePathRegistration (00470af0), ObjectConstructorWithGlobalReferences (00470cc0), UICameraConstructor (00470d30), ShortComputation_1540 (00471540), ShortComputation_15d0 (004715d0), ConstructorLEDIndicatorSetup (00471650), GraphicsConstructorWithConstants (004716d0), ObjectInitializerWithGlobals (00471750), ComplexConstructor (004717e0), ObjectConstructorWithVTableAndFieldInit (00471860), sub_4718E0 (004718e0), ShortComputation_1970 (00471970), ObjectConstructor_1a00 (00471a00), UIObjectConstructorWithDefaults (00471b20), StringPathResolutionWithFallback (00472720), sub_472A80 (00472a80), ShortComputation_3330 (00473330), ReferencesGlobalState_33a0 (004733a0), ConstructorSimilarUIElement (00473430), GraphicsConstructor (004734a0), Constructor (00473b00), ShortComputation_3c40 (00473c40), ObjectConstructor_3cc0 (00473cc0), UIObjectConstructor (00473dd0), ObjectInitWithGlobalRef (00473e50), ConstructorWithDefaults (00473ed0), UIScreenConstructor_3f50 (00473f50), UIOptionsConstructor_3fd0 (00473fd0), ObjectInitWithVTableRenderStateConfig (004742a0), sub_474440 (00474440), UICameraConstructor2 (00474900), ConstructorWithMultipleFieldInitsAndGlobalRef (00474ba0), ObjectConstructorWithVTableAndResourceReg (00474f40), sub_47DAF0 (0047daf0), DriverCareerStatsHTMLWriter (0047dd10), sub_47E0A0 (0047e0a0), sub_47E440 (0047e440), GameOptionsUIConstructor (0047e960)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | — | head pointer of linked list |
| this | 0x48 | RW | — | tail pointer of linked list |
| this | 0x4C | RW | 0 | current/iterator pointer (initialized 0) |
| this | 0x50 | R | — | count of elements in list |

**Written-by note (persistence):**
- this 0x44: set on first insertion (prepend path) or unchanged; external poke overwritten on prepend
- this 0x48: updated every prepend (becomes new tail); overwritten each call
- this 0x4C: set to new node on prepend, or updated to seek target on replace; overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copy/replace string content into a string node |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 8-byte string node or 12-byte list entry |

**Guard conditions:** 1) If a3 ≤ 0 → prepend path: allocates string node (8 bytes) and list entry (12 bytes). Guarded by null checks on allocations — if either fails, insert is skipped. 2) If a3 > 0 → seek path: if a3 >= count (this[20]), set current (this[19]) to null and skip replacement. If index exists, seek to node and replace string if it has a data pointer.
