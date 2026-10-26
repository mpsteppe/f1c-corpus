## sub_4ACA10_004aca10 — Parse float setting and refresh text buffers

**Summary:** Reads a string field (offset 0xA0, falling back to WindowName when null), converts it with atof into a float field at this+0x114 (defaults to 5.0f when the parsed value is 0.0), then re-parses/refreshes several global text buffers and copies their strings into owned buffers via StringCopyWithBufferRealloc. UI/text configuration helper.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | R | — | Source string pointer parsed with atof; null falls back to WindowName |
| this | 0x114 | RW | 1084227584 → 5.0f | Float value parsed from the 0xA0 string; forced to 5.0f when parsed result is 0.0 |

**Written-by note (persistence):**
- this 0x114: recalculated at the start of every call from the this+0xA0 string (or WindowName when null); an external poke survives only until this function runs again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback string for a null this+0xA0 field and for null strings returned from the buffer accessor |
| 00731ce8 | String2 | R | unknown (not visible in provided decompile) |
| 00b6f708 | dword_B6F708 | R | Global string pointer passed to sub_539600 for parsing; null falls back to WindowName |
| 00b6f724 | dword_B6F724 | R | unknown (not visible in provided decompile) |
| 00b6f740 | dword_B6F740 | R | unknown (not visible in provided decompile) |
| 00b72314 | dword_B72314 | R | Pointer to a state/mode dword; compared against 4 and 8 to decide whether the final string copy runs |
| 00be1bd0 | dword_BE1BD0 | W | Receives the result of sub_53A0E0 over unk_BE1CE0 (parsed value/count for the global buffer) |
| 00be1cdc | unk_BE1CDC | R | Global text buffer; sub_538790 returns a pointer into it whose first string and element at v5+463 are copied |
| 00be1ce0 | unk_BE1CE0 | R | Global buffer consumed by sub_539FF0/sub_53A0E0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00538790 | sub_538790 | Returns a pointer into the unk_BE1CDC buffer (string table accessor); called twice |
| 00539600 | sub_539600 | Re-parses/loads text into a buffer from the given string |
| 00539ff0 | sub_539FF0 | Initializes/resets the unk_BE1CE0 buffer |
| 0053a0e0 | sub_53A0E0 | Derives a value from unk_BE1CE0; result stored in dword_BE1BD0 |
| 00615860 | StringCopyWithBufferRealloc [structural] | Copies a CHAR* string into an owned buffer, reallocating as needed; called for the fetched string and its +463 element |
| 00631c76 | _atof | String-to-double conversion used to produce the this+0x114 float |

**Guard conditions:** this+0xA0 == 0 → WindowName is parsed instead (no skip). Parsed value == 0.0 → this+0x114 forced to 5.0f. dword_B6F708 == 0 → WindowName used for sub_539600. *v5 (first string from sub_538790 buffer) == 0 → WindowName used for the first copy. *(dword_B72314) == 4 or == 8 → the third StringCopyWithBufferRealloc is skipped and the function returns immediately; any other value → the third copy runs.
