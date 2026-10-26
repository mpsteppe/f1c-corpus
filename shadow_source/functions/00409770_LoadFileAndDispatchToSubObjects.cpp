// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00409770
// Canonical corpus name: sub_409770
// Owner: FileResourceProcessor [DERIVED]
// Raw source: functions/sub_409770_00409770.c

void FileResourceProcessor::LoadFileAndDispatchToSubObjects()
{
    // Removes the read-only attribute from the named file, loads its contents into a stack temp struct via one of two loader variants selected by a3, then dispatches the loaded state to up to four fixed sub-object pointers (this+0x10..0x1C) and to each element of a variable-length sub-object array (this+0x20, stride 200 bytes, count this+0x38) through each object's vtable+8 callback. Returns 0 if at least one sub-object received the data, 1 otherwise. The temp struct is closed and freed on all paths.
    // GUARD: If lpFileName is null, skip loading and dispatch entirely and fall through to return 1. [source:raw]
    // CALL: Clear the FILE_ATTRIBUTE_READONLY attribute (128) on lpFileName via the Win32 attribute-toggle helper before reading the file. [callee:0x0058BA36, source:raw]
    // CALL: Zero-initialize the stack temp struct (v12) that will hold the loaded file state. [callee:0x005668B0, source:raw]
    // GUARD: Branch on a3 to select which file-loading variant is used: nonzero picks sub_566940, zero picks sub_566A70. [source:raw]
    // CALL: Load lpFileName into the temp struct using the a3-nonzero loader variant (sub_566940) with arguments (v12, lpFileName, 0, 1, 1). [callee:0x00566940]
    // CALL: Load lpFileName into the temp struct using the a3-zero loader variant (sub_566A70) with arguments (v12, lpFileName, 0, 1, 1). [callee:0x00566A70]
    // GUARD: If the temp struct's first field (v12[0]) is nonzero, the file loaded successfully and dispatch to sub-objects may proceed. [source:raw]
    // CALL: Dispatch the loaded state to fixed sub-object 0 held at this+0x10, invoking its vtable+8 callback with (subObject0, v12, 0). [field:this:0x00000010, field:*(this+0x10):0x00000008, function:0x00409770]
    // CALL: Dispatch the loaded state to fixed sub-object 1 held at this+0x14, invoking its vtable+8 callback with (subObject1, v12, 0). [field:this:0x00000014, field:*(this+0x14):0x00000008, function:0x00409770]
    // CALL: Dispatch the loaded state to fixed sub-object 2 held at this+0x18, invoking its vtable+8 callback with (subObject2, v12, 0). [field:this:0x00000018, field:*(this+0x18):0x00000008, function:0x00409770]
    // CALL: Dispatch the loaded state to fixed sub-object 3 held at this+0x1C, invoking its vtable+8 callback with (subObject3, v12, 0). [field:this:0x0000001C, field:*(this+0x1C):0x00000008, function:0x00409770]
    // ASSIGNMENT: Set dispatch flag v3 to 1 whenever any sub-object (fixed or array element) received the loaded data. [source:raw]
    // LOOP: Iterate the variable-length sub-object array rooted at this+0x20 with element stride 0xC8 (200 bytes) for the count held at this+0x38, dispatching the loaded state to each element's vtable+8 callback with (element, v12, 0). [field:this:0x00000020, field:this:0x00000038, guard:0, function:0x00409770]
    // CALL: Close the file handle via the conditional-close dispatcher after data extraction completes. [callee:0x00566B90, source:raw]
    // CALL: If v3 indicates at least one sub-object received the data, free the temp struct via SubCallWithConditionalFieldFree and return 0 (success). [callee:0x005668D0, source:raw]
    // RETURN: Return 0 to signal that the loaded data was dispatched to at least one sub-object. [function:0x00409770, source:raw]
    // CALL: On the null-filename, failed-load, or no-recipient paths, free the temp struct via SubCallWithConditionalFieldFree before returning 1. [callee:0x005668D0, source:raw]
    // RETURN: Return 1 to signal that no sub-object received data (null filename, failed load, or no recipient). [function:0x00409770, source:raw]

    // Conservative worker pseudocode:
    //   bool LoadFileAndDispatchToSubObjects(this, lpFileName, a3) {
    //     bool dispatched = false;
    //     if (!lpFileName) return true;
    //     ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128);
    //     FileLoadState state = {};
    //     if (a3)
    //       sub_566940(&state, lpFileName, 0, 1, 1);
    //     else
    //       sub_566A70(&state, lpFileName, 0, 1, 1);
    //     if (state.firstField) {
    //       for (ptr in {this+0x10, this+0x14, this+0x18, this+0x1C})
    //         if (ptr) { ptr.vtable[2](&state, 0); dispatched = true; }
    //       for (i = 0; i < this+0x38; i++) {
    //         element = *(this+0x20) + i * 0xC8;
    //         element.vtable[2](&state, 0);
    //         dispatched = true;
    //       }
    //       ConditionalFileHandleCloseWithFlagDispatch(&state);
    //       if (dispatched) { SubCallWithConditionalFieldFree(&state); return false; }
    //     }
    //     SubCallWithConditionalFieldFree(&state);
    //     return true;
    //   }
    // UNRESOLVED: Semantics of the temp struct's first field (v12[0]) used as the load-success indicator are not specified in evidence.
    // UNRESOLVED: What each object's vtable+8 callback does with the loaded state is unknown; it is a generic dispatch target.
    // UNRESOLVED: The meaning of the two loader variants selected by a3 (sub_566940 vs sub_566A70) is unknown; possibly text vs binary or raw vs parsed loading.
    // UNRESOLVED: The relationship between the fixed sub-objects (this+0x10..0x1C) and the array elements (this+0x20, count this+0x38) is unknown.
    // UNRESOLVED: Whether callers interpret the return value as success (0) versus no-op (1) is inferred from control flow, not stated by evidence.
}
