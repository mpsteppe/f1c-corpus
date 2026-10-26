## sub_51FBF0_0051fbf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| obj | 0x18 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e8f3b | byte_6E8F3B | R | [LLM] |
| 0071bf40 | aReflectionrend_0 | R | [LLM] |
| 0071bf60 | aReflectionrend | R | [LLM] |
| 0071bf80 | aRreflect22d | R | [LLM] |
| 0071bfd0 | aTunnel22d | R | [LLM] |
| 00757c10 | dword_757C10 | R | [LLM] |
| 00800000 | byte_800000 | R | [LLM] |
| 0091bca0 | flt_91BCA0 | R | [LLM] |
| 0091bdd8 | dword_91BDD8 | R | [LLM] |
| 0091e088 | dword_91E088 | R | [LLM] |
| 00be10b8 | dword_BE10B8 | R | [LLM] |
| 00fb1ce0 | dword_FB1CE0 | R | [LLM] |
| 00fb2ea0 | unk_FB2EA0 | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401190 | sub_401190 | [LLM] |
| 0051d6c0 | sub_51D6C0 | [LLM] |
| 0051e910 | sub_51E910 | [LLM] |
| 0051fa00 | sub_51FA00 | [LLM] |
| 0051fad0 | sub_51FAD0 | [LLM] |
| 00591de0 | sub_591DE0 | [LLM] |
| 005da9a0 | sub_5DA9A0 | [LLM] |
| 005e5b30 | sub_5E5B30 | [LLM] |
| 005f61a0 | sub_5F61A0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `ReflectionRenderToTextureTrack`
- `RREFLECT%2.2d`
- `TUNNEL%2.2d`
