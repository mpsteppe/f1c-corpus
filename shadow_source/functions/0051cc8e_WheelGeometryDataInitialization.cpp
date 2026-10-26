// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051CC8E
// Canonical corpus name: WheelGeometryDataInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelGeometryDataInitialization_0051cc8e.c

void UnknownObject::WheelGeometryDataInitialization()
{
    // Allocates four 1024-dword lookup tables by dispatching through vtable slot 0 (vtable pointer at this+0x4) with arguments (this, 1, 1024), storing the results into the wheel data sub-struct at this+0x19C (offsets 0x10, 0x14, 0x18, 0x1C), then fills all four tables in a single loop with four independent arithmetic progressions: v9>>16 (v9 stepping by 91881), v8>>16 (v8 stepping by 116130), pointer-derived values read from unk_5B6900 with a decreasing offset, and the decreasing loop counter. Returns 0.
    // CALL: Resolve the wheel data sub-struct v2 = *(this+0x19C) and dispatch the allocator at vtable slot 0 (vtable pointer at this+0x4) with (this, 1, 1024), storing the result at v2[4] (byte offset 0x10). [field:this:0x0000019C, field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x19C):0x00000010, source:raw]
    // CALL: Dispatch the same vtable slot-0 allocator with (this, 1, 1024), storing the result at v2[5] (byte offset 0x14). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x19C):0x00000014, source:raw]
    // CALL: Dispatch the same vtable slot-0 allocator with (this, 1, 1024), storing the result at v2[6] (byte offset 0x18). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x19C):0x00000018, source:raw]
    // CALL: Dispatch the same vtable slot-0 allocator with (this, 1, 1024), storing the result at v2[7] (byte offset 0x1C). [field:this:0x00000004, field:*(this+0x4):0x00000000, field:*(this+0x19C):0x0000001C, source:raw]
    // LOOP: Fill all four tables in a single loop from counter 2919680 down to -2831590 stepping by -22554: table 0 (v2[4]) receives v9>>16 with v9 stepping by 91881, table 1 (v2[5]) receives v8>>16 with v8 stepping by 116130, table 2 (v2[6]) receives the decreasing pointer into unk_5B6900 (offset steps by 46802), and table 3 (v2[7]) receives the loop counter. The per-element index advances by 4 bytes. [field:*(this+0x19C):0x00000010, field:*(this+0x19C):0x00000014, field:*(this+0x19C):0x00000018, field:*(this+0x19C):0x0000001C, global:0x005B6900, source:raw]
    // RETURN: Return 0. [function:0x0051CC8E, source:raw]

    // Conservative worker pseudocode:
    //   v2 = *(DWORD**)(this + 0x19C);
    //   v2[4] = vtable0_alloc(this, 1, 1024);
    //   v2[5] = vtable0_alloc(this, 1, 1024);
    //   v2[6] = vtable0_alloc(this, 1, 1024);
    //   v2[7] = vtable0_alloc(this, 1, 1024);
    //   i = 2919680; v8 = -14831872; v9 = -11728000; v4 = (char*)&unk_5B6900; k = 0;
    //   while (i >= -2831590) {
    //     v2[4][k] = v9 >> 16;  v9 += 91881;
    //     v2[5][k] = v8 >> 16;  v8 += 116130;
    //     v2[6][k] = v4;        v4 -= 46802;
    //     v2[7][k] = i;         i -= 22554;
    //     k += 1;
    //   }
    //   return 0;
    // UNRESOLVED: The concrete allocator behind vtable slot 0 (this+0x4) is not resolved; no callee address is evidenced by the packet.
    // UNRESOLVED: The semantic meaning of the four arithmetic-progression tables inside the sub-struct at 0x19C (labeled wheel geometry/suspension by existing analysis) is not established by the packet.
    // UNRESOLVED: The role of unk_5B6900 and its decreasing-offset traversal are not established by the packet.
}
