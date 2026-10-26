## SubCallVirtualDispatch_0047d060 — VehicleStatsTooltipDispatch

**Summary:** Calls VehicleStatsEstimationDisplay with session name buffer, then dispatches virtual function at vtable offset 0xA4 for additional tooltip/display processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA4 | R | — | vtable offset for post-display virtual dispatch |
| this | 0x0 | R | — | vtable pointer for virtual method calls |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] — session/race name passed to vehicle stats estimation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00430f00 | VehicleStatsEstimationDisplay | display vehicle statistics estimation with session context |

**Guard conditions:** none — always calls both display function and virtual dispatch
