## QueueUserAPCAsyncProcedureCall_00585de0 — QueueUserAPCAsyncCall

**Summary:** Calls QueueUserAPC with global pfnAPC as function pointer, thread handle from `this+4` as target thread, and `this` as ULONG_PTR parameter. Queues an asynchronous procedure call for execution in the target thread.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57A730 (0057a730), sub_5853B0 (005853b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Thread handle (HANDLE) for target thread of APC |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0041a160 | pfnAPC | R | Global APC function pointer passed to QueueUserAPC |
| 0059e1f4 | QueueUserAPC | R | Win32 API: queues APC to thread |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always calls QueueUserAPC with available parameters.
