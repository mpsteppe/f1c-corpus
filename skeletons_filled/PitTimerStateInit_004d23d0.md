## PitTimerStateInit_004d23d0 — Pit timer state initialization

**Summary:** Initializes pit timer struct from source: copies timestamp and computed offset value, zeroes two flag bytes, dispatches registration (sub_42D140), and broadcasts the timestamp to all vehicles via sub_4BC2D0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | — | Timestamp — copied from a2+12 (source float value) |
| this | 0xB4 | RW | — | Computed time — a2+12 + this+0xB8 (timestamp plus stored offset) |
| this | 0xB8 | R | — | Time offset — added to base timestamp for computed field |
| this | 0xC1 | RW | 0 | Flag byte — zeroed unconditionally |
| this | 0xC2 | RW | 0 | Flag byte — zeroed unconditionally |
| this | 0xD8 | RW | — | Stored value — copied from a2+8 (source DWORD) |

**Written-by note (persistence):**
- this 0xB0: Written unconditionally from source. External poke overwritten on next call.
- this 0xB4: Written unconditionally as computed sum. External poke overwritten on next call.
- this 0xC1: Written to 0 unconditionally. External poke overwritten on next call.
- this 0xC2: Written to 0 unconditionally. External poke overwritten on next call.
- this 0xD8: Written unconditionally from source. External poke overwritten on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount — loop bound for per-vehicle broadcast |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — vehicle pointers for broadcast |
| 007c569c | dword_7C569C | R | SessionType5 — passed to sub_42D140 as dispatch parameter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042d140 | sub_42D140 | Dispatches registration/notification with session type and value |
| 004bc2d0 | sub_4BC2D0 | Broadcasts timestamp value to each vehicle at offset +16436 |

**Guard conditions:** None — all writes unconditional. Vehicle loop iterates over dword_5C329C vehicles; executes 0 times if count is 0.
