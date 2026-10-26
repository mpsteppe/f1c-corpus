## sub_4A9FE0_004a9fe0 — CallVtableSlot40WithModeFlag

**Summary:** Builds a boolean flag (default true; in game mode 4 it is derived from whether the object fetched from the global list anchor unk_B76270 has field +95732 different from 3) and dispatches it to the object's virtual method at vtable offset 0x28. Returns that virtual call's result.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x28 | R | — | Vtable slot (index 10) holding the virtual method invoked with (this, flag). |
| this | 0x0 | R | — | Vtable pointer of the receiving object. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b72314 | dword_B72314 | R | Mode/state selector; only when it equals 4 is the extra object lookup performed. |
| 00b76270 | dword_B76270 | R | Anchor passed to LinkedListDereference (as unk_B76270) to obtain the object whose field +95732 is tested. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00532d20 | LinkedListDereference [exact] | Dereferences the global list anchor &unk_B76270; returns the target object (or 0). |

**Guard conditions:** Flag v4 starts as 1 (true). The flag is recomputed only when *(DWORD*)dword_B72314 == 4 AND sub_532D20(&unk_B76270) returns non-zero; then v4 = (*(DWORD*)(object + 95732) != 3). Everything else leaves v4 = 1. The virtual method at vtable +0x28 is always called with the resulting flag.
