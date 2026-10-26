## EnumToVTableCallMapper_0055ca40 — Maps enum action ID to vtable call with parameter

**Summary:** Maps an action enum (a2: 1, 2, or 4) to a vtable call at entry 37 (offset 0x94) with a corresponding integer parameter (256, 2, or 3). Result stored in this[0]. Part of action/command dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraProjectionUpdate (00541b70), LogSessionEvent (0054b9e0), sub_553700 (00553700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x94 | R | — | Vtable entry 37 — called with action parameter |
| this | 0x0 | RW | — | Result storage — written with return value of vtable call |
| this | 0x1100 | R | — | Pointer to sub-struct whose first field is the vtable |

**Written-by note (persistence):**
- this 0x0: Written from vtable call result on every matching path. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 == 1: PASSES — calls vtable with 256. a2 == 2: PASSES — calls vtable with 2. a2 == 4: PASSES — calls vtable with 3. All other values: BLOCKED — returns (a2 - 4) without vtable call.
