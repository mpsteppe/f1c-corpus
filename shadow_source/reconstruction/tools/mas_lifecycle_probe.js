/*
 * Read-only MAS lifecycle/thread probe for F1 Challenge Online.exe.
 * Records function entry/exit, thread IDs, results, output pointers and
 * post-mutation list invariants. It never writes target memory.
 */
'use strict';

const moduleName = 'F1 Challenge Online.exe';
const imageBase = ptr('0x00400000');
const moduleBase = Process.getModuleByName(moduleName).base;

function at(va) {
  return moduleBase.add(ptr(va).sub(imageBase));
}

const gHead = at('0x008B8F14');
const gCount = at('0x008B6AC0');

function safeU32(address) {
  try { return address.readU32(); } catch (_) { return null; }
}

function safePointer(address) {
  try { return address.readPointer(); } catch (_) { return null; }
}

function safeString(address, limit) {
  if (address === null || address.isNull()) return null;
  try {
    const bytes = new Uint8Array(address.readByteArray(limit));
    let nul = -1;
    for (let i = 0; i < bytes.length; i++) {
      if (bytes[i] === 0) { nul = i; break; }
    }
    return {
      preview: nul >= 0 ? address.readCString() : '<unterminated>',
      terminated_within_limit: nul >= 0,
      terminator_offset: nul >= 0 ? nul : null,
      examined_bytes: limit
    };
  } catch (_) {
    return { preview: '<unreadable>', terminated_within_limit: null,
             terminator_offset: null, examined_bytes: limit };
  }
}

function hexPointer(value) {
  return value === null ? null : value.toString();
}

function snapshotList() {
  const declared = safeU32(gCount);
  const head = safePointer(gHead);
  if (head === null) {
    return { readable: false, declared_count: declared, error: 'head_unreadable' };
  }
  const seen = Object.create(null);
  let node = head;
  let previous = ptr(0);
  let traversed = 0;
  let reciprocal = true;
  let error = null;
  while (!node.isNull() && traversed < 4096) {
    const key = node.toString();
    if (seen[key]) { error = 'cycle'; break; }
    seen[key] = true;
    const back = safePointer(node.add(0x12c));
    const next = safePointer(node.add(0x130));
    if (back === null || next === null) { error = 'node_unreadable'; break; }
    if (!back.equals(previous)) reciprocal = false;
    previous = node;
    node = next;
    traversed++;
  }
  if (traversed >= 4096 && !node.isNull()) error = 'walk_limit';
  return {
    readable: error !== 'node_unreadable',
    head: hexPointer(head),
    declared_count: declared,
    traversed_count: traversed,
    count_matches: declared !== null && declared === traversed,
    reciprocal_back_links: reciprocal,
    error: error
  };
}

function emit(kind, name, extra) {
  send(Object.assign({
    schema_version: 1,
    kind: kind,
    function: name,
    thread_id: Process.getCurrentThreadId(),
    timestamp_ms: Date.now()
  }, extra || {}));
}

function hookPhase(name, va) {
  Interceptor.attach(at(va), {
    onEnter() { emit('phase_enter', name); },
    onLeave(retval) { emit('phase_leave', name, { result: retval.toInt32() }); }
  });
}

const markerSeen = Object.create(null);
function hookThreadMarker(name, va) {
  Interceptor.attach(at(va), {
    onEnter() {
      const tid = Process.getCurrentThreadId();
      const key = name + ':' + tid;
      if (!markerSeen[key]) {
        markerSeen[key] = true;
        emit('thread_marker', name);
      }
    }
  });
}

Interceptor.attach(at('0x0053CBC0'), {
  onEnter(args) {
    this.output = args[0];
    this.filename = args[1];
    this.before = snapshotList();
    emit('call_enter', 'mas_root_load', {
      output_slot: hexPointer(this.output),
      filename_pointer: hexPointer(this.filename),
      filename: safeString(this.filename, 512),
      list: this.before
    });
  },
  onLeave(retval) {
    let produced = null;
    if (this.output !== null && !this.output.isNull()) produced = safePointer(this.output);
    emit('call_leave', 'mas_root_load', {
      result: retval.toInt32(),
      output_slot: hexPointer(this.output),
      output_value: hexPointer(produced),
      list: snapshotList()
    });
  }
});

Interceptor.attach(at('0x0053CE40'), {
  onEnter(args) {
    this.object = args[0];
    emit('call_enter', 'mas_remove_one', {
      object: hexPointer(this.object), list: snapshotList()
    });
  },
  onLeave(retval) {
    emit('call_leave', 'mas_remove_one', {
      object: hexPointer(this.object), result: retval.toInt32(), list: snapshotList()
    });
  }
});

Interceptor.attach(at('0x0053CED0'), {
  onEnter() { emit('call_enter', 'mas_prune_marked', { list: snapshotList() }); },
  onLeave(retval) {
    emit('call_leave', 'mas_prune_marked', { result: retval.toInt32(), list: snapshotList() });
  }
});

Interceptor.attach(at('0x00494FE0'), {
  onEnter(args) {
    this.output = args[1];
    emit('call_enter', 'mas_checked_load_bridge', {
      filename_pointer: hexPointer(args[0]), output_slot: hexPointer(this.output)
    });
  },
  onLeave(retval) {
    let produced = null;
    if (this.output !== null && !this.output.isNull()) produced = safePointer(this.output);
    emit('call_leave', 'mas_checked_load_bridge', {
      result: retval.toInt32(), output_value: hexPointer(produced)
    });
  }
});

hookThreadMarker('game_main_entry', '0x0045B200');
hookThreadMarker('main_loop_tick', '0x0042D8A0');
hookThreadMarker('network_thread_entry', '0x00583D90');
hookPhase('scene_top_level_parser', '0x0055B200');
hookPhase('vertex_buffer_resource_setup', '0x00543FA0');
hookPhase('resource_manager_shutdown', '0x004963D0');

rpc.exports = {
  snapshot() { return snapshotList(); }
};

emit('probe_ready', 'mas_lifecycle_probe', {
  module_base: moduleBase.toString(),
  initial_list: snapshotList(),
  policy: 'read_only'
});
