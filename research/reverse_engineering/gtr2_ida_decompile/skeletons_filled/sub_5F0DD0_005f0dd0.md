## sub_5F0DD0_005f0dd0 — Font string draw (immediate and buffered paths)

**Summary:** Draws the string a4 at position (a5,a6) on the font object: the immediate path just emits glyphs through sub_5EFFC0, while the buffered path (this+0x10 bit0) releases the old vertex buffer at this+0xA4, requests a new one from the renderer singleton (vtable+368, size derived from 6*strlen), locks it (buffer+0x4C into this+0xA8), emits the glyphs, then unlocks and issues the vtable+420 draw with a temporary render-state block built from a9. Errors return -2 (empty string) or -1 (state/buffer failure), otherwise 0.

**Called by:** sub_4E1950 (004e1950), StringFormatAndRender [structural] (004e6210), sub_4E6AA0 (004e6aa0), sub_4E6E80 (004e6e80), sub_562B70 (00562b70), sub_562C80 (00562c80), sub_5F10F0 (005f10f0), sub_5F1150 (005f1150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA4) | 0xC | RW | — | Refcount of the vertex buffer object; incremented on acquire, decremented (and released at zero) before re-creation |
| *(this+0xA4) | 0x4C | R | — | Locked vertex-data pointer of the buffer object; copied into this+0xA8 for glyph emission |
| this | 0x10 | R | — | Mode flags; bit0 selects the buffered vertex-buffer path vs the immediate glyph path |
| this | 0x88 | R | — | Draw parameter forwarded to the vtable+420 draw call |
| this | 0x8C | R | — | Draw parameter forwarded to the vtable+420 draw call |
| this | 0x94 | R | — | Draw parameter forwarded to the vtable+420 draw call |
| this | 0xA0 | RW | 0 | Vertex count; reset to 0 before emission, accumulated by the glyph emitter, passed as the primitive count |
| this | 0xA4 | RW | 0 | Pointer to the current vertex buffer object; released/re-created each buffered draw |
| this | 0xA8 | RW | 0 | Current vertex write pointer; loaded from buffer+0x4C, cleared after the draw |
| this | 0xB0 | R | — | Offset/scale parameter forwarded to the vtable+420 draw call |
| this | 0xB4 | R | — | Offset/scale parameter forwarded to the vtable+420 draw call |

**Written-by note (persistence):**
- *(this+0xA4) 0xC: incremented when a buffer is acquired and decremented (with release at zero) before each re-creation; recalculated on every buffered draw — an external poke survives only until the next such draw.
- this 0xA0: reset to 0 then incremented per glyph on every buffered draw; a poke survives until the next buffered draw.
- this 0xA4: set to 0 after releasing the old buffer and overwritten by the new buffer creation; recalculated every buffered draw.
- this 0xA8: set from buffer+0x4C during the draw and cleared to 0 afterwards; recalculated every buffered draw.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006eca5b | SEH_5F0DD0 | R | SEH scope/handler record protecting the renderer-interface calls in this function |
| 00fb27a4 | dword_FB27A4 | R | Renderer/device singleton; vtable slots +156, +368, +408, +416, +420, +460 are used for target query, buffer creation, release, unlock and draw |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051d670 | sub_51D670 | Called with the temporary draw descriptor, the target a9 and v26 while preparing the buffered draw |
| 005e5050 | sub_5E5050 | Sets a state value (318) on the temporary draw descriptor |
| 005e53e0 | sub_5E53E0 | Sets the descriptor rectangle (0,0,width,height,0) from the a9 target dimensions |
| 005e54e0 | sub_5E54E0 | Sets descriptor float parameters (0.1, 1.0) |
| 005e55e0 | sub_5E55E0 | Binds/associates the a9 target with the draw descriptor |
| 005e57e0 | sub_5E57E0 | Initializes the temporary draw descriptor (v30) |
| 005e7120 | sub_5E7120 | State query on a7 with argument 2 — nonzero result allows the draw to proceed |
| 005e7150 | sub_5E7150 | State query on a7 with argument 8 — nonzero result allows the draw to proceed |
| 005effc0 | sub_5EFFC0 | Glyph emitter — called per character with the running X position; returns the glyph advance |

**Guard conditions:** `!*a4`: an empty string returns -2 immediately (BLOCKED). `!sub_5E7120(a7, 2) && !sub_5E7150(a7, 8)`: the draw is blocked with return -1 unless at least one of the two state checks on a7 is true. In the buffered path, the vtable+368 buffer-creation call returning nonzero triggers a vtable+416 release and return -1 (BLOCKED); `if (*v13)`: the glyph emission and draw only run when a buffer pointer exists. `if (strlen(a4))`: glyph loops run only for a non-empty string (already guaranteed). `a9 != (vtable+156)()`: the temporary descriptor setup and the extra descriptor-related calls run only when a9 differs from the current target returned by vtable+156; otherwise that block is skipped. Success returns 0.
