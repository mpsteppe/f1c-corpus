## MultiFieldSetterDispatchingTo7SubSetters_005546a0 — MultiFieldSetterDispatchingTo7SubSetters

**Summary:** Orchestrator that sets this[0]=a3 then dispatches to 7 sub-setters using values from a2 array indices 8-14. Coordinates state machine transitions and GameDeviceObject notifications.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioBufferFormatSetup (00541120), sub_5550E0 (005550e0), sub_55C070 (0055c070), sub_55C860 (0055c860), sub_55CF50 (0055cf50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object state/ID, set from a3 |

**Written-by note (persistence):**
- this 0x0: Overwritten each call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553fc0 | sub_553FC0 | Primary state machine transition handler (field group 1) |
| 005542f0 | sub_5542F0 | Secondary state machine transition handler (field group 2) |
| 005544c0 | GameStateSettingViaVirtualDispatch | Sets GameDeviceObject state 13 |
| 00554510 | EnumToIDMappingWithVTableNotify | Sets GameDeviceObject state 14 |
| 00554560 | sub_554560 | Sets GameDeviceObject state 18 with conditional routing |
| 005545e0 | SetterWithNotification | Sets GameDeviceObject state 11 directly |
| 00554610 | StateParameterSetterWithVirtualDeviceNotify | Sets parameter on GameDeviceObject via vtable+244 |

**Guard conditions:** No early-exit guards in this function — all 7 sub-setters are called unconditionally with values from a2[8] through a2[14]. Each sub-setter has its own internal guard.
