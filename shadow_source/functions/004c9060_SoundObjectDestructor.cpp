// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9060
// Canonical corpus name: sub_4C9060
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C9060_004c9060.c

void UnknownObject::SoundObjectDestructor()
{
    // Sound object destructor (thiscall): installs the destructor-stage vtable off_5ACE3C, runs the three-stage vtable release TripleVTableDestructorRelease, restores the base vtable off_5ACE2C, and frees the object via FreeWrapper_7bcf only when a2 bit 0 is set. Returns this.
    // ASSIGNMENT: Install the destructor-stage vtable: *this = off_5ACE3C. [field:this:0x00000000, global:0x005ACE3C, source:raw]
    // CALL: Run the three-stage vtable destructor release chain TripleVTableDestructorRelease(this). [callee:0x004C91D0, source:raw]
    // ASSIGNMENT: Restore the base vtable: *this = off_5ACE2C after the release chain. [field:this:0x00000000, global:0x005ACE2C, source:raw]
    // GUARD: Guard on a2 bit 0 (a2 & 1); when set, the object itself is freed. [source:raw]
    // CALL: Free the object via FreeWrapper_7bcf when a2 bit 0 is set (final release). [callee:0x00587BCF, source:raw]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *SoundObjectDestructor(_DWORD *this, char a2) {
    //     *this = &off_5ACE3C;
    //     TripleVTableDestructorRelease(this);
    //     *this = &off_5ACE2C;
    //     if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Owner class of the sound object and the roles of off_5ACE3C/off_5ACE2C are not established here.
    // UNRESOLVED: TripleVTableDestructorRelease internals and the meaning of the two-vtable handoff are unknown.
}
