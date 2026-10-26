# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Ten functions reconstructed around rotation math, constraint solving, and container utilities. Three math helpers operate on 3x3 row-major double matrices or an Euler triple: RotationMatrixToEuler (0x00566EE0) extracts three angles to this+0/+4/+8 with an FPU-status singularity branch, QuaternionToRotationMatrix (0x00566F40) expands a unit quaternion into nine double matrix elements, and Matrix33Multiply (0x0056C740) computes the nine dot products of two matrices and returns the output pointer. ConstraintStiffnessMatrixAssembly (0x0056BAF0) iterates constraint entries (88-byte stride) at this+0x240, cross-products axes, transforms them through the world inverse inertia via Matrix3x3VectorMultiply (0x00435E00), scales by inverse mass this+0xB4, and accumulates diagonal and type-selected off-diagonal blocks through the row-pointer table at this+0x228. The container utilities are heterogeneous: LinearSearchInStructArrayByString (0x0056EB30) walks 72-byte structs skipping null entries using string comparison 0x00588410; initMatrixIdentityColumnAndRow (0x0056EC70) either dispatches to a vtable+24 virtual or manually zeroes a column/row and sets a 1.0 diagonal on a pointer-array matrix representation; InitializeStructArrayPool (0x005823C0) and InitializeLargeStructArrayPool (0x005824F0) build size-scaled 4/16-slot dual-list pools through the NTimeCallbackLoopWithSEH_a6eb initializer; NullTerminatedIntArrayCopyWithAlloc (0x00598502) deep-copies a null-terminated string-pointer array with abort-on-alloc-failure; GrowDynamicElementArray (0x0059B530) grows a two-WORD-element array by a stride until capacity covers count+1. Four functions remain ownerless in function_roles because no common-ownership evidence exists.

## Function roles

- `0x00566EE0` **UnknownObject** — Rotation matrix to Euler conversion: writes x-angle atan2(-a1[5], sqrt(a1[3]^2 + a1[4]^2)) to this+0, then branches on FPU status word & 0x4100 left by the sqrt. Singularity branch writes y-angle atan2(-a1[6], a1[0]) to this+4 and zeroes this+8; normal branch writes y-angle atan2(a1[2], a1[8]) to this+4 and z-angle atan2(a1[3], a1[4]) to this+8. Returns the FPU status mask (non-zero when the singularity branch was taken).
- `0x00566F40` **UnknownObject** — Unit quaternion to 3x3 row-major rotation matrix: a1[0]=w, a1[1]=x, a1[2]=y, a1[3]=z; doubles each component, forms the pairwise products, and writes nine matrix elements to a2[0..8] with 1-(zz+yy), 1-(zz+xx), 1-(yy+xx) on the diagonal. Pure computation with no branches.
- `0x0056BAF0` **UnknownObject** — Constraint stiffness matrix assembly for a contact-constraint solver: reads the constraint count at this+0x23C as loop bound and initial return value, guards on count>0, then walks the entry buffer at this+0x240 with 88-byte stride. Per entry loads axis doubles at +24/+32/+40 and +64/+72/+80, an index dword at +48 and a type byte at +52, cross-products the axes, transforms them via Matrix3x3VectorMultiply on the world inverse inertia, scales by inverse mass this+0xB4, and accumulates the diagonal block through the row-pointer table at this+0x228. An inner loop over subsequent entries computes off-diagonal coupling terms, adding when the two type bytes match and subtracting otherwise. Returns the last row index, consumed by InertialTensorVectorTransform.
- `0x0056C740` **UnknownObject** — 3x3 matrix multiply: computes the nine output entries of a3, each a dot product of one row of a1 with one column of a2 (row-major over nine doubles at 0x0..0x40), and returns the unmodified a3 pointer. Structural twin of Matrix3x3VectorMultiply per cluster_copy prelabel; called from suspension and collision transform paths.
- `0x0056EB30` **UnknownObject** — Linear search over an array of 72-byte structs that skips null entries: returns 0 when the element count at this+0x18 is <= 0; otherwise walks the array base at this+0x1C with stride 72, continuing while the element string pointer is null or string comparison 0x00588410 reports non-match, and returns this+0x1C + 72*index on the first non-null match or 0 when exhausted.
- `0x0056EC70` **UnknownObject** — Matrix identity init for one column and one row: when the vtable pointer at this+0x30 is non-null, delegates to the virtual method at vtable+24; otherwise zeroes the 8-byte elements of column a2 (via the column pointer array) and row a2 (via the row pointer array) for each index in [0, this[8]), sets the diagonal element to 1.0 (high 32-bit word 1072693248), zeroes the matching row element at this+0x2C, and returns this[11] (the row-pointer array address).
- `0x005823C0` **UnknownObject** — Struct-array pool initialization (4 slots): allocates a 4-byte wrapper, a 164-byte pool array (4 sub-objects of 40 bytes plus a 4-byte slot-count header), stores the slot count 4, runs NTimeCallbackLoopWithSEH_a6eb over 4 slots with 40-byte stride invoking the StructInitializationWithVTable and sub_57AEF0 callbacks under the SEH_5823C0 handler, wraps the pool in a 12-byte node marked free, and appends it to list1 (head this+0x0, tail this+0x4, cursor this+0x8, count this+0xC). Then pre-allocates one 12-byte free node per sub-object slot into list2 (head this+0x10, tail this+0x14, cursor this+0x18, count this+0x1C), leaving every slot node free. Returns the last list2 count.
- `0x005824F0` **UnknownObject** — Struct-array pool initialization (16 slots), size-scaled counterpart of 0x005823C0: zeroes the dual-list header this[0..7], allocates a 4-byte wrapper and a 644-byte pool array (16 sub-objects of 40 bytes plus a 4-byte slot-count header), stores the slot count 16, runs NTimeCallbackLoopWithSEH_a6eb over 16 slots with 40-byte stride under the SEH_5824F0 handler, wraps the pool in a 12-byte free node appended to list1, and pre-allocates 12-byte free nodes per slot into list2. Returns this.
- `0x00598502` **UnknownObject** — Null-terminated string-pointer array deep copy: returns 0 when the input pointer is null; otherwise walks the array counting elements until a null terminator (first element from offset 0, subsequent from offset 4 upward), allocates 4*(count+1) bytes via MallocWrapperForNhMalloc, aborts via CRTAmsgExit(9) if the allocation fails, copies each entry through StringAllocCopy, writes a null terminator, and returns the new array base.
- `0x0059B530` **UnknownObject** — Dynamic element-array growth: returns 1 when used count + 1 (this+0x14) does not exceed capacity this+0xC; otherwise computes new capacity starting at growth stride this+0x1C plus capacity and adding the stride until it covers count+1, allocates a 4*i byte buffer (two WORDs per element) via OperatorNewNhMallocWrapper returning 0 on failure, zero-initializes it, copies the first this+0x14 elements from the old array this+0x8, frees the old buffer via FreeWrapper_7bcf, and updates this+0x8 (pointer) and this+0xC (capacity). Returns 1 on the no-growth and success paths.

## Proposed classes

### RotationMatrixMath

Free-function rotation/matrix helpers over 3x3 row-major double matrices: unit-quaternion expansion into nine matrix elements (0x00566F40) and 3x3 by 3x3 multiplication (0x0056C740) reading matrix slots at 8-byte stride 0x0..0x40. The class is a thematic grouping; the matrix element slots are shared layout, not proven ownership.

Methods: `0x00566F40`, `0x0056C740`

- `this+0x00000000` `double m00` (read_write, GUESS)
- `this+0x00000008` `double m01` (read_write, GUESS)
- `this+0x00000010` `double m02` (read_write, GUESS)
- `this+0x00000018` `double m10` (read_write, GUESS)
- `this+0x00000020` `double m11` (read_write, GUESS)
- `this+0x00000028` `double m12` (read_write, GUESS)
- `this+0x00000030` `double m20` (read_write, GUESS)
- `this+0x00000038` `double m21` (read_write, GUESS)
- `this+0x00000040` `double m22` (read_write, GUESS)

### EulerAngleMath

Rotation-matrix to Euler-angle extraction writing three angle doubles to an output buffer at this+0/+4/+8, with an FPU-status singularity branch that collapses the z angle to zero.

Methods: `0x00566EE0`

- `this+0x00000000` `double euler_angle_x` (write, GUESS)
- `this+0x00000004` `double euler_angle_y` (write, GUESS)
- `this+0x00000008` `double euler_angle_z` (write, GUESS)

### ConstraintStiffnessMatrixBuilder

Sparse constraint stiffness-matrix assembly for the contact solver: reads the constraint count at +0x23C and entry buffer at +0x240 (88-byte stride), scales axis cross products by inverse mass at +0xB4, transforms them through the world inverse inertia, and accumulates diagonal plus type-selected off-diagonal blocks through the row-pointer table at +0x228. The world-inverse-inertia operand of the Matrix3x3VectorMultiply call is described in the packet but not listed among its allowed field evidence refs.

Methods: `0x0056BAF0`

- `this+0x000000B4` `float inverse_mass` (read, GUESS)
- `this+0x00000228` `void** row_ptr_table` (read_write, GUESS)
- `this+0x0000023C` `int constraint_count` (read, GUESS)
- `this+0x00000240` `void* constraint_entries` (read, GUESS)

### StringKeyedStructArray

Linear search container over 72-byte struct entries keyed by an embedded string: element count at +0x18, array base at +0x1C, null entries skipped, string equality decided by an external comparison helper. Returns the matching element pointer or 0.

Methods: `0x0056EB30`

- `this+0x00000018` `int element_count` (read, GUESS)
- `this+0x0000001C` `void* entries_ptr` (read, GUESS)

### MatrixIdentityInitializer

Matrix column/row identity initialization on a pointer-array matrix representation: dimension at +0x20, column-pointer array at +0x28, row-pointer array at +0x2C, vtable at +0x30. Either dispatches to a virtual method at vtable+24 or manually zeroes a column and row and sets a 1.0 diagonal.

Methods: `0x0056EC70`

- `this+0x00000020` `int dimension` (read, GUESS)
- `this+0x00000028` `double** column_ptr_array` (read_write, GUESS)
- `this+0x0000002C` `double** row_ptr_array` (read_write, GUESS)
- `this+0x00000030` `void** vtable_ptr` (read, GUESS)
- `*(this+0x30)+0x00000018` `void (*)() virtual_init_column_row` (unknown, GUESS)

### StructArrayPoolManager

Dual-list struct-array pool initialization at two scales (4 and 16 slots): list1 header at +0x0/+0x4/+0x8/+0xC (head/tail/cursor/count) holding one container node that wraps a pool array with a slot-count header, list2 header at +0x10/+0x14/+0x18/+0x1C holding per-slot free nodes. The two entry points are size-scaled counterparts and are grouped as one class, but common ownership is not proven by the packet.

Methods: `0x005823C0`, `0x005824F0`

- `this+0x00000000` `void* list1_head` (read_write, GUESS)
- `this+0x00000004` `void* list1_tail` (read_write, GUESS)
- `this+0x00000008` `void* list1_cursor` (read_write, GUESS)
- `this+0x0000000C` `int list1_count` (read_write, GUESS)
- `this+0x00000010` `void* list2_head` (read_write, GUESS)
- `this+0x00000014` `void* list2_tail` (read_write, GUESS)
- `this+0x00000018` `void* list2_cursor` (read_write, GUESS)
- `this+0x0000001C` `int list2_count` (read_write, GUESS)

### DynamicElementArray

Growable array of 2-WORD elements: data pointer at +0x8, capacity at +0xC, used count at +0x14, growth stride at +0x1C. Grows by repeated stride addition, allocates and zero-initializes the new buffer, copies the used prefix, frees the old buffer, and returns success/failure.

Methods: `0x0059B530`

- `this+0x00000008` `void* elements_ptr` (read_write, GUESS)
- `this+0x0000000C` `int capacity` (read_write, GUESS)
- `this+0x00000014` `int used_count` (read, GUESS)
- `this+0x0000001C` `int growth_stride` (read, GUESS)

## Compatibility contracts

- **EulerExtractionContract** — Rotation-matrix to Euler conversion writes three double angles to the output buffer at +0/+4/+8 and returns the FPU status mask (status word & 0x4100); a non-zero return indicates the singularity branch was taken, in which case the z angle is written as 0.0. A replacement must preserve the output layout, the angle formulas, and the singularity return value.
- **QuaternionToMatrixContract** — A unit quaternion (w,x,y,z) expands into a 3x3 row-major rotation matrix: a pure computation writing nine elements with 1-(zz+yy), 1-(zz+xx), 1-(yy+xx) on the diagonal and the six off-diagonal products in the standard quaternion-to-matrix arrangement. A replacement must preserve the element formulas and the output write order.
- **MatrixMultiplyContract** — 3x3 matrix multiply computes each output entry as the dot product of one row of the left matrix and one column of the right matrix over the nine-double row-major layout, and returns the unmodified output pointer. A replacement must preserve the row-major element order, the multiplication semantics, and the returned pointer.
- **ConstraintStiffnessAssemblyContract** — Contact-constraint stiffness assembly iterates the constraint buffer at +0x240 with 88-byte stride up to the count at +0x23C, scales transformed axis cross products by inverse mass at +0xB4, and accumulates diagonal plus type-selected off-diagonal blocks through the row-pointer table at +0x228; entries sharing the type byte add while differing types subtract. The function returns the last processed row index. A replacement must preserve the stride, the add/subtract type selection, the sparse addressing, and the return value.
- **StringKeyedStructArraySearchContract** — Linear search over a null-skipping 72-byte-stride array: returns 0 for an empty or exhausted array and the matching element pointer otherwise, where a match is a non-null string pointer that the external comparison helper reports as equal. A replacement must preserve the null-skip behavior, the 72-byte stride, and the zero-vs-pointer result contract.
- **StructArrayPoolInitializationContract** — Dual-list pool initialization builds a pool array with a slot-count header, runs a callback loop over each 40-byte slot, wraps the pool in a free container node appended to list1, and pre-allocates one free node per slot into list2. A replacement must preserve the slot count, the 40-byte slot stride, the free-node layout (payload/next/flag), and the list head/tail/cursor/count fields at +0x0..+0x1C.
- **NullTerminatedArrayDeepCopyContract** — Deep copy of a null-terminated string-pointer array: null input returns 0, otherwise the array is counted, allocated as 4*(count+1) bytes, each entry deep-copied, and a null terminator written. Allocation failure terminates the process through CRTAmsgExit(9). A replacement must preserve the null-terminator counting, the allocation size, the deep copy of every entry, and the abort-on-failure behavior.
- **DynamicElementArrayGrowthContract** — Dynamic array growth triggers when used count + 1 exceeds capacity, grows by repeatedly adding the growth stride until it covers the need, allocates and zero-initializes a 4*i byte buffer, copies the used prefix, frees the old buffer, and updates the pointer/capacity fields. Returns 1 on the no-growth and success paths and 0 only on allocation failure. A replacement must preserve the growth rule, the copy, the free, and the return contract.

## Unresolved

- Owners of all ten functions are unknown and left as UnknownObject in function_roles; the classes are worker-proposed thematic groupings and are not recovered source types.
- RotationMatrixToEuler (0x00566EE0): the read global flt_5B8968 is listed in the packet but does not appear in the raw source text; its role as EulerSingularityThreshold is unverified. The axis-to-angle mapping (pitch/yaw/roll) is inferred from existing analysis, not from the raw source.
- QuaternionToRotationMatrix (0x00566F40): global flt_59E43C (physics constant per skeleton fill) is listed as a read global but no reference is visible in the raw decompiled source; its role here is unexplained.
- ConstraintStiffnessMatrixAssembly (0x0056BAF0): the type byte at entry+52 that selects add/subtract accumulation is DERIVED from control flow; the sparse-matrix layout and 8-byte element size behind the row-pointer table at +0x228 are inferred; the 88-byte entry stride and axis field offsets are inferred from loop arithmetic. The world-inverse-inertia operand of the transform call is described in the packet but has no allowed field evidence ref.
- Matrix33Multiply (0x0056C740): row-major layout is inferred; a column-major interpretation is equally compatible with the field offsets. Caller 0x0056F100 is unnamed, and the claimed structural-twin relationship with Matrix3x3VectorMultiply was not verified here.
- LinearSearchInStructArrayByString (0x0056EB30): sub_588410 is treated as a string comparison returning 0 on match per existing analysis, but its exact contract is not part of this packet; the concrete 72-byte struct type and why entries may be null are unverified.
- initMatrixIdentityColumnAndRow (0x0056EC70): the matrix representation (dimension at this[8], column/row pointer arrays at this[10]/this[11]) is inferred from access pattern; the 8-byte element stride implies double entries but is not proven; the literal 1072693248 as the high 32-bit word of IEEE-754 double 1.0 is an interpretation; the virtual method at vtable+24 semantics are unknown.
- InitializeStructArrayPool (0x005823C0) / InitializeLargeStructArrayPool (0x005824F0): the two-list pool/queue consumer semantics live in external callers and are not determined here; the SEH handlers (SEH_5823C0 / SEH_5824F0) are not analyzed; whether the two functions share a common list-manager object type is not established - equal offsets on independent this pointers are not proof of identity, so the StructArrayPoolManager class grouping is a GUESS.
- NullTerminatedIntArrayCopyWithAlloc (0x00598502): the structure of objects returned by StringAllocCopy is unknown; the CRTAmsgExit(9) exit code meaning is unresolved; offsets 0 and 4 are the first two int slots of the walked array with caller-defined semantics.
- GrowDynamicElementArray (0x0059B530): the 2-WORD element semantic (clip-rect entries) is DERIVED from existing analysis; the owner object type is UNKNOWN; only the caller BitmapAllocationTracker (0x0059B5C0) is known.
- RotationMatrixMath and EulerAngleMath overlap on field offsets 0x00/0x04/0x08 (matrix element slots vs Euler output triple). The packet does not prove these are the same object, so the two classes are kept separate rather than merged.
- QuaternionToRotationMatrix records its nine output fields at 4-byte-spaced offsets (0x00..0x20) while Matrix33Multiply reads matrix slots at 8-byte stride (0x00..0x40); the two layouts are not proven to describe the same element type, so the class fields keep each function's own packet offsets.
