## WidgetNameAccessor_00476240 — AccessWidgetNameOrDefault

**Summary:** Accesses a widget's name string at offset 0x40. Returns global default directory path if widget name is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | widget name string pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `this[16]` (offset 0x40) == NULL → returns global default `byte_5EA438`; non-NULL → returns widget name pointer
