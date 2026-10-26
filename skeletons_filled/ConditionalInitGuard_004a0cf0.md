## ConditionalInitGuard_004a0cf0 — ConditionalInitGuard

**Summary:** Guards initialization logic against the HUD-disable flag. Only runs sub_4A0250 and resets InitZeroFieldSet when DisableHUDFlag is 0. Returns the DisableHUDFlag value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RestartGate (004a0fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce258 | dword_7CE258 | W | InitZeroFieldSet [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a0250 | sub_4A0250 | Performs initialization routine for session state |

**Guard conditions:** DisableHUDFlag (byte_7CE254) must be 0 to execute sub_4A0250 and set dword_7CE258 = 0. If byte_7CE254 is non-zero, skips both operations and returns byte_7CE254 directly.
