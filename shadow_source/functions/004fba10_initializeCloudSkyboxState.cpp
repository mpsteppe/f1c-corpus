// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FBA10
// Canonical corpus name: sub_4FBA10
// Owner: CloudSkyboxState [DERIVED]
// Raw source: functions/sub_4FBA10_004fba10.c

void CloudSkyboxState::initializeCloudSkyboxState()
{
    // Initializes the cloud/skybox rendering state object. Resolves the skybox scene node from the "SkyboxI" name, resolves three cloud-layer scene nodes (normal "Clouds", snowy "Cloudsny", rainy "Cloudrny"), scans the audio network graph for node handles whose names match the snowy/rainy markers, allocates and fills the cloud and rain handle arrays, computes layer opacity via sub_548890, generates noise-driven animation speeds scaled by flt_7CF914, and computes the skybox bounding box from the resolved skybox node.
    // CALL: EvaluateSceneNodeProperty(aSkyboxi, 0) resolves the skybox scene node handle and stores it in this+0x0. [callee:0x005453A0, global:0x005D6F28, field:this:0x00000000, source:raw]
    // GUARD: If the skybox handle is non-null: TripleFieldQuery(this+1, this+2, this+3) fills the skybox position vector and UIElementBitfieldStateSetter(0, 0, 0) clears the UI element bitfield state. [callee:0x0054B420, callee:0x0054BDC0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set the sentinel float at this+0x40 to NaN (cloud-layer array terminator). [field:this:0x00000040, source:raw]
    // LOOP: Loop over the three cloud layers (index 0 = aClouds, 1 = aCloudsny, 2 = aCloudrny): EvaluateSceneNodeProperty(layerName, skyboxHandle) resolves the layer scene node handle and stores it at this+0x10 / this+0x20 / this+0x30; if non-null, TripleFieldQuery fills its position vector and UIElementBitfieldStateSetter(0,0,0) clears the UI bitfield state. [global:0x005D6F08, global:0x005D6F1C, global:0x005D6F10, callee:0x005453A0, callee:0x0054B420, callee:0x0054BDC0, field:this:0x00000020, field:this:0x00000030, source:raw]
    // GUARD: If the snowy cloud layer handle at this+0x20 is non-null, seed the cloud handle scratch array with it and set the cloud node count at this+0x48 to 1. [field:this:0x00000020, field:this:0x00000048, source:raw]
    // GUARD: If the rainy cloud layer handle at this+0x30 is non-null, seed the rain handle scratch array with it and set the rain node count at this+0x7C to 1. [field:this:0x00000030, field:this:0x0000007C, source:raw]
    // LOOP: AudioNetworkNodeCount(dword_8AFE88) yields the number of nodes in the audio network; for each node: take its handle via LinkedListNodeFinder(i), read its name with SelfRelativeStringCopy(v33), and if sub_588640(v33, aCloudsny, len-1) matches the snowy marker (and does not match aCloudrny) append it to the rain array and bump the rain count at this+0x7C, otherwise append it to the cloud array and bump the cloud count at this+0x48. [global:0x008AFE88, callee:0x005452F0, callee:0x00545340, callee:0x0054BDA0, callee:0x00588640, global:0x005D6F1C, global:0x005D6F10, field:this:0x00000048, field:this:0x0000007C, source:raw]
    // CALL: OperatorNewNhMallocWrapper(4 * cloudCount) allocates the cloud handle array; its pointer is stored at this+0x4C and the scratch entries are copied in. [callee:0x00587C03, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: OperatorNewNhMallocWrapper(4 * rainCount) allocates the rain handle array; its pointer is stored at this+0x80 and the scratch entries are copied in. [callee:0x00587C03, field:this:0x0000007C, field:this:0x00000080, source:raw]
    // GUARD: ValueGetter(dword_8AFE88) returns the audio network pointer; if non-null, the cloud layer opacity at this+0x70 is set from sub_548890(aCloudsny), otherwise it is set to 0.0. [global:0x008AFE88, callee:0x00545F40, callee:0x00548890, global:0x005D6F1C, field:this:0x00000070, source:raw]
    // CALCULATION: Cloud animation speeds: this+0x74 and this+0x78 are set to (flt_8AAE74[dword_8AAE70++]*0.5 + 0.5) * flt_7CF914, consuming two noise-table entries through the advancing index dword_8AAE70. [global:0x008AAE70, global:0x008AAE74, global:0x007CF914, field:this:0x00000074, field:this:0x00000078, source:raw]
    // GUARD: If the audio network pointer is non-null, the rain layer opacity at this+0xA4 is set from sub_548890(aCloudrny), otherwise it is set to 0.0. [callee:0x00548890, global:0x005D6F10, field:this:0x000000A4, source:raw]
    // CALCULATION: Rain animation speeds: this+0xA8 and this+0xAC are set to (flt_8AAE74[dword_8AAE70++]*0.5 + 0.5) * flt_7CF914, consuming the next two noise-table entries. [global:0x008AAE70, global:0x008AAE74, global:0x007CF914, field:this:0x000000A8, field:this:0x000000AC, source:raw]
    // ASSIGNMENT: Initialize the bounding box: this+0xB0 = 3.4028235e38 (min), this+0xB4 = -3.4028235e38 (max) and the sentinel this+0xB8 = -1.0. [field:this:0x000000B0, field:this:0x000000B4, field:this:0x000000B8, source:raw]
    // CALL: If the skybox node handle at this+0x20 is non-null, BoundingBoxComputation(skyboxHandle, &bboxMin, &bboxMax) computes the box and the results are stored at this+0xB0 and this+0xB4. [callee:0x004DD550, field:this:0x00000020, field:this:0x000000B0, field:this:0x000000B4, source:raw]
    // RETURN: Return the final dword_8AAE70 value (or the BoundingBoxComputation result when the skybox node was present). [global:0x008AAE70, source:raw]

    // Conservative worker pseudocode:
    //   skybox = resolveNode("SkyboxI", 0);
    //   this->skyboxHandle = skybox;
    //   if (skybox) { readPosition(this+4, this+8, this+12); setUIState(0,0,0); }
    //   this->sentinel = NaN;
    //   for (layer = 0; layer < 3; layer++) {
    //     name = layer == 0 ? "Clouds" : layer == 1 ? "Cloudsny" : "Cloudrny";
    //     h = resolveNode(name, skybox);
    //     storeHandle(this + 4*(layer+1), h);
    //     if (h) { readPosition(handlePos); setUIState(0,0,0); }
    //   }
    //   if (this->snowyHandle) { scratch[0] = this->snowyHandle; this->cloudCount = 1; }
    //   if (this->rainyHandle) { rainScratch[0] = this->rainyHandle; this->rainCount = 1; }
    //   n = audioNodeCount(network);
    //   for (i = 0; i < n; i++) {
    //     node = findNode(i);
    //     readName(nameBuf);
    //     if (nameEq(nameBuf, "Cloudsny") && !nameEq(nameBuf, "Cloudrny")) {
    //       rainScratch[this->rainCount++] = node;
    //     } else {
    //       cloudScratch[this->cloudCount++] = node;
    //     }
    //   }
    //   this->cloudArray = malloc(4 * this->cloudCount); copyEntries();
    //   this->rainArray = malloc(4 * this->rainCount); copyEntries();
    //   net = getValue(network);
    //   this->cloudOpacity = net ? getOpacity("Cloudsny") : 0.0;
    //   this->cloudSpeedX = (noise() * 0.5 + 0.5) * speedScale;
    //   this->cloudSpeedY = (noise() * 0.5 + 0.5) * speedScale;
    //   this->rainOpacity = net ? getOpacity("Cloudrny") : 0.0;
    //   this->rainSpeedX = (noise() * 0.5 + 0.5) * speedScale;
    //   this->rainSpeedY = (noise() * 0.5 + 0.5) * speedScale;
    //   this->bboxMin = +FLT_MAX; this->bboxMax = -FLT_MAX; this->bboxSentinel = -1.0;
    //   if (this->skyboxNode) { computeBBox(this->skyboxNode, &this->bboxMin, &this->bboxMax); }
    //   return noiseIndex;
    // UNRESOLVED: flt_59E450 is listed as read by this function but no reference to it appears in the decompiled body; its role is unknown.
    // UNRESOLVED: The cloud-layer handle slot at this+0x10 (loop index 0) is written but absent from the field evidence list; only this+0x20 and this+0x30 have field evidence.
    // UNRESOLVED: The exact node-name matching semantics (sub_588640 with length minus one) and the COERCE_FLOAT(LinkedListNodeFinder(i)) handle interpretation are DERIVED from the branch structure, not proven.
    // UNRESOLVED: The stride-4 float indexing means several written slots (positions, handle at +0x10, animation speeds at +0x74/0x78/0xA8/0xAC as dword-slot reads) are not all backed by explicit field evidence refs.
}
