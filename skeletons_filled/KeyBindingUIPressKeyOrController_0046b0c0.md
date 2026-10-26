## KeyBindingUIPressKeyOrController_0046b0c0 — KeyBindingUI_StateMachine

**Summary:** State machine for key/controller binding UI that cycles through three states: (1) display "Press Key or Controller" prompt and begin binding, (2) capture input via parameter lookup, and (3) finalize binding with reserved-key conflict detection. Operates on a per-team-entry basis.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIClickHandlerWithBoundsCheck (0046b070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1589 | RW | 1 | popup visibility byte on child UI panel (0=hidden, 1=visible) |
| this | 0x40 | R | — | pointer to child UI panel object (popup control) |
| this | 0x1F4 | RW | — | selected team/entry index (set from FieldGetter result) |
| this | 0x1F8 | RW | — | bitmap sprite handle for the key-binding UI element |
| this | 0x1FC | RW | 0 | state machine state: 0=idle, 1=prompt, 2=wait-for-input, 3=finalize |
| this | 0x200 | RW | — | captured input parameter value (from ParameterLookupWithFallback) |
| this | 0x204 | RW | — | mapped key/button ID (from EnumToIDMappingWithDefaultFallthrough) |
| this | 0x208 | RW | 0 | lookup accumulator/counter (incremented in state 1, consumed in state 2) |

**Written-by note (persistence):**
- *(this+0x40) 0x1589: written on state entry/exit — survives between calls
- this 0x1F4: written in state 1 — survives until next binding cycle
- this 0x1F8: written in state 1 — survives until state 3 teardown
- this 0x1FC: written on every state transition — survives between calls (state machine core)
- this 0x200: written in state 2/3 — survives for finalization
- this 0x204: written in state 2/3 — survives for finalization
- this 0x208: written in state 1, zeroed in state 2 — survives between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c69b8 | aPressKeyOrCont | R | String_PressKeyOrCont [DERIVED] |
| 005c69e0 | aPopupControlSe | R | PopupControlSetString [DERIVED] |
| 005c69f4 | aReservedKey | R | ReservedKeyString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007d1424 | dword_7D1424 | R | TeamEntryCount [DERIVED] (also: ` — number of teams/entries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | searches string table for a key, returns string value (used for UI text lookup) |
| 00454c20 | EnumToIDMappingWithDefaultFallthrough | maps scancode/enum value to key ID with default fallback of 89 |
| 00454d30 | ParameterLookupWithFallback | captures user input parameter (key press or controller button) |
| 00455560 | ArrayIndexedAccessor | indexes into the module pointer array by team index |
| 0046a9c0 | ControllerShifterMapping | handles controller/shifter input mapping for finalization |
| 00489940 | FieldGetter | gets current selection field value (team/entry index) |
| 00497940 | LookupDispatch | dispatches UI lookup/visibility toggle for popup control |
| 00497980 | BitmapSpriteAccessor | retrieves bitmap sprite handle by index for UI rendering |
| 004988c0 | sub_4988C0 | enables/disables a UI element (called with param 1 to enable after finalization) |
| 00498950 | SpriteTextureEnumeration | displays sprite texture for reserved-key warning message |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1FC | == | 3 | state 3: finalize binding — calls ControllerShifterMapping, re-enables popup, dispatches cleanup |
| this | 0x1FC | == | 2 | state 2: wait for input — calls ParameterLookupWithFallback, on success transitions to state 3 |
| this | 0x1FC | == | 1 | state 1: begin binding — displays prompt string, captures bitmap sprite, transitions to state 2 |

**Guard interpretation:** State machine driven by this+0x1FC (offset 0x1FC = 508). State 1: displays "Press Key or Controller" prompt with team name, increments lookup counter, transitions to state 2. State 2: captures input parameter; if valid, checks for reserved keys via EnumToIDMappingWithDefaultFallthrough; if reserved, shows warning and stays in state 2; otherwise transitions to state 3. State 3: calls ControllerShifterMapping to finalize, re-enables popup, dispatches cleanup, transitions to state 0 (idle). Entry guard: FieldGetter() returns valid index within [0, dword_7D1424) else function returns without action.</content>
