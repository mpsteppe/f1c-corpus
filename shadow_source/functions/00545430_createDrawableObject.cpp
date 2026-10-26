// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545430
// Canonical corpus name: sub_545430
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_545430_00545430.c

void UnknownObject::createDrawableObject()
{
    // Allocates a 112-byte drawable object, initializes it with float defaults and a string copy, registers it with DrawableObjectNodeManager, and writes the resulting pointer through output parameter a1 on success. On allocation or initialization failure it logs the "could not create" error via sub_53C590 and returns -1; a non-zero StringCopyWithFlagUnion result also aborts with -1. Returns 0 on success.
    // CALL: Allocate a 112-byte block through OperatorNewNhMallocWrapper(112); the resulting pointer is kept in v3. [callee:0x00587C03, source:raw]
    // CALL: Call StructInitWithFloatDefaults_d230(v3) to fill the new object with default float values; the result is kept in v4. [callee:0x0055D230, source:raw]
    // GUARD: If v3 is null or the initialization result v4 is null, the allocation/init path is blocked: log the error via sub_53C590(-1, aCouldNotCreate) and return -1. [callee:0x00587C03, callee:0x0055D230, callee:0x0053C590, global:0x005DBE30, source:raw]
    // CALL: Call StringCopyWithFlagUnion(a2, a3) to copy a string with flag/union handling into the object. [callee:0x0055D2A0, source:raw]
    // GUARD: If StringCopyWithFlagUnion(a2, a3) returns non-zero, abort with return -1 before registration. [callee:0x0055D2A0, source:raw]
    // CALL: Call DrawableObjectNodeManager(v4, a3) to register the initialized object with the drawable object node manager. [callee:0x005454D0, source:raw]
    // ASSIGNMENT: If output pointer a1 is non-null, store the initialized object pointer v4 into *a1 (offset this+0x0). [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on the successful path (registration done, optional output written); return -1 on allocation/init failure or string-copy failure. [source:raw]

    // Conservative worker pseudocode:
    //   obj = OperatorNewNhMallocWrapper(112);
    //   if (!obj || !(node = StructInitWithFloatDefaults_d230(obj))) {
    //       sub_53C590(-1, aCouldNotCreate);
    //       return -1;
    //   }
    //   if (StringCopyWithFlagUnion(a2, a3)) return -1;
    //   DrawableObjectNodeManager(node, a3);
    //   if (a1) *a1 = node;
    //   return 0;
    // UNRESOLVED: Exact class/type of the 112-byte allocated object is not evidenced; owner remains UnknownObject.
    // UNRESOLVED: a3 is passed to both StringCopyWithFlagUnion and DrawableObjectNodeManager; its role (string length, flags, or node parameter) is not resolved.
    // UNRESOLVED: The buffer/encoding semantics of the source string a2 are not evidenced.
}
