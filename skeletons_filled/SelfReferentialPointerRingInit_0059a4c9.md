## SelfReferentialPointerRingInit_0059a4c9 — Self-referential pointer ring init for buffer

**Summary:** Initializes a self-referential ring of pointers within the object: each buffer control slot at offsets 0xC, 0x10, 0x1C, 0x20, 0x2C, 0x30 is set to point to another field within the same object (forming a ring topology), and all pointed-to target fields are zeroed. Establishes the internal buffer position/metadata pointer structure for a streambuf-style object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSEHVTableInitChain (00598bbc), ObjectInitializationWithBufferBoundsSetup (005994bc), LocaleObjectConstructorWithVTableSetup (00599cb7), ObjectInitWithBufferDataPointerAssignment (0059a473)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | buffer slot pointer (target of ring at 0x10), zeroed |
| this | 0xC | RW | 0 | ring pointer → this+0x4, then target zeroed |
| this | 0x10 | RW | — | ring pointer → this+0x8 (target zeroed) |
| this | 0x1C | RW | 0 | ring pointer → this+0x14, then target zeroed |
| this | 0x20 | RW | 0 | ring pointer → this+0x18, then target zeroed |
| this | 0x2C | RW | 0 | ring pointer → this+0x24, then target zeroed |
| this | 0x30 | RW | 0 | ring pointer → this+0x28, then target zeroed |

**Written-by note (persistence):**
- this 0x8: written once to 0; persists until overwritten
- this 0xC: written once to (this+0x4), then target at 0x4 zeroed; persists
- this 0x10: written once to (this+0x8); persists
- this 0x1C: written once to (this+0x14), then target at 0x14 zeroed; persists
- this 0x20: written once to (this+0x18), then target at 0x18 zeroed; persists
- this 0x2C: written once to (this+0x24), then target at 0x24 zeroed; persists
- this 0x30: written once to (this+0x28), then target at 0x28 zeroed; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
