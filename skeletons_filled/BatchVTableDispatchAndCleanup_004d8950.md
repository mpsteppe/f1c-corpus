## BatchVTableDispatchAndCleanup_004d8950 — Batch release and cleanup

**Summary:** Releases all Direct3D/render objects (25 + 3 + 2) by dispatching vtable method at offset 0 with parameter 1 (release/free), then nulls each pointer. Counterpart to sub_4D88D0 allocation. Called during cleanup/shutdown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x0 | R | — | Vtable dispatch on D3D object 0: calls release method (first vtable entry) |
| *(*(this+0x74)+0x0) | 0x0 | R | — | Vtable dispatch on sub-object 0: calls release method |
| *(this+0x10) | 0x0 | R | — | Pointer to first D3D object in array (25 items) |
| *(this+0x74) | 0x0 | R | — | Pointer to first sub-object in array (3 items) |
| *(this+0xC) | 0x0 | R | — | Pointer to conditional object (RangeCheck-gated) |
| *(this+0xD8) | 0x0 | R | — | Pointer to fixed node allocator object |
| this | 0xC | RW | 0 | Cleared to null after release |
| this | 0x10 | RW | 0 | Cleared to null after release (array start) |
| this | 0x74 | RW | 0 | Cleared to null after release (array start) |
| this | 0xD8 | RW | 0 | Cleared to null after release |

**Written-by note (persistence):**
- this 0xC: Set to 0 after release; conditional on non-null before write.
- this 0x10: Each of 25 slots set to 0 after release; slot must be non-null to trigger release.
- this 0x74: Each of 3 slots set to 0 after release; slot must be non-null to trigger release.
- this 0xD8: Set to 0 after release; conditional on non-null before write.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each pointer (25 array slots, 3 sub-array slots, 2 singletons) checked for null before dispatch. Non-null → vtable[0](obj, 1) called and pointer nulled. Null → skipped.
