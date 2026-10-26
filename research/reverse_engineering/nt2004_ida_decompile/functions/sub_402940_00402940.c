int __thiscall sub_402940(int this, int a2, int a3)
{
  int v3; // esi
  int v5; // ecx
  int result; // eax
  int v7; // ebp
  int v8; // ecx
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  int v14; // eax
  char v15; // [esp+0h] [ebp-ACh]
  char v16; // [esp+13h] [ebp-99h]
  int v17; // [esp+14h] [ebp-98h]
  int v18; // [esp+18h] [ebp-94h]
  _BYTE v19[32]; // [esp+1Ch] [ebp-90h] BYREF
  unsigned int v20; // [esp+3Ch] [ebp-70h]
  _BYTE v21[32]; // [esp+40h] [ebp-6Ch] BYREF
  unsigned int v22; // [esp+60h] [ebp-4Ch]
  _BYTE v23[32]; // [esp+64h] [ebp-48h] BYREF
  int v24; // [esp+84h] [ebp-28h]
  _BYTE v25[32]; // [esp+88h] [ebp-24h] BYREF
  int v26; // [esp+A8h] [ebp-4h]

  v3 = a2;
  v5 = a3;
  if ( a3 < a2 )
  {
    v5 = *(_DWORD *)(this + 356);
    v3 = 0;
  }
  result = dword_767FD0;
  if ( dword_767FD0 )
  {
    v7 = *(_DWORD *)(this + 356);
    if ( v7 )
    {
      v8 = v5 - v3;
      result = *(_DWORD *)(this + 360) + 348 * v3;
      v9 = v8;
      v16 = 0;
      if ( v8 < v7 && v8 > 0 )
      {
        do
        {
          --v8;
          result = *(_DWORD *)(result + 296);
        }
        while ( v8 );
      }
      v10 = *(_DWORD *)(result + 296);
      v11 = 0;
      if ( v10 )
      {
        while ( v10 != result )
        {
          if ( ++v11 > 12000 )
            return result;
          if ( (*(_BYTE *)(v10 + 308) & 0x20) != 0 )
            v16 = 1;
          v10 = *(_DWORD *)(v10 + 296);
          if ( !v10 )
            goto LABEL_16;
        }
        sub_4F6B30(9);
        sub_4F6B30(10);
        sub_4F6B30(12);
        sub_4F6B30(13);
        sub_4F6B30(14);
        if ( v9 < *(_DWORD *)(this + 356) && v9 > 0 )
        {
          do
          {
            --v9;
            v10 = *(_DWORD *)(v10 + 296);
          }
          while ( v9 );
        }
        v17 = v10;
        sub_590140(2, 0);
        v18 = *(_DWORD *)dword_7689CC != 6 ? 0 : 2;
        do
        {
          if ( v16 )
            v12 = sub_402390(v10);
          else
            v12 = sub_5299B0(v10);
          v20 = ((unsigned int)(__int64)(v12 * 254.0) << 24) + 0xFFFFFF;
          if ( v16 )
            v13 = sub_402390(*(_DWORD *)(v10 + 296));
          else
            v13 = sub_5299B0(*(_DWORD *)(v10 + 296));
          v22 = ((unsigned int)(__int64)(v13 * 254.0) << 24) + 0xFFFFFF;
          if ( v20 && (unsigned int)(__int64)(v13 * 254.0) << 24 != -16777215 )
          {
            sub_4024D0((float *)this, (float *)v10, (int)v19, v18);
            sub_4024D0((float *)this, *(float **)(v10 + 296), (int)v21, v18);
            if ( *(_DWORD *)(v10 + 308) )
              v14 = *(_DWORD *)(v10 + 308) & 0x1F;
            else
              v14 = 9;
            if ( *(_DWORD *)dword_7689CC == 6 )
              sub_4F6AC0(v14, v19, v21);
            else
              sub_4F6AC0(9, v19, v21);
          }
          sub_4024D0((float *)this, (float *)v10, (int)v25, 1);
          sub_4024D0((float *)this, *(float **)(v10 + 296), (int)v23, 1);
          v26 = 0xFFFFFF;
          v24 = 0xFFFFFF;
          sub_4F6AC0(10, v25, v23);
          v10 = *(_DWORD *)(v10 + 296);
        }
        while ( v10 != v17 );
        return sub_590140(1, 0);
      }
      else
      {
LABEL_16:
        result = sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_5, 1090);
        if ( (_BYTE)result )
          return sub_500FE0((int)&unk_7D7920, aIncompleteWayp, v15);
      }
    }
  }
  return result;
}
