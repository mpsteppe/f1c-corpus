## MenuCommandDispatcher_004674e0 — MenuCommandDispatcher

**Summary:** Dispatches menu creation based on a command ID (this[93]) — formats and creates UI menu items for setup/date/angle display modes. Routes through different formatters depending on command range and UI bypass flag. Belongs to menu UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | R | — | command ID (switch value, range 446-458) |
| this | 0x178 | R | — | sub-type/parameter for formatters (checked ==1 for message path) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00467674 | jpt_467506 | R | jump table for the switch dispatcher |
| 00467684 | byte_467684 | R | data referenced by jump table entries |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |
| 007c7378 | byte_7C7378 | W | MenuStateFlag [DERIVED] (also: ` — menu state flag (written 0) |
| 007c737c | dword_7C737C | R | float value used in integer format for command 446 |
| 007d048c | byte_7D048C | R | UIBypassFlag [DERIVED] (also: ` — conditional flag for menu path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ec00 | MessageStringFormatter | formats a message string (used when sub-type==1 and bypass flag is 0) |
| 00431950 | SetupIntegerFormatDS | formats integer with float parameter for command 446 |
| 00431aa0 | SetupDateAngleDisplayFormat | formats date/angle display with mode parameter (called with modes 3,2,1,0) |
| 00489600 | UIMenuItemCreator | creates a UI menu item from the formatted string |
| 00489cb0 | StateCleanupNotification | performs state cleanup before dispatching |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x178 | == | 1 | sub-type/parameter for message formatting path |

**Guard interpretation:** Command 446 passes through unconditional SetupIntegerFormatDS path. Commands 447-450: if UIBypassFlag (byte_7D048C) is non-zero (PASSES), only date/angle format mode 3 runs. If bypass flag is zero (BLOCKED) and this[94]==1 (PASSES), message formatting runs first before all 4 date/angle modes. Commands 451-454 jump to separate code (not shown). Commands 455-458 use a thunk call and create a single UI item.
