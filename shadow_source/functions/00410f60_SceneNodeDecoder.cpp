// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410F60
// Canonical corpus name: SceneNodeDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNodeDecoder_00410f60.c

void UnknownObject::SceneNodeDecoder()
{
    // Scene-node transform decoder in the render subsystem. Reads a 6-bit node-group type from (*(DWORD*)a2 >> 18) & 0x3F and a 16-bit node index at a2+8, dispatches via the jump table at 0x00411100 to one of six node groups (each group: a count field and a base pointer on 'this'), bounds-checks the index, and resolves a target pointer as base + stride*idx + 208 (stride 792 for groups 1/2/3/5/6, stride 808 for group 4). When the resolved pointer is non-NULL it decodes a packed 24-byte transform into six floats (three rotation int16s at a2+19/21/23 scaled by flt_59E77C = 0.00048828125, three packed position values across a2+10..18 scaled by flt_59E780 = 0.000030517578) and forwards them to sub_54B4D0. Returns the unmodified node index on guard/default failure.
    // CALCULATION: Decode the 6-bit node-group type from (*(DWORD*)a2 >> 18) & 0x3F and the 16-bit node index at a2+8; dispatch to the matching case via the jump table jpt_410F7B (0x00411100). [global:0x00411100, function:0x00410F60, source:raw]
    // GUARD: Each case guards the node index: if the index is negative or >= the group's count the case falls through to default and the node index is returned unchanged. [source:raw]
    // CALCULATION: Case 1 (group A): index bounds-checked against count this[0x24]; target = *(DWORD*)(792*idx + this[0x2C] + 208). [field:this:0x00000024, field:this:0x0000002C, source:raw]
    // CALCULATION: Case 2 (group B): index bounds-checked against count this[0x30]; target = *(DWORD*)(792*idx + this[0x38] + 208). [field:this:0x00000030, field:this:0x00000038, source:raw]
    // CALCULATION: Case 3 (group C): index bounds-checked against count this[0x3C]; target = *(DWORD*)(792*idx + this[0x44] + 208). [field:this:0x0000003C, field:this:0x00000044, source:raw]
    // CALCULATION: Case 4 (group D): index bounds-checked against count this[0x48]; stride differs (808), target = *(DWORD*)(808*idx + this[0x50] + 208). [field:this:0x00000048, field:this:0x00000050, source:raw]
    // CALCULATION: Case 5 (group E): index bounds-checked against count this[0x54]; target = *(DWORD*)(792*idx + this[0x5C] + 208). [field:this:0x00000054, field:this:0x0000005C, source:raw]
    // CALCULATION: Case 6 (group F): index bounds-checked against count this[0x60]; target = *(DWORD*)(792*idx + this[0x68] + 208). [field:this:0x00000060, field:this:0x00000068, source:raw]
    // CALCULATION: When the resolved target pointer is non-NULL, decode the packed transform: rotation int16s at a2+19/21/23 scaled by flt_59E77C (0.00048828125) and packed position bytes across a2+10..18 scaled by flt_59E780 (0.000030517578). [global:0x0059E77C, global:0x0059E780, source:raw]
    // CALL: Call sub_54B4D0 with the six decoded floats (position x/y/z, then rotation components). [callee:0x0054B4D0, source:raw]
    // RETURN: Return the resolved target pointer value, or the result of sub_54B4D0 once it has processed the node, or the unmodified node index when no case applies. Recorded caller is LinkedListIteratorWithStateUpdate (0x004B5760). [caller:0x004B5760, source:raw]

    // Conservative worker pseudocode:
    //   int SceneNodeDecoder(this, input) {
    //       int type = (*(int*)input >> 18) & 0x3F;
    //       int idx = *(short*)(input + 8);
    //       void* target = 0;
    //       switch (type) {
    //           case 1: if (idx >= 0 && idx < this->countA)  target = *(int*)(792*idx + this->baseA  + 208); break;
    //           case 2: if (idx >= 0 && idx < this->countB)  target = *(int*)(792*idx + this->baseB  + 208); break;
    //           case 3: if (idx >= 0 && idx < this->countC)  target = *(int*)(792*idx + this->baseC  + 208); break;
    //           case 4: if (idx >= 0 && idx < this->countD)  target = *(int*)(808*idx + this->baseD  + 208); break;
    //           case 5: if (idx >= 0 && idx < this->countE)  target = *(int*)(792*idx + this->baseE  + 208); break;
    //           case 6: if (idx >= 0 && idx < this->countF)  target = *(int*)(792*idx + this->baseF  + 208); break;
    //           default: return idx;
    //       }
    //       if (target) {
    //           decode rotation/position floats (scales flt_59E77C, flt_59E780);
    //           return sub_54B4D0(posX, posY, posZ, rotX, rotY, rotZ);
    //       }
    //       return result;
    //   }
    // UNRESOLVED: The class owning the six node groups and the semantic role of the stride difference (792 vs 808) between group D and the others are not established.
    // UNRESOLVED: The behavior of sub_54B4D0 on the decoded transform is unknown; only the call and its six float arguments are evidenced.
    // UNRESOLVED: The meaning of the returned pointer/value to the caller LinkedListIteratorWithStateUpdate (0x004B5760) is not established.
    // UNRESOLVED: The mapping of the 6-bit type value to a specific node-group meaning (what each of the six groups stores) is not established.
}
