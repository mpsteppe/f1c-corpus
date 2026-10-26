## sub_5BC7C0_005bc7c0 — Free pointer returned by virtual getter

**Summary:** Calls the object's virtual method at vtable slot +0xC; if it returns a non-null pointer, runs sub_5C2630 on it and heap-frees it. A destructor/cleanup helper that releases a pointer obtained through a virtual accessor.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | vtable slot +0xC (virtual method used as pointer getter) |
| this | 0x0 | R | — | vtable pointer of this, read to dispatch slot +0xC |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c2630 | sub_5C2630 | cleanup/sub-destructor run on the fetched pointer before freeing |
| 006308d3 | j__free | CRT heap free of the fetched pointer |

**Guard conditions:** `if (vtable+0xC(this))` — non-zero result enters the body; the pointer is fetched again via the same virtual call and `if (v2)` non-null → sub_5C2630 + free. Zero from the first call → nothing happens (skip). Null on the second fetch → no cleanup/free.
