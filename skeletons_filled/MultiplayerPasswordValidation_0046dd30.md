## MultiplayerPasswordValidation_0046dd30 — Multiplayer password validation

**Summary:** Validates multiplayer password entry: creates UI element ID 34, retrieves entered text, validates entrant credentials via game module manager. If no password is set and validation passes, shows password entry UI; if entrant validation fails but join request succeeds, sets field to 4.0f. Part of multiplayer session join workflow.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x1C | R | — | vtable offset 28 — function that creates/gets UI objects by ID |
| *(this+0x40) | 0x0 | R | — | vtable pointer of UI object at this+0x40 |
| this | 0x40 | R | — | pointer to vtable-based object for creating UI elements |
| this | 0xE4 | RW | 1082130432 → 4.0f | float field set to 4.0f on successful join request |

**Written-by note (persistence):**
- this 0xE4: conditional — set to 4.0f only when SendJoinRequest succeeds; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6c58 | aClientPassword | R | "ClientPassword" string — passed to sub_4988D0 |
| 005c6c70 | aMultiClientPas | R | "MultiClientPasswordEntryString" — UI lookup for password entry screen |
| 007cd25c | dword_7CD25C | R | GameModuleManager — passed to entrant validation and SendJoinRequest |
| 007cd850 | byte_7CD850 | R | MultiClientPassword — current password buffer; empty check triggers password entry UI |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | prepares failure/wrong description scenario data |
| 004615f0 | BitFlagTestAt0x6E | tests bit flag at offset 0x6E in validation result |
| 00462c00 | SendJoinRequest | sends join request to game session with password |
| 00489940 | FieldGetter | retrieves field value from UI element; returns >=0 if valid |
| 00489950 | UIScreenTextAccessor_9950 | retrieves text content from UI screen element |
| 00497940 | LookupDispatch | dispatches UI lookup by string identifier |
| 004988d0 | sub_4988D0 | triggers password entry dialog with given prompt string |
| 004b0170 | EmptyStub_0170 | empty/stub function call |
| 00587ece | sub_587ECE | converts UI text to entrant identifier |

**Guard conditions:** No entry guard. If UI element ID 34 creation fails (returns null), skips entire body, returns -1. If FieldGetter returns < 0, skips validation. If UIScreenTextAccessor returns null, skips remaining body. If entrant validation (loc_462010) succeeds AND BitFlagTestAt0x6E passes AND MultiClientPassword is empty → shows password entry UI (branch A). Else if SendJoinRequest succeeds → sets this+0xE4 to 4.0f (branch B). Always calls EmptyStub_0170 and returns -1.
