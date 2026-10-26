## WindowsAdminCheck_00423250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | [LLM] |
| 0059e000 | SetSecurityDescriptorOwner | R | [LLM] |
| 0059e00c | FreeSid | R | [LLM] |
| 0059e010 | RevertToSelf | R | [LLM] |
| 0059e014 | AccessCheck | R | [LLM] |
| 0059e018 | IsValidSecurityDescriptor | R | [LLM] |
| 0059e01c | ImpersonateSelf | R | [LLM] |
| 0059e020 | OpenThreadToken | R | [LLM] |
| 0059e024 | OpenProcessToken | R | [LLM] |
| 0059e028 | AllocateAndInitializeSid | R | [LLM] |
| 0059e02c | InitializeSecurityDescriptor | R | [LLM] |
| 0059e030 | GetLengthSid | R | [LLM] |
| 0059e034 | InitializeAcl | R | [LLM] |
| 0059e038 | AddAccessAllowedAce | R | [LLM] |
| 0059e03c | SetSecurityDescriptorDacl | R | [LLM] |
| 0059e040 | SetSecurityDescriptorGroup | R | [LLM] |
| 0059e0f0 | GetCurrentThread | R | [LLM] |
| 0059e188 | GetLastError | R | [LLM] |
| 0059e18c | GetCurrentProcess | R | [LLM] |
| 0059e190 | LocalAlloc | R | [LLM] |
| 0059e194 | LocalFree | R | [LLM] |
| 0059e840 | stru_59E840 | R | SecurityDescriptorBase [DERIVED] |
| 005c3084 | aAccesscheckFai | R | AccessCheckFailed [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | [LLM] |
| ff00000000001695 | byte_FF00000000001695 | W | [LLM] |
| ff0000000000169b | byte_FF0000000000169B | RW | [LLM] |
| ff00000000005379 | byte_FF00000000005379 | W | [LLM] |
| ff0000000000537e | byte_FF0000000000537E | W | [LLM] |
| ff0000000000537f | byte_FF0000000000537F | W | [LLM] |
| ff00000000005380 | byte_FF00000000005380 | W | [LLM] |
| ff00000000005381 | byte_FF00000000005381 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588821 | FileOpWithGlobalBuffer | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
