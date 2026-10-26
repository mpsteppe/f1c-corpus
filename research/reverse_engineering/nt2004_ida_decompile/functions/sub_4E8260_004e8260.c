int __thiscall sub_4E8260(_DWORD *this, const char *a2)
{
  int v2; // ebx
  char *i; // esi
  int *v5; // eax
  char **v6; // ecx
  int v7; // ebx
  int v8; // edi
  int *v9; // esi
  int **v10; // eax
  int v11; // edx
  int result; // eax
  int v13; // [esp+10h] [ebp-384h] BYREF
  int v14; // [esp+14h] [ebp-380h]
  int v15; // [esp+18h] [ebp-37Ch] BYREF
  int v16; // [esp+1Ch] [ebp-378h] BYREF
  char Delimiter[8]; // [esp+20h] [ebp-374h] BYREF
  char String2[8]; // [esp+28h] [ebp-36Ch] BYREF
  char v19[8]; // [esp+30h] [ebp-364h] BYREF
  char v20[4]; // [esp+38h] [ebp-35Ch] BYREF
  _DWORD v21[50]; // [esp+3Ch] [ebp-358h] BYREF
  _DWORD v22[50]; // [esp+104h] [ebp-290h] BYREF
  _DWORD v23[50]; // [esp+1CCh] [ebp-1C8h] BYREF
  char String[256]; // [esp+294h] [ebp-100h] BYREF

  v2 = 0;
  v13 = 0;
  sub_4E8200(this);
  if ( !a2 || !strcmp(a2, &byte_629120) )
  {
    sub_578600(&byte_629120);
    v7 = dword_7D6A58;
    v8 = 0;
    if ( dword_7D6A58 > 0 )
    {
      v13 = dword_7D6A58;
      do
      {
        v9 = (int *)operator new(4u);
        *v9 = v8;
        v10 = (int **)operator new(0xCu);
        if ( v10 )
        {
          *v10 = v9;
          v10[1] = 0;
          *((_BYTE *)v10 + 8) = 1;
        }
        else
        {
          v10 = 0;
        }
        if ( this[2] )
        {
          *(_DWORD *)(this[3] + 4) = v10;
        }
        else
        {
          this[2] = v10;
          this[4] = v10;
        }
        v11 = this[5] + 1;
        ++v8;
        this[3] = v10;
        this[5] = v11;
      }
      while ( v8 < v7 );
    }
  }
  else
  {
    sub_578600(a2);
    strcpy(String2, "AND:");
    strcpy(Delimiter, " ,\t\n");
    strcpy(v19, "NOT:");
    strcpy(v20, "OR:");
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    strcpy(String, a2);
    memset(v22, 0, sizeof(v22));
    memset(v21, 0, sizeof(v21));
    for ( i = strtok(String, Delimiter); i; i = strtok(0, Delimiter) )
    {
      if ( _strcmpi(i, String2) )
      {
        if ( _strcmpi(i, v20) )
        {
          if ( _strcmpi(i, v19) )
          {
            switch ( v14 )
            {
              case 0:
                goto LABEL_15;
              case 1:
                v5 = &v16;
                v6 = (char **)&v22[v16];
                break;
              case 2:
                v5 = &v13;
                v6 = (char **)&v23[v13];
                break;
              default:
LABEL_15:
                v5 = &v15;
                v6 = (char **)&v21[v2];
                break;
            }
            if ( *v5 < 49 )
            {
              ++*v5;
              v2 = v15;
              *v6 = i;
            }
            continue;
          }
          v14 = 2;
        }
        else
        {
          v14 = 1;
        }
      }
      else
      {
        v14 = 0;
      }
    }
    sub_4E7EA0(this, v21, v2);
    sub_4E7FB0(this, v22, v16);
    v13 = sub_4E80C0(this, v23, v13);
  }
  this[4] = this[2];
  result = v13;
  this[6] = 0;
  return result;
}
