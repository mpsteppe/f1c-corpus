#!/usr/bin/env python3
"""
run_text_probe.py — attach Frida to F1 Challenge and run f1c_text_probe.js.

Logs every FUN_0045BD10 call (param_1 address, text, slot metadata) and
attempts a live "RED FLAG" injection on the 2nd call to prove the mechanism.

Usage:
    python tools/trace/run_text_probe.py

Game must be running first. Trigger a penalty to see calls (cut-track shortcut).
"""
import frida
import json
import sys
import time
from pathlib import Path

PROCESS = "F1 Challenge Online.exe"
AGENT   = Path(__file__).parent / "f1c_text_probe.js"

def on_message(msg, _data):
    if msg["type"] == "error":
        print(f"[FRIDA-ERR] {msg['description']}")
        if msg.get("stack"):
            print(msg["stack"])
        return
    p = msg.get("payload", {})
    t = p.get("t", "?")

    if t == "ready":
        print(f"[*] {p['msg']}")

    elif t == "call":
        print(f"\n[CALL #{p['n']}]")
        print(f"  p1        = {p['p1']}")
        print(f"  p2 (line) = {p['p2']}")
        print(f"  p3 (color)= {p['p3']}")
        print(f"  text      = {repr(p['text'][:80])}")
        print(f"  slot_count= {p['slot_count']}  slot0_timer= {p['slot0_timer']:.4f}")
        print(f"  thread    = {p['tid']}")

    elif t == "inject_start":
        print(f"\n[INJECT] Starting RED FLAG test on param_1={p['p1']} (game thread)...")

    elif t == "inject_ok":
        print("[INJECT] SUCCESS — FUN_0045BD10 returned without crash!")
        print("         Check screen for RED FLAG text. If visible: mechanism proven.")
        print("         Next step: hook a frequent game function, set flag, call from there.")

    elif t == "inject_fail":
        print(f"[INJECT] FAILED: {p['err']}")
        print("         Crash from game thread too — need different approach.")
    else:
        print(f"[?] {p}")

try:
    session = frida.attach(PROCESS)
except frida.ProcessNotFoundError:
    print(f"ERROR: '{PROCESS}' not running. Start the game first.")
    sys.exit(1)

js = AGENT.read_text(encoding="utf-8")
script = session.create_script(js)
script.on("message", on_message)
script.load()

print(f"Attached to {PROCESS}. Press Ctrl+C to detach.")
try:
    while True:
        time.sleep(0.5)
except KeyboardInterrupt:
    pass
finally:
    session.detach()
    print("Detached.")
