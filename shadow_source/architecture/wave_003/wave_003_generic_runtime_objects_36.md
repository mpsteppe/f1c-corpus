# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups 17 runtime-object routines from the render/scene/UI path. CreateRenderElement (0x00557CE0) builds a render element from a config descriptor: it allocates a 128-byte-stride element slot array at +0x34 whose per-slot layout is installed by ColorStateInit (0x005573A0), builds a 68-byte control object at +0x50 holding a sub-object, vertex and index buffers, and fills 36-byte vertex records in per-element or shared-static modes. ResourceNodeCleanup (0x005574B0) is the matching teardown: it frees the element array, the four auxiliary buffers at +0x3C/+0x40/+0x44/+0x48, the control's sub-resources, and an audio resource gated on a flag bit. WritePixelAttributeToTexture (0x00558DC0) writes a pixel dword into the control's texture buffer guarded by mode +0x4C and flags +0x20. ListNodeAllocateAndAppend (0x00559200) allocates a 108-byte node (initialized by 0x00557410 with 1.0f/100.0f defaults and node links at +0x64/+0x68) and appends it to a container's tail (count +0x144, head +0x148). The scene-file path parses a MAS file (0x0055B200) writing fog/ambient state and recursing into sub-parsers; SceneLinePropertyLookup (0x00559E20) extracts key=value pairs from the line-reader stream; CountMeshFilesInSceneFile (0x0055B8C0) scans Instance blocks for MeshFile entries. ResourceLookupAndBind (0x00559820) and ActorResponseLinkAllocate (0x005598B0) resolve names against the global resource list and bind them into a SceneNode-style object. RenderStateBufferAllocAndCopy (0x0055D720) allocates and fills a DirectX-style vertex buffer for a render state. All class identities beyond the packet's RenderElement owner are conservative GUESS/DERIVED proposals; equal byte offsets on different `this` bases are never merged.

## Function roles

- `0x005573A0` **RenderElementSlot** — Per-slot color/transform initializer: zeroes the slot, installs a 4x4 identity transform at +0x4 and a white (0xFFFFFF) color at +0xC; used to fill render-element slots at 128-byte strides
- `0x00557410` **ListNodeObject** — List-node constructor: GlobalZeroInit then explicit zeroes of +0x0 and +0x20..+0x50, three 1.0f defaults at +0x54..+0x5C and a 100.0f bound at +0x60; node links at +0x64/+0x68
- `0x005574B0` **RenderElementObject** — Render-element teardown: frees element array at +0x34, control sub-resources at +0x50, the four buffers +0x3C/+0x40/+0x44/+0x48, and an audio resource gated on flag bit 8 at +0x20; invoked from doubly-linked-list node removal
- `0x00557CE0` **RenderElementObject** — Render-element constructor from a configuration descriptor: resolves the shared game object, creates the resource, builds the element slot array at +0x34, the 68-byte control object at +0x50, vertex/index buffers, and selects 2D/3D sizing paths
- `0x00558DC0` **RenderElementObject** — Guarded pixel-attribute write into the control object's texture buffer; gated on mode +0x4C equal to 1 and negative flags byte +0x20, writes the pixel dword into the texture buffer via +0x50 +0x20
- `0x00559200` **ListNodeContainer** — Allocates a 108-byte list node, zero-initializes via 0x00557410, validates it, and appends it to the container's tail (head at +0x148, count at +0x144); node next +0x68, back-pointer +0x64
- `0x00559330` **SmallListNode** — Small node-type initializer: GlobalZeroInit plus explicit zeroes at +0x0, +0x14, +0x18, +0x1C; called by near-neighbor list routines and LinkedListNodeSearchAllocation
- `0x005593B0` **SmallStructZeroInit** — Small struct zero-initializer: GlobalZeroInit then explicit zeroes of the three leading dwords +0x0/+0x4/+0x8
- `0x005593D0` **DirectXObjectContainer** — Frees three singly-linked lists rooted at +0x0/+0x4/+0x8 (node next at +0x1C) via EmptyStub_7470 + FreeWrapper_7bcf and nulls the heads; used in DirectX object teardown
- `0x00559820` **SceneNode** — Name-based actor/resource lookup against the global list dword_8B8F2C; on success stores node at +0x220 and caller value at +0x21C, on failure formats and reports an error returning -1
- `0x005598B0` **SceneNode** — Links an actor name to a response name: searches actor list and response tree, resolves/creates a mapping node via LinkedListNodeSearchAllocation, and appends an 8-byte node (value + next) to the list at +0x224
- `0x00559E20` **LineReader** — Scene line property lookup and key=value extraction: counts '=' in the line buffer at +0xC, dispatches on line shape, copies the lookup result from +0x30C into the scratch at +0x18C and collapses the value substring into caller buffers
- `0x0055B200` **SceneDefinition** — Top-level scene (MAS) file parser: reads the file, dispatches directives (includefile, searchpath, groupmethod, fontfile, masfile, ambientcolor, fogmode/fogcolor/fogin/fogout/fogdensity, view/group/instance/light) writing fog state and recursing into sub-parsers
- `0x0055B8C0` **SceneFileUtility** — Counts MeshFile entries inside Instance blocks of a scene file: opens the file directly or via the search-directory array, reads it, scans the line-reader stream, increments the output counter and reports 'Illegal scene file name' on failure
- `0x0055D200` **RenderGraphNode** — Constructor: GlobalZeroInit of the base sub-object then explicit zeroes of +0x0 and +0x14..+0x30; render/graph-node style object used by drawable/managed/vertex-buffer callers
- `0x0055D230` **ConfigDefaultsStruct** — Constructor: tag value 384 at +0x0, nine 1.0f defaults at +0x14..+0x34, -1.0f sentinel at +0x48, plus explicit zeroes; a default-bound struct
- `0x0055D720` **RenderStateVertexBuffer** — Allocates and fills a DirectX-style vertex buffer for a render state: complex vs simple path by getter on dword_8B78A0, buffer allocation via BufferLockAllocate, vertex-data copy from +0xC to +0x8, and mode dispatch on +0x0

## Proposed classes

### RenderElementObject

Render element produced from a configuration descriptor: owns the element slot array, four auxiliary buffers, and a 68-byte control object; provides teardown and texture-write behavior.

Methods: `0x00557CE0`, `0x005574B0`, `0x00558DC0`

- `this+0x00000020` `u32 flags render_flags` (read_write, DERIVED)
- `this+0x00000024` `u32 vertex_stride` (read_write, DERIVED)
- `this+0x00000028` `u32 vertex_count_factor` (read_write, GUESS)
- `this+0x0000002C` `u32 element_count` (read_write, DERIVED)
- `this+0x00000034` `ptr to slot array (128-byte stride, count header at base-4) element_array` (read_write, DERIVED)
- `this+0x0000003C` `ptr aux_buffer_a` (read_write, GUESS)
- `this+0x00000040` `ptr aux_buffer_b` (read_write, GUESS)
- `this+0x00000044` `ptr aux_buffer_c` (read_write, GUESS)
- `this+0x00000048` `ptr aux_buffer_d` (read_write, GUESS)
- `this+0x0000004C` `u32 (set to 1; read as render mode in WritePixel and as control-array count in teardown) usage_and_mode` (read_write, DERIVED)
- `this+0x00000050` `ptr to RenderElementControl control_object` (read_write, DERIVED)

### RenderElementSlot

Per-element record inside the render element slot array; initialized by ColorStateInit with an identity transform and a white color, then per-element index/color fields are written.

Methods: `0x005573A0`

- `this+0x00000000` `u32 field_0` (write, GUESS)
- `this+0x00000004` `float[16] 4x4 identity matrix block transform_identity4` (write, GUESS)
- `this+0x00000008` `u32 field_8` (write, GUESS)
- `this+0x0000000C` `u32 (0xFFFFFF white/opaque literal) color_literal` (write, DERIVED)
- `this+0x00000078` `u32 field_78` (write, GUESS)
- `this+0x0000007C` `u32 field_7C` (write, GUESS)

### RenderElementControl

68-byte control object at RenderElementObject+0x50: first dword is a count/control word, +0x4 holds the sub-object, +0x8/+0x10 count fields, +0xC/+0x14 vertex and index buffers, +0x20 the texture buffer base.

Methods: 

- `*(this+0x50)+0x00000000` `u32 (set to 1; rebuilt from config flag bits) control_word` (read_write, DERIVED)
- `*(this+0x50)+0x00000004` `ptr (sub-object from sub_548890, retained, freed in teardown) sub_object` (read_write, DERIVED)
- `*(this+0x50)+0x00000008` `u32 (4*count or 8*count) vertex_count_field` (read_write, GUESS)
- `*(this+0x50)+0x0000000C` `ptr vertex_buffer` (read_write, DERIVED)
- `*(this+0x50)+0x00000010` `u32 index_count_field` (read_write, GUESS)
- `*(this+0x50)+0x00000014` `ptr index_buffer` (read_write, DERIVED)
- `*(this+0x50)+0x00000020` `ptr (texture buffer base read for pixel writes) texture_buffer_base` (read, DERIVED)

### RenderElementSubObject

Sub-object at RenderElementControl+0x4; exposes a count field and an element-list pointer configured from config dwords.

Methods: 

- `*(*(this+0x50)+0x4)+0x000000A4` `u32 (guard > 0) count_field` (read, GUESS)
- `*(*(this+0x50)+0x4)+0x000000A8` `ptr element_list_pointer` (read_write, GUESS)

### VertexRecordData

Content written into the vertex buffer at RenderElementControl+0xC: repeated 36-byte vertex records of float constants and ARGB colors (second record starts at 0x24, its color at 0x3C).

Methods: 

- `*(*(this+0x50)+0xC)+0x00000000` `float float_coord_0` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x00000004` `float float_coord_1` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x00000008` `float float_coord_2` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x00000018` `u32 ARGB color argb_color` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x00000024` `float (record 2, offset 0) float_coord_second_0` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x00000028` `float (record 2, offset 4) float_coord_second_1` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x0000002C` `float (record 2, offset 8) float_coord_second_2` (write, GUESS)
- `*(*(this+0x50)+0xC)+0x0000003C` `u32 ARGB color (record 2, offset 0x18) argb_color_second` (write, GUESS)

### ListNodeObject

108-byte list node initialized by 0x00557410 with 1.0f defaults and a 100.0f bound; carries next pointer at +0x68 and back-pointer at +0x64 for container append.

Methods: `0x00557410`

- `this+0x00000000` `byte byte_0_flag` (write, GUESS)
- `this+0x00000020` `u32 zeroed_dword_8` (write, GUESS)
- `this+0x00000024` `u32 zeroed_dword_9` (write, GUESS)
- `this+0x00000028` `u32 zeroed_dword_10` (write, GUESS)
- `this+0x0000002C` `u32 zeroed_dword_11` (write, GUESS)
- `this+0x00000030` `u32 zeroed_dword_12` (write, GUESS)
- `this+0x00000034` `u32 zeroed_dword_13` (write, GUESS)
- `this+0x00000038` `u32 zeroed_dword_14` (write, GUESS)
- `this+0x0000003C` `u32 zeroed_dword_15` (write, GUESS)
- `this+0x00000040` `u32 zeroed_dword_16` (write, GUESS)
- `this+0x00000044` `u32 zeroed_dword_17` (write, GUESS)
- `this+0x00000048` `u32 zeroed_dword_18` (write, GUESS)
- `this+0x0000004C` `u32 zeroed_dword_19` (write, GUESS)
- `this+0x00000050` `u32 zeroed_dword_20` (write, GUESS)
- `this+0x00000054` `float 1.0f default_float_1` (write, DERIVED)
- `this+0x00000058` `float 1.0f default_float_2` (write, DERIVED)
- `this+0x0000005C` `float 1.0f default_float_3` (write, DERIVED)
- `this+0x00000060` `float 100.0f max_bound` (write, DERIVED)
- `this+0x00000064` `ptr to previous node back_pointer` (read_write, DERIVED)
- `this+0x00000068` `ptr to next node next_pointer` (read_write, DERIVED)

### ListNodeContainer

List container (the `this` of 0x00559200): maintains node count at +0x144 and head at +0x148; appends 108-byte nodes. Field +0x1B0 has no direct raw occurrence and is unresolved.

Methods: `0x00559200`

- `this+0x00000144` `u32 node_count` (read_write, DERIVED)
- `this+0x00000148` `ptr to ListNodeObject list_head` (read_write, DERIVED)

### SceneDefinition

Scene definition object that ParseSceneFileTopLevel fills from a MAS file: fog color/mode/in/out/density fields plus ambient color via the UI-refresh setter.

Methods: `0x0055B200`

- `this+0x00000188` `word fog_blue` (write, DERIVED)
- `this+0x0000018A` `word fog_green` (write, DERIVED)
- `this+0x0000018C` `word fog_red` (write, DERIVED)
- `this+0x00000190` `float fog_density` (write, DERIVED)
- `this+0x00000194` `float fog_in_near` (write, DERIVED)
- `this+0x00000198` `float fog_out_far` (write, DERIVED)
- `this+0x0000019C` `u32 enum (0x20000 linear / 0x40000 exp / 0x80000 exp2) fog_mode` (write, DERIVED)

### LineReader

Line-reader stream state used by the scene parsers: line buffer at +0xC, scratch copy buffer at +0x18C, lookup-result string pointer at +0x30C; status byte at +0x0 with values 2 (skip) and 3 (end of stream).

Methods: `0x00559E20`

- `this+0x00000000` `byte (2=skip, 3=end of stream) line_status` (read, GUESS)
- `this+0x0000000C` `char* line_buffer` (read, GUESS)
- `this+0x0000018C` `char buffer (strcpy destination) scratch_buffer` (write, GUESS)
- `this+0x0000030C` `char* result string lookup_result_ptr` (read, GUESS)

### SceneNode

Scene/actor node object that binds named resources: stores a found node at +0x220 and a caller value at +0x21C, and owns the actor-to-response mapping list at +0x224.

Methods: `0x00559820`, `0x005598B0`

- `this+0x0000021C` `ptr (caller-supplied value) bound_value` (write, GUESS)
- `this+0x00000220` `ptr (found resource node) bound_node` (write, GUESS)
- `this+0x00000224` `ptr to MappingListNode head mapping_list_head` (read_write, DERIVED)

### MappingListNode

8-byte actor-to-response mapping node (value pointer + next pointer at +0x4); appended to the SceneNode mapping list at +0x224.

Methods: 

- `*(this+0x224)+0x00000004` `ptr next_pointer` (read_write, GUESS)

### RenderStateVertexBuffer

Render-state object backing a DirectX-style vertex buffer: mode flags at +0x0, source vertex data at +0xC copied into the destination buffer at +0x8, flags at +0x38, external state pointer at +0x4/+0xA0, lock field at +0x154.

Methods: `0x0055D720`

- `this+0x00000000` `u32 (bit 0x1 and 0x2 select dispatch routine) mode_flags` (read, DERIVED)
- `this+0x00000008` `ptr dest_vertex_buffer` (read_write, DERIVED)
- `this+0x0000000C` `ptr src_vertex_data` (read, DERIVED)
- `this+0x00000018` `ptr (external state sub-object) sub_object` (read, GUESS)
- `this+0x0000001C` `u32 alloc_size_arg` (read, GUESS)
- `this+0x00000020` `u32 bucket_count` (read, GUESS)
- `this+0x0000002C` `u32 (bit 0x400000 triggers refresh) state_word` (read, GUESS)
- `this+0x00000038` `u32 flags (0x100/0x200/0x400/0x800 bits) flags` (read_write, DERIVED)
- `this+0x000000A0` `byte (signed; negative gates sub_55EBA0) external_state_byte` (read, GUESS)
- `this+0x00000154` `u32 lock_field` (read, GUESS)

### RenderGraphNode

Render/graph-node object (constructed by 0x0055D200): zeroed base and +0x14..+0x30 range; used by drawable-object manager, sub_5491D0, and vertex-buffer transform paths.

Methods: `0x0055D200`

- `this+0x00000000` `u32 field_0` (write, GUESS)
- `this+0x00000014` `u32 field_14` (write, GUESS)
- `this+0x00000018` `u32 field_18` (write, GUESS)
- `this+0x0000001C` `u32 field_1C` (write, GUESS)
- `this+0x00000020` `u32 field_20` (write, GUESS)
- `this+0x00000024` `u32 field_24` (write, GUESS)
- `this+0x00000028` `u32 field_28` (write, GUESS)
- `this+0x0000002C` `u32 field_2C` (write, GUESS)
- `this+0x00000030` `u32 field_30` (write, GUESS)

### ConfigDefaultsStruct

Struct with default-bound configuration: tag 384 at +0x0, nine 1.0f defaults at +0x14..+0x34, -1.0f sentinel at +0x48, and explicit zeroed ranges.

Methods: `0x0055D230`

- `this+0x00000000` `u32 (384) tag_value` (write, DERIVED)
- `this+0x00000008` `u32 zeroed_dword_2` (write, GUESS)
- `this+0x0000000C` `u32 zeroed_dword_3` (write, GUESS)
- `this+0x00000010` `u32 zeroed_dword_4` (write, GUESS)
- `this+0x00000014` `float 1.0f default_float_5` (write, DERIVED)
- `this+0x00000018` `float 1.0f default_float_6` (write, DERIVED)
- `this+0x0000001C` `float 1.0f default_float_7` (write, DERIVED)
- `this+0x00000020` `float 1.0f default_float_8` (write, DERIVED)
- `this+0x00000024` `float 1.0f default_float_9` (write, DERIVED)
- `this+0x00000028` `float 1.0f default_float_10` (write, DERIVED)
- `this+0x0000002C` `float 1.0f default_float_11` (write, DERIVED)
- `this+0x00000030` `float 1.0f default_float_12` (write, DERIVED)
- `this+0x00000034` `float 1.0f default_float_13` (write, DERIVED)
- `this+0x00000038` `u32 zeroed_dword_14` (write, GUESS)
- `this+0x0000003C` `u32 zeroed_dword_15` (write, GUESS)
- `this+0x00000040` `u32 zeroed_dword_16` (write, GUESS)
- `this+0x00000044` `u32 zeroed_dword_17` (write, GUESS)
- `this+0x00000048` `float -1.0f sentinel_minus_one` (write, DERIVED)
- `this+0x0000004C` `u32 zeroed_dword_19` (write, GUESS)
- `this+0x00000050` `u32 zeroed_dword_20` (write, GUESS)
- `this+0x00000054` `u32 zeroed_dword_21` (write, GUESS)
- `this+0x00000058` `byte zeroed_byte_88` (write, GUESS)
- `this+0x00000068` `u32 zeroed_dword_26` (write, GUESS)
- `this+0x0000006C` `u32 zeroed_dword_27` (write, GUESS)

### SmallListNode

Small node-type struct initialized by 0x00559330 (zeroed +0x0/+0x14/+0x18/+0x1C); used by near-neighbor list routines and LinkedListNodeSearchAllocation.

Methods: `0x00559330`

- `this+0x00000000` `byte field_0` (write, GUESS)
- `this+0x00000014` `u32 zeroed_dword_5` (write, GUESS)
- `this+0x00000018` `u32 zeroed_dword_6` (write, GUESS)
- `this+0x0000001C` `u32 zeroed_dword_7` (write, GUESS)

### SmallStructZeroInit

Small struct zero-initialized by 0x005593B0: three leading dwords +0x0/+0x4/+0x8 explicitly cleared after GlobalZeroInit; render-UI and mesh buffer loader init paths.

Methods: `0x005593B0`

- `this+0x00000000` `u32 field_0` (write, GUESS)
- `this+0x00000004` `u32 field_4` (write, GUESS)
- `this+0x00000008` `u32 field_8` (write, GUESS)

### DirectXObjectContainer

Container with three singly-linked list heads at +0x0/+0x4/+0x8, all freed by 0x005593D0 during DirectX resource cleanup.

Methods: `0x005593D0`

- `this+0x00000000` `ptr to SinglyListNode list_head_0` (read_write, DERIVED)
- `this+0x00000004` `ptr to SinglyListNode list_head_1` (read_write, DERIVED)
- `this+0x00000008` `ptr to SinglyListNode list_head_2` (read_write, DERIVED)

### SinglyListNode

Node of the three freed lists: next pointer at +0x1C.

Methods: 

- `obj+0x0000001C` `ptr next_pointer` (read, DERIVED)

### SceneFileUtility

Standalone scene-file utility: CountMeshFilesInSceneFile opens a scene file (directly or via the search-directory array byte_8B5A3C / count dword_8B8E30) and counts MeshFile entries inside Instance blocks.

Methods: `0x0055B8C0`


## Compatibility contracts

- **RenderElementConstructionContract** — A replacement must build, from a config descriptor, a render element exposing element count at +0x2C, an element slot array at +0x34 (128-byte stride, count header at base-4, per-slot init via ColorStateInit), four owned buffers at +0x3C/+0x40/+0x44/+0x48, a usage/mode word at +0x4C (set to 1), and a 68-byte control object at +0x50 whose +0x0 word is a count/control word, +0x4 sub-object, +0xC vertex buffer and +0x14 index buffer are populated; teardown frees these plus an audio resource gated on flag bit 8 at +0x20. Config flag bit 0x1 at descriptor +0x32 selects 2D and bit 0x2 selects 3D sizing; bit 0x80 selects per-element vs shared-static vertex fills.
- **ListContainerAppendContract** — A replacement list container must keep node count at +0x144 and head at +0x148; appending allocates a 108-byte node zero-initialized to 1.0f defaults at +0x54..+0x5C and a 100.0f bound at +0x60, links next at +0x68 and back-pointer at +0x64, increments the count, and returns 0 when the per-node VertexBufferResourceAllocation succeeds, -1 on validation failure (with the output pointer zeroed).
- **SceneFileParseErrorContract** — Scene-file parse/load failures must free the file buffer, report a formatted message through sub_53C590(-1, message), and return -1, while success frees the buffer and returns 0. Observable messages include 'Illegal scene file name %s', 'Could not find actor %s', and the misspelled 'Could not find resposne %s'.
- **FogStateFieldContract** — A scene definition object stores fog blue/green/red words at +0x188/+0x18A/+0x18C, fog density at +0x190, fog-in near at +0x194, fog-out far at +0x198, and a fog-mode enum (0x20000 linear / 0x40000 exp / 0x80000 exp2, default 0x80000) at +0x19C, parsed from fogmode/fogcolor/fogin/fogout/fogdensity directives.
- **ActorResponseMappingContract** — A replacement must resolve an actor name in the global resource list dword_8B8F2C and a response name in a binary tree, and append an 8-byte mapping node (value pointer + next at +0x4) to the list head at +0x224; any lookup failure formats an error and returns -1.

## Unresolved

- RenderElementObject +0x4C plays two roles in the packet: CreateRenderElement sets it to 1 as a usage/flag word, while ResourceNodeCleanup reads it as the element count of the control array at +0x50; whether these are one semantic or two is unresolved.
- The vertex buffer content offsets 0x24/0x28/0x2C/0x3C sit beyond the stated 36-byte vertex record; they are best read as the second 36-byte record (0x3C = 0x18 + 0x24) but the exact record layout is unconfirmed.
- RenderElementObject flag mapping (config a2+32/a2+88 bits to this+0x20 flags 0x200/0x210/0x220 and control+0x0 bits 1/2) is only partially decoded; names are by effect, not authoritative.
- Semantics of sub_547240 (dimension setter) and sub_548890 (sub-object factory) are taken from call context only.
- The vertex float literals (-0.5f / 0.5f / 0.05f and -0.05f) observed on vertex-data fields are interpreted as UV/position baselines but not confirmed.
- Offsets 0x18C on SceneDefinition (fog red WORD) and LineReader (scratch buffer) are byte-equal on different object bases; they are not proven to be the same object and are kept as separate fields per the no-merge rule.
- ListNodeContainer field +0x1B0 is listed in the packet but has no direct occurrence in raw source; the node next-pointer evidence is expressed through *(this+0x1B0)+0x68.
- The actor-response error format string is the misspelled 'Could not find resposne %s'; no dedicated global evidence ref is present for it in the packet.
- ParseSceneFileTopLevel writes fog-mode literals but the init literal 524288 (0x80000) for field 0x19C is recorded in the packet with no write in this function's raw code; it may be a struct default set elsewhere.
- RenderStateVertexBuffer fields at +0x10, +0x14, +0x24, +0x28, +0x30, +0x40, +0x44 are listed as accessed but do not appear in the visible function body; they likely configure the render-state object consumed by the dispatched routines.
- CountMeshFilesInSceneFile reads global 0x005C2D64 per the packet but it does not appear in the raw source text; its role is unestablished.
- Global dword_8B8F2C is read only as a list head; the element/string layout of its entries is not resolved from this packet.
- Class identities beyond RenderElementObject (the only DERIVED owner in the packet) are conservative GUESS proposals from call-context; equal byte offsets on unrelated `this` pointers are never treated as shared ownership.
- PRNG4UniformFloatsFromSeed (0x00559FB0) is used as a single-float parser despite its PRNG-oriented name.
- The exact behavior of sub_53C590 (error logging/handling) and sub_589901 (copy/trim variant) is external to these functions.
