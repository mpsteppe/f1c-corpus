// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053F3F0
// Canonical corpus name: sub_53F3F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53F3F0_0053f3f0.c

void UnknownObject::NegotiateSurfaceFormat()
{
    // Negotiates a surface format between a source surface (optional) and a destination capability block, mapping format bitmasks to canonical format ids, then drives a retry loop of up to three attempts that calls surface-creation vtable slots on two sub-objects (this+0x10FC, this+0x1100) with format variants 71/77/80. Each call result is stored in this+0. When one variant yields all-zero results the output is flagged (out+24 |= 2) and 0 returned; if all variants are exhausted the error logger sub_53C590 is invoked with the aInvalidParamet string and -1 is returned.
    // CALCULATION: Map the input format bitmask a5 to a subtype code v21: 0x20 to 2, 0x100 to 3, 0x40 to 4, 0x400 to 6, otherwise HIWORD(a5) & 0x10. [function:0x0053F3F0, source:raw]
    // CALCULATION: When a source surface a2 exists, read its pixel-format dword (a2+280) and format dword (a2+260), query format info via sub_55BDE0, then normalize the format id a5 via sub_55C650 from the queried info field. [callee:0x0055BDE0, callee:0x0055C650]
    // CALCULATION: Classify the format via sub_55C450 (result in v22): when v22 is 16 pick format id 23/24/25 from flags in *a2 (0x1000000/0x4000000/0x2000000); when v22 is 24 or 32 pick 20/22/21 from flags (0x8000000/0x20000000/0x10000000). [callee:0x0055C450, source:raw]
    // CALCULATION: Without a source surface: normalize a5 from the destination format a3[12] via sub_55C650, map 21 to 22 and 25 to 24, and zero the subtype and source-format locals. [callee:0x0055C650, source:raw]
    // CALCULATION: Normalize the destination-derived format into a2 via sub_55C650 and apply the same mapping (21 to 22, 25 to 24); when a source surface exists, re-classify a2 via sub_55C450 using the same flag tests. [callee:0x0055C650, callee:0x0055C450]
    // LOOP: Retry loop over up to three attempts selecting surface format variants 71, 77, 80 for the surface-creation calls; loop exits early on the accept condition or errors after the third attempt. [field:this:0x000010FC, field:this:0x00001100, caller:0x0053E070, caller:0x0053F720, caller:0x00555E50]
    // CALL: Attempt 1: call the vtable slot at *(this+0x10FC)+0x28 (vtable[10]) with arguments (v23, 1, a5, 2, 1, variant); store the result in this+0. [field:*(this+0x10FC):0x00000028, field:this:0x00000000, field:this:0x000010FC]
    // CALL: When attempt 1 returns 0, attempt 2 via the vtable slot *(this+0x10FC)+0x30 (vtable[12]) with (v23, 1, a5, a2, variant); store the result in this+0. [field:*(this+0x10FC):0x00000030, field:this:0x00000000]
    // CALL: When attempt 2 also returns 0, attempt 3 via the vtable slot *(this+0x1100)+0x68 (vtable[26]) with (a3[7], a3[8], variant, v21, out+12); store the result in this+0. [field:*(this+0x1100):0x00000068, field:this:0x00000000, field:this:0x00001100]
    // GUARD: When all three retry attempts are exhausted without reaching the accept condition, log the invalid-parameter error via sub_53C590(-1, aInvalidParamet) and return -1. [callee:0x0053C590, global:0x005DBCD0]
    // RETURN: On the accept condition (a variant whose surface-creation calls all returned 0), set the success flag on the output struct (out+24 |= 2) and return 0. [function:0x0053F3F0]

    // Conservative worker pseudocode:
    //   // Map format bitmask a5 to a subtype code.
    //   if (a5 & 0x20) subtype = 2;
    //   else if (a5 & 0x100) subtype = 3;
    //   else if (a5 & 0x40) subtype = 4;
    //   else if (a5 & 0x400) subtype = 6;
    //   else subtype = HIWORD(a5) & 0x10;
    //   src = a2;
    //   if (src) {
    //       pf = *(src + 280); fmt = *(src + 260);
    //       info = sub_55BDE0(pf);
    //       sub_55C650(&a5, *(info + 20), 0);
    //       sub_55C450(a5, &cls, 0);
    //       if (cls == 16) a5 = pick(*src, 0x1000000, 0x4000000, 0x2000000, 23, 24, 25);
    //       else if (cls == 24 || cls == 32) a5 = pick(*src, 0x8000000, 0x20000000, 0x10000000, 20, 22, 21);
    //   } else {
    //       sub_55C650(&a5, a3[12], 0);
    //       if (a5 == 21) a5 = 22; else if (a5 == 25) a5 = 24;
    //       subtype = 0; fmt = 0;
    //   }
    //   sub_55C650(&a2, a3[12], 0);
    //   if (a2 == 21) a2 = 22; else if (a2 == 25) a2 = 24;
    //   if (src) { sub_55C450(a2, &cls, 0); a2 = pick(*src, /* same flag table * / 0); }
    //   for (attempt = 0; attempt < 3; ++attempt) {
    //       variant = (attempt == 0) ? 71 : (attempt == 1) ? 77 : 80;
    //       *this = vtable(this[1087], 40)(this[1087], fmt, 1, a5, 2, 1, variant);
    //       if (!*this) {
    //           *this = vtable(this[1087], 48)(this[1087], fmt, 1, a5, a2, variant);
    //           if (!*this) {
    //               *this = vtable(this[1088], 104)(this[1088], a3[7], a3[8], variant, subtype, out + 12);
    //               if (!*this) break;
    //           }
    //       }
    //       if (attempt == 2) { sub_53C590(-1, aInvalidParamet); return -1; }
    //   }
    //   *(out + 24) |= 2;
    //   return 0;
    // UNRESOLVED: Semantics of the exact format ids (20..25, 71, 77, 80) and the bitmask flags in *a2 are not established.
    // UNRESOLVED: Reason the accept condition requires all three vtable calls to return 0 (treating non-zero as failure to retry) is inferred, not confirmed.
    // UNRESOLVED: The owner class and the roles of the two sub-objects at this+0x10FC and this+0x1100 are unknown.
    // UNRESOLVED: Purpose of the output flag at out+24 |= 2 is not established.
}
