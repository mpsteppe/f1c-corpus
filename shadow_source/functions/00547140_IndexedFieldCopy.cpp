// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547140
// Canonical corpus name: IndexedFieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedFieldCopy_00547140.c

void UnknownObject::IndexedFieldCopy()
{
    // Dispatches on index a2 through jump table jpt_54714C: cases 1-4 each invoke the virtual method at vtable offset 16 of the object dword_8B8F24, passing a3 plus one of this+84, this+68, this+100, this+116 as the destination field; the default case returns this. Returns the virtual-call result otherwise.
    // GUARD: Dispatch on index a2 via jump table jpt_54714C (0x005471B0); cases 1-4 select a destination this-field offset, and the default case returns immediately with this [global:0x005471B0, source:raw]
    // CALL: Case 1: invoke the virtual at vtable offset 16 of object dword_8B8F24 with arguments (a3, this+84) [global:0x008B8F24, source:raw]
    // CALL: Case 2: same virtual call on dword_8B8F24 with arguments (a3, this+68) [global:0x008B8F24, source:raw]
    // CALL: Case 3: same virtual call on dword_8B8F24 with arguments (a3, this+100) [global:0x008B8F24, source:raw]
    // CALL: Case 4: same virtual call on dword_8B8F24 with arguments (a3, this+116) [global:0x008B8F24, source:raw]
    // RETURN: Return the virtual-call result (or this in the default case); the function is invoked by ConstructorInputControlInit (0x00546250) [function:0x00547140, caller:0x00546250, source:raw]

    // Conservative worker pseudocode:
    //   switch (a2) {
    //     case 1: return vtable[4](dword_8B8F24, a3, (int)this + 84);
    //     case 2: return vtable[4](dword_8B8F24, a3, (int)this + 68);
    //     case 3: return vtable[4](dword_8B8F24, a3, (int)this + 100);
    //     case 4: return vtable[4](dword_8B8F24, a3, (int)this + 116);
    //     default: return (int)this;
    //   }
    // UNRESOLVED: The virtual callee at object dword_8B8F24 vtable offset 16 is unresolved; the packet records no callee entry, so the called method's identity is unknown
    // UNRESOLVED: The destination fields this+84, this+68, this+100, this+116 are not in the packet field list (the packet lists no fields), so their meaning is unknown
    // UNRESOLVED: Object dword_8B8F24 and the caller ConstructorInputControlInit (0x00546250) hint at an input-control setup path, but ownership is unverified
}
