int sub_479510()
{
  int v0; // edi
  int v1; // eax
  int v2; // esi
  CHAR **v3; // eax
  CHAR **v4; // edi
  CHAR *v5; // eax
  int v6; // eax

  v0 = sub_49FB50();
  if ( v0 >= 0 )
  {
    v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
    if ( v1 )
    {
      v2 = *(_DWORD *)(v1 + 28);
      if ( v2 )
      {
        if ( v0 < (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 100))(*(_DWORD *)(v1 + 28)) )
        {
          v3 = (CHAR **)(*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 108))(v2, v0);
          v4 = v3;
          if ( v3 )
          {
            v5 = *v3;
            if ( !*v4 )
              v5 = &byte_629120;
            sub_578600(v5);
            dword_7652F8 = (int)v4[2];
            dword_7652E4 = *((unsigned __int8 *)v4 + 14);
            v6 = (*(int (__thiscall **)(int, CHAR **))(*(_DWORD *)v2 + 140))(v2, v4);
            sub_578600(v6);
          }
        }
      }
    }
  }
  return 0;
}
