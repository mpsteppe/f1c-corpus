// f1c_intercept_write.js
// On the first b9c0 write to ECX=0x3c571e0:
//   1. Read the struct snapshot BEFORE leave
//   2. Send the snapshot so we can analyze it
//   3. Patch the text of whatever slot was just written to "RED FLAG"
// This tells us: a) where the write landed, b) whether the render sees our patch

var INNER = ptr(0x03c571e0);
var STRIDE = 0x5c;
var done = false;

Interceptor.attach(ptr(0x0045b9c0), {
    onEnter: function(args) {
        this.ecx = this.context.ecx.toUInt32();
        this.text = '';
        try { this.text = args[0].readCString(); } catch(e) {}
        this.do_it = (this.ecx === 0x03c571e0 && !done);
    },
    onLeave: function(retval) {
        if (!this.do_it) return;
        done = true;

        // Snapshot
        var raw = INNER.readByteArray(0x2c0);
        send({ t: 'snap', text: this.text }, raw);

        // Find the slot with timer = 5.0 (0x40a00000) — it was just written
        for (var n = 0; n < 8; n++) {
            var timer_off = n * STRIDE + 0x90;
            var timer = INNER.add(timer_off).readFloat();
            if (Math.abs(timer - 5.0) < 0.01) {
                var text_off = n * STRIDE + 0x3c;
                var addr = INNER.add(text_off);
                var old_text = addr.readCString();
                addr.writeUtf8String('RED FLAG');
                send({ t: 'patch', slot: n, old: old_text, timer_off: timer_off, text_off: text_off });
                break;
            }
        }
    }
});

send({ ready: true });
