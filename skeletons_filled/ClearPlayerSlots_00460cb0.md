## ClearPlayerSlots_00460cb0 — ClearPlayerSlots

**Summary:** Resets player slot arrays to default state: clears count to 0, initializes node ID and DWORD arrays with -1 sentinel, zeroes struct fields. Optionally validates slot entries against node ID array and logs debug for stale entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), SynchronizeWithServer (00464290), SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1D4 | RW | 18446744073709551615 | Slot/entity ID DWORD array (104 elements), stale entries reset to -1 |
| this | 0x3C74 | R | — | Node ID array (104 elements), used for slot validation lookup |
| this | 0x3E14 | RW | 0 | Player slot count, reset to 0 |
| this | 0x3E18 | RW | 18446744073709551615 | DWORD array (104 elements), each initialized to -1 |
| this | 0x3FB8 | R | — | COM interface pointer for UtilityFunction_a800 |
| this | 0x3FC4 | R | — | Session phase (when != 3, validate slot entries) |

**Written-by note (persistence):**
- this 0x1D4: conditional — stale entries reset to -1; valid entries preserved
- this 0x3E14: once per call — reset to 0 unconditionally
- this 0x3E18: once per call — all 104 entries set to -1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6098 | aMarkingSlotDAs | R | MarkingSlotDAsField [DERIVED] — debug log string |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — guards debug logging |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461480 | StructFieldZeroInitWithDefaults | Zero-init 140-byte struct with defaults |
| 004d7a50 | StringSplitLoop | Sanitize debug message string |
| 004d7aa0 | DebugLogWrite | Write debug log for stale/marked slots |
| 0057a800 | UtilityFunction_a800 | Utility call on COM interface |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1D4 | != | 18446744073709551615 | Slot array entry not empty |
| this | 0x3FC4 | != | 3 | Session phase |

**Guard interpretation:**
- Unconditionally: set this[0x3E14] = 0, loop 104 times setting node ID array (0x3C74) and DWORD array (0x3E18) entries to -1.
- Call UtilityFunction_a800(this[0x3FB8]).
- If a2 != 0: zero-init remaining struct fields (140-byte each) for count..103.
- If phase (this+0x3FC4) != 3:
  - Iterate slot array at this+0x1D4 (104 entries).
  - Entry == -1 → skip.
  - Entry != -1 → search in node ID array (0x3C74).
  - Not found in node ID array → log "Marking slot as invalid" (if not server) and set entry to -1.
  - Found → keep entry.
- If phase == 3: skip slot validation entirely.
