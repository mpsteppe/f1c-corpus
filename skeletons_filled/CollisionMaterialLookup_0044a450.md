## CollisionMaterialLookup_0044a450 — Collision material property lookup

**Summary:** Looks up material properties (friction, restitution) from global tables indexed by material ID. For basic materials (0-7), reads property from MaterialPropertyTable and restitution from CollisionRestitutionTable. For extended materials (8+), reads from ExtendedMaterialTable and negated CollisionResponseTable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44A4B0 (0044a4b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca36c | flt_7CA36C | R | CollisionResponseTable [DERIVED] (also: ` — extended response table) — lookup for extended material response values |
| 007ca388 | dword_7CA388 | R | MaterialPropertyTable [DERIVED] (also: ` — material property table (8 entries) — lookup for basic material properties |
| 007ca3a4 | unk_7CA3A4 | R | CollisionRestitutionTable [DERIVED] (also: ` — restitution/response table) — lookup for basic material restitution |
| 007ca3c0 | flt_7CA3C0 | R | ExtendedMaterialTable [DERIVED] — lookup for extended material properties (negative index) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a1 (material index) > 7 → extended material path (negative indexing). a1 <= 7 → basic material path (direct indexing).
