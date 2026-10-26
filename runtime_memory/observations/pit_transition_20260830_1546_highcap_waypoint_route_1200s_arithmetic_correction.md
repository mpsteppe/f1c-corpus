# Arithmetic correction — 2026-08-30

This additive correction supersedes only the pointer hexadecimal conversions and candidate-index arithmetic in `pit_transition_20260830_1546_highcap_waypoint_route_1200s_summary.md`. The raw correlation JSON is unchanged.

Verified formula: index = (pointer - 0x1784438C) / 316, only when the remainder is zero. Therefore index 943 is 0x1788CF90, 944 is 0x1788D0CC, 945 is 0x1788D208, 983 is 0x178900F0, 984 is 0x1789022C, and 985 is 0x17890368.

Raw JSON re-check: every PathSelector 0 -> 1 context in this capture is record-base aligned. The prior summary accidentally transcribed two pointers incorrectly: raw 394817984 is 0x178871C0 (index 867), not 0x17887220; raw 394845792 is 0x1788DE60 (index 955), not 0x1788D890. These are conversion/transcription errors in the summary, not evidence of an interior pointer, adapter mismatch, or transient runtime inconsistency.

Correct selected transitions: slot 14 at t=503.375 is 0x1788CF90 / index 943; slot 17 at t=701.516 and slot 20 at t=715.516 are also index 943; slot 9 at t=831.610 and slot 8 at t=945.688 are 0x1788D0CC / index 944; slot 5 at t=407.281 and slot 3 at t=649.469 are 0x1788D208 / index 945. Other aligned selections are index 947 (slot 13), 948 (slot 12), 949 (slots 16, 6, 7), 951 (slot 10), 952 (slot 4), 954 (slot 1), 955 (slot 2), and 867 (slots 11, 19, 21).

Slot 5 changed from 0x1788691C / index 860 at t=406.281 to 0x1788D208 / index 945 at t=407.281, while PathSelector changed 0 -> 1 and CallToBox was 1. This confirms the previous candidate-index-900 statement was wrong. No sampled event pointer equals indices 983 or 984; no direct passage through those nodes is established by this 1 Hz capture.
