## SelectedSeasonUIInit_00470850 — SelectedSeasonUIListConstructor

**Summary:** Constructor for selected season UI list: calls base init (sub_48C070), sets vtable to off_5A0540, initializes field 0x31C to 401, inserts four linked list entries (UI handle, "Normal", "TimeScaled", "SelectedSeason" strings), and calls SessionSetupScreenSetup. Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0540 |
| this | 0x31C | RW | 401 | numeric field / type ID, initialized to 401 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0540; overwritten if external code changes vtable
- this 0x31C: set once to 401; overwritten if external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0540 | off_5A0540 | R | vtable pointer assigned to this object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — inserted as first linked list entry |
| 005c6e58 | aSelectedSeason | R | "SelectedSeason" string for UI list display |
| 005c6e68 | aTimeScaled | R | "TimeScaled" string for UI list display |
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] — "Normal" string for UI list display |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00470960 | SessionSetupScreenSetup | session setup screen configuration after list insertion |
| 00486f30 | LinkedListInsertWithNodeAllocation | insert node into linked list (-1 = append) |
| 0048c070 | sub_48C070 | base UI list constructor (flag=1) |

**Guard conditions:** No guards — unconditional initialization sequence.
