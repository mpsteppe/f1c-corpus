// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9820
// Canonical corpus name: WheelForceAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelForceAccessor_004b9820.c

void UnknownObject::WheelForceAccessor()
{
    // Wheel/force-feedback value accessor. Dereferences this to obtain the owning object pointer, then reads and returns the dword at offset 0xF1C (3868) within that object. A trivial read-only accessor with no guards; called by sub_4BA1F0.
    // CALCULATION: Dereferences this to load the object pointer stored at this+0x0. [field:this:0x00000000, source:raw]
    // CALCULATION: Reads the dword force/feedback value at obj+0xF1C (3868) from the dereferenced object. [field:obj:0x00000F1C, source:raw]
    // RETURN: Returns the read value to the caller. [function:0x004B9820, source:raw]

    // Conservative worker pseudocode:
    //   int WheelForceAccessor(void* this) {
    //       int* obj = *this;
    //       return *(int*)((char*)obj + 3868);
    //   }
    // UNRESOLVED: The type of the object reached through this+0x0 and the meaning of the 0xF1C value are not evidenced beyond the single read.
    // UNRESOLVED: There is no null check on the dereferenced object pointer.
}
