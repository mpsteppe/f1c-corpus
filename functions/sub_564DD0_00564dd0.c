int __fastcall sub_564DD0(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned int v3; // eax
  int v4; // ebp
  unsigned int v5; // esi
  int v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // esi
  unsigned int v13; // eax
  int result; // eax

  v3 = 0;
  v4 = 0x8000;
  v5 = a2;
  v6 = 1;
  a1[304] = 0;
  do
  {
    v7 = v6 + v5;
    v8 = v7 + v3;
    v9 = v8 + v7;
    if ( (v4 & a3) != 0 )
    {
      v6 = 2 * v6 + 1;
      v10 = a1[(unsigned __int8)v8] ^ v8;
      v11 = ((a1[(unsigned __int8)((unsigned __int16)~(_WORD)v9 >> 8)] ^ ((~v9 >> 8) | (~v9 << 24))) >> 8)
          | ((a1[(unsigned __int8)((unsigned __int16)~(_WORD)v9 >> 8)] ^ ((~v9 >> 8) | (~v9 << 24))) << 24);
      v5 = a1[(unsigned __int8)v11] ^ v11;
      v3 = ((a1[HIBYTE(v10)] ^ ((v10 << 8) | HIBYTE(v10))) << 8)
         | ((a1[HIBYTE(v10)] ^ ((v10 << 8) | HIBYTE(v10))) >> 24);
    }
    else
    {
      a1[a1[304] + 256] = v9;
      a1[a1[304] + 272] = v8;
      a1[a1[304]++ + 288] = v6;
      v12 = a1[(unsigned __int8)v9] ^ v9;
      v13 = ((a1[BYTE1(v8)] ^ ((v8 >> 8) | (v8 << 24))) >> 8) | ((a1[BYTE1(v8)] ^ ((v8 >> 8) | (v8 << 24))) << 24);
      v3 = a1[(unsigned __int8)v13] ^ v13;
      v5 = ((a1[HIBYTE(v12)] ^ ((v12 << 8) | HIBYTE(v12))) << 8)
         | ((a1[HIBYTE(v12)] ^ ((v12 << 8) | HIBYTE(v12))) >> 24);
      v6 *= 2;
    }
    v4 >>= 1;
  }
  while ( v4 > 0 );
  a1[306] = v3;
  a1[305] = v5;
  result = v5 ^ v3;
  a1[307] = v6;
  a1[308] = a2;
  return result;
}
