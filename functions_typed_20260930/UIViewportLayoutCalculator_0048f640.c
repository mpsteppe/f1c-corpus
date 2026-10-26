int __thiscall sub_48F640(_DWORD *this)
{
  int v2; // eax
  int v3; // ebp
  int v4; // edx
  int v5; // edi
  int v6; // ebp
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  int i; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // edx

  v2 = this[72];
  v3 = this[73];
  v4 = this[81];
  v5 = this[80];
  this[88] = 0;
  this[89] = 0;
  this[86] = 0;
  this[87] = 0;
  this[91] = 0;
  v6 = v3 - v2;
  v7 = (int *)this[60];
  v8 = v4 - v5;
  this[62] = v7;
  if ( v7 )
    v9 = *v7;
  else
    v9 = 0;
  for ( i = this[63]; v9; v9 = *v14 )
  {
    v11 = *(_DWORD *)(v9 + 12);
    if ( this[88] < v11 )
      this[88] = v11;
    v12 = *(_DWORD *)(v9 + 16);
    if ( this[89] < v12 )
      this[89] = v12;
    v13 = this[62];
    if ( !v13 )
      break;
    v14 = *(int **)(v13 + 4);
    this[62] = v14;
    if ( !v14 )
      break;
  }
  v15 = this[64];
  if ( v15 )
  {
    if ( v15 == 1 )
    {
      v16 = this[88];
      if ( v16 )
        this[87] = v6 / (v16 + this[84]);
      v17 = this[87];
      if ( v17 )
      {
        this[86] = i / v17;
        if ( i % v17 > 0 )
          ++this[86];
        this[91] = i / v17;
        if ( i % v17 > 0 )
          this[91] = i / v17 + 1;
      }
      else
      {
        this[91] = i;
      }
      v18 = this[85] + this[89];
      if ( v18 )
        this[91] -= v8 / v18;
      if ( (int)this[91] < 0 )
        this[91] = 0;
      this[91] *= v18;
    }
  }
  else
  {
    v19 = this[89];
    if ( v19 )
      this[86] = v8 / (v19 + this[85]);
    v20 = this[87];
    if ( v20 )
      this[87] = i / v20;
    v21 = this[86];
    if ( v21 && i % v21 > 0 )
      ++this[87];
    v22 = this[88];
    if ( v22 )
      this[91] = this[87] - v6 / v22;
    if ( (int)this[91] < 0 )
      this[91] = 0;
  }
  if ( this[87] * (this[88] + this[84]) > v6 || this[86] * (this[89] + this[85]) > v8 )
  {
    v23 = *this;
    this[65] = 0;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(v23 + 64))(this, 0);
  }
  UITileGrid(this);
  return (*(int (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
}

