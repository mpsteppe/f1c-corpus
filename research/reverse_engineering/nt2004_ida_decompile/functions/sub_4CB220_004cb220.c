int __thiscall sub_4CB220(_DWORD *this)
{
  float *v2; // ecx
  int v3; // ebx
  int v4; // eax
  int v5; // esi
  double v6; // st7
  float v7; // eax
  bool v8; // c0
  bool v9; // c3
  float *v10; // ecx
  int v11; // ebx
  int v12; // eax
  int v13; // esi
  double v14; // st7
  float v15; // eax
  bool v16; // c0
  bool v17; // c3
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  int result; // eax
  _DWORD *v22; // esi
  int v23; // ebx
  int v24; // eax
  int v25; // edx
  int v26; // [esp-4h] [ebp-14h]
  int v27; // [esp-4h] [ebp-14h]
  float v28; // [esp+Ch] [ebp-4h] BYREF

  if ( this[2058] == 1 )
  {
    v10 = (float *)(this + 981);
    v11 = 3;
    do
    {
      v12 = *((_DWORD *)v10 + 2);
      v13 = *((_DWORD *)v10 + 3);
      *v10 = 0.0;
      if ( *(_DWORD *)v10 >= v12 )
      {
        if ( *(_DWORD *)v10 > v13 )
          *(_DWORD *)v10 = v13;
      }
      else
      {
        *(_DWORD *)v10 = v12;
      }
      v14 = v10[1724];
      v15 = v10[1725];
      v10[1722] = 0.050000001;
      v16 = v14 < v10[1722];
      v17 = v14 == v10[1722];
      v28 = v15;
      if ( v16 || v17 )
      {
        if ( v10[1722] > (double)v28 )
          v10[1722] = v28;
      }
      else
      {
        v10[1722] = v14;
      }
      v10 += 9;
      --v11;
    }
    while ( v11 );
    this[2163] = 1;
  }
  else
  {
    if ( this[2058] != 2 )
      goto LABEL_29;
    v2 = (float *)(this + 981);
    v3 = 3;
    do
    {
      v4 = *((_DWORD *)v2 + 2);
      v5 = *((_DWORD *)v2 + 3);
      *(_DWORD *)v2 = 2;
      if ( *(_DWORD *)v2 >= v4 )
      {
        if ( *(_DWORD *)v2 > v5 )
          *(_DWORD *)v2 = v5;
      }
      else
      {
        *(_DWORD *)v2 = v4;
      }
      v6 = v2[1724];
      v7 = v2[1725];
      v2[1722] = 0.5;
      v8 = v6 < v2[1722];
      v9 = v6 == v2[1722];
      v28 = v7;
      if ( v8 || v9 )
      {
        if ( v2[1722] > (double)v28 )
          v2[1722] = v28;
      }
      else
      {
        v2[1722] = v6;
      }
      v2 += 9;
      --v3;
    }
    while ( v3 );
    this[2163] = 0;
  }
  v18 = this[2163];
  v19 = this[2165];
  v20 = this[2166];
  if ( v18 >= v19 )
  {
    if ( v18 > v20 )
      this[2163] = v20;
  }
  else
  {
    this[2163] = v19;
  }
LABEL_29:
  result = this[2058];
  if ( result )
  {
    v22 = this + 2988;
    v23 = 3;
    do
    {
      v24 = v22[2];
      v25 = v22[3];
      *v22 = 1;
      if ( *v22 >= v24 )
      {
        if ( *v22 > v25 )
          *v22 = v25;
      }
      else
      {
        *v22 = v24;
      }
      v26 = v22[84];
      v22[81] = 1;
      sub_4CF410(v26);
      v27 = *(v22 - 2493);
      *(v22 - 2496) = 2;
      sub_4CF410(v27);
      v22 += 9;
      --v23;
    }
    while ( v23 );
    LODWORD(v28) = 44;
    return sub_4CF370(&v28);
  }
  return result;
}
