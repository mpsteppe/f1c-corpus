## StateChangeNotification_00486660 — StateChangeNotifySubscribers

**Summary:** Stores a byte state value at this+0x64; if changed, calls vtable offset 44 (pre-change notification), then notifies all linked subscriber nodes via vtable offset 56. Part of UI widget state propagation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIWidgetPropagateState (0048741b), StateChangeHandlerWithSubscriberNotification (00487900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x90)+0x0) | 0x38 | R | — | vtable offset 56 on subscriber node — notification method |
| *(this+0x90) | 0x0 | R | — | vtable pointer of first subscriber node |
| obj | 0x2C | R | — | vtable offset 44 on this — pre-change notification callback |
| this | 0x0 | R | — | vtable pointer of this object |
| this | 0x64 | RW | — | stored byte state value |
| this | 0x90 | R | — | pointer to head of subscriber linked list |

**Written-by note (persistence):**
- this 0x64: set unconditionally every call; external poke overwritten when function is called

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | traverse linked list — returns next subscriber node |

**Guard conditions:** Checks if `a2 != this[100]` (byte at offset 0x64). If different, pre-change callback (vtable+44) fires. If same, callback skipped. Either way, value is stored and subscribers are notified.
