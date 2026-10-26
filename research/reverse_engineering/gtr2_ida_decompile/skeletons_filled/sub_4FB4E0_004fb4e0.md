## sub_4FB4E0_004fb4e0 — cleanup-gated entity route

**Summary:** Variant of the teardown tail without the state-4 block: performs the optional sub_4094C0() cleanup first (skipped when byte_B6F118 is set), then if sub_5BFC80(this[4]) reports inactive it either forwards the entity to sub_4074A0 (state field at v4[25]+15576 non-zero) or tears down v4+0x3C and cleans up.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | this[4]: pointer to the entity being routed/cleaned |
| this | 0x74 | R | — | unknown — not directly visible; the listing reads the entity's v4[25] slot instead |
| this | 0x3D4C | R | — | entity state field read as *(v4[25]+15576); non-zero routes to sub_4074A0, zero to the teardown path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b6f118 | byte_B6F118 | R | gate: when zero the leading sub_4094C0() cleanup runs |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004074a0 | sub_4074A0 | forwarding call for the entity when the state field is non-zero |
| 004094c0 | sub_4094C0 | global cleanup, run conditionally first and again on the state-zero path |
| 0054b280 | sub_54B280 | tears down the sub-object at v4+0x3C when the state field is zero |
| 005bfc80 | sub_5BFC80 | predicate on this[4]; its byte value is also the returned result |

**Guard conditions:** (1) `byte_B6F118 == 0` runs the leading sub_4094C0(); non-zero skips it. (2) The routing block runs only when the returned byte of sub_5BFC80(this[4]) is zero; within it, `*(v4[25]+15576) != 0` passes to sub_4074A0(v4), while zero takes sub_54B280(v4+0x3C) + sub_4094C0(). An active result returns that byte directly.
