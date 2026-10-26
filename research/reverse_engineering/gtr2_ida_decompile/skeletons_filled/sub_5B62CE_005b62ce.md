## sub_5B62CE_005b62ce — compose 4x4 transform matrix from scale, quaternion, pivot and translation (MMX)

**Summary:** Large MMX routine that fills the 16-float matrix at `a1` from up to three optional transform ingredients: a scale vector (`a4`), a rotation quaternion (`a3`) optionally applied about pivot `a2`, then a second quaternion (`a6`) applied about pivot `a5`, then an extra translation (`a7`). Quaternion-to-matrix conversion uses the standard `1 - 2(x²+...)`, `2(xy ± zw)` packed-float formulas; when inputs are null it emits identity / diagonal-scale-only / scale-about-pivot variants.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix qword 0 (float elements f0,f1 — first row pair); set to identity (1.0, 0.0) or to composed rotation/scale products, and re-read during the in-place multiply passes. |
| this | 0x8 | R | — | Output matrix qword 1 (f2,f3); read back during the multiply stages. |
| this | 0x10 | R | — | Output matrix qword 2 (f4,f5); in the identity case written as (0.0, 1.0) via shuffle of 1.0f. |
| this | 0x18 | R | — | Output matrix qword 3 (f6,f7); read back during the multiply stages. |
| this | 0x20 | R | — | Output matrix qword 4 (f8,f9); read back during the multiply stages. |
| this | 0x28 | R | — | Output matrix qword 5 (f10,f11); identity/scale branch places the middle diagonal value (f10) here. |
| this | 0x30 | R | — | Output matrix qword 6 (f12,f13) — bottom-row x,y (translation pair); pivot and final translation adds (`+a2`, `-a5`/`+a5`, `+a7`) are applied to this slot. |
| this | 0x38 | R | — | Output matrix qword 7 (f14,f15) — bottom-row z and homogeneous element; holds pivot z / translation z and the trailing 1.0 (or `1 - scale.z` compensation). |

**Written-by note (persistence):**
- this 0x0: overwritten on every call — either identity/scaled basis or recomputed from the quaternion/scale inputs in each multiply stage; an external poke would not survive the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729018 | qword_729018 | R | Read-only MMX packed-float constant pool entry used by this routine (the 1.0f/1.0f-type literal consumed by the quaternion→matrix `1 - 2x²…` terms). |
| 00729028 | qword_729028 | R | Read-only MMX packed-float constant pool entry used by the quaternion→matrix math (shuffle/scale constant). |
| 00729038 | qword_729038 | R | Read-only MMX packed-float constant pool entry used by the quaternion→matrix math (shuffle/scale constant). |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** All branching is null-pointer selection, no value checks. `a4` (scale) is the master gate: if `a4 == 0` the whole compose is skipped and `a1` becomes plain identity. With `a4 != 0`: `a3 != 0` → full quaternion rotation path, and inside it `a2 != 0` selects the pivot variant (translation seeded to `-a2`, restored with `+a2` at the end) while `a2 == 0` builds rotation×scale directly; `a3 == 0 && a2 != 0` → scale about pivot `a2` (`(1-s)·p` translation terms); `a3 == 0 && a2 == 0` → plain diagonal scale. Afterwards, `a6 != 0` runs the second quaternion pass, where `a5 != 0` selects the pivot sandwich (`result -= a5`, rotate, `result += a5`) and `a5 == 0` rotates without pivot; finally `a7 != 0` adds the extra translation. `_m_femms` always executes before return.
