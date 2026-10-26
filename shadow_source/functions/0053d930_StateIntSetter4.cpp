// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D930
// Canonical corpus name: StateIntSetter4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateIntSetter4_0053d930.c

void UnknownObject::StateIntSetter4()
{
    // Conditional state integer quad-setter on the receiver. Writes four consecutive state fields at this+0x1508..0x1514 from arguments a2..a5, each stored only when the corresponding argument is non-negative so a caller can pass -1 to leave a field untouched. Returns the a5 argument unchanged. Called by RenderUISystemGlobalInit (0053c360) and sub_53DB90 (0053db90).
    // GUARD: Each of the four state fields (this+0x1508, this+0x150C, this+0x1510, this+0x1514) is written only when its corresponding argument (a2..a5) is >= 0; passing -1 leaves that field untouched, enabling partial updates [field:this:0x00001508, field:this:0x0000150C, field:this:0x00001510, field:this:0x00001514, source:raw]
    // ASSIGNMENT: If a2 >= 0, this[1346] (this+0x1508) = a2 [field:this:0x00001508, source:raw]
    // ASSIGNMENT: If a3 >= 0, this[1347] (this+0x150C) = a3 [field:this:0x0000150C, source:raw]
    // ASSIGNMENT: If a4 >= 0, this[1348] (this+0x1510) = a4 [field:this:0x00001510, source:raw]
    // ASSIGNMENT: If a5 >= 0, this[1349] (this+0x1514) = a5 [field:this:0x00001514, source:raw]
    // RETURN: Returns the raw a5 argument, not the stored field value [source:raw]
    // CALL: Invoked by RenderUISystemGlobalInit (0053c360) and sub_53DB90 (0053db90) to set up to four state integers in one call [caller:0x0053C360, caller:0x0053DB90]

    // Conservative worker pseudocode:
    //   if (a2 >= 0) this[1346] = a2;
    //   if (a3 >= 0) this[1347] = a3;
    //   if (a4 >= 0) this[1348] = a4;
    //   result = a5;
    //   if (a5 >= 0) this[1349] = a5;
    //   return result;
    // UNRESOLVED: The semantics of the four state fields at this+0x1508..0x1514 are not established from this packet; they are only known to be dword state slots updated conditionally
}
