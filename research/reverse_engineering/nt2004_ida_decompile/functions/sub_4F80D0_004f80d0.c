int __thiscall sub_4F80D0(_DWORD *this)
{
  int result; // eax
  int v2; // ecx
  int i; // esi

  result = sub_4F7ED0(this);
  v2 = NumOfElements;
  for ( i = 1; i <= v2; ++i )
  {
    result = 0;
    if ( v2 > 0 )
    {
      while ( i != *(_DWORD *)(dword_75AAD0[result] + 20884) )
      {
        if ( ++result >= v2 )
          goto LABEL_10;
      }
      if ( i % 2 == 1 )
        result = sub_4F8150(dword_75AAD0[result]);
      else
        result = sub_4F8170(dword_75AAD0[result]);
      v2 = NumOfElements;
    }
LABEL_10:
    ;
  }
  return result;
}
