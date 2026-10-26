## VTableDispatchWithFieldClear_004d7e30 — VTableDispatchWithStateClear

**Summary:** Clears this[3] to 0, then dispatches through the vtable at offset 0x10 (4th vtable entry). Standard virtual call wrapper with state reset.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** OnScreen_Restart (0049f000), sub_4D8760 (004d8760), VehicleStateUpdate (004d9fe0), ThunkToSub4D7E30 (004db110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | vtable function pointer at offset 0x10 (4th slot) |
| this | 0x0 | R | — | vtable pointer (first dword of object) |
| this | 0xC | RW | 0 | state/flag field cleared to 0 before dispatch |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None; always clears and dispatches.
