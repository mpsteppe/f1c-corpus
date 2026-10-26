## TimerInitWithSEH_005835f0 — QPCTimerStructInit

**Summary:** Initializes a high-precision timer structure by zero-initializing the data area, setting up a QPC (QueryPerformanceCounter) timer, and calling FloatSetWithTimingCall to configure timing parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5837F0 (005837f0), StartAddress (00583d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ce4b | SEH_5835F0 | R | SEH handler registration for exception protection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568ba0 | StructZeroInit_8ba0 | Zero-initialize the timer's data structure |
| 00568be0 | QPCTimerInitialization | Initialize QPC-based high-precision timer |
| 00583660 | FloatSetWithTimingCall | Configure timing-related float parameters |

**Guard conditions:** none — no conditional guards based on field checks.
