## SeasonDatabaseObjectFactory_0047f440 — SeasonDatabaseObjectFactory

**Summary:** Factory function that constructs season/career-mode database objects by type ID — allocates memory for the requested object type, calls the appropriate constructor and vtable setup, caches the result in an internal array indexed by (ID-1), and returns the constructed object pointer (or NULL on allocation failure or out-of-range ID).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047fa1c | jpt_47F48B | R | Switch jump table pointer — dispatches the large switch-on-ID to per-case constructors |
| 005a6e98 | off_5A6E98 | R | VTableRef_5A6E98 [DERIVED] |
| 005a6f48 | off_5A6F48 | R | Vtable for object type 3 (1108-byte object, zero-fields constructor) |
| 005a7008 | off_5A7008 | R | Vtable for object types 35/36 (372-byte object, sub_4893C0 constructor) |
| 005a70b8 | off_5A70B8 | R | Vtable for object type 18 (384-byte object, LargeConstructor) |
| 005a7168 | off_5A7168 | R | VTable_FUN_0047fb10 [DERIVED] |
| 005a7218 | off_5A7218 | R | Vtable for object types 11-15,19,25,26 (384-byte object, LargeConstructor) |
| 005a72c8 | off_5A72C8 | R | Vtable for object type 20 (388-byte object, LargeConstructor + zero field 96) |
| 005a7378 | off_5A7378 | R | Vtable for object type 10 (232-byte UI component, UIComponentInit5) |
| 005a7428 | off_5A7428 | R | Vtable for object type 9 (232-byte UI component, UIComponentInit5) |
| 005a74d8 | off_5A74D8 | R | Vtable for object type 8 (232-byte UI component, UIComponentInit5) |
| 005a7588 | off_5A7588 | R | Vtable for object type 7 (232-byte UI component, UIComponentInit5) |
| 005a7638 | off_5A7638 | R | Vtable for object type 1 (236-byte track DB object, ConstructorWithByteParams + filename copy) |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004685b0 | FunctionCallWrapper_85b0 | Constructs object type 2 (380-byte) — wraps allocation + vtable + field init |
| 0046a220 | ObjectConstructorWithVTable | Constructs object types 5/6 (848-byte) — alloc-init + vtable assignment |
| 0046a4e0 | ConstructorWithVTableAndSubInit | Constructs object type 27 (380-byte) — vtable + sub-init sequence |
| 0046a900 | ConstructorFieldsVTable | Constructs object type 28 (524-byte) — fields init + vtable |
| 0046b580 | ShortComputation_b580 | Constructs object types 30-33 (384-byte) — short init with flag param (0 or 1) |
| 0046e7d0 | ShortComputation_e7d0 | Constructs object type 43 (376-byte) — specialized short init |
| 0046eec0 | ObjectInitWithVTableState | Constructs object type 44 (376-byte) — vtable + state init |
| 00470230 | ConstructorWithBulkInitAndVTable | Constructs object type 436 (772-byte) — bulk field initialization + vtable |
| 004750f0 | sub_4750F0 | Constructs object type 34 (384-byte) — specialized constructor |
| 004766f0 | ShortComputation_66f0 | Constructs object types 21/23 (400-byte) — receives a2 for type discrimination |
| 00477410 | sub_477410 | Constructs object types 17/24 (396-byte) — receives a2 for type discrimination |
| 0047a9e0 | sub_47A9E0 | Constructs object type 37 (288-byte) — specialized constructor |
| 0047be70 | InitWithVTable_be70 | Constructs object type 38 (376-byte) — init + vtable |
| 00487220 | ConstructorWithByteParams | Constructs object types 1 and 45 — byte-level parameter init, called with (0,0) |
| 004893c0 | sub_4893C0 | Constructs object types 35/36/39-42 (372-376 bytes) — base init before vtable override |
| 0048c9f0 | ObjectConstructorWithZeroedFields | Constructs object type 3 (1108-byte) — zeroes large field block then sets vtable |
| 0048eaa0 | LargeConstructor | Constructs object types 11-16,18-20,22 (384+-byte) — full initialization |
| 0048fe60 | UIComponentInit5 | Constructs UI component types 7-10 (232-byte) — UI element base init |
| 004c5db0 | ShortComputation_5db0 | Post-construction computation on object types 16/22 — called on field at offset 96 |
| 00566650 | StringCopyWithBufferRealloc | Copies track DB filename string into type-1 object's string buffer at offset 57 |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates memory (operator new with no-throw) — returns NULL on failure |

**Guard conditions:** Range check: `a2 - 1 < 0 || v2 >= 508` → ID out of bounds, return 0. Cache hit: `this[v2 + 1607]` (object already created) → return cached pointer, skip construction. ID > 436 → return cached value (no construction for high IDs except 436). Allocation failure: `OperatorNewNhMallocWrapper` returns NULL → store 0 in cache, return 0/NULL. Default switch case (IDs not 1-45 or 436) → return cached value.
