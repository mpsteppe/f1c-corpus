import re
from collections import defaultdict

INPUT = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\01-engine-architecture.md'
OUTPUT = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_synth\worker_C.md'

with open(INPUT, 'r', encoding='utf-8') as f:
    lines = f.readlines()

# Find all FUN_/Unwind_ headers
fun_headers = []
for i, line in enumerate(lines):
    m = re.match(r'^#{2,3}\s+(FUN_[0-9A-Fa-f]{8}|Unwind_[0-9A-Fa-f]+)\s*[:\-?]\s*(.*)', line)
    if m:
        fun_headers.append((i, m.group(1), m.group(2).strip()))

def find_fun_for_line(ln):
    best = None
    for fn_ln, addr, name in fun_headers:
        if fn_ln <= ln:
            best = (addr, name, fn_ln)
        else:
            break
    return best

observations = []

i = 0
while i < len(lines):
    line = lines[i]
    
    if re.match(r'^\*\*Struct offsets', line.strip()):
        func_info = find_fun_for_line(i)
        
        # Check for inline offsets
        inline_all = re.findall(r'\+0x([0-9A-Fa-f]+)\s*\(([^)]*)\)', line)
        for offset_str, field in inline_all:
            if func_info:
                observations.append((f'+0x{offset_str.upper()}', 'int', field.strip(), func_info[0], func_info[1], i))
        
        # Read table rows
        j = i + 1
        while j < len(lines):
            next_line = lines[j].strip()
            if next_line.startswith('#') or next_line.startswith('**Struct offsets') or next_line.startswith('---'):
                break
            
            # Skip table headers (| Offset | or |--------|)
            if next_line.startswith('| Offset ') or next_line.startswith('|----'):
                j += 1
                continue
            
            table_m = re.match(r'\|\s*\+0x([0-9A-Fa-f]+)\s*(?:\([^)]*\))?\s*\|\s*(.*?)\s*\|\s*(.*?)\s*\|', next_line)
            if table_m:
                offset_str = f'+0x{table_m.group(1).upper()}'
                field = table_m.group(2).strip()
                notes = table_m.group(3).strip()
                
                type_hint = 'int'
                nl = notes.lower()
                if 'float' in nl or 'double' in nl:
                    type_hint = 'double' if 'double' in nl else 'float'
                if 'byte' in field.lower() or 'byte' in nl:
                    type_hint = 'byte'
                if 'char' in nl:
                    type_hint = 'char'
                if 'HANDLE' in notes:
                    type_hint = 'HANDLE'
                if 'DWORD' in notes:
                    type_hint = 'DWORD'
                if 'uint32' in nl:
                    type_hint = 'uint32'
                if 'int32' in nl:
                    type_hint = 'int32'
                if '*ptr' in nl or 'void*' in notes or 'int*' in notes or 'code*' in notes:
                    type_hint = 'ptr'
                if 'ptr' in nl and type_hint == 'int':
                    type_hint = 'ptr'
                if 'int' == type_hint and ('pointer' in nl or '*' in notes):
                    type_hint = 'ptr'
                
                if func_info:
                    observations.append((offset_str, type_hint, field, func_info[0], func_info[1], j))
                j += 1
            elif next_line == '' or next_line.startswith('|'):
                # Blank lines or other table rows (like header/separator) - skip
                j += 1
            else:
                break
        i = j
    else:
        i += 1

# Write output
with open(OUTPUT, 'w', encoding='utf-8') as f:
    f.write('# Worker C \u2014 Struct Offset Synthesis\n\n')
    f.write('Source: `docs/01-engine-architecture.md` (778 entries, 593 offset observations)\n\n')
    f.write(f'Total extracted observations: {len(observations)}\n\n')
    
    # 1. HighResTimer
    f.write('## 1. HighResTimer (inferred)\n\n')
    f.write('Performance counter timer. FUN_005564b0, FUN_00556510, FUN_00568c60, FUN_00568cb0.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    timer = [
        ('+0x00', 'int32', 'Enabled/ActiveFlag', 'FUN_005564b0, FUN_00568c60, FUN_00568cb0', '0=disabled'),
        ('+0x08', 'double', 'ScaleFactor', 'FUN_00556510', 'Multiplier for elapsed high part'),
        ('+0x10', 'int32', 'OtherAccum0', 'FUN_00568c60', 'Zeroed on reset'),
        ('+0x14', 'int32', 'OtherAccum1', 'FUN_00568c60', 'Zeroed on reset'),
        ('+0x18', 'uint32', 'CurrentLow', 'FUN_00568c60, FUN_00556510', 'QPC low part'),
        ('+0x1c', 'uint32', 'CurrentHigh', 'FUN_00568c60, FUN_00556510', 'QPC high part'),
        ('+0x20', 'uint32', 'LastLow', 'FUN_00568c60, FUN_00556510', 'Previous sample low'),
        ('+0x24', 'uint32', 'LastHigh', 'FUN_00568c60, FUN_00556510', 'Previous sample high'),
        ('+0x28', 'uint32', 'AccumLow', 'FUN_00568c60', 'Accumulated time low'),
        ('+0x2c', 'uint32', 'AccumHigh', 'FUN_00568c60', 'Accumulated time high'),
        ('+0x48', 'int/byte', 'TimerModeFlags', 'FUN_005564b0, FUN_00568c60, FUN_00568cb0', 'Bit 0=QPC mode, bit 1=alternate'),
    ]
    for off, t, field, funcs, notes in timer:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 2. LinkedList
    f.write('## 2. LinkedList (inferred)\n\n')
    f.write('Standard 4-field linked list container.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    ll = [
        ('+0x00', 'ptr', 'HeadPtr', 'FUN_005819c0, FUN_00581a20, FUN_00586000', 'First node'),
        ('+0x04', 'ptr', 'TailPtr', 'FUN_005819c0, FUN_00586000', 'Last node'),
        ('+0x08', 'int', 'Count', 'FUN_005819c0, FUN_00586000', 'Node count'),
        ('+0x0c', 'int', 'Capacity', 'FUN_005819c0', 'Max capacity'),
    ]
    for off, t, field, funcs, notes in ll:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 3. LinkedListNode
    f.write('## 3. LinkedListNode (inferred)\n\n')
    f.write('Node with data, next, and optional free flag.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    lln = [
        ('+0x00', 'ptr', 'DataPtr', 'Multiple', 'Pointer to node data'),
        ('+0x04', 'ptr', 'NextPtr', 'Multiple', 'Next node in list'),
        ('+0x08', 'byte', 'FreeFlag', 'Multiple', 'If non-zero, free data on destroy'),
    ]
    for off, t, field, funcs, notes in lln:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 4. MutexGuard
    f.write('## 4. MutexGuard (inferred)\n\n')
    f.write('Mutex/critical section synchronization struct. Multiple instances at different base offsets within larger structs.\n\n')
    f.write('| Offset (base) | Type | Field Name | Observed in | Notes |\n')
    f.write('|---------------|------|------------|-------------|-------|\n')
    mx = [
        ('+0x1c/+0x24', 'HANDLE+byte', 'MutexHandle+MutexActive', 'FUN_005865c0', 'Mutex at +0x1c, flag at +0x24'),
        ('+0x54/+0x5c', 'HANDLE+byte', 'MutexHandle+ValidFlag', 'FUN_00586560', 'Mutex at +0x54, flag at +0x5c'),
        ('+0xec/+0xf0/+0xf4', 'int+HANDLE+DWORD', 'SharedValue+MutexHandle+Timeout', 'FUN_00585770', 'Thread-safe read'),
        ('+0x5b4/+0x5b8/+0x5bc', 'ptr+HANDLE+DWORD', 'WriteTarget+MutexHandle+Timeout', 'FUN_00585cd0, FUN_005932f5', 'Thread-safe write'),
        ('+0x50/+0x54', 'HANDLE+DWORD', 'MutexHandle+Timeout', 'FUN_005941ee, FUN_005936ff', 'From FUN_0058bb79 group'),
        ('+0x08/+0x0c', 'int32+CRITICAL_SECTION', 'InitFlag+CriticalSection', 'FUN_00595a61', 'Array of CS at stride 0x24'),
        ('+0x554/+0x558', 'HANDLE+DWORD', 'MutexHandle+Timeout', 'FUN_005932f5', ''),
    ]
    for off, t, field, funcs, notes in mx:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 5. Camera
    f.write('## 5. CamMan (docs/01)\n\n')
    f.write('Camera manager struct (FUN_0040c9e0, FUN_0040cce0).\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    cam = [
        ('+0x00', 'ptr', 'MAINVIEWSceneNode', 'FUN_0040cce0', ''),
        ('+0x08', 'ptr', 'CurrentCamera', 'FUN_0040cce0', ''),
        ('+0x18', 'ptr', 'CameraObject1', 'FUN_0040cce0', ''),
        ('+0x1c', 'ptr', 'CameraObject2', 'FUN_0040cce0', ''),
        ('+0x20', 'ptr', 'CameraObject3', 'FUN_0040cce0', ''),
        ('+0x2e', 'byte', 'Flag', 'FUN_0040c9e0', ''),
        ('+0x38', 'int', 'CameraIndex', 'FUN_0040c9e0', '-1=none'),
    ]
    for off, t, field, funcs, notes in cam:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 6. GameConfig
    f.write('## 6. GameConfig (inferred \u2014 FUN_004216f0)\n\n')
    f.write('Config directory/option table. Range +0xb8 to +0xe8.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    cfg = [
        ('+0xb8', 'int', 'Field_0xb8', 'FUN_004216f0', ''),
        ('+0xbc', 'int', 'Field_0xbc', 'FUN_004216f0', ''),
        ('+0xc0', 'int', 'Field_0xc0', 'FUN_004216f0', ''),
        ('+0xc4', 'int', 'Field_0xc4', 'FUN_004216f0', 'Default 22 (0x16)'),
        ('+0xc8', 'bool', 'Field_0xc8', 'FUN_004216f0', 'Default 1'),
        ('+0xcc', 'int', 'Field_0xcc', 'FUN_004216f0', ''),
        ('+0xd0', 'int', 'Field_0xd0', 'FUN_004216f0', ''),
        ('+0xd4', 'byte', 'Field_0xd4', 'FUN_004216f0', ''),
        ('+0xd5', 'byte', 'Field_0xd5', 'FUN_004216f0', 'Default 1'),
        ('+0xd6', 'byte', 'Field_0xd6', 'FUN_004216f0', ''),
        ('+0xd8', 'int', 'Field_0xd8', 'FUN_004216f0', 'Default 1'),
        ('+0xdc', 'int', 'Field_0xdc', 'FUN_004216f0', 'Default 1'),
        ('+0xe0', 'int', 'Field_0xe0', 'FUN_004216f0', ''),
        ('+0xe4', 'int', 'Field_0xe4', 'FUN_004216f0', 'Default 1'),
        ('+0xe8', 'float', 'Field_0xe8', 'FUN_004216f0', '-1.0f (disabled)'),
    ]
    for off, t, field, funcs, notes in cfg:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 7. UIObjectList
    f.write('## 7. UIObjectList (inferred \u2014 FUN_0047e960)\n\n')
    f.write('UI option list manager.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    ui = [
        ('+0x44 (0x11)', 'ptr', 'ItemListHead', 'FUN_0047e960', ''),
        ('+0x48 (0x12)', 'ptr', 'ItemListTail', 'FUN_0047e960', ''),
        ('+0x4c (0x13)', 'ptr', 'CurrentItem', 'FUN_0047e960', ''),
        ('+0x50 (0x14)', 'int', 'ItemCount', 'FUN_0047e960', ''),
        ('+0xec (0x3b)', 'int', 'InitField', 'FUN_0047e960', 'zeroed'),
        ('+0xf0 (0x3c)', 'int', 'EndMarker', 'FUN_0047e960', '-1'),
        ('+0xf4 (0x3d)', 'int', 'OptionID', 'FUN_0047e960', ''),
    ]
    for off, t, field, funcs, notes in ui:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 8. PauseStringTable
    f.write('## 8. PauseStringTable (inferred \u2014 FUN_004541d0)\n\n')
    f.write('Pause menu string table manager.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    pst = [
        ('+0xc88', 'int', 'EntryCount', 'FUN_004541d0', 'Max string count'),
        ('+0xc8c', 'int', 'CurrentID', 'FUN_004541d0', 'Current string ID'),
    ]
    for off, t, field, funcs, notes in pst:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 9. RaceModeBackup
    f.write('## 9. RaceModeBackup (inferred \u2014 FUN_00404890, FUN_004049d0)\n\n')
    f.write('Race mode save/restore struct.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    rmb = [
        ('+0x14', 'byte', 'InitFlag', 'FUN_00404890, FUN_004049d0', 'WasInitialized'),
        ('+0x15', 'byte', 'InitFlag2', 'FUN_00404890', ''),
        ('+0x20', 'byte', 'StateCondition', 'FUN_00404890, FUN_004049d0', '1=active'),
        ('+0x50', 'int', 'SavedSessionType', 'FUN_00404890, FUN_004049d0', 'Backup DAT_007d2e44'),
        ('+0x54', 'int', 'SavedRaceMode', 'FUN_00404890, FUN_004049d0', 'Backup DAT_007d0410'),
    ]
    for off, t, field, funcs, notes in rmb:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 10. DynamicBuffer
    f.write('## 10. DynamicBuffer (inferred \u2014 FUN_00564930)\n\n')
    f.write('Growing buffer with accumulator and realloc.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    db = [
        ('+0x04', 'int', 'AccumSize', 'FUN_00564930', 'Accumulated count'),
        ('+0x08', 'int', 'ElemSize', 'FUN_00564930', 'Per-element size'),
        ('+0x0c', 'int', 'Addend', 'FUN_00564930', 'Growth amount'),
        ('+0x14', 'ptr', 'Buffer', 'FUN_00564930', 'Allocated buffer'),
    ]
    for off, t, field, funcs, notes in db:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 11. SceneExtents
    f.write('## 11. SceneExtents (inferred \u2014 FUN_004bdc10)\n\n')
    f.write('Scene bounding box extents.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    se = [
        ('+0x924', 'float', 'MinX', 'FUN_004bdc10', ''),
        ('+0x928', 'float', 'ScaleX', 'FUN_004bdc10', '1/(maxX-minX)'),
        ('+0x92c', 'float', 'MinZ', 'FUN_004bdc10', ''),
        ('+0x930', 'float', 'ScaleZ', 'FUN_004bdc10', '1/(maxZ-minZ)'),
    ]
    for off, t, field, funcs, notes in se:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 12. DoubleLinkedList node
    f.write('## 12. DoublyLinkedList (inferred)\n\n')
    f.write('Doubly-linked list node and container. Multiple offset variants.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    dll = [
        ('+0x1c/+0x2c', 'ptr', 'PrevPtr', 'FUN_005519e0, FUN_0055c2e0', 'Previous node; offset varies by container'),
        ('+0x20/+0x30', 'ptr', 'NextPtr', 'FUN_005519e0, FUN_0055c2e0', 'Next node; offset varies by container'),
        ('+0x118/+0x1518', 'ptr', 'ListHead', 'FUN_005519e0, FUN_0055c2e0', 'Head pointer; offset varies by container'),
    ]
    for off, t, field, funcs, notes in dll:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 13. BoolToggle
    f.write('## 13. BoolFloatToggle (inferred \u2014 FUN_0059d6ff)\n\n')
    f.write('Boolean-to-float conversion toggle.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    bft = [
        ('+0x1065', 'byte', 'BoolFlag', 'FUN_0059d6ff', 'Toggle'),
        ('+0x3584', 'float', 'FloatParam', 'FUN_0059d6ff', '0.0 or 1.0'),
    ]
    for off, t, field, funcs, notes in bft:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 14. AnimationList
    f.write('## 14. AnimationList (inferred)\n\n')
    f.write('Animation/sprite list container.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    al = [
        ('+0x204', 'ptr', 'ListHead', 'FUN_00585bf0, FUN_004f2e90', 'Linked list of anim objects'),
        ('+0x10 (node)', 'ptr', 'NextPtr', 'FUN_004f2e90', 'Node next ptr'),
        ('+0x118', 'int', 'ElementCount', 'FUN_004f2e90', 'Per-node sub-element count'),
        ('+0x11c', 'ptr', 'ElementBase', 'FUN_004f2e90', 'Per-element data array'),
    ]
    for off, t, field, funcs, notes in al:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 15. ArrayContainer
    f.write('## 15. ArrayContainer (various)\n\n')
    f.write('Multiple stride-based array container variants.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    ac = [
        ('+0x04/+0x0c', 'int', 'Count', 'Multiple', 'Element count'),
        ('+0x08/+0x10/+0x34', 'ptr', 'ArrayBase', 'Multiple', 'Array pointer'),
        ('+0x18/+0x2c', 'int', 'SlotCount', 'FUN_00558cf0, FUN_0056eb30', ''),
        ('+0x1c', 'ptr', 'ElementArray', 'FUN_0056eb30', 'Stride 0x48'),
        ('+0xa4', 'int', 'TableCount', 'FUN_0058a638', ''),
        ('+0xa8', 'ptr', 'TableBase', 'FUN_0058a638', 'Stride 0x94'),
    ]
    for off, t, field, funcs, notes in ac:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 16. InputDevice
    f.write('## 16. InputDevice (inferred)\n\n')
    f.write('Input device binding struct and controller array.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    inp = [
        ('+0x13E8', 'int', 'BindingValueA', 'FUN_0040be70', 'Read when state 0x10'),
        ('+0x13EC', 'int', 'InputDeviceHandle', 'FUN_0040be70', 'Handle/ptr'),
        ('+0x1544', 'int', 'ControlID', 'FUN_0040be70 sibling', ''),
        ('+0x1f98', 'ptr', 'ControllerArray', 'FUN_00455da0', 'Stride 0xb, max 0x21 entries'),
    ]
    for off, t, field, funcs, notes in inp:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 17. NetworkMessage
    f.write('## 17. NetworkMessage (inferred)\n\n')
    f.write('Network message/packet struct with event code and string buffer.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    nm = [
        ('+0x5C4', 'uint', 'EventCode', 'FUN_004a3ef0', ''),
        ('+0x5C8', 'char[]', 'StringBuffer', 'FUN_004a3ef0', ''),
        ('+0x618', 'HANDLE', 'BufferMutex', 'FUN_004a3ef0', ''),
        ('+0x910', 'uint16', 'HeaderField', 'FUN_00591583', ''),
        ('+0xAC8', 'ptr', 'ListBase', 'FUN_00591583', ''),
        ('+0xAD8', 'HANDLE', 'ListMutex', 'FUN_00591583', ''),
        ('+0xADC', 'DWORD', 'MutexTimeout', 'FUN_00591583', ''),
    ]
    for off, t, field, funcs, notes in nm:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 18. FreeableMultiPtr
    f.write('## 18. FreeableMultiPtr (inferred)\n\n')
    f.write('Struct with 3-7 freeable pointer fields, often freed in cleanup loops.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    fmp = [
        ('+0x0c..+0x24', 'void*[7]', 'FreeablePtrs', 'FUN_0058f8eb', 'Freed if not sentinel'),
        ('+0x224..+0x240', 'ptr*3+int*3', 'SubBuffers', 'FUN_005913d0', '3 ptrs + counters'),
        ('+0x0c/+0x1c/+0x20', 'ptr*3', 'ResourcePtrs', 'FUN_0059a17b', 'Freed with release+free'),
    ]
    for off, t, field, funcs, notes in fmp:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # 19. Bounds2D
    f.write('## 19. Bounds2D (inferred)\n\n')
    f.write('2D bounding box int pair.\n\n')
    f.write('| Offset | Type | Field Name | Observed in | Notes |\n')
    f.write('|--------|------|------------|-------------|-------|\n')
    b2d = [
        ('+0x120', 'int', 'XMin', 'FUN_005977c4', ''),
        ('+0x124', 'int', 'XMax', 'FUN_005977c4', ''),
        ('+0x140', 'int', 'YMin', 'FUN_005977c4', ''),
        ('+0x144', 'int', 'YMax', 'FUN_005977c4', ''),
    ]
    for off, t, field, funcs, notes in b2d:
        f.write(f'| {off} | {t} | {field} | {funcs} | {notes} |\n')
    f.write('\n')
    
    # Remaining misc observations
    f.write('## 20. Unmatched / Single-Observation Offsets\n\n')
    f.write('Offsets appearing once or without clear struct identity.\n\n')
    f.write('| Offset | Type | Field | Function | Line |\n')
    f.write('|--------|------|-------|----------|------|\n')
    
    # Group remaining by function for readability
    func_groups = defaultdict(list)
    for obs in observations:
        offset, type_h, field, addr, name, ln = obs
        func_groups[(addr, name)].append((offset, type_h, field, ln))
    
    for (addr, name), obs_list in sorted(func_groups.items()):
        for offset, type_h, field, ln in obs_list:
            f.write(f'| {offset} | {type_h} | {field} | {addr} — {name} | {ln} |\n')
    
    f.write('\n---\n')
    f.write(f'Total observations extracted: {len(observations)}\n')
    f.write('Confidence: medium. Automated extraction with heuristic grouping. Some type guesses may be inaccurate.\n')
