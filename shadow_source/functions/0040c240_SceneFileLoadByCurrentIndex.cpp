// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C240
// Canonical corpus name: SceneFileLoadByCurrentIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFileLoadByCurrentIndex_0040c240.c

void UnknownObject::SceneFileLoadByCurrentIndex()
{
    // Camera-scene file loader. Lazily allocates and vtable-initializes a 24-byte scene loader object stored at this+0x1C on first call, then resolves the scene path for the current scene index: reads the scene array entry at dword_8AC490 + 396 * dword_8AC48C, extracts the file-name component after the last backslash, strips its extension, appends the "cam" suffix, joins it to the directory portion, and loads the resulting path through the loader object's virtual method (vtable+4). Always returns 0.
    // GUARD: Lazy-init guard: if this[7] (this+0x1C) is null, allocate and initialize the scene loader object. [field:this:0x0000001C, source:raw]
    // CALL: Allocate a 24-byte scene loader object via OperatorNewNhMallocWrapper(24). [callee:0x00587C03, source:raw]
    // CALL: Initialize the allocated object with its vtable via StructInitWithVTable; a null allocation yields a null object. [callee:0x0040AC00, source:raw]
    // ASSIGNMENT: Store the initialized object pointer into this+0x1C so the allocation happens only once. [field:this:0x0000001C, source:raw]
    // CALCULATION: Resolve the current scene entry: v4 = dword_8AC490 + 396 * dword_8AC48C (scene array base plus index times stride). [global:0x008AC48C, global:0x008AC490, source:raw]
    // GUARD: If the resolved scene entry v4 is null, skip all path construction and loading. [source:raw]
    // CALCULATION: Copy the entry's file-name string (entry+4) into the v17 buffer, then trim v17 back to the directory portion by searching backward for the last '\\' (92). [source:raw]
    // CALCULATION: Trim the remaining name at the last '.' (46): walk the entry file name forward from its directory prefix and cut off the extension in v16. [source:raw]
    // CALCULATION: Build the scene path: strcat(v16, aCam) appends the "cam" suffix to the extension-less base name, then strcat(v17, v16) joins it onto the directory buffer. [global:0x005BE880, source:raw]
    // CALL: Load the constructed scene file path via virtual dispatch: call vtable+4 of the object at this+0x1C with v17 as the argument. [field:*(this+0x1C):0x00000004, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]
    // CALL: Invoked by CamMan_Init (0x0040C920) during camera manager initialization. [caller:0x0040C920, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C240(this) {
    //     if (!this[7]) this[7] = StructInitWithVTable(OperatorNewNhMallocWrapper(24));
    //     entry = dword_8AC490 + 396 * dword_8AC48C;
    //     if (entry) {
    //       dir = copy_dir_prefix(entry + 4);
    //       name = strip_extension(base_name(entry + 4));
    //       strcat(name, aCam);
    //       path = join(dir, name);
    //       this[7]->vtbl[1](this[7], path);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The type of the scene loader object at this+0x1C and its vtable+4 method identity are not resolvable from this function.
    // UNRESOLVED: The scene array layout (stride 0x18c, file name at entry+4) is derived from the raw pointer arithmetic and not from a named struct.
    // UNRESOLVED: aCam (0x005BE880) is a string constant treated as the "cam" suffix here; its broader role (also labeled a vehicle data string elsewhere) is unresolved.
}
