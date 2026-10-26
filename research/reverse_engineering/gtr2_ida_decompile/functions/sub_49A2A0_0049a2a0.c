int __thiscall sub_49A2A0(_DWORD *this)
{
  _DWORD *v1; // ebx
  char *v2; // edi
  int result; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // esi
  const char *v7; // eax
  double v8; // st7
  const char *v9; // edi
  int v10; // ebp
  int v11; // eax
  char v12; // cl
  const char *v13; // ebx
  char *v14; // edi
  unsigned int v16; // eax
  char *v17; // edi
  int v19; // [esp+8h] [ebp-278h]
  int v20; // [esp+8h] [ebp-278h]
  float v21; // [esp+1Ch] [ebp-264h]
  float v22; // [esp+1Ch] [ebp-264h]
  int v23; // [esp+1Ch] [ebp-264h]
  int v24; // [esp+20h] [ebp-260h]
  char *v26; // [esp+28h] [ebp-258h]
  int v27; // [esp+2Ch] [ebp-254h]
  char Buffer[48]; // [esp+30h] [ebp-250h] BYREF
  _BYTE v29[47]; // [esp+60h] [ebp-220h] BYREF
  char v30; // [esp+8Fh] [ebp-1F1h]
  _BYTE v31[47]; // [esp+90h] [ebp-1F0h] BYREF
  char v32; // [esp+BFh] [ebp-1C1h]
  _BYTE v33[47]; // [esp+C0h] [ebp-1C0h] BYREF
  char v34; // [esp+EFh] [ebp-191h]
  char v35[48]; // [esp+F0h] [ebp-190h] BYREF
  char v36[48]; // [esp+120h] [ebp-160h] BYREF
  char v37[47]; // [esp+150h] [ebp-130h] BYREF
  char v38; // [esp+17Fh] [ebp-101h] BYREF
  _BYTE v39[256]; // [esp+180h] [ebp-100h] BYREF

  v1 = this;
  v2 = (char *)&unk_9204A0 + 22616 * this[150];
  result = *((_DWORD *)v2 + 3705);
  v26 = v2;
  if ( result == -1 || *((int *)v2 + 4821) < 1 || result == 4 )
  {
    this[150] = -1;
  }
  else
  {
    sub_4D0AC0(v19);
    sub_630FE0(v29, &v2[108 * *((_DWORD *)v2 + 5447) + 21568], 47);
    v30 = 0;
    sub_630FE0(v31, v2 + 22064, 47);
    v32 = 0;
    if ( dword_B6E088 )
      sub_630FE0(v33, v2 + 21808, 47);
    else
      sub_630FE0(v33, v2 + 21872, 47);
    v4 = *((_DWORD *)v2 + 4821);
    v5 = *((_DWORD *)v2 + 4869);
    v34 = 0;
    v24 = v4;
    if ( v4 >= v5 )
      v24 = v5;
    result = v24;
    v6 = 0;
    if ( v24 > 0 )
    {
      while ( 1 )
      {
        if ( (unsigned __int8)sub_523BA0(&unk_BE1210, v20) )
        {
          v7 = v6 ? CommandLine : sub_41D840(&byte_91CC38, (const char *)&off_6FB0B8);
          strcpy(Buffer, v7);
        }
        else
        {
          sprintf(Buffer, "%d", *(char *)(*((_DWORD *)v2 + 4872) + v6));
        }
        v27 = v6 + 1;
        sprintf(v35, "%d", v6 + 1);
        v21 = *(float *)(*((_DWORD *)v2 + 4871) + 4 * v6);
        if ( v21 > 0.0 )
          sprintf(v36, "%d:%06.3f", (unsigned int)(unsigned __int64)(v21 * 0.016666668), (double)fmod(v21, 60.0));
        else
          strcpy(v36, "--:--.---");
        if ( v21 <= 0.0 || *((float *)v2 + 4859) <= 0.0 )
        {
          strcpy(v37, "--:--.---");
        }
        else
        {
          v8 = v21 - *((float *)v2 + 4859);
          v9 = "+";
          v22 = v8;
          if ( v8 < 0.0 )
            v9 = WindowName;
          sprintf(v37, "%s%d:%06.3f", v9, (unsigned int)(unsigned __int64)(v22 * 0.016666668), (double)fmod(v22, 60.0));
          if ( v22 == 0.0 )
            v1[146] = v6;
        }
        v10 = 1;
        v11 = 0;
        do
        {
          v12 = Buffer[v11];
          v39[v11++] = v12;
        }
        while ( v12 );
        v23 = v1[153];
        v13 = v29;
        do
        {
          if ( v23 != 1 || v10 == 1 || v10 == 5 || v10 == 2 )
          {
            v14 = &v38;
            while ( *++v14 )
              ;
            *(_WORD *)v14 = 9;
            v16 = strlen(v13) + 1;
            v17 = &v38;
            while ( *++v17 )
              ;
            qmemcpy(v17, v13, v16);
          }
          ++v10;
          v13 += 48;
        }
        while ( v10 < 7 );
        sub_4D93B0(v39, 0, 0, 0, 0, 0, -1, -1, -1, -1);
        sub_630FE0(v29, CommandLine, 47);
        v30 = 0;
        sub_630FE0(v31, CommandLine, 47);
        v32 = 0;
        sub_630FE0(v33, CommandLine, 47);
        ++v6;
        result = v24;
        v34 = 0;
        if ( v27 >= v24 )
          break;
        v2 = v26;
        v1 = this;
      }
    }
  }
  return result;
}
