## ServerSessionGateCheck_0042ae60 — SessionTypeFiveGateCheck

**Summary:** Gate for session type 5. Returns 0 if session type mismatch or if vehicle on lap 2 without pit call. Returns 1 to allow pass.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Overtaking (0042af70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4094 | R | — | lapOfRun [CONFIRMED] |
| this | 0x454C | R | — | callToBox [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4094 | == | 2 | lapOfRun [CONFIRMED] |
| this | 0x454C | != | 1 | callToBox [CONFIRMED] |

**Guard interpretation:** SessionType must be 5 to proceed. PASSES when (callToBox == 1) OR (lapOfRun != 2) — vehicle is either called to pits or not yet on lap 2. BLOCKED when SessionType != 5, OR (SessionType == 5 AND callToBox != 1 AND lapOfRun == 2).
