# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `GUESS`

This packet contains a single function, 0x005267A2 (j_F_4DVectorTransform), a jump/indirect-forward thunk that passes its three __m64* pointer arguments unchanged to F_4DVectorTransform and returns that callee's result. It contains no logic of its own. The callee F_4DVectorTransform is named in the source text but is absent from the packet, so its target address, signature details, and behavior are unresolved here. The proposal therefore scopes only the thunk's forwarding contract and records the callee as an open evidence gap.

## Function roles

- `0x005267A2` **VectorTransformUtility** — Forwarding thunk for the 4D vector transform F_4DVectorTransform; forwards three __m64* pointer arguments and returns the callee result; contains no local logic.

## Proposed classes

### VectorTransformUtility

Exposes the 4D vector transform operation through its stable thunk entry point; concrete implementation lives in F_4DVectorTransform which is unresolved in this packet.

Methods: `0x005267A2`


## Compatibility contracts

- **F4DVectorTransformCallable** — A replacement executable must provide a 4D vector transform entry reachable at the semantics of 0x005267A2 that accepts three __m64* pointer arguments, forwards them unchanged to the real transform, and returns the transform result as an __m64*. Callers depend on the argument-passing shape, not on the thunk address itself.

## Unresolved

- Callee F_4DVectorTransform is called from the source text but absent from the packet callees list; its target address and behavior are not resolved here.
- Function IR reports owner type UnknownObject (trust UNKNOWN); the proposed VectorTransformUtility owner is a GUESS and is not grounded in packet ownership evidence.
- Whether the 4D vector transform is vehicle-physics-specific or part of a shared math library is not determinable from this single thunk; scope attribution is a GUESS.
- The thunk's __m64* return and argument types come from the packet summary; the true signature of F_4DVectorTransform (matrix layout, element count, in-place vs out-of-place) is unknown.
