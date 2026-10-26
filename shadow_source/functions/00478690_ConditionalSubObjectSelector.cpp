// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478690
// Canonical corpus name: ShortComputation_8690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8690_00478690.c

void UnknownObject::ConditionalSubObjectSelector()
{
    // Selects between a live sub-object pointer and null based on a boolean flag at this+0x138 (this[78]). Reads the object's vtable pointer at this+0 and calls the virtual method at vtable+0x3C with an integer enable/disable argument (1 when the flag is set, 0 otherwise). On the enabled path it returns the sub-object pointer this+70; on the disabled path it returns null.
    // GUARD: Test the flag at this+0x138 (this[78]): non-zero selects the enabled sub-object path, zero selects the disabled path [field:this:0x00000138, source:raw]
    // CALL: Enabled path: read the vtable pointer at this+0, load the virtual method at vtable+0x3C, and call it on this with argument 1 [field:this:0x00000000, field:obj:0x0000003C, source:raw]
    // RETURN: Enabled path: return the sub-object pointer this+70 (byte offset 0x118) [source:raw]
    // CALL: Disabled path: call the same vtable+0x3C method on this with argument 0 [field:this:0x00000000, field:obj:0x0000003C, source:raw]
    // RETURN: Disabled path: return null [source:raw]

    // Conservative worker pseudocode:
    //   if (this[78]) {
    //     vtable[0x3C](this, 1);
    //     return this + 70;
    //   }
    //   vtable[0x3C](this, 0);
    //   return 0;
    // UNRESOLVED: The identity and purpose of the virtual method at vtable+0x3C are not derivable; the packet records no callee address for the indirect call
    // UNRESOLVED: The meaning of the enable/disable integer argument (1 vs 0) and what the returned sub-object (this+70) represents is unverified
    // UNRESOLVED: No caller or callee is recorded for this function in the packet
}
