## ShortComputation_6100_00406100 — GuardedAudioInitCompute

**Summary:** Guarded initialization and computation for audio subsystem. Checks sample info pointer validity before performing one-time registration and delegating to a computation function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundPositioningUpdate (00405b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | pointer to sample info structure |
| this | 0x68 | R | — | unknown (not directly referenced in decompiled code) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | performs one-time registration for audio subsystem init |
| 00407e10 | ShortComputation_7e10 | delegates actual computation to this function |

**Guard conditions:** checks this[22] (offset 0x58) != NULL, then checks *(this[22]+16) != NULL — if either check fails, returns early without performing initialization or computation
