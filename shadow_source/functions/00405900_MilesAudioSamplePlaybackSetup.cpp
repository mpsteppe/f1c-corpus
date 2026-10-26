// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405900
// Canonical corpus name: MilesAudioSamplePlaybackSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MilesAudioSamplePlaybackSetup_00405900.c

void UnknownObject::MilesAudioSamplePlaybackSetup()
{
    // Sets up Miles audio sample playback. First runs the collision/spatial response computation and aborts with return 1 when it triggers. On the first call (sample handle slot this+0x58 null) allocates a playback handle through the spatial query with weighted distance selection, stores a back-reference to this, and, when both the sample pointer and the file reference at this+0x5C are valid, sets the sample file, configures the loop count from the mode flag at this+0x14 (0 = infinite when the flag is 1, else 1 = single play), and hands this to the sample processor setup. Afterwards writes the position parameters and an active flag into the handle. When the caller requests 3D positioning (a7 non-zero), applies the 3D sound position update and clears the active flag. Returns 0 on success, 1 on early abort.
    // CALL: Runs the collision/spatial response computation first and returns 1 when it triggers, aborting playback setup [callee:0x00405E60, source:raw]
    // GUARD: Initializes the sample playback handle only on the first call, when the handle slot at this+0x58 is null [field:this:0x00000058, source:raw]
    // CALL: Allocates the playback handle via the spatial query with weighted distance selection and stores it into this+0x58 [callee:0x004070E0, field:this:0x00000058, source:raw]
    // GUARD: Returns 1 when handle allocation failed (slot this+0x58 remains null) [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Stores a back-reference to this inside the new handle and reads the loaded sample pointer from handle+0x10 [field:this:0x00000058, source:raw]
    // GUARD: Proceeds with sample configuration only when the loaded sample (handle+0x10) and the file reference at this+0x5C are both non-null [field:this:0x0000005C, source:raw]
    // CALL: Sets the sample file for the loaded sample through the AIL_set_sample_file import, passing the file reference at this+0x5C [global:0x0059E3E0, field:this:0x0000005C, source:raw]
    // GUARD: Selects the loop mode from the flag at this+0x14: value 1 means infinite looping, otherwise single play [guard:0, field:this:0x00000014, source:raw]
    // CALL: Configures the loop count through the AIL_set_sample_loop_count import: 0 for infinite when this+0x14 is 1, else 1 [global:0x0059E3E8, field:this:0x00000014, source:raw]
    // CALL: Passes this to the sample processor setup, supplying the processor-related state fields at this+0x60, this+0x64 (initialized to 0) and this+0x68 [callee:0x004060C0, field:this:0x00000060, field:this:0x00000064, field:this:0x00000068, source:raw]
    // ASSIGNMENT: Writes the position parameters (a2, a4) and the active flag (1) into the handle struct at this+0x58 [field:this:0x00000058, source:raw]
    // STATE_TRANSITION: When the caller requests 3D positioning (a7 non-zero), applies the 3D sound position update and clears the handle's active flag [callee:0x00405B90, field:this:0x00000058, source:raw]
    // RETURN: Returns 0 on success, or 1 when the collision/spatial response triggered or handle allocation failed [function:0x00405900, source:raw]

    // Conservative worker pseudocode:
    //   if (PhysicsCollisionResponseComputation(a5, a6, a3, a4, &a4, v13))
    //       return 1;
    //   if (*(this + 0x58) == 0) {
    //       handle = SpatialQueryWithWeightedDistanceSelection(a2, a4, a7);
    //       *(this + 0x58) = handle;
    //       if (!handle) return 1;
    //       *handle = this;
    //       if (*(handle + 0x10) && *(this + 0x5C)) {
    //           AIL_set_sample_file(*(handle + 0x10), *(this + 0x5C), -1);
    //           AIL_set_sample_loop_count(*(handle + 0x10), (*(this + 0x14) == 1) ? 0 : 1);
    //           MilesSoundSampleProcessorSetup(this);
    //       }
    //   }
    //   handle = *(this + 0x58);
    //   *(handle + 0x4) = a2;
    //   *(float*)(handle + 0x8) = a4;
    //   *(byte*)(handle + 0xC) = 1;
    //   if (a7) {
    //       F_3DSoundPositioningUpdate(this);
    //       *(byte*)(handle + 0xC) = 0;
    //   }
    //   return 0;
    // UNRESOLVED: The owning class of this audio playback object is not identified; the handle slot at this+0x58 is allocated lazily and freed outside this packet
    // UNRESOLVED: The per-handle fields at +0x4, +0x8 and +0xC (position/active flag) and +0x10 (sample pointer) are read and written but their semantic names are not confirmed by this packet
    // UNRESOLVED: The exact roles of the state fields this+0x60, this+0x64 and this+0x68 inside MilesSoundSampleProcessorSetup are defined outside this packet
}
