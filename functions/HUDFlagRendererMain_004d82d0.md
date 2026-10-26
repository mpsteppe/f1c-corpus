## HUDFlagRendererMain_004d82d0 — Primary HUD flag display renderer

**Summary:** Collects flag bytes into local buffer from multiple check functions and renders via text overlay. Flag values: yellow=62, blue=65 (0x41), black=63, pit=102, checkered=66. Extended flags (when mode==2): sub_49B9A0→130 (-126), fuel→68, sub_49BA30==1→140 (-116), ==2→141 (-115). Temporarily patches a UI object's scale values at +0x5C/+0x60 (1.5f) during render, restores afterward. NOT_FOUND frame path — frequency UNKNOWN.

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| this[2] | 0x0008 | Read | — | Conditional guard: must be -1 to proceed |
| dword_8AD394+92 | +0x5C | Read, Write | saves/restores original; writes 1069547520=0x3FC00000=1.5f | UI object scale X (temporary override during render) |
| dword_8AD394+96 | +0x60 | Read, Write | saves/restores original; writes 1069547520=1.5f | UI object scale Y (temporary override during render) |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| dword_7CFEA0 | 0 vs non-zero | non-zero | 0 (immediate return 0) |
| ConditionalFlagReturn(&dword_5EA43C) | 0 vs non-zero | 0 | non-zero (return that value) |
| dword_8AB6E4 | ==2 | !=2 | ==2 (return) |
| this[2] | -1 | == -1 | != -1 (return) |
| v3 (flag count) | >0 | enter render block | ≤0 (skip render) |
| dword_8AD394 | 0 vs non-zero | non-zero (render using UI object) | 0 (skip render block) |

**Written-by note:** Writes local buffer only (not vehicle struct). Writes to dword_8AD394+0x5C and +0x60 are temporary — original values saved before and restored after render. External poke to those float fields would be overwritten by the restore. NOT_FOUND frame path — call frequency UNKNOWN; cannot determine persistence.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007CFEA0 | dword_7CFEA0 | Read | HUD render gate (0=disabled) |
| 0x005EA43C | dword_5EA43C | Read | Conditional flag reference |
| 0x008AB6E4 | dword_8AB6E4 | Read | Mode/state check (==2 blocks render) |
| 0x007C56A8 | dword_7C56A8 | Read | Session sub-state (==8 activates checkered flag 66) |
| 0x008AD394 | dword_8AD394 | Read, Write | UI object pointer (text render target, scale temp modified) |
| 0x008B8DC8 | dword_8B8DC8 | Read | Render target/context |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| 0x004A0AC0 | ConditionalFlagReturn | Check conditional flag at address |
| 0x004D8350 | ShortComputation_bad0 | Yellow flag check (returns bool) |
| 0x004BAEB0 | VehicleFlagCheck | Blue flag check (returns bool) |
| 0x004BC0A0 | DisqualificationCheck | Disqualification flag check (returns bool) |
| 0x004BC070 | PitStateFlagCheck | Pit state flag check (returns bool) |
| 0x0049B9A0 | sub_49B9A0 | Extended HUD flag check (returns bool) |
| 0x0049BC40 | FuelWeightComputation | Fuel weight flag check (returns bool) |
| 0x0049BA30 | sub_49BA30 | Extended HUD flag type (returns 1 or 2) |
| 0x00553070 | sub_553070 | Text/flag render function |
| 0x004D43B0 | FieldSetterAt0x48 | Set field at offset 0x48 to 0xFFFFFF |

**Call frequency:** UNKNOWN (NOT_FOUND frame path — no static reachability from per-frame tick root; may be vtable-initiated or event-driven)
