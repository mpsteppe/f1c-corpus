int __thiscall sub_47FBF0(_DWORD *this)
{
  const char *v1; // edi
  int v3; // eax
  int *v4; // esi
  int v5; // edx
  unsigned __int8 v6; // bl
  int v7; // ecx
  const char **v8; // eax
  const char **v9; // edi
  const char *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  const char *v14; // eax
  void *v15; // [esp+10h] [ebp-4h] BYREF

  v1 = dword_765324;
  if ( !dword_765324 )
    v1 = &byte_629120;
  if ( strlen(v1) )
  {
    v3 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
    if ( v3 )
    {
      v4 = *(int **)(v3 + 28);
      if ( v4 )
      {
        v5 = *v4;
        v6 = 0;
        v7 = *(_DWORD *)(v3 + 28);
        LOBYTE(v15) = 0;
        if ( (*(unsigned __int8 (__thiscall **)(int))(v5 + 100))(v7) )
        {
          while ( 1 )
          {
            v8 = (const char **)(*(int (__thiscall **)(int *, void *))(*v4 + 108))(v4, v15);
            v9 = v8;
            if ( v8 )
            {
              v10 = *v8;
              if ( !*v9 )
                v10 = &byte_629120;
              v11 = dword_765324;
              if ( !dword_765324 )
                v11 = &byte_629120;
              if ( !_strcmpi(v11, v10) )
                break;
            }
            v12 = *v4;
            LOBYTE(v15) = ++v6;
            if ( v6 >= (*(unsigned __int8 (__thiscall **)(int *))(v12 + 100))(v4) )
              return 0;
          }
          v14 = (const char *)this[42];
          v15 = 0;
          if ( !v14 )
            v14 = &byte_629120;
          if ( !_strcmpi(v14, aErrorcheck) )
          {
            (*(void (__thiscall **)(int *, const char **, _DWORD, void **))(*v4 + 116))(v4, v9, 0, &v15);
            if ( sub_46DFC0(v15) )
            {
              sub_4AD720(a2003CareerSpon, 1);
              sub_4AD720(a2003CareerEndC, 1);
              return -1;
            }
          }
          if ( (*(unsigned __int8 (__thiscall **)(int *, const char **, int, void **))(*v4 + 116))(v4, v9, 1, &v15) )
            dword_600F44 = 1;
        }
      }
    }
  }
  return 0;
}
