## sub_5B7CBE_005b7cbe — compose 4x4 transform matrix from quaternion, scale, pivot and translation (MMX, pfpnacc variant)

**Summary:** Near-twin of the 7-argument transform compose (sub_5B62CE): fills the 16-float matrix at `a1` from scale vector (`a4`), rotation quaternion (`a3`) with optional pivot `a2`, a second quaternion (`a6`) with optional pivot `a5`, and a trailing translation (`a7`). This variant builds the quaternion→matrix terms with `_m_pfpnacc`/`_m_pswapd` and constructs the identity case via `_m_pswapd(1.0f)`.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix qword 0 (f0,f1 — first row pair); identity (1.0,0.0) or composed rotation/scale products, re-read in the in-place multiply passes. |
| this | 0x8 | R | — | Output matrix qword 1 (f2,f3); read back during the multiply stages. |
| this | 0x10 | R | — | Output matrix qword 2 (f4,f5); identity case writes (0.0,1.0) here via `_m_pswapd`. |
| this | 0x18 | R | — | Output matrix qword 3 (f6,f7); read back during the multiply stages. |
| this | 0x20 | R | — | Output matrix qword 4 (f8,f9); read back during the multiply stages. |
| this | 0x28 | R | — | Output matrix qword 5 (f10,f11); scale/identity middle diagonal element lives here. |
| this | 0x30 | R | — | Output matrix qword 6 (f12,f13) — bottom-row x,y (translation pair); pivot compensation (`±a2`, `±a5`) and `+a7` applied here. |
| this | 0x38 | R | — | Output matrix qword 7 (f14,f15) — bottom-row z and homogeneous element; pivot z / translation z and trailing 1.0 (or `1 - scale.z` term). |

**Written-by note (persistence):**
- this 0x0: recomputed on every call — identity or composed from quaternion/scale inputs during the multiply stages; an external poke would not survive the call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729018 | qword_729018 | R | Read-only MMX packed-float constant pool entry used by this routine (1.0f/1.0f-type literal of the quaternion→matrix terms). |
| 00729028 | qword_729028 | R | Read-only MMX packed-float constant pool entry used by the quaternion→matrix math. |
| 00729038 | qword_729038 | R | Read-only MMX packed-float constant pool entry used by the quaternion→matrix math. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Null-pointer selection only, no value checks. `a4 == 0` blocks everything and leaves plain identity in `a1`. With `a4 != 0`: `a3 != 0` → quaternion rotation path, where `a2 != 0` selects the pivot variant (translation seeded `-a2`, restored `+a2`) and `a2 == 0` builds rotation×scale directly; `a3 == 0 && a2 != 0` → scale about pivot `a2`; `a3 == 0 && a2 == 0` → plain diagonal scale. Then `a6 != 0` runs the second quaternion pass with optional pivot `a5` (subtract → rotate → add); finally `a7 != 0` adds the extra translation. `_m_femms` always executes.
