## UIStateChangeDispatcher_00487400 — UI state change dispatcher with change detection

**Summary:** Compares new state parameter a2 against current state via ByteFieldGetterAt100; if different, invokes virtual state-change notification, then propagates state through UIWidgetPropagateState.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | current state value used for change detection |
| this | 0x0 | R | — | vtable pointer for virtual notification call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | retrieves current UI state byte from object field |

**Guard conditions:** a2 (new state) == ByteFieldGetterAt100(this) — BLOCKS vtable notification call (no change). a2 != current state — PASSES through to virtual notify + UIWidgetPropagateState.
