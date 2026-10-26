## EnumToEnumTranslator_00462d30 — Join Error Code Translator

**Summary:** Translates join-session error enum values: passes through a delegation guard check, calls sub_57A590 to convert input, then maps result 0→0, 1→3, 2→1, 3→2, 4→3, 5→4, default→3. Returns 0 on delegation failure or unknown input.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | sub-object pointer for delegation guard check |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a590 | sub_57A590 | converts input enum to intermediate value for mapping |
| 0057a900 | SingleDelegationCall_a900 | delegation guard check on sub-object; non-zero = blocked |

**Guard conditions:** SingleDelegationCall_a900 returns non-zero (delegation active): BLOCKED, return 0. sub_57A590 returns 0: BLOCKED, return 0. PASSES only when both return non-zero (delegation not active, intermediate value valid).
