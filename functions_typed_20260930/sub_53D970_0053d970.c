int __thiscall sub_53D970(int *this, int a2)
{
  int v3; // edx
  char *v4; // ebp
  int v5; // eax
  int result; // eax
  int v7; // edi
  int v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  char v20; // cl
  int i; // [esp+B4h] [ebp-940h]
  char v22[88]; // [esp+B8h] [ebp-93Ch] BYREF
  int v23; // [esp+110h] [ebp-8E4h]
  int v24; // [esp+114h] [ebp-8E0h]
  _DWORD v25[271]; // [esp+18Ch] [ebp-868h] BYREF
  _BYTE v26[1048]; // [esp+5C8h] [ebp-42Ch] BYREF
  int v27; // [esp+9E0h] [ebp-14h]
  int v28; // [esp+9E4h] [ebp-10h]
  int v29; // [esp+9E8h] [ebp-Ch]
  int v30; // [esp+9ECh] [ebp-8h]

  v3 = 0;
  if ( this[2] > 0 )
  {
    v4 = (char *)(this + 3);
    do
    {
      memset(v4, 0, 0x43Cu);
      ++v3;
      v4 += 1084;
    }
    while ( v3 < this[2] );
  }
  v5 = this[1087];
  this[2] = 0;
  result = (*(int (__stdcall **)(int))(*(_DWORD *)v5 + 16))(v5);
  v7 = 0;
  for ( i = result; v7 < i; ++v7 )
  {
    v8 = 0;
    v9 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
           this[1087],
           v7,
           1,
           23,
           23,
           0);
    *this = v9;
    if ( !v9 )
      v8 = 0x1000000;
    v10 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
            this[1087],
            v7,
            1,
            24,
            25,
            0);
    *this = v10;
    if ( !v10 )
      v8 |= 0x2000000u;
    v11 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
            this[1087],
            v7,
            1,
            24,
            24,
            0);
    *this = v11;
    if ( !v11 )
      v8 |= 0x4000000u;
    v12 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
            this[1087],
            v7,
            1,
            20,
            20,
            0);
    *this = v12;
    if ( !v12 )
      v8 |= 0x8000000u;
    v13 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
            this[1087],
            v7,
            1,
            22,
            22,
            0);
    *this = v13;
    if ( !v13 )
      v8 |= 0x20000000u;
    v14 = (*(int (__stdcall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)this[1087] + 36))(
            this[1087],
            v7,
            1,
            22,
            21,
            0);
    *this = v14;
    if ( !v14 )
      v8 |= 0x10000000u;
    if ( (v8 & 0x3F000000) != 0 )
    {
      v15 = (*(int (__stdcall **)(int, int, int, char *))(*(_DWORD *)this[1087] + 52))(this[1087], v7, 1, v22);
      *this = v15;
      if ( v15 || (v25[71] = v23, v23 > 512) && (v25[72] = v24, v24 > 512) )
      {
        v16 = (*(int (__stdcall **)(int, int, int, _BYTE *))(*(_DWORD *)this[1087] + 20))(this[1087], v7, 2, v26);
        v17 = v27;
        v18 = v29;
        *this = v16;
        v25[2] = v17;
        v25[3] = v28;
        v25[0] = v8;
        v25[1] = v7;
        v25[4] = v18;
        v25[5] = v30;
        v19 = 0;
        do
        {
          v20 = v26[v19 + 512];
          *((_BYTE *)&v25[6] + v19++) = v20;
        }
        while ( v20 );
        v25[73] = 0;
        v25[70] = 0;
        sub_53D8B0(this, v25);
      }
    }
    result = i;
  }
  return result;
}

