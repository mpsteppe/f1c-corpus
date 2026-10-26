char __thiscall sub_419200(int this)
{
  char result; // al
  FILE *v3; // eax
  int v4; // esi
  LPVOID **v5; // ebp
  char v6; // al
  LPVOID *v7; // edi

  result = *(_BYTE *)(this + 16);
  if ( result )
  {
    v3 = *(FILE **)(this + 36);
    *(_BYTE *)(this + 16) = 0;
    if ( v3 )
    {
      fclose(v3);
      *(_DWORD *)(this + 36) = 0;
    }
    sub_5BE8AE(*(LPVOID *)(this + 40));
    *(_DWORD *)(this + 40) = 0;
    v4 = *(_DWORD *)(this + 20);
    while ( v4 )
    {
      v5 = (LPVOID **)v4;
      v6 = *(_BYTE *)(v4 + 8);
      v4 = *(_DWORD *)(v4 + 4);
      if ( v6 )
      {
        v7 = *v5;
        if ( *v5 )
        {
          if ( *v7 )
            sub_5BE8AE(*v7);
          sub_5BE8AE(v7);
        }
      }
      sub_5BE8AE(v5);
    }
    *(_DWORD *)(this + 20) = 0;
    *(_DWORD *)(this + 24) = 0;
    *(_DWORD *)(this + 28) = 0;
    *(_DWORD *)(this + 32) = 0;
    return sub_58DAB0();
  }
  return result;
}
