int __thiscall sub_6C019D(int *this)
{
  int *v2; // eax
  int v3; // ebx
  unsigned int v4; // ebx
  int result; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // eax
  int *v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  char v16[64]; // [esp+14h] [ebp-108h] BYREF
  _BYTE v17[16]; // [esp+54h] [ebp-C8h] BYREF
  int v18; // [esp+64h] [ebp-B8h]
  int v19; // [esp+74h] [ebp-A8h]
  int v20[4]; // [esp+F4h] [ebp-28h] BYREF
  int *v21; // [esp+104h] [ebp-18h]
  int v22; // [esp+108h] [ebp-14h]
  unsigned int v23; // [esp+10Ch] [ebp-10h]
  int v24; // [esp+110h] [ebp-Ch]
  unsigned int v25; // [esp+114h] [ebp-8h] BYREF
  _DWORD *v26; // [esp+118h] [ebp-4h]

  v2 = (int *)this[64];
  v3 = *v2;
  v20[1] = 1;
  v4 = v3 & 0xFFFFF;
  v21 = this;
  v25 = 0;
  v20[0] = 0;
  v20[2] = 2;
  v20[3] = 3;
  result = sub_6BB35B(this, v2, dword_745F10, v16, &v25, (int)v17, v20, v4, 1);
  if ( !result )
  {
    v25 = 0;
    v24 = 0;
    v23 = 0;
    v26 = 0;
    if ( v4 )
    {
      v6 = this[5];
      v7 = *(_DWORD *)(v6 + 4 * v18);
      v8 = *(_DWORD *)(v6 + 4 * v19);
      v9 = this[4];
      v22 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(v7 + 4)) + 4) & 0x100;
      do
      {
        if ( !v22
          || (*(_BYTE *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)(v8 + 4)) + 5) & 1) == 0
          || *(_DWORD *)(v7 + 8) != -1
          || *(_DWORD *)(v8 + 8) != -1 )
        {
          return 1;
        }
        if ( *(double *)(v7 + 32) == 1.0 && *(double *)(v8 + 32) == 0.0 )
        {
          v25 = 1;
        }
        else
        {
          if ( *(double *)(v8 + 32) != 1.0 || *(double *)(v7 + 32) != 0.0 )
            return 1;
          v24 = 1;
        }
        v26 = (_DWORD *)((char *)v26 + 1);
      }
      while ( (unsigned int)v26 < v4 );
      if ( v25 )
      {
        if ( v24 )
          return 1;
        v23 = v4 & 0xFFFFF | 0x73500000;
      }
      if ( v24 )
        v23 = v4 & 0xFFFFF | 0x73600000;
    }
    v10 = (_DWORD *)sub_681186(116);
    if ( v10 )
      v26 = sub_680CEC(v10);
    else
      v26 = 0;
    if ( !v26 )
      return -2147024882;
    v11 = sub_6811D1((char *)v26, v23, 2 * v4, v4, 0);
    if ( v11 >= 0 )
    {
      v11 = sub_680D22(v26, this[64]);
      if ( v11 >= 0 )
      {
        qmemcpy((void *)v26[4], *(const void **)(this[64] + 16), 4 * ((4 * v4) >> 2));
        qmemcpy((void *)v26[2], v17, 4 * ((4 * v4) >> 2));
        v12 = v21;
        v13 = sub_681AAA(v21, v21[30], 0, 0, 0.0);
        if ( v13 == -1 )
        {
          v14 = -2147024882;
LABEL_35:
          sub_66238F(v26, 1);
          return v14;
        }
        if ( v4 )
        {
          v15 = 4 * v4;
          do
          {
            *(_DWORD *)(v15 + v26[2]) = v13;
            v15 += 4;
            --v4;
          }
          while ( v4 );
        }
        v11 = sub_681430((char *)v12[64], v26);
      }
    }
    v14 = v11;
    goto LABEL_35;
  }
  return result;
}
