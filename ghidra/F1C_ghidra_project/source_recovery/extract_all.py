"""
Extract all source material into text files for DS worker consumption.

Outputs go to source_recovery/extracted/ — one text file per category.
DS workers read these files to cross-reference against F1C docs.

Usage: python source_recovery/extract_all.py
"""

import struct, re, os, datetime, glob

PROJECT = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(PROJECT)
SRC_MAT = r"%USERPROFILE%\Desktop\source_material"
OUT = os.path.join(PROJECT, "extracted")
os.makedirs(OUT, exist_ok=True)

# ─── Helpers ──────────────────────────────────────────────────────────────────

def read_binary(path):
    with open(path, "rb") as f:
        return f.read()

def extract_strings(data, min_len=6):
    return [s.decode("ascii", errors="replace")
            for s in re.findall(b"[\x20-\x7e]{" + str(min_len).encode() + b",}", data)]

def pe_info(data):
    """Extract basic PE info: sections, Rich header, RTTI, debug dir, imports."""
    info = {}
    if data[:2] != b"MZ":
        return {"error": "not MZ"}
    pe_off = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe_off:pe_off+4] != b"PE\x00\x00":
        return {"error": "not PE"}
    coff = pe_off + 4
    info["machine"] = struct.unpack_from("<H", data, coff)[0]
    info["num_sections"] = struct.unpack_from("<H", data, coff+2)[0]
    info["timestamp"] = struct.unpack_from("<I", data, coff+4)[0]
    try:
        info["build_date"] = str(datetime.datetime.fromtimestamp(info["timestamp"], datetime.UTC))
    except:
        info["build_date"] = "unknown"
    opt = coff + 20
    info["linker"] = f"{data[opt+2]}.{data[opt+3]}"
    info["image_base"] = struct.unpack_from("<I", data, opt+28)[0]
    info["entry"] = struct.unpack_from("<I", data, opt+16)[0]
    opt_size = struct.unpack_from("<H", data, coff+16)[0]
    sec_off = coff + 20 + opt_size

    # Sections
    sections = []
    for i in range(info["num_sections"]):
        s = sec_off + i * 40
        name = data[s:s+8].rstrip(b"\x00").decode("ascii", errors="replace")
        vsize = struct.unpack_from("<I", data, s+8)[0]
        vaddr = struct.unpack_from("<I", data, s+12)[0]
        rawsize = struct.unpack_from("<I", data, s+16)[0]
        rawoff = struct.unpack_from("<I", data, s+20)[0]
        sections.append({"name": name, "va": vaddr, "vsize": vsize, "raw": rawsize, "rawoff": rawoff})
    info["sections"] = sections

    def rva2off(rva):
        for sec in sections:
            if sec["va"] <= rva < sec["va"] + sec["vsize"]:
                return rva - sec["va"] + sec["rawoff"]
        return None

    # Rich header
    rich_end = data.find(b"Rich")
    if rich_end != -1:
        rkey = struct.unpack_from("<I", data, rich_end+4)[0]
        dm = rich_end
        while dm > 0:
            dm -= 4
            if struct.unpack_from("<I", data, dm)[0] ^ rkey == 0x536E6144:
                break
        entries = []
        for off in range(dm+16, rich_end, 8):
            r1 = struct.unpack_from("<I", data, off)[0] ^ rkey
            r2 = struct.unpack_from("<I", data, off+4)[0] ^ rkey
            entries.append({"type": (r1>>16)&0xFFFF, "build": r1&0xFFFF, "count": r2})
        info["rich"] = entries
    else:
        info["rich"] = []

    # RTTI
    rtti = []
    idx = 0
    while True:
        idx = data.find(b".?AV", idx)
        if idx == -1:
            break
        end = data.find(b"\x00", idx)
        rtti.append(data[idx:end].decode("ascii", errors="replace"))
        idx += 1
    info["rtti"] = rtti

    # Debug directory
    dd = opt + 96
    ndd = struct.unpack_from("<I", data, dd-4)[0]
    info["pdb"] = None
    if ndd > 6:
        drva = struct.unpack_from("<I", data, dd+48)[0]
        dsz = struct.unpack_from("<I", data, dd+52)[0]
        if drva > 0:
            doff = rva2off(drva)
            if doff:
                chunk = data[doff:doff+dsz]
                pdb_matches = re.findall(rb"[A-Za-z]:\\[^\x00]+\.pdb", chunk)
                if pdb_matches:
                    info["pdb"] = pdb_matches[0].decode("ascii", errors="replace")

    # Imports
    imp_rva = struct.unpack_from("<I", data, dd+8)[0]
    dlls = []
    if imp_rva > 0:
        off = rva2off(imp_rva)
        if off:
            while True:
                nrva = struct.unpack_from("<I", data, off+12)[0]
                if nrva == 0:
                    break
                noff = rva2off(nrva)
                if noff:
                    end = data.find(b"\x00", noff)
                    dlls.append(data[noff:end].decode("ascii", errors="replace"))
                off += 20
    info["imports"] = sorted(dlls)

    return info

# ─── Task 1: rFactor binary forensics ────────────────────────────────────────

def extract_rfactor_binaries():
    print("=== Extracting rFactor binaries ===")
    lines = ["# rFactor Binary Forensics", ""]
    rf_dir = os.path.join(SRC_MAT, "rFactor")

    exes = [
        ("rFactor.exe", "Game client (isiMotor 2.0)"),
        ("rFactor Dedicated.exe", "Dedicated server"),
        ("rF Config.exe", "Configuration utility"),
    ]
    plugins = [
        "Plugins/NetCommUtilPlugin.dll",
        "Plugins/RaceCastPlugin.dll",
        "Plugins/rFactorTrackIRPlugin.dll",
    ]

    for fname, desc in exes:
        path = os.path.join(rf_dir, fname)
        if not os.path.exists(path):
            continue
        data = read_binary(path)
        info = pe_info(data)
        lines.append(f"## {fname} — {desc}")
        lines.append(f"Size: {len(data):,} bytes")
        lines.append(f"Build: {info.get('build_date', '?')}")
        lines.append(f"Linker: {info.get('linker', '?')}")
        lines.append(f"Sections: {info.get('num_sections', '?')}")
        for sec in info.get("sections", []):
            lines.append(f"  {sec['name']:10s} VA=0x{sec['va']:08X} Size=0x{sec['vsize']:06X}")
        lines.append("")

        if info.get("rich"):
            lines.append("### Rich Header")
            total = 0
            for e in info["rich"]:
                lines.append(f"  type={e['type']} build={e['build']}: {e['count']}")
                total += e["count"]
            lines.append(f"  TOTAL: {total}")
            lines.append("")

        if info.get("rtti"):
            lines.append(f"### RTTI ({len(info['rtti'])} hits)")
            for r in info["rtti"]:
                lines.append(f"  {r}")
            lines.append("")

        if info.get("pdb"):
            lines.append(f"### PDB: {info['pdb']}")
            lines.append("")

        lines.append(f"### Imports ({len(info.get('imports', []))})")
        for d in info.get("imports", []):
            lines.append(f"  {d}")
        lines.append("")

        # Source paths in strings
        strings = extract_strings(data)
        src_paths = [s for s in strings if any(k in s for k in [".cpp", ".cxx", "Source", "Dev\\", ":\\"])]
        if src_paths:
            lines.append("### Source Paths")
            seen = set()
            for s in src_paths:
                if s not in seen and len(s) < 200:
                    seen.add(s)
                    lines.append(f"  {s}")
            lines.append("")

        # ISI/engine strings
        isi = [s for s in strings if any(k in s.lower() for k in
               ["gizmo", "osc ", "prelink", "cube", "isimo", "isi ", "image space",
                "racesession", "sessiontype", "gamestate", "racephase", "weathermode",
                "hotpacket", "gamespy", "currentrace", "formation", "caution",
                "safety car", "pitstop", "telemetry", "scoring", "checkpoint",
                "vehicle", "physics"])]
        if isi:
            lines.append("### ISI/Engine Strings")
            seen = set()
            for s in isi:
                if s not in seen and len(s) < 150:
                    seen.add(s)
                    lines.append(f"  {s}")
            lines.append("")

    # Plugin DLLs
    for ppath in plugins:
        path = os.path.join(rf_dir, ppath)
        if not os.path.exists(path):
            continue
        data = read_binary(path)
        fname = os.path.basename(ppath)
        lines.append(f"## Plugin: {fname}")
        lines.append(f"Size: {len(data):,} bytes")

        if data[:2] == b"MZ":
            info = pe_info(data)
            lines.append(f"Build: {info.get('build_date', '?')}")
            if info.get("rtti"):
                lines.append(f"### RTTI ({len(info['rtti'])} hits)")
                for r in info["rtti"]:
                    lines.append(f"  {r}")
            if info.get("pdb"):
                lines.append(f"### PDB: {info['pdb']}")
            lines.append("")

            # Exported functions
            strings = extract_strings(data, 4)
            exports = [s for s in strings if s.startswith("?") and "@" in s]
            if exports:
                lines.append("### Exported/Mangled Symbols")
                for e in exports[:100]:
                    lines.append(f"  {e}")
                lines.append("")

            # Plugin interface strings
            iface = [s for s in extract_strings(data) if any(k in s for k in
                     ["Plugin", "Create", "Destroy", "GetName", "GetVersion",
                      "Internals", "Scoring", "Telemetry", "Vehicle", "Physics"])]
            if iface:
                lines.append("### Interface Strings")
                seen = set()
                for s in iface:
                    if s not in seen and len(s) < 150:
                        seen.add(s)
                        lines.append(f"  {s}")
                lines.append("")

    out_path = os.path.join(OUT, "rfactor_binaries.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path} ({len(lines)} lines)")

# ─── Task 2: All config files (hdv, pm, tbc, veh, ini) ───────────────────────

def extract_config_params():
    print("=== Extracting config parameters ===")
    lines = ["# Physics Config Parameter Catalog", "",
             "All parameter names from .hdv, .pm, .tbc, .veh, .ini files across ISI games.", "",
             "Format: GAME | FILE | SECTION | PARAM=value // comment", ""]

    # Map of game dirs
    games = {
        "F1_2000": os.path.join(SRC_MAT, "F1 2000"),
        "NASCAR_2003_Demo": os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo"),
        "NASCAR_2004_Demo": os.path.join(SRC_MAT, "NASCAR Thunder TM 2004 Demo"),
        "NASCAR_2003_Retail": os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Win_EN_ISO-Version", "iso contents"),
        "NASCAR_2004_Retail": os.path.join(SRC_MAT, "NASCAR-Thunder-2004_Win_EN_ISO-Version"),
        "SCGT": os.path.join(SRC_MAT, "Sports Car GT"),
        "rFactor": os.path.join(SRC_MAT, "rFactor"),
    }

    all_params = {}  # param_name -> set of (game, section, value, comment)
    extensions = (".hdv", ".pm", ".tbc", ".veh", ".ini", ".eng")

    for game, base_dir in games.items():
        if not os.path.exists(base_dir):
            continue
        for root, dirs, files in os.walk(base_dir):
            for fname in files:
                ext = os.path.splitext(fname)[1].lower()
                if ext not in extensions:
                    continue
                fpath = os.path.join(root, fname)
                try:
                    with open(fpath, "r", encoding="utf-8", errors="replace") as f:
                        content = f.read()
                except:
                    continue

                # Skip binary files
                if "\x00" in content[:200]:
                    continue

                rel = os.path.relpath(fpath, base_dir)
                section = ""
                for line in content.split("\n"):
                    line = line.strip()
                    if not line or line.startswith("//"):
                        continue
                    # Section header
                    m = re.match(r"\[(\w+)\]", line)
                    if m:
                        section = m.group(1)
                        continue
                    # Key=value
                    m = re.match(r"(\w+)\s*=\s*(.+)", line)
                    if m:
                        param = m.group(1)
                        value_and_comment = m.group(2).strip()
                        # Split value from comment
                        comment = ""
                        if "//" in value_and_comment:
                            parts = value_and_comment.split("//", 1)
                            value = parts[0].strip()
                            comment = parts[1].strip()
                        else:
                            value = value_and_comment

                        key = param
                        if key not in all_params:
                            all_params[key] = []
                        all_params[key].append({
                            "game": game, "file": rel, "section": section,
                            "value": value, "comment": comment
                        })

    # Write grouped by parameter name (alphabetical)
    lines.append(f"## Unique Parameters: {len(all_params)}")
    lines.append("")

    for param in sorted(all_params.keys(), key=str.lower):
        entries = all_params[param]
        games_with = sorted(set(e["game"] for e in entries))
        sections_with = sorted(set(e["section"] for e in entries if e["section"]))

        # Find best comment (longest, from rFactor preferred)
        best_comment = ""
        for e in entries:
            if e["comment"] and len(e["comment"]) > len(best_comment):
                best_comment = e["comment"]

        lines.append(f"### {param}")
        lines.append(f"  Games: {', '.join(games_with)}")
        if sections_with:
            lines.append(f"  Sections: {', '.join(sections_with)}")
        if best_comment:
            lines.append(f"  Description: {best_comment}")
        # Show example values (one per game, prefer hdv)
        seen_games = set()
        for e in entries:
            if e["game"] not in seen_games:
                seen_games.add(e["game"])
                lines.append(f"  {e['game']}: {e['value']}  ({e['file']}:{e['section']})")
        lines.append("")

    out_path = os.path.join(OUT, "config_params.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path} ({len(all_params)} unique params)")

# ─── Task 3: Full .hdv/.pm file dump (annotated, for workers) ────────────────

def extract_hdv_pm_full():
    print("=== Extracting full .hdv/.pm files ===")
    lines = ["# Full .hdv and .pm File Contents", "",
             "Complete text of representative .hdv and .pm files with ISI comments.", ""]

    # Pick best examples: one NASCAR, one rFactor F1-type, one rFactor stock car
    key_files = [
        ("rFactor_F1", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06.hdv")),
        ("rFactor_F1_Susp", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Susp.pm")),
        ("rFactor_StockCar", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "NationalStockCar", "Season_2006", "NSC06_Centennial.hdv")),
        ("rFactor_StockCar_Susp", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "NationalStockCar", "Season_2006", "NSC06_susp.pm")),
        ("NASCAR_2003_Demo", os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo", "Season03", "Vehicles", "Chevy", "Dupont24", "Dupont24.hdv")),
        ("NASCAR_2003_Retail", os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Win_EN_ISO-Version", "iso contents", "Options", "Earnhardt3", "Earnhardt3.hdv")),
        ("NASCAR_2003_Susp", os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo", "Season03", "Vehicles", "nascar_susp.pm")),
        ("NASCAR_2004_Demo", os.path.join(SRC_MAT, "NASCAR Thunder TM 2004 Demo", "SEASON04", "Vehicles", "Chevy", "DuPont24", "DuPont24.hdv")),
        ("NASCAR_2004_Susp", os.path.join(SRC_MAT, "NASCAR Thunder TM 2004 Demo", "SEASON04", "Vehicles", "nascar_susp.pm")),
        ("F1_2000_Ferrari", os.path.join(SRC_MAT, "F1 2000", "Season00", "Vehicles", "Ferrari", "G03gpxa.veh")),
        ("F1_2000_Default", os.path.join(SRC_MAT, "F1 2000", "Season00", "Vehicles", "Default.vhs")),
    ]

    # Also grab tire brand, engine, gears, damage files
    extras = [
        ("rFactor_Tires", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Tires.tbc")),
        ("rFactor_Engine", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Engine.ini")),
        ("rFactor_Gears", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Gears.ini")),
        ("rFactor_Damage", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Damage.ini")),
        ("rFactor_HeadPhys", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "HeadPhysics.ini")),
        ("rFactor_Upgrades", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_Upgrades.ini")),
        ("rFactor_CockpitInfo", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "FormulaIS", "Season_2006", "Form06_cockpitinfo.ini")),
        ("NASCAR_2003_Engine_Restricted", os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Win_EN_ISO-Version", "iso contents", "Options", "Earnhardt3", "EngineRestricted.ini")),
        ("NASCAR_2003_Engine_Unrestricted", os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Win_EN_ISO-Version", "iso contents", "Options", "Earnhardt3", "EngineUnrestricted.ini")),
        ("NASCAR_2003_Tires", os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo", "Season03", "Vehicles", "generic.tbc")),
        ("rFactor_Damage_Global", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "damage.ini")),
        ("rFactor_DoubleWishbone", os.path.join(SRC_MAT, "rFactor", "GameData", "Vehicles", "doublewishbone.pm")),
    ]

    for label, path in key_files + extras:
        if not os.path.exists(path):
            continue
        try:
            with open(path, "r", encoding="utf-8", errors="replace") as f:
                content = f.read()
        except:
            continue
        if "\x00" in content[:200]:
            continue
        lines.append(f"{'='*80}")
        lines.append(f"FILE: {label}")
        lines.append(f"PATH: {os.path.relpath(path, SRC_MAT)}")
        lines.append(f"{'='*80}")
        lines.append(content)
        lines.append("")

    out_path = os.path.join(OUT, "hdv_pm_full.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path}")

# ─── Task 4: String cross-reference table ────────────────────────────────────

def extract_string_crossref():
    print("=== Building string cross-reference ===")
    lines = ["# Cross-Binary String Comparison", "",
             "Strings shared between ISI game binaries.", ""]

    binaries = {
        "F1C": r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe",
        "F1_2000": os.path.join(SRC_MAT, "F1 2000", "F1_2000.ICD"),
        "F1_2000_Config": os.path.join(SRC_MAT, "F1 2000", "F1Config.exe"),
        "NASCAR_2003_Demo": os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo", "NASCAR_Thunder_2003_Demo.exe"),
        "NASCAR_2003_Retail": os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Win_EN_ISO-Version", "iso contents", "NASCAR_Thunder_2003.exe"),
        "NASCAR_2003_Patch": os.path.join(SRC_MAT, "NASCAR-Thunder-2003_Patch_Win_EN_Patch-v11", "NT 2003 Patch 1.1", "NASCAR_Thunder_2003.exe"),
        "NASCAR_2003_3DConfig": os.path.join(SRC_MAT, "NASCAR Thunder TM 2003 Demo", "3DConfig.exe"),
        "NASCAR_2004_Demo": os.path.join(SRC_MAT, "NASCAR Thunder TM 2004 Demo", "NASCAR_Thunder_2004_Demo.exe"),
        "NASCAR_2004_Retail": os.path.join(SRC_MAT, "NASCAR-Thunder-2004_Win_EN_ISO-Version", "NASCAR_Thunder_2004.exe"),
        "NASCAR_2004_retail": os.path.join(SRC_MAT, "NASCAR-Thunder-2004_retail_Win_EN", "NT 2004 retail", "NASCAR_Thunder_2004.exe"),
        "NASCAR_2004_Dedicated": os.path.join(SRC_MAT, "NASCAR-Thunder-2004_Win_EN_ISO-Version", "NT2004_Dedicated.exe"),
        "NASCAR_2004_3DConfig": os.path.join(SRC_MAT, "NASCAR Thunder TM 2004 Demo", "3DConfig.exe"),
        "rFactor": os.path.join(SRC_MAT, "rFactor", "rFactor.exe"),
        "rFactor_Dedicated": os.path.join(SRC_MAT, "rFactor", "rFactor Dedicated.exe"),
        "rFactor_Config": os.path.join(SRC_MAT, "rFactor", "rF Config.exe"),
        "SCGT": os.path.join(SRC_MAT, "Sports Car GT", "Spcar.exe"),
        "SCGT_1551": os.path.join(SRC_MAT, "scgt1551", "Spcar.exe"),
    }

    string_sets = {}
    for game, path in binaries.items():
        if not os.path.exists(path):
            print(f"  SKIP {game}: {path} not found")
            continue
        data = read_binary(path)
        strings = set(s for s in extract_strings(data, 8) if len(s) < 200)
        string_sets[game] = strings
        print(f"  {game}: {len(strings)} strings")

    if "F1C" not in string_sets:
        lines.append("ERROR: F1C exe not found")
    else:
        f1c = string_sets["F1C"]

        # For each other game, find shared and unique strings
        for game in sorted(string_sets.keys()):
            if game == "F1C":
                continue
            other = string_sets[game]
            shared = f1c & other
            only_other = other - f1c

            lines.append(f"## {game} vs F1C")
            lines.append(f"Shared: {len(shared)}, Only in {game}: {len(only_other)}")
            lines.append("")

            # Categorize shared strings
            categories = {
                "Source paths": lambda s: any(k in s for k in [".cpp", ".c ", "Source", "Dev"]),
                "Physics/Vehicle": lambda s: any(k in s.lower() for k in ["tire", "brake", "spring", "damper", "engine", "gear", "throttle", "steer", "suspension", "aero", "wing", "drag", "downforce", "camber", "toe", "ride"]),
                "Session/Race": lambda s: any(k in s.lower() for k in ["race", "session", "qualify", "practice", "grid", "pit", "lap", "flag", "caution", "formation", "replay"]),
                "UI/Gizmo": lambda s: any(k in s.lower() for k in ["gizmo", "osc", "prelink", "widget", "button", "scroll", "menu", "screen"]),
                "Network": lambda s: any(k in s.lower() for k in ["packet", "winsock", "gamespy", "server", "client", "connect", "socket", "vote", "chat"]),
                "Audio/Video": lambda s: any(k in s.lower() for k in ["sound", "audio", "miles", "bink", "mpeg", "movie", "music"]),
                "File/MAS": lambda s: any(k in s.lower() for k in [".mas", ".gdb", ".osc", ".dic", ".veh", ".hdv", "cubemas", "cubeasf"]),
            }

            for cat, test in categories.items():
                matches = sorted(s for s in shared if test(s))
                if matches:
                    lines.append(f"### {cat} ({len(matches)})")
                    for s in matches[:50]:
                        lines.append(f"  {s}")
                    if len(matches) > 50:
                        lines.append(f"  ... ({len(matches)-50} more)")
                    lines.append("")

            # Strings only in other game (potential new discoveries)
            interesting_unique = sorted(s for s in only_other
                if any(k in s.lower() for k in ["race", "vehicle", "physics", "tire", "engine",
                    "session", "damage", "weather", "gizmo", "osc", "config", "setup",
                    "player", "ai ", "scoring", "telemetry"])
                and len(s) > 10 and len(s) < 100)
            if interesting_unique:
                lines.append(f"### Unique to {game} (interesting) ({len(interesting_unique)})")
                for s in interesting_unique[:80]:
                    lines.append(f"  {s}")
                lines.append("")

    out_path = os.path.join(OUT, "string_crossref.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path}")

# ─── Task 5: rFactor SDK structs ─────────────────────────────────────────────

def extract_sdk_structs():
    print("=== Extracting SDK structs ===")
    lines = ["# rFactor SDK Struct Definitions", "",
             "From InternalsPlugin.hpp — official ISI struct layouts.", ""]

    hpp = os.path.join(SRC_MAT, "InternalsPlugin.hpp")
    if not os.path.exists(hpp):
        hpp = os.path.join(PROJECT, "03_sdk_crossref", "headers", "InternalsPlugin.hpp")
    if os.path.exists(hpp):
        with open(hpp, "r", encoding="utf-8", errors="replace") as f:
            content = f.read()
        lines.append("## Full Header")
        lines.append("```cpp")
        lines.append(content)
        lines.append("```")
    else:
        lines.append("ERROR: InternalsPlugin.hpp not found")

    out_path = os.path.join(OUT, "sdk_structs.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path}")

# ─── Task 6: F1C reference data for workers ──────────────────────────────────

def extract_f1c_reference():
    print("=== Extracting F1C reference data ===")
    lines = ["# F1C Reference Data for Cross-Referencing", "",
             "Current state of F1C documentation — workers compare against this.", ""]

    # docs/12 globals (first 200 lines as sample)
    g12 = os.path.join(ROOT, "docs", "12-globals-reference.md")
    if os.path.exists(g12):
        with open(g12, "r", encoding="utf-8", errors="replace") as f:
            content = f.readlines()
        lines.append("## docs/12 Globals Reference (sample — first 300 entries)")
        for line in content[:350]:
            lines.append(line.rstrip())
        lines.append(f"... ({len(content)} total lines)")
        lines.append("")

    # docs/13 struct offsets (first 300 lines)
    g13 = os.path.join(ROOT, "docs", "13-struct-offsets.md")
    if os.path.exists(g13):
        with open(g13, "r", encoding="utf-8", errors="replace") as f:
            content = f.readlines()
        lines.append("## docs/13 Struct Offsets (sample — first 400 lines)")
        for line in content[:450]:
            lines.append(line.rstrip())
        lines.append(f"... ({len(content)} total lines)")
        lines.append("")

    # F1C source file list
    lines.append("## F1C Known Source Files (from binary strings)")
    lines.append("Path: D:\\dev\\F1_1999_2002\\Source\\")
    src_files = [
        "ai.cpp", "camera.cpp", "camera_ed.cpp", "carhull.cpp",
        "clouds.cpp", "config.cpp", "controls.cpp", "damagemodel.cpp",
        "dynobj.cpp", "f1sounds.cpp", "f1special.cpp", "garage.cpp",
        "graphics.cpp", "grip.cpp", "hdvehicle.cpp", "lbmpeg.cpp",
        "misc.cpp", "monitor.cpp", "multimedia.cpp", "ocontrol.cpp",
        "onscreen.cpp", "options.cpp", "pitcrew.cpp", "plrfile.cpp",
        "pvehicle.cpp", "realroad.cpp", "rftracks.cpp", "steward.cpp",
        "trackdata.cpp", "vehicle.cpp", "weather.cpp"
    ]
    for f in src_files:
        lines.append(f"  {f}")
    lines.append("")

    out_path = os.path.join(OUT, "f1c_reference.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path}")

# ─── Task 7: Dev tree evolution ───────────────────────────────────────────────

def extract_dev_tree():
    print("=== Extracting dev tree map ===")
    lines = ["# ISI Development Tree Evolution", "",
             "Reconstructed from PDB paths and source strings across all binaries.", ""]

    lines.append("""```
D:\\Dev\\
├── F1\\                              (F1 2000, March 2000)
│   ├── WIN32\\Gold\\                  — f1_2000.pdb
│   └── CONFIG\\Debug\\               — F1Config.pdb
│
├── Common\\Source\\                   (F1 2002 Demo, April 2002)
│   └── 25 shared isiMotor1 files:
│       ai.cpp, camera.cpp, camera_ed.cpp, carhull.cpp, clouds.cpp,
│       controls.cpp, damagemodel.cpp, dynobj.cpp, f1sounds.cpp,
│       f1special.cpp, garage.cpp, graphics.cpp, grip.cpp, hdvehicle.cpp,
│       misc.cpp, monitor.cpp, multimedia.cpp, ocontrol.cpp, onscreen.cpp,
│       options.cpp, pitcrew.cpp, plrfile.cpp, pvehicle.cpp, realroad.cpp,
│       vehicle.cpp
│
├── F1_2002\\Source\\                  (F1 2002 Demo)
│   └── 4 game-specific: onscreen.cpp, options.cpp, plrfile.cpp, steward.cpp
│
├── F1_1999_2002\\Source\\             (F1C retail, April 2003)
│   └── 31 files (Common + specific merged):
│       + config.cpp, rftracks.cpp, trackdata.cpp, weather.cpp, f1sounds.cpp
│
├── NASCAR_2003\\Source\\              (NASCAR 2003, 2002-2003)
│   └── 34 files (32 game + config.cpp + dict.cpp):
│       + pitman.cpp, random.cpp (unique to NASCAR)
│
├── NASCAR_2004\\Source\\              (NASCAR 2004, 2003)
│   └── 34 files (same set as 2003)
│
├── CONFIG\\Debug\\                    (3DConfig.exe, NASCAR 2003)
├── CUBE41\\Library\\Source\\           (CUBE renderer, NASCAR 2003)
│   └── DX8Main.cpp, DX8Pipe.cpp, DX8Util.cpp, Particle.cpp, Shadow.cpp
├── CUBE42\\                          (CUBE renderer, NASCAR 2004)
│   ├── Config\\Debug\\               — 3DConfig.pdb
│   └── Library\\Source\\             — + Cube.cpp
│
├── ISIUtility\\Source\\               (shared utility)
│   └── FileLine.cpp
│
└── AudioDev\\Shared\\Engine\\Dev\\    (shared audio/video, all games)
    └── LbMpeg.cpp
```""")
    lines.append("")

    lines.append("## Timeline")
    lines.append("| Date | Game | Dev Path | Compiler | Notes |")
    lines.append("|------|------|----------|----------|-------|")
    lines.append("| 2000-03 | F1 2000 | D:\\Dev\\F1\\ | MSVC 6.0 | DirectDraw, TbAudioR, SafeDisc |")
    lines.append("| 2002-04 | F1 2002 Demo | D:\\Dev\\Common\\+F1_2002\\ | MSVC 6.0 SP6 | Common/specific split |")
    lines.append("| 2003-04 | F1C Retail | D:\\dev\\F1_1999_2002\\ | MSVC 6.0+7.x mixed | D3D8, Miles, merged tree |")
    lines.append("| 2003-xx | NASCAR 2003 | D:\\Dev\\NASCAR_2003\\ | MSVC 6.0+7.x mixed | CUBE41, 207 units |")
    lines.append("| 2003-08 | NASCAR 2004 | D:\\Dev\\NASCAR_2004\\ | Pure MSVC 7.x | CUBE42, 167 units |")
    lines.append("| 2007-xx | rFactor | ? | ? | isiMotor 2.0 |")

    out_path = os.path.join(OUT, "dev_tree.txt")
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"  Wrote {out_path}")

# ─── Main ────────────────────────────────────────────────────────────────────

if __name__ == "__main__":
    print(f"Source material: {SRC_MAT}")
    print(f"Output: {OUT}")
    print()
    extract_rfactor_binaries()
    extract_config_params()
    extract_hdv_pm_full()
    extract_string_crossref()
    extract_sdk_structs()
    extract_f1c_reference()
    extract_dev_tree()
    print()
    print("=== DONE ===")
    for f in sorted(os.listdir(OUT)):
        sz = os.path.getsize(os.path.join(OUT, f))
        print(f"  {f}: {sz:,} bytes")
