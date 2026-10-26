## ProximityCheckWithTagUpdate_004bda20 — ProximityTagUpdater

**Summary:** Iterates two dynamic arrays of objects (first by this[1]/this[2], second by this[4]/this[5]), updates tag identifier on objects whose tag doesn't match a2, and calls SwitchBasedStateHandler on each updated object.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GridCellIterate (004be340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | first array element count |
| this | 0x8 | R | — | first array data pointer |
| this | 0x10 | R | — | second array element count |
| this | 0x14 | R | — | second array data pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f380 | SwitchBasedStateHandler | handle state transition on tagged object |

**Guard conditions:** First loop: BLOCKED when v7[8] == a3 or v7[1] == a2 (tag already matches or object type doesn't match). Second loop: BLOCKED when v13[1] == a2 (tag already matches). The `!(v9 | v10)` condition is uninitialized (decompilation artifact of x87 flags); behavior depends on actual CPU flag state.
