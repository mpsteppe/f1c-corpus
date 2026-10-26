## RenderingCompositionSetup_0053fed0 — Rendering compositing setup with lock and blit

**Summary:** Sets up compositing surfaces via LockUnlockWrapper on source rectangle, calls sub_53F720 for surface allocation, selects output surface based on flag (1/2/4/8), then performs compositing blit via sub_5008E4 with alpha channel management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_543050 (00543050), sub_560050 (00560050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | stores return values from vtable calls |

**Written-by note (persistence):**
- this 0x0: overwritten by each call — last error code persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] — tested against a4[6] flag for alpha mode selection |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005006d5 | LockUnlockWrapper | locks source surface for reading |
| 005008e4 | sub_5008E4 | performs compositing blit operation |
| 0053f720 | sub_53F720 | allocates/initializes destination surface |
| 0055c450 | sub_55C450 | format/size query helper |

**Guard conditions:** a4[6] & 0x800 → uses a4[13] for alpha channel if available. Else if (unk_800000 & a4[6]) → uses MMX alpha path. Default alpha: -65281. If sub_53F720 fails, returns -1. Output surface selection by a5 flag bits (4=sub[4], 8=sub[5], 1=sub[2], 2=sub[3]).
