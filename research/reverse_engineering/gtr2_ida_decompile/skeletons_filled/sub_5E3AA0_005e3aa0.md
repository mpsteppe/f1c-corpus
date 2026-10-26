## sub_5E3AA0_005e3aa0 — Material/texture array initializer

**Summary:** Initializes the object's material array (216 bytes per element): generates the special textures (CUBENORMALIZER, SPECPOWER lookup table), then for each element builds the .DDS/extra texture names from the base name at this+12 and loads them through sub_5E30C0; video-type materials use a video-file object instead. On failure it destroys the array/video object, logs a texture error and returns -1.

**Called by:** sub_5E6040 (005e6040), sub_5E9420 (005e9420), sub_5E9C00 (005e9c00), sub_5FF950 (005ff950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xDC) | 0x6C | R | — | refcount/use counter at +108 of the material array head, incremented before the early return |
| this | 0x0 | RW | — | material flag word: bits 0xC cleared, flags 0x400/0x800 tested, 0x40000 set on the video path |
| this | 0x4 | R | — | element count (this[1]) driving the material loop |
| this | 0x8 | R | — | this[2] passed to the material load call (sub_5E30C0) |
| this | 0xC | R | — | base name string (this+12) used to build .DDS/video texture names |
| this | 0x54 | R | — | this[21]: material kind; value 7 selects the video-file path |
| this | 0x60 | R | — | this[24]: material type switch (15, 14, 9, 99, default) |
| this | 0x78 | R | — | this[30] passed to the material load call (sub_5E30C0) |
| this | 0x88 | RW | 0 | this[34]: result flag set to 1, (flags & 0x20) >> 4, or 0 |
| this | 0xDC | RW | 0 | this[55]: pointer to the 216-byte-per-element material array (zeroed on the failure path) |
| this | 0xE0 | RW | — | this[56]: video-file object (allocated in the type-7 path, freed on failure) |

**Written-by note (persistence):**
- this 0x0: modified on every call (flag bits cleared/set conditionally); partial pokes survive only where no write occurs that call.
- this 0x88: written on every call (either 1/(x>>4) or 0) — recalculated each time.
- this 0xDC: assigned on the material-array path and zeroed on the failure cleanup; survives until the next call changes it.
- this 0xE0: assigned only inside the type-7 video branch (not touched otherwise); freed on failure without an explicit visible clearing.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e2ac0 | sub_5E2AC0 | R | element constructor callback passed to the array constructor (sub_630A11) |
| 005e2b00 | j_j_nullsub_7 | R | empty destructor callback used with the array/video cleanup |
| 005e43b4 | jpt_5E4022 | R | jump table for the material-type switch |
| 005e43c4 | byte_5E43C4 | R | unknown byte in the switch region (not identifiable from the visible code) |
| 006ec6a8 | SEH_5E3AA0 | R | SEH scope record for the function |
| 006f1f34 | aSS | R | `%s%s` format used for the single-element DDS/extra names |
| 006f2a98 | aS_2 | R | second copy of `%s%s` (extra-name variant) |
| 006f5fec | flt_6F5FEC | R | float constant used in the case-9 SPECPOWER table generation (one of 1/1024, 256.0; not separable) |
| 006f6048 | dbl_6F6048 | R | double constant used in the same SPECPOWER generation (one of 1/1024, 256.0; not separable) |
| 00712ee0 | aDds | R | `.DDS` extension string |
| 0072bc08 | aErrorInitializ | R | error format `Error initializing texture surface for %s` |
| 0072bd18 | aErrorLoadingTe_0 | R | error format `Error loading texture %s for material %s` |
| 0072bd34 | aErrorLoadingTe | R | error format `Error loading texture %s` |
| 0072bd60 | aErrorInitializ_1 | R | error format `Error initializing video file texture %s` |
| 0072bd8c | aS4sSC | R | format `%s%4s%s%c` used to rename the extra texture entry |
| 0072bd98 | aS2dS | R | format `%s%.2d%s` used for numbered multi-element names |
| 0072bda4 | word_72BDA4 | R | unknown data in the string-literal region (not identifiable from the visible code) |
| 0072bda6 | byte_72BDA6 | R | unknown data in the string-literal region (not identifiable from the visible code) |
| 0072bda8 | aErrorInitializ_0 | R | error format `Error initializing video file %s` |
| 0072bdcc | aSpecpower1f | R | `SPECPOWER%.1f` generated texture name |
| 0072bddc | aCubenormalizer | R | `CUBENORMALIZER` generated texture name |
| 00fb2754 | byte_FB2754 | R | gate for the per-material flag handling (with `flags & 0xC`) |
| 00fb27a4 | dword_FB27A4 | R | renderer object whose vtable +516 method is called when the surface creation fails |
| 00fb27f8 | dword_FB27F8 | R | unknown (not visible in the provided C text) |
| 00fb2d78 | dword_FB2D78 | R | unknown (not visible in the provided C text) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | error reporter (object, -1, format, string) for the texture/video failures |
| 005d8ce0 | sub_5D8CE0 | abort/cleanup hook called before returning -1 when a5 is set |
| 005e2e70 | sub_5E2E70 | video-file texture setup for the type-7 element (name, w, h, 0,4,4,0) |
| 005e30c0 | sub_5E30C0 | loads the .DDS/extra texture into a material entry; 0 = success, nonzero = failure |
| 005e6dd0 | sub_5E6DD0 | destroys/clears a material entry (name byte forced to 0 on failure cleanup) |
| 005e6e70 | sub_5E6E70 | allocates the 1024-entry SPECPOWER lookup table (4,0,2) |
| 005e6ea0 | sub_5E6EA0 | commits/uploads the SPECPOWER table (4,0,2) |
| 005e72d0 | sub_5E72D0 | creates the texture surface (256x256x8,1,20 / 1024x1x8,1,4); nonzero triggers the error path |
| 005e7fb0 | sub_5E7FB0 | builds the secondary name string (String) from this+12 |
| 005e9100 | sub_5E9100 | looks up an existing texture by name (early exit when already registered) |
| 005e9670 | sub_5E9670 | per-instance setup called when the element count is > 1 (non-video path) |
| 005f2f60 | j_nullsub_7 | empty callback invoked on the video object during cleanup |
| 005f4570 | sub_5F4570 | getter for a video-object field (passed to sub_5E2E70) |
| 005f4580 | DoubleFieldGetter [structural] | getter for the other video-object field (passed to sub_5E2E70) |
| 005f4610 | sub_5F4610 | constructs the video-file object (operator new 0x114 + ctor) |
| 005f4640 | sub_5F4640 | initializes the video file from this+12; nonzero = failure (flags 0x40000 set otherwise) |
| 005fdfb0 | sub_5FDFB0 | finalizes/registers the material array (array, 0) |
| 00630739 | ??2@YAPAXI@Z | allocates the array/video objects |
| 006308d3 | j__free | frees the video object on the failure path |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | `eh vector destructor iterator` for the material array elements (216 = 0xD8 each) |
| 0063099c | __ftol2 | float-to-int conversion used in the SPECPOWER table generation |
| 00630a11 | sub_630A11 | constructs the material array (element size 216, ctor sub_5E2AC0, dtor j_j_nullsub_7) |
| 00631761 | _sprintf | builds the per-element .DDS/extra names and the SPECPOWER/CUBENORMALIZER names |
| 00633410 | BitfieldManager [structural] | unknown here (not visible in the provided C text) |
| 00633686 | __strupr | uppercases the generated texture name (via _strupr on the entry name) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | <= | 1 | element count <= 1: single-name path (`%s%s`), no index numbering |
| this | 0x4 | > | 1 | element count > 1: numbered names (`%s%.2d%s`) and sub_5E9670 is called first |
| this | 0x54 | == | 7 | material kind 7: video-file path (sub_5F4610/sub_5F4640, `Error initializing video file`) |

**Guard interpretation:** The type switch returns 0 immediately for types 15 and 99 (no work). Types 14 and 9 take the bespoke texture-generation paths (with the `sub_5E9100` early exit when the texture already exists); any other type falls through to the general load path. `this[21] == 7` selects the video-file branch: on `sub_5F4640` failure the video object is freed/cleared, `Error initializing video file %s` is logged and -1 returned; otherwise flag 0x40000 is set. A count `> 1` triggers sub_5E9670 and switches the name build from `%s%s` to the `%s%.2d%s` numbered form. Per element, the decorated path requires `byte_FB2754` and `(flags & 0xC)`; the extra-name rename requires `flags & 0x100` plus a non-null a3. If both sub_5E30C0 attempts fail, the array and video object are destroyed, the error message is selected by `a2 == 0.0` (plain vs "for material"), sub_5D8CE0 runs when `a5` is set, and the function returns -1. When the surface creation in types 14/9 fails, the entry is freed and `Error initializing texture surface for %s` is logged.

**String literals referenced (deterministic):**

- `%s%s`
- `%s%s`
- `.DDS`
- `Error loading texture %s`
- `Error loading texture %s for material %s`
- `Error initializing video file texture %s`
- `%s%4s%s%c`
- `%s%.2d%s`
- `%s%.2d%s`
- `Error initializing video file %s`
- `SPECPOWER%.1f`
- `SPECPOWER%.1f`
- `CUBENORMALIZER`
- `CUBENORMALIZER`
