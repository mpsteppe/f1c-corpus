## sub_43DFB0_0043dfb0 — ComputeFrontSuspensionGeometry

**Summary:** Computes front suspension arm geometry for both left and right wheels. Looks up steering and fore-link bar endpoints via SuspensionBarLookup, transforms them by the chassis rotation matrix, normalizes direction vectors, and calculates suspension arm angles stored as projected scalar values.

**Called by:** sub_43BB20 (0043bb20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1854) | 0x0 | R | — | First double from source data block A — copied to this+0x1858 |
| *(this+0x1854) | 0x4 | R | — | Second double from source data block A — copied to this+0x185C |
| *(this+0x1868) | 0x0 | R | — | First double from source data block B — copied to this+0x186C |
| *(this+0x1868) | 0x4 | R | — | Second double from source data block B — copied to this+0x1870 |
| this | 0x60 | RW | — | Computed time value (double): a2.step * a2.dt + a2.base |
| this | 0x68 | RW | 0 | Reciprocal of time delta (1/dt) — set to 0 if dt <= 0 |
| this | 0x6C | RW | 0 | Zeroed when dt <= 0 (paired with this+0x68) |
| this | 0x70 | RW | — | Time value from a2: (a2.step_count - 1) * a2.dt + a2.base |
| this | 0x78 | RW | — | Scaled factor: this+0x68 * this+0x70 |
| this | 0xA4 | RW | — | Half negative time: this+0x60 * -0.5 |
| this | 0xB4 | RW | 0 | Zero-initialized flag/accumulator |
| this | 0xB8 | RW | 0 | Zero-initialized flag/accumulator |
| this | 0x3FC | R | — | Pointer to left-side suspension data (passed to SuspensionBarLookup for fl_ bars) |
| this | 0x8E4 | R | — | Pointer to right-side suspension data (passed to SuspensionBarLookup for fr_ bars) |
| this | 0x1814 | R | — | Pointer to chassis 3x3 rotation matrix + position (offset +4 = matrix, +28 = position) |
| this | 0x1854 | R | — | Source data pointer A — first two doubles copied to this+0x1858/0x185C |
| this | 0x1858 | RW | — | Cached double from source A element 0 |
| this | 0x185C | RW | — | Cached double from source A element 1 |
| this | 0x1860 | RW | — | Left (fl) suspension arm angle: projected scalar from normalized direction cross product |
| this | 0x1868 | R | — | Source data pointer B — first two doubles copied to this+0x186C/0x1870 |
| this | 0x186C | RW | — | Cached double from source B element 0 |
| this | 0x1870 | RW | — | Cached double from source B element 1 |
| this | 0x1874 | RW | — | Right (fr) suspension arm angle: projected scalar from normalized direction cross product |

**Written-by note (persistence):**
- this 0x60: recalc every call — overwritten
- this 0x68: recalc every call — overwritten (set to 0 or 1/dt)
- this 0x6C: recalc every call — overwritten (0 when dt<=0)
- this 0x70: recalc every call — overwritten
- this 0x78: recalc every call — overwritten
- this 0xA4: recalc every call — overwritten
- this 0xB4: recalc every call — overwritten (always 0)
- this 0xB8: recalc every call — overwritten (always 0)
- this 0x1858: recalc every call — overwritten from source pointer
- this 0x185C: recalc every call — overwritten from source pointer
- this 0x1860: recalc every call — overwritten (computed angle)
- this 0x186C: recalc every call — overwritten from source pointer
- this 0x1870: recalc every call — overwritten from source pointer
- this 0x1874: recalc every call — overwritten (computed angle)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54c0 | dbl_5D54C0 | R | Constant 0.0 for zero vector component |
| 005d54c8 | dbl_5D54C8 | R | Constant -1.0 for cross product negation |
| 005d54d0 | dbl_5D54D0 | R | Constant 1.0 for normalization and cross product |
| 005d5fb8 | dbl_5D5FB8 | R | Constant -0.5 for halving |
| 005fe2e4 | aFrSteering | R | String "fr_steering" — lookup key for right steering bar |
| 005fe2f0 | aFlSteering | R | String "fl_steering" — lookup key for left steering bar |
| 005fe3d4 | aFrForeLower | R | String "fr_fore_lower" — lookup key for right front lower arm |
| 005fe3e4 | aFrForeUpper | R | String "fr_fore_upper" — lookup key for right front upper arm |
| 005fe3f4 | aFlForeLower | R | String "fl_fore_lower" — lookup key for left front lower arm |
| 005fe404 | aFlForeUpper | R | String "fl_fore_upper" — lookup key for left front upper arm |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004388f0 | F_3DVectorTransformBy33Matrix [exact] | Transform 3D bar endpoint by chassis rotation matrix — converts local suspension points to world space |
| 0043d970 | SuspensionBarLookup [structural] | Look up suspension bar endpoints by name string and side data pointer |

**Guard conditions:** Only guard is the dt <= 0 check: if computed time delta (v8) <= 0, sets this+0x68 and this+0x6C to 0 instead of computing 1/dt. No other branching.

**String literals referenced (deterministic):**

- `fr_steering`
- `fl_steering`
- `fr_fore_lower`
- `fr_fore_upper`
- `fl_fore_lower`
- `fl_fore_upper`
