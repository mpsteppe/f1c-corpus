## ThreadResumeWithMutexWait_00585680 — ResumeThreadWithMutexWait

**Summary:** Waits on mutex at offset 0xD4, performs float operations on sub-object at 0x84 via FloatSetWithTimingCall, then waits on second mutex at offset 0x20 and resumes thread handle at offset 0x4 if suspended flag at offset 0x1C is set. Returns success/failure flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkSocketInitializationAndListen (005804a0), ThreadTerminationWithWaitCleanup (00585550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Thread handle passed to ResumeThread |
| this | 0x1C | RW | 0 | Flag byte: non-zero indicates thread needs resuming; cleared to 0 after successful resume |
| this | 0x20 | R | — | Mutex handle for second WaitForSingleObject/ReleaseMutex pair |
| this | 0x24 | R | — | Timeout (ms) for second mutex wait |
| this | 0xD4 | R | — | Mutex handle for first WaitForSingleObject/ReleaseMutex pair (also released after float ops) |
| this | 0xD8 | R | — | Timeout (ms) for first mutex wait |

**Written-by note (persistence):**
- this 0x1C: conditionally set to 0 after successful ResumeThread; persists as external write target before call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | Called in resume retry loop (delay between attempts) |
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex handles with timeout |
| 0059e1a4 | ReleaseMutex | R | Release mutex handles after critical sections |
| 0059e1f8 | ResumeThread | R | Resume suspended thread; looped if suspend count > 1 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00583660 | FloatSetWithTimingCall | Sets float value with timing on sub-object at offset 0x84 |
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | Computes float parameter for FloatSetWithTimingCall from sub-object pointer |

**Guard conditions:** First WaitForSingleObject: handle at 0xD4 must be non-NULL AND wait return value must be 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) to set v5 to sub-object pointer; else v5=0. Second WaitForSingleObject: handle at 0x20 must be non-NULL AND return 0 or 128 to set v13 to flag byte address at 0x1C; else v13=0. Skip resume loop if *v13 == 0. Resume loop aborts with failure (v11=0) if v8 >= 50 iterations without ResumeThread returning < 2.
