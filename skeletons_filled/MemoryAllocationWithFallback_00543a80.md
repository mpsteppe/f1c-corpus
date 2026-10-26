## MemoryAllocationWithFallback_00543a80 — AudioStreamFallbackAllocation

**Summary:** Allocates two audio stream emitter handles (globals dword_8B8DBC, dword_8B8DC0) as fallback when primary stream initialization via sub_55B6B0 returns 0. Cleans up fallback emitters if sub_55B6B0 succeeds (non-zero return).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | flags/state field; bits 0x10800 set when fallback is active |

**Written-by note (persistence):**
- this 0xEC: bit 0x10800 OR'd in when fallback path taken; other bits survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8dbc | dword_8B8DBC | RW | audio stream handle A — allocated fallback emitter |
| 008b8dc0 | dword_8B8DC0 | RW | audio stream handle B — allocated fallback emitter |
| 008b8df4 | dword_8B8DF4 | R | width/dimension parameter for stream initialization |
| 008b8df8 | dword_8B8DF8 | R | flags/parameter for stream initialization |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005426a0 | AudioEmitterCreate | allocate and initialize audio emitter |
| 00542950 | UtilityFunction_2950 | configure stream mode and register emitter with SoundManager |
| 00542e50 | sub_542E50 | destroy/release audio emitter (cleanup on failure or after override) |
| 00557470 | EmptyStub_7470 | stub function (debug/reference) |
| 0055b6b0 | sub_55B6B0 | primary stream initialization; return 0 when fallback needed |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory wrapper |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 60-byte emitter objects |

**Guard conditions:** BLOCKED when a2 is 0 → return 0 immediately. BLOCKED when this[236] & 4 is set → skip emitter allocation entirely. If sub_55B6B0 returns non-zero → destroy both fallback emitters and return -1.
