void __thiscall sub_48BE60(void *this, const char *a2)
{
  char *v3; // eax
  char *v4; // edi
  void *v5; // ecx
  int v6; // eax
  int v7; // ecx
  char *i; // eax
  char *v9; // eax
  unsigned int v10; // eax
  char *v11; // edx
  char v12; // cl
  char *v13; // eax
  char *v14; // edi
  void *v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-204h] BYREF
  char String2[253]; // [esp+10h] [ebp-200h] BYREF
  __int16 v18; // [esp+10Dh] [ebp-103h]
  char v19; // [esp+10Fh] [ebp-101h]
  char v20[256]; // [esp+110h] [ebp-100h] BYREF

  if ( a2 )
  {
    String2[0] = byte_629120;
    memset(&String2[1], 0, 0xFCu);
    v18 = 0;
    v19 = 0;
    strcpy(String2, a2);
    v3 = &String2[strlen(String2)];
    if ( v3 > String2 )
    {
      while ( *v3 != 46 )
      {
        if ( --v3 <= String2 )
          goto LABEL_7;
      }
      *v3 = 0;
    }
LABEL_7:
    v4 = &String2[strlen(String2) + 1];
    v5 = off_601F1C;
    *(_DWORD *)--v4 = dword_601F18;
    *((_DWORD *)v4 + 1) = v5;
    v6 = sub_4AD970(String2, 0, 0, 1);
    if ( v6 )
      goto LABEL_34;
    v7 = strlen(String2);
    if ( v7 > 0 )
    {
      for ( i = &String2[v7 - 1]; i >= String2; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v9 = &String2[strlen(String2)];
    if ( v9 > String2 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= String2 )
          goto LABEL_21;
      }
      *v9 = 0;
      if ( v9 > String2 )
      {
        while ( *v9 != 92 )
        {
          if ( --v9 <= String2 )
            goto LABEL_21;
        }
        *++v9 = 0;
      }
    }
LABEL_21:
    v10 = (unsigned int)(v9 - 2);
    if ( v10 > (unsigned int)String2 )
    {
      while ( *(_BYTE *)v10 != 92 )
      {
        if ( --v10 <= (unsigned int)String2 )
          goto LABEL_26;
      }
      ++v10;
    }
LABEL_26:
    v11 = &v20[-v10];
    do
    {
      v12 = *(_BYTE *)v10;
      v11[v10] = *(_BYTE *)v10;
      ++v10;
    }
    while ( v12 );
    v13 = &v20[strlen(v20)];
    if ( v13 > v20 )
    {
      while ( *v13 != 92 )
      {
        if ( --v13 <= v20 )
          goto LABEL_33;
      }
      *v13 = 0;
    }
LABEL_33:
    v16 = strlen(v20) + 1;
    qmemcpy(&String2[strlen(String2)], v20, v16);
    v14 = &String2[strlen(String2) + 1];
    v15 = off_601F1C;
    *(_DWORD *)--v14 = dword_601F18;
    *((_DWORD *)v14 + 1) = v15;
    v6 = sub_4AD970(String2, 0, 0, 1);
    if ( v6 )
    {
LABEL_34:
      sub_4B0AC0(v6);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 40))(this, 1);
      sub_578600(a2);
    }
    else
    {
      (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
      sub_578600(&byte_629120);
    }
  }
}
