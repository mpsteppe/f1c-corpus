## SoundEffectStateCallback_0051be7d — Sound effect state transition handler

**Summary:** Handles state transitions for a sound effect audio object. Selects the appropriate ring buffer function (read/write/render dispatch) based on state parameter a2, allocates buffer on first use, and resets ring buffer position on each transition.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x188) | 0x4 | RW | — | v3[1]: Function pointer for buffer operations (set to read/write/dispatch) |
| *(this+0x188) | 0x8 | R | — | v3[2]: State flag — checked for 0 to trigger default method |
| *(this+0x188) | 0xC | RW | — | v3[3]: Allocated buffer address |
| *(this+0x188) | 0x10 | R | — | v3[4]: Buffer capacity/size |
| *(this+0x188) | 0x14 | RW | 0 | v3[5]: Accumulated offset counter (reset to 0 on transition) |
| *(this+0x188) | 0x18 | RW | 0 | v3[6]: Ring buffer position (reset to 0 on transition) |
| *(this+0x19C) | 0x4 | R | — | Fallback function pointer for v3[1] when a2==0 and flag not set |
| *(this+0x4) | 0x1C | R | — | Vtable method at offset 0x1C: buffer allocation function |
| obj | 0x0 | R | — | Object vtable pointer (used to dispatch default method) |
| obj | 0x14 | RW | 4 | State field written to 4 (stopped/error state indicator) |
| this | 0x0 | R | — | Vtable pointer (first DWORD) |
| this | 0x4 | R | — | Vtable pointer (second DWORD) |
| this | 0x4A | R | — | Flag byte — checked for non-zero to determine state 0 path |
| this | 0x188 | R | — | Pointer to ring buffer sub-struct (v3) |
| this | 0x19C | R | — | Base pointer for fallback function pointer access |

**Written-by note (persistence):**
- *(this+0x188) 0x4: Written each call based on state. Function pointer — survives external pokes but gets overwritten next transition.
- *(this+0x188) 0xC: Written only when buffer not yet allocated (v3[3]==0). Survives pokes after allocation.
- *(this+0x188) 0x14: Reset to 0 on every call. External pokes survive only until next transition.
- *(this+0x188) 0x18: Reset to 0 on every call. External pokes survive only until next transition.
- obj 0x14: Written to 4 when v3[2]==0 or unknown state. Survives external pokes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051bcfc | RenderCommandDispatch | R | Render dispatch function — set as v3[1] for state 0 |
| 0051bd61 | AudioRingBufferManager | R | Write manager function — set as v3[1] for state 3 |
| 0051bdf1 | BufferedDataReader | R | Read manager function — set as v3[1] for state 2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x188) | 0xC | == | 0 | v3[3] (buffer address) — null indicates buffer not allocated |

**Guard interpretation:** For a2==0 path: if byte at this+0x4A is non-zero AND v3[3]==0 (buffer not yet allocated), allocate buffer via vtable method. If v3[3]!=0, skip allocation (buffer exists). For a2==2 or a2==3 path: if v3[2]==0, first set state to 4 and call default method, then set function pointer. For unknown state (a2 non-zero but not 2 or 3): always set state to 4 and call default method, no function pointer change. For a2==0 and byte at this+0x4A==0: use fallback from *(this+0x19C)+4 as v3[1], skipping allocation.
