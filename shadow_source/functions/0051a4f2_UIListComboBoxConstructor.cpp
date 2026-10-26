// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051A4F2
// Canonical corpus name: UIListComboBoxConstructor
// Owner: UIListComboBox [DERIVED]
// Raw source: functions/UIListComboBoxConstructor_0051a4f2.c

void UIListComboBox::UIListComboBoxConstructor()
{
    // UI list combo-box buffer constructor. Allocates a 116-byte state buffer through the sub-allocator vtable at this+0x4 and stores it at this+0x184, seeds it with function pointers (InitAndChain, ProtocolStateHandler) and a zeroed field, then branches on the a2 mode flag. Copy mode walks the sprite descriptor array at this+0xC4 (gated on count this+0x20, tripling element width when flag this+0xC8 is set), computes AlignUp dimensions, allocates one per-object buffer per element through vtable entry 5, stores the results in the buffer's output array at +18, and points the buffer's fourth slot at that array. Compositing mode instead allocates a flat 1280-byte buffer through vtable entry 1 and fills ten 128-byte strided pointers starting at buffer+8. Returns the output-array pointer in copy mode and the flat buffer base (advanced by ten strides) in compositing mode. Called by sub_516C7B.
    // CALL: Primary allocation of the 116-byte state buffer via sub-allocator vtable entry 0 (*(this+0x4)): (**(this+0x4))(this, 1, 116). [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Persist the allocated buffer at this+0x184. [field:this:0x00000184, source:raw]
    // ASSIGNMENT: Seed the state buffer: slot 0 = InitAndChain (0x005199C5), slot 2 = ProtocolStateHandler (0x0051A4B7), slot 28 = 0. [global:0x005199C5, global:0x0051A4B7, source:raw]
    // GUARD: Branch on a2: non-zero selects per-object copy mode, zero selects flat compositing mode. [source:raw]
    // GUARD: Copy mode: the descriptor walk is gated on the count at this+0x20 being greater than 0 (packet guard). [guard:0, field:this:0x00000020, source:raw]
    // LOOP: Copy mode: do-while loop over the descriptor array at this+0xC4 (element stride 84 bytes, 21 dwords), once per count in this+0x20. [field:this:0x000000C4, source:raw]
    // GUARD: Copy mode: when the flag at this+0xC8 is set, the element width (first dword of the descriptor) is tripled. [field:this:0x000000C8, source:raw]
    // CALCULATION: Copy mode: compute aligned dimensions with AlignUp from descriptor fields (this+0xC4 base, offsets 0xC/0x1C/0x20) for the per-object buffer size. [callee:0x00515927, field:*(this+0xC4):0x0000000C, field:*(this+0xC4):0x0000001C, field:*(this+0xC4):0x00000020, source:raw]
    // CALL: Copy mode: per-object buffer allocation via sub-allocator vtable entry 5 (*(this+0x4)+0x14): call(this, 1, 1, aligned_w, aligned_h, width). [field:this:0x00000004, field:*(this+0x4):0x00000014, source:raw]
    // ASSIGNMENT: Copy mode: store each per-object allocation result into the output array at buffer+18, advancing the write pointer per element. [source:raw]
    // ASSIGNMENT: Copy mode tail: buffer slot 1 = CompositingCopy (0x00519BB2), slot 3 = DrawableObjectBatchProcessor (0x00519D51), slot 4 = buffer+18 (the output array, self-referential). [global:0x00519BB2, global:0x00519D51, source:raw]
    // RETURN: Copy mode returns the output array pointer at buffer+18. [source:raw]
    // CALL: Compositing mode: flat allocation of the 1280-byte buffer via sub-allocator vtable entry 1 (*(this+0x4)+0x4): call(this, 1, 1280). [field:this:0x00000004, field:*(this+0x4):0x00000004, source:raw]
    // LOOP: Compositing mode: write ten strided pointers into buffer+8..+8+9, advancing the base by 128 bytes after each store. [source:raw]
    // ASSIGNMENT: Compositing mode tail: buffer slot 1 = sub_519BAF (0x00519BAF), slot 3 = CompositingPass (0x005199D5), slot 4 = 0. [global:0x00519BAF, global:0x005199D5, source:raw]
    // RETURN: Compositing mode returns the flat buffer base, which has been advanced by ten 128-byte strides past the allocation start. [source:raw]
    // CALL: Invoked by sub_516C7B (00516C7B) to build the combo-box state buffer for a UI list object. [caller:0x00516C7B, source:raw]

    // Conservative worker pseudocode:
    //   int sub_51A4F2(int a1, char a2) {
    //     _DWORD* buf = (**(int (__cdecl***)(int,int,int))(a1 + 4))(a1, 1, 116);
    //     *(int*)(a1 + 388) = (int)buf;
    //     buf[0] = InitAndChain;
    //     buf[2] = ProtocolStateHandler;
    //     buf[28] = 0;
    //     if (a2) {
    //       int descBase = *(int*)(a1 + 196);
    //       int n = 0;
    //       if (*(int*)(a1 + 32) > 0) {
    //         int* p = (int*)(descBase + 12);
    //         _DWORD* out = buf + 18;
    //         do {
    //           int w = *p;
    //           if (*(char*)(a1 + 200)) w *= 3;
    //           int v15 = w;
    //           int v14 = AlignUp(p[5], p[0]);
    //           int v8 = AlignUp(p[4], p[-1]);
    //           *out++ = (*(int (__cdecl**)(int,int,int,int,int,int))(*(int*)(a1+4) + 20))(a1, 1, 1, v8, v14, v15);
    //           p += 21;
    //           ++n;
    //         } while (n < *(int*)(a1 + 32));
    //       }
    //       buf[1] = CompositingCopy;
    //       buf[3] = DrawableObjectBatchProcessor;
    //       buf[4] = buf + 18;
    //       return (int)(buf + 18);
    //     }
    //     int result = (*(int (__cdecl**)(int,int,int))(*(int*)(a1 + 4) + 4))(a1, 1, 1280);
    //     _DWORD* p = buf + 8;
    //     int k = 10;
    //     do { *p++ = result; result += 128; --k; } while (k);
    //     buf[1] = sub_519BAF;
    //     buf[3] = CompositingPass;
    //     buf[4] = 0;
    //     return result;
    //   }
    // UNRESOLVED: The sub-allocator vtable at this+0x4 is invoked through entries 0/1/5 but the allocator object's identity and the exact meaning of its arguments are not resolvable from this packet.
    // UNRESOLVED: The sprite descriptor element layout (stride 84 bytes, fields at +0xC/+0x1C/+0x20 relative to this+0xC4) and the meaning of the AlignUp dimensions depend on the descriptor type, which is not defined here.
    // UNRESOLVED: The two modes return different pointer types (copy mode: per-object output array at buffer+18; compositing mode: flat buffer base advanced by ten strides), and the self-referential buffer+18 slot leaves the caller contract at 00516C7B to decide which is consumed.
    // UNRESOLVED: The identity and role of the 116-byte state buffer (slots InitAndChain, ProtocolStateHandler) beyond its function-pointer slots is unresolved.
}
