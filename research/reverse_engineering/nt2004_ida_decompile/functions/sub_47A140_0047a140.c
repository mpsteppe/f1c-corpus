int __thiscall sub_47A140(void *this)
{
  unsigned __int8 v1; // bl
  int v2; // ebx
  int v3; // ebp
  int v4; // eax
  char v5; // cl
  int v6; // esi
  const char *v7; // ecx
  int v8; // esi
  const char *v9; // eax
  double v10; // st7
  double v11; // st7
  unsigned __int8 v12; // al
  unsigned __int8 v13; // al
  bool v14; // zf
  unsigned __int8 v16; // [esp+23h] [ebp-451h]
  CHAR v17; // [esp+24h] [ebp-450h] BYREF
  __int16 v18; // [esp+25h] [ebp-44Fh]
  char v19; // [esp+27h] [ebp-44Dh]
  _DWORD **v20; // [esp+28h] [ebp-44Ch]
  int v21; // [esp+2Ch] [ebp-448h]
  void *v22; // [esp+30h] [ebp-444h]
  char Buffer[253]; // [esp+34h] [ebp-440h] BYREF
  __int16 v24; // [esp+131h] [ebp-343h]
  char v25; // [esp+133h] [ebp-341h]
  char v26[253]; // [esp+134h] [ebp-340h] BYREF
  __int16 v27; // [esp+231h] [ebp-243h]
  char v28; // [esp+233h] [ebp-241h]
  char Destination[255]; // [esp+234h] [ebp-240h] BYREF
  char v30; // [esp+333h] [ebp-141h]
  _BYTE v31[320]; // [esp+334h] [ebp-140h] BYREF

  v22 = this;
  sub_49FEC0(this);
  v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 92))(dword_76BB24);
  sub_47A040((int)v31, 80);
  v18 = 0;
  v19 = 0;
  Buffer[0] = byte_629120;
  v26[0] = byte_629120;
  v17 = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v24 = 0;
  v25 = 0;
  memset(&v26[1], 0, 0xFCu);
  v27 = 0;
  v28 = 0;
  sub_49F640(&v17);
  if ( v1 )
  {
    v20 = (_DWORD **)v31;
    v21 = v1;
    do
    {
      v2 = (int)*v20;
      v3 = sub_40EFA0(*v20);
      if ( v3 )
      {
        strcpy(Destination, "Nobody");
        memset(&Destination[7], 0, 0xF8u);
        v30 = 0;
        v4 = 0;
        do
        {
          v5 = *(&byte_629120 + v4);
          v26[v4++] = v5;
        }
        while ( v5 );
        if ( *(_BYTE *)(v2 + 32) )
        {
          sub_4CE010(Destination, 255);
        }
        else
        {
          v16 = 0;
          if ( dword_7D6A58 > 0 )
          {
            v6 = 0;
            do
            {
              v7 = *(const char **)v2;
              if ( !*(_DWORD *)v2 )
                v7 = &byte_629120;
              v8 = 1232 * v6;
              v9 = *(const char **)(v8 + dword_7D6A5C);
              if ( !v9 )
                v9 = &byte_629120;
              if ( !_strcmpi(v9, v7) )
              {
                strncpy(Destination, (const char *)(v8 + dword_7D6A5C + 246), 0xFFu);
                v30 = 0;
              }
              v6 = ++v16;
            }
            while ( v16 < dword_7D6A58 );
          }
        }
        sub_405480(Buffer, 0xFFu, "%s%s", Destination, &v17);
        strcat(v26, Buffer);
        v10 = sub_414320(v3);
        sub_405480(Buffer, 0xFFu, "%.3f%s", v10, &v17);
        strcat(v26, Buffer);
        v11 = sub_414380(v3);
        sub_405480(Buffer, 0xFFu, "%.3f%s", v11, &v17);
        strcat(v26, Buffer);
        v12 = sub_414280(v3);
        sub_405480(Buffer, 0xFFu, "%d%s", v12, &v17);
        strcat(v26, Buffer);
        sub_405480(Buffer, 0xFFu, "%d%s", *(_DWORD *)(v3 + 24), &v17);
        strcat(v26, Buffer);
        v13 = sub_4142A0(v3);
        sub_405480(Buffer, 0xFFu, "%d%s", v13, &v17);
        strcat(v26, Buffer);
        sub_49F730(v26, 0, 0, 0, 0);
      }
      v14 = v21 == 1;
      ++v20;
      --v21;
    }
    while ( !v14 );
  }
  return sub_4A0640(0);
}
