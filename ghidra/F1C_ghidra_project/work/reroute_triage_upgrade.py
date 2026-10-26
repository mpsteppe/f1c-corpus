"""
Re-route triage_upgrade worker outputs: replace all
<!-- target: docs/20-math-utilities.md --> with correct target doc
based on function address.

Run BEFORE merge_to_docs.py.
"""
import re
from pathlib import Path

ROOT       = Path(__file__).parent.parent
OUTPUT_DIR = ROOT / "analysis_pipeline" / "output" / "triage_upgrade"

# Address (lowercase, no 0x prefix) → correct target doc
ROUTES = {
    # ── Physics Collision (17) ────────────────────────────────────────────────
    "00401910": "docs/17-physics-collision.md",   # Swept Suspension Collision Detection
    "004493a0": "docs/17-physics-collision.md",   # Triangle Mesh Adjacency Builder
    "004a5fa0": "docs/17-physics-collision.md",   # Vehicle Proximity Collision Detection
    "004dd9f0": "docs/17-physics-collision.md",   # Triangle Normal Computation
    "004fb2e0": "docs/17-physics-collision.md",   # Vehicle Proximity / Collision Avoidance Radar
    "0044dbe0": "docs/17-physics-collision.md",   # Collision Parameter Block Init
    "0051427f": "docs/17-physics-collision.md",   # OBBFittingAndProjection
    "0054f2f0": "docs/17-physics-collision.md",   # CollisionContactDetection

    # ── Physics Dynamics (18) ─────────────────────────────────────────────────
    "004d68a0": "docs/18-physics-dynamics.md",    # Physics State Structure Initializer
    "004f8440": "docs/18-physics-dynamics.md",    # Suspension Force Computation w/ Virtual Dispatch
    "00435e60": "docs/18-physics-dynamics.md",    # Suspension Spring-Damper Force With Clamping
    "00441650": "docs/18-physics-dynamics.md",    # Vehicle Physics Integration Step
    "004e9a40": "docs/18-physics-dynamics.md",    # Vehicle Body-to-Wheel Contact Distance

    # ── Vehicle Physics (10) ──────────────────────────────────────────────────
    "004e19d0": "docs/10-vehicle-physics.md",     # VehicleStateUpdate
    "004adf10": "docs/10-vehicle-physics.md",     # Driving Mode Parameter Setup

    # ── AI System (02) ────────────────────────────────────────────────────────
    "00447160": "docs/02-ai-system.md",           # Vehicle Active / AI Eligibility Check

    # ── Tire System (04) ──────────────────────────────────────────────────────
    "004e88b0": "docs/04-tire-system.md",         # TireGripCoefficient

    # ── Renderer (19) ─────────────────────────────────────────────────────────
    "0049e5b0": "docs/19-renderer.md",            # Float-to-Color Encoding
    "004950e0": "docs/19-renderer.md",            # RenderFrameWrapper
    "005527c0": "docs/19-renderer.md",            # VertexBufferSurfaceInit
    "00498030": "docs/19-renderer.md",            # Renderer Alpha Blend Setter
    "004ca2d0": "docs/19-renderer.md",            # Particle Emitter Child Update
    "004cce90": "docs/19-renderer.md",            # Particle Spawn Function
    "00519361": "docs/19-renderer.md",            # SurfaceMemoryAllocate
    "004e2a00": "docs/19-renderer.md",            # Scene Graph Child Velocity Scaling

    # ── Audio / Network Internals (21) ────────────────────────────────────────
    "00405b90": "docs/21-audio-network-internals.md",  # 3D Sound Positioning Update
    "0044e360": "docs/21-audio-network-internals.md",  # Audio Filter Parameter Defaults
    "0044e960": "docs/21-audio-network-internals.md",  # AudioStateInit
    "00456170": "docs/21-audio-network-internals.md",  # 3D Sound Emitter / Camera Struct Init
    "0052ab4e": "docs/21-audio-network-internals.md",  # Audio Codec MDCT/FFT Transform
    "0051a87e": "docs/21-audio-network-internals.md",  # Huffman/Arithmetic Bitstream Decoder
    "00565080": "docs/21-audio-network-internals.md",  # RC4 Key Schedule (network crypto)

    # ── Session / Race Logic (06) ─────────────────────────────────────────────
    "0044dfa0": "docs/06-session-race-logic.md",  # ScoringDBReset

    # ── Engine Architecture (01) ──────────────────────────────────────────────
    "0053c1b0": "docs/01-engine-architecture.md", # Callback Registration Thunk
    "0053d470": "docs/01-engine-architecture.md", # System Init Allocator Wrapper
    "004651c0": "docs/01-engine-architecture.md", # Resource Manager Frame Cleanup
    "0040c870": "docs/01-engine-architecture.md", # Virtual Dispatch Helper
    "0047f080": "docs/01-engine-architecture.md", # VTable Pointer Constructor
    "004f6ab0": "docs/01-engine-architecture.md", # Global Table Initialization
    "00421570": "docs/01-engine-architecture.md", # Struct Pointer Array Deallocation
    "0046e590": "docs/01-engine-architecture.md", # ProcessingDispatch
    "00414900": "docs/01-engine-architecture.md", # FilePathExtensionCheck
    "00551cf0": "docs/01-engine-architecture.md", # Bink Video Frame Render

    # ── Math Utilities (20) — already correct, listed for completeness ─────────
    # 00457d00, 0045c0a0, 00567340, 0056bd40, 004baa50, 00502bea,
    # 00514fee, 004bea10, 00433370, 00497c40, 00564220, 005653f0,
    # 00457b60, 00582dc0, 004c2f20, 0058a8a3, 00589c49, 0059491a,
    # 0054a340, 004dfca0  → stay at docs/20-math-utilities.md
}

FUN_RE    = re.compile(r'^## FUN_([0-9a-fA-F]+)', re.MULTILINE)
TARGET_RE = re.compile(r'<!-- target:\s*docs/[^\s>]+\s*-->')


def reroute_file(path):
    text = path.read_text(encoding="utf-8", errors="replace")
    changed = 0

    # Split on ## FUN_ boundaries; fix the target comment preceding each entry
    # Strategy: find each <!-- target: --> comment and the ## FUN_ that follows it,
    # look up the address, replace the target if needed.
    def replace_target(m):
        nonlocal changed
        old_target = m.group(0)
        # Find the ## FUN_ immediately after this comment
        rest = text[m.end():]
        fun_m = FUN_RE.search(rest)
        if not fun_m:
            return old_target
        addr = fun_m.group(1).lower()
        new_doc = ROUTES.get(addr)
        if new_doc is None:
            return old_target  # stays at docs/20
        new_target = f"<!-- target: {new_doc} -->"
        if new_target != old_target:
            changed += 1
        return new_target

    new_text = TARGET_RE.sub(replace_target, text)
    if changed:
        path.write_text(new_text, encoding="utf-8")
        print(f"  {path.name}: {changed} target(s) updated")
    else:
        print(f"  {path.name}: no changes")
    return changed


def main():
    worker_files = sorted(OUTPUT_DIR.glob("worker_*.md"))
    if not worker_files:
        print(f"No worker files in {OUTPUT_DIR}")
        return

    total = 0
    for wf in worker_files:
        total += reroute_file(wf)

    print(f"\nTotal targets updated: {total}")
    print("Ready to merge: cd analysis_pipeline && python merge_to_docs.py --subdir triage_upgrade --archive")


if __name__ == "__main__":
    main()
