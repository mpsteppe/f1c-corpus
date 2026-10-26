void __fastcall sub_5A0770(_DWORD *a1)
{
  int v1; // esi
  _DWORD **v2; // ebp
  char v3; // al
  _DWORD *v4; // edi
  void (__thiscall ***v5)(_DWORD, int); // ecx
  _DWORD *v6; // [esp+4h] [ebp-4h]

  v1 = *a1;
  v6 = a1;
  if ( *a1 )
  {
    do
    {
      v2 = (_DWORD **)v1;
      v3 = *(_BYTE *)(v1 + 8);
      v1 = *(_DWORD *)(v1 + 4);
      if ( v3 )
      {
        v4 = *v2;
        if ( *v2 )
        {
          v5 = (void (__thiscall ***)(_DWORD, int))*v4;
          if ( *v4 )
          {
            if ( *(v5 - 1) )
              (**v5)(v5, 3);
            else
              j_j__free(v5 - 1);
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
