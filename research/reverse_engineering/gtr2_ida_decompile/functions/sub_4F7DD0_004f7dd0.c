int __thiscall sub_4F7DD0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  _DWORD *v4; // esi

  result = this[35];
  if ( result )
  {
    result = this[40];
    if ( !result || *(_DWORD *)(result + 96) != a2 && *(_DWORD *)(result + 116) != a2 )
    {
      v3 = this[38];
      result = 0;
      if ( v3 > 0 )
      {
        v4 = (_DWORD *)(this[39] + 116);
        do
        {
          if ( *v4 == a2 )
            JUMPOUT(0x4F59C0);
          ++result;
          v4 += 30;
        }
        while ( result < v3 );
      }
    }
  }
  return result;
}
