## AudioBufferClear_00541470 — Clear audio buffer via lock-allocate

**Summary:** Checks if an audio buffer pointer at offset 0x114C is non-null, then calls BufferLockAllocate to lock (prepare for write) 96 bytes at a computed sub-offset within that buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5613E0 (005613e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1148 | R | — | buffer sub-index used to compute lock offset |
| this | 0x114C | R | — | buffer base pointer; must be non-null to proceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540f00 | BufferLockAllocate | lock (prepare for write) a region of the audio buffer |

**Guard conditions:** this[0x114C] (buffer pointer) must be non‑null. If null, function returns 0 immediately — buffer not allocated / not ready.
