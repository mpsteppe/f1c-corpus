// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490B00
// Canonical corpus name: sub_490B00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_490B00_00490b00.c

void UnknownObject::FixedBucketArrayInit()
{
    // Constructor for a fixed-capacity bucket-array struct. Zeros twelve 32-bit state DWORDs at this+0x4..this+0x38, initializes the embedded sub-object at this+0x3C via ThunkToFUN00491330, stores the requested element count a2 into this+0x0, then allocates a 16-byte-per-element array (16*a2+4 bytes) through OperatorNewNhMallocWrapper, zero-fills every element (four DWORDs each) and stores the payload pointer in this+0x8 (or 0 on allocation failure). Returns the struct pointer. Called by ObjectConstructor_1710 (00491710).
    // ASSIGNMENT: Zeros twelve consecutive DWORD state fields at this+0x4, this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C, this+0x20, this+0x24, this+0x28, this+0x2C, this+0x30 and this+0x34 to the literal 0 [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: ThunkToFUN00491330 invoked on the embedded sub-object at this+15 (byte offset 0x3C) to initialize it [callee:0x004912F0, source:raw]
    // ASSIGNMENT: Stores the element count a2 into this+0x0 (this[0]); no init literal in packet, value is the a2 parameter [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clears this+0x38 (this[14]) to 0 as part of the state block initialisation [field:this:0x00000038, source:raw]
    // CALL: OperatorNewNhMallocWrapper allocates 16*a2+4 bytes for the element array [callee:0x00587C03, source:raw]
    // GUARD: Allocation result v3 is tested for null; non-null selects the fill branch, null stores 0 into this+0x8 [source:raw]
    // ASSIGNMENT: Writes a2 as the allocation header DWORD and derives the payload pointer v4 = v3+1 used as the element array base [source:raw]
    // LOOP: Zero-fill loop walks the payload array four DWORDs at a time (16 bytes per element), running exactly a2 times, zeroing fields 0x0..0xC of each element [source:raw]
    // ASSIGNMENT: Stores the element array payload pointer v4 into this+0x8, or 0 when the allocation failed [field:this:0x00000008, source:raw]
    // RETURN: Returns the constructed struct pointer (this) on both the success and the allocation-failure path [source:raw]
    // CALL: Invoked by ObjectConstructor_1710 (00491710) during its object construction sequence [caller:0x00491710, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 4; i <= 0x38; i += 4) *(this + i) = 0;
    //   ThunkToFUN00491330(this + 15);
    //   this[0] = a2;
    //   v3 = OperatorNewNhMallocWrapper(16 * a2 + 4);
    //   if (v3) {
    //     *v3 = a2;
    //     v4 = v3 + 1;
    //     for (n = a2; n > 0; --n) { v4[0]=0; v4[1]=0; v4[2]=0; v4[3]=0; v4 += 4; }
    //     this[2] = v4;
    //   } else {
    //     this[2] = 0;
    //   }
    //   return this;
    // UNRESOLVED: The embedded sub-object target of ThunkToFUN00491330 (this+0x3C) is not identified; its field layout is out of scope for this packet
    // UNRESOLVED: The element layout at 16 bytes per element is inferred from the four-DWORD fill step; no named field semantics for the elements exist
    // UNRESOLVED: this+0x4 (offset 0x4) is zeroed here but the skeleton names it a counter/index with no corroboration inside this function
}
