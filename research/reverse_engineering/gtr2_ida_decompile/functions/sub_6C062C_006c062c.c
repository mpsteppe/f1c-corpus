int __thiscall sub_6C062C(_DWORD *this)
{
  int *v2; // eax
  int v3; // edi
  unsigned int v4; // edi
  int result; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ebx
  int *v14; // [esp-18h] [ebp-124h]
  char v15[64]; // [esp+14h] [ebp-F8h] BYREF
  _DWORD v16[40]; // [esp+54h] [ebp-B8h] BYREF
  int v17[4]; // [esp+F4h] [ebp-18h] BYREF
  int v18; // [esp+104h] [ebp-8h]
  int v19; // [esp+108h] [ebp-4h] BYREF

  v2 = (int *)this[64];
  v3 = *v2;
  v19 = 0;
  v17[0] = 0;
  v18 = 0;
  v4 = v3 & 0xFFFFF;
  v17[1] = 1;
  v17[2] = 2;
  v17[3] = 3;
  result = sub_6BB35B(this, v2, dword_7461B0, v15, (unsigned int *)&v19, (int)v16, v17, v4, 1);
  if ( result == 1 )
  {
    v14 = (int *)this[64];
    v18 = 1;
    result = sub_6BB35B(this, v14, dword_746230, v15, (unsigned int *)&v19, (int)v16, v17, v4, 1);
  }
  if ( !result )
  {
    v19 = 0;
    if ( v4 )
    {
      while ( 1 )
      {
        v6 = v16[v19];
        v7 = v16[v19 + 4];
        if ( v6 != v7 || v7 != v16[v19 + 8] || v6 != v16[v19 + 12] )
          return 1;
        if ( ++v19 >= v4 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      v8 = v4 & 0xFFFFF;
      if ( v18 )
        v9 = v8 | 0x73700000;
      else
        v9 = v8 | 0x73800000;
      *(_DWORD *)this[64] = v9;
      v18 = sub_681AAA(this, this[30], 0, 0, 0.0);
      if ( v18 == -1 )
      {
        return -2147024882;
      }
      else
      {
        v10 = 0;
        if ( v4 )
        {
          v19 = 4 * v4;
          do
          {
            v11 = *(_DWORD *)(this[64] + 8);
            v12 = v16[v10];
            v13 = v19;
            v19 += 4;
            *(_DWORD *)(v11 + 4 * v10++) = v12;
            *(_DWORD *)(v13 + *(_DWORD *)(this[64] + 8)) = v18;
          }
          while ( v10 < v4 );
        }
        return 0;
      }
    }
  }
  return result;
}
