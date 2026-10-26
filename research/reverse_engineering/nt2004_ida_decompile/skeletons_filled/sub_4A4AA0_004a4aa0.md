## sub_4A4AA0_004a4aa0 — GUI Layout and Render List Processor

**Summary:** Iterates a linked list of GUI render elements, updating their positions/sizes via sub_4A4660 (4-field setter) and calling each element's virtual render method. Handles cursor/navigation state via sub_4A50D0 and optionally draws a progress/scrollbar via sub_49CB80 when the element count exceeds viewport.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x11C)+0x0) | 0xC | R | — | List node: position/size field X |
| *(*(this+0x11C)+0x0) | 0x10 | R | — | List node: position/size field Y |
| *(*(this+0x11C)+0x0) | 0x2C | R | — | List node: bool flag (byte at offset 44) |
| *(*(this+0x124)+0x4) | 0x0 | R | — | Scroll state: element pointer chain |
| *(this+0x118) | 0x14 | R | — | Scroll state: item count |
| *(this+0x118) | 0x18 | R | — | Scroll state: item height |
| *(this+0x11C) | 0x0 | R | — | Linked list head pointer |
| *(this+0x11C) | 0x8 | R | — | Linked list: item capacity |
| *(this+0x124) | 0x4 | R | — | Scroll state struct pointer |
| this | 0x4 | R | — | Output param: base X |
| this | 0x8 | R | — | Output param: base Y |
| this | 0xC | R | — | Output param: width |
| this | 0x10 | R | — | Output param: height |
| this | 0x30 | R | — | Layout state: padding/spacing |
| this | 0x110 | R | — | List: item cursor/selection |
| this | 0x114 | R | — | List: item index |
| this | 0x118 | R | — | List: container struct pointer |
| this | 0x11C | R | — | Sub-list: render element list head |
| this | 0x124 | RW | — | Iterator: current list position |
| this | 0x128 | R | — | Iterator: list item count |
| this | 0x12C | R | — | State: navigation mode (1 = active) |
| this | 0x134 | R | — | State: layout mode (4 = list mode) |
| this | 0x150 | R | — | Layout: item width |
| this | 0x154 | R | — | Layout: item height |
| this | 0x158 | R | — | Layout: item spacing X |
| this | 0x170 | R | — | Layout: content area left |
| this | 0x174 | R | — | Layout: content area top |
| this | 0x178 | R | — | Layout: content area width |
| this | 0x17C | R | — | Layout: content area height |
| this | 0x198 | R | — | Scroll: viewport start |
| this | 0x19C | R | — | Scroll: viewport size |
| this | 0x1A0 | R | — | Scroll: total item count |
| this | 0x1AF | R | — | Flag: scroll enabled |

**Written-by note (persistence):**
- this 0x124: iterator pointer, recalculated each call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | Delta time for animations |
| 00765b00 | unk_765B00 | R | Font/render state reference |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cb80 | sub_49CB80 | Draw scrollbar/progress indicator |
| 004a4660 | F_4FieldSetter [structural] | Set 4 layout fields (position/size) on element |
| 004a4c90 | sub_4A4C90 | Set cursor position on element |
| 004a50d0 | sub_4A50D0 | Get current highlighted/selected element |
| 004ab570 | sub_4AB570 | Get font or text metrics |
| 004ae870 | sub_4AE870 | Get screen/viewport dimensions |
| 005be8bc | __ftol | Float to long conversion |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x12C | == | 1 | Navigation mode active; PASSES — applies cursor selection logic |
| this | 0x134 | == | 4 | Layout mode is "list"; BLOCKS scrollbar rendering if not 4 |

**Guard interpretation:** When navigation mode is 1 (this+0x12C), the currently selected element (from sub_4A50D0) receives cursor position updates via sub_4A4C90. When layout mode is 4 (this+0x134), the function skips scrollbar rendering. Otherwise, a scrollbar is drawn via sub_49CB80 using viewport and content height calculations.
