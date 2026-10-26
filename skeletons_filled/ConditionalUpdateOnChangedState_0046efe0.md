## ConditionalUpdateOnChangedState_0046efe0 — Conditional update on changed state

**Summary:** Compares cached value at this[93] (offset 0x174) against current value retrieved from module callback table; if different, runs extension update/stripping and caches the new value. State-change detection with deferred update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | RW | — | cached state value (this[93]) — compared against current; updated on change |

**Written-by note (persistence):**
- this 0x174: conditional — updated only when value changes; persists until next change

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable — source of current state value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432a60 | VtableGetterAtOffset0x1c | retrieves current value from module callback table via vtable offset 0x1C |
| 0046f170 | ExtensionStripperForAllListEntries | performs extension stripping/update on all list entries |

**Guard conditions:** No entry guard. If this[93] == v2 (value unchanged, BLOCKED), skips update and returns 0. If different (PASSES), calls ExtensionStripperForAllListEntries, caches new value, returns 0.
