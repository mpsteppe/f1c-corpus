## ConditionalStateDispatch_00463760 — Server Track Open/Close Signal Dispatch

**Summary:** Dispatches server track signals based on state and a parameter. If state check fails, calls ServerOpenedClosedNotification. If state check passes and a2 is set, calls ServerOpenTrackSignal; otherwise calls ServerCloseTrackSignal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherSurfaceUpdate (004628a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | vtable/primary pointer (passed to callees) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00460e90 | ServerOpenTrackSignal | signals server to open track |
| 00461020 | ServerCloseTrackSignal | signals server to close track |
| 00461190 | ServerOpenedClosedNotification | notifies server of track open/closed state change |
| 00461dc0 | StateCheckWrapper | checks object state to determine dispatch path |

**Guard conditions:** StateCheckWrapper(this) result selects path: if state NOT active → ServerOpenedClosedNotification (BLOCKED from open/close signals). If state active AND a2 non-zero → ServerOpenTrackSignal (PASSES open). If state active AND a2 zero → ServerCloseTrackSignal (PASSES close).
