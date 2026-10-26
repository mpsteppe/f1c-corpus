// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462250
// Canonical corpus name: TextureCreationWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureCreationWrapper_00462250.c

void UnknownObject::TextureCreationWrapper()
{
    // Creates a texture/data COM object via a vtable call on an interface pointer fetched from this+0 dereferenced plus 16312, sets or overrides its type, computes a network send payload length from a flag word, dispatches the object over the network, and releases the temporary object. Returns success of the send dispatch.
    // ASSIGNMENT: Derive a boolean flag from bit 27 of the flag word. [source:raw]
    // CALL: Create a COM object via the vtable at offset 0x60 on the interface stored at this+0 dereferenced plus 16312. [callee:0x0057A680, field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // GUARD: If custom type is -1, mark the object default type by setting byte at object+4 to 1; otherwise invoke the object vtable method at offset 12 to set the custom type. [source:raw]
    // STATE_TRANSITION: Select send code and flag from type selector: 1 yields code 1, 2 yields code 2 with flag 1, anything else yields code 0. [source:raw]
    // CALCULATION: Compute payload length as ((flag_word >> 8) & 0x3FF) + 8. [source:raw]
    // CALL: Dispatch the created object over the network with derived flags, code, length and context; set success flag when dispatch returns zero. [callee:0x0057A6A0, source:raw]
    // CALL: Release/destroy the temporary COM object via virtual method dispatch. [callee:0x0057A690, field:this:0x00000000, field:obj:0x00003FB8, source:raw]
    // RETURN: Return success flag: 1 when the network dispatch returned zero. [source:raw]

    // Conservative worker pseudocode:
    //   success = 0;
    //   packet_flag = (flag_word & 0x8000000) != 0;
    //   obj = COMVTableCallVia0x60(*(*(int*)this + 16312));
    //   if (custom_type == -1) obj[4] = 1;
    //   else (*(vtable+12))(obj, custom_type);
    //   if (type_selector == 1) { code = 1; write_flag = 0; }
    //   else if (type_selector == 2) { code = 2; write_flag = 1; }
    //   else { code = 0; write_flag = 0; }
    //   if (!NetworkSendDispatch(flag_word, ((flag_word >> 8) & 0x3FF) + 8, obj, packet_flag, code, send_context, write_flag))
    //       success = 1;
    //   VirtualMethodDispatch(*(*(int*)this + 16312), obj);
    //   return success;
    // UNRESOLVED: Meaning of the 16312 (0x3FB8) interface offset and the exact object type created are not derivable from this function alone.
}
