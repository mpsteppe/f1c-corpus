int __thiscall sub_415650(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax
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
      return 0;
    }
LABEL_6:
    if ( !v4 )
      return 0;
    return *v4;
  }
  return result;
}
