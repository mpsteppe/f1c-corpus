char __thiscall sub_40A240(_DWORD *this, int a2)
{
  int v2; // edx
  char result; // al
  _DWORD *v4; // eax

  v2 = a2;
  result = 0;
  if ( a2 >= 0 && a2 < this[3] )
  {
    v4 = (_DWORD *)*this;
    if ( a2 > 0 )
    {
      while ( v4 )
      {
        v4 = (_DWORD *)v4[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
      return sub_40A7D0(0);
    }
LABEL_6:
    if ( !v4 )
      return sub_40A7D0(0);
    return sub_40A7D0(*v4);
  }
  return result;
}
