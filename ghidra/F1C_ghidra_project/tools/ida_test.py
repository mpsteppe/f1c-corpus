"""Minimal IDA test — verifies headless execution works."""
import sys
import os

LOG = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ida_test_output.txt")

try:
    import idc
    import idaapi
    import idautils

    idaapi.auto_wait()

    lines = []
    lines.append("IDA test script running OK")
    lines.append(f"IDA SDK: {idaapi.IDA_SDK_VERSION}")

    count = 0
    for ea in idautils.Functions():
        count += 1
    lines.append(f"Functions: {count}")

    segs = []
    for seg_ea in idautils.Segments():
        segs.append(idc.get_segm_name(seg_ea))
    lines.append(f"Segments: {', '.join(segs)}")

    output = "\n".join(lines)
    print(output)

    with open(LOG, "w") as f:
        f.write(output + "\n")

    print(f"Log written to: {LOG}")
    idaapi.qexit(0)

except Exception as e:
    msg = f"ERROR: {e}"
    print(msg)
    try:
        with open(LOG, "w") as f:
            f.write(msg + "\n")
    except:
        pass
    sys.exit(1)
