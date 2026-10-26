void *sub_4BC6E0()
{
  int v0; // ebx
  void **v1; // eax
  char v2; // cl
  char *v3; // ebp
  char *v4; // esi
  int v5; // edi
  char *v6; // esi
  int v7; // ebx
  void *result; // eax
  void **v9; // [esp+Ch] [ebp-4h]

  v0 = dword_7662F0;
  while ( v0 )
  {
    v1 = (void **)v0;
    v2 = *(_BYTE *)(v0 + 8);
    v0 = *(_DWORD *)(v0 + 4);
    v9 = v1;
    if ( v2 )
    {
      v3 = (char *)*v1;
      if ( *v1 )
      {
        v4 = v3 + 556;
        v5 = 14;
        do
        {
          v4 -= 32;
          nullsub_5();
          --v5;
        }
        while ( v5 );
        sub_5BE8AE(v3);
        v1 = v9;
      }
    }
    sub_5BE8AE(v1);
  }
  dword_7662F0 = 0;
  dword_7662F4 = 0;
  dword_7662F8 = 0;
  dword_7662FC = 0;
  v6 = (char *)&unk_7662EC;
  v7 = 14;
  do
  {
    result = (void *)*((_DWORD *)v6 - 2);
    v6 -= 8;
    if ( result )
      result = (void *)sub_5BE8AE(result);
    --v7;
  }
  while ( v7 );
  return result;
}
