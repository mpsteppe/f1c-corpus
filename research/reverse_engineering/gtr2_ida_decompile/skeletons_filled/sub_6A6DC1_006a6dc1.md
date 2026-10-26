## sub_6A6DC1_006a6dc1 — AssignSlotsByMode

**Summary:** Worker that binds a list of ps_1_4 instructions into a six-entry slot array (a2) with a parallel register-binding array (a3), using one of three strategies selected by a6: direct binding by the operand's register number (mode 0), first-free-slot binding where the recorded binding must match the operand or be -1 (mode 1), and first-free-slot binding restricted to opcodes 0x11000000/0x72100000 (mode 2). Returns 0 on any conflict (slot taken, register >= 6, binding mismatch, no free slot), 1 when the list is exhausted.

**Called by:** sub_6A6F97 (006a6f97)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | this[4]: table of type records; entry indexed by descriptor field +4, its word at +4 is tested with mask 0x840 |
| this | 0x14 | R | — | this[5]: register descriptor table; descriptors provide +4 (type-record index) and +12 (register number, 0..5) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Mode 0 (a6 == 0): entries whose opcode & 0xFFF00000 is 0x11000000 or 0x72100000, entries failing the (word+4 & 0x840) type-record test, and null entries are skipped (not consumed). Otherwise: descriptor register number >= 6 → BLOCK return 0; slot a2[reg] already occupied → BLOCK return 0; a3[reg] neither -1 nor equal to the operand register index → BLOCK return 0; on success the entry is cleared (list pointer set to 0). Mode 1 (a6 == 1): for each remaining non-special entry, scan slots 0..5 for the first slot that is empty in a2 and whose a3 binding is the operand register index or -1; none found within 6 → BLOCK return 0; else bind and clear the entry. Mode 2 (a6 != 0,1,2 handled last): only entries whose opcode is 0x11000000 or 0x72100000 are considered; the first empty a2 slot is used; all six full → BLOCK return 0. a6 outside {0,1,2} → treat as success (return 1). Empty list (a5 == 0) → return 1.

**String literals referenced (deterministic):** none
