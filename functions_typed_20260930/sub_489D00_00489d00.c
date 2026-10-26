int __thiscall sub_489D00(int *this)
{
  int v2; // eax
  int *v3; // edi
  char *v4; // eax
  int result; // eax
  int v6; // ebx
  bool v7; // cc
  int v8; // ecx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // edi
  int v17; // eax
  int v18; // ecx
  int v19; // ecx
  int v20; // [esp+10h] [ebp-4h] BYREF

  v2 = this[50];
  v3 = this + 86;
  v20 = 0;
  this[86] = 0;
  if ( v2 )
  {
    v4 = *(char **)(v2 + 64);
    if ( !v4 )
      v4 = byte_5EA438;
    sub_498560(v4);
  }
  result = TextRenderToSurface(aTtgjz, &v20, v3, 1);
  v6 = *v3;
  v7 = *v3 <= 0;
  this[91] = 0;
  this[89] = 0;
  this[88] = 0;
  this[87] = 0;
  this[85] = 0;
  if ( !v7 )
  {
    v8 = this[2] - this[1];
    v9 = v8 / 40 + 2;
    this[78] = (this[4] - this[3]) / 40 + 2;
    v10 = v8 - 2 * v9;
    this[91] = v10;
    v11 = v10 / v6;
    v12 = this[37];
    this[77] = v9;
    v13 = v12 - v11;
    this[89] = v11;
    this[88] = v13;
    this[88] = v13 <= 0 ? 0 : v13;
    v14 = ConditionalDelegation_6460(this, 3);
    if ( v14 )
      this[87] = *(_DWORD *)(v14 + 12) - *(_DWORD *)(v14 + 8);
    v15 = (*(int (__thiscall **)(int *))(*this + 36))(this) - this[87];
    v16 = v15 - (*(int (__thiscall **)(int *))(*this + 28))(this);
    this[85] = v16;
    if ( v16 < 0 )
      this[85] = 0;
    v17 = this[83];
    v18 = this[88];
    if ( v17 <= v18 )
    {
      if ( v17 >= 0 )
        goto LABEL_15;
      this[83] = 0;
    }
    else
    {
      this[83] = v18;
    }
    FloatToIntConversion(this);
LABEL_15:
    result = this[84];
    v19 = this[85];
    if ( result <= v19 )
    {
      if ( result < 0 )
      {
        this[84] = 0;
        return ShortComputation_9ee0(this);
      }
    }
    else
    {
      this[84] = v19;
      return ShortComputation_9ee0(this);
    }
  }
  return result;
}

