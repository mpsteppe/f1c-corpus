// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414E54
// Canonical corpus name: PlayerSteeringUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerSteeringUpdate_00414e54.c

void UnknownObject::PlayerSteeringUpdate()
{
    // Accumulates a per-frame steering delta a1 (char, passed in bl) into a byte accumulator at a2 + 51. When that signed addition does not set the flag composite (no overflow/zero), it records the target object pointer a2 at _ESI + 12 and the delta a1 at _ESI + 16. The rcr instruction and the 'sp value detected' warning are decompiler artifacts; the ABI is a register-based __usercall.
    // CALCULATION: Compute the flag composite v3 from a1 + *(BYTE)(a2 + 51): (sign bit XOR overflow bit) OR zero flag. This captures the signed-add condition that later gates the store. [source:raw, function:0x00414E54]
    // ASSIGNMENT: Accumulate the steering delta into the byte counter: *(BYTE)(a2 + 51) += a1. [source:raw]
    // UNKNOWN: rcr byte ptr [esi-7Fh], 0C4h appears in the raw source but is decompiler noise from the register-based calling convention; it does not correspond to the store logic. [source:raw, function:0x00414E54]
    // GUARD: Branch on !v3: the state update is performed only when the accumulation did not set the flag composite. [source:raw]
    // ASSIGNMENT: Store the target object pointer into the state object: *(_DWORD *)(_ESI + 12) = a2. [source:raw]
    // ASSIGNMENT: Store the steering delta into the state object: *(_BYTE *)(_ESI + 16) = a1. [source:raw]
    // UNKNOWN: Register-based __usercall ABI: a1 in bl, a2 in edi, state base in esi; the positive-sp warning marks the disassembly as potentially unreliable around the rcr artifact. [abi:lead, function:0x00414E54]

    // Conservative worker pseudocode:
    //   // a1: steering delta (char, bl); a2: target object; _ESI: steering state
    //   v3 = signed_add_flags(a1, obj.byte[51]);   // Hex-Rays flag composite
    //   obj.byte[51] += a1;
    //   if (!v3) { state.dword[3] = a2; state.byte[4] = a1; }
    // UNRESOLVED: Exact flag semantics of v3 (sign-bit XOR overflow OR zero) are a Hex-Rays artifact of the original flags capture; only the conditional-store behavior is certain.
    // UNRESOLVED: Meaning of the rcr instruction is not resolvable from this packet; treated as decompiler noise.
    // UNRESOLVED: Identity of the state object _ESI and the target object a2 is not established; the +12/+16 and +51 offsets have no named field mapping here.
}
