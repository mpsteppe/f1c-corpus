## sub_4DCE40_004dce40 — UI page/gizmo definition parser

**Summary:** Parses a UI page/gizmo definition stream: for each line it reads and dispatches keywords (NAME, LOCATION, POS-W-H, LOCATION2, SURFACE, PAGE_POINTER, GIZMO, ENTERTARGET/ESCTARGET), builds a new 100-byte page node attached to this+0x310, and returns through the off_16C9950 helper when a "}" end marker is seen or the input ends.

**Called by:** sub_4DD1F0 (004dd1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | RW | — | Page/node counter: incremented by 1 on every call |
| this | 0x2FE | R | — | Byte flag enabling the name registration via sub_4DBCD0 |
| this | 0x300 | R | — | Count of registered names; sub_4DBCD0 runs only while it is < 4 |
| this | 0x308 | R | — | Parent/owner object pointer (stored in the new node at +48 and passed to the SURFACE/GIZMO helpers) |
| this | 0x30C | R | — | Parameter passed as the third argument to sub_4E0E80 |
| this | 0x310 | RW | — | Pointer to the newly created page node (v3) |

**Written-by note (persistence):**

- this 0x2F8: recomputed on every call (+1); an external poke is overwritten by the next parse call.
- this 0x310: rewritten to the new node pointer on every call (0 when the node allocation fails); an external poke does not survive the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e532e | SEH_4DCE40 | R | Exception-handling scope record for this function |
| 00712824 | asc_712824 | R | unknown (string constant near the keyword table; content not identifiable from the decompilation) |
| 007128c4 | aSurface | R | Keyword "SURFACE" |
| 007128cc | aPosWH | R | Keyword "POS-W-H" |
| 007128d4 | aLocation | R | Keyword "LOCATION" |
| 00712c78 | aName | R | Keyword "NAME" |
| 00712cdc | aGizmo | R | Keyword "GIZMO" |
| 00712ce4 | aPagePointer | R | Keyword "PAGE_POINTER" |
| 00712cf4 | aLocation2 | R | Keyword "LOCATION2" |
| 00712d00 | aEsctarget | R | Keyword "ESCTARGET" |
| 00712d0c | aEntertarget | R | Keyword "ENTERTARGET" |
| 0075ad58 | unk_75AD58 | R | unknown (not visible in the provided decompilation) |
| 0075af70 | byte_75AF70 | R | Current input line/token buffer; searched for the "}" end marker |
| 016c9950 | off_16C9950 | R | Function pointer used to finish/return from the parse (also on the "}" end marker) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dac90 | sub_4DAC90 | Advances to the next input token/line; returns nonzero while more remain |
| 004dbcd0 | sub_4DBCD0 | Adds the NAME value to the object's registered-name list, gated by +0x2FE and the +0x300 count |
| 004dc3c0 | sub_4DC3C0 | Resolves the named GIZMO object |
| 004df040 | sub_4DF040 | Prepares a surface/rectangle object from the parsed values; result attached to the new node |
| 004df500 | sub_4DF500 | Initializes the newly allocated node v3 |
| 004df750 | sub_4DF750 | Attaches the prepared object to the new page node |
| 004e0080 | sub_4E0080 | Applies SURFACE properties to the parent object |
| 004e0a60 | sub_4E0A60 | Constructs the new page node inside the 100-byte allocation |
| 004e0e80 | sub_4E0E80 | Attaches the resolved gizmo to the parent object with the parameter from +0x30C |
| 004e2a80 | ShortComputation_a9c0 [exact] | Applies the four LOCATION floats to the node rectangle |
| 004e2aa0 | RectangleEdgeOffsetCalculator [exact] | Computes rectangle edge offsets from the four LOCATION2 floats |
| 004e2b70 | sub_4E2B70 | Assigns the NAME value to the new page node |
| 006131c0 | sub_6131C0 | Reads a keyword value into the destination, returning success |
| 006134b0 | sub_6134B0 | Reads a four-float keyword value (LOCATION / POS-W-H / LOCATION2) |
| 00615860 | StringCopyWithBufferRealloc [structural] | Copies the ENTERTARGET/ESCTARGET/PAGE_POINTER string value |
| 00630739 | ??2@YAPAXI@Z | operator new — allocates the 100-byte page node |
| 0063099c | __ftol2 | Float-to-integer conversion helper used by the rectangle computations |
| 00630a80 | _strstr | Searches the current line for the "}" end marker |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | Registered-name count limit: sub_4DBCD0 runs only while fewer than 4 names are registered |

**Guard interpretation:** The parse loop runs while sub_4DAC90 reports more input; a line containing "}" ends parsing immediately (return via off_16C9950). NAME handling registers the name via sub_4DBCD0 only when the byte at +0x2FE is nonzero AND the count at +0x300 is < 4 — with 4 or more names already registered the registration is blocked (the name is still applied to the node via sub_4E2B70). The keyword checks form an else-if chain: once LOCATION / POS-W-H / LOCATION2 matches, the SURFACE/PAGE_POINTER/GIZMO checks are skipped, and vice versa.

**String literals referenced (deterministic):**

- `SURFACE`
- `POS-W-H`
- `LOCATION`
- `NAME`
- `GIZMO`
- `PAGE_POINTER`
- `LOCATION2`
- `ESCTARGET`
- `ENTERTARGET`
