char __fastcall sub_5FF6F0(int a1, int a2, _DWORD *a3)
{
  _DWORD *i; // eax

  LOBYTE(i) = *a3 & 3;
  if ( (_BYTE)i == 1 )
  {
    sub_5FF0E0(a1, a2, a3);
    i = (_DWORD *)a3[157];
    a3[159] = i;
    if ( i )
    {
      for ( i = (_DWORD *)*i; i; i = (_DWORD *)*i )
      {
        sub_5FF6F0(i);
        i = (_DWORD *)a3[159];
        if ( !i )
          break;
        i = (_DWORD *)i[1];
        a3[159] = i;
        if ( !i )
          break;
      }
    }
  }
  return (char)i;
}
