// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A2220
// Canonical corpus name: sub_4A2220
// Owner: PitCrewAnimationStruct [DERIVED]
// Raw source: functions/sub_4A2220_004a2220.c

void PitCrewAnimationStruct::PitCrewAnimStructInitAndCleanup()
{
    // Initializes a pit crew animation structure to defaults and releases any previously allocated resources: a 3D sound source, a raw buffer, and an array of 28-byte animation elements. Serves as an init/reinit cleanup hybrid invoked from the loader and UI/resource cleanup paths.
    // ASSIGNMENT: Initialize the word state field at this+0x0 to 0 and the byte flags at this+0x2 (1 = enabled), this+0x3 (0), this+0x4 (0). [field:this:0x00000000, field:this:0x00000002, field:this:0x00000003, field:this:0x00000004]
    // ASSIGNMENT: Initialize the dword region this+0x44..0x60: position/vector component to -1.0f (literal -1082130432), handle/index field to -1, and the remaining four dwords to 0. [field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060]
    // GUARD: If global dword_8AFE88 is set and this+0x64 holds a live 3D sound source, destroy it via F_3DSoundSourceDestructor. [global:0x008AFE88, field:this:0x00000064, callee:0x00545150]
    // ASSIGNMENT: Clear the sound-source pointer this+0x64 and the adjacent this+0x68 after sound cleanup. [field:this:0x00000064, field:this:0x00000068]
    // GUARD: If this+0x6C holds an allocated buffer, release it via FreeWrapper_7bcf. [field:this:0x0000006C, callee:0x00587BCF]
    // ASSIGNMENT: Clear the buffer pointer this+0x6C and the adjacent this+0x70 after buffer cleanup. [field:this:0x0000006C, field:this:0x00000070]
    // GUARD: Save the array pointer at this+0x74; if nonzero, destruct its elements and free the allocation. [field:this:0x00000074]
    // LOOP: Element count is stored in the dword at the allocation base minus 4; iterate count elements of 28 bytes each in reverse, calling ShortComputation_d4d0 on every element. [callee:0x004DD4D0, field:this:0x00000074]
    // CALL: Free the array allocation (header at base minus 4) via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000074]
    // ASSIGNMENT: Clear this+0x74 to 0 after the array is freed. [field:this:0x00000074]
    // RETURN: Return the previously saved this+0x74 value (the freed array allocation address). [function:0x004A2220]

    // Conservative worker pseudocode:
    //   state = 0; enabled = 1; flags = 0;
    //   sound_pos = -1.0f; sound_handle = -1; counters = 0;
    //   if (dword_8AFE88 && sound_source) F_3DSoundSourceDestructor(sound_source);
    //   if (buffer) FreeWrapper_7bcf(buffer);
    //   if (array) { for (each of count elements) ShortComputation_d4d0(elem); FreeWrapper_7bcf(array_header); }
    //   return previous_array;
    // UNRESOLVED: Purpose of the 3D sound source and of the freed buffer inside the pit crew animation struct is not established from this packet alone.
    // UNRESOLVED: Role of global dword_8AFE88 as a subsystem-liveness guard is inferred from the guard shape only.
    // UNRESOLVED: The array is treated as owning 28-byte elements, but element layout is not known.
}
