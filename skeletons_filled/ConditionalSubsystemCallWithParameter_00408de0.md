## ConditionalSubsystemCallWithParameter_00408de0 — ConditionalSubsystemCallWithParameter

**Summary:** Conditionally invokes a subsystem operation and optional render draw with clipping, guarded by an enable flag and a sub-object pointer. Part of camera/view render pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ViewCameraModeDispatch (00409440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Guard enable flag (this[2]), must be non-zero to proceed |
| this | 0xC | R | — | Pointer to sub-object with render parameters (this[3]) |
| this | 0x28 | R | — | Sub-object field at offset 0x1C (render width/coordinate parameter) |
| this | 0x2C | R | — | Sub-object field at offset 0x20 (render height/coordinate parameter) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00686b75 | unk_686B75 | R | VEH[33].0x43DD — static parameter passed to render operation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541ca0 | sub_541CA0 | Performs subsystem operation on input parameter a2 |
| 00543440 | RenderDrawOperationWithClipping | Renders draw operation with clipping rectangle using sub-object dimensions |

**Guard conditions:** this[2] must be non-zero → proceed to sub_541CA0(a2). Then a2 must evaluate to zero (post-call) AND this[3] (sub-object pointer) must be non-null → call RenderDrawOperationWithClipping. Otherwise → skip.
