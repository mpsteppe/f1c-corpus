char __userpurge sub_5D9700@<al>(int *a1@<ecx>, __int32 a2@<ebx>, int a3@<esi>, int a4, char a5)
{
  char result; // al
  int v6; // esi
  int v7; // edx
  int v8; // edi
  void *v9; // edi

  result = 0;
  if ( a4 )
  {
    v6 = *a1;
    v7 = 0;
    if ( *a1 )
    {
      while ( *(_DWORD *)v6 != a4 )
      {
        v7 = v6;
        v6 = *(_DWORD *)(v6 + 4);
        if ( !v6 )
          return result;
      }
      if ( v6 == a1[2] )
        a1[2] = *(_DWORD *)(v6 + 4);
      v8 = *(_DWORD *)(v6 + 4);
      if ( v7 )
        *(_DWORD *)(v7 + 4) = v8;
      else
        *a1 = v8;
      if ( a1[1] == v6 )
        a1[1] = v7;
      --a1[3];
      if ( !a5 )
        *(_BYTE *)(v6 + 8) = 0;
      if ( *(_BYTE *)(v6 + 8) )
      {
        v9 = *(void **)v6;
        if ( *(_DWORD *)v6 )
        {
          sub_51D670(*(void **)v6, a2, a3);
          j__free(v9);
        }
      }
      j__free((void *)v6);
      return 1;
    }
  }
  return result;
}
