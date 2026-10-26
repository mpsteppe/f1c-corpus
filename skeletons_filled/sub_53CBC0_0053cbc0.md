## sub_53CBC0_0053cbc0 — CubeMapMASFileLoader

**Summary:** Loads and validates a .MAS cube map file: searches registered path prefixes, reads 12-byte header magic, allocates and initializes a 308-byte physics object for Cubemas410 format. Links object into a linked list at offset 304 with global head at dword_8B8F14.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFieldClear (00494fe0), sub_49B0A0 (0049b0a0), CockpitDashboardLEDGaugeSetup (0049ca00), sub_49CD80 (0049cd80), PITANIMSMASAnimationFileLoader (004a3220), PitCrewAnimationMASSetup (004a3910), sub_4A4900 (004a4900), SpecialFX_Init (004cf070), sub_4D0110 (004d0110), sub_4D1450 (004d1450), sub_4D8AB0 (004d8ab0), sub_4DCBA0 (004dcba0), PitCrewInstanceSetup (004ddad0), sub_4F8D70 (004f8d70), sub_4FC550 (004fc550), ErrorHandlerSet (0053ce10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output pointer for allocated object (written if a1 non-null) |

**Written-by note (persistence):**
- this 0x0: conditional — written only if a1 non-null and allocation succeeds; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005c2d64 | aSS_3 | R | SessionConfigFile [DERIVED] |
| 005dbbd4 | aIncorrectMasFi | R | Err_IncorrectMassFile [DERIVED] |
| 005dbbf0 | aCubemas401 | R | Str_CubeMask401 [DERIVED] |
| 005dbbfc | aCubemas400 | R | StringCubeMas400 [DERIVED] |
| 005dbc08 | aCubemas410 | R | CubeMapFileName [DERIVED] |
| 005dbc14 | aErrorOpeningMa | R | StrErrorOpeningMa [DERIVED] |
| 008b5a3c | byte_8B5A3C | R | AudioEntryArray [DERIVED] (also: ` — entry array base (stride 0x84) |
| 008b6ac0 | dword_8B6AC0 | W | PhysicsObjectCount [DERIVED] |
| 008b8e30 | dword_8B8E30 | R | RegisteredEntryCount [DERIVED] (also: ` — entry count (max 0x20) |
| 008b8f14 | dword_8B8F14 | RW | ObjLinkedListHead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c590 | sub_53C590 | Error/log message handler |
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 0055fbe0 | sub_55FBE0 | Physics object initializer for 308-byte allocation |
| 0055fc40 | sub_55FC40 | Object registration/store by name string |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation wrapper for 308-byte object |
| 00587d02 | FileCloseWithLock | Thread-safe file close |
| 00587db0 | sub_587DB0 | File open wrapper (returns handle or 0) |
| 0058803f | ThreadSafeReadWrapper_803f | Thread-safe file read (12-byte header) |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting for path construction |
| 00589901 | sub_589901 | String transformation/canonicalization |

**Guard conditions:** Checks input string pointer and first byte: if NULL or empty string, returns 0 immediately. Checks file open result: if direct open fails, iterates registered path prefixes; if none produce a valid file handle, logs error and returns -2. Reads 12-byte header and compares magic: if "Cubemas410", processes as valid; if "Cubemas400" or "Cubemas401", logs "Incorrect MAS file" error and returns -1; otherwise returns 0. During object registration, checks sub_55FC40 result: -2/-1 trigger cleanup and return, 0 triggers linked-list insertion.
