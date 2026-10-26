## ??1ios_base@std@@UAE@XZ_00409430 — std::ios_base destructor

**Summary:** MSVC std::ios_base destructor: installs the destruction-time vtable, releases the handle stored at this+0x8 through the release-and-null helper sub_408AC0, destroys and frees the heap block at this+0xC, and finally rewrites the vptr with the base vtable.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Object vptr; set to off_6F1D14 on entry and left as off_6F1D04 at exit |
| this | 0x8 | R | — | Handle pointer (this[2]) released via sub_408AC0 when non-null |
| this | 0xC | R | — | Heap block pointer (this[3]) destroyed via nullsub_7 and freed when non-null |

**Written-by note (persistence):**
- this 0x0: written unconditionally on entry (destruction vtable) and again at exit (base vtable); each object's destructor runs once, so no per-frame recalc — an external poke is overwritten only if the object is destroyed again.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e0e88 | ??1ios_base@std@@UAE@XZ_SEH | R | IDA-generated SEH handler associated with this destructor's exception machinery |
| 006f1d04 | off_6F1D04 | R | Vtable pointer written to this+0x0 at the end of destruction |
| 006f1d14 | off_6F1D14 | R | Destruction-time vtable pointer installed at this+0x0 on entry |
| 0091be2c | dword_91BE2C | R | Global referenced by this routine (its use is not visible in the rendered decompiled body) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408ac0 | sub_408AC0 | Release-and-null helper; deletes the object behind the handle at this+0x8 and clears the handle |
| 004eda30 | nullsub_7 | No-op placeholder invoked on the this+0xC block before freeing (a virtual-destructor slot resolved to a stub) |
| 006308d3 | j__free | CRT free thunk; releases the this+0xC heap block |

**Guard conditions:** Two null gates. (1) `if (*((_DWORD*)this + 2))` — only a non-null handle at this+0x8 triggers sub_408AC0. (2) `if (v2)` — only a non-null block at this+0xC gets nullsub_7 + j__free. Both the entry vtable store and the final base-vtable store are unconditional.
