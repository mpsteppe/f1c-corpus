// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055A060
// Canonical corpus name: sub_55A060
// Owner: SceneViewParser [DERIVED]
// Raw source: functions/sub_55A060_0055a060.c

void SceneViewParser::ParseViewElement()
{
    // Parses a 'View' element from a scene-file token stream: reads optional attributes (view/recursion, color, clipplanes, orient, dir, size, center, clear, bgmap, separatesurfac), then configures a view object (angles, projection, clip planes, color, orientation matrix or direction translation, clear/bgmap flags) and tail-inserts it into the owning scene list. Returns 0 on success, -1 on parse or allocation failure.
    // CALL: Parse the View element opening from the token stream via sub_544E90; return -1 on failure. [callee:0x00544E90, source:raw]
    // CALCULATION: Initialize parse state: counters cleared to 0, three fields defaulted to 72, and the clear-mode flag initialized to 32. [source:raw]
    // CALL: Read the first token via LineReaderFromBuffer; when it is not the final token (value 1), enter the attribute token loop. [callee:0x00559A70, source:raw]
    // LOOP: While the token stream head is not the end-of-stream marker (3), keep consuming attribute tokens; break early when LineReaderFromBuffer returns 1. [callee:0x00559A70, source:raw]
    // GUARD: Skip the structured-token block when the current token is the delimiter value 2. [source:raw]
    // CALL: Match the token against the 'view' string (aView) via sub_559E20; on match recurse into sub_55A060 for a nested view and return -1 if it fails. [callee:0x00559E20, global:0x005DC234, callee:0x0055A060]
    // CALL: Read a float quartet seeded from off_5DC230 (last value unused) and a float pair seeded from off_5C57FC. [callee:0x00559FB0, global:0x005DC230, global:0x005C57FC]
    // CALL: Read the color triple via sub_559F00 using the 'color' token. [callee:0x00559F00, global:0x005C57F4]
    // CALL: Read the clip-planes pair via the 'clipplanes' token. [callee:0x00559FB0, global:0x005C57E8]
    // CALL: Read the orientation triple via the 'orient' token; when present set the orientation-mode flag to 1. [callee:0x00559FB0, global:0x005DC228]
    // CALL: Read the direction triple via the 'dir' token; when present set the orientation-mode flag to 2. [callee:0x00559FB0, global:0x005DC224]
    // CALCULATION: Read the size pair via the 'size' token; scale entries that are at most 1.0 by the screen-width global dword_8B8DD4 and screen-height global dword_8B8DD8. [callee:0x00559FB0, global:0x005C57D0, global:0x008B8DD4, global:0x008B8DD8]
    // CALCULATION: Read the center pair via the 'center' token; scale entries that are at most 1.0 by dword_8B8DD4 and dword_8B8DD8. [callee:0x00559FB0, global:0x005C57C8, global:0x008B8DD4, global:0x008B8DD8]
    // CALL: Match the 'clear' token via sub_559E20; when found, set or clear bit 1 of the clear-mode flag depending on whether the read string equals 'true'. [callee:0x00559E20, global:0x005C57A0, global:0x005C596C]
    // CALL: Match the 'bgmap' token via sub_559E20; set the bgmap-present flag to 1 when found. [callee:0x00559E20, global:0x005DC21C]
    // CALL: Match the 'separatesurfac' token via sub_559E20 (result value not retained). [callee:0x00559E20, global:0x005DC20C]
    // CALL: After the loop, if a bgmap was requested allocate the background-map surface on the parsed object (+104 words) via MemoryAllocation_cb20; return -1 on failure. [callee:0x0053CB20, source:raw]
    // CALCULATION: Convert the two parsed angle values to radians (multiply by 0.01745433) and set the view orientation via sub_542050. [callee:0x00542050, source:raw]
    // CALCULATION: Compute the view center (center minus half of size) and configure the projection via sub_542200. [callee:0x00542200, source:raw]
    // CALL: Set the clip-plane pair on the view object via TwoFieldSetterCall. [callee:0x005423C0]
    // CALL: Pack the color into the view object via ColorPack. [callee:0x005423E0]
    // ASSIGNMENT: Store the accumulated clear-mode flag into the view object's flag word. [source:raw]
    // CALL: When direction mode was selected, negate the direction triple, update the orientation rotation matrix via OrientationRotationMatrixUpdate, and translate the camera by the negated direction via sub_541F60. [callee:0x00541D10, callee:0x00541F60, source:raw]
    // CALL: Otherwise feed the orientation triple into UtilityFunction_1cd0. [callee:0x00541CD0, source:raw]
    // CALL: Tail-insert the constructed view object: LinkedListInsertTail into the provided owner list a3 when non-null, else DoublyLinkedListTailInsertion into the current object. [callee:0x005419D0, callee:0x00545030, source:raw]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (sub_544E90(this, &view, name)) return -1;
    //   if (LineReaderFromBuffer(a4) != 1) {
    //     while (*a4 != 3) {
    //       if (*a4 != 2) {
    //         if (match(a4, aView, name) && sub_55A060(name, view, a4)) return -1;
    //         read orientation/size/center/color/clipplanes/clear/bgmap/separatesurfac tokens;
    //       }
    //       if (LineReaderFromBuffer(a4) == 1) break;
    //     }
    //     if (bgmapRequested && MemoryAllocation_cb20(view + 104, bgmapName, 0, 1)) return -1;
    //   }
    //   configure angles, projection, clip planes, color, orientation/direction;
    //   if (a3) LinkedListInsertTail(a3, view); else DoublyLinkedListTailInsertion(this, view);
    //   return 0;
    // UNRESOLVED: Packet globals dbl_59E420, flt_59E450 and flt_59E65C are not referenced by the raw body; the source uses the literals 0.01745433 and 1.0 instead.
}
