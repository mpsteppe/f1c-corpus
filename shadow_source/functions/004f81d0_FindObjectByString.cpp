// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F81D0
// Canonical corpus name: StringMatchWithWildcard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringMatchWithWildcard_004f81d0.c

void UnknownObject::FindObjectByString()
{
    // Looks up an object by string identifier. Requires a non-null output pointer a1 and string descriptor a2. Uses *a2 as the lookup string, falling back to global default string byte_5EA438 when *a2 is empty. An empty selected string writes 0 to *a1 and returns 1. When global vtable object dword_8AC4C4 is non-null, dispatches its vtable slot at +92 (__thiscall) with arguments (a2, a3, a4), stores the returned handle in *a1, then validates the handle by calling its vtable slot at +20; a zero return from that validation call makes the function return 0. Otherwise returns 1. Called from sub_4F70C0.
    // GUARD: Proceed only when both the output pointer a1 and the string descriptor a2 are non-null. [source:raw]
    // ASSIGNMENT: Select the lookup string: *a2, or the global default string byte_5EA438 when *a2 is null. [global:0x005EA438, source:raw]
    // GUARD: When the selected string has zero length, short-circuit: write 0 to *a1 and return 1. [field:this:0x00000000, source:raw]
    // GUARD: Perform the virtual lookup only when the global vtable object dword_8AC4C4 is non-null. [global:0x008AC4C4, source:raw]
    // CALL: Dispatch dword_8AC4C4's vtable slot at +92 (__thiscall) with arguments (a2, a3, a4) and store the returned handle in *a1. [global:0x008AC4C4, field:this:0x00000000, source:raw]
    // GUARD: When the lookup returned a non-null handle, validate it by calling the handle's vtable slot at +20; a zero return makes the function return 0. [field:this:0x00000000, source:raw]
    // RETURN: Return 1 on the short-circuit and default success paths. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4F81D0(int* out, const char** in, int a3, int a4) {
    //     int ok = 1;
    //     if (out && in) {
    //       const char* s = *in ? *in : byte_5EA438;
    //       if (!strlen(s)) { *out = 0; return 1; }
    //       if (dword_8AC4C4) {
    //         int handle = (*(int (__thiscall **)(const char**, int, int))(*(int*)dword_8AC4C4 + 92))(dword_8AC4C4, in, a3, a4);
    //         *out = handle;
    //         if (handle && !(*(int (__thiscall **)(int))(*(int*)handle + 20))(handle))
    //           return 0;
    //       }
    //     }
    //     return ok;
    //   }
    // UNRESOLVED: Semantics of the +92 lookup dispatch and the +20 validation dispatch depend on the runtime object behind global dword_8AC4C4; vtable offsets come from the raw source but the class identity is unknown.
    // UNRESOLVED: Meaning of a3/a4 (filter or context arguments) is unknown.
    // UNRESOLVED: Whether the returned handle is released by the caller is unknown.
}
