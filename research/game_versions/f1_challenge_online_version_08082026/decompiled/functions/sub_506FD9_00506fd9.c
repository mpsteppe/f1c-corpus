int __usercall sub_506FD9@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  int v3; // eax
  unsigned int v4; // ebx
  bool v5; // cf
  unsigned int i; // edi

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 20) = v1;
  *v1 = &off_5ADB90;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v1[1071] )
  {
    v3 = v1[1072];
    if ( v3 )
    {
      v4 = v1[1063];
      v5 = v4 < v1[1064];
      *(_DWORD *)(a1 - 16) = v3;
      if ( v5 )
      {
        do
        {
          for ( i = v2[1060]; i < v2[1062]; i += 4 )
          {
            sub_587BCF(*(LPVOID *)(*(_DWORD *)(a1 - 16) + 4));
            *(_DWORD *)(a1 - 16) += 8;
          }
          ++v4;
        }
        while ( v4 < v2[1064] );
      }
    }
  }
  sub_587BCF((LPVOID)v2[1070]);
  sub_587BCF((LPVOID)v2[1072]);
  *(_DWORD *)(a1 - 4) = -1;
  return sub_506CCC(v2);
}
