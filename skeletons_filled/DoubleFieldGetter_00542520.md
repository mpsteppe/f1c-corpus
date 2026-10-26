## DoubleFieldGetter_00542520 — Get two fields at offsets 0x4, 0x8

**Summary:** Reads values at offsets 0x4 and 0x8 and writes them through output pointers a2, a3 respectively. Each output pointer is null-guarded.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewSystem (00408e20), sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | first value |
| this | 0x8 | R | — | second value |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer individually guarded: if null, that field is skipped.
