int __thiscall sub_479A40(void *this)
{
  int result; // eax
  unsigned __int8 v2; // bl
  int v3; // eax
  const char **v4; // ebx
  int v5; // ebp
  int v6; // eax
  char v7; // cl
  unsigned __int8 v8; // bl
  int v9; // esi
  const char *v10; // ecx
  int v11; // esi
  const char *v12; // eax
  const char *v13; // ecx
  unsigned __int8 v14; // al
  int v15; // esi
  const char *v16; // ecx
  int v17; // esi
  const char *v18; // eax
  unsigned __int8 v19; // al
  unsigned __int8 v20; // al
  unsigned __int8 v21; // al
  unsigned __int8 v22; // al
  bool v23; // zf
  CHAR v24; // [esp+8h] [ebp-560h] BYREF
  __int16 v25; // [esp+9h] [ebp-55Fh]
  char v26; // [esp+Bh] [ebp-55Dh]
  unsigned __int8 v27; // [esp+Fh] [ebp-559h]
  const char **v28; // [esp+10h] [ebp-558h]
  const char ***v29; // [esp+14h] [ebp-554h]
  int v30; // [esp+18h] [ebp-550h]
  int v31; // [esp+1Ch] [ebp-54Ch]
  void *v32; // [esp+20h] [ebp-548h]
  char ArgList[4]; // [esp+24h] [ebp-544h]
  char v34[253]; // [esp+28h] [ebp-540h] BYREF
  __int16 v35; // [esp+125h] [ebp-443h]
  char v36; // [esp+127h] [ebp-441h]
  char v37[253]; // [esp+128h] [ebp-440h] BYREF
  __int16 v38; // [esp+225h] [ebp-343h]
  char v39; // [esp+227h] [ebp-341h]
  char Destination[255]; // [esp+228h] [ebp-340h] BYREF
  char v41; // [esp+327h] [ebp-241h]
  char Buffer[4]; // [esp+328h] [ebp-240h] BYREF
  _BYTE v43[252]; // [esp+32Ch] [ebp-23Ch] BYREF
  _DWORD *v44[80]; // [esp+428h] [ebp-140h] BYREF

  v32 = this;
  sub_49FEC0(this);
  result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 92))(dword_76BB24);
  v2 = result;
  if ( (_BYTE)result )
  {
    sub_47A040(v44, 80);
    v25 = 0;
    v26 = 0;
    v34[0] = byte_629120;
    v37[0] = byte_629120;
    v24 = byte_629120;
    memset(&v34[1], 0, 0xFCu);
    v35 = 0;
    v36 = 0;
    memset(&v37[1], 0, 0xFCu);
    v38 = 0;
    v39 = 0;
    v31 = 0;
    v3 = sub_40EFA0(v44[0]);
    if ( v3 )
      v31 = *(_DWORD *)(v3 + 12);
    sub_49F640(&v24);
    if ( v2 )
    {
      v29 = (const char ***)v44;
      v30 = v2;
      do
      {
        v4 = *v29;
        v28 = *v29;
        v5 = sub_40EFA0(v28);
        if ( v5 )
        {
          strcpy(Buffer, "199");
          memset(v43, 0, sizeof(v43));
          strcpy(Destination, "Nobody");
          memset(&Destination[7], 0, 0xF8u);
          v41 = 0;
          *(_DWORD *)ArgList = *(_DWORD *)(v5 + 12) - v31;
          v6 = 0;
          do
          {
            v7 = *(&byte_629120 + v6);
            v37[v6++] = v7;
          }
          while ( v7 );
          if ( *((_BYTE *)v4 + 32) )
          {
            sub_4CE010(Destination, 255);
          }
          else
          {
            v8 = 0;
            if ( dword_7D6A58 > 0 )
            {
              v9 = 0;
              do
              {
                v10 = *v28;
                if ( !*v28 )
                  v10 = &byte_629120;
                v11 = 1232 * v9;
                v12 = *(const char **)(v11 + dword_7D6A5C);
                if ( !v12 )
                  v12 = &byte_629120;
                if ( !_strcmpi(v12, v10) )
                {
                  strncpy(Destination, (const char *)(v11 + dword_7D6A5C + 246), 0xFFu);
                  v41 = 0;
                }
                v9 = ++v8;
              }
              while ( v8 < dword_7D6A58 );
            }
            v4 = v28;
          }
          if ( *((_BYTE *)v4 + 32) )
          {
            v13 = v4[7];
            if ( v13 )
            {
              v14 = (*(int (__thiscall **)(const char *))(*(_DWORD *)v13 + 216))(v13);
              sub_405480(Buffer, 0xFFu, "%d", v14);
            }
          }
          else
          {
            v27 = 0;
            if ( dword_7D6A58 > 0 )
            {
              v15 = 0;
              do
              {
                v16 = *v4;
                if ( !*v4 )
                  v16 = &byte_629120;
                v17 = 1232 * v15;
                v18 = *(const char **)(v17 + dword_7D6A5C);
                if ( !v18 )
                  v18 = &byte_629120;
                if ( !_strcmpi(v18, v16) )
                {
                  strncpy(Buffer, (const char *)(v17 + dword_7D6A5C + 168), 0xFFu);
                  v43[251] = 0;
                }
                v15 = ++v27;
              }
              while ( v27 < dword_7D6A58 );
            }
          }
          sub_405480(v34, 0xFFu, "%d%s", *(unsigned __int8 *)(v5 + 16), &v24);
          strcat(v37, v34);
          sub_405480(v34, 0xFFu, "%s%s", Buffer, &v24);
          strcat(v37, v34);
          sub_405480(v34, 0xFFu, "%s%s", Destination, &v24);
          strcat(v37, v34);
          sub_405480(v34, 0xFFu, "%d%s", *(_DWORD *)(v5 + 12), &v24);
          strcat(v37, v34);
          sub_405480(v34, 0xFFu, "%d%s", *(_DWORD *)ArgList, &v24);
          strcat(v37, v34);
          v19 = sub_414250(v5);
          sub_405480(v34, 0xFFu, "%d%s", v19, &v24);
          strcat(v37, v34);
          v20 = sub_4142A0(v5);
          sub_405480(v34, 0xFFu, "%d%s", v20, &v24);
          strcat(v37, v34);
          v21 = sub_4142C0(v5);
          sub_405480(v34, 0xFFu, "%d%s", v21, &v24);
          strcat(v37, v34);
          v22 = sub_4142F0(v5);
          sub_405480(v34, 0xFFu, "%d%s", v22, &v24);
          strcat(v37, v34);
          sub_49F730(v37, 0, 0, 0, 0);
        }
        v23 = v30 == 1;
        ++v29;
        --v30;
      }
      while ( !v23 );
    }
    return sub_4A0640(0);
  }
  return result;
}
