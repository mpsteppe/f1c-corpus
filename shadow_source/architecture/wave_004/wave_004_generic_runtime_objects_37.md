# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal reconstructs twenty-seven generic runtime-object routines into eighteen defensible classes plus shared stream/critical-section interfaces. Core clusters: (1) a streambuf-style buffer-control object (0x005994BC ctor, 0x0059A473 initializer, 0x0059A4C9 ring init) with a self-referential ring of stream-position pointer slots, a locale-facet refcount path, and an external-buffer install; (2) a refcounted string buffer (0x00599615 write, 0x0059A9CA subrange assign) sharing full-length buffers through a refcount byte before the data pointer; (3) iostream construction (0x00599B1C ostream frame, 0x00599BF0 istream/locale) sharing StreamCreationWithFlagInit; (4) a global critical-section facility (0x0059A54D init+enter, 0x0059A5E9 guarded leave) keyed by the atomic state global 0x008D4610; (5) a global 8-slot object table (0x0059A8FA); and (6) two stream lock/query wrappers (0x0059BBAF, 0x0059BCD2). All packet owners are UNKNOWN; class ownership assignments are DERIVED/GUESS proposals, and equal byte offsets on different classes (e.g. this+0x50 as buffer base in CStreamBufferControl versus file handle in CFileHandleCloseGuard) are kept as distinct fields per rule 8.

## Function roles

- `0x00599495` **CFileHandleCloseGuard** — file_handle_close_with_status_report
- `0x005994BC` **CStreamBufferControl** — buffer_control_constructor
- `0x00599615` **CRefCountedStringBuffer** — buffer_write_null_terminated
- `0x005997A1` **CGlobalObjectChain** — module_global_chain_init
- `0x00599B1C` **COStreamObjectConstructor** — ostream_frame_setup
- `0x00599BF0` **CIStreamObjectConstructor** — istream_locale_constructor
- `0x0059A44C` **CFileHandleCloseGuard** — file_handle_close_with_status_report_variant
- `0x0059A473` **CStreamBufferControl** — buffer_data_pointer_assignment
- `0x0059A4C9` **CStreamBufferControl** — self_referential_pointer_ring_init
- `0x0059A54D` **CGlobalCriticalSectionFacility** — critical_section_init_and_enter
- `0x0059A5E9` **CGlobalCriticalSectionFacility** — conditional_leave_critical_section
- `0x0059A765` **CScalarDeletingDestructorThunk** — scalar_deleting_destructor
- `0x0059A8FA` **CGlobalObjectTableFacility** — global_object_table_register
- `0x0059A980` **CCallbackListOwner** — callback_chain_iterate_and_free
- `0x0059A9CA` **CRefCountedStringBuffer** — string_buffer_assign_range
- `0x0059AC63` **CScalarDeletingDestructorThunk** — exception_scalar_deleting_destructor
- `0x0059AE61` **CScalarDeletingDestructorThunk** — destructor_with_conditional_free
- `0x0059AF50` **CStdLogicErrorException** — std_length_error_constructor
- `0x0059B038` **CStdLogicErrorException** — std_out_of_range_constructor
- `0x0059B092` **CRefCountedConversionGuard** — refcounted_guarded_delegated_conversion
- `0x0059B260` **CArgumentPackDispatch** — versioned_argument_pack_parser
- `0x0059B2F0` **CSurfaceAllocationContainer** — surface_allocation_constructor
- `0x0059B5C0` **CUnitBitmapTracker** — bitmap_range_allocate
- `0x0059BAA3` **CTypeInfoDestructor** — type_info_destructor
- `0x0059BB00` **CStreamBufferDescriptor** — stream_buffer_setup
- `0x0059BBAF` **CStreamLockedQuery** — stream_query_lock_wrapper
- `0x0059BCD2` **CStreamLockedQuery** — stream_read_lock_wrapper

## Proposed classes

### CStreamBufferControl

Streambuf-style buffer-control object with a self-referential ring of stream-position pointer slots, an optional external caller buffer install, a locale-facet refcount path, and a mode flag selecting internal vs external buffer layout.

Methods: `0x005994BC`, `0x0059A473`, `0x0059A4C9`

- `this+0x0000000C` `unsigned char* get_ptr` (read_write, GUESS)
- `this+0x00000010` `unsigned char* get_end_ptr` (read_write, GUESS)
- `this+0x0000001C` `unsigned char* eback_ptr` (read_write, GUESS)
- `this+0x00000020` `unsigned char* put_ptr` (read_write, GUESS)
- `this+0x0000002C` `unsigned char* put_end_ptr` (read_write, GUESS)
- `this+0x00000030` `unsigned char* put_base_ptr` (read_write, GUESS)
- `this+0x00000038` `unsigned int codecvt_state_field` (write, GUESS)
- `this+0x0000003C` `unsigned int capacity_end` (write, DERIVED)
- `this+0x00000040` `unsigned int capacity_limit` (write, DERIVED)
- `this+0x00000044` `void* external_buffer_clear_slot` (write, GUESS)
- `this+0x00000048` `unsigned char external_buffer_flag` (read_write, DERIVED)
- `this+0x00000050` `unsigned char* buffer_base_ptr` (read_write, DERIVED)

### CRefCountedStringBuffer

Reference-counted byte-string buffer storing its refcount byte immediately before the data pointer; supports capacity-guaranteed writes with NUL termination and copy-on-assign full-length buffer sharing.

Methods: `0x00599615`, `0x0059A9CA`

- `this+0x00000004` `unsigned char* data_ptr` (read_write, DERIVED)
- `this+0x00000008` `unsigned int used_length` (read_write, DERIVED)
- `this+0x0000000C` `unsigned int capacity` (read_write, GUESS)

### CFileHandleCloseGuard

Object storing a file handle at +0x50 and closing it through FileCloseWithLock, reporting failure through a status-raising helper called with literal arguments (0, 2) and returning this as a non-null failure signal.

Methods: `0x00599495`, `0x0059A44C`

- `this+0x00000050` `void* file_handle` (read, GUESS)

### COStreamObjectConstructor

Constructs a std::basic_ostream-family stream object from frame-passed handle/name and mode fields, registering an SEH handler and installing the basic_ios/basic_ostream vtable chain before opening the stream.

Methods: `0x00599B1C`

- `this+0x00000008` `unsigned int stream_argument_1` (read, GUESS)
- `this+0x0000000C` `unsigned int stream_argument_2` (read, GUESS)
- `this+0x00000010` `unsigned char init_flag` (read, GUESS)
- `this+0x00000014` `unsigned char guard_flag` (read, GUESS)

### CIStreamObjectConstructor

Constructs a locale/istream-family object with a multi-inheritance vtable layout (base vtable, basic_ios vtable, and an adjusted basic_istream vtable written at the slot selected by *(*(this)+4)), completing construction through StreamCreationWithFlagInit.

Methods: `0x00599BF0`

- `this+0x00000008` `unsigned int stream_argument_1` (read, GUESS)
- `this+0x0000000C` `unsigned int stream_argument_2` (read, GUESS)
- `this+0x00000010` `unsigned int guard_field` (read, GUESS)

### CGlobalObjectChain

Module-level initializer installing an SEH handler and reference-count-guarding a one-time construction chain of seven linked global objects (vtable/SEH-chain and locale-style objects) in static module storage.

Methods: `0x005997A1`


### CGlobalCriticalSectionFacility

Thread-safe one-time initialization and enter/leave of the process-wide critical section, keyed by the atomic state global Target (0=uninitialized, 1=initializing, 2=ready). The state (Target at 0x008D4610) and the CRITICAL_SECTION object (at 0x008D45F8) are globals carried in evidence_refs rather than this-relative fields.

Methods: `0x0059A54D`, `0x0059A5E9`


### CGlobalObjectTableFacility

Global 8-slot object registration table (entries at 0x008D4618, ref-count bytes at 0x008D463C) with a parallel ref-count byte array; objects self-register by advancing their slot-index field at this+0x24 until an empty or already-self slot is found. The table arrays are globals carried in evidence_refs; the per-object slot index is a this-relative field.

Methods: `0x0059A8FA`

- `this+0x00000024` `unsigned int slot_index` (read_write, GUESS)

### CCallbackListOwner

Object owning two singly-linked callback lists (head pointers at +0x18 and +0x1C); teardown runs the registered callback chain then frees both lists through FreeWrapper and clears both heads.

Methods: `0x0059A980`

- `this+0x00000018` `void* callback_list_head` (read_write, DERIVED)
- `this+0x0000001C` `void* callback_list_head_second` (read_write, DERIVED)

### CScalarDeletingDestructorThunk

MSVC scalar-deleting-destructor thunk pattern: invoke the destructor body then free the object storage through FreeWrapper only when the deletion flag low bit is set; returns the object pointer.

Methods: `0x0059A765`, `0x0059AC63`, `0x0059AE61`


### CStdLogicErrorException

std::logic_error-derived exception objects (std::length_error, std::out_of_range) constructed by building the logic_error base then overwriting the object vtable pointer.

Methods: `0x0059AF50`, `0x0059B038`

- `this+0x00000000` `void* vtable_ptr` (write, GUESS)

### CRefCountedConversionGuard

Reference-counted guarded wrapper around a delegated conversion routine: bumps an interlocked counter, optionally lazily enters critical section 19, and balances counter or lock on exit.

Methods: `0x0059B092`


### CArgumentPackDispatch

Packs a small fixed argument array, validates/reorders it against a version string, dispatches it with mode 4, and writes the parsed output pointer back through the out parameter.

Methods: `0x0059B260`

- `this+0x00000000` `void* output_ptr_slot` (write, GUESS)

### CSurfaceAllocationContainer

Surface/bitmap container allocating a zeroed pixel buffer, a clip-rectangle entry array (pair of WORDs each), working counters, and dimension fields; dimensions default to 1 when the argument is zero.

Methods: `0x0059B2F0`

- `this+0x00000000` `void* pixel_buffer` (read_write, DERIVED)
- `this+0x00000004` `unsigned int pixel_buffer_size` (read_write, DERIVED)
- `this+0x00000008` `void* clip_rect_array` (read_write, DERIVED)
- `this+0x0000000C` `unsigned int clip_rect_count` (read_write, DERIVED)
- `this+0x00000010` `unsigned int work_index_1` (write, GUESS)
- `this+0x00000014` `unsigned int work_index_2` (write, GUESS)
- `this+0x00000018` `unsigned int dimension_1` (write, GUESS)
- `this+0x0000001C` `unsigned int dimension_2` (write, GUESS)

### CUnitBitmapTracker

Bitmap-tracked unit allocator: grows a bitmap byte array and a parallel element array, marks a2 consecutive bits used, records the cumulative-counter low word plus size per element, and returns the slot index.

Methods: `0x0059B5C0`

- `this+0x00000000` `unsigned char* bitmap_bytes` (read_write, DERIVED)
- `this+0x00000008` `void* element_array` (read_write, DERIVED)
- `this+0x00000010` `unsigned int cumulative_counter` (read_write, DERIVED)
- `this+0x00000014` `unsigned int element_index` (read_write, DERIVED)

### CTypeInfoDestructor

Destructor for an MSVC RTTI type-info object: restores the canonical type-info vtable, frees the type-descriptor name string under critical section 27, and leaves it.

Methods: `0x0059BAA3`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x00000004` `char* name_string` (read, GUESS)

### CStreamBufferDescriptor

FILE-stream-family buffer descriptor: validates a mode/size contract, rounds the size down to even, selects embedded/caller/heap buffer, manages the flag word, and writes buffer position/count/base/size fields under a critical section.

Methods: `0x0059BB00`

- `this+0x00000000` `void* buffer_ptr` (read_write, DERIVED)
- `this+0x00000004` `unsigned int buffer_position` (write, GUESS)
- `this+0x00000008` `void* buffer_put_ptr` (read_write, DERIVED)
- `this+0x0000000C` `unsigned short flag_word` (read_write, DERIVED)
- `this+0x00000018` `unsigned int buffer_size` (write, DERIVED)

### CStreamLockedQuery

Critical-section-wrapped stream query/read wrappers: lock the stream handle, run a query/read primitive, unlock, and return the 16-bit result.

Methods: `0x0059BBAF`, `0x0059BCD2`


## Compatibility contracts

- **CriticalSectionReadinessGate** — Enter/Leave of the global critical section must be gated on the atomic init-state global equalling 2 (ready); state 0 triggers one-time initialization by a single winning thread and state 1 makes other threads spin with Sleep(1).
- **ScalarDeletingDestructorAbi** — MSVC scalar-deleting-destructor convention: run the destructor body on the object, then free the storage through FreeWrapper only when the deletion flag low bit is set, and return the object pointer.
- **RefCountedStringBufferShareContract** — Full-length buffer assignment shares the source buffer by adopting its data/length/capacity pointers and incrementing the refcount byte stored immediately before the data pointer; partial or empty copies fall back to an allocation path, and a null source data pointer falls back to a static empty-string sentinel.
- **StreamBufferSetupContract** — Buffer setup validates the mode/size contract (mode 4 always allowed; otherwise size >= 2 and mode in {0, 64}), rounds the size down to even, runs under the stream critical section, and selects an embedded (effective size 2), caller-supplied, or heap-allocated buffer; returns 0 on success and -1 on validation or allocation failure.
- **GlobalObjectTableRegistrationContract** — Objects self-register into a global 8-slot table by advancing their slot-index field until an empty or already-self slot is found; the table stores the object pointer and increments the matching ref-count byte.
- **StreamLockQueryDiscipline** — Stream queries and reads must be wrapped in enter/leave of the stream critical section keyed by the stream handle, preserving the 16-bit result across the unlock call.

## Unresolved

- All packet owner markers are UnknownObject/UNKNOWN; every class assignment here is a DERIVED or GUESS proposal, not a confirmed original type.
- The meaning of the literal 2 argument passed to the error-reporting helpers (called with (0, 2)) from the file-close guards is unknown; whether the returned non-null pointer is consumed as an error object or merely as a boolean is unresolved.
- The locale facet pointer at +0x4C appears only in raw source and has no field evidence reference; its type and ownership are unknown.
- The sentinel comparison this == -76 (0xFFFFFFB4) in the buffer-control constructor is DERIVED, not independently evidenced.
- Offset +0x50 carries different semantics on different objects: buffer base in CStreamBufferControl versus file handle in CFileHandleCloseGuard. Per rule 8 these are kept as distinct fields; common ownership is not claimed.
- sub_599560 (capacity ensure) semantics and its third argument (growth policy, alignment, or exact-fit flag) are unknown; whether it reallocates and updates this+0x4 is not visible in the packet.
- The identities of dword_8D5A60 and dword_8D5A68 (buffer capacity constants) are DERIVED only.
- The concrete types and runtime purpose of the globals constructed by GuardedGlobalObjectChainInit are unknown; the +vtable[1] displacement arithmetic is unverified.
- The CEHFrameSetup and LocaleObjectAllocAndVtableSetup __userpurge/__ebp ABI means their field offsets map onto a caller stack frame, not a conventional object; the stream-object slot selector *v5+4 and the relationship between the unk_5B9C* vftables are not established.
- The identity of the compiler guard/SEH helpers used by the global-chain init and the semantics of the module reference counter beyond first-vs-subsequent are unknown.
- The owners of critical-section indices 19 and 27 are unknown; the relation of the CriticalSection/Target globals to the refcount and locale subsystems is not established.
- The mode-4 dispatch semantics of sub_5357E0, the version-string meaning, and the format of the parsed output in CArgumentPackDispatch are not established here.
- The clip-rectangle entry layout (pair of WORDs) and the width/height reading of surface container fields 0x18/0x1C are inferred, not typed-evidenced.
- The type-descriptor name allocation scheme in CTypeInfoDestructor is not proven from this packet alone.
- dword_5E9EF4 (the module reference counter read by GuardedGlobalObjectChainInit) is described from packet prose only and has no allowed evidence reference; no role is asserted.
