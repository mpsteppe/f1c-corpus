# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-three functions covering four defensible object groupings. (1) SceneRegistryList: append/remove on the process-global doubly-linked registry whose head is global 0x008B8E20 and whose nodes link at byte offsets 0x86C (prev) and 0x870 (next). (2) VideoManager: a large this-object holding a display sub-object at +0x10FC, a secondary device/audio sub-object at +0x1100, surface/descriptor buffers at +0x1148/+0x114C, audio-channel config at +0x1170 and graphics state at +0x13DC/+0x13E0; its methods drive display-mode enumeration, surface-format negotiation with a three-attempt retry, flag-driven surface allocation, dirty-resource flushing, paired surface blits, index-buffer creation, audio-buffer format setup, texture-surface allocation and video-manager global/state setters. This-object sharing is proven by direct calls (0x53F720 calls 0x53F3F0; 0x53FED0 calls 0x53F720; 0x541470 calls 0x540F00); the rest of the membership is inferred from field-offset overlap and VidMan caller names. (3) CameraObject: camera/viewport projection state built by 0x542050 (FOV, frustum tangents, clip halves, projection/view matrices, far-corner term, flip flag) plus the small setters/getters 0x5423C0/0x542420/0x542460 that operate on it; 0x5423C0 provably forwards this to 0x542050 and 0x542420 forwards a1 to 0x542460. (4) SurfaceDescriptor / TextureDescriptorBlock: a flag-bit-selected surface descriptor (flags at +0x18, slot pointers +0x8..+0x14) and the 36-byte texture descriptor blocks initialized to 34/322/24/a2. All owner identities remain UNKNOWN at packet level; every class is a DERIVED grouping and the vtable slot semantics are inferred from dispatch patterns.

## Function roles

- `0x0053D340` **SceneRegistryList** — Append a node to the global registry doubly-linked list (head global 0x008B8E20, node links prev at +0x86C, next at +0x870): empty list makes the node the head with cleared links; non-empty walks the next chain to the tail and links it. Returns the new tail (or new head when the list was empty).
- `0x0053D3A0` **SceneRegistryList** — Unlink a node from the global registry doubly-linked list: patch the previous node's next and the next node's prev, advance the head global 0x008B8E20 when this node is the head, clear the node's own links at +0x86C/+0x870, and return the node pointer.
- `0x0053D400` **VideoManager** — Single-global setter: write argument into module global 0x008B8E4C and return it unchanged; used by the video-manager init (0x004FA320) and post (0x004FAC00) paths.
- `0x0053D4C0` **VideoManager** — Resource teardown helper: call GlobalResourceCleanup (0x0053C4D0) on the object at field this+0x0 and return -1 on non-zero result; otherwise free the object via FreeWrapper (0x00587BCF) and return 0. Caller VidMan_Exit (0x004FAD00) suggests video-manager shutdown.
- `0x0053D850` **VideoManager** — Release a sub-object of the owning object: call cleanup helper 0x00540760 unconditionally, then, when the sub-object at this+0x10FC is non-null, dispatch its vtable slot 2 (offset 8), store the return value into the object's vtable pointer at this+0x0, null this+0x10FC, and always return 0.
- `0x0053D970` **VideoManager** — Enumerate display modes of the sub-object at this+0x10FC: zero-fill the per-mode entry array (count at this+0x8, 0x43C bytes per entry), query the mode count via vtable slot 4, probe pixel formats via vtable slot 9, fetch mode info and framebuffer data via vtable slots 13 and 5, pack accepted mode records and hand them to 0x0053D8B0. Returns the mode count.
- `0x0053F3F0` **VideoManager** — Negotiate a surface format between an optional source surface and a destination capability block: normalize format ids via 0x0055C650/0x0055BDE0/0x0055C450, then run a three-attempt retry over surface-creation vtable slots 0x28/0x30 on this+0x10FC and 0x68 on this+0x1100 with format variants 71/77/80. On accept flag out+24 and return 0; after exhaustion report invalid parameter via 0x0053C590 and return -1.
- `0x0053F720` **VideoManager** — Flag-driven DirectX-style surface allocation: derive a surface format from a2[12] and this+0x110C via 0x0055C650, then, per flag bits in a2[6], issue create-surface vtable calls on the primary sub-object this+0x10FC (vtable+40) and the secondary this+0x1100 (vtable+108/+100/+80), selecting width/depth from this+0x13E8/this+0x13EC and remapping formats from capability flags at this+0x13A8. Optionally creates an audio emitter (0x00587C03 + 0x005426A0 stored at a2[1]) and post-processes via 0x0053F3F0 / 0x005404D0. Any vtable failure formats aCouldNotAlloca via 0x0058815F and reports via 0x0053C590, returning -1; otherwise returns 0.
- `0x0053FB80` **SurfaceDescriptor** — Flush/validate up to four optional vtable-backed resource slots on the descriptor a2, each selected by a flag bit in the flags dword at a2+24: bit 0x1 -> a2+8, bit 0x2 -> a2+12, bit 0x4 -> a2+16, bit 0x8 -> a2+20 (the a2+4 slot is only drained by 0x0053F6E0 when bit 0x40000 is set). Each non-null slot is flushed through its vtable slot 8; a non-zero return reports invalid parameter via 0x0053C590 and returns -1, otherwise the flag bit is cleared. Returns 0 when all active slots flush cleanly.
- `0x0053FC30` **SurfaceDescriptor** — Paired surface blit helper: resolve a source surface from descriptor a2 (vtable slot 60 when flags a2[6] have bits 0x4/0x8, direct pointer at a2[2]/a2[3] when flags 0x1/0x2), resolve the destination from descriptor a3 identically, call SurfaceBlitOperation 0x0050099C, store its result in *this and return -1 on non-zero; when flags include 0xC release the resolved surfaces through their vtable slot 8. Returns 0 on success.
- `0x0053FED0` **VideoManager** — Rendering compositing setup: pick an alpha from a4[6] flags (a4[13] | 0xFF000000 when bit 0x800 set, global 0x00800000-labeled path, else default -65281), lock the source via 0x005006D5 into this+0x0, when a6 is null fill surface fields and call 0x0055C450 / 0x0053F720, select the destination by the a5 mode (vtable slot 60 for modes 4/8, direct v6[2]/v6[3] for bits 1/2), run the compositing blit 0x005008E4, and release the surface for modes 4/8. Returns 0 on success, -1 on any failure.
- `0x00540050` **VideoManager** — Resource load helper: call 0x005006D5(a2, a3, &v9), store the status into this+0x0 and return -1 on failure; on success optionally copy result words v9[0]/v9[1] into outputs a4/a5 and, when a6 is non-null, call 0x0055C450(v9[4], 0, a6). Returns 0 on success.
- `0x005408F0` **VideoManager** — Graphics-config state setter on a _DWORD array (this): mode 0 clears this[1271] (0x13DC) and this[1272] (0x13E0) to 0, mode 1 sets both to 1, mode 2 sets this+0x13E0 to 2 and this+0x13DC to 1; other modes leave the fields untouched. Returns the mode argument. Only caller is VidMan_Enter.
- `0x00540F00` **VideoManager** — Allocate a buffer through the allocator object at a2[8] (vtable slot 44, offsets from the request struct): base flag 2048, raised to 2064 by request bit 0, and 0x2000/0x1000 selected by the allocation-type hint field this+0x13E0 when request bit 0x20 is set. Stores the allocation pointer into *this; returns 0 on success, otherwise increments the request failure counter a2[5] and returns the buffer ID. Null request or allocator return 0 early.
- `0x00540FC0` **VideoManager** — Create an index buffer through a virtual call at vtable offset 96 on the sub-object at this+0x1100: derive usage flags from a2[0] bits (0x2/0x10 -> 8, 0x20 -> 0x200), pass buffer size 2 * a2[1] with format id 101, store the result in *this. Returns 0 on success, or -1 after reporting via 0x0053C590 on null a2 or a failed creation.
- `0x00541090` **VideoManager** — Surface lock helper: when a2 is non-null, read its lock sub-object at a2+24 and invoke that sub-object's vtable method at offset 44 with doubled dimensions (2*a4, 2*a5), a status out-slot, and lock flags 2064 when bit 0 of a2's first byte is set, else 2048. Store the call result in this+0; on non-zero return 0, otherwise increment the lock/ref counter at a2+12 and return the out-slot value.
- `0x00541120` **VideoManager** — Configure the audio buffer format on the audio sub-object: guard on a config object a3 with non-zero dword at a3+32, optionally tear down a pending buffer via vtable slot 148 and enter state 7 via vtable slot 200 on the sub-object at this+0x1100, decode format flags a7/a8 into the channel-config field this+0x1170, dispatch through 0x00554F80/0x00554790/0x005546A0/0x00553FA0/0x00554700, set the format via vtable slot 280 (sample rate buffered or divided by 3), and restore the saved state field this+0x13B8 through vtable slot 200.
- `0x00541340` **VideoManager** — Texture surface descriptor allocation and creation: allocate 76 bytes via 0x00587C03, mark the header 2, zero two 9-DWORD (36-byte) descriptor blocks, store the first block pointer at this+0x114C, fill both blocks with the constants 34 (header), 322 (+4), 24 (+8) and the a2 argument (+12; second block at +36/+40/+44/+48), and call 0x00540DF0 once per block, returning -1 if either fails and 0 on success.
- `0x00541470` **VideoManager** — Conditionally lock a 96-byte region of an audio buffer for writing: read the buffer base at this+0x114C; when non-null compute buffer_base + 36 * this[0x1148] and call 0x00540F00(this, target, 96, 0, 0). Returns the lock result, or 0 immediately when the buffer pointer is null.
- `0x00542050` **CameraObject** — Rebuild camera/viewport projection state: store horizontal FOV at this+0x6C and vertical FOV at this+0x70 (from a3 when a4 is non-zero, else aspect-corrected from globals 0x008B8DD8/0x008B8DD4), store frustum tangents at this+0x1C/0x20, clip-plane halves at this+0x0C/0x10 from viewport dimensions at this+0x54/0x58, fill projection-matrix tail this+0xDC..0xF8 and view-rotation matrix this+0x9C..0xD8 from sin/cos of half FOVs, write the far-corner distance at this+0x78, negate this+0x0C when the flags byte at this+0x80 has bit 0x10, and return that flags byte.
- `0x005423C0` **CameraObject** — Small thiscall setter: store the first argument into this+0x4 and the second into this+0x8, then call 0x00542050(this, float at this+0x6C, float at this+0x70, 1) and return its result. Called by nine camera/car-selection sites.
- `0x00542420` **CameraObject** — Thin delegation: call 0x00542490(a4, a5, a6) and discard its result, then return the result of 0x00542460(a1, a2, a3); all six arguments pass through unchanged. Called by MainCameraDirectorUpdate (0x0040CA30) and 0x00466350.
- `0x00542460` **CameraObject** — Thiscall triple-field getter: write this+0x24 to *a2, this+0x28 to *a3 and this+0x2C to *a4, each output pointer individually null-guarded; returns a4. Called by camera/geometry sites (0x0040CA30, 0x004DC960, 0x004FBD70) and by 0x00542420.

## Proposed classes

### SceneRegistryList

Process-global registry doubly-linked list. Head pointer is global 0x008B8E20; nodes carry prev/next links at byte offsets 0x86C/0x870. The two functions are list operations that take a node as their this argument; the node payload layout beyond the two links is undefined.

Methods: `0x0053D340`, `0x0053D3A0`

- `this+0x0000086C` `void* prev_link` (read_write, DERIVED)
- `this+0x00000870` `void* next_link` (read_write, DERIVED)

### VideoManager

Central video/surface/audio manager object. Holds the display sub-object at +0x10FC, a secondary device/audio sub-object at +0x1100, surface/descriptor buffer pointers at +0x1148/+0x114C, audio channel-config at +0x1170, capability flags at +0x13A8, saved-state/pending-init fields at +0x13B8/+0x13CC, graphics state at +0x13DC/+0x13E0 and width/depth formats at +0x13E8/+0x13EC. Membership is proven for the 0x53F3F0/0x53F720/0x53FED0 and 0x540F00/0x541470 this-sharing chains; other members are inferred from field-offset overlap and VidMan caller labels. The this+0x0 field is a result/status slot reused by nearly every member.

Methods: `0x0053D4C0`, `0x0053D850`, `0x0053D970`, `0x0053F3F0`, `0x0053F720`, `0x0053FED0`, `0x00540050`, `0x005408F0`, `0x00540F00`, `0x00540FC0`, `0x00541090`, `0x00541120`, `0x00541340`, `0x00541470`

- `this+0x00000000` `int status_result_slot` (read_write, DERIVED)
- `this+0x00000008` `int mode_entry_count` (read_write, DERIVED)
- `this+0x000010FC` `void* display_subobject` (read, GUESS)
- `this+0x00001100` `void* secondary_device_subobject` (read, GUESS)
- `this+0x0000110C` `int default_surface_format` (read, GUESS)
- `this+0x00001148` `int buffer_sub_index` (read, GUESS)
- `this+0x0000114C` `void* buffer_or_descriptor_ptr` (read_write, GUESS)
- `this+0x00001170` `int audio_channel_config` (write, GUESS)
- `this+0x000013A8` `int surface_capability_flags` (read, GUESS)
- `this+0x000013B8` `int saved_state_field` (read, GUESS)
- `this+0x000013CC` `int pending_init_flag` (read_write, GUESS)
- `this+0x000013DC` `int graphics_state_field_a` (write, DERIVED)
- `this+0x000013E0` `int graphics_state_field_b` (read_write, DERIVED)
- `this+0x000013E8` `int width_depth_format_a` (read, GUESS)
- `this+0x000013EC` `int width_depth_format_b` (read, GUESS)

### CameraObject

Camera/viewport projection object. Holds horizontal/vertical FOV at +0x6C/+0x70, near-plane values at +0x4/+0x8, viewport dimensions at +0x54/+0x58, frustum tangents at +0x1C/+0x20, clip-plane halves at +0x0C/+0x10, a far-corner term at +0x78, a flags byte at +0x80, and projection/view matrices at +0x9C..+0xF8. 0x5423C0 provably forwards this to 0x542050; 0x542420 forwards a1 to the 0x542460 getter, whose +0x24/+0x28/+0x2C triple is labeled position-orientation X/Y/Z by prior (DERIVED) analysis.

Methods: `0x00542050`, `0x005423C0`, `0x00542420`, `0x00542460`

- `this+0x00000004` `float near_plane_a` (read_write, DERIVED)
- `this+0x00000008` `float near_plane_b` (read, DERIVED)
- `this+0x0000000C` `float left_clip_half_width` (read_write, DERIVED)
- `this+0x00000010` `float top_clip_half_height` (read_write, DERIVED)
- `this+0x0000001C` `float horizontal_frustum_tan` (write, DERIVED)
- `this+0x00000020` `float vertical_frustum_tan` (write, DERIVED)
- `this+0x00000024` `float position_orientation_x` (read, GUESS)
- `this+0x00000028` `float position_orientation_y` (read, GUESS)
- `this+0x0000002C` `float position_orientation_z` (read, GUESS)
- `this+0x00000054` `int viewport_width` (read, DERIVED)
- `this+0x00000058` `int viewport_height` (read, DERIVED)
- `this+0x0000006C` `float horizontal_fov` (read_write, DERIVED)
- `this+0x00000070` `float vertical_fov` (read_write, DERIVED)
- `this+0x00000078` `float far_corner_distance` (write, GUESS)
- `this+0x00000080` `byte flags_byte` (read, DERIVED)
- `this+0x0000009C` `float view_rot_00` (write, DERIVED)
- `this+0x000000A0` `float view_rot_01` (write, DERIVED)
- `this+0x000000A4` `float view_rot_02` (write, DERIVED)
- `this+0x000000A8` `float view_rot_03` (write, DERIVED)
- `this+0x000000AC` `float view_rot_04` (write, DERIVED)
- `this+0x000000B0` `float view_rot_05` (write, DERIVED)
- `this+0x000000B4` `float view_rot_06` (write, DERIVED)
- `this+0x000000B8` `float view_rot_07` (write, DERIVED)
- `this+0x000000BC` `float view_rot_08` (write, DERIVED)
- `this+0x000000C0` `float view_rot_09` (write, DERIVED)
- `this+0x000000C4` `float view_rot_10` (write, DERIVED)
- `this+0x000000C8` `float view_rot_11` (write, DERIVED)
- `this+0x000000CC` `float view_rot_12` (write, DERIVED)
- `this+0x000000D0` `float view_rot_13` (write, DERIVED)
- `this+0x000000D4` `float view_rot_14` (write, DERIVED)
- `this+0x000000D8` `float view_rot_15` (write, DERIVED)
- `this+0x000000DC` `float proj_tail_00` (write, DERIVED)
- `this+0x000000E0` `float proj_tail_01` (write, DERIVED)
- `this+0x000000E4` `float proj_tail_02` (write, DERIVED)
- `this+0x000000E8` `float proj_tail_03` (write, DERIVED)
- `this+0x000000EC` `float proj_tail_04` (write, DERIVED)
- `this+0x000000F0` `float proj_tail_05` (write, DERIVED)
- `this+0x000000F4` `float proj_tail_06` (write, DERIVED)
- `this+0x000000F8` `float proj_tail_07` (write, DERIVED)

### TextureDescriptorBlock

36-byte texture-surface descriptor block created in pairs by 0x00541340: header constant 34, 322, 24 and the a2 argument at +4/+8/+12, mirrored at +36/+40/+44/+48 for the second block. The constant meanings (format enum, width, height) are not identified.

Methods: 

- `*(this+0x114C)+0x00000004` `int header_constant` (write, GUESS)
- `*(this+0x114C)+0x00000008` `int constant_322` (write, GUESS)
- `*(this+0x114C)+0x0000000C` `int descriptor_arg` (write, GUESS)
- `*(this+0x114C)+0x00000024` `int second_block_header_constant` (write, GUESS)
- `*(this+0x114C)+0x00000028` `int second_block_constant` (write, GUESS)
- `*(this+0x114C)+0x0000002C` `int second_block_constant_2` (write, GUESS)
- `*(this+0x114C)+0x00000030` `int second_block_descriptor_arg` (write, GUESS)

### SurfaceDescriptor

Flag-bit-selected surface descriptor. Evidence in the raw bodies (no formal packet field refs): flags dword at +0x18, slot pointers at +0x8/+0xC/+0x10/+0x14 (dword indices 2-5); flag bits 0x1/0x2 select a direct pointer, 0x4/0x8 resolve the surface through the object's vtable slot 60, and bits 0xC request a vtable-slot-8 release after use. The layout is not formalized as fields because the packet exposes only raw-source evidence for it.

Methods: `0x0053FB80`, `0x0053FC30`


## Compatibility contracts

- **RegistryDoublyLinkedListLayout** — A process-global head pointer (0x008B8E20) manages a doubly-linked list whose nodes carry prev/next links at byte offsets 0x86C and 0x870. Append (0x53D340) and unlink (0x53D3A0) must preserve that layout, the head advance rule, and the cleared-link invariant on the removed node.
- **SurfaceFormatRetryContract** — Surface creation retries format variants 71/77/80 across vtable slots 0x28/0x30 on the display sub-object and 0x68 on the secondary sub-object; on accept the output struct is flagged (out+24 |= 2) and 0 returned, and after exhaustion the invalid-parameter message (0x005DBCD0) is reported via 0x0053C590 and -1 returned.
- **DirtyResourceSlotFlushContract** — Up to four resource slots selected by flag bits at descriptor+0x18 flush through vtable slot 8 of each slot object; a non-zero flush return reports the invalid-parameter message (0x005DBCD0) via 0x0053C590 and aborts with -1, otherwise the flag bit is cleared.
- **AudioFormatStateRestoreContract** — Audio format setup saves the current state via this+0x13B8, enters state 7 through vtable slot 200 on the secondary sub-object, sets the format through vtable slot 280, and restores the saved state through vtable slot 200 again; the pending-init flag at this+0x13CC gates a vtable-slot-148 teardown of the prior buffer.
- **CameraProjectionStateContract** — The camera object maintains horizontal/vertical FOV at +0x6C/+0x70, viewport dimensions at +0x54/+0x58, near-plane values at +0x4/+0x8, a flags byte at +0x80 (bit 0x10 mirrors the frustum), projection/view matrices at +0x9C..+0xF8 and a far-corner term at +0x78; 0x542050 rebuilds the state and its callers must keep those fields coherent.

## Unresolved

- The VideoManager grouping is only partially proven: direct this-sharing calls link 0x53F3F0/0x53F720/0x53FED0 and 0x540F00/0x541470, but membership of 0x53D4C0, 0x53D400, 0x540050, 0x5408F0, 0x540FC0, 0x541120 and 0x541340 is inferred from field-offset overlap and the VidMan caller labels, not independently established.
- Whether the two vtable-backed sub-objects at this+0x10FC and this+0x1100 are the same or distinct surface interfaces is unresolved; the packet explicitly flags the question.
- The format ids 20-25, 71, 77, 80 and 101, the capability-bitmask mapping (0x1000000/0x2000000/0x4000000/0x8000000/0x10000000/0x20000000) and the meaning of the out+24 flag bit 2 are not decoded by this corpus.
- The audio-emitter object (60-byte allocation via 0x00587C03, stored at a2[1]) and the audio-buffer 96-byte lock region contract of 0x00540F00 are not established.
- Globals 0x0059E450, 0x005B8978 and 0x005B897C are listed as read globals but do not appear in the raw decompiled body; Hex-Rays likely folded them into the FOV computation literals, so their exact consumption site is unresolved.
- Global 0x00800000 (unk_800000) is tested in 0x53FED0 but its value and purpose are unverified; prior analysis labels it an MMX flag at DERIVED tier only.
- The surface descriptor layout (flags at +0x18, slots at +0x8..+0x14) is observed only in operation prose; the packet provides no formal field evidence refs for it, so it is not formalized as class fields.
- The position-orientation X/Y/Z interpretation of the 0x542460 triple (+0x24/+0x28/+0x2C) is DERIVED from caller context, not established by the raw source.
- Global 0x008B8E4C written by 0x53D400 has no recorded readers; the value semantics (mode, handle, or dimension) are unknown.
- The registry node payload beyond the prev/next links at +0x86C/+0x870 (stride and shape) is undefined by the packet.
- Vtable slot semantics (vtable+8 as release vs flush, vtable+60 as surface resolution, vtable+44 as lock/allocate) are inferred from dispatch patterns only; no named callee is statically known.
- The buffer/descriptor pointer at this+0x114C is treated as an audio buffer base by 0x541470 and as a texture descriptor pointer by 0x541340; whether these are one field or two aliased fields on the same object is not proven.
