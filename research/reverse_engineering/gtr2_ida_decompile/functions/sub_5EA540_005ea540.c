char __userpurge sub_5EA540@<al>(int a1@<ecx>, __int32 a2@<ebx>, int a3, char a4)
{
  _DWORD *v4; // eax
  int *v5; // edi
  _DWORD *v6; // esi

  v4 = *(_DWORD **)(a1 + 36);
  v5 = (int *)(a1 + 36);
  if ( v4 )
  {
    while ( !*v4 || *v4 != a3 )
    {
      v4 = (_DWORD *)v4[1];
      if ( !v4 )
        return (char)v4;
    }
    v6 = (_DWORD *)*v4;
    if ( *v4 )
    {
      if ( (a4 & 1) != 0 )
        v6[54] = 1;
      v4 = (_DWORD *)sub_5E95C0(v6);
      if ( !v4 )
      {
        sub_5E9AE0();
        LOBYTE(v4) = sub_5E99E0(v5, a2, (int)v6, (int)v6, 1);
      }
    }
  }
  return (char)v4;
}
