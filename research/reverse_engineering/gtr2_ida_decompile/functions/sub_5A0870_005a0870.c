void __fastcall sub_5A0870(_DWORD *a1)
{
  int v1; // esi
  int **v2; // ebp
  char v3; // al
  int *v4; // edi
  int v5; // ecx
  _DWORD *v6; // [esp+4h] [ebp-4h]

  v1 = *a1;
  v6 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (int **)v1;
      v3 = *(_BYTE *)(v1 + 8);
      v1 = *(_DWORD *)(v1 + 4);
      if ( v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
          v5 = *v4;
          if ( *v4 )
          {
            if ( *(_DWORD *)(v5 - 4) )
              (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 4))(v5, 3);
            else
              j_j__free((void *)(v5 - 4));
          }
          j__free(v4);
        }
      }
      j__free(v2);
    }
    while ( v1 );
    a1 = v6;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
}
