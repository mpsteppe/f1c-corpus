// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC550
// Canonical corpus name: sub_4FC550
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FC550_004fc550.c

void UnknownObject::LoadCommonLogoMapAndSetupCloudTextures()
{
    // Builds the season/track path ending in the common logo-map archive name and loads it: allocates a 256-byte path buffer, seeds it with the season directory (dword_5EC3D8) or the default directory byte_5EA438 via StringCopyWithBufferRealloc, appends the track directory (dword_5EC420 or default), the "common" component and the "logomap.mas" key with sub_5665B0, then loads the resource through sub_53CBC0. When that returns zero, optionally selects a random cloud scene object (CloudSceneObjectRandomSelector), registers the wcclouds/wccloudr cloud texture variants at this+80 and this+132 via sub_4FC400, and removes the loaded resource from the physics linked list (PhysicsObjectLinkedListRemoval). The path buffer is freed via FreeWrapper_7bcf on exit.
    // ASSIGNMENT: Initialize the resource-handle output v7 to 0 and allocate a 256-byte path buffer v8 via OperatorNewNhMallocWrapper, then null-terminate it. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Select the season directory global dword_5EC3D8, falling back to the default directory byte_5EA438 when it is null. [global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: Copy the selected season directory into the path buffer with StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // ASSIGNMENT: Select the track directory global dword_5EC420, falling back to the default directory byte_5EA438 when it is null. [global:0x005EC420, global:0x005EA438, source:raw]
    // CALL: Append the track directory, the "common" component (aCommon) and the "logomap.mas" archive key (aLogomapMas) to the path buffer via sub_5665B0. [callee:0x005665B0, global:0x005D3C34, global:0x005D3C3C, source:raw]
    // CALL: Load/parse the resource from the constructed path via sub_53CBC0(&v7, path), using byte_5EA438 as the fallback path when the buffer allocation failed. [callee:0x0053CBC0, global:0x005EA438, source:raw]
    // GUARD: When sub_53CBC0 returns zero, proceed with the cloud setup body; otherwise skip it. [source:raw]
    // CALL: When flag a2 is nonzero, select a random cloud scene object via CloudSceneObjectRandomSelector(this, v7). [callee:0x004FC2F0, source:raw]
    // CALL: Register cloud texture variants: sub_4FC400(aWcclouds, this+80) and sub_4FC400(aWccloudr, this+132). [callee:0x004FC400, global:0x005D6F5C, global:0x005D6F50, source:raw]
    // CALL: Remove the loaded resource from the physics object linked list via PhysicsObjectLinkedListRemoval(v7). [callee:0x0053CE40, source:raw]
    // RETURN: Free the 256-byte path buffer via FreeWrapper_7bcf when it was allocated, and return the buffer pointer (or null). [callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   v7 = 0;
    //   v8 = OperatorNewNhMallocWrapper(256);
    //   *v8 = 0;
    //   v3 = dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438;
    //   StringCopyWithBufferRealloc(v3);
    //   v4 = dword_5EC420 ? dword_5EC420 : byte_5EA438;
    //   sub_5665B0(v4);
    //   sub_5665B0(aCommon);
    //   sub_5665B0(aLogomapMas);
    //   v5 = v8 ? v8 : byte_5EA438;
    //   if (!sub_53CBC0(&v7, v5)) {
    //     if (a2) CloudSceneObjectRandomSelector(this, v7);
    //     sub_4FC400(aWcclouds, this + 80);
    //     sub_4FC400(aWccloudr, this + 132);
    //     PhysicsObjectLinkedListRemoval(v7);
    //   }
    //   if (v8) return FreeWrapper_7bcf(v8);
    //   return v8;
    // UNRESOLVED: Global 0x008AFE64 (dword_8AFE64) is listed as a read global by packet facts but never appears in the raw decompiled source; it is likely touched by a callee (StringCopyWithBufferRealloc / sub_5665B0) rather than here.
    // UNRESOLVED: Branch polarity of sub_53CBC0 is unresolved: the setup body runs when it returns zero, but whether zero means load-success or load-failure is not documented in this function.
    // UNRESOLVED: Meaning of a2 (whether to randomize cloud scene objects) and the exact content of the cloud texture variants at this+80 / this+132 are caller-contract details unknown here.
}
