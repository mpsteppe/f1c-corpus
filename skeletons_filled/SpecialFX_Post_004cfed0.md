## SpecialFX_Post_004cfed0 — SpecialFX_Post

**Summary:** Tears down special effects system — frees all allocated particle/emitter arrays with type-specific cleanup, cleans collision tree nodes, zeroes all struct fields. Called when leaving the game session.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | emitter count (zeroed) |
| this | 0x4 | RW | 0 | pointer to 60-byte stride particle array (freed, zeroed) |
| this | 0x8 | RW | 0 | secondary array count (zeroed) |
| this | 0xC | RW | 0 | pointer to 108-byte stride array (freed, zeroed) |
| this | 0x10 | RW | 0 | third array count for Free loop (zeroed) |
| this | 0x14 | RW | 0 | pointer to 108-byte stride array (freed, zeroed) |
| this | 0x18 | RW | 0 | particle spawner pointer (zeroed) |
| this | 0x1C | RW | 0 | particle spawner pointer (zeroed) |
| this | 0x20 | RW | 0 | field 0x20 (zeroed) |
| this | 0x24 | RW | 0 | field 0x24 (zeroed) |
| this | 0x28 | RW | 0 | field 0x28 (zeroed) |
| this | 0x2C | RW | 0 | field 0x2C (zeroed) |

**Written-by note (persistence):**
- this 0x0: unconditionally zeroed, no external survival
- this 0x4: unconditionally freed and zeroed, no external survival
- this 0x8: unconditionally zeroed, no external survival
- this 0xC: unconditionally freed and zeroed, no external survival
- this 0x10: unconditionally zeroed, no external survival
- this 0x14: unconditionally freed and zeroed, no external survival
- this 0x18: unconditionally zeroed, no external survival
- this 0x1C: unconditionally zeroed, no external survival
- this 0x20: unconditionally zeroed, no external survival
- this 0x24: unconditionally zeroed, no external survival
- this 0x28: unconditionally zeroed, no external survival
- this 0x2C: unconditionally zeroed, no external survival

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d39f0 | aEnteredSpecial_3 | R | Str_EnteredSpecial_3 [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c470 | CollisionTreeNodeCleanup | clean up collision tree nodes |
| 00499ae0 | FreeIfNonNull | free memory if pointer is non-null |
| 004ca280 | sub_4CA280 | cleanup single 60-byte stride entry |
| 004ca410 | sub_4CA410 | cleanup single 108-byte stride entry |
| 004cb4f0 | MultiFieldFree | free multiple embedded fields in an entry |
| 004d7a50 | StringSplitLoop | conditional debug/log trace trigger |
| 004d7aa0 | DebugLogWrite | write debug log message to buffer |
| 00587bcf | FreeWrapper_7bcf | free allocated memory block |

**Guard conditions:** None at function entry — always executes full cleanup. Inner guards check each array pointer for non-null before freeing.
