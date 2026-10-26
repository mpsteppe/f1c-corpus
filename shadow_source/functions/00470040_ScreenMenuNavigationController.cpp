// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00470040
// Canonical corpus name: ScreenMenuNavigationController
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScreenMenuNavigationController_00470040.c

void UnknownObject::ScreenMenuNavigationController()
{
    // Menu navigation dispatch: reads a session flag pointer at this+0xE8 and returns early if null; otherwise picks a UI list index (0, 1, or 2) based on the global dword_7D0410 (compared against 3 and 5) and the pointed-to flag, copies the selected list entry string into a buffer via StringCopyWithBufferRealloc, then dispatches navigation through the vtable slot at offset 0x40 passing the selected index.
    // ASSIGNMENT: Load result from this[58] (byte offset 0xE8), the session flag pointer that also serves as the early-return value. [field:this:0x000000E8, source:raw]
    // GUARD: Guard on this+0xE8 being non-null; when null, return it immediately without navigating. [field:this:0x000000E8, source:raw]
    // GUARD: Select the race-mode branch: global dword_7D0410 equal to 3 or 5 chooses the flag-dependent branch; any other value falls back to index 2. [global:0x007D0410]
    // ASSIGNMENT: Inside the race-mode branch, if the byte pointed to by the session flag is non-zero set this[56] (byte offset 0xE0) to 0, otherwise set it to 1. [field:this:0x000000E0, field:this:0x000000E8]
    // CALL: Call UIListIndexedAccessor(this, 1) when the flag byte is non-zero, or UIListIndexedAccessor(this, 0) when zero, to obtain the selected list element string. [callee:0x00487010]
    // ASSIGNMENT: In the fallback branch (dword_7D0410 not 3 or 5), set this[56] (byte offset 0xE0) to 2 and obtain the list element via UIListIndexedAccessor(this, 2). [field:this:0x000000E0, callee:0x00487010]
    // CALL: Copy the selected list element string into the buffer at this + 59 dwords (byte offset 0xEC) with StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // CALL: Dispatch navigation through the vtable: read the vtable pointer at this+0x00 and call its slot at byte offset 0x40 with arguments (this, this[56]), passing the selected index. [field:this:0x00000000, field:obj:0x00000040]
    // RETURN: Return the original session flag pointer when the null guard fails; otherwise return the navigation dispatch result. [source:raw]

    // Conservative worker pseudocode:
    //   void* ScreenMenuNavigationController(void* this) {
    //     void* result = ((void**)this)[58];
    //     if (!result) return result;
    //     char* v3;
    //     if (dword_7D0410 == 3 || dword_7D0410 == 5) {
    //       if (*(char*)result) { ((int*)this)[56] = 0; v3 = UIListIndexedAccessor(this, 1); }
    //       else               { ((int*)this)[56] = 1; v3 = UIListIndexedAccessor(this, 0); }
    //     } else {
    //       ((int*)this)[56] = 2;
    //       v3 = UIListIndexedAccessor(this, 2);
    //     }
    //     StringCopyWithBufferRealloc((char*)this + 0xEC, v3);
    //     return (*(void* (__thiscall **)(void*, int))(*(void**)this + 0x40))(this, ((int*)this)[56]);
    //   }
    // UNRESOLVED: Meaning of the dword_7D0410 values 3 and 5 is asserted by an existing analysis as a race/championship mode, but the field is not resolved independently here.
    // UNRESOLVED: The pointed-to session flag byte at this+0xE8 selects index 0 vs 1; its exact semantic is unknown.
    // UNRESOLVED: The vtable slot at offset 0x40 is assumed to be the navigation dispatch because it receives the selected index, which is inferred not proven.
}
