## SessionPhaseDispatchWithCascadeChecks_0040d1b0 — SessionPhaseDispatchWithCascadeChecks

**Summary:** Attempts cascading lookup across three dispatch objects (menu, callback, resource). On first match, records the matched object pointer, sets dispatch flag, decodes session phase, transitions game action state, and optionally triggers a virtual callback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraDirectorResetInit (0040da30), sub_40DE60 (0040de60), EngineGuardedInitializer (004347c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x10 | R | — | virtual method at vtable+16 on matched object, called when a3 flag is set |
| *(this+0x8) | 0x0 | R | — | vtable of matched dispatch object |
| this | 0x8 | R | — | pointer to matched dispatch object (set by SimpleSetter on success) |
| this | 0x18 | R | — | first dispatch object (menu slot dispatch) |
| this | 0x1C | R | — | second dispatch object (callback lookup) |
| this | 0x20 | R | — | third dispatch object (resource lookup) |
| this | 0x2C | RW | 1 | byte flag set to 1 on successful dispatch |

**Written-by note (persistence):**
- this 0x2C: set to 1 on successful cascade match; init 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040a910 | MenuSlotActionDispatch | first cascade: tries to match a2 against menu slot |
| 0040b450 | LookupWithOptionalCallback | second cascade: tries callback-based lookup |
| 0040bcd0 | ResourceLookupWithOptionalVTableDispatch | third cascade: tries resource lookup |
| 0040cd60 | SessionPhaseDecode | decodes current session phase after dispatch |
| 0040cdd0 | SimpleSetter | stores matched object pointer into this+0x8 |
| 0040cde0 | GameActionStateMachine | transitions game action state with decoded phase |

**Guard conditions:** if a2 is 0, returns 0 immediately. Each cascade stage (menu, callback, resource) is tried in order; if all fail, returns 0. If a3 is set and this+0x8 is non-null, virtual method at vtable+16 called.
