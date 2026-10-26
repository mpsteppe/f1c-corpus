// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540CA1
// Canonical corpus name: PhysicsStateStoreTwoInts
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStateStoreTwoInts_00540ca1.c

void UnknownObject::PhysicsStateStoreTwoInts()
{
    // Stores two consecutive dwords into a physics/vehicle state object: a2 at a3 + 5084 and result at a3 + 5088, then returns result (eax). The __userpurge ABI reuses the eax return register as the second stored value; a4 is unused.
    // ASSIGNMENT: Store the first int a2 (edx) into the state object: *(_DWORD *)(a3 + 5084) = a2. [source:raw, function:0x00540CA1]
    // ASSIGNMENT: Store the second int result (eax) into the adjacent state slot: *(_DWORD *)(a3 + 5088) = result. [source:raw]
    // RETURN: Return result (eax), which is also the value just stored at a3 + 5088. [source:raw]
    // UNKNOWN: __userpurge ABI: result arrives in eax, a2 in edx, a3 (state base) in ecx; a4 is declared but unused. [abi:lead, function:0x00540CA1]

    // Conservative worker pseudocode:
    //   // a3: state object; writes two adjacent ints and returns the second
    //   state.a3[5084] = a2;
    //   state.a3[5088] = result;
    //   return result;
    // UNRESOLVED: Meaning of the adjacent dword pair at a3 + 5084 and a3 + 5088 (a state snapshot pair) is not named in this packet.
    // UNRESOLVED: Identity of the state object a3 is not established; +5084/+5088 have no named field mapping here.
}
