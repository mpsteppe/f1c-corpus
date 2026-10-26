// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D5C0
// Canonical corpus name: sub_55D5C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55D5C0_0055d5c0.c

void UnknownObject::SceneRelativeDirectionVectorCompute()
{
    // Computes and stores a normalized direction vector on the scene-node object. Sets a dirty flag 0x40000 at this+0x14, walks a context node list rooted at dword_8B8F28 to find a target entry, obtains a scene position (either the object's stored position at this+0xE8..0xF0 or the result of SceneNodePositionGetter), combines it with the caller-supplied offset a2[9..11], and stores a twice-normalized delta direction at this+0x100/0x104/0x108.
    // GUARD: Guard on a2 being non-null; the whole body runs only when a2 is valid. [source:raw]
    // ASSIGNMENT: Set the 0x40000 dirty flag on the bitfield at this+0x14. [field:this:0x00000014]
    // LOOP: Iterate the context node list: read the list from dword_8B8F28 + 288 with count at + 284, walk entries linked through +108 while each entry's sign byte is >= 0, and return early when the walk exceeds the count. [global:0x008B8F28, source:raw]
    // GUARD: Load the scene node pointer from this+0x138 and branch on the bit 0x10 flag at that node's byte +0x3C to choose the position source. [field:this:0x00000138, field:*(this+0x138):0x0000003C]
    // CALL: When the node flag is clear, call SceneNodePositionGetter on the scene node to fill the local position triple; otherwise the object's stored position at this+0xE8/0xEC/0xF0 is used directly. [callee:0x0054B950, field:this:0x000000E8, field:this:0x000000EC, field:this:0x000000F0]
    // CALCULATION: Form the offset direction vector by adding the caller offset a2[9..11] to the selected position components. [source:raw]
    // CALCULATION: Compute the vector magnitude with sqrt and, when non-zero (against the zero threshold constants), negate-normalize by -1/magnitude. [global:0x0059E43C, global:0x0059E440, source:raw]
    // ASSIGNMENT: Store the normalized direction delta at this+0x100/0x104/0x108, subtracting the target entry's components (node +0x44/0x48/0x4C positions). [field:this:0x00000100, field:this:0x00000104, field:this:0x00000108, source:raw]
    // CALCULATION: Second normalization pass: recompute the magnitude of the stored delta and, when non-zero, rescale each component by 1/magnitude using the sentinel/zero threshold constant. [global:0x0059E440, global:0x0059E670, field:this:0x00000100, field:this:0x00000104, field:this:0x00000108]
    // RETURN: Early return when the node-list walk passes the count without finding a target. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_55D5C0(SceneNodeObject* this, float a2[12], int a3) {
    //     if (!a2) return;
    //     this->flags |= 0x40000;
    //     int count = *(int*)(dword_8B8F28 + 284);
    //     int* node = *(int**)(dword_8B8F28 + 288);
    //     int i = 0;
    //     if (count > 0) {
    //       while (*(char*)node >= 0) { node = *(int**)(node + 108); if (++i >= count) return; }
    //       float px, py, pz;
    //       if ((*(byte*)(this->sceneNode + 60) & 0x10) != 0) { px = this->posX; py = this->posY; pz = this->posZ; }
    //       else SceneNodePositionGetter(this->sceneNode, &px, &py, &pz);
    //       float dx = a2[9] + px; float dy = a2[10] + py; float dz = a2[11] + pz;
    //       float m = sqrt(dx*dx + dy*dy + dz*dz);
    //       if (m != 0.0f) { float k = -1.0f / m; dx *= k; dy *= k; dz *= k; }
    //       this->dirX = dx - *(float*)(node + 68);
    //       this->dirY = dy - *(float*)(node + 72);
    //       this->dirZ = dz - *(float*)(node + 76);
    //       m = sqrt(this->dirX*this->dirX + this->dirY*this->dirY + this->dirZ*this->dirZ);
    //       if (m != 0.0f) { float k = 1.0f / m; this->dirX *= k; this->dirY *= k; this->dirZ *= k; }
    //     }
    //   }
    // UNRESOLVED: Semantic identity of the node-list walk (which list dword_8B8F28 names and what a found node represents) depends on context the function itself does not reveal.
    // UNRESOLVED: Meaning of caller argument a3 is unused within the shown body and unknown.
    // UNRESOLVED: The exact zero-threshold role of flt_59E43C, flt_59E440 and flt_59E670 is inferred from the constant pool, not from explicit packet literals.
}
