// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564C70
// Canonical corpus name: sub_564C70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564C70_00564c70.c

void UnknownObject::rc4_crypt()
{
    // Classic RC4 stream cipher: initializes a 256-byte S-box to the identity, runs the key-scheduling algorithm over key a1 of length a2, then generates keystream and XORs it into buffer a3 for a4 bytes, returning a4. The swap primitive is ByteSwap at 0x005622B0.
    // LOOP: Initialize the 256-byte S-box v17 with identity values 0..255. [source:raw, function:0x00564C70]
    // LOOP: Key scheduling algorithm: j = (j + key[i % keylen] + sbox[i]) mod 256, then swap sbox[i] and sbox[j]; iterates over all 256 entries using the key a1 of length a2. [source:raw, function:0x00564C70]
    // CALL: Invoke ByteSwap to swap two S-box entries during key scheduling and keystream generation. [callee:0x005622B0, source:raw]
    // GUARD: Only run the stream-cipher output stage when data length a4 is positive. [source:raw, function:0x00564C70]
    // LOOP: Keystream generation and application: advance i, j = (j + sbox[i]) mod 256, swap sbox[i] and sbox[j], XOR data[a3 + n] with sbox[(sbox[i] + sbox[j]) mod 256] for each of a4 bytes. [source:raw, function:0x00564C70]
    // RETURN: Return the data length a4 as the result. [source:raw, function:0x00564C70]

    // Conservative worker pseudocode:
    //   unsigned char S[256];
    //   for (i = 0; i < 256; i++) S[i] = i;
    //   j = 0;
    //   for (i = 0; i < 256; i++) {
    //     j = (j + S[i] + key[i % keylen]) % 256;
    //     ByteSwap(&S[i], &S[j]);
    //   }
    //   i = 0; j = 0;
    //   for (n = 0; n < datalen; n++) {
    //     i = (i + 1) % 256;
    //     j = (j + S[i]) % 256;
    //     ByteSwap(&S[i], &S[j]);
    //     data[n] ^= S[(S[i] + S[j]) % 256];
    //   }
    //   return datalen;
    // UNRESOLVED: Owner class and subsystem unknown; callers/callees only place it in the 0x562E30 neighborhood.
}
