int __thiscall sub_4E6CD0(char *this)
{
  const char *v2; // ecx
  char *v3; // eax
  char *v4; // edx
  int v5; // esi
  char v6; // cl
  char *v7; // ecx
  int v8; // eax
  int v9; // esi
  bool v10; // zf
  int v11; // ebx
  LPVOID **v12; // ebp
  char v13; // al
  LPVOID *v14; // edi
  _DWORD v16[3]; // [esp+10h] [ebp-210h] BYREF
  int v17; // [esp+1Ch] [ebp-204h]
  char v18[512]; // [esp+20h] [ebp-200h] BYREF

  v2 = *(const char **)this;
  memset(v16, 0, sizeof(v16));
  v17 = 0;
  if ( !v2 )
    v2 = &byte_629120;
  strcpy(v18, v2);
  v3 = &v18[strlen(v18)];
  if ( v3 > v18 )
  {
    while ( *v3 != 92 )
    {
      if ( --v3 <= v18 )
        goto LABEL_8;
    }
    ++v3;
  }
LABEL_8:
  v4 = this + 1164;
  v5 = this + 1164 - v3;
  do
  {
    v6 = *v3;
    v3[v5] = *v3;
    ++v3;
  }
  while ( v6 );
  v7 = &v4[strlen(this + 1164)];
  if ( v7 > v4 )
  {
    while ( *v7 != 46 )
    {
      if ( --v7 <= v4 )
        goto LABEL_15;
    }
    *v7 = 0;
  }
LABEL_15:
  strcat(this + 1164, ".dds");
  sub_4E6E00(v16);
  v8 = v17;
  v9 = v16[0];
  v10 = v16[0] == 0;
  *((_DWORD *)this + 307) = v17;
  v11 = v8;
  if ( !v10 )
  {
    do
    {
      v12 = (LPVOID **)v9;
      v13 = *(_BYTE *)(v9 + 8);
      v9 = *(_DWORD *)(v9 + 4);
      if ( v13 )
      {
        v14 = *v12;
        if ( *v12 )
        {
          if ( *v14 )
            sub_5BE8AE(*v14);
          sub_5BE8AE(v14);
        }
      }
      sub_5BE8AE(v12);
    }
    while ( v9 );
  }
  return v11;
}
