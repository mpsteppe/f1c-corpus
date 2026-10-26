# Broker discovery live integration

Date: 2026-08-07. Candidate ABI range: 5 through 6.

## Results

Three process-local discovery paths were exercised in the supported game:

```text
current:   result=PASS discovery=0 negotiated=6 abi=6 caps=0xF
missing:   result=PASS discovery=2 expected=2 negotiated=0
duplicate: result=PASS discovery=3 expected=3 negotiated=0
```

- The current broker was found by exported contract, not module filename, and
  pinned while the API table was in use. ABI 6 and the required snapshot/event
  capabilities were negotiated.
- With no broker loaded, discovery returned `NOT_FOUND` and no table.
- With the real broker plus one broker-shaped fixture, discovery returned
  `DUPLICATE` and no table. It did not select by load order.
- The successful client unregistered and released its module pin before the
  broker's clean hook detach and unload.

The isolated 32-bit matrix separately passes old, current, forward-compatible,
too-new, missing-capability, missing, and duplicate fixtures.

## Remaining boundary

This validates startup discovery and orderly release/unload. A client racing an
uncooperative forced broker unload remains outside the supported contract; the
broker refuses orderly unload while API calls or clients remain. Public
packaging must make the pin/release rule mandatory.

## Cleanup

Every launch used staged `f1cm_guard.asi`, never QuickRace. The game was stopped,
all broker/probe/fixture ASIs were removed, and configuration remained
`MODE=Off`, `LAUNCHTIME=77`.

