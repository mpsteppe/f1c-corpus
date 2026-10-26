// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055A910
// Canonical corpus name: SceneNode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNode_0055a910.c

void UnknownObject::SceneNode()
{
    // Scene-file node parser. Allocates and constructs a 572-byte scene graph node, attaches it to a parent (a3), then consumes a token stream (a4) one line at a time, matching keyword strings against the node's mesh/animation/LOD/collision/shadow/render/visibility properties and setting bit flags and float/view fields. On stream end it links the node into the scene graph (doubly-linked or actor-list append) and optionally applies orientation/view data; on parse failure it frees the node.
    // CALL: Prologue: atomically decrement the audio-buffer reference counter dword_8B8EE8 via InterlockedDecrement, then run AudioVolumeLoadComputation(0). [global:0x008B8EE8, global:0x0059E234, callee:0x00545F50, source:raw]
    // CALL: Allocate a 572-byte node with OperatorNewNhMallocWrapper; if non-null construct it through sub_54A600, otherwise leave it null. [callee:0x00587C03, callee:0x0054A600, source:raw]
    // ASSIGNMENT: Initialize the node: v6[15] = 0 (state field), v6[16] = a3 (parent pointer); zero local float/int scratch v42/v45/v44/v39/v41/v43, and prime v40/v38 with -1.0. [source:raw]
    // ASSIGNMENT: If a parent (a3) is present, set the node's state field v6[15] to 8. [source:raw]
    // CALL: Read the first line via LineReaderFromBuffer(a4); if it returns 1 the stream is exhausted and parsing jumps straight to the finish path (LABEL_122). [callee:0x00559A70, source:raw]
    // LOOP: Finish path: walk the child-node chain rooted at v6[129], writing v6[20] into each child's +252 slot and advancing via the +16 next pointer until the chain ends. [source:raw]
    // CALL: Finish path link: if a parent (a3) exists insert the node with DoublyLinkedListNodeMover(a3, v6, 0), otherwise append with ActorNodeLinkedListAppend(this, v6). [callee:0x0054BA00, callee:0x00545250, source:raw]
    // CALL: Finish path fallback: when the node has no children, register it with SceneGraph(v6), run TwoFunctionCallChain(), then free it with FreeWrapper_7bcf(v6). [callee:0x0054A770, callee:0x0054A710, callee:0x00587BCF, source:raw]
    // CALL: Finish path orientation: if the view-orientation flag v37 is set, apply the parsed view data via sub_54B4D0(v6, v43, v41, v39, v44, v45, v42). [callee:0x0054B4D0, source:raw]
    // RETURN: Return 0 on the normal finish path. [function:0x0055A910, abi:lead, source:raw]
    // LOOP: Main token loop: if *a4 == 3 jump to finish; if *a4 == 2 jump to the line re-read (LABEL_120); if sub_559F00 matches the aVisgroups keyword into v46, break to the visgroup continuation. [callee:0x00559F00, global:0x005DC394, source:raw]
    // CALL: aInstance keyword: match with sub_559E20; if a nested scene node definition follows, recurse as SceneNode(v48, v8, a4) and return -1 on failure. [callee:0x00559E20, global:0x005CD620, callee:0x0055A910, source:raw]
    // CALL: aMeshfile keyword: copy the mesh path via SelfCopyStringWithValidation(v8, a2, v48) (return -1 on failure), then walk the mesh list at v8+516 to its tail, tracking the last node in v4. [callee:0x00559E20, global:0x005CD614, callee:0x0054A730, source:raw]
    // CALL: aAnimfile keyword: resolve the animation name through sub_5518A0(this, &v34, v48, 0) (return -1 on failure); read the aAutostart keyword and compare to aTrue to set the v36 autostart flag. [callee:0x00559E20, global:0x005DC388, global:0x005DC37C, global:0x005C596C, callee:0x005518A0, source:raw]
    // LOOP: Animation list walk at v31+516: scan nodes with sub_551560; when autostart (v36) is set, remove the matching animation entry with LinkedListStringKeyRemoval(v4, v34 + 28); return -1 if a matching node is found. [callee:0x00551560, callee:0x00551790, source:raw]
    // CALL: Animation registration: add the animation to the node via UIListNodeManager(v31, v34) (return -1 on failure); if autostart, flag the audio handle at v31+532 with AudioFlagSet. [callee:0x0054BB40, callee:0x00551480, source:raw]
    // CALL: aLodin keyword: parse a LOD-in distance with PRNG4UniformFloatsFromSeed(a4, aLodin, &v40, 0, 0, 0); on success apply it via ConditionalFloatFieldSetter(v4, v40, -1.0). [callee:0x00559FB0, global:0x005CD60C, callee:0x0054D4E0, source:raw]
    // CALL: aLodout keyword: parse a LOD-out distance with PRNG4UniformFloatsFromSeed(a4, aLodout, &v38, 0, 0, 0); on success apply it via ConditionalFloatFieldSetter(v4, -1.0, v38). [callee:0x00559FB0, global:0x005CD604, callee:0x0054D4E0, source:raw]
    // ASSIGNMENT: aHattarget keyword: set or clear bit 0x100 in the current node's +20 flag dword depending on whether the value equals aTrue. [callee:0x00559E20, global:0x005DC370, source:raw]
    // ASSIGNMENT: aColltarget keyword: set or clear bit 0x40 in the current node's +20 flag dword depending on aTrue. [callee:0x00559E20, global:0x005DC364, source:raw]
    // ASSIGNMENT: aSpheretarget keyword: set or clear bit 0x80 in the current node's +20 flag dword depending on aTrue. [callee:0x00559E20, global:0x005DC354, source:raw]
    // ASSIGNMENT: aZbuffer keyword: clear or set bit 0x2000 in the current node's +20 flag dword depending on aTrue (inverted: true clears it). [callee:0x00559E20, global:0x005DC34C, source:raw]
    // CALL: aShadowcaster keyword: if true and not already handled (v35), insert the current node with LinkedListNodeInsert_5930(this, v4, a3) (return -1 on failure) and set the v35 guard. [callee:0x00545930, global:0x005DC33C, source:raw]
    // CALL: aShadowobject keyword: if true and not already handled (v35), insert with LinkedListNodeInsert_5930(this, v4, a3) (return -1 on failure), OR bit 0x2000000 into the +20 flags, and set the v35 guard. [callee:0x00545930, global:0x005CD5F4, source:raw]
    // STATE_TRANSITION: aShadowreceiver keyword: on true OR bit 0x4000 into the +20 flags and increment the container's shadow-receiver count this[79]; on false clear bit 0x4000. [callee:0x00559E20, global:0x005DC32C, field:this:0x0000013C, source:raw]
    // STATE_TRANSITION: aReflector keyword: on true OR bit 0x20000 into the +20 flags and increment the container's reflector count this[93]; on false clear bit 0x20000. [callee:0x00559E20, global:0x005DC320, field:this:0x00000174, source:raw]
    // ASSIGNMENT: aMorphtarget keyword: if true, OR bit 0x200000 into the current node's +20 flags. [callee:0x00559E20, global:0x005DC314, source:raw]
    // CALL: aLightobject keyword: read the token value into v47 with sub_559E20; the parsed value is not used further. [callee:0x00559E20, global:0x005DC308, source:raw]
    // CALL: View orientation (vtable): parse three floats through PRNG4UniformFloatsFromSeed(a4, &off_5DC230, &v43, &v41, &v39, 0); on success set the v37 flag. [callee:0x00559FB0, global:0x005DC230, source:raw]
    // CALL: aOrient keyword: parse three floats through PRNG4UniformFloatsFromSeed(a4, aOrient, &v44, &v45, &v42, 0); on success set the v37 flag. [callee:0x00559FB0, global:0x005DC228, source:raw]
    // ASSIGNMENT: aMoveable keyword: set or clear bit 0x10 in the scene node's +60 flags depending on aTrue. [callee:0x00559E20, global:0x005DC2FC, source:raw]
    // ASSIGNMENT: aStamp keyword: on true OR bits 0x100|0x10 into the scene node's +60 flags; on false clear bit 0x100. [callee:0x00559E20, global:0x005DC2F4, source:raw]
    // ASSIGNMENT: aBillboard keyword: on true OR bits 0x2000|0x10 into the scene node's +60 flags; on false clear bit 0x2000. [callee:0x00559E20, global:0x005DC2E8, source:raw]
    // ASSIGNMENT: aRender keyword: on true clear bit 4 of the scene node's +60 flags; on false set bit 4. [callee:0x00559E20, global:0x005DC2E0, source:raw]
    // ASSIGNMENT: aChange keyword: on true clear bit 0x200 of the scene node's +60 flags; on false set bit 0x200. [callee:0x00559E20, global:0x005DC2D8, source:raw]
    // CALL: aSpecial1 keyword: parse an int with sub_559F00 into v33, then apply it with RenderFlagSetter(v31, v33, 2048). [callee:0x00559F00, global:0x005DC2CC, callee:0x0054C110, source:raw]
    // CALL: aSpecial2 keyword: parse an int with sub_559F00 into v33, then apply it with RenderFlagSetter(v31, v33, 4096). [callee:0x00559F00, global:0x005DC2C0, callee:0x0054C110, source:raw]
    // ASSIGNMENT: aPlanes keyword: parse an int with sub_559F00 into v33 and store it at scene node +80. [callee:0x00559F00, global:0x005DC2B8, source:raw]
    // CALL: aActor keyword: copy the actor name into v47 and register it via sub_559820(v31, v47, 0). [callee:0x00559E20, global:0x005CD46C, callee:0x00559820, source:raw]
    // CALL: aHatactor keyword: copy the hat-actor name into v47 and register it via sub_559820(v31, v47, 1). [callee:0x00559E20, global:0x005DC2AC, callee:0x00559820, source:raw]
    // CALL: aResponse keyword: copy the response name into v47 and its payload into v49, then dispatch via sub_5598B0(v31, v47, v49). [callee:0x00559E20, global:0x005DC2A0, callee:0x005598B0, source:raw]
    // CALL: LABEL_120 (a4 == 2 path): re-read the next line with LineReaderFromBuffer(a4); if it returns 1 jump to the finish path. [callee:0x00559A70, source:raw]
    // STATE_TRANSITION: Visgroup continuation after aVisgroups match: if (v46 & dword_8B8EE0) == v46, store the mask at scene node +56 and resume the token loop; otherwise skip the remaining lines. [global:0x008B8EE0, source:raw]
    // CALL: Visgroup rejection path: drain lines until *a4 == 3 or LineReaderFromBuffer returns 1, then run TwoFunctionCallChain() and free the scene node with FreeWrapper_7bcf(v31); return 0. [callee:0x0054A710, callee:0x00587BCF, callee:0x00559A70, source:raw]

    // Conservative worker pseudocode:
    //   InterlockedDecrement(&dword_8B8EE8); AudioVolumeLoadComputation(0);
    //   node = new(572); if (node) node = construct(node);
    //   node[15] = 0; node[16] = parent; if (parent) node[15] = 8;
    //   if (readLine() == 1) goto finish;
    //   loop:
    //     if (*buf == 3) goto finish;
    //     if (*buf == 2) goto reread;
    //     if (match(visgroups, &mask)) { if ((mask & dword_8B8EE0) == mask) { node[56] = mask; continue; } drain(); cleanup(); return 0; }
    //     if (match(instance, s) && SceneNode(s, node, buf) == -1) return -1;
    //     if (match(meshfile, s)) { if (copyString(node, a2, s) == -1) return -1; v4 = tail(node[516]); }
    //     ... (keyword/flag apply: hat/coll/sphere/zbuffer/shadow* /reflector/morph/light/view/orient/move/stamp/billboard/render/change/special1/2/planes/actor/hatactor/response) ...
    //   reread: if (readLine() == 1) goto finish;
    //   finish:
    //     for (c = node[129]; c; c = c[4]) c[63] = node[20];
    //     if (parent) DoublyLinkedListNodeMover(parent, node, 0); else ActorNodeLinkedListAppend(this, node);
    //     if (viewFlag) sub_54B4D0(node, z, y, x, yaw, pitch, roll);
    //     return 0;
    // UNRESOLVED: Node layout offsets beyond the packet field table (v6[15], v6[16], v6[20], v6[129], +516 mesh list, +532 audio handle, +20 flag dword, +60 flags, +56 visgroup mask, +80 planes) are DERIVED from the decompilation, not packet facts.
    // UNRESOLVED: Bit flags (0x100 hat, 0x40 coll, 0x80 sphere, 0x2000 zbuffer, 0x2000000 shadowobject, 0x4000 shadowreceiver, 0x20000 reflector, 0x200000 morphtarget, 0x10/0x110/0x2010/4/0x200 at +60) are raw literals from the source with no named semantics in the packet.
}
