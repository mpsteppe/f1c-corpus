## PitstopActionSet_004b6940 — Pit Stop Action Set

**Summary:** Adds a new entry to the pit stop circular buffer, writing a float value (Z-position/speed) into the current slot. Resets buffer if indices are invalid; otherwise advances to next slot.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStallProximityCheck (004b5da0), PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | Pointer to pit stall circular buffer data array |
| this | 0x9B8 | RW | 0 | Current write index (reset to 0 when buffer reinitialized) |
| this | 0x9BC | RW | 0 | Read index (reset to 0 when buffer reinitialized) |

**Written-by note (persistence):**
- this 0x9B8: Reset to 0 on CoordinateBoundCheck pass; otherwise advanced by CircularCounterIncrement; persists.
- this 0x9BC: Reset to 0 on CoordinateBoundCheck pass; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4e10 | PhysicsObjectListManager | Manage physics objects for the buffer data |
| 004b69a0 | CircularCounterIncrement | Advance circular buffer write index |
| 004b69f0 | CoordinateBoundCheck | Check if buffer indices are negative (invalid state) |
| 004b7860 | sub_4B7860 | Pre-setup or reset helper |

**Guard conditions:** Always calls sub_4B7860(0) first. If CoordinateBoundCheck returns true (indices negative), reset both indices to 0 and call PhysicsObjectListManager (reinitialize path). Otherwise, advance buffer via CircularCounterIncrement. Then writes a2 to array[write_index] + 108 (entry float field).
