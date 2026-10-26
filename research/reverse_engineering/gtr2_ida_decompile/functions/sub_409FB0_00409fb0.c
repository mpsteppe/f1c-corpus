int __fastcall sub_409FB0(_DWORD *a1)
{
  int v1; // esi
  void ***v2; // ebp
  char v3; // al
  void **v4; // edi
  _DWORD *v6; // [esp+10h] [ebp-4h]

  v1 = *a1;
  v6 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (void ***)v1;
      v3 = *(_BYTE *)(v1 + 8);
      v1 = *(_DWORD *)(v1 + 4);
      if ( v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
          if ( *v4 )
            j_j__free(*v4);
          j__free(v4);
        }
      }
      j__free(v2);
    }
    while ( v1 );
    a1 = v6;
  }
  return off_16C94B8(a1);
}
