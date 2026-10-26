// f1c_slot_snapshot.js — hook b9c0, on first write to ECX=0x3c571e0:
// 1. Let the write happen normally
// 2. Read 0x300 bytes from ECX and send as a buffer dump
// Goal: see EXACTLY where in the struct the text+timer land.

var INNER = 0x03c571e0;
var done = false;

Interceptor.attach(ptr(0x0045b9c0), {
    onEnter: function(args) {
        var ecx = this.context.ecx.toUInt32();
        if (ecx !== INNER || done) return;
        this.capture = true;
    },
    onLeave: function() {
        if (!this.capture) return;
        done = true;
        // Read 0x300 bytes from inner struct AFTER write
        var raw = ptr(INNER).readByteArray(0x300);
        send({ t: 'snap' }, raw);
    }
});

send({ ready: true, msg: 'Waiting for first b9c0 write to 0x3c571e0 (pause game).' });
