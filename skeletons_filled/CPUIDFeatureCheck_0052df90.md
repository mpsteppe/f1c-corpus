## CPUIDFeatureCheck_0052df90 — CPUIDCheckMMXSupport

**Summary:** Executes CPUID with EAX=1 and checks EDX bit 23 (MMX feature flag at unk_800000). Returns 1 if MMX supported, 0 otherwise. Clears MMX state via _m_empty() before returning.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateCheckAndConditionalInit (0052df70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | unknown |
| 005b47f8 | stru_5B47F8 | R | CPUID feature block data structure |
| 00800000 | unk_800000 | R | CPUID EDX bit 23 mask (MMX feature flag) |
| ff00000000001692 | byte_FF00000000001692 | R | unknown |
| ff00000000001695 | byte_FF00000000001695 | W | unknown |
| ff00000000001699 | byte_FF00000000001699 | RW | unknown |
| ff0000000000169b | byte_FF0000000000169B | RW | unknown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** returns 0 early if CPUID EDX & 0x800000 (MMX bit) is zero (MMX not supported); PASSES if MMX available, returns 1
