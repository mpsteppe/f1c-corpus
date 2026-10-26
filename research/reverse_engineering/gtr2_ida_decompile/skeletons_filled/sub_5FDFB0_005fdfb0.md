## sub_5FDFB0_005fdfb0 — List element insert via global allocator hook

**Summary:** If a2 is nonzero, allocates a 12-byte node holding a2 and delegates to the global routine pointed to by off_16C9594 (which performs the actual insertion/registration and returns a char result); if the allocation fails, the object's list linkage is reset (tail link cleared, tail zeroed, counter at +0xC incremented) and 1 is returned.

**Called by:** sub_40B8E0 (0040b8e0), sub_40B980 (0040b980), sub_40BBA0 (0040bba0), sub_41DF60 (0041df60), sub_41E030 (0041e030), sub_47BEE0 (0047bee0), sub_481CB0 (00481cb0), sub_4839A0 (004839a0), sub_485F30 (00485f30), sub_488A20 (00488a20), sub_48A940 (0048a940), sub_4B6470 (004b6470) … +77 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | head pointer of the managed list; checked before clearing (written 0 only when already null) |
| this | 0x4 | RW | 0 | tail pointer; when head exists its next-link field (tail+4) is cleared, then tail is zeroed |
| this | 0x8 | RW | 0 | aux list field, zeroed only when the list was already empty (head null) |
| this | 0xC | R | — | element/failure counter, incremented on the allocation-failure cleanup path |

**Written-by note (persistence):**
- this 0x0: written only during the allocation-failure cleanup, and only when it is already 0; an external poke survives normal (successful-insert) calls.
- this 0x4: zeroed only on the allocation-failure path; survives otherwise.
- this 0x8: zeroed only in the empty-head failure branch; survives otherwise.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9594 | off_16C9594 | R | function pointer to the routine invoked after a successful node allocation — performs the real insert/registration with (a3-derived selector, a2, a3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | operator new(0xC) — allocates the 12-byte list node whose first dword receives a2 |

**Guard conditions:** If `a2 == 0` nothing happens and 0 is returned. For nonzero a2 the allocation must succeed to reach the registration call through off_16C9594 (that call's return value is passed back). If the allocation FAILS, the cleanup path runs: when the head (0x0) is nonzero the tail node's next pointer (tail+4) is cleared, otherwise head is written 0 and 0x8 is written 0; then the tail (0x4) is zeroed, the counter at 0xC is incremented, and 1 is returned — i.e. failure does not register anything and reports 1.
