## sub_6A5ECA_006a5eca — ValidateAndBuildProgramTables

**Summary:** Scans the this[6] object list for texture-read state (owner this[32], TEXCOORD/TEXLOOKUP bytes +108/+109, duplicate-use flags): fast path allocates only the this[140] table and builds programs via sub_6A572C, otherwise it allocates two 2048-byte tables plus a queue, validates dependent reads with sub_6A554C and builds both tables, then reassigns owner this[29] to entries whose +64 was set to 1. Reports ps_1 restriction violations through sub_686791.

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | this[2]: count of entries in this[5] whose +64 flags are cleared first and re-checked at the end |
| this | 0xC | R | — | this[3]: number of objects in this[6]; 0 skips the first scan (and the slow-path scan) |
| this | 0x14 | R | — | this[5]: entry pointer array (owner +4, link +56, state +108/+109, category +16) |
| this | 0x18 | R | — | this[6]: object array scanned for type codes and cleared +9 flags |
| this | 0x4C | R | — | this[19]: last argument of the second sub_6A572C call (final index passed to the builder) |
| this | 0x74 | R | — | this[29]: owner value written into entries whose +64 == 1 after a successful build |
| this | 0x80 | R | — | this[32]: owner/type expected on inputs; drives TEXCOORD checks and errors |
| this | 0x88 | R | — | this[34]: owner compared in the slow-path dispatch of the element at v34 |
| this | 0xC8 | R | — | this[50]: low 16 bits checked against 260 to enable duplicate-use rejections |
| this | 0x220 | RW | 0 | this[136]: count output of the this[139]-table build (zeroed in the slow path) |
| this | 0x224 | RW | 0 | this[137]: count output of the this[140]-table build (zeroed in the slow path) |
| this | 0x22C | RW | 0 | this[139]: first program-table pointer (cleared in the fast path, freshly allocated in the slow path) |
| this | 0x230 | RW | — | this[140]: second program-table pointer (freshly allocated and zeroed every call) |

**Written-by note (persistence):**
- this 0x220: zeroed at the start of the slow path, then recomputed by sub_6A572C; an external poke is overwritten on the next invocation that takes the slow path.
- this 0x224: zeroed in the slow path and used as count output in both paths; overwritten on every invocation.
- this 0x22C: written every call (0 in the fast path, newly allocated zeroed 2048-byte buffer in the slow path); external pokes do not survive.
- this 0x230: always replaced with a freshly allocated, zeroed 2048-byte buffer; external pokes do not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007438e8 | aCannotPerformD | R | message "cannot perform dependent texture read which in any way is based on color inputs" (code 4513) |
| 00743ae0 | aProgramTooBig | R | message "program too big" (code 4514) when the slow-path scan index reaches 0x200 |
| 00743c18 | aCanReadFromTex | R | message "can read from texcoord and use it for texlookup only in ps_1_4 and higher" (code 4520) |
| 00743c68 | aTextureLoadsOr | R | message "texture loads or clips cannot be from inputs not marked TEXCOORD" (code 4513) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | operator new: allocates the 2048-byte program-table/queue buffers |
| 006308d3 | j__free | frees the Block queue and v55 buffer on the exit path |
| 00686791 | sub_686791 | reports the ps_1 restriction violations (codes 4513/4514/4520) |
| 006a554c | sub_6A554C | dependent-texture validation over the second-half element list (slow path) |
| 006a572c | sub_6A572C | builds program tables into this[139]/this[140] with their counts |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | this[3] == 0: first scan skipped (straight to LABEL_30) and slow path jumps to LABEL_71 |
| this | 0xC8 | != | 260 | shader model: != 260 turns duplicate TEXCOORD/TEXLOOKUP use into failures (v52 = 0) and enables the 4520 error |

**Guard interpretation:** PASS (fast path builds a single table) only when the scan leaves v52 != 0: no element with owner this[32] and +108 != 3, no +4 != this[32] or +60 != 0 on the dispatched element, and no duplicate +109 use while this[50] != 260, with at most 0x10 counted uses. BLOCK/errors: element with owner this[32], +60 == 0 and +108 != 3 → "texture loads or clips cannot be from inputs not marked TEXCOORD" (4513); slow-path scan index >= 0x200 → "program too big" (4514); owner == this[32] with +108 != 3 → "cannot perform dependent texture read..." (4513); re-use of a TEXCOORD input (v44 slot set) with this[50] != 260 → "can read from texcoord..." (4520); all return -2147467259. Allocation failures return -2147024882, and negative sub_6A572C/sub_6A554C results are propagated.

**String literals referenced (deterministic):**

- `cannot perform dependent texture read which in any way is based on color inputs`
- `program too big`
- `can read from texcoord and use it for texlookup only in ps_1_4 and higher`
- `texture loads or clips cannot be from inputs not marked TEXCOORD`
