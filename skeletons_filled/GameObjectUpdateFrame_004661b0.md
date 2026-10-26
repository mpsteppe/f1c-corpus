## GameObjectUpdateFrame_004661b0 — GameObjectUpdateFrame

**Summary:** Per-frame update for game object. Optionally appends to doubly linked list, decrements a timer (field 0x124), calls position/physics subroutines (sub_466350, sub_466650) when flags set, and invokes virtual methods at vtable+44 and vtable+168.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | data accessed via FloatFieldAccessor (sub-object field) |
| obj | 0xA8 | R | — | node pointer for DoublyLinkedListAppend |
| obj | 0xAC | R | — | linked list context for DoublyLinkedListAppend |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x40 | R | — | pointer passed to DoublyLinkedListAppend and FieldSetterCall |
| this | 0xE8 | R | — | flag: non-zero triggers DoublyLinkedListAppend |
| this | 0xF4 | R | — | flag byte 1: OR'd with 0xF5 to gate sub_466350 call |
| this | 0xF5 | R | — | flag byte 2: OR'd with 0xF4 to gate sub_466350 call |
| this | 0x124 | RW | — | float timer/countdown, decremented each frame |

**Written-by note (persistence):**
- this 0x124: every frame (decremented). External poke overwrites.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466350 | sub_466350 | position/velocity update (conditional on flags 0xF4/0xF5) |
| 00466650 | sub_466650 | secondary physics update |
| 00496750 | DoublyLinkedListAppend_6750 | append this object to a linked tracking list |
| 00498730 | FloatFieldAccessor | read float field from sub-object |
| 004988a0 | FieldSetterCall | set state field on sub-object |

**Guard conditions:** If byte at this+0xE8 is non-zero → append to doubly linked list (PASS). If float at this+0x124 >= 0.0 → decrement with delta; if it goes below 0, call FieldSetterCall(1) + virtual method at vtable+172 (PASS). If flag at this+0xF4 or this+0xF5 is non-zero → call sub_466350 (PASS). Always calls sub_466650 and virtual methods at vtable+44 and vtable+168 (unconditional).
