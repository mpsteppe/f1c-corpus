## sub_4AAB60_004aab60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_49C1D0 (0049c1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | RW | — | [LLM] |
| this | 0x1E1 | RW | — | [LLM] |
| this | 0x1E2 | RW | 0 | [LLM] |
| this | 0x1EC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1E0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E1: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E2: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1EC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d513c | Sleep | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d550c | flt_5D550C | R | [LLM] |
| 005d64a0 | flt_5D64A0 | R | [LLM] |
| 005fb7e8 | Format | R | [LLM] |
| 00601a00 | aBik | R | [LLM] |
| 006088cc | byte_6088CC | RW | [LLM] |
| 00608f40 | aEasBik | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0062a0a8 | dword_62A0A8 | R | [LLM] |
| 0062a0e0 | dword_62A0E0 | R | [LLM] |
| 007d7a0c | dword_7D7A0C | R | [LLM] |
| 007da938 | unk_7DA938 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d5b0 | sub_40D5B0 | [LLM] |
| 004a8410 | sub_4A8410 | [LLM] |
| 004a8480 | sub_4A8480 | [LLM] |
| 004a85a0 | sub_4A85A0 | [LLM] |
| 004a8640 | sub_4A8640 | [LLM] |
| 004ac660 | sub_4AC660 | [LLM] |
| 004cf510 | nullsub_6 | [LLM] |
| 00527460 | sub_527460 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00578960 | sub_578960 | [LLM] |
| 005789d0 | LinkedListNodePeek [exact] | [LLM] |
| 00578a30 | sub_578A30 | [LLM] |
| 00578d80 | DirectoryEntryIterator [structural] | [LLM] |
| 00578e30 | sub_578E30 | [LLM] |
| 0057b5d0 | StructZeroInit_8ba0 [exact] | [LLM] |
| 0057b610 | QPCTimerInitialization [exact] | [LLM] |
| 0057b690 | TimerResetUsingQueryPerformanceCounter [exact] | [LLM] |
| 0057b720 | HighResolutionTimerDelta [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005beec8 | _sprintf | [LLM] |
| 005bf36d | _rand | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `%s%s`
- `*.bik`
- `eas.bik`
