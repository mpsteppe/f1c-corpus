## sub_4DA5E0_004da5e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42FE80 (0042fe80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x820 | RW | — | [LLM] |
| *(this+0x8) | 0x87C | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0x820: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00601808 | aLoadingReplay | R | [LLM] |
| 0060fe88 | aDDevNascar2004_15 | R | [LLM] |
| 00610080 | aLoadingVcrFile | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 00629124 | dword_629124 | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | R | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0076612c | unk_76612C | R | [LLM] |
| 007684e0 | dword_7684E0 | R | [LLM] |
| 00768504 | dword_768504 | R | [LLM] |
| 007689cc | dword_7689CC | R | [LLM] |
| 007d7920 | dword_7D7920 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405bf0 | sub_405BF0 | [LLM] |
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 0042db60 | sub_42DB60 | [LLM] |
| 0042dc00 | sub_42DC00 | [LLM] |
| 004ba730 | sub_4BA730 | [LLM] |
| 004d82e0 | sub_4D82E0 | [LLM] |
| 004d8430 | sub_4D8430 | [LLM] |
| 004d97e0 | sub_4D97E0 | [LLM] |
| 004d9810 | sub_4D9810 | [LLM] |
| 004d9820 | sub_4D9820 | [LLM] |
| 004d9830 | sub_4D9830 | [LLM] |
| 004d9840 | sub_4D9840 | [LLM] |
| 004d9ef0 | sub_4D9EF0 | [LLM] |
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 0057a080 | ZeroInitSmallStruct [exact] | [LLM] |
| 0057a0a0 | sub_57A0A0 | [LLM] |
| 0057a110 | sub_57A110 | [LLM] |
| 0057a2f0 | AudioStreamOpen [structural] | [LLM] |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | [LLM] |
| 0057a3a0 | sub_57A3A0 | [LLM] |
| 0057a3d0 | sub_57A3D0 | [LLM] |
| 0057af60 | sub_57AF60 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005beab0 | _strncpy | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Loading Replay`
- `Loading Replay`
- `D:\dev\NASCAR_2004\Source\Replay.cpp`
- `Loading VCR File for playback`
