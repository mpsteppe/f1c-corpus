_DWORD *__thiscall sub_414BB0(char *this)
{
  bool v2; // zf
  int v3; // ecx
  char *v4; // eax
  int v5; // ecx
  _DWORD *result; // eax
  _DWORD *v7; // eax

  v2 = this[140] == 0;
  this[141] = 0;
  *(_DWORD *)this = 1;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  if ( !v2 )
  {
    sub_40C420(*((int **)this + 1), 0);
    this[140] = 0;
  }
  v3 = *((_DWORD *)this + 31);
  if ( v3 )
  {
    v4 = (char *)sub_459B80(v3);
    sub_40C400(*((int ****)this + 1), v4);
  }
  if ( *((int *)this + 32) >= 0 )
    sub_42DB40(*((_DWORD *)this + 32));
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = -1;
  sub_57AC20(this + 56);
  v5 = *((_DWORD *)this + 29);
  if ( v5 )
  {
    result = (_DWORD *)sub_414620(v5);
  }
  else
  {
    v7 = operator new(0x30u);
    if ( v7 )
      result = sub_414600(v7, (int)this);
    else
      result = 0;
    *((_DWORD *)this + 29) = result;
  }
  if ( !*((_DWORD *)this + 29) )
    *(_DWORD *)this = -1;
  return result;
}
