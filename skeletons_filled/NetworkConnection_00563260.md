## NetworkConnection_00563260 — ProcessNetworkConnectionOrInit

**Summary:** Manages network socket array initialization and server entry processing during connection setup. If socket array does not exist (a1[0]==0), creates it, processes server entries, and optionally enters a polling loop. If already initialized, handles lookup results by updating entry fields or counting display-mode queries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectoryStringProcessingWithDecode (00461ed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562d20 | SocketArrayCreate | create UDP socket array |
| 00562fe0 | AudioValueSetterCall | signal connection state change (value 3) |
| 00563000 | PollingLoopWithProcessCalls | enter polling loop for network events |
| 00563160 | ConditionalNetworkUtility | allocate and dispatch network struct |
| 005631a0 | TwoStepDispatch | lookup server entry by ID |
| 00563230 | ArrayOfStructStrideSearchByID | search array for struct by ID |
| 005633d0 | DisplayModeQueryWrapper | allocate struct and push to audio stack |
| 00563e70 | sub_563E70 | compute array count minus one |
| 005648b0 | LinearInterpolation | retrieve pointer from indexed array |
| 005648c0 | SingleFunctionCallWrapper_48c0 | call single-argument function pointer |
| 005648d0 | AudioStackPushWithOverflowRealloc | push entry to audio stack with overflow handling |
| 00564990 | ArrayElementRemovalWithShift | remove element from array and shift |
| 00598666 | inet_addr | validate/convert server address string |

**Guard conditions:** if a1[0] (socket array pointer) is zero, enters initialization path: creates socket array, processes entries, sets up bookkeeping, signals state 3, and optionally enters polling loop (if a4==0). If a1[0] is non-zero (already initialized), processes lookup results: if v7==-1 (entry not found) and a1[0] is 1 or 2, increments a1[38]; if entry found, updates entry fields and removes from array.

