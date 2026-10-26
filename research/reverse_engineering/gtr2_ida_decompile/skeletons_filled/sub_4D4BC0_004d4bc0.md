## sub_4D4BC0_004d4bc0 — Screen-space quad draw for object (scaled UVs + renderer id cache)

**Summary:** Reads the object's four stored coordinates, outputs them through the caller's pointers, and — when the global renderer context and the cached renderer id are both valid — draws a stretched quad using coordinates scaled by 1/600 and 1/800, wrapped in begin/end state calls and render-state setup.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | first stored coordinate (v6); written to *a2 and used as scaled draw coordinate |
| this | 0x8 | R | — | second stored coordinate (v7); written to *a3 and used in the scaled span calculation |
| this | 0xC | R | — | third stored coordinate (v9); written to *a4 and used as scaled draw coordinate |
| this | 0x10 | R | — | fourth stored coordinate (v8); written to *a5 and used in the scaled span calculation |
| this | 0x10C | RW | — | cached renderer/texture id (dword index 67); lazily filled from dword_B6E198 and gates the draw block |

**Written-by note (persistence):**
- this 0x10C: written only when currently zero (lazy one-time cache fetched from the global renderer object/array); once non-zero it is not refreshed here, so an external poke survives — but a non-zero poke also changes the draw gate.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f4dc8 | flt_6F4DC8 | R | float normalization constant used by this path (the 0.0016666667 ≈ 1/600 factor) |
| 006f9500 | flt_6F9500 | R | float normalization constant used by this path (the 0.00125 = 1/800 factor) |
| 00b6e198 | dword_B6E198 | R | global renderer/context object; +400 count and +388 pointer/array source for the cached id |
| 00b6e2a0 | unk_B6E2A0 | R | object passed to sub_4DDFE0 to resolve the value later handed to sub_5E55E0 |
| 00fb1ce0 | dword_FB1CE0 | R | unknown (no directly visible use in the decompiled body) |
| 00fb1e98 | unk_FB1E98 | R | state block object passed to the begin/end pair sub_58F290 / sub_58F2C0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ddfe0 | sub_4DDFE0 | lookup on unk_B6E2A0 whose returned value is fed to sub_5E55E0 |
| 0058f290 | sub_58F290 | begins a draw/state block over unk_FB1E98 |
| 0058f2c0 | sub_58F2C0 | ends the draw/state block over unk_FB1E98 |
| 005dcfa0 | sub_5DCFA0 | draw-list call with argument 0 (batch/setup step inside the block) |
| 005e5050 | sub_5E5050 | render-state/config call with argument 286 |
| 005e53e0 | sub_5E53E0 | stretched-quad draw using the scaled coordinates and flag 0x4000; also called again with (0,0,1,1) to reset the rect |
| 005e55e0 | sub_5E55E0 | consumes the value returned by sub_4DDFE0 (apply handle to the pipeline) |

**Guard conditions:** The draw path requires dword_B6E198 != 0 (global renderer context). If this+0x10C is zero it is lazily filled from the global: count at global+400 > 0 and pointer at global+388 != 0 → takes the first int, else 0. The draw calls run only when both dword_B6E198 and this+0x10C are non-zero; the four outputs (*a2, *a3, *a4, *a5) are written unconditionally.
