## SimpleSetterWithSubCall_0040d470 — StructFirstFieldSetter

**Summary:** Sets first DWORD of struct (likely vtable or parent pointer) from parameter, then calls StructFieldInit to initialize remaining fields. Returns `this`. Used during camera director reset/init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraDirectorResetInit (0040da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First DWORD — set to `a2` (vtable pointer or parent object reference) |

**Written-by note (persistence):**
- this 0x0: init once from caller — external poke persists (only written during reset/init)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d490 | StructFieldInit | Initialize remaining struct fields after first field is set |

**Guard conditions:** none — no conditional branches; always sets field and calls sub-init.
