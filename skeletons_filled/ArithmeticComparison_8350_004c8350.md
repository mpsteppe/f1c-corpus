## ArithmeticComparison_8350_004c8350 — Singleton manager shutdown/cleanup

**Summary:** Destructor dispatch for four global singleton managers: AudioMixerPtr (dword_8AC4C8), SceneManagerPtr (dword_8AC4CC), SingletonMgrPtr_3 (dword_8AC4D0), and InitStatus (dword_8AC4C4). Calls each object's destructor (vtable offset 4 for first three, offset 12 for InitStatus) and zeroes the pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ListDestructorWithSubFree (004c8210), InitWithStatusCheck (004c82c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac4c4 | dword_8AC4C4 | RW | InitStatus [DERIVED] |
| 008ac4c8 | dword_8AC4C8 | RW | AudioMixerPtr [DERIVED] |
| 008ac4cc | dword_8AC4CC | RW | SceneManagerPtr [DERIVED] |
| 008ac4d0 | dword_8AC4D0 | RW | SingletonMgrPtr_3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** each pointer checked individually — if non-zero, call destructor and set to 0; if zero, skip that entry.
