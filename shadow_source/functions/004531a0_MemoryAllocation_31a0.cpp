// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004531A0
// Canonical corpus name: MemoryAllocation_31a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_31a0_004531a0.c

void UnknownObject::MemoryAllocation_31a0()
{
    // Large object initializer (this) that zeroes several data regions, sets three axis/group count fields to 17 at 0x27C/0x107C/0x1478, builds 44 fixed structs at 0x1B20 via StructInitWithFixedValues, writes 44 {value, -1} sentinel pairs at 0x22B0, resets state/tail fields, sets an activation byte to 1 at 0xD7C, stores a -2 tail sentinel at 0x2424 and a self-reference at 0x1580, returning this.
    // ASSIGNMENT: Initialize state flag at this+0x8 to 0 [field:this:0x00000008]
    // ASSIGNMENT: Set group A count field at this+0x27C to 17 [field:this:0x0000027C]
    // CALCULATION: Zero 0xCB8 bytes starting at this+0x4 [source:raw]
    // CALCULATION: Zero 0xC0 bytes starting at this+0xCBC [source:raw]
    // ASSIGNMENT: Set group A state at this+0xE08 to 0 [field:this:0x00000E08]
    // ASSIGNMENT: Set group B count field at this+0x107C to 17 [field:this:0x0000107C]
    // CALCULATION: Zero 0x3FC bytes starting at this+0xD88 [source:raw]
    // ASSIGNMENT: Set group B state at this+0x1204 to 0 [field:this:0x00001204]
    // ASSIGNMENT: Set group C count field at this+0x1478 to 17 [field:this:0x00001478]
    // CALCULATION: Zero 0x3FC bytes starting at this+0x1184 [source:raw]
    // CALCULATION: Zero 0x590 bytes starting at this+0x1580 [source:raw]
    // LOOP: Loop 44 times calling StructInitWithFixedValues on successive 11-dword fixed structs starting at this+0x1B20 [callee:0x00452780, source:raw]
    // LOOP: Loop 44 times writing {value=0, sentinel=-1} dword pairs starting at this+0x22B0 [field:this:0x000022B0, field:this:0x000022B4, source:raw]
    // ASSIGNMENT: Set this+0xD80 (deactivation counter/state) to 0 [field:this:0x00000D80]
    // ASSIGNMENT: Zero five tail struct dwords at this+0x2410 through this+0x2420 [field:this:0x00002410, field:this:0x00002414, field:this:0x00002418, field:this:0x0000241C, field:this:0x00002420]
    // ASSIGNMENT: Set end-marker byte at this+0x2428 to 0 [field:this:0x00002428]
    // ASSIGNMENT: Set activation flag byte at this+0xD7C to 1 [field:this:0x00000D7C]
    // ASSIGNMENT: Set tail sentinel dword at this+0x2424 to -2 [field:this:0x00002424]
    // ASSIGNMENT: Store self-reference: this+0x1580 = this [field:this:0x00001580]
    // RETURN: Return this pointer [source:raw]

    // Conservative worker pseudocode:
    //   struct LargeObject* init_large_object(struct LargeObject* this) {
    //       this->state = 0;
    //       this->countA = 17;
    //       memset(this + 0x4, 0, 0xCB8);
    //       memset(this + 0xCBC, 0, 0xC0);
    //       this->stateA = 0;
    //       this->countB = 17;
    //       memset(this + 0xD88, 0, 0x3FC);
    //       this->stateB = 0;
    //       this->countC = 17;
    //       memset(this + 0x1184, 0, 0x3FC);
    //       memset(this + 0x1580, 0, 0x590);
    //       for (i = 0; i < 44; i++) StructInitWithFixedValues(this + 0x1B20 + i*0x2C);
    //       for (i = 0; i < 44; i++) { pair[i].value = 0; pair[i].sentinel = -1; }
    //       this->deactCounter = 0;
    //       this->tail[0..4] = 0;
    //       this->endMarker = 0;
    //       this->active = 1;
    //       this->tailSentinel = -2;
    //       this->self = this;
    //       return this;
    //   }
    // UNRESOLVED: Exact device-context semantics (force-feedback per existing analysis) are not provable from this packet alone; the 17 axis count and the role of the 44 fixed structs and sentinel pairs are unconfirmed.
    // UNRESOLVED: Region memsets at this+0x4, this+0xCBC, this+0xD88, this+0x1184, this+0x1580 have no per-field evidence refs; described from raw source only.
}
