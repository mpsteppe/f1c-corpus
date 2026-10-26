// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005169AC
// Canonical corpus name: ComplexStateValidator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ComplexStateValidator_005169ac.c

void UnknownObject::ComplexStateValidator()
{
    // Validates an object state by requiring every checked field to match an expected constant: two byte flags (this+0x48, this+0x108) must be clear, four dword enum/state fields must equal 3/3/2/3, and a sub-object (this+0xC4) must have its own fields equal to fixed constants plus three fields matching a reference value loaded from this+0x114. Returns 1 only when all checks pass, otherwise 0.
    // GUARD: Guard: byte at this+0x48 must be 0 (cleared); any nonzero value returns 0. [field:this:0x00000048, source:raw]
    // GUARD: Guard: byte at this+0x108 must be 0 (cleared); any nonzero value returns 0. [field:this:0x00000108, source:raw]
    // GUARD: Guard: dword at this+0x20 must equal 3; mismatch returns 0. [guard:6, field:this:0x00000020]
    // GUARD: Guard: dword at this+0x24 must equal 3; mismatch returns 0. [guard:7, field:this:0x00000024]
    // GUARD: Guard: dword at this+0x28 must equal 2; mismatch returns 0. [guard:8, field:this:0x00000028]
    // GUARD: Guard: dword at this+0x64 must equal 3; mismatch returns 0. [guard:9, field:this:0x00000064]
    // ASSIGNMENT: Load the sub-object pointer v2 from this+0xC4. [field:this:0x000000C4]
    // GUARD: Guard: sub-object dword at +0x8 must equal 2; mismatch returns 0. [guard:0, field:*(this+0xC4):0x00000008]
    // ASSIGNMENT: Initialize the pass result to 1 before the remaining sub-object checks. [source:raw]
    // GUARD: Guard: sub-object dword at +0xC must not exceed 2 (rejected when greater); over-limit returns 0. [guard:1, field:*(this+0xC4):0x0000000C]
    // GUARD: Guard: sub-object dword at +0x5C must equal 1; mismatch returns 0. [guard:2, field:*(this+0xC4):0x0000005C]
    // GUARD: Guard: sub-object dword at +0x60 must equal 1; mismatch returns 0. [guard:3, field:*(this+0xC4):0x00000060]
    // GUARD: Guard: sub-object dword at +0xB0 must equal 1; mismatch returns 0. [guard:4, field:*(this+0xC4):0x000000B0]
    // GUARD: Guard: sub-object dword at +0xB4 must equal 1; mismatch returns 0. [guard:5, field:*(this+0xC4):0x000000B4]
    // ASSIGNMENT: Load the reference value v4 from this+0x114 that three sub-object fields must match. [field:this:0x00000114]
    // GUARD: Guard: sub-object dwords at +0x24, +0x78 and +0xCC must all equal the reference value v4; any mismatch returns 0. [field:*(this+0xC4):0x00000024, field:*(this+0xC4):0x00000078, field:*(this+0xC4):0x000000CC]
    // RETURN: Return 1 when every check passes; each failing guard returns 0. [source:raw, function:0x005169AC]
    // CALL: Function is statically called from sub_516A1D and sub_516C7B. [caller:0x00516A1D, caller:0x00516C7B]
    // UNKNOWN: ABI: __fastcall(int a1, int a2) returning char; a1 is unused, a2 is the object being validated. [abi:lead]

    // Conservative worker pseudocode:
    //   char sub_5169AC(int unused, int obj) {
    //     if (*(byte*)(obj+0x48) || *(byte*)(obj+0x108)) return 0;
    //     if (*(dword*)(obj+0x20) != 3 || *(dword*)(obj+0x24) != 3) return 0;
    //     if (*(dword*)(obj+0x28) != 2 || *(dword*)(obj+0x64) != 3) return 0;
    //     dword* sub = *(dword**)(obj+0xC4);
    //     if (sub[2] != 2 || (int)sub[3] > 2) return 0;
    //     if (sub[23] != 1 || sub[24] != 1 || sub[44] != 1 || sub[45] != 1) return 0;
    //     int ref = *(dword*)(obj+0x114);
    //     if (sub[9] != ref || sub[30] != ref || sub[51] != ref) return 0;
    //     return 1;
    //   }
    // UNRESOLVED: Object types behind this and this+0xC4 are unidentified; owner remains UnknownObject.
    // UNRESOLVED: Meaning of the expected constants 1, 2, 3 (enum/state identifiers) is not established here.
    // UNRESOLVED: Semantics of the reference value at this+0x114 and of the three matching sub-object fields are unknown.
}
