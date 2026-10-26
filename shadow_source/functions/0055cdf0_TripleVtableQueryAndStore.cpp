// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CDF0
// Canonical corpus name: TripleVtableQueryAndStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleVtableQueryAndStore_0055cdf0.c

void UnknownObject::TripleVtableQueryAndStore()
{
    // Three unconditional vtable queries against the sub-object at this+0x1100. Two calls go through vtable entry 0x98 (offset 152) with enum selectors 2 and 3, writing through output pointers &this[1302] and &this[1318]; the third goes through vtable entry 0xA4 (offset 164) writing through &this[1334]. The scratch field this[0x0] receives each call result, and the final result is returned.
    // CALL: First query: indirect call through vtable entry at *(this+0x1100)+0x98 (offset 152), passing (this[0x1100], 2, &this[1302]). [field:*(this+0x1100):0x00000098, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the first query result into this[0x0]. [field:this:0x00000000, source:raw]
    // CALL: Second query: same vtable entry at *(this+0x1100)+0x98 (offset 152), passing (this[0x1100], 3, &this[1318]). [field:*(this+0x1100):0x00000098, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the second query result into this[0x0]. [field:this:0x00000000, source:raw]
    // CALL: Third query: indirect call through vtable entry at *(this+0x1100)+0xA4 (offset 164), passing (this[0x1100], &this[1334]). [field:*(this+0x1100):0x000000A4, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Store the third query result into this[0x0]. [field:this:0x00000000, source:raw]
    // RETURN: Return the third query result. [source:raw, function:0x0055CDF0]

    // Conservative worker pseudocode:
    //   int sub_55CDF0(int *this) {
    //     this->field_0 = (this->subobj_1100->vtbl[152])(this->subobj_1100, 2, &this->dst_1302);
    //     this->field_0 = (this->subobj_1100->vtbl[152])(this->subobj_1100, 3, &this->dst_1318);
    //     int result = (this->subobj_1100->vtbl[164])(this->subobj_1100, &this->dst_1334);
    //     this->field_0 = result;
    //     return result;
    //   }
    // UNRESOLVED: The vtable methods at entries 0x98 and 0xA4 are not identified; the meaning of the enum selectors 2 and 3 is unknown.
    // UNRESOLVED: The destination offsets this+1302, this+1318, this+1334 (element indices) are not in the packet field list, so their concrete byte offsets are not asserted here.
}
