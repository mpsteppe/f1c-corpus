## PhysicsObjectLinkedListRemoval_0053ce40 — PhysicsObjectLinkedListRemoveNode

**Summary:** Removes a physics object node from the global doubly-linked list (prev/next at offsets 0x12C/0x130, head at dword_8B8F14). Patches neighbor pointers, updates head if removing first node, cleans up fields, frees memory, and decrements global count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49B0A0 (0049b0a0), CockpitDashboardLEDGaugeSetup (0049ca00), sub_49CD80 (0049cd80), PITANIMSMASAnimationFileLoader (004a3220), PitCrewAnimationMASSetup (004a3910), sub_4A4900 (004a4900), SpecialFX_Init (004cf070), sub_4D0110 (004d0110), sub_4D1450 (004d1450), sub_4D8AB0 (004d8ab0), sub_4DCBA0 (004dcba0), PitCrewInstanceSetup (004ddad0), sub_4F8D70 (004f8d70), sub_4FC550 (004fc550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x12C | R | — | Previous node pointer (prev) |
| this | 0x130 | R | — | Next node pointer (next) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b6ac0 | dword_8B6AC0 | RW | PhysicsObjectCount [DERIVED] |
| 008b8f14 | dword_8B8F14 | RW | ObjLinkedListHead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | Empty stub (debug/logging hook) |
| 0055fe30 | DualFieldCleanupWithNullChecks | Cleans up two fields of the node with null checks |
| 00587bcf | FreeWrapper_7bcf | Heap free wrapper |

**Guard conditions:** Checks list head (dword_8B8F14) non-null before traversal. Walks next-pointer chain (offset 0x130) matching against target node; if node not found (next reaches 0), returns 0. Checks prev/next pointers before patching their reciprocal links. Checks if a1[75] (prev at 0x12C) is zero to detect head node and update global head pointer.
