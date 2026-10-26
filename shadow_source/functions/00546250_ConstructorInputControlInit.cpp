// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546250
// Canonical corpus name: ConstructorInputControlInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorInputControlInit_00546250.c

void UnknownObject::ConstructorInputControlInit()
{
    // Constructor/initializer for an input-control object. Zero-initializes the object via GlobalZeroInit_c2a0, writes 14 fields at this+0x84..this+0xC0 to literals (including a float 294912.0625 at +0x9C, an all-bits-set sentinel at +0xA0, 65538 at +0xAC and float 1.0 at +0xB0), memsets the first 0x40 bytes, then configures four indexed control channels through IndexedFieldCopy(1..4, ...) and SwitchBasedFloatSetter(1..4, 0). Returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the object. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: this[39] (this+0x9C) = 1217396738 (float 294912.0625): encoded state/parameter literal. [field:this:0x0000009C, source:raw]
    // ASSIGNMENT: this[40] (this+0xA0) = -1 (all bits set; unsigned 18446744073709551615): no-entry/invalid sentinel. [field:this:0x000000A0, source:raw]
    // ASSIGNMENT: this[34] (this+0x88) = 0. [field:this:0x00000088, source:raw]
    // ASSIGNMENT: this[33] (this+0x84) = 0. [field:this:0x00000084, source:raw]
    // CALL: memset(this, 0, 0x40): zero the first 64 bytes of the object. [source:raw]
    // CALL: IndexedFieldCopy(2, 0xFFFFFF): copy the 0xFFFFFF value into control channel 2. [callee:0x00547140, source:raw]
    // CALL: IndexedFieldCopy(1, 0xFFFFFF): copy the 0xFFFFFF value into control channel 1. [callee:0x00547140, source:raw]
    // CALL: IndexedFieldCopy(3, 0): copy 0 into control channel 3. [callee:0x00547140, source:raw]
    // CALL: IndexedFieldCopy(4, 0): copy 0 into control channel 4. [callee:0x00547140, source:raw]
    // CALL: SwitchBasedFloatSetter(2, 0): set the float state of control channel 2 to 0. [callee:0x005471D0, source:raw]
    // CALL: SwitchBasedFloatSetter(1, 0): set the float state of control channel 1 to 0. [callee:0x005471D0, source:raw]
    // CALL: SwitchBasedFloatSetter(3, 0): set the float state of control channel 3 to 0. [callee:0x005471D0, source:raw]
    // CALL: SwitchBasedFloatSetter(4, 0): set the float state of control channel 4 to 0. [callee:0x005471D0, source:raw]
    // ASSIGNMENT: this[41] (this+0xA4) = 0. [field:this:0x000000A4, source:raw]
    // ASSIGNMENT: this[42] (this+0xA8) = 0. [field:this:0x000000A8, source:raw]
    // ASSIGNMENT: this[45] (this+0xB4) = 0. [field:this:0x000000B4, source:raw]
    // ASSIGNMENT: this[37] (this+0x94) = 0. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: this[38] (this+0x98) = 0. [field:this:0x00000098, source:raw]
    // ASSIGNMENT: this[46] (this+0xB8) = 0. [field:this:0x000000B8, source:raw]
    // ASSIGNMENT: this[48] (this+0xC0) = 0. [field:this:0x000000C0, source:raw]
    // ASSIGNMENT: this[47] (this+0xBC) = 0. [field:this:0x000000BC, source:raw]
    // ASSIGNMENT: this[43] (this+0xAC) = 65538: packed control-state literal. [field:this:0x000000AC, source:raw]
    // ASSIGNMENT: this[44] (this+0xB0) = 1065353216 (float 1.0): default scale/multiplier. [field:this:0x000000B0, source:raw]
    // RETURN: Return this as the constructed object pointer. [source:raw, function:0x00546250]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   this[39] = 1217396738; /* this+0x9C, float 294912.0625 * /
    //   this[40] = -1;         /* this+0xA0, all bits set * /
    //   this[34] = 0; this[33] = 0;
    //   memset(this, 0, 0x40);
    //   IndexedFieldCopy(2, 0xFFFFFF); IndexedFieldCopy(1, 0xFFFFFF);
    //   IndexedFieldCopy(3, 0); IndexedFieldCopy(4, 0);
    //   SwitchBasedFloatSetter(2, 0); SwitchBasedFloatSetter(1, 0);
    //   SwitchBasedFloatSetter(3, 0); SwitchBasedFloatSetter(4, 0);
    //   this[41]=0; this[42]=0; this[45]=0; this[37]=0; this[38]=0;
    //   this[46]=0; this[48]=0; this[47]=0;
    //   this[43] = 65538; /* this+0xAC * /
    //   this[44] = 1065353216; /* this+0xB0, float 1.0 * /
    //   return this;
    // UNRESOLVED: Which object fields the IndexedFieldCopy/SwitchBasedFloatSetter calls (channels 1-4) actually write is not evidenced; the packet gives no object-relative offset for them, so they cannot be linked to the field table's this+0x84..this+0xC0 offsets.
    // UNRESOLVED: Semantics of the literal 1217396738 (this+0x9C) and the packed literal 65538 (this+0xAC) are unknown.
    // UNRESOLVED: The ABI lead (LEGACY) names a constructor and is consistent with the body; callers (ResourceObjectCreationWithConfig, DirectXMeshVertexBufferParsingAndLoading, D3DTextureResourceCreation) invoke it during resource-object creation, but no owner object is evidenced.
}
