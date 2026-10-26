"""COFF timestamp + VERSIONINFO string-table scrape (no resource-dir parsing,
just UTF-16LE string scan for known VS_VERSION_INFO keys). Cheap, stdlib only.
"""
import struct, sys, datetime, re

KEYS = [b'C\0o\0m\0p\0a\0n\0y\0N\0a\0m\0e\0', b'P\0r\0o\0d\0u\0c\0t\0N\0a\0m\0e\0',
        b'F\0i\0l\0e\0D\0e\0s\0c\0r\0i\0p\0t\0i\0o\0n\0', b'C\0o\0m\0m\0e\0n\0t\0s\0',
        b'P\0r\0i\0v\0a\0t\0e\0B\0u\0i\0l\0d\0', b'S\0p\0e\0c\0i\0a\0l\0B\0u\0i\0l\0d\0',
        b'I\0n\0t\0e\0r\0n\0a\0l\0N\0a\0m\0e\0', b'O\0r\0i\0g\0i\0n\0a\0l\0F\0i\0l\0e\0n\0a\0m\0e\0',
        b'L\0e\0g\0a\0l\0C\0o\0p\0y\0r\0i\0g\0h\0t\0']

def dump(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:2] != b'MZ':
        print("  not PE"); return
    e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
    ts = struct.unpack_from('<I', data, e_lfanew + 8)[0]
    try:
        dt = datetime.datetime.utcfromtimestamp(ts).isoformat()
    except Exception:
        dt = f"raw={ts}"
    print(f"  COFF TimeDateStamp: {dt}")

    for key in KEYS:
        idx = 0
        found = []
        label = key.decode('utf-16-le')
        while True:
            idx = data.find(key, idx)
            if idx == -1:
                break
            # value follows: aligned utf-16 string right after key + padding, terminated by \0\0
            tail = data[idx+len(key):idx+len(key)+200]
            # find first non-null run of utf-16 chars after skipping alignment nulls
            m = re.search(rb'((?:[^\x00]\x00){1,80})', tail)
            if m:
                val = m.group(1).decode('utf-16-le', errors='replace').strip()
                if val and val not in found:
                    found.append(val)
            idx += len(key)
        for v in found[:1]:
            print(f"  {label}: {v}")

if __name__ == '__main__':
    for p in sys.argv[1:]:
        print(f"=== {p} ===")
        try:
            dump(p)
        except Exception as e:
            print(f"  ERROR: {e}")
