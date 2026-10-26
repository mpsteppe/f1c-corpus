## NetworkUIUpdate_00462848 — NetworkUITickUpdate

**Summary:** Updates UI state counters, optionally broadcasts collision events and renders all session UI elements.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x374 | RW | 1 | UI update-complete flag (set to 1 after rendering) |
| this | 0x0 | R | — | This pointer dereference |

**Written-by note (persistence):**
- obj 0x374: set to 1 each tick; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | Session type — when ==7, triggers collision event broadcast |
| 007ce24c | unk_7CE24C | R | Critical section / session data object for serialization |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045f2b0 | SessionUIElementRenderer | Render all session UI elements |
| 00460710 | ConditionalRenderStateUpdate | Update conditional render state for UI |
| 004613e0 | ShortComputation_13e0 | Broadcast collision events for active drivers |
| 004a0590 | sub_4A0590 | Enter critical section / lock (returns 0 on success) |

**Guard conditions:** Returns 0 immediately when sub_4A0590 fails (critical section lock fails). ShortComputation_13e0 only called when dword_7C56A4 == 7 (specific session type).
