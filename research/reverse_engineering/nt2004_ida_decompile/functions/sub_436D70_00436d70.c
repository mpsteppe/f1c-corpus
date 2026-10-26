char __thiscall sub_436D70(int *this, int a2)
{
  int *v2; // ebx
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // esi
  int v9; // edi
  int v10; // ebp
  CHAR **v11; // edx
  CHAR *v12; // esi
  CHAR *v13; // ecx
  bool v14; // cf
  unsigned __int8 v15; // bl
  int v16; // ecx
  int v17; // ebx
  CHAR **v18; // edx
  CHAR *v19; // esi
  CHAR *v20; // ecx
  bool v21; // cf
  int v22; // ecx
  int v23; // ecx
  int v24; // edx
  int v26; // [esp+4h] [ebp-8h]
  int *v27; // [esp+8h] [ebp-4h]

  v2 = this;
  v3 = *this;
  v4 = 0;
  v27 = v2;
  v5 = v3;
  if ( v3 )
  {
    do
    {
      v5 = *(_DWORD *)(v5 + 4);
      ++v4;
    }
    while ( v5 );
    if ( v4 >= 2 )
    {
      v6 = v4 / 2 - 1;
      v7 = v3;
      if ( v6 > 0 )
      {
        do
        {
          --v6;
          v7 = *(_DWORD *)(v7 + 4);
        }
        while ( v6 );
      }
      v8 = *(_DWORD *)(v7 + 4);
      *(_DWORD *)(v7 + 4) = 0;
      v9 = sub_436F70(v3);
      v4 = sub_436F70(v8);
      v10 = v4;
      if ( v9 )
      {
        if ( v4 )
        {
          v11 = *(CHAR ***)v9;
          v12 = **(CHAR ***)v4;
          if ( !v12 )
            v12 = &byte_629120;
          v13 = *v11;
          if ( !*v11 )
            v13 = &byte_629120;
          while ( 1 )
          {
            LOBYTE(v4) = *v13;
            v14 = (unsigned __int8)*v13 < (unsigned __int8)*v12;
            if ( *v13 != *v12 )
              break;
            if ( !*v13 )
              goto LABEL_16;
            LOBYTE(v4) = v13[1];
            v15 = v12[1];
            v14 = (unsigned __int8)v4 < v15;
            if ( (_BYTE)v4 != v15 )
              break;
            v13 += 2;
            v12 += 2;
            if ( !(_BYTE)v4 )
            {
LABEL_16:
              v16 = 0;
              goto LABEL_18;
            }
          }
          v16 = -v14 - (v14 - 1);
LABEL_18:
          if ( v16 >= 0 )
          {
            v26 = v10;
            v17 = v10;
            v10 = *(_DWORD *)(v10 + 4);
          }
          else
          {
            v26 = v9;
            v17 = v9;
            v9 = *(_DWORD *)(v9 + 4);
          }
          if ( v9 )
          {
            while ( v10 )
            {
              v18 = *(CHAR ***)v9;
              v19 = **(CHAR ***)v10;
              if ( !v19 )
                v19 = &byte_629120;
              v20 = *v18;
              if ( !*v18 )
                v20 = &byte_629120;
              while ( 1 )
              {
                LOBYTE(v4) = *v20;
                v21 = (unsigned __int8)*v20 < (unsigned __int8)*v19;
                if ( *v20 != *v19 )
                  break;
                if ( !*v20 )
                  goto LABEL_31;
                LOBYTE(v4) = v20[1];
                v21 = (unsigned __int8)v4 < (unsigned __int8)v19[1];
                if ( (_BYTE)v4 != v19[1] )
                  break;
                v20 += 2;
                v19 += 2;
                if ( !(_BYTE)v4 )
                {
LABEL_31:
                  v22 = 0;
                  goto LABEL_33;
                }
              }
              v22 = -v21 - (v21 - 1);
LABEL_33:
              if ( v22 >= 0 )
              {
                v23 = v10;
                v10 = *(_DWORD *)(v10 + 4);
              }
              else
              {
                v23 = v9;
                v9 = *(_DWORD *)(v9 + 4);
              }
              *(_DWORD *)(v17 + 4) = v23;
              v17 = v23;
              if ( !v9 )
                goto LABEL_37;
            }
            *(_DWORD *)(v17 + 4) = v9;
            v2 = v27;
          }
          else
          {
LABEL_37:
            if ( v10 )
              *(_DWORD *)(v17 + 4) = v10;
            else
              *(_DWORD *)(v17 + 4) = 0;
            v2 = v27;
          }
        }
        else
        {
          v26 = v9;
        }
      }
      else
      {
        v26 = v4;
      }
      v3 = v26;
    }
  }
  *v2 = v3;
  if ( v3 && (v4 = *(_DWORD *)(v3 + 4)) != 0 )
  {
    do
    {
      v24 = v4;
      v4 = *(_DWORD *)(v4 + 4);
    }
    while ( v4 );
    v2[1] = v24;
    v2[2] = v3;
  }
  else
  {
    v2[1] = v3;
    v2[2] = v3;
  }
  return v4;
}
