## TimerClampAndProcess_004e38d0 — TimerCountClampAndArrayDestroy

**Summary:** Clamps timer counter at offset 0xBA8 to valid range [0, 11], then iterates up to count calling DualArrayDestructor on each array entry (stride 748 bytes). Resets counter to 0 at end. Timer/array cleanup during vehicle reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleResetClear (004e09e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBA8 | RW | 0 | timer/counter field, clamped and reset to 0 |

**Written-by note (persistence):**
- this 0xBA8: clamped to [0,11], then reset to 0; no persistence across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ded20 | DualArrayDestructor | destroy internal dual-array structure |

**Guard conditions:** If counter (this+0xBA8) < 0, clamp to 0. If > 11, clamp to 11. If clamped count > 0, process DualArrayDestructor on each entry.
