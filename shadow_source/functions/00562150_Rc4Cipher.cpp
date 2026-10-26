// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562150
// Canonical corpus name: sub_562150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562150_00562150.c

void UnknownObject::Rc4Cipher()
{
    // Two-phase keyed byte cipher matching the RC4 structure: first a 256-entry state table v17 is initialized to 0..255, then a key-scheduling loop mixes key a1 (length a2) into the table using ByteSwap (0x005622B0) swaps; second, a stream phase XORs each of a4 bytes of data at a3 against a keystream byte selected from the table, swapping table entries via ByteSwap as it advances. Returns a4.
    // LOOP: Initialize the 256-byte state table v17 with values 0 through 255. [source:raw]
    // LOOP: Key-scheduling phase: for each of 256 rounds, accumulate j from key byte (a1 indexed by (round mod a2)) plus the current table byte, then swap the table entries at the round index and j via ByteSwap (0x005622B0). [callee:0x005622B0, source:raw]
    // GUARD: Guard on data length a4 > 0; the stream phase is skipped when a4 <= 0. [source:raw]
    // LOOP: Stream phase: advance the state index v12, compute j = (j + state[v12]) mod 256, swap state[v12] and state[v13] via ByteSwap (0x005622B0), then XOR each data byte at a3 with state[(state[v13] + state[v12]) % 256]. [callee:0x005622B0, source:raw]
    // RETURN: Return a4, the data length processed. [function:0x00562150, source:raw]

    // Conservative worker pseudocode:
    //   int sub_562150(char* key, int keyLen, char* data, int dataLen) {
    //     unsigned char s[256];
    //     for (int i = 0; i < 256; ++i) s[i] = i;
    //     for (int i = 0, j = 0, k = 0; i < 256; ++i) {
    //       j = (j + key[i % keyLen] + s[i]) % 256;
    //       ByteSwap(&s[i], &s[j]);
    //     }
    //     for (int i = 0, j = 0; i < dataLen; ++i) {
    //       i = (i + 1) % 256; j = (j + s[i]) % 256;
    //       ByteSwap(&s[i], &s[j]);
    //       data[i] ^= s[(s[i] + s[j]) % 256];
    //     }
    //     return dataLen;
    //   }
    // UNRESOLVED: The RC4 identification is DERIVED from the 256-entry permutation table and two-phase swap stream structure; no packet evidence names it.
    // UNRESOLVED: The stream-phase index advance in the packet reads as v12 += data[i] + 1; a plain (v12 + 1) increment cannot be distinguished from this artifact without runtime or further static evidence.
    // UNRESOLVED: Key length a2 is used as a modulo for the key index; a2 <= 0 would divide by zero but that path is unevidenced.
}
