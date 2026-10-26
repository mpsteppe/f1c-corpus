## sub_4DCBA0_004dcba0 — Texture/object initialization with fallback construction

**Summary:** Attempts to initialize a texture/rendering object: first tries D3D texture creation, then falls back to generic object construction with sub-init; stores configuration fields (a2, a7, a8) and computes alignment when both paths fail. Cleans up on error.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49B0A0 (0049b0a0), FloatToIntConversionDelegation (004dcc90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Allocated texture/object pointer (this[1]) |
| this | 0x14 | RW | — | Stored parameter a7 (fallback config field 5) |
| this | 0x18 | RW | — | Stored parameter a8 (fallback config field 6) |
| this | 0x1C | RW | — | Stored parameter a2 (fallback config field 7) |

**Written-by note (persistence):**
- this 0x4: written each call (re-allocated); persists until next call or cleanup
- this 0x14: written conditionally when both creation paths fail; persists until overwritten
- this 0x18: written conditionally when both creation paths fail; persists until overwritten
- this 0x1C: written conditionally when both creation paths fail; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dcd10 | ResourceCleanup_cd10 | Cleanup/destructor for current object state |
| 004dcdd0 | PositionComputationWithAlignment | Compute position with alignment parameters |
| 0053cbc0 | sub_53CBC0 | Process additional parameter a10 (linked-list or registration) |
| 0053ce40 | PhysicsObjectLinkedListRemoval | Remove physics object from linked list |
| 0054fe10 | StructInitWithZeroFill | Allocate and zero-fill a struct |
| 00550080 | D3DTextureCreation | Create D3D texture from parameter a3 |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | Generic object constructor with allocation and sub-init |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation wrapper (operator new) |

**Guard conditions:** First guards on `a3` parameter — if non-null, attempts D3D texture creation path. Inside that path, `a10` parameter gates `sub_53CBC0` call. `D3DTextureCreation` return value branches: if non-zero (failure), sets error flag and skips to cleanup; if zero (success), falls through to object construction path. `ObjectConstructorWithAllocationAndSubInit` return value gates: if success, sets error flag; if failure, stores fallback fields.
