int __thiscall sub_6C1B55(_DWORD *this)
{
  int *v2; // eax
  int v3; // esi
  unsigned int v4; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int *v10; // [esp-20h] [ebp-128h]
  _BYTE v11[160]; // [esp+Ch] [ebp-FCh] BYREF
  char v12[64]; // [esp+ACh] [ebp-5Ch] BYREF
  int v13[4]; // [esp+ECh] [ebp-1Ch] BYREF
  int v14; // [esp+FCh] [ebp-Ch]
  unsigned int v15; // [esp+100h] [ebp-8h]
  int v16; // [esp+104h] [ebp-4h] BYREF

  v2 = (int *)this[64];
  v3 = *v2;
  v16 = 0;
  v13[0] = 0;
  v14 = 0;
  v4 = v3 & 0xFFFFF;
  v13[1] = 1;
  v13[2] = 2;
  v13[3] = 3;
  result = sub_6BB35B(this, v2, &unk_746570, v12, (unsigned int *)&v16, (int)v11, v13, v4, 1);
  if ( result == 1 )
  {
    v10 = (int *)this[64];
    v14 = 1;
    result = sub_6BB35B(this, v10, dword_7465D0, v12, (unsigned int *)&v16, (int)v11, v13, v4, 1);
  }
  if ( !result )
  {
    v15 = 0;
    if ( v4 )
    {
      v16 = 4 * v4;
      while ( *(_DWORD *)&v11[4 * v15 + 16] == *(_DWORD *)&v11[4 * v15 + 32] )
      {
        v6 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v16 + *(_DWORD *)(this[64] + 8)));
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v6 + 4)) + 5) & 1) == 0
          || *(double *)(v6 + 32) != 0.0
          || *(_DWORD *)(v6 + 8) != -1 )
        {
          break;
        }
        ++v15;
        v16 += 4;
        if ( v15 >= v4 )
          goto LABEL_11;
      }
      return 1;
    }
    else
    {
LABEL_11:
      v7 = 0;
      v8 = v4 & 0xFFFFF;
      if ( v14 )
        v9 = v8 | 0x74400000;
      else
        v9 = v8 | 0x74500000;
      *(_DWORD *)this[64] = v9;
      if ( v4 )
      {
        do
        {
          *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * v7) = *(_DWORD *)&v11[4 * v7 + 16];
          ++v7;
        }
        while ( v7 < v4 );
      }
      return 0;
    }
  }
  return result;
}
