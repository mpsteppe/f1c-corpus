## ViewCameraReset_004064c0 — SlotDataResetWithMutexAcquire

**Summary:** Resets slot data entries to default (-1/0) state and optionally closes audio stream if handle is non-null. Acquires mutex lock at end after initializing default path string into each slot.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_6250 (00406250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | audio stream handle (checked non-zero before cleanup call) |
| this | 0x1C | RW | 18446744073709551615 | first slot identifier (reset to -1) |
| this | 0x20 | RW | 0 | first slot byte flag (reset to 0) |

**Written-by note (persistence):**
- this 0x1C: written on reset — set to -1
- this 0x20: written on reset — set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406700 | MutexLockWithTimeout | acquires mutex lock with timeout 0 after reset |
| 00406750 | AudioStreamCloseAndCleanup | closes and cleans up audio stream if handle is non-null |
| 00566650 | StringCopyWithBufferRealloc | copies default path string into each slot during reset |

**Guard conditions:** checks this[3] (offset 0xC) != 0 — if non-null, calls AudioStreamCloseAndCleanup before resetting slots. If null, skips stream cleanup.
