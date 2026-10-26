// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00448140
// Canonical corpus name: sub_448140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_448140_00448140.c

void UnknownObject::HelicopterAudioAndSceneInit()
{
    // One-shot init (called once from Steward_Init 0x004D38F0): stores the top-level handle a2 at this+0x0, then, when the audio device (dword_8AC4C4) exists, builds the 'Ambient\helicopter.wav' path from dword_5EC3E0 (fallback byte_5EA438), creates an audio playback object through the device vtable+92, and programs three DSP float parameters (inverse RPM threshold, interpolation factor, and a copied float) into the audio object. It then walks the scene-graph entity list (LinkedListIndexedAccessor_c230) to link the scene entity at root+316 into this+0xC, copies a float from a nested sub-object into this+0x8, and applies a conditional per-child entity call; finally it looks up the helicopter linked data by the aHeli name (sub_548890) into this+0x10 and walks its scrolling offset.
    // ASSIGNMENT: *((_DWORD *)this + 0) = a2: store the top-level handle parameter into the object's first dword. [field:this:0x00000000, source:raw]
    // GUARD: If the global audio device pointer dword_8AC4C4 is non-null, initialize the audio playback subsystem; otherwise skip straight to the scene-graph section. [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Initialize the buffer descriptor v16[0] = 0 and v16[1] = -1 (end marker) used to create the playback object. [source:raw]
    // CALL: StringCopyWithBufferRealloc(&byte_5EA438): load the default resource path as the fallback audio directory. [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: StringFormatProcessingWithNullTerm(v21, 256, "%sAmbient\\helicopter.wav", v4) where v4 = dword_5EC3E0 or byte_5EA438 when dword_5EC3E0 is null: compose the helicopter wav path (format literal aSambientHelico), then StringCopyWithBufferRealloc(v21) stores it. [callee:0x0058969D, callee:0x00566650, global:0x005C43B8, global:0x005EC3E0, global:0x005EA438, source:raw]
    // CALL: Invoke the audio device's virtual method at vtable+92 (*(v5 + 92))(v3, v16, 1, 0) to create a playback object; store the result into *((_DWORD *)this + 1). [field:this:0x00000004, source:raw]
    // GUARD: If the created playback object (this+0x4) is non-null, start it via its virtual method at vtable+20 and program the DSP parameters. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Compute v9 = 1.0 / flt_7CF59C when flt_7CF59C > 0.0, else 1.0, using v20 = *(float *)&dword_7CF5E4, and write the three DSP floats: v8[7] = v9 (offset 0x1C), v8[8] = 1.0 - v9 * v20 (offset 0x20), v8[9] = flt_7CF5C0 (offset 0x24) on the audio object at this+0x4. [field:*(this+0x4):0x0000001C, field:*(this+0x4):0x00000020, field:*(this+0x4):0x00000024, global:0x007CF59C, global:0x007CF5C0, global:0x007CF5E4, source:raw]
    // CALL: FreeWrapper_7bcf(v16[0]): release the buffer descriptor base when it was allocated. [callee:0x00587BCF, source:raw]
    // CALL: v10 = LinkedListIndexedAccessor_c230(0): fetch the root scene-graph entity from the linked list. [callee:0x0054C230, source:raw]
    // GUARD: If the root scene-graph entity v10 is non-null, link the scene entity and walk its children. [source:raw]
    // ASSIGNMENT: v11 = *(v10 + 316) and store into *((_DWORD *)this + 3) (this+0xC): the scene entity pointer; when v11 is non-null and *(v11 + 28) is non-null, copy the float *(v12 + 8) into this[2] (this+0x8). [field:this:0x0000000C, field:this:0x00000008, source:raw]
    // CALL: v13 = SceneGraphChildCount(*(_DWORD *)this): count the children of the top-level handle, then loop i in [0, v13), calling LinkedListIndexedAccessor_c230(i) and ConditionalEntityCallOnNonNull(this+0xC) for each. [callee:0x0054C210, callee:0x0054C230, callee:0x00551800, field:this:0x00000000, source:raw]
    // CALL: ValueGetter(dword_8AFE88): resolve a global resource/vertex-buffer value used by the scene. [callee:0x00545F40, global:0x008AFE88, source:raw]
    // CALL: result = sub_548890(aHeli): look up the helicopter linked data object by the aHeli name and store it at *((_DWORD *)this + 4) (this+0x10). [callee:0x00548890, global:0x005C43B0, field:this:0x00000010, source:raw]
    // RETURN: If the helicopter linked data (this+0x10) is non-null, return ScrollingDataOffsetAcrossLinkedEntries(result, 0) to walk its scrolling offset; otherwise return result. [callee:0x00550620, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   int HelicopterAudioAndSceneInit(void** this, int a2) {
    //     this[0] = a2;
    //     if (dword_8AC4C4) {
    //       setAudioDir(dword_5EC3E0 ? dword_5EC3E0 : byte_5EA438);
    //       char path[256]; StringFormatProcessingWithNullTerm(path, 256, "%sAmbient\\helicopter.wav", dir);
    //       this[1] = audioDevice->vtable[92](audioDevice, &desc, 1, 0);
    //       if (this[1]) {
    //         audio->vtable[20](audio);
    //         float inv = flt_7CF59C > 0.0f ? 1.0f / flt_7CF59C : 1.0f;
    //         audio[7] = inv;
    //         audio[8] = 1.0f - inv * *(float*)&dword_7CF5E4;
    //         audio[9] = flt_7CF5C0;
    //       }
    //       if (desc.base) FreeWrapper_7bcf(desc.base);
    //     }
    //     if (root = LinkedListIndexedAccessor_c230(0)) {
    //       this[3] = *(root + 316);
    //       if (this[3] && *(this[3] + 28)) this[2] = *(float*)(*(this[3] + 28) + 8);
    //       for (int i = 0; i < SceneGraphChildCount(this[0]); ++i) {
    //         LinkedListIndexedAccessor_c230(i);
    //         ConditionalEntityCallOnNonNull(this[3]);
    //       }
    //     }
    //     ValueGetter(dword_8AFE88);
    //     int h = sub_548890(aHeli);
    //     this[4] = h;
    //     return h ? ScrollingDataOffsetAcrossLinkedEntries(h, 0) : h;
    //   }
    // UNRESOLVED: Two packet globals, flt_59E43C and flt_59E440, are not referenced by name in the raw source; their role in this function is unknown (likely physics/audio constants used elsewhere in the compiled unit).
    // UNRESOLVED: The semantics of the three DSP parameters (offsets 0x1C/0x20/0x24 on the audio object) as engine-RPM-based tuning come from the existing analysis prose and are not deterministically provable from this packet.
    // UNRESOLVED: The scene entity selection (root+316, sub-object +28 -> +8 float) is structural; the meaning of the copied float is not established.
    // UNRESOLVED: The object owning this init state is not established by the packet; owner stays UNKNOWN.
}
