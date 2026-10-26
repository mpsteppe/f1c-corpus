// Dump disassembly bytes of FUN_004ef5a0 (218 bytes)
'use strict';
const base = ptr('0x004ef5a0');
const size = 218;
const bytes = base.readByteArray(size);
const arr = new Uint8Array(bytes);
let lines = [];
for (let i = 0; i < size; i += 16) {
  const addr = base.add(i);
  let hex = '';
  for (let j = 0; j < 16 && i + j < size; j++) {
    hex += ('0' + arr[i + j].toString(16)).slice(-2) + ' ';
  }
  lines.push(addr + ': ' + hex.trim());
}
console.log(lines.join('\n'));
