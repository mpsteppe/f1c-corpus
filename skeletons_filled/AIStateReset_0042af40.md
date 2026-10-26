## AIStateReset_0042af40 — ResetAIStateToRetired

**Summary:** Resets AI driver state: calls state change notification, evaluates conditional gate, sets RetiredFlag (0x4410) to 1 and ActiveFlag (0x45F4) to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewStateMachine (004bbfc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4410 | RW | 1 | RetiredFlag [FACT] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x4410: written to 1 every call; external poke overwritten on next call
- this 0x45F4: written to 0 every call; external poke overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5c80 | StateChangeNotify | Notify state change event with parameter 0 |
| 004efac0 | ConditionalGate | Evaluate conditional gate at this+12 for state transition |

**Guard conditions:** No guard conditions — unconditional state reset. Both flags always overwritten.
