## CollisionGlobalInitG_0044d340 — InitializeCollisionWorldObjTypeAndSentinels

**Summary:** Initializes CollisionWorldObjType to 63, sets CameraInitFloat1 and FloatInit to 0, and writes -1.0f as a sentinel value (Sentinel_MinusOne).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca4d0 | dword_7CA4D0 | W | CollisionWorldObjType [DERIVED] (also: ` — collision object index/type) |
| 007ca4d4 | dword_7CA4D4 | W | CameraInitFloat1 [DERIVED] |
| 007ca4d8 | dword_7CA4D8 | W | Sentinel_MinusOne [DERIVED] (also: ` — initialized to -1.0f (invalid/null index sentinel) |
| 007ca4dc | dword_7CA4DC | W | FloatInit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of four globals.
