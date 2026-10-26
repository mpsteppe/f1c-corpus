## SceneNode_0055a910 — SceneNodeParser

**Summary:** Parses a scene file node definition from a line buffer, creating a 572-byte scene graph node and populating its properties (mesh file, animations, visibility groups, shadow/render flags, LOD distances, collision targets, view orientation) by matching keyword-value pairs from the scene description. Appends the constructed node into the scene graph via linked list operations. Part of the scene file loading/parsing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13C | R | — | shadow receiver count (this+316 = this[79]), incremented for each shadowreceiver=true node |
| this | 0x174 | R | — | reflector count (this+372 = this[93]), incremented for each reflector=true node |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e234 | InterlockedDecrement | R | InterlockedDecrement function pointer — atomically decrements dword_8B8EE8 for audio buffer sync |
| 005c596c | aTrue | R | sTrue [DERIVED] |
| 005cd46c | aActor | R | StrActor [DERIVED] |
| 005cd5f4 | aShadowobject | R | ShadowObjectKey [DERIVED] |
| 005cd604 | aLodout | R | StringLODOut [DERIVED] |
| 005cd60c | aLodin | R | StringLODIn [DERIVED] |
| 005cd614 | aMeshfile | R | Key_MeshFile [DERIVED] |
| 005cd620 | aInstance | R | StringInstance [DERIVED] |
| 005dc228 | aOrient | R | String_Orient [DERIVED] |
| 005dc230 | off_5DC230 | R | ViewVTable [DERIVED] |
| 005dc2a0 | aResponse | R | ResponseString [DERIVED] |
| 005dc2ac | aHatactor | R | HatactorString [DERIVED] |
| 005dc2b8 | aPlanes | R | PlanesString [DERIVED] |
| 005dc2c0 | aSpecial2 | R | Str_Special2 [DERIVED] |
| 005dc2cc | aSpecial1 | R | StringSpecial1 [DERIVED] |
| 005dc2d8 | aChange | R | ChangeString [DERIVED] |
| 005dc2e0 | aRender | R | RenderString [DERIVED] |
| 005dc2e8 | aBillboard | R | BillboardString [DERIVED] |
| 005dc2f4 | aStamp | R | StampStr [DERIVED] |
| 005dc2fc | aMoveable | R | MoveableString [DERIVED] |
| 005dc308 | aLightobject | R | LightObjectField [DERIVED] |
| 005dc314 | aMorphtarget | R | StrMorphtarget [DERIVED] |
| 005dc320 | aReflector | R | String_Reflector [DERIVED] |
| 005dc32c | aShadowreceiver | R | ShadowReceiverString [DERIVED] |
| 005dc33c | aShadowcaster | R | ShadowcasterString [DERIVED] |
| 005dc34c | aZbuffer | R | ZBufferString [DERIVED] |
| 005dc354 | aSpheretarget | R | String_SphereTarget [DERIVED] |
| 005dc364 | aColltarget | R | aColltarget [DERIVED] |
| 005dc370 | aHattarget | R | HatTarget [DERIVED] |
| 005dc37c | aAutostart | R | AutostartField [DERIVED] |
| 005dc388 | aAnimfile | R | AnimFileString [DERIVED] |
| 005dc394 | aVisgroups | R | VisgroupsString [DERIVED] |
| 008b8ee0 | dword_8B8EE0 | R | AudioSystemFlags [DERIVED] |
| 008b8ee8 | dword_8B8EE8 | R | AudioBufferSize [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545250 | ActorNodeLinkedListAppend | appends the parsed scene node to the actor linked list in the scene graph root |
| 00545930 | LinkedListNodeInsert_5930 | inserts a node into a shadow-related linked list (shadowcaster/shadowobject registration) |
| 00545f50 | AudioVolumeLoadComputation | resets/initializes audio volume computation (called with 0) |
| 0054a600 | sub_54A600 | scene node constructor: allocates and initializes the 572-byte node struct |
| 0054a710 | TwoFunctionCallChain | cleanup teardown on early exit or error (frees resources) |
| 0054a730 | SelfCopyStringWithValidation | copies and validates the mesh file path string (append extension/directory) |
| 0054a770 | SceneGraph | builds/registers the scene graph for the node (called when node has no children) |
| 0054b4d0 | sub_54B4D0 | applies view direction and orientation (from v43/v41/v39 and v44/v45/v42) to the node transform |
| 0054ba00 | DoublyLinkedListNodeMover | moves the node within a doubly linked list (used when a3 parent is specified) |
| 0054bb40 | UIListNodeManager | manages a UI list node entry for animation file references |
| 0054c110 | RenderFlagSetter | sets render flags (2048/4096) on the node for Special1/Special2 keywords |
| 0054d4e0 | ConditionalFloatFieldSetter | conditionally sets LOD float fields on the leaf sub-object (v4) |
| 00551480 | AudioFlagSet | sets audio-related flag on animation data at v31+532 |
| 00551560 | sub_551560 | checks if an animation with given string key already exists in the linked list |
| 00551790 | LinkedListStringKeyRemoval | removes an entry from a string-keyed linked list (autostart override removal) |
| 005518a0 | sub_5518A0 | resolves/registers an animation file path string, storing result in v34 |
| 00559820 | sub_559820 | processes actor/hatactor string reference and associates with node (param: 0=actor, 1=hatactor) |
| 005598b0 | sub_5598B0 | processes response key-value data and attaches to node |
| 00559a70 | LineReaderFromBuffer | reads next token/line from the scene file buffer; returns 1 at end-of-block |
| 00559e20 | sub_559E20 | parses a keyword=string_value pair from the current line into v48 buffer; returns 1 if matched |
| 00559f00 | sub_559F00 | parses a keyword=integer_value pair from the current line into output int; returns 1 if matched |
| 00559fb0 | PRNG4UniformFloatsFromSeed | parses up to 4 float values from the current line; returns 1 if keyword matched |
| 0055a910 | SceneNode | recursive call: parses a nested instance sub-node from the same buffer |
| 00587bcf | FreeWrapper_7bcf | frees dynamically allocated memory (used to free node on error/early exit) |
| 00587c03 | OperatorNewNhMallocWrapper | heap memory allocation (572 bytes for scene node) |

**Guard conditions:** The outer loop reads lines via LineReaderFromBuffer: token type 3 (end-of-block) exits the loop and processes the completed node; token type 2 skips the current line. The visgroups check (sub_559F00 for visgroups): if the parsed visgroups mask v46 does not match dword_8B8EE0 (audio system flags), the entire node is discarded — TwoFunctionCallChain + FreeWrapper_7bcf called, returns 0. Each keyword property is gated by its respective parser returning true (sub_559E20/sub_559F00/PRNG4UniformFloatsFromSeed). Boolean properties (hattarget, colltarget, spheretarget, zbuffer, shadowreceiver, reflector, morphtarget, moveable, stamp, billboard, render, change) compare the parsed string against "true" via strcmp to determine whether to set or clear the corresponding bitflag. Shadowcaster and shadowobject nodes are additionally gated by v35==0 (only one shadow registration per node). The meshfile keyword copies the path via SelfCopyStringWithValidation and advances v4 to the last leaf node. The animfile keyword resolves the path and registers it; autostart=true sets v36=1 which triggers LinkedListStringKeyRemoval if animation already exists. When LineReaderFromBuffer returns 1 (normal exit), the completed node is appended: if v6[129] is non-null, iterates the child linked list setting back-references (v29+252 = v6[20]), then either DoublyLinkedListNodeMover (with parent a3) or ActorNodeLinkedListAppend; if v6[129] is null, calls SceneGraph + TwoFunctionCallChain + FreeWrapper_7bcf (node has no renderable mesh — likely cleanup). v37 flag triggers sub_54B4D0 to apply view/orient transform.
