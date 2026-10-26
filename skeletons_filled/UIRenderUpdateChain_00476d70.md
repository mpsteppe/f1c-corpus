## UIRenderUpdateChain_00476d70 — UIRenderUpdateDispatcher

**Summary:** Updates UI rendering state by ticking the sound system, initializing render buffers, and looking up team name display data from a linked list of render entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | initializes render buffer with 0x10 default values |
| 0041b980 | TeamNameDisplayIDLookup | looks up team name display entry by ID |
| 0048f590 | LinkedListIndexedAccessor_f590 | retrieves an indexed element from a linked list |

**Guard conditions:** `dword_5EB10C` (SoundSystemPtr) must be non-null for sound tick; `LinkedListIndexedAccessor_f590` return must be non-null; list entry offset 0x48 (entry count) must be > 0; pointer table at entry offset 0x3C must be non-null; dereferenced table entry must be non-null; table entry's string/pointer at offset 0x3C must be non-null for team name lookup
