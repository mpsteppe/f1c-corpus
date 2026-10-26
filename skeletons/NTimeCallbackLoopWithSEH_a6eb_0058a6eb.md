## NTimeCallbackLoopWithSEH_a6eb_0058a6eb — ForwardStepCallbackN

**Summary:** Calls a callback function N times while stepping forward through memory. Starts from base pointer, increments by step size each iteration. Forward-iterating counterpart to NTimeCallbackLoopWithSEH.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_502F31 (00502f31), sub_506003 (00506003), sub_581D40 (00581d40), sub_581FD0 (00581fd0), sub_5823C0 (005823c0), sub_5824F0 (005824f0), sub_582780 (00582780), sub_5828B0 (005828b0), sub_582BA0 (00582ba0), ObjectAllocationWithSEH (005830c0), sub_5837F0 (005837f0), sub_586320 (00586320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | SEH exception handler (referenced in scope table) |
| 005b8cb8 | stru_5B8CB8 | R | SEH registration scope table |
| ff00000000001692 | byte_FF00000000001692 | R | KUSER_SHARED_DATA / TEB low-address bytes |
| ff00000000001695 | byte_FF00000000001695 | W | unknown |
| ff0000000000169b | byte_FF0000000000169B | RW | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a677 | sub_58A677 | Callback invocation delegate (stepping + call) |

**Guard conditions:** Loop runs for i from 0 to a3-1. If a3 <= 0, loop body never executes; returns 0 immediately.
