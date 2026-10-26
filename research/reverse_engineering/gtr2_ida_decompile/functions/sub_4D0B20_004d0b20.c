void __thiscall sub_4D0B20(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // edi
  const CHAR *v4; // eax
  bool v5; // cc
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // [esp-4h] [ebp-14h]
  char v23[4]; // [esp+8h] [ebp-8h] BYREF
  int v24; // [esp+Ch] [ebp-4h]

  v2 = this[61];
  v3 = this + 142;
  v24 = 0;
  this[142] = 0;
  if ( v2 )
  {
    v4 = *(const CHAR **)(v2 + 64);
    if ( !v4 )
      v4 = WindowName;
    sub_4DF1B0(this[12], v4);
  }
  sub_4E08C0(this[12], "Ttgjz", v23, v3, 1, v22);
  v5 = *v3 <= 0;
  this[147] = 0;
  this[145] = 0;
  this[144] = 0;
  this[143] = 0;
  this[141] = 0;
  if ( !v5 )
  {
    v6 = (this[4] - this[3]) / 40 + 2;
    v7 = this[2] - this[1];
    this[133] = 0;
    this[134] = v6;
    this[147] = v7;
    if ( sub_4CFD30(this, 3) > 0 && sub_4CFD30(this, 2) > 0 )
    {
      v8 = sub_4CFD30(this, 3);
      this[147] = v8 - sub_4CFD30(this, 2);
      v9 = this[1];
      this[133] = sub_4CFD30(this, 2) - v9;
    }
    if ( sub_4CFCC0(this, 2) > 0 )
    {
      v10 = this[3];
      this[136] = sub_4CFCC0(this, 2) - v10;
    }
    v11 = this[147] / (*v3 + this[135]);
    v12 = this[37] - v11;
    this[145] = v11;
    this[144] = v12;
    v13 = v12 <= 0 ? 0 : v12;
    v14 = this[61];
    this[144] = v13;
    if ( v14 )
    {
      v15 = sub_4E29F0(3);
      if ( v15 )
        this[143] = *(_DWORD *)(v15 + 12) - *(_DWORD *)(v15 + 8);
    }
    v16 = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this) - this[143];
    v17 = v16 - (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
    this[141] = v17;
    if ( v17 < 0 )
      this[141] = 0;
    v18 = this[139];
    v19 = this[144];
    if ( v18 <= v19 )
    {
      if ( v18 >= 0 )
        goto LABEL_21;
      this[139] = 0;
    }
    else
    {
      this[139] = v19;
    }
    sub_4CE500();
LABEL_21:
    v20 = this[140];
    v21 = this[141];
    if ( v20 <= v21 )
    {
      if ( v20 < 0 )
      {
        this[140] = 0;
        sub_4CE550(this);
      }
    }
    else
    {
      this[140] = v21;
      sub_4CE550(this);
    }
  }
}
