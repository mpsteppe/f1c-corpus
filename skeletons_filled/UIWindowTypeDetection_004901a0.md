## UIWindowTypeDetection_004901a0 — UIWindowTypeDetection

**Summary:** Classifies a UI window by matching its name/path string against known patterns ("UI_Load", ".c", ".r") and sets a type field accordingly. Used to determine render/behavior mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_fec0 (0048fec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | R | — | Window name/path string pointer |
| this | 0xE4 | RW | 2 | Window type classification (0=UI_Load, 1=.c, 2=.r) |

**Written-by note (persistence):**
- this 0xE4: Updated each call based on string match; persists until next classification.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005cc210 | aC_0 | R | StrExtension_c [DERIVED] |
| 005cc21c | byte_5CC21C | R | Str_UI_Load [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default application directory |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | String copy/construction into local buffer (max 63 chars) |
| 00588410 | sub_588410 | String comparison against known token/extension |

**Guard conditions:** Checks `this[46]` (offset 0xB8) — if null, defaults to `byte_5EA438`. Compares constructed string against three tokens sequentially: match `byte_5CC21C` ("UI_Load") → sets this[57]=0; match `aC_0` (".c") → sets this[57]=1; match `aR` (".r") → sets this[57]=2. Early matches do NOT skip later comparisons; all three run. Last match overwrites previous.
