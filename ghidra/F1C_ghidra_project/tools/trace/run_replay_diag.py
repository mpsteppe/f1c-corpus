#!/usr/bin/env python3
"""Attach Frida to F1C and load the replay diagnostic agent."""
import frida
import sys
import time
from pathlib import Path

PROCESS = "F1 Challenge Online.exe"
AGENT = Path(__file__).parent / "agent_replay_diag.js"

def on_message(msg, data):
    if msg["type"] == "send":
        print(msg["payload"])
    elif msg["type"] == "error":
        print("[ERR]", msg.get("description", msg))

try:
    session = frida.attach(PROCESS)
except frida.ProcessNotFoundError:
    print(f"ERROR: '{PROCESS}' not running.")
    sys.exit(1)

print(f"Attached (PID {session._impl.pid}). Loading agent...")
script = session.create_script(AGENT.read_text(encoding="utf-8"))
script.on("message", on_message)
script.load()

print("Agent loaded. Reproduce the bug. Press Ctrl+C to detach.\n")
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    pass

script.unload()
session.detach()
print("\nDetached.")
