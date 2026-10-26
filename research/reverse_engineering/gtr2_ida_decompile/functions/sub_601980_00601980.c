int __thiscall sub_601980(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // eax

  v2 = a2;
  v3 = this[163];
  if ( a2 < v3 && a2 >= 0 && a2 < v3 )
  {
    v4 = (_DWORD *)this[160];
    if ( a2 <= 0 )
    {
LABEL_7:
      if ( v4 )
        return *v4;
    }
    else
    {
      while ( v4 )
      {
        v4 = (_DWORD *)v4[1];
        if ( --v2 <= 0 )
          goto LABEL_7;
      }
    }
  }
  return 0;
}
