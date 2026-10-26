// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044EE10
// Canonical corpus name: D3DWindowSurfaceCreation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DWindowSurfaceCreation_0044ee10.c

void UnknownObject::D3DWindowSurfaceCreation()
{
    // Creates a D3D window surface. Initializes a buffer of this with a 1/0/dword-zeroing loop, writes two surface constants at this+0xC7C and this+0xC80 (init_literals 18446744072619032576 and 18446744072598899917), stores the HWND a4 into this+0x0, registers via the ppvOut COM interface (entries +16 and +12) with the sub_44ED10 callback and unk_5AD3F0 data, then creates and configures a surface object through its vtable: nulls this+0x4, optionally acquires via unk_5AD490, sets surface descriptions with modes derived from a3, writes this+0x24C = 44, and applies unk_5B0E84. Early-exits with a negated surface Release/restore result when this+0x0 != 1, otherwise runs the v13 {20,16,0,0,1024} setup through vtable +24.
    // LOOP: Iterate over a byte/dword region of this: write 1 into the byte at (v5-256), 0 into the byte at v5, and 0 into successive DWORDs, advancing until the 256-iteration bound; v5 starts at this+0x37C so the loop touches the byte at this+0x37C [field:this:0x0000037C, source:raw]
    // ASSIGNMENT: Write surface constants to this[799] (this+0xC7C, literal -1090519040) and this[800] (this+0xC80, literal -1110651699), then store the a4 parameter (HWND) into this+0x0 [field:this:0x00000C7C, field:this:0x00000C80, field:this:0x00000000, source:raw]
    // CALL: Register via the ppvOut COM interface vtable entry +16 with parameters (19, sub_44ED10, 19, 1); this must return 0 to continue [global:0x007CA590, global:0x0044ED10, source:raw]
    // GUARD: Guard on this[158] (this+0x278) comparing equal to 19; the surface creation block proceeds only when this holds [field:this:0x00000278, guard:1, source:raw]
    // CALL: Call the ppvOut COM interface vtable entry +12 with unk_5AD3F0 and &a4 to acquire the device object; must return 0 to continue [global:0x007CA590, global:0x005AD3F0, source:raw]
    // ASSIGNMENT: Null the surface pointer this[1] (this+0x4); if the following acquire call fails or the pointer stays null, the surface remains null [field:this:0x00000004, source:raw]
    // CALL: Call the acquired device object's vtable entry +0 with unk_5AD490 and &this[1]; the surface pointer written here is then dispatched through the surface vtable pointer at *(this+0x4) [global:0x005AD490, field:*(this+0x4):0x00000000, source:raw]
    // CALL: Call the device object's vtable entry +8, then the surface vtable entry +52 twice with mode constants 22 + 4*(a3!=0) and 22 + 4*(a3==0) to set the surface descriptions [field:*(*(this+0x4)+0x0):0x00000034, source:raw]
    // ASSIGNMENT: Write literal 44 into this[147] (this+0x24C), used as the surface description input [field:this:0x0000024C, source:raw]
    // CALL: Call the surface vtable entry +12 with &this[147] and, when that succeeds, the surface vtable entry +44 with unk_5B0E84 [field:*(*(this+0x4)+0x0):0x0000000C, field:*(*(this+0x4)+0x0):0x0000002C, global:0x005B0E84, source:raw]
    // GUARD: Guard on this+0x0 comparing not-equal to 1: when the stored HWND differs from 1, return the negated result of the surface vtable entry +28 call [field:this:0x00000000, guard:0, field:*(*(this+0x4)+0x0):0x0000001C, source:raw]
    // CALL: Fill the local v13 block {20,16,0,0,1024} and call the surface vtable entry +24 with (1, v13); on failure return the negated surface vtable entry +28 result [field:*(*(this+0x4)+0x0):0x00000018, field:*(*(this+0x4)+0x0):0x0000001C, source:raw]
    // RETURN: Default return of -1 at the end of the function; the function is invoked by HWInput_Setup (00455C60) [caller:0x00455C60, function:0x0044EE10, source:raw]

    // Conservative worker pseudocode:
    //   for (region loop, 256 iterations) {
    //     *(v5 - 256) = 1; *v5 = 0;
    //     *v6++ = 0; ++v5;
    //   }
    //   this[799] = -1090519040;
    //   this[800] = -1110651699;
    //   this[0] = a4;
    //   if (ppvOut->vtable[16](ppvOut, 19, sub_44ED10, 19, 1) == 0
    //       && this[158] == 19
    //       && ppvOut->vtable[12](ppvOut, &unk_5AD3F0, &a4, 0) == 0) {
    //     v8 = &this[1]; this[1] = 0;
    //     if (a4->vtable[0](a4, &unk_5AD490, &this[1]) != 0 || *v8 == 0) {
    //       *v8 = 0;
    //     } else {
    //       a4->vtable[8](a4); a4 = 0;
    //       if (v8->vtable[52](*v8, a2, 22 + 4*(a3!=0)) != 0
    //           || v8->vtable[52](*v8, a2, 22 + 4*(a3==0)) != 0) {
    //         this[147] = 44;
    //         if (v8->vtable[12](*v8, &this[147]) == 0
    //             && v8->vtable[44](*v8, &unk_5B0E84) == 0) {
    //           if (this[0] != 1)
    //             return -(v8->vtable[28](*v8) != 0);
    //           v13 = {20, 16, 0, 0, 1024};
    //           if (v8->vtable[24](*v8, 1, v13) != 0)
    //             return -(v8->vtable[28](*v8) != 0);
    //         }
    //       }
    //     }
    //   }
    //   return -1;
    // UNRESOLVED: The exact DirectDraw/D3D interface contracts behind ppvOut (0x007CA590) and the unk_5AD3F0/unk_5AD490/unk_5B0E84 data blobs are not resolvable from this packet; vtable slot meanings are inferred from call position only
    // UNRESOLVED: The v13 block semantics ({20,16,0,0,1024}) passed to surface vtable +24 are unknown
    // UNRESOLVED: Guard this+0x0 != 1 uses the stored HWND field as a mode discriminator; the meaning of value 1 is undocumented here
    // UNRESOLVED: The init_literal values 18446744072619032576 and 18446744072598899917 are recorded in the packet as the 32-bit writes at this+0xC7C/this+0xC80; their float interpretation is not asserted
}
