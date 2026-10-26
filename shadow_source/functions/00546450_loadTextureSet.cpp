// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546450
// Canonical corpus name: sub_546450
// Owner: TextureResourceLoader [DERIVED]
// Raw source: functions/sub_546450_00546450.c

void TextureResourceLoader::loadTextureSet()
{
    // Iterates a this-owned array of 148-byte element descriptors (base this+0xA8, bound from this+0xA4) and materializes a texture resource set: builds per-frame file paths, allocates zero-filled 96-byte frame blocks (this+0x9C tracks state), creates D3D textures via D3DTextureCreation, registers/reuses nodes in a string-keyed linked list, and optionally maintains a float-keyed node at this+0xB4. Elements whose dword at +96 equals the 0x8000000 sentinel take a single-object path (20-byte struct at element+144, load via sub_551A50). Cleans up global stream handles on the audio flag path. Returns 0 on success, -1 on load failure. Called from LinkedListWalkInterlockedDec (0x005487A0).
    // GUARD: Entry guard: return 0 unless the flags dword at this+0x9C has both bit 0 and bit 1 set. [function:0x00546450, field:this:0x0000009C]
    // ASSIGNMENT: Select iteration range: when a2 == -1, start at index 0 and read end bound from this+0xA4; otherwise start at a2 and end at a2+1. [field:this:0x000000A4, source:raw]
    // GUARD: Return 0 when start index >= end bound (no elements to process). [field:this:0x000000A4]
    // LOOP: Iterate element descriptors: array base read from this+0xA8, element address = base + 148*index. [field:this:0x000000A8, source:raw]
    // GUARD: Per element, read the dword at element+96; when it equals sentinel 0x8000000 take the alternate single-object path. [source:raw]
    // ASSIGNMENT: Alternate path: allocate 20 bytes via OperatorNewNhMallocWrapper(20), initialize the object with StructInitWithDefaultScale, and store it at element+144. [callee:0x00587C03, callee:0x00551A30]
    // CALL: Call sub_551A50(element, 1, 0); a nonzero result breaks the iteration and leads to cleanup plus return -1. [callee:0x00551A50]
    // CALL: After load, search the string-keyed linked list with StringSearchInLinkedList(element); when a node is found store it at element+140 and increment the node refcount. [callee:0x00547920]
    // ASSIGNMENT: When the list node is not found: allocate (96*element+72 count + 4) bytes via OperatorNewNhMallocWrapper, zero-fill each 96-byte block with StructInitWithZeroFill, and store the block pointer at element+140. [callee:0x00587C03, callee:0x0054FE10]
    // CALL: StructFieldSetterAt0x4c records the element+72 count into the freshly allocated block. [callee:0x00550300]
    // CALL: sub_54FEC0 validates/loads the element using the object at element+144 (reads element+144 + 8 and element+144 + 12 as arguments); a nonzero result returns -1. [callee:0x0054FEC0]
    // CALL: Main element path, empty name case: skip directly to the float-key node maintenance step (LABEL_92). [source:raw]
    // CALL: Main element path with a non-empty name: StringSearchInLinkedList(element); when found and element+64 lacks flag 0x100, reuse the node (element+140 = node) and increment its refcount; when the miss path is taken the block allocation and load below occur instead. [callee:0x00547920, callee:0x00547860, callee:0x0054FEC0]
    // ASSIGNMENT: Main path, node miss (or flag 0x100 set): allocate (96*element+72 count + 4) via OperatorNewNhMallocWrapper, zero-fill the 96-byte frame blocks, store at element+140, and record count via StructFieldSetterAt0x4c. [callee:0x00587C03, callee:0x0054FE10, callee:0x00550300]
    // ASSIGNMENT: When the element+72 count exceeds 1, set bit 0x400 in the this+0x9C flags. [field:this:0x0000009C]
    // ASSIGNMENT: Copy the extension/suffix bytes from global dword_5CC79C into the local v59 buffer until a NUL byte is read. [global:0x005CC79C]
    // CALCULATION: Scan the element name (at element+0) for '.'; when found, truncate/copy so the base name separates from the extension. [source:raw]
    // LOOP: Per-frame loop over the element+72 count: build the frame file path with StringFormatWithBufferOverflowCheck, using the format strings backed by globals aSS/aS4sSC/aS2dS (single-frame form vs. multi-frame form with a two-digit frame index). [callee:0x0058815F, global:0x005BE860, global:0x005DBE48, global:0x005DBE54]
    // ASSIGNMENT: When element+96 flags intersect 0x00800000 and 0x4000, clear bit 4 of the frame flags and set bit 2 in element+64. [global:0x00800000]
    // CALL: When element+64 bit 2 is set: stop/cleanup the global stream handle dword_8B8DBC (sub_542E50, then EmptyStub_7470 + FreeWrapper_7bcf, then null it), otherwise do the same for dword_8B8DC0; set frame flags 0x40008 and element+64 bit 1. [callee:0x00542E50, callee:0x00557470, callee:0x00587BCF, global:0x008B8DBC, global:0x008B8DC0]
    // ASSIGNMENT: When global dword_8B8E24 is set and element+64 bits (0xC) are active: write element+68 + 1 into the block dword at index 19, and set frame flags 0x2000/0x4000 according to the element+64 bits; otherwise clear element+64 bits 2-3 and write 1 at block index 19. [global:0x008B8E24]
    // ASSIGNMENT: When element+64 bit 0 is set, mark the block dword at index 16 with flag 1. [source:raw]
    // ASSIGNMENT: When element+96 flags include 0x400000, fold 0x00800000 into the frame flags. [global:0x00800000]
    // CALL: D3DTextureCreation(block, element+128, frame flags) creates the D3D texture; a nonzero result returns -1 (texture load failure). [callee:0x00550080]
    // CALL: When element+96 has 0x00800000 & 0x4000 and LinkedListNodeAppenderWithLazyAllocation(2, this) returns nonzero, return -1. [callee:0x00548D40, global:0x00800000]
    // ASSIGNMENT: When the refcount dword at element+140 + 80 exceeds 1 and element+64 bits 0xC are clear, set bit 8 in element+64. [source:raw]
    // ASSIGNMENT: When element+64 flag 0x100 is set: locate '.' in the formatted path, NUL-terminate at the extension, and rebuild the path via StringFormatWithBufferOverflowCheck using the v61 prefix buffer and v59 suffix buffer. [callee:0x0058815F, source:raw]
    // CALL: After the per-frame blocks: sub_547860 post-processes the block at element+140, then the element refcount is incremented. [callee:0x00547860]
    // ASSIGNMENT: Float-key node maintenance: when this+0x9C bit 0x40 is set, LinkedListFloatSearch on the float at this+0xB0 stores the node at this+0xB4; when the search returns null, append via LinkedListNodeAppend_89a0(this+0xB0 float) and re-search to populate this+0xB4. [field:this:0x0000009C, field:this:0x000000B0, field:this:0x000000B4, callee:0x00548A00, callee:0x005489A0]
    // ASSIGNMENT: End of iteration: clear bit 2 in this+0x9C and advance the index; when the index passes the end bound, return 0. [field:this:0x0000009C]
    // CALL: Failure path after a broken loop: free the object at element+144 via EmptyStub_7470 + FreeWrapper_7bcf and return -1. [callee:0x00557470, callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   // Load/refresh a set of texture resources described by the this+0xA8 array.
    //   // this+0x9C bits 0+1 must be set; iterate index [start, end) bounded by this+0xA4.
    //   // Per element: if element+96 == 0x8000000, take the single-object path (20-byte
    //   //   struct at element+144, load via sub_551A50).
    //   // Otherwise maintain a frame-block array at element+140 (96-byte blocks, count at
    //   //   element+72) and create each D3D texture via D3DTextureCreation.
    //   // this+0x9C bit 0x40 triggers float-keyed linked-list node maintenance at this+0xB4.
    //   // Returns 0 on success, -1 on load failure.
    // UNRESOLVED: Mapping of the rodata format-string globals 0x005BE860 / 0x005DBE48 / 0x005DBE54 to the inline format literals in the decompiled text is inferred, not evidenced.
    // UNRESOLVED: Role of the read-only global dword_8B8F28 (0x008B8F28) is not visible in the decompiled text.
    // UNRESOLVED: this+64 is passed as a char* source to StringFormatWithBufferOverflowCheck; its field semantics are unclear.
    // UNRESOLVED: Element descriptor layout beyond the observed offsets +0, +64, +68, +72, +96, +128, +140, +144 is unverified.
    // UNRESOLVED: Caller contract from LinkedListWalkInterlockedDec (0x005487A0) is not resolved here.
    // UNRESOLVED: Semantics of the 0x8000000 sentinel and the element+64 / element+96 flag bits are observed literals only, not confirmed.
    // UNRESOLVED: Semantics of global stream handles dword_8B8DBC / dword_8B8DC0 and the exact lifecycle of the this+0xB4 node are unconfirmed.
}
