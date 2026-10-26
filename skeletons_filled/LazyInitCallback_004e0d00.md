## LazyInitCallback_004e0d00 — LazyInitUISoundEffect

**Summary:** Performs one-time lazy initialization of a UI element — moves doubly-linked list node, applies position/color values, triggers sound effect, and registers in global lookup arrays. Part of UI lazy-init system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MultiSystemStructInitializer (004e0db0), ArrayEntryCleanup (004e0e20), SubsystemStateMachine (004e17c0), ActorMotionPostProcessingUpdate (004ed030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x964 | R | — | Sound effect index/ID passed to AudioSoundEffectController |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0ed0 | AudioSoundEffectController | Plays the UI activation sound effect |
| 0054b4d0 | sub_54B4D0 | Applies position/color state values to UI element |
| 0054ba00 | DoublyLinkedListNodeMover | Moves UI element node to front of linked list |

**Guard conditions:** Checks a2 param block — if *(int*)a2 is NULL (no element), returns immediately. If *(byte*)(a2+64) is non-zero (already initialized), skips initialization body. PASSES: both checks pass -> runs full init. BLOCKED: NULL element or already initialized.
