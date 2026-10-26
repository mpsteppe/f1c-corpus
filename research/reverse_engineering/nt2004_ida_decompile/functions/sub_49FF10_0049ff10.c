int __thiscall sub_49FF10(int *this)
{
  int v2; // eax
  int *v3; // edi
  char *v4; // eax
  int result; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // ebp
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // [esp+Ch] [ebp-4h] BYREF

  v2 = this[61];
  v3 = this + 97;
  v18 = 0;
  this[97] = 0;
  if ( v2 )
  {
    v4 = *(char **)(v2 + 64);
    if ( !v4 )
      v4 = &byte_629120;
    sub_4AE350(v4);
  }
  result = sub_4AE230(aTtgjz, (int)&v18, (int)v3);
  v6 = *v3;
  this[102] = 0;
  this[100] = 0;
  this[99] = 0;
  this[98] = 0;
  this[96] = 0;
  if ( v6 > 0 )
  {
    v7 = this[2] - this[1];
    v8 = this[90];
    this[89] = (this[4] - this[3]) / 40 + 2;
    v9 = v7 / (v6 + v8);
    this[102] = v7;
    v10 = this[37];
    this[88] = 0;
    v11 = v10 - v9;
    this[100] = v9;
    this[99] = v11;
    this[99] = v11 <= 0 ? 0 : v11;
    v12 = sub_49CB60(this, 3);
    if ( v12 )
      this[98] = *(_DWORD *)(v12 + 12) - *(_DWORD *)(v12 + 8);
    v13 = (*(int (__thiscall **)(int *))(*this + 16))(this) - this[98];
    v14 = v13 - (*(int (__thiscall **)(int *))(*this + 8))(this);
    this[96] = v14;
    if ( v14 < 0 )
      this[96] = 0;
    v15 = this[94];
    v16 = this[99];
    if ( v15 <= v16 )
    {
      if ( v15 >= 0 )
        goto LABEL_15;
      this[94] = 0;
    }
    else
    {
      this[94] = v16;
    }
    sub_4A0090(this);
LABEL_15:
    result = this[95];
    v17 = this[96];
    if ( result <= v17 )
    {
      if ( result < 0 )
      {
        this[95] = 0;
        return sub_4A00E0(this);
      }
    }
    else
    {
      this[95] = v17;
      return sub_4A00E0(this);
    }
  }
  return result;
}
