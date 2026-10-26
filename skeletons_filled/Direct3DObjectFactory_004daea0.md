## Direct3DObjectFactory_004daea0 — UIWidgetFactory

**Summary:** Factory function allocating and initializing UI widget objects of various types (0,1,2,6,7,8,0xD,0x11,0x13) based on type ID. Sets vtable pointer and common fields. Returns new object pointer or NULL on allocation failure. Part of UI/widget system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D88D0 (004d88d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004db02c | jpt_4DAEB6 | R | Switch jump table for type ID dispatch |
| 004db054 | byte_4DB054 | R | Data referenced near switch table (likely type metadata) |
| 005acf70 | off_5ACF70 | R | VtablePtr_5ACF70 [DERIVED] |
| 005acf8c | off_5ACF8C | R | VTable_InputHandler [DERIVED] |
| 005acfa8 | off_5ACFA8 | R | VTablePtr7 [DERIVED] |
| 005acfc4 | off_5ACFC4 | R | GameObjVTable [DERIVED] |
| 005acfe0 | off_5ACFE0 | R | PTR_VTABLE_5ACFE0 [DERIVED] |
| 005acffc | off_5ACFFC | R | Ptr_VTable2 [DERIVED] |
| 005ad018 | off_5AD018 | R | VtablePtr_5AD018 [DERIVED] |
| 005ad034 | off_5AD034 | R | Vtable_UIWidgetFactory [DERIVED] |
| 005ad050 | off_5AD050 | R | VTablePtr_5AD050 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004db070 | ConstructorVTable3Fields | Initializes additional fields for type IDs 7 and 0x11 |
| 004db0e0 | SmallStructConstructor_b0e0 | Initializes additional fields for type ID 8 |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation with size parameter |

**Guard conditions:**
- Line 10: Switch on type ID (passed as `this` in ecx). Case 0/1/2/6/7/8/0xD/0x11/0x13: allocate and init. Default: return NULL (unhandled type).
- Lines 14-15, 23-24, 32-33, etc.: Allocation returns NULL. PASS: goto LABEL_20 (return NULL). BLOCK: continue initialization.
