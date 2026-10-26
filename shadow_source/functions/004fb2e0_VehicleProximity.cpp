// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FB2E0
// Canonical corpus name: VehicleProximity
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleProximity_004fb2e0.c

void UnknownObject::VehicleProximity()
{
    // Computes closest-approach proximity distances from this vehicle to two target entities by projecting position+direction lines. Target1 is resolved through the this+0x110 pointer, target2 through the this+0x114 pointer; own data comes from the this+0x10C block plus direct fields. Parallel (non-intersecting) directions store a sentinel, self references store 0, otherwise the smaller of the two line distances is stored as a float into this+0xB0 (target1) and this+0xB4 (target2).
    // GUARD: Entry guards: the own data-block pointer this+0x10C must be non-null, the target1 pointer this+0x110 must be non-null, and the target1 object's internal pointer (field +0x110 of the target1 object) must be non-null. [field:this:0x0000010C, field:this:0x00000110, field:*(this+0x110):0x00000110, source:raw]
    // CALCULATION: Load target1 position (X at *(this+0x110)+0x94, Y at +0x9C), own position (this+0x94, this+0x9C), own direction (this+0xA4, negated Y at this+0xAC) and target1 direction (*(this+0x110)+0xA4/+0xAC); form the cross product v4 = own.dirX * target1.dirY - own.dirY * target1.dirX. [field:*(this+0x110):0x00000094, field:*(this+0x110):0x0000009C, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000AC, field:*(this+0x110):0x000000A4, field:*(this+0x110):0x000000AC, source:raw]
    // GUARD: Parallel-direction branch for target1: when the cross product v4 lies within +/-0.00001 the directions are parallel; write 0 to this+0xB0 when the target is self, otherwise write the large sentinel 1232348144, and return. [field:this:0x000000B0, field:this:0x00000110, source:raw]
    // CALCULATION: Line-intersection projection for target1: solve the intersection parameter from the position deltas and the direction ratio (target1.dirX / -target1.dirY) using target1 position (*(this+0x110)+0x94/+0x9C), target1 direction (*(this+0x110)+0xA4/+0xAC) and own position/direction (this+0x94/+0x9C/+0xA4/+0xAC); compute the two distances v16 (intersection to target1 position) and v6 (intersection to own position). [field:*(this+0x110):0x00000094, field:*(this+0x110):0x0000009C, field:*(this+0x110):0x000000A4, field:*(this+0x110):0x000000AC, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000AC, source:raw]
    // ASSIGNMENT: Store target1 proximity to this+0xB0: 0 when the target is self (this+0x110 == this), otherwise the smaller of the two distances v16 and v6 as a float. [field:this:0x000000B0, field:this:0x00000110, source:raw]
    // GUARD: Second-target guard: the target2 pointer this+0x114 must be non-null. [field:this:0x00000114, source:raw]
    // CALCULATION: Load the own data-block position/direction from the this+0x10C object (fields +0x94/+0x9C/+0xA4/+0xAC) and the target2 position (fields *(this+0x114)+0x0/+0x8); form the cross product v11 = data.dirX * this+0xAC - data.dirY * this+0xA4 against the own direction fields. [field:*(this+0x10C):0x00000094, field:*(this+0x10C):0x0000009C, field:*(this+0x10C):0x000000A4, field:*(this+0x10C):0x000000AC, field:this:0x000000A4, field:this:0x000000AC, field:*(this+0x114):0x00000000, field:*(this+0x114):0x00000008, source:raw]
    // GUARD: Parallel-direction branch for target2: when the cross product v11 lies within +/-0.00001, write the FLT_MAX-like large float sentinel to this+0xB4 when the target is not self and return; when the target is self fall through to the zero store. [field:this:0x000000B4, field:this:0x00000114, source:raw]
    // CALCULATION: Line-intersection projection for target2: use the target2 position delta (fields *(this+0x114)+0x0/+0x8), the own data-block position/direction (fields *(this+0x10C)+0x94/+0x9C/+0xA4/+0xAC) and the own position fields (this+0x94/+0x9C); compute the distances v17 (intersection to target2 position) and v14 (intersection to the own data position). [field:*(this+0x114):0x00000000, field:*(this+0x114):0x00000008, field:*(this+0x10C):0x00000094, field:*(this+0x10C):0x0000009C, field:*(this+0x10C):0x000000A4, field:*(this+0x10C):0x000000AC, field:this:0x00000094, field:this:0x0000009C, field:this:0x000000AC, source:raw]
    // ASSIGNMENT: Store target2 proximity to this+0xB4: 0 when the target is self (this+0x114 == this), otherwise the smaller of the two distances v17 and v14 as a float. [field:this:0x000000B4, field:this:0x00000114, source:raw]

    // Conservative worker pseudocode:
    //   if (!this[0x10C] || !this[0x110] || !this[0x110]->[0x110]) return;
    //   own = this+0x94/0x9C; dir = this+0xA4/0xAC;
    //   t1pos = this[0x110]+0x94/0x9C; t1dir = this[0x110]+0xA4/0xAC;
    //   cross = dir.x * t1dir.y - dir.y * t1dir.x;
    //   if (fabs(cross) < 0.00001) { this[0xB0] = (this[0x110] == this) ? 0 : 1232348144; return; }
    //   solve intersection; d1 = dist(intersection, t1pos); d2 = dist(intersection, own);
    //   this[0xB0] = (this[0x110] == this) ? 0 : min(d1, d2);
    //   if (this[0x114]) {
    //     data = this[0x10C]; t2pos = this[0x114]+0x0/0x8;
    //     cross2 = data.dir.x * dir.y - data.dir.y * dir.x;
    //     if (fabs(cross2) < 0.00001) { if (this[0x114] != this) this[0xB4] = FLT_MAX; else this[0xB4] = 0; return; }
    //     solve intersection; d3 = dist(intersection, t2pos); d4 = dist(intersection, data.pos);
    //     this[0xB4] = (this[0x114] == this) ? 0 : min(d3, d4);
    //   }
    // UNRESOLVED: The large float sentinel 2139095039 written to this+0xB4 for the non-self parallel case appears only in the raw source beyond the packet's 2000-char truncation; it is not enumerated in the packet fields.
    // UNRESOLVED: The read-only doubles dbl_5AD278 and dbl_5AD280 are listed as read by this function but are folded into FPU literals by Hex-Rays (likely the +/-0.00001 epsilon); their exact identity is unproven.
    // UNRESOLVED: The object roles of this+0x10C (own data block), this+0x110 (target1) and this+0x114 (target2) are DERIVED from existing analysis, not stated in the packet.
    // UNRESOLVED: Both callers (MultiPhaseProcessingStateMachine 0x00404460 and CountedLoopCallToElementUpdate 0x004047D0) are listed but not exercised in the body.
}
