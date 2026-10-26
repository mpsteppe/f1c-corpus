// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D720
// Canonical corpus name: sub_55D720
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55D720_0055d720.c

void UnknownObject::RenderStateBufferAllocAndCopy()
{
    // Allocates and fills a DirectX-style vertex buffer for a render state. Two paths selected by SimpleGetter_14f0(dword_8B78A0): complex (getter == 0) clears flags, optionally allocates a 160-byte-bucket buffer via BufferLockAllocate, copies vertex data from this[3] into this[8] (3 or 6 dwords per element, dest stride 16 dwords, src stride 12 dwords, gated by flag 0x800), then dispatches to sub_55E320/sub_55DA50/sub_55D900 by mode flags at this[0]. Simple path (getter != 0) sets flag 0x100, allocates, copies 3 dwords once (flag 0x200), and optionally calls sub_55EBA0 when the byte at this+0xA0 is negative. Both paths end by unlocking the buffer via ArithmeticComparison_0f90 when allocation happened.
    // CALL: Query render-state category via SimpleGetter_14f0(dword_8B78A0); result == 0 selects the complex path, non-zero selects the simple path. [callee:0x005414F0, global:0x008B78A0, source:raw]
    // GUARD: Complex path: enter only when flags at this+0x38 have bit 0x100 clear or bit 0x400 set. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Complex path: rewrite flags at this+0x38 to (flags & 0xFFFFFAFF) | 0x100, clearing bits 0x400/0x200 and setting 0x100. [field:this:0x00000038, source:raw]
    // GUARD: Proceed only while the lock field at this+0x154 (sub-object at this+0x18 plus 316) is zero. [field:this:0x00000154, field:this:0x00000018, source:raw]
    // CALL: If a3 is nonzero, allocate the buffer: this[8] = BufferLockAllocate(dword_8B78A0, this[7], 160, this[11], this[2]). [callee:0x00540F00, field:this:0x00000020, field:this:0x0000001C, field:this:0x0000002C, field:this:0x00000008, global:0x008B78A0, source:raw]
    // LOOP: Copy this[2] elements from source this[3] into destination this[8]: when flag 0x800 at this+0x38 is set copy 6 dwords (0,1,2,8,9) per element, otherwise 3 dwords (0,1,2); destination advances 16 dwords and source 12 dwords per element. [field:this:0x00000038, field:this:0x00000020, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // CALL: Dispatch to a mode-specific routine based on mode flags at this+0x0: bit 0x2 -> sub_55E320(a2), else bit 0x1 -> sub_55DA50(a2), else sub_55D900(a2). [field:this:0x00000000, callee:0x0055E320, callee:0x0055DA50, callee:0x0055D900, source:raw]
    // CALL: If the state word at this+0x2C (sub-object at this+0x18 plus 20) has bit 0x400000 set, refresh via sub_55EB30(this). [field:this:0x0000002C, callee:0x0055EB30, source:raw]
    // ASSIGNMENT: Simple path: when bit 0x100 of flags at this+0x38 is clear, set it (flags | 0x100). [field:this:0x00000038, source:raw]
    // GUARD: Simple path: enter the allocate/copy block only when bit 0x200 of flags at this+0x38 is clear or the signed byte at this+0xA0 (external state pointer this+0x4 plus 156) is negative. [field:this:0x00000038, field:this:0x000000A0, field:this:0x00000004, guard:0, source:raw]
    // CALL: If a3 is nonzero, allocate the buffer: this[8] = BufferLockAllocate(dword_8B78A0, this[7], 160, this[11], this[2]). [callee:0x00540F00, field:this:0x00000020, field:this:0x0000001C, field:this:0x0000002C, field:this:0x00000008, global:0x008B78A0, source:raw]
    // LOOP: If bit 0x200 of flags at this+0x38 is clear: copy this[2] elements from this[3] into this[8] (3 dwords per element, dest stride 16 dwords, src stride 12 dwords), then set bit 0x200 in the flags. [field:this:0x00000038, field:this:0x00000020, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // CALL: If the signed byte at this+0xA0 (external state pointer this+0x4 plus 156) is negative, call sub_55EBA0(a2). [field:this:0x000000A0, field:this:0x00000004, callee:0x0055EBA0, guard:0, source:raw]
    // CALL: Common tail: if a3 was nonzero, unlock/release the buffer via ArithmeticComparison_0f90(dword_8B78A0, this[7]). [callee:0x00540F90, field:this:0x0000001C, global:0x008B78A0, source:raw]
    // RETURN: Void return at merged tail (LABEL_31). [function:0x0055D720, source:raw]

    // Conservative worker pseudocode:
    //   complex = (SimpleGetter_14f0(dword_8B78A0) == 0);
    //   flags = this->flags_38;
    //   if (complex) {
    //     if ((flags & 0x100) == 0 || (flags & 0x400) != 0) {
    //       this->flags_38 = (flags & 0xFFFFFAFF) | 0x100;
    //       if (*(this->sub_18 + 316) == 0) {
    //         if (a3) this->buf_20 = BufferLockAllocate(dword_8B78A0, this->h_1C, 160, this->n_2C, this->cnt_8);
    //         for (i = 0; i < this->cnt_8; i++) {
    //           if (this->flags_38 & 0x800) copy6(dst, src); else copy3(dst, src);
    //           dst += 16; src += 12;
    //         }
    //         if (this->mode_0 & 2) sub_55E320(a2);
    //         else if (this->mode_0 & 1) sub_55DA50(a2);
    //         else sub_55D900(a2);
    //         if (*(this->sub_18 + 20) & 0x400000) sub_55EB30(this);
    //         goto tail;
    //       }
    //     }
    //   } else if ((flags & 0x100) == 0) {
    //     this->flags_38 = flags | 0x100;
    //     if ((this->flags_38 & 0x200) == 0 || *(char *)(this->ext_4 + 156) < 0) {
    //       if (a3) this->buf_20 = BufferLockAllocate(dword_8B78A0, this->h_1C, 160, this->n_2C, this->cnt_8);
    //       if ((this->flags_38 & 0x200) == 0) {
    //         for (i = 0; i < this->cnt_8; i++) { copy3(dst, src); dst += 16; src += 12; }
    //         this->flags_38 |= 0x200;
    //       }
    //       if (*(char *)(this->ext_4 + 156) < 0) sub_55EBA0(a2);
    //   tail:
    //       if (a3) ArithmeticComparison_0f90(dword_8B78A0, this->h_1C);
    //     }
    //   }
    // UNRESOLVED: Fields at this+0x10, this+0x14, this+0x24, this+0x28, this+0x30, this+0x40 and this+0x44 are listed as accessed but do not appear in the visible body; likely configuration of the render-state object consumed by the dispatched routines.
    // UNRESOLVED: Four callers (sub_54CA00, sub_5550E0, sub_556B10, D3DMarkDirty) invoke this routine but contribute no field evidence here.
    // UNRESOLVED: Semantics of BufferLockAllocate's 160 parameter (bucket size) and of sub_55E320/55DA50/55D900 dispatch modes are not resolvable from this packet.
}
