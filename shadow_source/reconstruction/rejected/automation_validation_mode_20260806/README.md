# Quarantined validator-mode mismatch

The overseer invoked `validate-candidates` on an already promoted runtime
contract. That command intentionally caps worker candidates at
`STATIC_DERIVED`, so it rejected the contract's `OBSERVED` status and expected
a packet reference in candidate form. The result is retained here as an
operator/tool-mode error; it is not evidence against the runtime observation.
