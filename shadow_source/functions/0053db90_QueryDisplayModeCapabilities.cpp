// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053DB90
// Canonical corpus name: sub_53DB90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53DB90_0053db90.c

void UnknownObject::QueryDisplayModeCapabilities()
{
    // Display adapter capability query for a selected display (a2[65]). Dispatches surface-format and multisample capability tests through vtable slots +20/+24/+36/+44/+52 on the sub-object at this+0x10FC, accumulating a support bitmask in *a2, then enumerates display modes (slots +32/+24/+28) and reports the modes that pass the resolution window this+0x1508..this+0x1510 to sub_55BC00. Logs aErrorEnumDispl / aCouldNotGetCur through sub_53C590 and returns -1 on failure. Invoked by DisplayModeEnumeratorWrapper (0x0055BBF0).
    // CALL: Gets surface data for the selected display a2[65] through vtable slot +20 on the sub-object at this+0x10FC, writing into buffer v41 and storing the result in this+0x0 [field:this:0x000010FC, field:*(this+0x10FC):0x00000000, field:*(*(this+0x10FC)+0x0):0x00000014, field:this:0x00000000, source:raw]
    // CALL: When the stack-sentinel check v42 == 4170 passes, resets the object state via StateIntSetter4(this, -1, -1, 1024, 768) [callee:0x0053D930, source:raw]
    // CALL: Tests surface format 23/23 capability via vtable slot +36; on failure ORs 0x1000000 into the capability bitmask *a2; the result is stored in this+0x0 [field:*(*(this+0x10FC)+0x0):0x00000024, field:this:0x00000000, source:raw]
    // CALL: Tests surface format 24/25 capability via slot +36; on failure ORs 0x2000000 into *a2 [field:*(*(this+0x10FC)+0x0):0x00000024, source:raw]
    // CALL: Tests surface format 24/24 capability via slot +36; on failure ORs 0x4000000 into *a2 [field:*(*(this+0x10FC)+0x0):0x00000024, source:raw]
    // CALL: Tests surface format 20/20 capability via slot +36; on failure ORs 0x8000000 into *a2 [field:*(*(this+0x10FC)+0x0):0x00000024, source:raw]
    // CALL: Tests surface format 22/22 capability via slot +36; on failure ORs 0x20000000 into *a2 [field:*(*(this+0x10FC)+0x0):0x00000024, source:raw]
    // CALL: Tests surface format 22/21 capability via slot +36; on failure ORs 0x10000000 into *a2 [field:*(*(this+0x10FC)+0x0):0x00000024, source:raw]
    // CALL: Queries mode-info data for the display via vtable slot +52 into buffer v37; a non-zero result makes the function return -1 [field:*(*(this+0x10FC)+0x0):0x00000034, source:raw]
    // CALCULATION: Assembles the capability bitmask in *a2 from format-descriptor output fields: v40 0x10000 selects bit 4, v40 0x100000 selects 0x400000, v40 0x80000 selects bit 8, v38 0x80000 selects bit 1, v39 low bit selects 0x10 [source:raw]
    // CALL: Tests multisample type 2 via slot +44 on formats 23 and 22; failure of either ORs 0x20 into *a2 [field:*(*(this+0x10FC)+0x0):0x0000002C, source:raw]
    // CALL: Tests multisample type 3 via slot +44; failure ORs 0x80 into *a2 [field:*(*(this+0x10FC)+0x0):0x0000002C, source:raw]
    // CALL: Tests multisample type 4 via slot +44; failure ORs 0x40 into *a2 [field:*(*(this+0x10FC)+0x0):0x0000002C, source:raw]
    // CALL: Tests multisample type 6 via slot +44; failure ORs 0x200 into *a2 [field:*(*(this+0x10FC)+0x0):0x0000002C, source:raw]
    // CALL: Tests multisample type 16 via slot +44; failure ORs 0x80000 into *a2 [field:*(*(this+0x10FC)+0x0):0x0000002C, source:raw]
    // CALL: Clears a2[68] and a2[69], then gets the current display mode via vtable slot +32 into buffer v35; on failure logs aCouldNotGetCur through sub_53C590 and returns -1 [field:*(*(this+0x10FC)+0x0):0x00000020, global:0x005DBCAC, callee:0x0053C590, source:raw]
    // CALL: Resolves the current mode's resolution via sub_55C450, using format id 21 when the mode format v36 equals 22 [callee:0x0055C450, source:raw]
    // CALL: Queries the display-mode count via vtable slot +24; when it is not positive, logs aErrorEnumDispl through sub_53C590 and returns -1 [field:*(*(this+0x10FC)+0x0):0x00000018, global:0x005DBC90, callee:0x0053C590, source:raw]
    // LOOP: Enumerates each display mode 0..count-1 via vtable slot +28 into v31/v32 (width/height), storing each call result in this+0x0 and re-testing the mode's surface format v34 through slot +36 [field:*(*(this+0x10FC)+0x0):0x0000001C, field:this:0x00000000, source:raw]
    // CALCULATION: Filters enumerated modes: skips the duplicate low resolutions (width 0x2C0/0x2D0/0x358 at height 480 and width 0x3C0/0x500 at height 720), then keeps modes inside the window v31 >= this+0x1508, v32 >= this+0x150C, v31 <= this+0x1510 and v32 <= this+0x1510 [field:this:0x00001508, field:this:0x0000150C, field:this:0x00001510, source:raw]
    // CALL: For modes passing the resolution filter, delegates to sub_55BC00(v31, v32, v30, v33) [callee:0x0055BC00, source:raw]
    // CALL: Invoked by DisplayModeEnumeratorWrapper (0x0055BBF0) as the capability/mode-enumeration stage [caller:0x0055BBF0, source:raw]

    // Conservative worker pseudocode:
    //   this+0 = getSurfaceData(this+0x10FC, a2[65], 2, v41);
    //   if (sentinel == 4170) StateIntSetter4(this, -1, -1, 1024, 768);
    //   mask bits via slot +36 tests:
    //     23/23 fail -> 0x1000000; 24/25 fail -> 0x2000000; 24/24 fail -> 0x4000000;
    //     20/20 fail -> 0x8000000; 22/22 fail -> 0x20000000; 22/21 fail -> 0x10000000;
    //   if (slot +52 mode-info query) return -1;
    //   assemble *a2 bits from v40/v38/v39 (0x10000->bit4, 0x100000->0x400000, 0x80000->bit8, v38&0x80000->bit1, v39&1->0x10);
    //   multisample type tests (formats 23 and 22) via slot +44:
    //     type 2 fail -> 0x20; type 3 fail -> 0x80; type 4 fail -> 0x40;
    //     type 6 fail -> 0x200; type 16 fail -> 0x80000;
    //   a2[68] = 0; a2[69] = 0;
    //   if (slot +32 current-mode query) { sub_53C590(-1, aCouldNotGetCur); return -1; }
    //   sub_55C450(v36 == 22 ? 21 : v36, &v29, &v30);
    //   count = slot +24 mode count;
    //   if (count <= 0) { sub_53C590(-1, aErrorEnumDispl); return -1; }
    //   for (v4 = 0; v4 < count; ++v4) {
    //     if (slot +28 get mode v31/v32) continue;
    //     re-test format v36/v34 via slot +36 with multisample 1;
    //     sub_55C450(v34 == 22 ? 21 : v34, &v29, &v30);
    //     if (v29 < 16) continue;
    //     if ((v31,v32) is one of the duplicate low resolutions) continue;
    //     if (v31 >= this+0x1508 && v32 >= this+0x150C && v31 <= this+0x1510 && v32 <= this+0x1510)
    //       sub_55BC00(v31, v32, v30, v33);
    //   }
    //   return 0;
    // UNRESOLVED: The sub-object at this+0x10FC is reached only through vtable slots +20/+24/+28/+32/+36/+44/+52; its concrete class and the meaning of the format ids 20-25 are unknown from this packet
    // UNRESOLVED: The capability bitmask bits (0x20/0x40/0x80/0x200/0x80000 for multisample types 2,3,4,6,16 and 0x1000000..0x10000000 for formats) are assembled from format-descriptor output fields v38/v39/v40 whose layout is not resolved
    // UNRESOLVED: The a3 argument is never referenced in the function body
    // UNRESOLVED: The duplicate-resolution skips (480/720) and the resolution window 0x1508..0x1510 encode display conventions that existing analysis marks only DERIVED
    // UNRESOLVED: The sentinel check v42 == 4170 and the StateIntSetter4 reset (1024, 768) path are unexplained
}
