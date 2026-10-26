## GameOptionsUIConstructor_0047e960 — GameOptionsUIConstructor

**Summary:** Constructs game options UI by freeing old list entries, storing option category in field 0xF4, and populating a settings list based on category (484-494=allowed/disallowed rules, 498=on/off toggle, 499-500=speed multipliers, 501=time mode).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | first node data pointer during linked list cleanup |
| *(this+0x48) | 0x4 | R | — | next node pointer during linked list traversal |
| this | 0x0 | RW | — | vtable pointer, set to off_5A6C78 |
| this | 0x44 | RW | 0 | linked list head, cleared after free |
| this | 0x48 | RW | 0 | linked list node, cleared after free |
| this | 0x4C | RW | 0 | linked list node, cleared after free |
| this | 0x50 | RW | 0 | linked list node, cleared after free |
| this | 0xEC | RW | 0 | deprecated/old field, zeroed on construction |
| this | 0xF0 | RW | 18446744073709551615 | sentinel/index value, initialized to -1 |
| this | 0xF4 | RW | — | option category identifier, set from parameter a2 |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime
- this 0x44: cleared on construction (list rebuilt); external poke survives until rebuild
- this 0x48: cleared on construction; external poke survives until rebuild
- this 0x4C: cleared on construction; external poke survives until rebuild
- this 0x50: cleared on construction; external poke survives until rebuild
- this 0xEC: zeroed on construction; external poke survives
- this 0xF0: initialized to -1 on construction; external poke survives
- this 0xF4: set from constructor parameter; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047eafc | jpt_47E9F7 | R | jump table for switch on option category |
| 0047eb10 | byte_47EB10 | R | default option category byte data |
| 005a6c78 | off_5A6C78 | R | vtable pointer for game options UI object |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — UI text handle for toggle/on-state string |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — "On" text string for toggle option |
| 005c32cc | aDisallowed | R | DisallowedString [DERIVED] — "Disallowed" text string for rule settings |
| 005c6e58 | aSelectedSeason | R | "Selected Season" text string for time mode option |
| 005c6e68 | aTimeScaled | R | "Time Scaled" text string for time mode option |
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] — "Normal" text string for speed/time mode |
| 005c6fac | aX7 | R | "x7" speed multiplier string |
| 005c6fb0 | aX6 | R | "x6" speed multiplier string |
| 005c6fb4 | aX5 | R | "x5" speed multiplier string |
| 005c6fb8 | aX4 | R | "x4" speed multiplier string |
| 005c6fbc | aX3 | R | "x3" speed multiplier string |
| 005c6fc0 | aX2 | R | "x2" speed multiplier string |
| 005c70e0 | aAllowed | R | "Allowed" text string for rule settings |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | insert option setting strings into the menu list |
| 00488b00 | ConstructorInitVTable | base object constructor with vtable and sentinel value |
| 00587bcf | FreeWrapper_7bcf | free old linked list nodes during cleanup |

**Guard conditions:** Switch on parameter a2: 484-494 inserts allowed/disallowed strings (rules); 498 inserts toggle/on strings; 499-500 inserts 7 speed multiplier strings; 501 inserts 3 time mode strings; any other value skips list population.
