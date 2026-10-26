## HUDFlagRendererSecondary_004dbac3 — Secondary HUD flag overlay (text)

**Summary:** Same flag byte collection as main renderer (yellow=62, blue=65, pit=102, black=63, checkered=66) but renders via UITextRenderWithScale as text overlay at position (a3+5, a4) with scale 2.0. Lacks extended flags (fuel, sub_49B9A0, sub_49BA30). Takes first flag trigger as parameter a1 (AL register via __userpurge). NOT_FOUND frame path — frequency UNKNOWN.

**Struct fields accessed:** None (no struct fields; only local buffer and passed parameters)

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| a1 (AL, first flag) | 0 vs non-zero | non-zero → yellow flag (62) added | zero → skip yellow flag |
| a2 (counter) | >0 | enter render block | ≤0 (skip render) |

**Written-by note:** Writes no persistent struct fields. Writes local buffer only (stack). NOT_FOUND frame path — frequency UNKNOWN.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007C56A8 | dword_7C56A8 | Read | Session sub-state (==8 activates checkered flag 66) |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| 0x004BAEB0 | VehicleFlagCheck | Blue flag check (returns bool) |
| 0x004BC070 | PitStateFlagCheck | Pit state flag check (returns bool) |
| 0x004BC0A0 | DisqualificationCheck | Disqualification flag check (returns bool) |
| 0x00532B70 | UITextRenderWithScale | Text overlay render with scale (2.0, 2.0) at position (a3+5, a4) |

**Call frequency:** UNKNOWN (NOT_FOUND frame path — no static reachability from per-frame tick root; may be vtable-initiated or event-driven)
