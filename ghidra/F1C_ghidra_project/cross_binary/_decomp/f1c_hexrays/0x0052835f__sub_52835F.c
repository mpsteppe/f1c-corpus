// f1c  0x0052835f  size=446
_BYTE *__cdecl sub_52835F(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // ebx
  int *v7; // edi
  _WORD *v8; // esi
  _WORD *v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // edx
  _BYTE *result; // eax
  _BYTE *v16; // edi
  int v17; // ecx
  char v18; // cl
  int v19; // ecx
  int v20; // esi
  _BYTE v21[64]; // [esp+Ch] [ebp-48h] BYREF
  int v22; // [esp+4Ch] [ebp-8h]
  int *v23; // [esp+50h] [ebp-4h]
  int v24; // [esp+5Ch] [ebp+8h]
  int v25; // [esp+5Ch] [ebp+8h]

  v5 = *(_DWORD *)(a2 + 80);
  v6 = *(_DWORD *)(a1 + 284) + 128;
  v7 = (int *)v21;
  v8 = (_WORD *)(a3 + 48);
  v22 = v6;
  v23 = (int *)v21;
  v24 = 8;
  v9 = (_WORD *)(v5 + 48);
  do
  {
    if ( v24 != 6 && v24 != 4 && v24 != 2 )
    {
      v10 = (__int16)*(v9 - 24);
      v11 = (__int16)*(v8 - 24);
      if ( *v8 | (unsigned __int16)(*(v8 - 16) | v8[16] | v8[32]) )
      {
        v13 = (v11 * v10) << 15;
        v14 = 29692 * (__int16)(*(v8 - 16) * *(v9 - 16))
            + 6967 * (__int16)(v8[16] * v9[16])
            - 5906 * (__int16)(v8[32] * v9[32])
            - 10426 * (__int16)(*v8 * *v9);
        v7 = v23;
        *v23 = (v14 + v13 + 4096) >> 13;
        v6 = v22;
        v12 = (v13 - v14 + 4096) >> 13;
      }
      else
      {
        v12 = 4 * v11 * v10;
        *v7 = v12;
      }
      v7[8] = v12;
    }
    ++v8;
    ++v7;
    ++v9;
    --v24;
    v23 = v7;
  }
  while ( v24 > 0 );
  v25 = 0;
  result = v21;
  do
  {
    v16 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v25));
    v17 = *(_DWORD *)result;
    if ( *((_DWORD *)result + 5) | *((_DWORD *)result + 1) | *((_DWORD *)result + 3) | *((_DWORD *)result + 7) )
    {
      v19 = v17 << 15;
      v20 = 6967 * *((__int16 *)result + 10)
          + 29692 * *((__int16 *)result + 2)
          + -10426 * *((__int16 *)result + 6)
          - 5906 * *((__int16 *)result + 14);
      v6 = v22;
      *v16 = *(_BYTE *)((((v20 + v19 + 0x80000) >> 20) & 0x3FF) + v22);
      v18 = *(_BYTE *)((((v19 - v20 + 0x80000) >> 20) & 0x3FF) + v6);
    }
    else
    {
      v18 = *(_BYTE *)((((v17 + 16) >> 5) & 0x3FF) + v6);
      *v16 = v18;
    }
    result += 32;
    ++v25;
    v16[1] = v18;
  }
  while ( v25 < 2 );
  return result;
}
