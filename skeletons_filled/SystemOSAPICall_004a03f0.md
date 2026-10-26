## SystemOSAPICall_004a03f0 — SystemOSAPICall

**Summary:** Shows OS cursor (busy-waits until ShowCursor > 0), resets global state to 0, runs a short computation, and initializes audio mixer device. Called during main menu and session transitions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainMenuTransition (00404f30), sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2c4 | ShowCursor | R | OS ShowCursor API — shows/hides mouse cursor; loop waits until display count > 0 |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a0ad0 | ShortComputation_0ad0 | Short computation on the this context |
| 004a0d30 | GlobalStateSetter | Sets global state to 0 (reset) |
| 004c85d0 | AudioMixerDeviceInit | Initializes audio mixer device from scene name |

**Guard conditions:** No guard — ShowCursor busy-loop until visible, then unconditional execution
