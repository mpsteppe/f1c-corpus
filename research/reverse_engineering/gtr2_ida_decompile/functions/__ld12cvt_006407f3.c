int __cdecl _ld12cvt(unsigned __int16 *a1, _DWORD *a2, int *a3)
{
  unsigned __int16 v4; // di
  int v5; // ecx
  int v6; // edi
  int v7; // ebx
  int result; // eax
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  int v13; // ebx
  int v14; // edx
  int v15; // [esp-4h] [ebp-28h]
  _DWORD v16[3]; // [esp+Ch] [ebp-18h] BYREF
  __int64 v17; // [esp+18h] [ebp-Ch] BYREF
  int v18; // [esp+20h] [ebp-4h]
  int v19; // [esp+2Ch] [ebp+8h]

  v4 = a1[5];
  v19 = v4 & 0x8000;
  LODWORD(v17) = *(_DWORD *)(a1 + 3);
  v5 = *(_DWORD *)(a1 + 1);
  v6 = (v4 & 0x7FFF) - 0x3FFF;
  v18 = *a1 << 16;
  HIDWORD(v17) = v5;
  if ( v6 == -16383 )
  {
    v7 = 0;
    if ( !_IsZeroMan((int)&v17) )
    {
      v17 = 0;
      v18 = 0;
LABEL_4:
      result = 2;
      goto LABEL_16;
    }
    goto LABEL_15;
  }
  _CopyMan((int)v16, &v17);
  if ( _RoundMan((int)&v17, a3[2]) )
    ++v6;
  v9 = a3[1];
  if ( v6 < v9 - a3[2] )
  {
    v17 = 0;
    v18 = 0;
LABEL_11:
    v7 = 0;
    goto LABEL_4;
  }
  if ( v6 <= v9 )
  {
    v10 = v9 - v6;
    _CopyMan((int)&v17, v16);
    _ShrMan((int)&v17, v10);
    _RoundMan((int)&v17, a3[2]);
    _ShrMan((int)&v17, a3[3] + 1);
    goto LABEL_11;
  }
  v15 = a3[3];
  if ( v6 >= *a3 )
  {
    LODWORD(v17) = 0;
    HIBYTE(v17) = 0;
    v18 = 0;
    *(_DWORD *)((char *)&v17 + 3) = 128;
    _ShrMan((int)&v17, v15);
    v7 = *a3 + a3[5];
    result = 1;
    goto LABEL_16;
  }
  v11 = a3[5];
  BYTE3(v17) &= ~0x80u;
  v7 = v6 + v11;
  _ShrMan((int)&v17, v15);
LABEL_15:
  result = 0;
LABEL_16:
  v12 = a3[4];
  v13 = v17 | (v19 != 0 ? 0x80000000 : 0) | (v7 << (31 - *((_BYTE *)a3 + 12)));
  if ( v12 == 64 )
  {
    v14 = HIDWORD(v17);
    a2[1] = v13;
    *a2 = v14;
  }
  else if ( v12 == 32 )
  {
    *a2 = v13;
  }
  return result;
}
