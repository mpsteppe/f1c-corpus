## StringNameMatching_004fc700 — MatchAndUpdateCloudSceneNames

**Summary:** Matches cloud scene object names against stored buffers; when names differ, copies new name data and triggers cloud texture setup or stores session type config. Used for switching cloud scene variants.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | — | stored type/configuration value (incrementing) |
| this | 0x6F | RW | 0 | null terminator for first name buffer (+0x50) |
| this | 0xA3 | RW | 0 | null terminator for second name buffer (+0x84) |

**Written-by note (persistence):**
- this 0x44: conditional — written when names mismatch (else branch) or match with type update; external poke survives until next call
- this 0x6F: conditional — written to 0 after name copy; external poke survives until next call
- this 0xA3: conditional — written to 0 after name copy; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9a00 | PackedFlagRead_9a00 | read packed flag from scoring data |
| 004fc550 | sub_4FC550 | load common logo map and setup cloud textures |
| 00587dd0 | sub_587DD0 | copy memory block (31 bytes) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44 | != | 18446744073709551615 | stored type check vs -1 sentinel |

**Guard interpretation:** this+0x44 == -1 AND names match → skip update entirely. this+0x44 != -1 AND names match → update stored type only (no string copy). dword_7C56A0 bit 0 set (multiplayer) AND v10==0 (ScoringGate==2 AND flag clear) → block entire function. v10 set OR new type matches SessionType → call sub_4FC550 for cloud texture setup. v10 clear AND type mismatch → store type in this+0x44 without texture setup.
