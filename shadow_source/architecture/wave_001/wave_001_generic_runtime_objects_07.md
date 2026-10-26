# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic_runtime_objects wave: five defensible object groups plus a set of free, ownerless runtime utilities. ParticleVertexBufferManager (DERIVED from the packet) owns a ParticleVertexBufferDescriptor (base *(this+0x1E0)) and a per-particle entry array (base *(*(this+0x1E0)+0x8)); allocateParticleVertexBuffer tears down and rebuilds the buffer and stores sqrt(max squared camera distance) for LOD. ConfigLineParser (DERIVED from the packet for parseConfigLine; extended to three more functions at GUESS level via shared fields this+0x180/0x198 and overlapping callers) parses lines in place and extracts key/value tokens. GrowableStringBuffer (GUESS) tracks a heap buffer at this+0x0 with capacity at this+0x4 and reallocates on append/copy. PhysicsRigidBodyState (GUESS) holds angular velocity, world inertia tensor rows, reciprocal diagonal and computed inertia products, transforming the tensor between frames. NetworkConnectionList (GUESS) owns two singly-linked node lists and duplicates them in 0x0057B330; LinkedListNode (GUESS) captures the uniform 12-byte node layout across both lists. Twelve functions (0x00587BCF..0x0058BB10) plus the 0x005546A0 setter dispatcher are left ownerless: they are free __cdecl/__thiscall shims and orchestrators whose callee bodies are largely outside the packet. Contradictions are recorded in unresolved: packet-prose decimal offsets (this+124, this+188) with no field refs, template prelabel conflicts (0x00589DB0), tail jumps out of the packet body (0x00589DB6), and inference-only return codes.

## Function roles

- `0x0054F830` **ParticleVertexBufferManager** — Allocates/reinitializes the particle vertex buffer: tears down the old descriptor (LinkedNodeDestruction + free), allocates a fresh descriptor and entry array, copies per-particle position/secondary data, computes sqrt(max squared camera distance) into descriptor+0x0, returns 0.
- `0x005546A0` **Unassigned** — Orchestrator: writes this[0] from a3 then dispatches to 7 sub-setter callees with consecutive a2[8..14] values; no guards of its own. Semantic meaning of the dispatch payload lives in the callees.
- `0x005651B0` **ConfigLineParser** — Parses the config/INI line buffer in place at this+408 (==0x198): strips whitespace, // comments and CR/LF, toggles quote state, tracks paren depth, trims trailing spaces and returns a line-classification code (1 empty/space/brace, 2 closing brace, 3 comment-only, 0/4 content).
- `0x005654A0` **ConfigLineParser** — Config key/value extractor: duplicates the source string at this+0x198 into the object head, tokenizes at asc_5C30AC, rejects a consumed key via sub_588410, re-tokenizes at asc_5C64D4, stores the value at this+0x180 and copies it to an output buffer; returns 1 on success.
- `0x005655F0` **ConfigLineParser** — Parses a config value at this+0x180 as an integer tuple of size 1-4 using a (%d,...) format chosen by which output pointers are non-null; writes boolean (parsed!=0) into non-null outputs; succeeds when the extraction count equals the expected tuple size.
- `0x00565760` **ConfigLineParser** — Tuple serializer/writer: after a sub_565400 precondition, formats a 1-4 value tuple into the buffer at this+0x180 via a (%d,...) format selected by non-zero outputs, falling back to bare %d; returns TRUE when the formatted length equals the number of arguments.
- `0x005665B0` **GrowableStringBuffer** — Appends string a2 to a growable string buffer (ptr this+0x0, capacity this+0x4): reallocates via new/free when capacity is exceeded, strcat-appends; delegates to StringCopyWithBufferRealloc when the buffer is empty.
- `0x00566650` **GrowableStringBuffer** — Copies source string into the managed buffer (ptr this+0x0, capacity this+0x4), reallocating via free + new when null or too small; returns 0 on success, -1 on null input. Callee of StringBufferConcatAlloc.
- `0x005691D0` **PhysicsRigidBodyState** — Rigid-body inertia helper: converts Euler angles via EulerAnglesTo33RotationMatrix, transforms the inertia tensor to world space via F_3x3InertiaTensorTransform, computes three dot products of the tensor rows with the angular-velocity vector (this+0x94/0x9C/0xA4) storing doubles at this+0x7C/0x84/0x8C, returns the tensor-transform result.
- `0x00569280` **PhysicsRigidBodyState** — Copies 0x18 bytes (6 dwords) from a2 into this+124 (packet-prose decimal target; byte offset unconfirmed by field ref), then calls InertiaTensorWorldSpaceTransform and returns its result.
- `0x005697A0` **PhysicsRigidBodyState** — Copies a 0x18-byte inertia-tensor diagonal region from a2 into this+188 (packet-prose decimal target; unconfirmed), writes reciprocals 1.0/a2[i] into this+0xD4/0xDC/0xE4 (numerator constant dbl_59E420), then calls InertiaTensorWorldSpaceTransform. Unconditional; void.
- `0x0057B330` **NetworkConnectionList** — Duplicates two singly-linked lists from source a2 into this: copies connection flag (this+4), frees both destination lists, clones the first list (16-byte socket-address entries in 12-byte nodes) and the second list (4-byte data words), returning 1 (0 on null source). Mutates the source walk pointers a2+16/a2+32.
- `0x00587BCF` **Unassigned** — Free shim: forwards a memory pointer to sub_58AA6F and returns its result. Large cleanup/destructor caller set is consistent with a generic free/delete wrapper; the callee body is outside the packet.
- `0x00587BDC` **Unassigned** — CRT float-to-int64 conversion helper (__ftol): truncates the FPU stack double to __int64 delivered in edx:eax. Identified by the legacy abi name CRT___ftol.
- `0x00587C03` **Unassigned** — Allocation shim: returns NhMalloc(a1, 1) with a fixed second argument 1; legacy ABI label identifies it as operator new. Used from hundreds of allocation sites (mesh, camera, physics buffers, list nodes, packets, strings, textures).
- `0x00587C20` **Unassigned** — Two-byte pattern search over a null-terminated haystack: returns match pointer, returns a1 unchanged on empty first byte, 0 when exhausted; single-byte patterns tail-jump to 0x00589DB6.
- `0x00587ECE` **Unassigned** — cdecl string-to-int parser: skips whitespace (category 8), optional sign, accumulates decimal digits (category 4), returns -v when '-' seen. Character classification versioned by the cbMultiByte global (off_5E69C8 vs CharacterEncodingConvertViaLookupTableFallback).
- `0x0058815F` **Unassigned** — Variadic string formatter with overflow budget: formats via sub_58D04D into the destination with a 0x7FFFFFFF budget, on underflow calls sub_58CF35(0, &v6), otherwise NUL-terminates; returns the sub_58D04D result.
- `0x00588410` **Unassigned** — Case-insensitive byte-string compare (strcmpi order): locale-aware path serialized via refcount dword_8D5A5C + critical section 19 with sub_58B4D4 folding, or an inline-ASCII fast path (A-Z + 0x20); mode selected by dword_8D3F30.
- `0x005884ED` **Unassigned** — MSVCRT rand(): TLS state at TLS+20 advanced through state = 214013*state + 2531011; returns HIWORD(state) & 0x7FFF. TLS block obtained via TLSValueRetrievalWithInit.
- `0x00588570` **Unassigned** — Float80-to-double conversion chain entry: passes the 64-bit view of ST0 to FloatExponentExtractWithNaNGuard then returns sub_58858D's result; the real conversion steps live in the two callees (usercall convention, outputs not tracked by Hex-Rays).
- `0x0058957A` **Unassigned** — Thin __thiscall wrapper: forwards this and the address of global unk_5E6550 to the Cintrindisp2 helper and returns its result. No branches/fields/guards.
- `0x00589DB0` **Unassigned** — strchr-like byte search: unaligned byte head scan then aligned DWORD scan with a 0x81010100 zero-byte test; returns match pointer or NULL. cdecl (a1, a2), no this; the template getter prelabel is contradicted by the raw source.
- `0x0058BB10` **Unassigned** — memset-style byte filler: writes a3 copies of byte a2 into a1, returning a1. Alignment prefix, aligned bulk via memset32 with the byte replicated across a DWORD (16843009*a2), trailing bytes. No fields/globals.

## Proposed classes

### ParticleVertexBufferManager

Owns the particle vertex-buffer descriptor and per-particle entry array; allocates, tears down and initializes the buffer and computes the max camera-to-particle distance used for LOD culling.

Methods: `0x0054F830`

- `this+0x000001E0` `ParticleVertexBufferDescriptor* particleBufferDescriptor` (read_write, DERIVED)
- `this+0x00000204` `void* cameraArray` (read, DERIVED)
- `*(this+0x204)+0x000000DC` `float cameraPositionX` (read, GUESS)
- `*(this+0x204)+0x000000E0` `float cameraPositionY` (read, GUESS)
- `*(this+0x204)+0x000000E4` `float cameraPositionZ` (read, GUESS)

### ParticleVertexBufferDescriptor

Descriptor for a particle vertex buffer: max camera distance for LOD culling and a pointer to the zero-initialized entry array.

Methods: 

- `*(this+0x1E0)+0x00000000` `float maxCameraDistance` (write, GUESS)
- `*(this+0x1E0)+0x00000008` `ParticleBufferEntry* entryArray` (read_write, GUESS)

### ParticleBufferEntry

Per-particle vertex-buffer entry (116-byte stride): flags, position, and a secondary vector; position is read back for camera-distance LOD computation.

Methods: 

- `*(*(this+0x1E0)+0x8)+0x00000000` `uint32_t flags` (write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x00000004` `float positionX` (read_write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x00000008` `float positionY` (read_write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x0000000C` `float positionZ` (read_write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x0000001C` `float secondaryVectorX` (write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x00000020` `float secondaryVectorY` (write, GUESS)
- `*(*(this+0x1E0)+0x8)+0x00000024` `float secondaryVectorZ` (write, GUESS)

### ConfigLineParser

Parses and tokenizes configuration lines: normalizes a line buffer in place (comments, whitespace, quotes, parens), extracts key/value pairs into the object's string slots, and converts/extracts tuple values. Extended membership (0x005654A0/0x005655F0/0x00565760) is GUESS-level from shared fields and overlapping callers.

Methods: `0x005651B0`, `0x005654A0`, `0x005655F0`, `0x00565760`

- `this+0x00000198` `char[?] lineBuffer` (read_write, DERIVED)
- `this+0x00000180` `char* currentToken` (read_write, DERIVED)

### GrowableStringBuffer

Managed heap string container: buffer pointer at this+0x0, tracked capacity at this+0x4. Appends and copies with free + new reallocation; capacity is rewritten on every operation so external pokes to the buffer pointer do not persist.

Methods: `0x005665B0`, `0x00566650`

- `this+0x00000000` `char* buffer` (read_write, GUESS)
- `this+0x00000004` `uint32_t capacity` (read_write, GUESS)

### PhysicsRigidBodyState

Holds rigid-body inertia-tensor state: angular velocity, world inertia tensor rows (doubles), reciprocal inertia diagonal, and computed inertia-times-angular-velocity outputs. Transforms the tensor between body and world frames. Grouping of 0x00569280/0x005697A0 with 0x005691D0 is GUESS-level, based on the shared callee chain (F_3x3InertiaTensorTransform / InertiaTensorWorldSpaceTransform).

Methods: `0x005691D0`, `0x00569280`, `0x005697A0`

- `this+0x0000007C` `double inertiaMomentX` (write, GUESS)
- `this+0x00000084` `double inertiaMomentY` (write, GUESS)
- `this+0x0000008C` `double inertiaMomentZ` (write, GUESS)
- `this+0x00000094` `double angularVelocityX` (read, GUESS)
- `this+0x0000009C` `double angularVelocityY` (read, GUESS)
- `this+0x000000A4` `double angularVelocityZ` (read, GUESS)
- `this+0x000000D4` `double invInertiaDiagonalX` (write, GUESS)
- `this+0x000000DC` `double invInertiaDiagonalY` (write, GUESS)
- `this+0x000000E4` `double invInertiaDiagonalZ` (write, GUESS)
- `this+0x000000EC` `double inertiaTensor00` (read, GUESS)
- `this+0x000000F4` `double inertiaTensor01` (read, GUESS)
- `this+0x000000FC` `double inertiaTensor02` (read, GUESS)
- `this+0x00000104` `double inertiaTensor10` (read, GUESS)
- `this+0x0000010C` `double inertiaTensor11` (read, GUESS)
- `this+0x00000114` `double inertiaTensor12` (read, GUESS)
- `this+0x0000011C` `double inertiaTensor20` (read, GUESS)
- `this+0x00000124` `double inertiaTensor21` (read, GUESS)
- `this+0x0000012C` `double inertiaTensor22` (read, GUESS)

### NetworkConnectionList

Owns two singly-linked node lists: a socket-address list (bookkeeping at this+0x8/+0xC/+0x10/+0x14) and a data-word list (this+0x18/+0x1C/+0x20/+0x24), plus a connection flag at this+0x4. Duplicates an entire source list object into a fresh destination.

Methods: `0x0057B330`

- `this+0x00000004` `uint8_t connectionFlag` (read_write, GUESS)
- `this+0x00000008` `LinkedListNode* socketListHead` (read_write, GUESS)
- `this+0x0000000C` `LinkedListNode* socketListTail` (read_write, GUESS)
- `this+0x00000010` `LinkedListNode* socketListFirst` (write, GUESS)
- `this+0x00000014` `uint32_t socketListCount` (read_write, GUESS)
- `this+0x00000018` `LinkedListNode* wordListHead` (read_write, GUESS)
- `this+0x0000001C` `LinkedListNode* wordListTail` (read_write, GUESS)
- `this+0x00000020` `LinkedListNode* wordListFirst` (write, GUESS)
- `this+0x00000024` `uint32_t wordListCount` (read_write, GUESS)

### LinkedListNode

Uniform 12-byte singly-linked node (data/word at +0, next at +4, flag/active at +8) shared by both lists of NetworkConnectionList. First-list nodes carry a pointer to a 16-byte socket-address entry; second-list nodes carry a 4-byte data word. Fields are kept per-base (first-list base *(this+0x8), tail bases *(this+0xC)/*(this+0x1C), second-list base *(this+0x18), next-of-next base *(*(this+0x8)+0x4)); the class-level merge across those bases is GUESS, justified by the packet's uniform node description.

Methods: 

- `*(this+0x8)+0x00000000` `void* data` (read, GUESS)
- `*(this+0x8)+0x00000008` `uint8_t flag` (read, GUESS)
- `*(*(this+0x8)+0x4)+0x00000004` `LinkedListNode* next` (read, GUESS)
- `*(this+0xC)+0x00000004` `LinkedListNode* next` (read_write, GUESS)
- `*(this+0x18)+0x00000008` `uint32_t word` (read, GUESS)
- `*(this+0x1C)+0x00000004` `LinkedListNode* next` (read_write, GUESS)

## Compatibility contracts

- **ConfigLineClassificationContract** — parseConfigLine must mutate the line buffer in place (this+408), strip // comments and whitespace, and return the documented classification codes (1 empty/space/brace, 2 closing-brace, 3 comment-only, 0/4 content) so callers can dispatch on line type.
- **ParticleLodDistanceContract** — ParticleVertexBufferManager stores sqrt(max squared camera-to-particle distance) at descriptor+0x0 after (re)allocation; downstream LOD culling reads this value from the descriptor.
- **StringBufferCapacityContract** — GrowableStringBuffer keeps the capacity at this+0x4 in sync with the allocated buffer at this+0x0; capacity and pointer are rewritten on every append/copy, so external writes to the buffer pointer do not persist.
- **AllocationFreeContract** — Memory allocated through NhMallocWrapper (0x00587C03, NhMalloc(a1,1)) must be released through freeWrapper (0x00587BCF, sub_58AA6F); the allocate/free pair must stay matched.
- **CaseInsensitiveCompareThreadSafetyContract** — CaseInsensitiveStringCompare serializes the locale-aware path with refcount dword_8D5A5C and critical section 19 (guarded by dword_8D5A58); a replacement must preserve this serialization or provide equivalent thread safety.
- **CrtRandSemanticsContract** — RandLCGNext implements the MSVCRT rand() LCG (state = 214013*state + 2531011) returning HIWORD(state) & 0x7FFF; sequence reproducibility depends on preserving the exact recurrence and TLS state slot.
- **NetworkListDuplicationContract** — NetworkConnectionListDuplication returns 1 on success and 0 on null source; it consumes the source object's walk pointers (a2+16, a2+32) while cloning, and a replacement must preserve the two-list layout (head/tail/first/count at this+8..+24) with per-node data freed when the node flag is set.

## Unresolved

- All functions except allocateParticleVertexBuffer (ParticleVertexBufferManager, DERIVED) and parseConfigLine (ConfigLineParser, DERIVED) have owner trust UNKNOWN in the packet; the 12 free CRT/utility shims (0x00587BCF..0x0058BB10) and the 0x005546A0 dispatcher are left ownerless rather than forced into a class.
- ConfigLineParser methods 0x005654A0/0x005655F0/0x00565760 are assigned to ConfigLineParser at GUESS level from the shared field this+0x180/0x198 and overlapping callers; the packet only DERIVED the owner for 0x005651B0.
- field:this:0x00000000 is used in transient contexts that are not owned object fields: pattern byte in 0x00587C20, string input in 0x00587ECE, format destination in 0x0058815F. Only the GrowableStringBuffer buffer-pointer interpretation is treated as a real owned field; field:this:0x00000001 (second pattern byte of 0x00587C20) is parked in unresolved_evidence_refs.
- 0x00569280 copies 0x18 bytes into 'this+124' and 0x005697A0 into 'this+188'; the packet spells these targets as decimal prose and provides no field evidence ref, so the byte offsets are ambiguous and unconfirmed.
- ParticleVertexBufferDescriptor count field at descriptor+0x4 is written (entry count) but has no packet field ref; the descriptor's entry-count dword is therefore absent from the class.
- LinkedListNode merges fields from two distinct lists of NetworkConnectionList (first-list base *(this+0x8), second-list base *(this+0x18)) plus tail bases *(this+0xC)/*(this+0x1C) and a next-of-next base *(*(this+0x8)+0x4); the merge is GUESS, justified by the packet's uniform 12-byte node description. The 16-byte socket-address entry internals and the meaning of second-list data words have no field refs.
- MultiFieldSetterDispatch (0x005546A0) semantics of a2[8..14] and of each sub-setter's target field are owned by its 7 callees and are not evidenced in the packet.
- 0x0058957A calls Cintrindisp2 with global unk_5E6550, but Cintrindisp2 has no address in the packet callee table.
- TwoBytePatternSearch tail-jumps to 0x00589DB6 for single-byte patterns; that continuation block is outside the packet body.
- parseConfigLine return codes 0/1/2/3/4 are inferred from branch structure; the StrlenFormatCallWrapper==-1 check and the code 4 vs 0 distinction for content lines are ambiguous.
- Mapping of the five format-literal globals (0x005C3280, 0x005E5074, 0x005E507C, 0x005E5084, 0x005E5090) to specific (%d,...) variants is DERIVED from the aD* naming pattern, not locked by the packet.
- StructCopyWithReciprocalDivision uses dbl_59E420 as the 1.0 numerator; this role is DERIVED from existing analysis prose, the raw source shows a literal 1.0 without naming the global.
- CRT identification of the free utilities (rand, ftol, strcmpi, strchr, memset, byte search, whitespace-skip parse, string formatting) rests on abi:lead labels and raw source; exact CRT identity is not proven by the packet.
- The 0x0058BB10 MemsetBytes bulk path uses the memset32 intrinsic, which is absent from the packet callee table; no call target is asserted.
