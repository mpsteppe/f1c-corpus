int __thiscall sub_684DF7(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4)
{
  int result; // eax
  unsigned int v5; // edi

  result = a4;
  if ( a2[14] != a4 )
  {
    a2[14] = a4;
    ++*a3;
    v5 = 0;
    if ( a2[5] )
    {
      while ( 1 )
      {
        result = sub_684DF7(*(_DWORD *)(this[6] + 4 * *(_DWORD *)(a2[6] + 4 * v5++)), a3, result);
        if ( v5 >= a2[5] )
          break;
        result = a4;
      }
    }
  }
  return result;
}
