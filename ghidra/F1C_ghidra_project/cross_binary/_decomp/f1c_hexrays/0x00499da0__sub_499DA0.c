// f1c  0x00499da0  size=79
int __thiscall sub_499DA0(_DWORD *this, _DWORD **a2)
{
  _DWORD **v2; // ebx
  _DWORD *v4; // esi
  int result; // eax

  v2 = a2;
  if ( !a2 )
    v2 = (_DWORD **)(this + 2);
  v4 = *v2;
  if ( *v2 )
  {
    sub_499DA0(v4 + 10);
    sub_499DA0(v4 + 9);
    sub_499B50(v4);
    result = sub_587BCF(v4);
  }
  *v2 = 0;
  this[3] = 0;
  return result;
}
