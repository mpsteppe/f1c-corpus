## GameStateBranchDispatch_0040d100 — GameStateBranchDispatch

**Summary:** Dispatches camera mode and game action based on global dispatch mode selector (dword_7CFDC4 values 1-4). Branches to ViewCameraModeDispatch and GameActionStateMachine with paired mode/action IDs. Part of game state management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_40C140 (0040c140), NetCommPlayerSlotSync (0045fc50), sub_4A00A0 (004a00a0), sub_4C6B60 (004c6b60), PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Camera/session pointer (this[6]), must be non-zero for dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d198 | jpt_40D118 | R | Jump table for dispatch mode selector (4 cases + default) |
| 007cfdc4 | dword_7CFDC4 | R | DispatchModeSelector [CONFIRMED] (also: Dispatch mode selector (0-3) — values 1-4 select camera mode + action pairs |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409440 | ViewCameraModeDispatch | Dispatches camera view mode with mode ID |
| 0040cde0 | GameActionStateMachine | Executes game action state machine with given action ID |

**Guard conditions:** this[6] (offset 0x18) must be non-zero → dispatch proceeds. If zero → early return.
