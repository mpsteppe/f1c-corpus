// f1c  0x00564f10  size=366
unsigned int __fastcall sub_564F10(_DWORD *a1, unsigned int *a2, int a3)
{
  unsigned int v3; // ebx
  int v5; // edx
  int v6; // esi
  unsigned int result; // eax
  unsigned int *v8; // ebp
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // esi
  int v14; // ebx
  int v15; // edi
  unsigned int v16; // edi
  unsigned int *v17; // [esp+10h] [ebp-4h]
  unsigned int v18; // [esp+18h] [ebp+4h]

  v3 = a1[307];
  v5 = a1[304];
  v6 = a1[306];
  result = a1[305];
  v17 = a2;
  v18 = (unsigned int)&a2[a3];
  if ( (unsigned int)a2 < v18 )
  {
    do
    {
      if ( v3 < 0x10000 )
      {
        v8 = &a1[v5 + 272];
        do
        {
          v9 = v3 + result;
          v8[16] = v3;
          v10 = v9 + v6;
          v3 *= 2;
          v11 = v10 + v9;
          *v8 = v10;
          *(v8 - 16) = v11;
          ++v5;
          ++v8;
          v12 = a1[(unsigned __int8)v11] ^ v11;
          v13 = ((a1[BYTE1(v10)] ^ ((v10 >> 8) | (v10 << 24))) >> 8)
              | ((a1[BYTE1(v10)] ^ ((v10 >> 8) | (v10 << 24))) << 24);
          v6 = a1[(unsigned __int8)v13] ^ v13;
          result = ((a1[HIBYTE(v12)] ^ ((v12 << 8) | HIBYTE(v12))) << 8)
                 | ((a1[HIBYTE(v12)] ^ ((v12 << 8) | HIBYTE(v12))) >> 24);
        }
        while ( v3 < 0x10000 );
      }
      *v17 = result ^ v6;
      --v5;
      ++v17;
      if ( v5 < 0 )
        v5 = 0;
      v15 = (unsigned __int64)(unsigned int)(a1[(unsigned __int8)a1[v5 + 272]] ^ a1[v5 + 272]) >> 24;
      v14 = (a1[(unsigned __int8)a1[v5 + 272]] ^ a1[v5 + 272]) << 8;
      result = a1[(unsigned __int8)((unsigned __int16)(LOWORD(a1[(unsigned __int8)((unsigned __int16)~LOWORD(a1[v5 + 256]) >> 8)])
                                                     ^ ((unsigned int)~a1[v5 + 256] >> 8)) >> 8)]
             ^ (((a1[(unsigned __int8)((unsigned __int16)~LOWORD(a1[v5 + 256]) >> 8)]
                ^ (((unsigned int)~a1[v5 + 256] >> 8) | (~a1[v5 + 256] << 24))) >> 8)
              | ((a1[(unsigned __int8)((unsigned __int16)~LOWORD(a1[v5 + 256]) >> 8)]
                ^ (((unsigned int)~a1[v5 + 256] >> 8) | (~a1[v5 + 256] << 24))) << 24));
      v16 = a1[(unsigned __int8)(v14 | v15)] ^ (v14 | v15);
      v6 = (v16 << 8) | HIBYTE(v16);
      v3 = 2 * a1[v5 + 288] + 1;
    }
    while ( (unsigned int)v17 < v18 );
  }
  a1[306] = v6;
  a1[307] = v3;
  a1[304] = v5;
  a1[305] = result;
  return result;
}
