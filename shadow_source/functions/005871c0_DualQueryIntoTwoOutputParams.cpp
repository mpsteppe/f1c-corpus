// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005871C0
// Canonical corpus name: DualQueryIntoTwoOutputParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualQueryIntoTwoOutputParams_005871c0.c

void UnknownObject::DualQueryIntoTwoOutputParams()
{
    // Queries two values derived from the object at this+1 and stores them into two output pointers: the element count from sub_563E70 into *a2, and the field value from FieldAccessor into *a3; always returns 0.
    // ASSIGNMENT: Derive the dword index this+1 (v3) as the source object for both queries. [source:raw]
    // CALL: Store the element count from sub_563E70(this+1) into the first output pointer *a2. [callee:0x00563E70]
    // CALL: Store the field value from FieldAccessor(this+1) into the second output pointer *a3. [callee:0x0053D880]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   src = this + 1;
    //   *a2 = sub_563E70(src);
    //   *a3 = FieldAccessor(src);
    //   return 0;
    // UNRESOLVED: The object type at this+1 and the semantics of the two queried values are not evidenced in this packet.
    // UNRESOLVED: The sole recorded caller is IterateTriggersViaVtableCallHandlersPerTick (0x00585BF0); the reason for querying both values together is out of scope.
}
