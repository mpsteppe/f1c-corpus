## DispatchChainWithVTableCalls_0046da20 — Dispatch chain with vtable calls

**Summary:** Sets session type flag to 1 via sub_42D210, creates/activates UI element ID 30 via vtable on this[16], calls force-feedback function sub_4D2450, then invokes vtable callback at offset 14 with param 1. Multi-step dispatch chain for session/UI initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | vtable offset 28 — function that creates/gets UI objects by ID |
| obj | 0x38 | R | — | vtable offset 56 (14*4) — callback invoked with param 1 |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | pointer to vtable-based object used for creating UI elements |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c569c | dword_7C569C | W | SessionType5 flag — set to 1 (server network mode) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase — passed to sub_4D2450 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042d210 | sub_42D210 | sets dword_7C569C to value 1 (session type flag) |
| 0046bf10 | sub_46BF10 | sets activation state on UI binding object (param 1 = activate) |
| 004d2450 | sub_4D2450 | force-feedback/input subsystem call with dword_8ACEE0 parameter |

**Guard conditions:** No early-return guards. All steps execute unconditionally in sequence.
