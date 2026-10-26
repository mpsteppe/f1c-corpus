// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00493990
// Canonical corpus name: sub_493990
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_493990_00493990.c

void UnknownObject::ParseUiSurfaceBlock()
{
    // Parses one UI surface definition block from a text stream. Reads 'location' and 'poswh' tokens as integer coordinate pairs via sub_565870/CRTFtol, reads the 'surface' name, and reads animation tokens ('animdelta' as float via sub_58850F, 'animrule' as int via sub_587ECE, 'subanimframe' as a recursive nested block). Once surface name and coordinates are present it creates the surface object through sub_499F70, then applies the parsed animation delta/rule to the created object. Tracks block nesting with a depth counter at this+0x194 (incremented on entry, decremented on exit).
    // ASSIGNMENT: Initialize a 125-byte token buffer: seed byte 0 from global byte_5EA438[0], zero the remaining 0x7C bytes and the trailing 16-bit field. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Increment the UI block nesting depth counter this[101] (field +0x194), store the this pointer, and remember the new depth for the whole parse. [field:this:0x00000194, source:raw]
    // GUARD: If sub_491FB0(this) (next input token reader) returns false, skip the parse loop entirely. [callee:0x00491FB0, source:raw]
    // LOOP: Iterate tokens with sub_491FB0(v14); each token is dispatched via sub_587C20 comparing against the shared compare buffer at unk_7CDB70. [callee:0x00491FB0, callee:0x00587C20, global:0x007CDB70, source:raw]
    // GUARD: Opening-block token asc_5CC4F4 matches: decrement depth v16; if it reaches zero break out of the parse loop. [callee:0x00587C20, global:0x005CC4F4, source:raw]
    // GUARD: Closing-block token asc_5CC4F8 matches: increment depth v16. [callee:0x00587C20, global:0x005CC4F8, source:raw]
    // GUARD: If sub_565870(aLocation, ...) parses the 'location' token into four floats, convert each float to int with CRTFtol (x/y/width/height) and mark coordinates as parsed. [callee:0x00565870, global:0x005CC694, callee:0x00587BDC, source:raw]
    // GUARD: Else if sub_565870(aPosWH, ...) parses the 'poswh' token, combine the two float pairs (v15+v13 and v17+v12) before CRTFtol conversion and mark coordinates as parsed. [callee:0x00565870, global:0x005CC68C, callee:0x00587BDC, source:raw]
    // GUARD: Else if sub_5654A0(aSurface, v25) reads the 'surface' name token into v25, mark the surface-name flag. [callee:0x005654A0, global:0x005CC678, source:raw]
    // GUARD: Else if sub_5654A0(aAnimdelta, v22) reads the 'animdelta' token, parse it as a float with sub_58850F into v20. [callee:0x005654A0, global:0x005CC92C, callee:0x0058850F, source:raw]
    // GUARD: Else if sub_5654A0(aAnimrule, v22) reads the 'animrule' token, parse it as an int with sub_587ECE into v21. [callee:0x005654A0, global:0x005CC920, callee:0x00587ECE, source:raw]
    // GUARD: Else if sub_5654A0(aSubanimframe, v22) reads the 'subanimframe' token while a surface object already exists, recursively call sub_493990(a2, v18) to parse the nested frame block. [callee:0x005654A0, global:0x005CC910, callee:0x00493990, source:raw]
    // CALL: Once both the surface name and coordinates are present, create the surface object via sub_499F70(v4, v5, v3, v19, v25, 0, 1, a3) and mark the created flag. [callee:0x00499F70, source:raw]
    // ASSIGNMENT: After the parse loop, if a surface object exists, write the parsed animdelta float to created-object +24 when positive and the animrule int to created-object +28. [source:raw]
    // RETURN: Decrement the nesting counter this[101] (field +0x194) and return 0. [field:this:0x00000194, source:raw]

    // Conservative worker pseudocode:
    //   init token buffer from byte_5EA438;
    //   depth = ++this[0x194/4];
    //   if sub_491FB0(this):
    //       loop while sub_491FB0(this):
    //           if sub_587C20(&unk_7CDB70, asc_5CC4F4): if --depth <= 0 break; continue
    //           if sub_587C20(&unk_7CDB70, asc_5CC4F8): ++depth; continue
    //           if sub_565870(aLocation, &v12,&v13,&v17,&v15,0,0,0,0): x=CRTFtol(v12); y=CRTFtol(v13); w=CRTFtol(v17); h=CRTFtol(v15)
    //           elif sub_565870(aPosWH, &v12,&v13,&v17,&v15,0,0,0,0): w=CRTFtol(v13); h=CRTFtol(v15+v13); x=CRTFtol(v12); y=CRTFtol(v17+v12)
    //           elif sub_5654A0(aSurface, v25): surface_seen = 1
    //           elif sub_5654A0(aAnimdelta, v22): animdelta = sub_58850F(v22)
    //           elif sub_5654A0(aAnimrule, v22): animrule = sub_587ECE(v22)
    //           elif sub_5654A0(aSubanimframe, v22) and created: sub_493990(a2, obj)
    //           if surface_seen and not created: obj = sub_499F70(x,y,w,h,v25,0,1,a3); created = 1
    //   if obj: if animdelta > 0.0 obj+24 = animdelta; obj+28 = animrule
    //   this[0x194/4]--; return 0
    // UNRESOLVED: Global flt_59E440 is listed as read (R) but does not appear in the raw function text; its role here is unclear.
    // UNRESOLVED: Global unk_7CD9D8 is listed as read (R) but does not appear in the raw function text; its role here is unclear.
    // UNRESOLVED: The object returned by sub_499F70 receives writes at +24 (float animdelta) and +28 (animrule); those offsets belong to the created surface object, not to this, and their meaning is DERIVED.
    // UNRESOLVED: The token strings asc_5CC4F4 / asc_5CC4F8 are treated as block open/close delimiters based on the depth-counter behavior (DERIVED).
}
