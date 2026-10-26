## QuaternionConstructionTransform_0051febe — ColorVectorTransform

**Summary:** Takes four unsigned int color/vector components (a2-a4), packs them with constant dword_8D6160 into an SSE register, applies color channel mask (xmmword_8D6150), calls RGBAColorSpaceConversion, then performs shuffle/multiply/XOR with sign mask (xmmword_8D6140) to produce final result. Likely a color or vector space transform reusing SSE math pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output __m128 result of color/vector transform |

**Written-by note (persistence):**
- this 0x0: unconditionally written with transformed result; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d6140 | xmmword_8D6140 | R | XOR sign-flip mask for final transform |
| 008d6150 | xmmword_8D6150 | R | Color channel mask for RGBA component extraction |
| 008d6160 | dword_8D6160 | R | Constant packed into SSE register alongside input components |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005289e0 | RGBAColorSpaceConversion | Converts RGBA packed color to different color space |

**Guard conditions:** No guard — always computes result unconditionally.
