## PerIndexStructFieldResetter_0045b430 — PerIndexCircularBufferEntryResetter

**Summary:** Resets a specific entry (by index a2) in an 8-entry circular buffer: clears byte flag, sets sentinel values (-1, -1.0f, state=3). If the reset index matches the current write cursor (this[0x31C]), advances cursor modulo 8. Part of collision/event log system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_b360 (0045b360), CollisionDamageDecayProcessor (0045b840), UtilityFunction_b9c0 (0045b9c0), StringMatchingWithCaseSensitiveCaseInsensitiveMo (0045ba60), DoubleDelegateCall_bbe0 (0045bbe0), ShortComputation_bdf0 (0045bdf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | RW | — | Circular buffer write cursor index (0-7, modulo 8) |

**Written-by note (persistence):**
- this 0x31C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early return guard. After resetting entry at index a2, checks if a2 == this[199] (write cursor); if so, advances cursor by 1 modulo 8.
