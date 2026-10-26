int __thiscall sub_480120(void *this)
{
  void *v1; // ebx
  int v2; // eax
  int v3; // eax
  int *v4; // esi
  unsigned int v5; // edi
  int v6; // eax
  unsigned int v7; // kr04_4
  int v8; // edx
  unsigned __int8 v9; // bl
  int v10; // eax
  const char *v11; // eax
  int v12; // edx
  unsigned __int8 v13; // cl
  int v14; // eax
  char v16; // [esp+10h] [ebp-Eh]
  char v17; // [esp+11h] [ebp-Dh]
  unsigned int v18; // [esp+12h] [ebp-Ch] BYREF
  int v19; // [esp+16h] [ebp-8h]
  void *v20; // [esp+1Ah] [ebp-4h]

  v1 = this;
  v2 = *(_DWORD *)dword_76BB24;
  v20 = this;
  v3 = (*(int (__thiscall **)(int))(v2 + 100))(dword_76BB24);
  if ( v3 )
  {
    v4 = *(int **)(v3 + 28);
    if ( v4 )
    {
      v5 = (*(int (__thiscall **)(_DWORD))(*v4 + 64))(*(_DWORD *)(v3 + 28));
      v6 = *v4;
      v18 = 0;
      if ( (*(unsigned __int8 (__thiscall **)(int *, char *, _DWORD, unsigned int *))(v6 + 168))(
             v4,
             byte_765578,
             0,
             &v18) )
      {
        if ( v18 <= v5 )
        {
          v7 = strlen(byte_765578) + 1;
          if ( (int)(v7 - 1) > 0 )
          {
            v8 = *v4;
            v9 = 0;
            v16 = 0;
            v17 = 1;
            LOBYTE(v19) = 0;
            if ( (*(unsigned __int8 (__thiscall **)(int *))(v8 + 144))(v4) )
            {
              while ( 1 )
              {
                v10 = (*(int (__thiscall **)(int *, int))(*v4 + 148))(v4, v19);
                if ( v10 )
                {
                  v11 = *(const char **)(v10 + 8);
                  if ( !v11 )
                    v11 = &byte_629120;
                  if ( !_strcmpi(v11, byte_765578) )
                    break;
                }
                v12 = *v4;
                LOBYTE(v19) = ++v9;
                if ( v9 >= (*(unsigned __int8 (__thiscall **)(int *))(v12 + 144))(v4) )
                  goto LABEL_14;
              }
              v16 = 1;
            }
LABEL_14:
            v13 = 0;
            v14 = 0;
            while ( byte_765578[v14] == 32 )
            {
              v14 = ++v13;
              if ( v13 >= (int)(v7 - 1) )
                goto LABEL_19;
            }
            v17 = 0;
LABEL_19:
            if ( !v16 && !v17 )
            {
              (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v20 + 36))(v20, 0);
              return 0;
            }
            v1 = v20;
          }
        }
      }
    }
  }
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)v1 + 36))(v1, 1);
  return 0;
}
