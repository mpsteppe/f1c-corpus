// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F7010
// Canonical corpus name: StateHandlerDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateHandlerDispatch_004f7010.c

void UnknownObject::StateHandlerDispatch()
{
    // Selects one of two handler tables based on the flag byte at this+0xB0 (non-zero selects the table pointer at this+0x694, zero selects this+0x6D8), then iterates up to 45 handler objects calling each one's virtual method at vtable offset 8. Writes a2 into the flag byte afterwards. Returns the selected table pointer with its low byte holding a2 (or null when no table was present).
    // GUARD: Select handler table by the flag byte at this+0xB0: non-zero selects the table A pointer at this+0x694, zero selects the table B pointer at this+0x6D8. [source:raw, field:this:0x000000B0]
    // GUARD: If the selected table pointer (this+0x694 or this+0x6D8) is null, skip handler iteration and only store a2 into the flag byte. [source:raw, field:this:0x00000694, field:this:0x000006D8]
    // LOOP: Iterate the selected handler table (A at this+0x694 or B at this+0x6D8): 45 entries at a 4-byte stride over offsets 0..176; for each non-null entry invoke the handler's virtual method at vtable offset 8. [source:raw, field:this:0x00000694, field:this:0x000006D8]
    // ASSIGNMENT: Store the new flag value a2 into the byte at this+0xB0. [source:raw, field:this:0x000000B0]
    // RETURN: Return the selected table pointer v3, whose low byte now holds a2 (or null when the flag was written without a table). [source:raw]
    // CALL: Called by sub_4A0250 and AudioSoundEffectController on the frame path. [caller:0x004A0250, caller:0x004E0ED0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4F7010(int this, char a2) {
    //     int table;
    //     if (*(BYTE*)(this+176)) {
    //       table = *(int*)(this+1684);
    //       if (table) { for (int i=0;i<180;i+=4) { int h=*(int*)(i+table); if (h) (*(void(__thiscall**)(int))(*(int*)h+8))(h); } }
    //     } else {
    //       table = *(int*)(this+1752);
    //       if (table) { for (int i=0;i<180;i+=4) { int h=*(int*)(i+table); if (h) (*(void(__thiscall**)(int))(*(int*)h+8))(h); } }
    //     }
    //     *(BYTE*)(this+176) = a2;
    //     return (char)table;
    //   }
    // UNRESOLVED: Identity of the virtual method at vtable offset 8 is unknown (indirect call with no recorded callee).
    // UNRESOLVED: Meaning of the a2 flag byte and the dual handler tables depends on the unknown owning object.
}
