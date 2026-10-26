## TripleBufferAllocation_005697f0 — AllocateConstraintGroupBuffers

**Summary:** Allocates three buffers for constraint/joint element groups: first group count*56 bytes to this[140], second group count*132 bytes to this[142], third group count*88 bytes to this[144]. Resets all counts to 0 after allocation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | 0 | count of elements in first group (reset to 0 after alloc) |
| this | 0x230 | RW | — | pointer to first group element buffer (stride 56) |
| this | 0x234 | RW | 0 | count of elements in second group (reset to 0 after alloc) |
| this | 0x238 | RW | — | pointer to second group element buffer (stride 132) |
| this | 0x23C | RW | 0 | count of elements in third group (reset to 0 after alloc) |
| this | 0x240 | RW | — | pointer to third group element buffer (stride 88) |

**Written-by note (persistence):**
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x230: recalc every frame — external poke does NOT persist
- this 0x234: recalc every frame — external poke does NOT persist
- this 0x238: recalc every frame — external poke does NOT persist
- this 0x23C: recalc every frame — external poke does NOT persist
- this 0x240: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation for each element group buffer |

**Guard conditions:** None — unconditional allocation for all three groups regardless of count values.
