// f1c_text_caller.js — log return address of every BD10 call to find the actual call site.
// Also hook _strncpy to catch when penalty text ("DQ", "Penalt") is copied anywhere.
// This tells us WHERE the persistent display storage is.

var g_n = 0;

// Hook FUN_0045BD10 — log return address (= caller's call site)
Interceptor.attach(ptr(0x0045BD10), {
    onEnter: function(args) {
        g_n++;
        var ret = this.returnAddress;
        var p1 = args[0];
        // Read text — use CString (null-terminated) instead of readUtf8String(N)
        var text = '';
        try { text = p1.readCString(); } catch(e) { text = '<err:' + e.message + '>'; }
        // Only log non-0x5ec4cc calls and every 200th 0x5ec4cc call
        var is_global = (p1.toUInt32() === 0x5ec4cc);
        if (!is_global || g_n % 200 === 1) {
            send({
                t: 'bd10',
                n: g_n,
                p1: p1.toString(),
                ret: ret.toString(),
                text: text.slice(0, 80)
            });
        }
    }
});

// Hook FUN_0045bde0 and FUN_0045bdf0 — the two thin wrappers called alongside BD10
// to understand their ECX (= the persistent display manager)
[0x0045bde0, 0x0045bdf0, 0x0045ba60, 0x0045b9a0].forEach(function(addr) {
    Interceptor.attach(ptr(addr), {
        onEnter: function(args) {
            send({
                t: 'wrapper',
                fn: '0x' + addr.toString(16),
                ecx: this.context.ecx.toString(),
                ret: this.returnAddress.toString()
            });
        }
    });
});

send({ ready: true, msg: 'Hooked. Trigger penalty to see caller addresses.' });
