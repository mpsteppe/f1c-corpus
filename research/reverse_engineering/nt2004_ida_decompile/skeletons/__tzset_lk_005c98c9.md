## __tzset_lk_005c98c9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** LazyInitSingletonWithFlagGuard [structural] (005c989b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d523c | GetTimeZoneInformation | R | [LLM] |
| 005d529c | WideCharToMultiByte | R | [LLM] |
| 005f6fb0 | VarName | R | [LLM] |
| 00626420 | dword_626420 | RW | [LLM] |
| 00626424 | dword_626424 | W | [LLM] |
| 00626428 | dword_626428 | W | [LLM] |
| 006264ac | lpMultiByteStr | R | [LLM] |
| 006264b0 | off_6264B0 | R | [LLM] |
| 006264b8 | dword_6264B8 | W | [LLM] |
| 006264c8 | dword_6264C8 | W | [LLM] |
| 007ff1f8 | CodePage | R | [LLM] |
| 007ff270 | dword_7FF270 | W | [LLM] |
| 007ff278 | TimeZoneInformation | R | [LLM] |
| 007ff27c | byte_7FF27C | R | [LLM] |
| 007ff2be | byte_7FF2BE | R | [LLM] |
| 007ff2cc | byte_7FF2CC | R | [LLM] |
| 007ff2d0 | byte_7FF2D0 | R | [LLM] |
| 007ff312 | byte_7FF312 | R | [LLM] |
| 007ff320 | byte_7FF320 | R | [LLM] |
| 007ff324 | dword_7FF324 | RW | [LLM] |
| ff00000000005ef3 | byte_FF00000000005EF3 | R | [LLM] |
| ff00000000005efc | byte_FF00000000005EFC | R | [LLM] |
| ff00000000005efd | byte_FF00000000005EFD | R | [LLM] |
| ff00000000005efe | byte_FF00000000005EFE | R | [LLM] |
| ff00000000005eff | byte_FF00000000005EFF | R | [LLM] |
| ff00000000005f00 | byte_FF00000000005F00 | R | [LLM] |
| ff00000000005f01 | byte_FF00000000005F01 | R | [LLM] |
| ff00000000005f02 | byte_FF00000000005F02 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005beab0 | _strncpy | [LLM] |
| 005bebfe | _atol | [LLM] |
| 005c1a4e | _malloc | [LLM] |
| 005c1b88 | sub_5C1B88 | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |
| 005c5315 | __unlock | [LLM] |
| 005c6e40 | _strcmp | [LLM] |
| 005c6f50 | _strcpy | [LLM] |
| 005ce695 | _getenv | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `,db`
- `,db`
- `,db`
- `,db`
- `,db`
- `ldb`
- `ldb`
- `ldb`
- `ldb`
- `ldb`
