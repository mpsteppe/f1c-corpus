// f1c_slot_write.js — hook FUN_0045b9c0 (slot writer) to log every ECX + text written.
// Also hook FUN_0045b430 (slot resetter). This reveals the TRUE slot struct base address.

var g_n = 0;

Interceptor.attach(ptr(0x0045b9c0), {
    onEnter: function(args) {
        g_n++;
        var ecx = this.context.ecx;
        var text = '';
        try { text = args[0].readCString(); } catch(e) { text = '<err>'; }
        // args[0] = param_2 (text to write, after ECX in thiscall)
        // ECX = the struct base (slot array)
        send({
            t: 'b9c0',
            n: g_n,
            ecx: ecx.toString(),
            text: text.slice(0, 80),
            ret: this.returnAddress.toString()
        });
    }
});

Interceptor.attach(ptr(0x0045b430), {
    onEnter: function(args) {
        var ecx = this.context.ecx;
        send({
            t: 'b430',
            ecx: ecx.toString(),
            slot: args[0].toInt32(),
            ret: this.returnAddress.toString()
        });
    }
});

send({ ready: true, msg: 'b9c0+b430 hooked. Trigger penalty (cut track) now.' });
