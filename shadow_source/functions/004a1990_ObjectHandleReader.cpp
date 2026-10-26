// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1990
// Canonical corpus name: ObjectHandleReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectHandleReader_004a1990.c

void UnknownObject::ObjectHandleReader()
{
    // Object-handle reader: __stdcall helper that passes its first argument a1 to sub_587ECE, stores the returned object handle into the caller-provided output dword a2, and returns the constant 4. No guards or fields. Called by SliderClampStringToIntControl (0x004B1BB0).
    // CALL: Call sub_587ECE (0x00587ECE) with argument a1 to obtain an object handle [callee:0x00587ECE, source:raw]
    // ASSIGNMENT: Store the sub_587ECE return value into the output dword *a2 [source:raw]
    // RETURN: Return the constant 4 (read length or status), independent of the stored handle [source:raw]
    // CALL: Invoked by SliderClampStringToIntControl (0x004B1BB0), the only known caller, to read the handle into its local output [caller:0x004B1BB0]

    // Conservative worker pseudocode:
    //   *a2 = sub_587ECE(a1);
    //   return 4;
    // UNRESOLVED: The semantics of sub_587ECE and the meaning of the constant return value 4 are not evidenced in this packet
}
