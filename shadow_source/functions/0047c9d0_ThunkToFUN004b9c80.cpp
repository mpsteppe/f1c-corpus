// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C9D0
// Canonical corpus name: ThunkToFUN004b9c80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN004b9c80_0047c9d0.c

void UnknownObject::ThunkToFUN004b9c80()
{
    // Trivial thunk: forwards the address of the global dword_8AB6EC to RangeWidthGetter (0x004B9C80) as its single argument and returns nothing. Invoked by CollisionSystemInit (0x0047C960) during collision-system initialization.
    // CALL: Call RangeWidthGetter with the address of the global dword_8AB6EC as its single argument. [callee:0x004B9C80, global:0x008AB6EC, source:raw]
    // CALL: Thunk invoked by CollisionSystemInit during collision-system setup. [caller:0x0047C960, source:raw]

    // Conservative worker pseudocode:
    //   void sub_47C9D0() {
    //     RangeWidthGetter(&dword_8AB6EC);
    //   }
    // UNRESOLVED: Purpose of the single global argument dword_8AB6EC and what RangeWidthGetter reads or writes through it is outside this function's evidence.
    // UNRESOLVED: A thunk with a single indirect call; the identity of the object owning this indirection is unknown.
}
