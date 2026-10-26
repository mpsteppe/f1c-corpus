// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8650
// Canonical corpus name: SoundAudioPlayback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SoundAudioPlayback_004c8650.c

void UnknownObject::SoundAudioPlayback()
{
    // Per-frame audio playback manager. When the active flag at this+0x10 is set and the audio mixer (dword_8AC4C8) is live with positive volume, it either ramps the current stream volume (fade-in state 1 adds a per-frame delta clamped at flt_7CF380; other states fade out clamped at 0.0, resetting the fade state at this+0x14 to 0) or, when the mixer reports not playing, selects a new track: from the scene-indexed table dword_5ACDEC[dword_8AC4C0] when the playlist count at this+0xC is <= 0, otherwise by advancing the playlist cursor at this+0x8 and resetting to the list head at this+0x0 when exhausted. The filename is built with StringCopyWithBufferRealloc and handed to the mixer via its vtable (slot +4), with the scratch buffer released through FreeWrapper_7bcf. A non-positive fade argument a2 is replaced by the default dbl_8AFE90.
    // ASSIGNMENT: When the fade argument a2 is not positive, substitute the default value dbl_8AFE90. [function:0x004C8650, global:0x008AFE90, source:raw]
    // GUARD: Run only when the active flag at this+0x10 is set, the mixer pointer dword_8AC4C8 is non-null, and the mixer volume float at dword_8AC4C8+4 is positive. [field:this:0x00000010, global:0x008AC4C8, source:raw]
    // CALL: Query the mixer through its vtable slot +8 (playing/ready check); the true branch ramps the active stream's volume, the false branch selects and plays a new track. [global:0x008AC4C8, source:raw]
    // GUARD: When the mixer reports it is not playing, build a new track selection from the playlist or the scene index. [source:raw]
    // GUARD: The fade state at this+0x14 (DWORD at this+5) is non-zero, so a volume ramp is in progress; a zero state skips the ramp and returns through the mixer refresh. [field:this:0x00000014, source:raw]
    // CALCULATION: Compute the per-frame volume delta as a2 * (fade speed float at this+0x18). [field:this:0x00000018, global:0x008AC4C8, source:raw]
    // GUARD: Fade-in state (state == 1) adds the delta to the current mixer volume at dword_8AC4C8+4. [source:raw]
    // ASSIGNMENT: Clamp the fade-in volume at flt_7CF380; once the clamp is reached reset the fade state at this+0x14 to 0. [global:0x007CF380, field:this:0x00000014, source:raw]
    // CALCULATION: Fade-out (any state other than 1) subtracts the delta from the current mixer volume. [source:raw]
    // ASSIGNMENT: Clamp the fade-out volume at 0.0; when the volume bottoms out reset the fade state at this+0x14 to 0. [field:this:0x00000014, source:raw]
    // CALL: Write the new volume into the mixer via its vtable slot +28, refresh it through slot +24, and return. [global:0x008AC4C8, source:raw]
    // ASSIGNMENT: Initialize a local LPVOID[2] scratch buffer (used to receive a filename) to {0, -1}. [source:raw]
    // CALL: Fill the scratch buffer from byte_5EA438 as a default path via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EA438, source:raw]
    // GUARD: Playlist count at this+0xC is <= 0, so the playlist is empty and a scene-indexed track is chosen instead. [field:this:0x0000000C, guard:0, source:raw]
    // ASSIGNMENT: Choose a scene track from dword_5ACDEC indexed by dword_8AC4C0 with dword_5D3254 as the scene value, filling the scratch buffer again with StringCopyWithBufferRealloc. [global:0x005ACDEC, global:0x005D3254, global:0x008AC4C0, source:raw]
    // ASSIGNMENT: Advance the scene index dword_8AC4C0 and wrap it to 0 once it reaches 4. [global:0x008AC4C0, source:raw]
    // CALCULATION: Advance the playlist cursor at this+0x8 to its successor node at +4; if the successor is empty or its data is missing, reset the cursor to the list head at this+0x0. [field:this:0x00000008, field:*(this+0x8):0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Resolve the track filename from the cursor node: name = *(char**)(node data pointer at *(*(this+0x8)+0x0)), defaulting to byte_5EA438 when empty, then fill the scratch buffer via StringCopyWithBufferRealloc. [field:*(*(this+0x8)+0x0):0x00000000, field:*(this+0x8):0x00000000, callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: Pass the filename buffer to the mixer play method at vtable slot +4 with flags (1, 0). [global:0x008AC4C8, source:raw]
    // CALL: Release the scratch buffer with FreeWrapper_7bcf when it was allocated. [callee:0x00587BCF, source:raw]
    // CALL: Refresh the mixer through vtable slot +24 after the new track is submitted. [global:0x008AC4C8, source:raw]

    // Conservative worker pseudocode:
    //   void SoundAudioPlayback(void *this, float fadeArg) {
    //     if (fadeArg <= 0.0f) fadeArg = dbl_8AFE90;
    //     if (!this[0x10] || !dword_8AC4C8 || *(float*)(dword_8AC4C8 + 4) <= 0.0f) return;
    //     if (MixerReady(dword_8AC4C8)) {
    //       int state = this[0x14];
    //       if (state) {
    //         float vol = *(float*)(dword_8AC4C8 + 4);
    //         float delta = fadeArg * *(float*)(this + 0x18);
    //         float next;
    //         if (state == 1) {
    //           next = vol + delta;
    //           if (next >= flt_7CF380) { next = flt_7CF380; this[0x14] = 0; }
    //         } else {
    //           next = vol - delta;
    //           if (next <= 0.0f) { next = 0.0f; this[0x14] = 0; }
    //         }
    //         MixerSetVolume(dword_8AC4C8, next);
    //         MixerRefresh(dword_8AC4C8);
    //         return;
    //       }
    //     } else {
    //       LPVOID buf[2] = {0, (LPVOID)-1};
    //       StringCopyWithBufferRealloc(byte_5EA438);
    //       if (this[0x0C] <= 0) {
    //         int scene = dword_5D3254;
    //         int track = dword_5ACDEC[dword_8AC4C0];
    //         StringCopyWithBufferRealloc(byte_5EA438);
    //         buf[0] = track; buf[1] = scene;
    //         dword_8AC4C0 = (dword_8AC4C0 + 1) % 4;
    //       } else {
    //         if (this[0x08]) this[0x08] = *(int*)(this[0x08] + 4);
    //         if (!this[0x08] || !**(int**)this[0x08]) this[0x08] = this[0x00];
    //         char* name = **(char***)this[0x08];
    //         if (!name) name = byte_5EA438;
    //         StringCopyWithBufferRealloc(name);
    //       }
    //       MixerPlay(dword_8AC4C8, buf, 1, 0);
    //       if (buf[0]) FreeWrapper_7bcf(buf[0]);
    //     }
    //     MixerRefresh(dword_8AC4C8);
    //   }
    // UNRESOLVED: The mixer object behind dword_8AC4C8 is accessed only via vtable slots (+4 play, +8 ready, +24 refresh, +28 volume) and a volume float at +4; its concrete class is unknown.
    // UNRESOLVED: flt_59E440 is listed by the packet as a read global but does not appear in the raw pseudocode, so its role in this function is unclear.
    // UNRESOLVED: The exact string semantics of StringCopyWithBufferRealloc into the LPVOID[2] scratch buffer (pointer plus capacity) are not defined.
    // UNRESOLVED: The meaning of the scene-indexed selection dword_5ACDEC[dword_8AC4C0] (table of up to 4 entries) together with dword_5D3254 is inferred from the existing analysis, not proven.
    // UNRESOLVED: The exact set of values for the fade state at this+0x14 beyond 0/1 is unknown; any value other than 1 is treated as fade-out.
}
