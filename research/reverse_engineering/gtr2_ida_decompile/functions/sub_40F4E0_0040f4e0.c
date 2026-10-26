int __thiscall sub_40F4E0(_DWORD *this)
{
  void *v2; // eax
  int v3; // eax
  _DWORD *v4; // eax
  void *v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  void *v8; // eax
  int v9; // eax
  _DWORD *v10; // eax
  void *v11; // eax
  int v12; // eax
  _DWORD *v13; // eax
  int result; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // edi
  _DWORD *v17; // ecx
  _DWORD *v18; // ecx

  if ( !this[4] )
  {
    v2 = operator new(0xCCu);
    if ( v2 )
      v3 = sub_46D4A0(v2);
    else
      v3 = 0;
    this[4] = v3;
    v4 = (_DWORD *)(v3 + 140);
    *v4 = 1135869952;
    v4[1] = 1135869952;
    v4[2] = 1135869952;
  }
  if ( !this[5] )
  {
    v5 = operator new(0xCCu);
    if ( v5 )
      v6 = sub_46D4A0(v5);
    else
      v6 = 0;
    this[5] = v6;
    v7 = (_DWORD *)(v6 + 140);
    *v7 = 1135869952;
    v7[1] = 1135869952;
    v7[2] = 1135869952;
  }
  if ( !this[6] )
  {
    v8 = operator new(0xCCu);
    if ( v8 )
      v9 = sub_46D4A0(v8);
    else
      v9 = 0;
    this[6] = v9;
    v10 = (_DWORD *)(v9 + 140);
    *v10 = 1135869952;
    v10[1] = 1135869952;
    v10[2] = 1135869952;
  }
  if ( !this[7] )
  {
    v11 = operator new(0xCCu);
    if ( v11 )
      v12 = sub_46D4A0(v11);
    else
      v12 = 0;
    this[7] = v12;
    v13 = (_DWORD *)(v12 + 140);
    *v13 = 1135869952;
    v13[1] = 1135869952;
    v13[2] = 1135869952;
  }
  result = this[8];
  if ( !result )
  {
    v15 = operator new(0xD0u);
    if ( v15 )
    {
      v16 = v15 + 1;
      *v15 = 1;
      sub_630A11(v15 + 1, 204, 1, sub_46D4A0, sub_46B2D0);
      v17 = v16;
    }
    else
    {
      v17 = 0;
    }
    this[8] = v17;
    sub_40DDE0();
    result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[8] + 28))(this[8]);
    v18 = (_DWORD *)(this[8] + 140);
    *v18 = 1135869952;
    v18[1] = 1135869952;
    v18[2] = 1135869952;
  }
  return result;
}
