_DWORD *__thiscall sub_40DA30(char *this)
{
  char v2; // al
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  _DWORD *result; // eax
  _DWORD *v8; // eax

  v2 = this[160];
  *(_DWORD *)this = 1;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  if ( v2 )
    *(_BYTE *)(*((_DWORD *)this + 1) + 36) = 0;
  v3 = *((_DWORD *)this + 36);
  this[160] = 0;
  if ( v3 )
    sub_40D1B0(*((_DWORD *)this + 1), v3, 1);
  v4 = *((_DWORD *)this + 37);
  if ( v4 >= 0 )
  {
    v5 = dword_7C54F0[v4];
    dword_7C54DC = *((_DWORD *)this + 37);
    dword_7C54E0 = v5;
  }
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = -1;
  sub_567F10(this + 76);
  v6 = *((_DWORD *)this + 34);
  if ( v6 )
  {
    result = (_DWORD *)sub_40D490(v6);
  }
  else
  {
    v8 = (_DWORD *)sub_587C03(48);
    if ( v8 )
      result = sub_40D470(v8, (int)this);
    else
      result = 0;
    *((_DWORD *)this + 34) = result;
  }
  if ( !*((_DWORD *)this + 34) )
    *(_DWORD *)this = -1;
  return result;
}
