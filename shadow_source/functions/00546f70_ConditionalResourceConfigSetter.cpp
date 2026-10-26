// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546F70
// Canonical corpus name: sub_546F70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_546F70_00546f70.c

void UnknownObject::ConditionalResourceConfigSetter()
{
    // Range-gated resource-object configuration. Reads the bound value at this+0xA4; when a2 < bound and bound < 8 it runs four setters (SimpleSetter_fc40(&unk_800000), DualFieldSetter(0, 0), ShortComputation_fd30(1065353216, 1065353216), FieldSetter_fca0(2)) and ORs bit 0x80 into the flags at this+0x9C. Returns 0 on both the taken and the blocked path.
    // CALCULATION: v3 = this[41] reads the comparison bound stored at this+0xA4 [field:this:0x000000A4, source:raw]
    // GUARD: Configuration runs only when a2 < v3 AND v3 < 8; otherwise the function returns 0 with no side effects [field:this:0x000000A4, source:raw]
    // CALL: SimpleSetter_fc40 is invoked with the address of the global unk_800000 as its argument [callee:0x0054FC40, global:0x00800000, source:raw]
    // CALL: DualFieldSetter is invoked with two zero arguments [callee:0x0054FC80, source:raw]
    // CALL: ShortComputation_fd30 is invoked with the float literal 1065353216 twice (1.0f) [callee:0x0054FD30, source:raw]
    // CALL: FieldSetter_fca0 is invoked with the argument 2 [callee:0x0054FCA0, source:raw]
    // ASSIGNMENT: Flags at this+0x9C get bit 0x80 (bit 7) OR-ed in when the range guard passes [field:this:0x0000009C, source:raw]
    // RETURN: Returns 0 unconditionally after the guarded block [source:raw]
    // CALL: Reached from ResourceObjectCreationWithConfig (005474d0), DirectXMeshVertexBufferParsingAndLoading (00547b40) and D3DTextureResourceCreation (00548190), all resource-creation paths [caller:0x005474D0, caller:0x00547B40, caller:0x00548190, source:raw]

    // Conservative worker pseudocode:
    //   int sub_546F70(this, a2) {
    //     v3 = this[41];
    //     if (a2 < v3 && v3 < 8) {
    //       SimpleSetter_fc40(&unk_800000);
    //       DualFieldSetter(0, 0);
    //       ShortComputation_fd30(1065353216, 1065353216);
    //       FieldSetter_fca0(2);
    //       this[39] |= 0x80;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Which resource fields the four setters write and what unk_800000 represents are unknown.
    // UNRESOLVED: Meaning of the 0x80 flag at this+0x9C and why the bound at this+0xA4 is capped at 8 is unknown.
    // UNRESOLVED: Owner class is unknown; callers are all D3D/resource creation paths.
}
