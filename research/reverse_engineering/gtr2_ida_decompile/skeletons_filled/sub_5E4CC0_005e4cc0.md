## sub_5E4CC0_005e4cc0 — apply delta to stored position (emit z at 0x60)

**Summary:** Adds an incoming x/y/z delta to a stored position carried by `this` and forwards the translated coordinate triple to sub_5D73C0 together with the transform context at this+0x158 (this+86 floats). Same shape as sub_5E4C80 but uses the 0x60/0x5C/0x58 position triple and the other position-writer.

**Called by:** sub_604F60 (00604f60), sub_6072F0 (006072f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | z component of a stored position, added to the incoming z delta (a4 + this[24] at float index 24) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d73c0 | sub_5D73C0 | receives the computed absolute x/y/z plus the this+0x158 context (position-writer counterpart of sub_5D7330) |

**Guard conditions:** No conditional branches — the function unconditionally computes the offset position and calls sub_5D73C0 with the shifted coordinates.
