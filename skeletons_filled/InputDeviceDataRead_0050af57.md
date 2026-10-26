## InputDeviceDataRead_0050af57 — ReadSurfaceDataToBuffer

**Summary:** Locks a texture surface region, copies raw pixel data into caller-provided buffer, then optionally runs post-process cleanup if a flag is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Post-process flag; if non-zero, calls ContactManifoldCleanup on copied data |
| this | 0x1030 | R | — | Destination line offset index for source pointer calculation |
| this | 0x1034 | R | — | Source X coordinate passed to sub_50AB51 |
| this | 0x1040 | R | — | Source Y coordinate passed to sub_50AB51 |
| this | 0x1058 | R | — | Row width in 16-byte units (copy size) |
| this | 0x106C | R | — | Pointer to source surface data |
| this | 0x1070 | R | — | Start offset within source for pointer calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | Post-processes the read-back pixel data if flag at 0x10 is set |
| 0050ab51 | sub_50AB51 | Performs surface lock for reading at given coordinates |

**Guard conditions:** Calls sub_50AB51 with coordinates (0x1034+a2, 0x1040+a3, flag=1). Only proceeds to memcpy and optional ContactManifoldCleanup if sub_50AB51 returns >= 0 (success).
