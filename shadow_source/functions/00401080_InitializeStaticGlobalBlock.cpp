// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401080
// Canonical corpus name: FunctionCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_00401080.c

void UnknownObject::InitializeStaticGlobalBlock()
{
    // One-time static-data initializer for the global block anchored at dword_5EA2C0. Fills an index table at dword_5EA2C0[2..5] with 1,2,3,4, zeroes several byte/dword/float fields in the block, stores two large constants at dword_5EA2C0[0..1], stores 0.995 into flt_5EA3E8, sets four small constant fields (1, 104, 52, 3), then returns the block's base pointer. No control flow beyond a small counting loop; no calls appear in the raw source despite the ABI lead naming this Calls_FUN_004010b0.
    // ASSIGNMENT: result = dword_5EA2C0; capture the base pointer of the global block before mutating it [global:0x005EA2C0, source:raw]
    // LOOP: v1 = 0; v2 = &dword_5EA2C0[2]; do { *v2++ = ++v1; } while (v1 < 4); write the sequence 1,2,3,4 into dword_5EA2C0[2..5] [global:0x005EA2C0, source:raw]
    // ASSIGNMENT: byte_5EA3EC = 0; clear a byte field inside the block [source:raw]
    // ASSIGNMENT: dword_5EA3F0 = 0; clear a dword field inside the block [source:raw]
    // ASSIGNMENT: *algn_5EA3F4 = 0; clear an aligned 4-byte field inside the block [source:raw]
    // ASSIGNMENT: flt_5EA3F8[0] = 0.0; flt_5EA408 = 0.0; flt_5EA40C = 0.0; clear three float fields [source:raw]
    // ASSIGNMENT: dword_5EA2C0[0] = 1083703296; dword_5EA2C0[1] = 1082785792; store two large constants at the head of the block [global:0x005EA2C0, source:raw]
    // ASSIGNMENT: flt_5EA3E8 = 0.995; store a fixed fractional value [source:raw]
    // ASSIGNMENT: unk_5EA41C = 1; unk_5EA420 = 104; unk_5EA424 = 52; unk_5EA428 = 3; store four small constant fields [source:raw]
    // RETURN: return result; yield the base pointer of the initialized global block [global:0x005EA2C0, source:raw]

    // Conservative worker pseudocode:
    //   result = dword_5EA2C0;
    //   v1 = 0;
    //   v2 = &dword_5EA2C0[2];
    //   do
    //     *v2++ = ++v1;
    //   while (v1 < 4);
    //   byte_5EA3EC = 0;
    //   dword_5EA3F0 = 0;
    //   *algn_5EA3F4 = 0;
    //   flt_5EA3F8[0] = 0.0;
    //   flt_5EA408 = 0.0;
    //   flt_5EA40C = 0.0;
    //   dword_5EA2C0[0] = 1083703296;
    //   dword_5EA2C0[1] = 1082785792;
    //   flt_5EA3E8 = 0.995;
    //   unk_5EA41C = 1;
    //   unk_5EA420 = 104;
    //   unk_5EA424 = 52;
    //   unk_5EA428 = 3;
    //   return result;
    // UNRESOLVED: the two large constants 1083703296 and 1082785792 written to dword_5EA2C0[0..1] are likely float bit patterns but their semantic meaning is not named in the packet
    // UNRESOLVED: the ABI lead names this function Calls_FUN_004010b0, yet the raw source contains no call; the relationship to function 004010b0 is unverified
    // UNRESOLVED: labels such as unk_5EA41C / flt_5EA408 are decompiler names; the enclosing struct owning the block is not identified
}
