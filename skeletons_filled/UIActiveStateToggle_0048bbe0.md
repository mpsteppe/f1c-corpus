## UIActiveStateToggle_0048bbe0 — UIActiveFocusToggle

**Summary:** Toggles active/focused state of a text edit widget. If widget IS the currently active field and needs activation (hidden cursor), sets active=1. If widget is NOT active but visible with cursor, deactivates it (active=0). Calls SetterVTableIDCheck and vtable[11] update on state change.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VirtualDispatchWrapper (0048bc70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x40 | R | — | Active widget reference pointer (compared against this) |
| this | 0xE0 | R | — | Visibility/active flag byte |
| this | 0xE1 | R | — | Cursor visibility flag byte |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b910 | SetterVTableIDCheck | Sets vtable/type ID to 1 (activate) or 0 (deactivate) |
| 004979d0 | FieldGetter_79d0 | Gets active/focused widget pointer from field at this+0x40 |

**Guard conditions:** If widget IS active (FieldGetter_79d0 returns this): PASSES to activate if visibility==0 OR cursor_flag==0. If widget is NOT active: PASSES to deactivate if visibility==1 AND cursor_flag==1. All other combinations: no state change.
