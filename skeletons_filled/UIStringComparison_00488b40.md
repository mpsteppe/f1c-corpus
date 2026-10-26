## UIStringComparison_00488b40 — UIStringCompareAndSet

**Summary:** Compares input string a2 with stored string at offset 0xB0 (or default path). If different, copies the new string via StringCopyWithBufferRealloc and invokes virtual method at +44 to notify/reload. Returns -1 if a2 is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TelemetryDisplaySwitch (0047dbe0), RaceLapsStringLoadOnTrigger (0047e3f4), VehicleNameToMessageBuffer (0047f010), LoadAndProcessMessageBuffer (0047f0a0), UIScreenSelectionHandler (0048d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Virtual +44 — notification/reload callback |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0xB0 | R | — | Stored string pointer (current value to compare against) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Allocate and copy new string |

**Guard conditions:** Input a2 null → return -1 (blocked). When a2 non-null, proceeds to compare; if string differs, performs update.
