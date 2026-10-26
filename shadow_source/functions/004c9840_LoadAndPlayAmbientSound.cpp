// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9840
// Canonical corpus name: AmbientSoundPlayback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AmbientSoundPlayback_004c9840.c

void UnknownObject::LoadAndPlayAmbientSound()
{
    // Loads and starts the ambient sound file ("ambient\pithorn.wav" under the base path) through the global sound manager (dword_8AC4C4). Builds the full path with StringFormatWithBufferOverflowCheck from a base directory, then calls the manager's stream-creation vtable entry; if the returned sound is already playing it is stopped and the handle cleared, otherwise volume, pan and fade parameters are written into the sound object's parameter slots. Returns 0. No static callers.
    // GUARD: Load the global sound manager pointer dword_8AC4C4; if null, do nothing and return 0. [global:0x008AC4C4]
    // CALL: Copy the default path byte_5EA438 into the reusable string buffer via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Select the base directory: use dword_5EC3E0 when nonzero, otherwise fall back to byte_5EA438. [global:0x005EC3E0, global:0x005EA438]
    // CALL: Format the ambient sound path with StringFormatWithBufferOverflowCheck using format "%s%s%s" (aSSS_0) with base + aAmbient + aPithornWav, yielding "<base>\ambient\pithorn.wav". [callee:0x0058815F, global:0x005C6784, global:0x005D3448, global:0x005D347C]
    // CALL: Copy the formatted path back through StringCopyWithBufferRealloc. [callee:0x00566650]
    // CALL: Invoke the sound manager's stream-create vtable entry (offset 92) with the path buffer and flags (0, 1); store the returned sound object handle into this+0x1C (this[7]). [global:0x008AC4C4, field:this:0x0000001C]
    // GUARD: When the loaded sound object is non-null, read its vtable at *(this+0x1C) and call the entry at offset 20 to test whether the sound is already playing. [field:*(this+0x1C):0x00000000, field:this:0x0000001C]
    // STATE_TRANSITION: If already playing, call the sound object's vtable entry at offset 0 with argument 1 to stop it, then clear this+0x1C to 0. [field:*(this+0x1C):0x00000000, field:this:0x0000001C]
    // CALCULATION: Otherwise configure the sound object: compute volume scale v9 = 1.0 / flt_7CF530 when flt_7CF530 > 0, else 1.0. [global:0x007CF530]
    // ASSIGNMENT: Write the sound parameter slots through the object pointer this[7]: volume = 1/flt_7CF530 (or 1.0) at this+0x38, pan term = 1.0 - volume*(float)dword_7CF578 at this+0x3C, and fade/level flt_7CF554 at this+0x40. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, global:0x007CF578, global:0x007CF554]
    // CALL: Free the path buffer with FreeWrapper_7bcf when it was allocated. [callee:0x00587BCF]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_8AC4C4) return 0;
    //   StringCopyWithBufferRealloc(byte_5EA438);
    //   base = dword_5EC3E0 ? dword_5EC3E0 : byte_5EA438;
    //   StringFormatWithBufferOverflowCheck(buf, "%s%s%s", base, "ambient", "pithorn.wav");
    //   StringCopyWithBufferRealloc(buf);
    //   this[7] = manager.vtable[92](manager, buf, 0, 1);
    //   if (this[7]) {
    //     if (sound.vtable[20](sound)) {
    //       sound.vtable[0](sound, 1);
    //       this[7] = 0;
    //     } else {
    //       v = flt_7CF530 > 0.0 ? 1.0 / flt_7CF530 : 1.0;
    //       sound[7] = v;
    //       sound[8] = 1.0 - v * *(float*)&dword_7CF578;
    //       sound[9] = flt_7CF554;
    //     }
    //   }
    //   if (buf) FreeWrapper_7bcf(buf);
    //   return 0;
    // UNRESOLVED: Two read-only float globals (flt_59E43C, flt_59E440) are flagged by the packet facts but do not appear in the raw decompiled source; likely inlined constants, their role is not verifiable here.
    // UNRESOLVED: The vtable offsets (20 = is-playing test, 0 = stop/release) and the exact meaning of the three written parameter slots (volume/pan/fade) are inferred from call shape and existing analysis, not from named members.
    // UNRESOLVED: The vtable offset 92 method signature on the manager is assumed thiscall from the call site shape.
}
