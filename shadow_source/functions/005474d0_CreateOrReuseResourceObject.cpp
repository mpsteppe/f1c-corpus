// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005474D0
// Canonical corpus name: ResourceObjectCreationWithConfig
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceObjectCreationWithConfig_005474d0.c

void UnknownObject::CreateOrReuseResourceObject()
{
    // Resource-manager entry point that either reuses an existing resource or allocates and configures a new one. Looks up the resource by name via sub_548890; when it already exists and the a4 flag bit 0x100 is clear, bumps its reference count at +136 and returns 0. Otherwise allocates a 196-byte object, initializes it, copies the name, allocates an array of 148-byte sub-resource elements, runs conditional per-element validators (sub_546F30 / ConditionalCheckCall / sub_546F70), stores config a4 and a3, links the node via sub_547670 and returns 0.
    // GUARD: Look up an existing resource by name via sub_548890; when found and the a4 flag bit 0x100 is clear, increment its reference count at offset 136 and return 0 without allocating. [callee:0x00548890, source:raw]
    // CALL: Allocate a 196-byte object via OperatorNewNhMallocWrapper and initialize it through ConstructorInputControlInit. [callee:0x00587C03, callee:0x00546250, source:raw]
    // ASSIGNMENT: Copy the identifier string a2 into the new object via SelfCopyStringToBuffer. [callee:0x00546330, source:raw]
    // CALCULATION: Build the sub-resource element count: read dword slot 41 (offset 164), increment it by one for the primary element and by one more when the suffix string a6 is present and non-empty. [source:raw]
    // CALL: Allocate an array of (148 * count) bytes plus a 4-byte count header via OperatorNewNhMallocWrapper; store the count at the header, initialize each 148-byte element with StructInitWithDefaults_fb90 in a loop, and store the element-array pointer into dword slot 42 (offset 168). [callee:0x00587C03, callee:0x0054FB90, source:raw]
    // GUARD: When the primary string a5 is non-empty, normalize it into the first sub-resource element via SelfRelativeCopyNormalize and run the primary validator sub_546F30; a nonzero result fails the function with -1. [callee:0x0054FC10, callee:0x00546F30, source:raw]
    // GUARD: When a5 is empty, run the fallback validator ConditionalCheckCall instead; a nonzero result fails the function with -1. [callee:0x00547100, source:raw]
    // GUARD: When the suffix string a6 is present and non-empty, normalize it into the second sub-resource element (first element + 148) via SelfRelativeCopyNormalize and run the suffix validator sub_546F70; a nonzero result fails the function with -1. [callee:0x0054FC10, callee:0x00546F70, source:raw]
    // ASSIGNMENT: Store the config value a4 into the first sub-resource element at offset 64, then store a3 into dword slot 39 (offset 156). [source:raw]
    // CALL: Link the new resource node into the owning object via sub_547670, then OR the value 3 into the flags dword slot 39 (offset 156). [callee:0x00547670, source:raw]
    // RETURN: Return 0 on success, -1 when a validator reports failure, or 0 via the reuse path when an existing resource was found. [source:raw]

    // Conservative worker pseudocode:
    //   int CreateOrReuseResource(const char* name, int config, int a3, const char* primary, const char* suffix, int a7) {
    //     Resource* existing = FindResource(name); // sub_548890
    //     if (existing && !(config & 0x100)) { existing->refCount++; return 0; }
    //     Obj* obj = ConstructorInputControlInit(OperatorNewNhMallocWrapper(196));
    //     SelfCopyStringToBuffer(obj, name, this);
    //     int count = obj->slot41 + 1;
    //     obj->slot41 = count;
    //     if (suffix && *suffix) { obj->slot41 = ++count; }
    //     DWORD* array = OperatorNewNhMallocWrapper(148 * count + 4);
    //     if (array) {
    //       array[0] = count;
    //       for (DWORD* e = array + 1; e < array + 1 + 37 * count; e += 37) StructInitWithDefaults_fb90(e);
    //       obj->slot42 = (DWORD*)(array + 1);
    //       if (primary && *primary) { SelfRelativeCopyNormalize(obj->slot42, primary); if (sub_546F30(obj, 0)) return -1; }
    //       else if (ConditionalCheckCall(obj, 0)) return -1;
    //       if (suffix && *suffix) { SelfRelativeCopyNormalize((LPCSTR)obj->slot42 + 148, suffix); if (sub_546F70(obj, 1)) return -1; }
    //       *(DWORD*)((BYTE*)obj->slot42 + 64) = config;
    //       obj->slot39 = a3;
    //       sub_547670(obj);
    //       obj->slot39 |= 3;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the validator helpers sub_546F30, ConditionalCheckCall and sub_546F70.
    // UNRESOLVED: Semantics of sub_547670 beyond linking the resource node into the owning object.
    // UNRESOLVED: Concrete resource type and the meaning of the flags value 3 stored in slot 39.
    // UNRESOLVED: Meaning of a7, which is captured into the descriptor but not otherwise consumed.
}
