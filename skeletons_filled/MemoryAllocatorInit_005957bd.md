## MemoryAllocatorInit_005957bd — BufferedIOContextInitSimple

**Summary:** Initializes a buffered I/O context with a 4KB heap buffer (via MallocWrapperForNhMalloc) or fallback 2-byte inline buffer. Sets cursor, remaining count (0), buffer base, size, and flags (heap=bit 3, inline=bit 2). Increments global file open counter.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C255 (0058c255), sub_58CF35 (0058cf35), sub_596888 (00596888), sub_59BCFC (0059bcfc), sub_59C1E7 (0059c1e7), sub_59C30E (0059c30e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | cursor pointer (current read/write position in buffer) |
| this | 0x4 | RW | 0 | remaining byte count in buffer |
| this | 0x8 | RW | — | buffer base pointer (start of allocated memory or inline buffer) |
| this | 0xC | RW | — | flags (bit 3 = heap-allocated buffer, bit 2 = inline buffer) |
| this | 0x18 | RW | 2 | total buffer capacity (4096 for heap, 2 for inline) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3ec8 | dword_8D3EC8 | W | FileOpenCount [DERIVED] — incremented for each buffer context init |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | allocate 4096-byte heap buffer for I/O |

**Guard conditions:** No early exits. Always initializes: if MallocWrapperForNhMalloc returns non-null → heap buffer path (flag bit 3 set). If null → inline buffer path (flag bit 4 set, 2-byte inline at a1+0x14).
