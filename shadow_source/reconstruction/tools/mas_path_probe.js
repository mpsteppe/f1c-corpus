/*
 * Read-only MAS path/search-order probe for F1 Challenge Online.exe.
 * Observes root filenames, registered prefixes, and file-open calls made while
 * the root is active. It never writes target memory or invokes target code.
 */
'use strict';

const moduleName = 'F1 Challenge Online.exe';
const imageBase = ptr('0x00400000');
const moduleBase = Process.getModuleByName(moduleName).base;
const gPrefixCount = moduleBase.add(ptr('0x008B8E30').sub(imageBase));
const gPrefixBase = moduleBase.add(ptr('0x008B5A3C').sub(imageBase));
const rootAddress = moduleBase.add(ptr('0x0053CBC0').sub(imageBase));
const openAddress = moduleBase.add(ptr('0x00587DB0').sub(imageBase));
const rootDirectReturn = moduleBase.add(ptr('0x0053CC13').sub(imageBase));
const rootFallbackReturn = moduleBase.add(ptr('0x0053CC5A').sub(imageBase));

function emit(kind, extra) {
  send(Object.assign({
    schema_version: 1,
    kind: kind,
    thread_id: Process.getCurrentThreadId(),
    timestamp_ms: Date.now()
  }, extra || {}));
}

function boundedString(address, limit) {
  if (address === null || address.isNull()) {
    return { preview: null, terminated_within_limit: null, terminator_offset: null,
             examined_bytes: 0 };
  }
  try {
    const bytes = new Uint8Array(address.readByteArray(limit));
    let nul = -1;
    for (let i = 0; i < bytes.length; i++) {
      if (bytes[i] === 0) { nul = i; break; }
    }
    let preview = '<unterminated>';
    // The bounded byte scan has already established a readable terminator.
    // Omitting Frida's size avoids treating that size as declared string data.
    if (nul >= 0) preview = address.readCString();
    return {
      preview: preview,
      terminated_within_limit: nul >= 0,
      terminator_offset: nul >= 0 ? nul : null,
      examined_bytes: limit
    };
  } catch (_) {
    return { preview: '<unreadable>', terminated_within_limit: null,
             terminator_offset: null, examined_bytes: limit };
  }
}

function pointerText(value) {
  return value === null ? null : value.toString();
}

function prefixSnapshot() {
  let count;
  try { count = gPrefixCount.readS32(); } catch (_) {
    return { readable: false, error: 'count_unreadable' };
  }
  if (count < 0 || count > 4096) {
    return { readable: false, count: count, error: 'count_out_of_probe_bounds' };
  }
  const entries = [];
  for (let i = 0; i < count; i++) {
    entries.push({ index: i, value: boundedString(gPrefixBase.add(i * 0x84), 0x84) });
  }
  return { readable: true, count: count, stride: 0x84, entries: entries };
}

let nextCallId = 1;
const activeByThread = Object.create(null);

Interceptor.attach(rootAddress, {
  onEnter(args) {
    const tid = Process.getCurrentThreadId();
    const stack = activeByThread[tid] || [];
    this.callId = nextCallId++;
    this.tid = tid;
    stack.push(this.callId);
    activeByThread[tid] = stack;
    emit('root_enter', {
      call_id: this.callId,
      filename_pointer: pointerText(args[1]),
      filename: boundedString(args[1], 1024),
      prefixes: prefixSnapshot()
    });
  },
  onLeave(retval) {
    emit('root_leave', { call_id: this.callId, result: retval.toInt32() });
    const stack = activeByThread[this.tid] || [];
    if (stack.length > 0) stack.pop();
  }
});

Interceptor.attach(openAddress, {
  onEnter(args) {
    const tid = Process.getCurrentThreadId();
    const stack = activeByThread[tid] || [];
    this.callId = stack.length > 0 ? stack[stack.length - 1] : null;
    this.path = boundedString(args[0], 1024);
    this.mode = boundedString(args[1], 16);
    this.returnAddressText = this.returnAddress.toString();
    if (this.returnAddress.equals(rootDirectReturn)) this.site = 'root_direct';
    else if (this.returnAddress.equals(rootFallbackReturn)) this.site = 'root_fallback';
    else this.site = this.callId === null ? 'outside_root' : 'nested_parser_or_helper';
  },
  onLeave(retval) {
    if (this.callId !== null || this.site === 'root_direct' || this.site === 'root_fallback') {
      emit('open_attempt', {
        call_id: this.callId,
        site: this.site,
        return_address: this.returnAddressText,
        path: this.path,
        mode: this.mode,
        succeeded: !retval.isNull()
      });
    }
  }
});

rpc.exports = { prefixes: prefixSnapshot };

emit('probe_ready', {
  module_base: moduleBase.toString(),
  policy: 'read_only_observation_only',
  prefixes: prefixSnapshot()
});
