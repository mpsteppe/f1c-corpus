void __thiscall sub_4062B0(char *this, char **a2, int a3, char a4)
{
  char **v4; // ebx
  char *v5; // ebp
  int v6; // esi
  char *v7; // edi
  const char *v8; // eax
  char **v9; // esi
  char *v10; // eax
  char *v11; // ebp
  char *v12; // esi
  int v13; // edi
  char *v14; // esi
  char **v15; // edi
  int v16; // ebp
  char *v17; // eax
  int v19; // [esp+2Ch] [ebp+4h]
  int v20; // [esp+34h] [ebp+Ch]

  v4 = a2;
  v5 = this;
  if ( a2 )
  {
    v6 = a3;
    if ( a3 <= 3 && a3 > 0 )
    {
      if ( a4 )
      {
        v20 = 0;
        StringCopyWithBufferRealloc(&byte_5EA438);
        v19 = 0;
        v7 = v5 + 28;
        while ( v20 < v6 )
        {
          v8 = (const char *)*((_DWORD *)v7 - 3);
          if ( !v8 )
            v8 = &byte_5EA438;
          if ( !strcmp(v8, &byte_5EA438) && *((_DWORD *)v7 - 1) == -1 && *(_DWORD *)v7 == -1 && !v7[4] )
          {
            v9 = v4;
            ++v20;
            v10 = *v4;
            v4 += 5;
            if ( !v10 )
              v10 = &byte_5EA438;
            StringCopyWithBufferRealloc(v10);
            *((_DWORD *)v7 - 1) = v9[2];
            *(_DWORD *)v7 = v9[3];
            v7[4] = *((_BYTE *)v9 + 16);
          }
          v5 = this;
          v7 += 20;
          if ( ++v19 >= 3 )
            break;
          v6 = a3;
        }
        if ( v20 > 0 && !(*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 8))(v5) )
          sub_406790(v5);
      }
      else
      {
        AudioStreamCloseAndCleanup(this);
        v11 = v5 + 28;
        v12 = v11;
        v13 = 3;
        do
        {
          StringCopyWithBufferRealloc(&byte_5EA438);
          *((_DWORD *)v12 - 1) = -1;
          *(_DWORD *)v12 = -1;
          v12[4] = 0;
          v12 += 20;
          --v13;
        }
        while ( v13 );
        v14 = v11;
        v15 = a2 + 3;
        v16 = a3;
        do
        {
          v17 = *(v15 - 3);
          if ( !v17 )
            v17 = &byte_5EA438;
          StringCopyWithBufferRealloc(v17);
          *((_DWORD *)v14 - 1) = *(v15 - 1);
          *(_DWORD *)v14 = *v15;
          v14[4] = *((_BYTE *)v15 + 4);
          v15 += 5;
          v14 += 20;
          --v16;
        }
        while ( v16 );
        sub_406790(this);
      }
    }
  }
}

