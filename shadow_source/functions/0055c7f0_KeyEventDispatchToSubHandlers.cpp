// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C7F0
// Canonical corpus name: KeyEventDispatchToSubHandlers
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/KeyEventDispatchToSubHandlers_0055c7f0.c

void UnknownObject::KeyEventDispatchToSubHandlers()
{
    // Key-event dispatch: prepares a key-event buffer from the field at this+0x1544 via sub_55C650, resolves the key state into v4 via sub_55C450, then filters on the event message type a2. Only a2 == 0x200000 passes; a2 == 32 routes to InputStateQueryWrapper, a2 == 16 routes to sub_55C7B0, and every other value is blocked with a -1 return.
    // CALL: Prepare the key-event buffer: call sub_55C650(&v4, this[0x1544], 0), passing the field at this+0x1544 as the source configuration. [callee:0x0055C650, field:this:0x00001544, source:raw]
    // CALL: Resolve the key state: call sub_55C450(v4, &v4, &v5), producing the key code used by the subsequent guards. [callee:0x0055C450, source:raw]
    // GUARD: Block the event when the message type a2 is not 0x200000: return (int *)-1 immediately. [source:raw]
    // GUARD: When the resolved key code v4 equals 32, dispatch to InputStateQueryWrapper (callee 0x0055C7D0). [callee:0x0055C7D0, source:raw]
    // GUARD: When the resolved key code v4 equals 16, dispatch to sub_55C7B0 (callee 0x0055C7B0). [callee:0x0055C7B0, source:raw]
    // RETURN: Return (int *)-1 for every unmatched or blocked path (message type other than 0x200000, or key code other than 32 and 16). [source:raw]

    // Conservative worker pseudocode:
    //   sub_55C650(&v4, this[0x1544], 0);
    //   sub_55C450(v4, &v4, &v5);
    //   if (a2 != 0x200000) return (int *)-1;
    //   if (v4 == 32) return InputStateQueryWrapper(v2);
    //   if (v4 == 16) return sub_55C7B0(v2);
    //   return (int *)-1;
    // UNRESOLVED: The v2 value (ecx) passed to InputStateQueryWrapper and sub_55C7B0 is uninitialized in the decompiler output; it is a register-passing artifact, not a known argument.
    // UNRESOLVED: The existing analysis maps key code 32 to the space key and 16 to the shift key; that mapping is prose (skeleton fill), not packet evidence.
    // UNRESOLVED: The owning class of the this pointer and the semantic role of the field at +0x1544 (configuration/buffer source) are DERIVED, not confirmed.
    // UNRESOLVED: Caller D3DTextureCreation (0x00550080) is the only recorded caller; the broader input/UI event context is not evidenced in this packet.
}
