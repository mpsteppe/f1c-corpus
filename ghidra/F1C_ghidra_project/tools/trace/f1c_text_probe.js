// f1c_text_probe.js
// Probe FUN_0045BD10 (Text Line Wrapping and Rendering) from the game's own thread.
//
// Step 1: Log every call — param_1, param_2, param_3, text at param_1[0..80],
//         thread id, and the slot-tracking byte at param_1[0x31c] (slot count).
// Step 2: On the 2nd real call, test calling FUN_0045BD10 again from onLeave
//         (still game thread, caller stack intact) with "RED FLAG" written to
//         param_1[0] so the function renders our text in the same struct context.
//
// To trigger calls: cut-track penalty, or just watch gear messages during practice.

var FN_TEXT = ptr(0x0045BD10);
var g_count = 0;
var g_tested = false;

// Also log callers of FUN_0045BD10 by checking xrefs
// Known callers: FUN_004bc0e0 (DQ), FUN_004D2E50 (Pit Timer), FUN_004D22E0 (penalty)

Interceptor.attach(FN_TEXT, {
    onEnter: function(args) {
        g_count++;
        this.p1 = args[0];
        this.p2 = args[1].toInt32();
        this.p3 = args[2].toUInt32();
        this.n  = g_count;

        var text = '<err>';
        try { text = this.p1.readUtf8String(120); } catch(e) { text = '<read-err>'; }

        // Slot tracking state at offset 0x31c (slot count) and 0x90 (slot[0] timer)
        var slot_count = 0, slot0_timer = 0;
        try { slot_count = this.p1.add(0x31c).readU32(); } catch(e) {}
        try { slot0_timer = this.p1.add(0x90).readFloat(); } catch(e) {}

        send({
            t: 'call',
            n: this.n,
            p1: this.p1.toString(),
            p2: this.p2,
            p3: '0x' + this.p3.toString(16),
            text: text,
            slot_count: slot_count,
            slot0_timer: slot0_timer,
            tid: Process.getCurrentThreadId()
        });

        // On 2nd call: after fn runs, inject "RED FLAG" call from onLeave
        if (this.n === 2 && !g_tested) {
            this.do_inject = true;
        }
    },

    onLeave: function() {
        if (!this.do_inject) return;
        g_tested = true;

        send({ t: 'inject_start', p1: this.p1.toString() });

        try {
            // Read original first 16 bytes so we can restore them
            var orig = this.p1.readByteArray(16);

            // Write "RED FLAG" at param_1[0]
            this.p1.writeUtf8String('RED FLAG');

            // Call FUN_0045BD10 on the game's own thread with same param_1 struct context.
            // param_2=3 (line slot), param_3=0x1020304 (color — same as penalty messages).
            var fn = new NativeFunction(FN_TEXT, 'void', ['pointer', 'int', 'uint32']);
            fn(this.p1, 3, 0x1020304);

            // Restore original bytes so the game's penalty text is not permanently corrupted
            this.p1.writeByteArray(orig);

            send({ t: 'inject_ok' });
        } catch(e) {
            send({ t: 'inject_fail', err: e.toString() });
        }
    }
});

send({ t: 'ready', msg: 'FUN_0045BD10 hooked. Trigger a penalty (cut-track) to capture a call.' });
