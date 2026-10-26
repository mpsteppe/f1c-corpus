## PollingStateChangeDetection_00477fa0 — Poll two game-object states for change and dispatch notification

**Summary:** Polls two monitored state objects via virtual accessors; if either differs from cached value, updates cache and calls virtual notification handler (offset 0xA0) to signal state change.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | virtual accessor function to retrieve monitored state (arg 3) |
| obj | 0xA0 | R | — | virtual notification callback invoked on state change |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | pointer to state-accessor sub-object |
| this | 0x11C | RW | — | cached value of first monitored state |
| this | 0x120 | RW | — | cached value of second monitored state |

**Written-by note (persistence):**
- this 0x11C: written conditionally when first monitored state changes
- this 0x120: written conditionally when second monitored state changes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | game command dispatch interface pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d360 | GuardedAccessor | extract integer value from monitored state object |

**Guard conditions:** If first accessor returns null, skip first check. If `this[71]` already equals extracted value, skip notification. Similarly for second check via global dispatch interface — if target object exists and `this[72]` differs, update and notify. Both checks independent.
