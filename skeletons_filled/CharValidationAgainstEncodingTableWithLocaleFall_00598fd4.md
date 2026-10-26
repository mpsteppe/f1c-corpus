## CharValidationAgainstEncodingTableWithLocaleFall_00598fd4 — PutbackOrValidateCharWithCodecvt

**Summary:** Validates a character for putback or output, handling encoding table check and codecvt conversion. Either returns character to putback buffer, validates backward scan with truncation, or writes raw byte to output. Returns character or -1 on error.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | encoding/mbstate value read via pointer at this+0x1C |
| *(this+0x44) | 0x4 | R | — | stream buffer field at offset 4 (gptr/pptr) |
| *(this+0x44) | 0x8 | R | — | stream buffer field at offset 8 (egptr/epptr) |
| *(this+0xC) | 0x0 | R | — | putback buffer state value read via pointer at this+0xC |
| this | 0xC | R | — | pointer to putback area state |
| this | 0x1C | R | — | pointer to encoding/mbstate tracking structure |
| this | 0x38 | R | — | pointer to codecvt facet (may be NULL) |
| this | 0x3C | R | — | position/state copied to this+0x40 on successful validation |
| this | 0x40 | RW | — | updated position/state after successful backward validation |
| this | 0x44 | R | — | pointer to stream buffer structure |
| this | 0x50 | R | — | pointer to output stream/device |

**Written-by note (persistence):**
- this 0x40: written conditionally when backward validation succeeds; external poke would corrupt stream position tracking

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059685f | FileIOWrapperWithLock | write single byte to output file with lock (no codecvt path) |
| 00599348 | BufferTruncationShrink | shrink/truncate buffer after successful validation |
| 00599465 | RefCountIncDec | increment reference count when putback character is accepted |
| 00599534 | BufferBoundaryMarkerCheckSet | check or set boundary markers on stream buffer |
| 00599707 | CharByCharBackwardScanWithValidation | scan buffer backward character-by-character for encoding validation |

**Guard conditions:** if putback buffer (this+0x1C) exists and has space (this+0xC < it), check if a2 matches putback byte — if match or a2==-1, increment refcount and return. If this+0x50 (output device) NULL or a2==-1, return -1. If this+0x38 (codecvt) exists, attempt backward validation; else write raw byte directly.
