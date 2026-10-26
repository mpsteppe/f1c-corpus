## StateArrayReset_004e3890 — StateArrayReset

**Summary:** Resets an array of contact/state entries by calling sub_4DF110 with zero on each entry and clearing the sixth float field to 0.0. Part of vehicle state/reset system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleRespawnReset (004e0800)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBA8 | R | — | Count of state entries to reset |
| this | 0xBC4 | RW | — | Sixth float of each entry (187-float stride), cleared to 0.0 |

**Written-by note (persistence):**
- this 0xBC4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df110 | ContactConstraintSolverUpdate | Resets contact constraint state to zero |

**Guard conditions:** Checks this[746] (count at this+0xBA8) > 0. If <= 0, skips loop. PASSES: entries to reset. BLOCKED: no entries.
