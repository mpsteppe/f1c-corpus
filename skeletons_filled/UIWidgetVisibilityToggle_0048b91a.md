## UIWidgetVisibilityToggle_0048b91a — WidgetVisibilityToggle

**Summary:** Sets widget visibility flag at a3+0xE0. When hiding (a2==0), clears active widget reference at a3+0x40 via FieldGetter_79d0/SimpleSetter_79e0 and calls vtable[44] destructor on widget. When showing, just calls callback at a1+44 and returns.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Callback function pointer at a1+44 (caller vtable entry 11) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004979d0 | FieldGetter_79d0 | Gets active/focused widget pointer from field at a3+0x40 |
| 004979e0 | SimpleSetter_79e0 | Clears active widget reference at a3+0x40 |

**Guard conditions:** No explicit guards on input. Always sets visibility byte. When a2==0 (hiding): checks if widget at a3+0x40 points to self; if so, clears it, then calls vtable[44] on widget. When a2!=0 (showing): skips cleanup. No values blocked.
