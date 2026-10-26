// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C070
// Canonical corpus name: sub_55C070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C070_0055c070.c

void UnknownObject::RenderResourcePropertyBinder()
{
    // Binds render resource properties from a resource descriptor a2: initializes a local struct, and when the a2+36 flag bit 2 is clear allocates and fills a vertex/index buffer through a render-device vtable call (+144), storing the resulting object in *this. When the a3 flag bit 0x10 is clear it configures render properties via MultiFieldSetterDispatchingTo7SubSetters and sub_554790, syncs a session-event resource reference, then walks the descriptor's resource list allocating locked buffers (BufferLockAllocate), copying vertex data, and pushing each resource through render-device vtable methods (+340, +284). Finally marks the descriptor as processed.
    // CALL: StructInitWithDefaultValues(v21) initializes the local struct v21. [callee:0x00553DB0, source:raw]
    // GUARD: When the flag bit 2 of the byte at a2 + 36 is clear, the buffer-init path runs. [source:raw]
    // CALL: sub_5424E0 computes the source geometry (v17..v20) from the descriptor's source pointer at a2 + 12. [callee:0x005424E0, source:raw]
    // CALL: Render-device vtable call at +144 (field *(this+0x1100):0x90): with the computed bounds, creates the vertex/index buffer from the source's element count at (a2+12)+124; the returned object is stored into *this. [field:*(this+0x1100):0x00000090, field:this:0x00001100, field:this:0x00000000, source:raw]
    // GUARD: When the a3 flag bit 0x10 is clear, the render-property path runs. [source:raw]
    // ASSIGNMENT: Set v21[8] = 5 (property-set selector) and call MultiFieldSetterDispatchingTo7SubSetters(this + 1118, v21, 0). [callee:0x005546A0, source:raw]
    // CALL: sub_554790(this, 256, 0, 0) applies a property change with the value 256. [callee:0x00554790, source:raw]
    // CALL: Render-device vtable call at +200 (field *(this+0x1100):0xC8) with the argument 7 stores a status result into *this. [field:*(this+0x1100):0x000000C8, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Resource reference sync: when the descriptor's resource pointer v9[78] differs from the stored this[1267] (this+0x13CC), update this[1267] and log the new value via LogSessionEvent. [field:this:0x000013CC, callee:0x0054B9E0, source:raw]
    // LOOP: Loop over v9[70] resource entries (pointer list at v9[71] + 28): for each entry whose flags (v9[5] bit 0x1000000) and v9[79] permit it, BufferLockAllocate allocates a locked 160-byte buffer and 16 dwords per element are copied from the source into it. [callee:0x00540F00, source:raw]
    // CALL: ArithmeticComparison_0f90(this, *v11) and PropertyValueSetterWithRefreshOnChange(this, *v11) complete each per-resource buffer setup. [callee:0x00540F90, callee:0x00554700, source:raw]
    // CALL: Per-resource render-device vtable calls: +340 (field *(this+0x1100):0x154) applies the resource, and +284 (field *(this+0x1100):0x11C) uploads the buffer data with an element count of (v15 - 2) when the descriptor flag bit 7 of v9[5] byte 1 is clear, otherwise v15 / 3. [field:*(this+0x1100):0x00000154, field:*(this+0x1100):0x0000011C, source:raw]
    // ASSIGNMENT: Mark the descriptor processed: v9[5] |= 0x1000000. [source:raw]
    // CALL: Final render-device vtable call at +200 (field *(this+0x1100):0xC8) with this[1262] (this+0x13B8) stores the last status result into *this. [field:*(this+0x1100):0x000000C8, field:this:0x000013B8, field:this:0x00000000, source:raw]
    // RETURN: Return the last status pointer (result / *this). [source:raw]

    // Conservative worker pseudocode:
    //   StructInitWithDefaultValues(v21);
    //   if ((a2[36] & 4) == 0) {
    //     sub_5424E0(*(a2 + 12), &v17, &v18, &v19, &v20);
    //     v19 += v17; v20 += v18;
    //     *this = renderDevice->vtable[144](renderDevice, 1, &v17, 1, *(a2+12)->dword124, 0, 0);
    //   }
    //   if ((a3 & 0x10) == 0) {
    //     v21[8] = 5;
    //     MultiFieldSetterDispatchingTo7SubSetters(this + 1118, v21, 0);
    //     sub_554790(this, 256, 0, 0);
    //     *this = renderDevice->vtable[200](renderDevice, 7, 0);
    //     if (v9[78] != this[1267]) { this[1267] = v9[78]; LogSessionEvent(v9[78]); }
    //     for (v22 = 0; v22 < v9[70]; v22++) {
    //       if ((v9[5] & 0x1000000) == 0 && !v9[79]) {
    //         v12 = BufferLockAllocate(this, *v11, 160, v11[4], *(v11 - 5));
    //         copy 16 dwords per element from v14 into v12;
    //         ArithmeticComparison_0f90(this, *v11);
    //       }
    //       PropertyValueSetterWithRefreshOnChange(this, *v11);
    //       *this = renderDevice->vtable[340](renderDevice, *(v11[2] + 24), v11[4]);
    //       if ((BYTE1(v9[5]) & 0x80) == 0)
    //         *this = renderDevice->vtable[284](renderDevice, 5, 0, *(v11 - 5), v11[5], v15 - 2);
    //       else
    //         *this = renderDevice->vtable[284](renderDevice, 4, 0, *(v11 - 5), v11[5], v15 / 3);
    //       v11 += 16;
    //     }
    //     v9[5] |= 0x1000000;
    //     result = renderDevice->vtable[200](renderDevice, 7, this[1262]);
    //     *this = result;
    //   }
    //   return result;
    // UNRESOLVED: The render-device vtable method offsets (+144, +200, +284, +340) are rendered in the raw source as direct dispatch slots on the object at this+0x1100; their concrete interfaces are not resolved beyond the field evidence.
    // UNRESOLVED: The descriptor a2 layout (flag byte at a2+36, source pointer at a2+12, resource-list header at a2+24) is inferred from the raw-source indexing; the a2 field semantics follow the existing analysis fill at DERIVED trust.
    // UNRESOLVED: The purpose of the v11 / v15 index arithmetic (16-dword entry stride, 12-dword source stride, v15 - 2 vs v15 / 3 element counts) is only partially evident from the raw source.
}
