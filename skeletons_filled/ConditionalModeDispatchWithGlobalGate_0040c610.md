## ConditionalModeDispatchWithGlobalGate_0040c610 — CameraModeConditionalDispatch

**Summary:** Dispatches camera mode request based on queued mode flag. When queue active, only mode 1 passes (mapped to mode 2); when inactive, modes 1 and 2 pass (mapped to mode 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewAssignment (0040c650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | requested camera mode value (1 or 2) |
| this | 0x14 | RW | 1 | stores the dispatched mode value before calling GameActionStateMachine |

**Written-by note (persistence):**
- this 0x14: written with dispatched mode when condition passes; init value 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] — selects dispatch path: queued vs immediate |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | transitions camera action state with mode and immediate flag |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 1 | requested camera mode value |

**Guard interpretation:** When dword_7CFCC8 (queued flag) is non-zero: only this+0xC == 1 passes (stores 1, calls GameActionStateMachine(2,0)); any other value returns 1 (blocked). When queued flag is zero: this+0xC == 1 or 2 passes (stores value, calls GameActionStateMachine(0,0)); otherwise returns this+0xC (blocked).
