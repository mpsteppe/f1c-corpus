## ShortStringSet_004c69b0 — Set short string value with hash

**Summary:** Copies a short string (max 7 chars) to this+4546 (offset 0x4708), null-terminates it, then hashes/processes it via sub_587ECE and stores the resulting hash at this[4548] (offset 0x4710).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NationalityDriverInfoLoader (004c78f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x470F | RW | 0 | null terminator byte for short string buffer (7-char limit) |
| this | 0x4710 | RW | — | hash/code derived from the short string value |

**Written-by note (persistence):**
- this 0x470F: written as null terminator after string copy; persists
- this 0x4710: written with hash result; persists

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | bounded string copy (strncpy-like) |
| 00587ece | sub_587ECE | compute hash/integer code from string |

**Guard conditions:** none — always copies string and computes hash
