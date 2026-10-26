## AudioResourceReleaseByType_004d9030 — Release resource by type

**Summary:** Releases a render/audio resource identified by type index (1-5) from the global handle array (dword_8AD398–8AD3A8). Type 3 additionally releases an associated extra struct (dword_8AD3AC) via destructor and memory free. Nulls handles after release.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_8720 (004d8720), sub_4D8CF0 (004d8cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d90bc | jpt_4D903E | R | Switch jump table for a1 (1-5 dispatch) |
| 008ad398 | dword_8AD398 | R | StateHandleArray [DERIVED] — handle for type 1 |
| 008ad39c | dword_8AD39C | R | RenderBufferID_2 [DERIVED] — handle for type 2 |
| 008ad3a0 | dword_8AD3A0 | R | AudioEmitter_Idx3 [DERIVED] — handle for type 3 |
| 008ad3a4 | dword_8AD3A4 | R | AudioChannel4 [DERIVED] — handle for type 4 |
| 008ad3a8 | flt_8AD3A8 | R | AudioStreamHandle [DERIVED] — handle for type 5 |
| 008ad3ac | dword_8AD3AC | RW | TrackDB_DataPtr [DERIVED] — extra struct for type 3, released separately |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005502c0 | DestructorWithConditionalFreeFlagClear | Destructor for type 3 extra struct before free |
| 005539f0 | ResourceCascadeCleanup | Cascading resource cleanup for the main handle |
| 00557470 | EmptyStub_7470 | Stub called before FreeWrapper (cleanup step) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation for type 3 extra struct |

**Guard conditions:** `a1` outside [1-5] → no-op. Each handle (cases 1-5): null-checked before ResourceCascadeCleanup call. Type 3 only: `dword_8AD3AC` null-checked before destructor, then internal null check before FreeWrapper_7bcf.
