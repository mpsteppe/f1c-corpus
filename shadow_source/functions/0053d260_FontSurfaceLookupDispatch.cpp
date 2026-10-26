// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D260
// Canonical corpus name: FontSurfaceLookupDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FontSurfaceLookupDispatch_0053d260.c

void UnknownObject::FontSurfaceLookupDispatch()
{
    // Font/surface dispatch. Looks up a font surface handle by name via WideStringLinkedListSearch(a1); when the lookup returns a non-null handle, applies three field-setter calls to the caller-supplied parameters (FieldSetterAt0x48(a2), MaskedFieldSetter(a3, a4), and the switch-based SwitchBasedParameterFieldSetWithFlags(a5, a6) whose result is returned). When the lookup fails, returns the null lookup result without applying any setter.
    // CALL: Look up the named font/surface via WideStringLinkedListSearch(a1); store the returned handle (possibly null) as result. [callee:0x0053D1F0, source:raw]
    // GUARD: When the lookup result is non-null the remaining setter calls are executed; a null result short-circuits straight to the return. [source:raw]
    // CALL: Invoke FieldSetterAt0x48 with parameter a2 (writes field at offset 0x48 on an object described by a2). [callee:0x00552FC0, source:raw]
    // CALL: Invoke MaskedFieldSetter with parameters a3, a4 (masked field write). [callee:0x00552FD0, source:raw]
    // CALL: Invoke SwitchBasedParameterFieldSetWithFlags with parameters a5, a6 and return its result directly. [callee:0x00552FF0, source:raw]
    // RETURN: Return the lookup result when the name was not found (early-return path). [source:raw]
    // CALL: Invoked by sub_4F8D70 as a dispatch wrapper around the font/surface lookup and its setter chain. [caller:0x004F8D70]

    // Conservative worker pseudocode:
    //   int sub_53D260(const char *a1, int a2, int a3, int a4, int a5, int a6) {
    //     int result = WideStringLinkedListSearch(a1);
    //     if (result) {
    //       FieldSetterAt0x48(a2);
    //       MaskedFieldSetter(a3, a4);
    //       return SwitchBasedParameterFieldSetWithFlags(a5, a6);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: What object the setter chain configures (surface/font material, layout, or render state) is not evidenced in this packet.
    // UNRESOLVED: Meaning of parameters a2..a6 and of the masked/switch-based setter semantics requires reading the setter callees.
}
