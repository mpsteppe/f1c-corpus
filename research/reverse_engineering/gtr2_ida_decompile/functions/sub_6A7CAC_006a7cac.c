int __thiscall sub_6A7CAC(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v4; // edi

  result = 1;
  if ( a2[10] == 1 )
  {
    v4 = 0;
    if ( a2[5] )
    {
      while ( !sub_6A7CAC(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(a2[6] + 4 * v4))) )
      {
        if ( (unsigned int)++v4 >= a2[5] )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
