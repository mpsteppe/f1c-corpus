// f1c_text_log.js — log-only hook on FUN_0045BD10. No injection, no crash risk.
var g_n = 0;

Interceptor.attach(ptr(0x0045BD10), {
    onEnter: function(args) {
        g_n++;
        var p1 = args[0];
        var text = '<err>';
        try { text = p1.readUtf8String(120); } catch(e) {}
        var slot_idx = 0, slot0_timer = 0;
        try { slot_idx   = p1.add(0x31c).readU32(); } catch(e) {}
        try { slot0_timer = p1.add(0x90).readFloat(); } catch(e) {}
        send({
            n: g_n,
            p1: p1.toString(),
            p2: args[1].toInt32(),
            p3: '0x' + args[2].toUInt32().toString(16),
            text: text.slice(0, 120),
            slot_idx: slot_idx,
            slot0_timer: slot0_timer,
            tid: Process.getCurrentThreadId()
        });
    }
});

send({ ready: true });
