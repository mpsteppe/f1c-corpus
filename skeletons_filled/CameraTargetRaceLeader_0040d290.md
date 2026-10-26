## CameraTargetRaceLeader_0040d290 — CameraTargetRaceLeader

**Summary:** Resolves race leader's team ID based on current player's vehicle and a direction flag, then dispatches game state change to target that leader.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyboardInputActionMapper (0040be70), RandomStateMachineWithTimerAndTrigger (0040c070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c540 | GetTeamIDByFinishPosition | gets team ID at adjusted finish position (offset +1 or -1 from current player) |
| 0040d240 | GameStateDispatchChain | dispatches full game state change to the resolved target |

**Guard conditions:** if a2 is non-zero, shifts forward one position to target leader; if zero, shifts backward. Delegates to GetTeamIDByFinishPosition for position adjustment.
