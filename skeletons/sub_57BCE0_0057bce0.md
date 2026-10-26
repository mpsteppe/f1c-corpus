## sub_57BCE0_0057bce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithFlagCleanup (0057bcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x940 | RW | — | [LLM] |
| this | 0xAF4 | RW | 0 | [LLM] |
| this | 0xAFC | R | — | [LLM] |
| this | 0xB10 | RW | 0 | [LLM] |
| this | 0xB18 | R | — | [LLM] |
| this | 0xB2C | RW | 0 | [LLM] |
| this | 0xB34 | R | — | [LLM] |
| this | 0xB3C | RW | 0 | [LLM] |
| this | 0xB44 | R | — | [LLM] |
| this | 0xB68 | RW | 0 | [LLM] |
| this | 0xB70 | R | — | [LLM] |
| this | 0xB94 | RW | 0 | [LLM] |
| this | 0xB9C | R | — | [LLM] |
| this | 0xBC0 | RW | 0 | [LLM] |
| this | 0xBC8 | R | — | [LLM] |
| this | 0xBEC | RW | 0 | [LLM] |
| this | 0xBF4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x940: [LLM: once/conditional? does external poke survive?]
- this 0xAF4: [LLM: once/conditional? does external poke survive?]
- this 0xB10: [LLM: once/conditional? does external poke survive?]
- this 0xB2C: [LLM: once/conditional? does external poke survive?]
- this 0xB3C: [LLM: once/conditional? does external poke survive?]
- this 0xB68: [LLM: once/conditional? does external poke survive?]
- this 0xB94: [LLM: once/conditional? does external poke survive?]
- this 0xBC0: [LLM: once/conditional? does external poke survive?]
- this 0xBEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c990 | SEH_57BCE0 | R | [LLM] |
| 0059e1a8 | CloseHandle | R | [LLM] |
| 005b8a00 | off_5B8A00 | R | PhysicsVtable [DERIVED] |
| 005b8a68 | off_5B8A68 | R | IOOpsVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499ae0 | FreeIfNonNull | [LLM] |
| 0057e530 | sub_57E530 | [LLM] |
| 0057fbe0 | NetworkCleanup_fbe0 | [LLM] |
| 00581880 | LinkedListDestructionWithVTableReleaseCall | [LLM] |
| 005819c0 | LinkedListDestroyWithVtableDestructorCall | [LLM] |
| 00581a80 | LinkedListCleanup | [LLM] |
| 005822b0 | LinkedListFreeStandard | [LLM] |
| 00582310 | CloseHandleWrapper | [LLM] |
| 00582650 | sub_582650 | [LLM] |
| 00582a10 | sub_582A10 | [LLM] |
| 00582ce0 | sub_582CE0 | [LLM] |
| 00582dc0 | LinkedBufferCleanup | [LLM] |
| 00583ae0 | sub_583AE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
