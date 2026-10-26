// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F6F7
// Canonical corpus name: sub_50F6F7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50F6F7_0050f6f7.c

void UnknownObject::handleJpegMarker()
{
    // Dispatches JPEG stream marker handling on the decoder's current marker field (this+0x20): case 1 (SOI), case 3 (SOF0) and case 4 (SOS) set decoder sub-state (this+0x24) and mode (this+0x28) fields. SOF0/SOS validate component descriptors read from the frame header pointed at by this+0xC4; unsupported layouts record an error on the callback object (error code at obj+0x14, diagnostic bytes at obj+0x18..0x20, callback invoked through the obj+0x4 vtable with (this, 1) or (this, -1)). All paths end in a shared tail that resets and re-initializes decoder counters/quant fields, then returns 1.
    // GUARD: ABI: __usercall, this passed in ESI; invoked from StateMachineDispatch (0x0050F86A). Dispatch on the decoder marker selector at this+0x20: case 1 (SOI), case 3 (SOF0), case 4 (SOS), default invalid. [abi:lead, caller:0x0050F86A, field:this:0x00000020, source:raw]
    // ASSIGNMENT: case 1 (SOI): set sub-state this+0x24 = 1 and mode this+0x28 = 1. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // GUARD: case 3 (SOF0): if byte this+0x100 is set, skip component validation and finish the SOF path with sub-state 3. [field:this:0x00000100, field:this:0x00000024, source:raw]
    // GUARD: case 3: if byte this+0x106 (component-info present) is set, dispatch on the component id byte this+0x107. [field:this:0x00000106, field:this:0x00000107, source:raw]
    // ASSIGNMENT: case 3: component id this+0x107 == 0 selects sub-state this+0x24 = 2. [field:this:0x00000107, field:this:0x00000024, source:raw]
    // GUARD: guard:1 — component id byte this+0x107 != 1 marks an unsupported single-component layout. [guard:1, field:this:0x00000107, source:raw]
    // CALL: case 3 unsupported component id (this+0x107 not 0 or 1): record error code obj+0x14 = 110 and diagnostic byte obj+0x18 = this+0x107; invoke the error callback through the obj+0x4 vtable with (this, -1). [field:this:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000107, source:raw]
    // ASSIGNMENT: case 3 component path completion: sub-state this+0x24 = 3; mode this+0x28 = 2. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALCULATION: Load the frame-header pointer from this+0xC4 and read three component descriptors into locals: header[0x0], header[0x54], header[0xA8]. [field:this:0x000000C4, field:*(this+0xC4):0x00000000, field:*(this+0xC4):0x00000054, field:*(this+0xC4):0x000000A8, source:raw]
    // GUARD: guard:0 — header component descriptor header[0x0] == 1 selects the single-component acceptance path. [guard:0, field:*(this+0xC4):0x00000000, source:raw]
    // GUARD: Single-component acceptance: header[0x54] == 2 and header[0xA8] == 3 mean the component layout is accepted; jump to the completion label. [field:*(this+0xC4):0x00000054, field:*(this+0xC4):0x000000A8, source:raw]
    // GUARD: Otherwise, if the descriptor triplet (header[0x0], header[0x54], header[0xA8]) equals (82, 71, 66) — ASCII 'R', 'G', 'B' — the layout is valid RGB: set sub-state this+0x24 = 2 and jump to the done label. [field:*(this+0xC4):0x00000000, field:*(this+0xC4):0x00000054, field:*(this+0xC4):0x000000A8, field:this:0x00000024, source:raw]
    // CALL: Unknown component layout: store the three component descriptors into obj+0x18/0x1C/0x20; set error code obj+0x14 = 107 (bad component count); invoke the callback through the obj+0x4 vtable with (this, 1). [field:this:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, field:*(this+0xC4):0x00000000, field:*(this+0xC4):0x00000054, field:*(this+0xC4):0x000000A8, source:raw]
    // ASSIGNMENT: Component validation passed: sub-state this+0x24 = 3; mode this+0x28 = 2. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // GUARD: case 4 (SOS): component-info present (this+0x106) and component id this+0x107 nonzero select the component-check path. [field:this:0x00000106, field:this:0x00000107, source:raw]
    // GUARD: guard:2 — component id byte this+0x107 != 2 marks an unsupported SOS component layout. [guard:2, field:this:0x00000107, source:raw]
    // CALL: SOS unsupported component id: record error code obj+0x14 = 110 and diagnostic obj+0x18 = this+0x107; invoke the error callback through the obj+0x4 vtable with (this, -1). [field:this:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000107, source:raw]
    // ASSIGNMENT: case 4: sub-state this+0x24 = 5 when the component is valid, else this+0x24 = 4; mode this+0x28 = 4 in both paths. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // ASSIGNMENT: default (unknown marker): sub-state this+0x24 = 0; mode this+0x28 = 0. [field:this:0x00000024, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Common tail reset: bytes this+0x40 and this+0x41 = 0; double this+0x38 = 1.0; this+0x44 = 0; byte this+0x4A = 0; this+0x74 = 0; bytes this+0x58/0x59/0x5A = 0. [field:this:0x00000038, field:this:0x00000040, field:this:0x00000041, field:this:0x00000044, field:this:0x0000004A, field:this:0x00000058, field:this:0x00000059, field:this:0x0000005A, field:this:0x00000074, source:raw]
    // ASSIGNMENT: Common tail init: this+0x2C = 1; this+0x30 = 1; bytes this+0x48 and this+0x49 = 1; this+0x4C = 2; byte this+0x50 = 1; this+0x54 = 256. [field:this:0x0000002C, field:this:0x00000030, field:this:0x00000048, field:this:0x00000049, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, source:raw]
    // RETURN: Return 1 (accepted / continue). [function:0x0050F6F7, source:raw]

    // Conservative worker pseudocode:
    //   int handleJpegMarker(this) {
    //     switch (this->marker /* +0x20 * /) {
    //       case 1: /* SOI * /
    //         this->substate = 1; /* +0x24 * /
    //         this->mode = 1;     /* +0x28 * /
    //         break;
    //       case 3: /* SOF0 * /
    //         if (this->b_0x100) goto finish_sof;
    //         if (this->b_0x106) { /* component info present * /
    //           if (this->b_0x107 == 0) { this->substate = 2; goto done; }
    //           if (this->b_0x107 != 1) { /* unsupported component id * /
    //             obj->err_code = 110;        /* +0x14 * /
    //             obj->diag = this->b_0x107;  /* +0x18 * /
    //             obj->callback(this, -1);    /* vtable +0x4 * /
    //           }
    //         finish_sof:
    //           this->substate = 3;
    //         done:
    //           this->mode = 2;
    //           break;
    //         }
    //         hdr = this->header;             /* +0xC4 * /
    //         c0 = hdr[0x0]; c1 = hdr[0x54]; c2 = hdr[0xA8];
    //         if (c0 == 1) { if (c1 == 2 && c2 == 3) goto accepted; }
    //         else if (c0 == 82 && c1 == 71 && c2 == 66) { /* 'R','G','B' * /
    //           this->substate = 2; goto done;
    //         }
    //         obj->components[0..2] = { c0, c1, c2 }; /* +0x18/0x1C/0x20 * /
    //         obj->err_code = 107;            /* +0x14 * /
    //         obj->callback(this, 1);         /* vtable +0x4 * /
    //       accepted:
    //         this->substate = 3;
    //         goto done;
    //       case 4: /* SOS * /
    //         if (this->b_0x106 && this->b_0x107) {
    //           if (this->b_0x107 != 2) { /* unsupported component id * /
    //             obj->err_code = 110;
    //             obj->diag = this->b_0x107;
    //             obj->callback(this, -1);
    //           }
    //           this->substate = 5;
    //         } else {
    //           this->substate = 4;
    //         }
    //         this->mode = 4;
    //         break;
    //       default:
    //         this->substate = 0;
    //         this->mode = 0;
    //         break;
    //     }
    //     /* common tail reset/init * /
    //     this->b_0x40 = 0; this->b_0x41 = 0; this->d_0x38 = 1.0;
    //     this->w_0x44 = 0; this->b_0x4A = 0; this->w_0x74 = 0;
    //     this->b_0x58 = 0; this->b_0x59 = 0; this->b_0x5A = 0;
    //     this->w_0x2C = 1; this->w_0x30 = 1; this->b_0x48 = 1;
    //     this->b_0x49 = 1; this->w_0x4C = 2; this->b_0x50 = 1;
    //     this->w_0x54 = 256;
    //     return 1;
    //   }
    // UNRESOLVED: Existing analysis names this function JpegSOFHandler_InitDecoder (JPEG Start-of-Frame handling); the packet owner is UnknownObject/UNKNOWN, so owner trust stays UNKNOWN and proposed_name is a DERIVED identifier.
    // UNRESOLVED: Semantics of this+0x100, this+0x106, this+0x107 (component-info presence / component id bytes) are inferred DERIVED from usage, not proven.
    // UNRESOLVED: Marker value meanings (1=SOI, 3=SOF0, 4=SOS) come from existing analysis (DERIVED); not independently confirmed.
    // UNRESOLVED: Fields obj+0x1C and obj+0x20 are only visibly written together with obj+0x18 as the three-component descriptor store in the unknown-layout path; the single-component error paths write only obj+0x18.
    // UNRESOLVED: obj+0x0 (error-code field) is part of the vtable-call object but is not itself referenced in the visible source.
}
