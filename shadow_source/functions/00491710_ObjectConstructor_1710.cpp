// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491710
// Canonical corpus name: ObjectConstructor_1710
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructor_1710_00491710.c

void UnknownObject::ObjectConstructor_1710()
{
    // Object factory/constructor. Allocates 76 bytes via OperatorNewNhMallocWrapper; on success constructs the object by calling sub_490B00 on the new memory with argument a2 and stores the result into this+0x0; on allocation failure stores 0. Returns this. Structural twin of ObjectAllocator (0045bb90).
    // CALL: Call OperatorNewNhMallocWrapper(76) to allocate 76 bytes; result kept as v3. [callee:0x00587C03]
    // GUARD: Branch on allocation result v3: non-zero means allocation succeeded. [callee:0x00587C03]
    // CALL: On success call sub_490B00(v3, a2) to construct/initialize the object at the allocated memory. [callee:0x00490B00]
    // ASSIGNMENT: Store the sub_490B00 result into this+0x0 (success path). [field:this:0x00000000, callee:0x00490B00]
    // ASSIGNMENT: On allocation failure store 0 into this+0x0. [field:this:0x00000000]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   v3 = OperatorNewNhMallocWrapper(76);
    //   if (v3)
    //       this[0] = sub_490B00(v3, a2);
    //   else
    //       this[0] = 0;
    //   return this;
    // UNRESOLVED: Receiver class and the object type constructed by sub_490B00 are unknown.
}
