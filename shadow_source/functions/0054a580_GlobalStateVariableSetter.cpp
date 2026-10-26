// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A580
// Canonical corpus name: GlobalStateVariableSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateVariableSetter_0054a580.c

void UnknownObject::GlobalStateVariableSetter()
{
    // Mode-based update of the global state variable dword_8B8F3C. When a3 is 0 the variable is set directly to a2; when a3 is 1 (non-zero, non-two) a2 is added to it; when a3 is 2 the variable is set to dword_8B8F38 - a2. Returns a3 when a3 is 0, dword_8B8F38 - a2 when a3 is 2, and a3 - 2 otherwise.
    // ASSIGNMENT: Initialize result to a3 before mode dispatch. [source:raw]
    // GUARD: When a3 is 0, assign dword_8B8F3C = a2 directly. [global:0x008B8F3C, source:raw]
    // GUARD: When a3 == 2, recompute dword_8B8F3C = dword_8B8F38 - a2 and set result to that value. [global:0x008B8F38, global:0x008B8F3C, source:raw]
    // ASSIGNMENT: Otherwise (a3 == 1), accumulate: dword_8B8F3C += a2. [global:0x008B8F3C, source:raw]
    // RETURN: Return result: a3 (0) when a3 == 0, dword_8B8F38 - a2 when a3 == 2, a3 - 2 when a3 == 1. [function:0x0054A580, source:raw]
    // CALL: Invoked by sub_54AC70 (0054AC70) to update the global state variable. [caller:0x0054AC70, source:raw]

    // Conservative worker pseudocode:
    //   result = a3;
    //   if (a3 == 0) { dword_8B8F3C = a2; }
    //   else if (a3 == 2) { result = dword_8B8F38 - a2; dword_8B8F3C = result; }
    //   else { dword_8B8F3C += a2; }
    //   return result;
    // UNRESOLVED: Semantic roles of a2 (absolute value or increment) and a3 (mode selector) are inferred from arithmetic only; no caller contract or global type is available.
    // UNRESOLVED: dword_8B8F38 is read but never written here; its producer is unknown.
}
