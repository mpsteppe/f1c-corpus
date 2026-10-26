// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3890
// Canonical corpus name: CompositeStringCompare
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CompositeStringCompare_004c3890.c

void UnknownObject::CompositeStringCompare()
{
    // Composite string key comparison: derives a key from the object at offset 116 on each side via sub_587ECE and returns whether the calling object's key is strictly less than the other object's key, as a BOOL.
    // CALL: Call sub_587ECE on a2 + 116 to derive the comparison key of the other object, storing the result in v3. [callee:0x00587ECE, source:raw]
    // CALL: Call sub_587ECE on this + 116 to derive the comparison key of the calling object. [callee:0x00587ECE, source:raw]
    // RETURN: Return whether the calling object's derived key is less than the other object's derived key (this + 116 key < v3). [callee:0x00587ECE, function:0x004C3890, source:raw]

    // Conservative worker pseudocode:
    //   v3 = sub_587ECE(a2 + 116);
    //   return sub_587ECE(this + 116) < v3;
    // UNRESOLVED: Offset 116 is a dword index per Hex-Rays rendering of the raw source; the actual byte field it selects is not named in the packet.
    // UNRESOLVED: The semantics of sub_587ECE (the key derivation helper) are unknown, so the exact meaning of the ordering comparison is not established.
    // UNRESOLVED: Caller context VehicleDataLoader suggests a vehicle-data string comparison, but no object type evidence exists in the packet.
}
