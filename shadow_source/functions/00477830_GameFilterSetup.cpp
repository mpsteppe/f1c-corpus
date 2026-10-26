// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477830
// Canonical corpus name: GameFilterSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameFilterSetup_00477830.c

void UnknownObject::GameFilterSetup()
{
    // Builds the 'Game Filter' UI screen: captures UI dimensions, tears down the previous widget linked lists (calling each widget's virtual destructor and freeing nodes, then zeroing the four list heads this+0xF0..0xFC), cleans the resource list at this+0x180, builds the track filter via ConditionalDispatch_81f0/SceneFileFilterBuilder, then iterates the track list producing one UI widget per track (car-icon handle + track name) and finalizes the viewport layout.
    // CALL: UIDimensionCapture() captures the current UI dimensions before layout is rebuilt. [callee:0x0048EBD0, source:raw]
    // LOOP: Walk the widget linked list from head this+0xF0 following the +4 next-pointer: for each node whose +12 flag is set and whose vtable (*v3) is non-null, call the virtual destructor (vtable[0])(node, 1), then FreeWrapper_7bcf(node). [field:*(this+0xF0):0x00000000, field:*(*(this+0xF0)+0x0):0x00000000, field:*(this+0xF4):0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the four UI widget list heads this+0xF0, this+0xF4, this+0xF8, this+0xFC after the cleanup walk. [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, source:raw]
    // CALL: ResourceListCleanup_62c0(this + 0x180) tears down the resource list object that holds the track filter state. [callee:0x004C62C0, source:raw]
    // CALL: ConditionalDispatch_81f0(aGameFilter) resolves the 'Game Filter' string, then SceneFileFilterBuilder(result) rebuilds the scene/track filter from it. [callee:0x005681F0, global:0x005C7130, callee:0x004C6330, source:raw]
    // CALL: ReadFieldAtOffset0x14(this + 0x180) reads the track/scene count used to bound the per-track loop. [callee:0x005871F0, source:raw]
    // LOOP: Per-track loop over the count: LinkedListRandomAccess(index) fetches each track node; the body runs only for non-null nodes. [callee:0x004C6780, source:raw]
    // CALL: OperatorNewNhMallocWrapper(72) allocates a new widget and UIObjectInit(v8) initializes it into v9. [callee:0x00587C03, callee:0x004761C0, source:raw]
    // CALCULATION: Copy the path from node+4 into the 256-byte scratch buffer v27 (seeded first byte from byte_5EA438), then strip everything after the last backslash (0x5C), leaving the bare filename; finally strcat the track name from node+260. [global:0x005EA438, source:raw]
    // CALCULATION: Append the icon name suffix to the buffer end: dword_5C7150, dword_5C7154, then the low word word_5C7158. [global:0x005C7150, global:0x005C7154, global:0x005C7158, source:raw]
    // CALL: sub_497AD0(v27, 0) looks up the car-icon resource by the built name, falling back to sub_497AD0(aDfcariconBmp, 0); on success StructFieldCopy_fc80(handle) copies the handle into the widget. [callee:0x00497AD0, global:0x005C6A04, callee:0x0048FC80, source:raw]
    // CALL: TrackSceneLoader(node+260) loads the track scene data, TrackNameReader(v24, 63) reads the track name into a 63-byte buffer, and StringCopyWithBufferRealloc is applied to both the name buffer and node+260. [callee:0x004C55B0, callee:0x004C5920, callee:0x00566650, source:raw]
    // ASSIGNMENT: Store the track node handle into widget+0x3C (v9[15] = node) and DoublyLinkedListAppend_f5d0(widget, 1) links the widget into the UI list. [callee:0x0048F5D0, source:raw]
    // CALL: Finalize: SceneListSearchByPath(this) then UIViewportLayoutCalculator(this) lay out the assembled widget viewport. [callee:0x00477BA0, callee:0x0048F640, function:0x00477830, source:raw]
    // RETURN: Return 0 after layout completes. [function:0x00477830, source:raw]

    // Conservative worker pseudocode:
    //   int GameFilterSetup(UI *this) {
    //     UIDimensionCapture();
    //     for (n = this->listHeadF0; n; n = *(n+4)) {
    //       if (*(BYTE*)(n+12) && *(vtable*)n) (*(vtable*)n)(n, 1);
    //       FreeWrapper_7bcf(n);
    //     }
    //     this->listHeadF0 = this->listHeadF4 = this->listHeadF8 = this->listHeadFC = 0;
    //     ResourceListCleanup_62c0(this + 0x180);
    //     SceneFileFilterBuilder(ConditionalDispatch_81f0(aGameFilter));
    //     count = ReadFieldAtOffset0x14(this + 0x180);
    //     for (i = 0; i < count; ++i) {
    //       node = LinkedListRandomAccess(i);
    //       if (!node) continue;
    //       widget = UIObjectInit(OperatorNewNhMallocWrapper(72));
    //       if (!widget) continue;
    //       build trackName buffer from node+4 (strip to last '\\') then cat node+260;
    //       append dword_5C7150/dword_5C7154/word_5C7158 icon suffix;
    //       handle = sub_497AD0(buffer, 0) ?: sub_497AD0(aDfcariconBmp, 0);
    //       if (handle) StructFieldCopy_fc80(handle);
    //       TrackSceneLoader(node+260);
    //       TrackNameReader(nameBuf, 63); StringCopyWithBufferRealloc(nameBuf); StringCopyWithBufferRealloc(node+260);
    //       widget[15] = node;
    //       DoublyLinkedListAppend_f5d0(widget, 1);
    //     }
    //     SceneListSearchByPath(this);
    //     UIViewportLayoutCalculator(this);
    //     return 0;
    //   }
    // UNRESOLVED: unk_8AC368 and dword_8AD3B4 are flagged as read-only globals in the packet but appear nowhere in the decompiled body; likely reachable through the SceneFileFilterBuilder/sub_497AD0 helper calls whose internals are out of scope here.
    // UNRESOLVED: The 72-byte widget layout (v9[15] at offset 0x3C, list linkage) is consumed by UI helpers and not fully defined in this function.
}
