const char **__thiscall sub_4A8E80(int this, const char *a2)
{
  char v3; // bl
  const char **v4; // esi
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // ecx
  const char *v9; // eax
  const char **v10; // ebx
  const char *v11; // eax
  const char *v12; // eax
  const char **v13; // ebx
  const char *v14; // eax
  const char *v15; // eax
  const char **v16; // ebx
  const char *v17; // eax
  const char *v18; // eax
  const char **v19; // ebx
  const char *v20; // eax
  char v21; // [esp+13h] [ebp-12Dh]
  int v22; // [esp+14h] [ebp-12Ch] BYREF
  int v23; // [esp+18h] [ebp-128h] BYREF
  int v24; // [esp+1Ch] [ebp-124h] BYREF
  int v25; // [esp+20h] [ebp-120h] BYREF
  int v26; // [esp+24h] [ebp-11Ch] BYREF
  int v27; // [esp+28h] [ebp-118h] BYREF
  int v28; // [esp+2Ch] [ebp-114h] BYREF
  int v29; // [esp+30h] [ebp-110h] BYREF
  int v30; // [esp+34h] [ebp-10Ch] BYREF
  int v31; // [esp+38h] [ebp-108h] BYREF
  int v32; // [esp+3Ch] [ebp-104h] BYREF
  char String1[128]; // [esp+40h] [ebp-100h] BYREF
  char String[125]; // [esp+C0h] [ebp-80h] BYREF
  __int16 v35; // [esp+13Dh] [ebp-3h]
  char v36; // [esp+13Fh] [ebp-1h]

  String1[0] = byte_629120;
  memset(&String1[1], 0, 127);
  String[0] = byte_629120;
  memset(&String[1], 0, 0x7Cu);
  v35 = 0;
  v3 = 0;
  v36 = 0;
  *(float *)&v22 = 0.0;
  *(float *)&v24 = 0.0;
  *(float *)&v23 = 0.0;
  *(float *)&v25 = 0.0;
  v21 = 0;
  if ( !a2 )
    sub_4AA390(2, aNullGizmonameP);
  strcpy(String, a2);
  _strupr(String);
  ++*(_DWORD *)(this + 476);
  v4 = (const char **)sub_4AA6E0(String);
  if ( !v4 )
  {
    sprintf(Buffer, "undefined gizmo type %s", String);
    sub_4AA390(1, Buffer);
    sub_4A8520((_DWORD *)this);
    return 0;
  }
  v4[12] = *(const char **)(this + 492);
  v4[38] = *(const char **)(this + 496);
  v4[39] = *(const char **)(this + 500);
  while ( sub_4A84A0((_DWORD *)this) )
  {
    if ( strstr(Str, asc_608AB4) )
      break;
    if ( sub_577E50(byte_7656E8, aName_0, (int)String1) )
    {
      if ( *(_BYTE *)(this + 482) && *(_DWORD *)(this + 484) < 4u )
        sub_4AA510(String1);
      sub_4B1560(String1);
      continue;
    }
    if ( sub_578220(aPosWH, (int)&v22, (int)&v24, (int)&v23, (int)&v25, 0, 0, 0, 0) )
    {
      sub_4B13F0(
        (__int64)*(float *)&v24,
        (__int64)(*(float *)&v25 + *(float *)&v24),
        (__int64)*(float *)&v22,
        (__int64)(*(float *)&v23 + *(float *)&v22));
      v3 = 1;
    }
    else if ( sub_578220(aPosition, (int)&v23, (int)&v22, 0, 0, 0, 0, 0, 0) )
    {
      sub_4B1460((__int64)*(float *)&v23, (__int64)*(float *)&v22);
    }
    else if ( sub_578220(aWidthHeight, (int)&v22, (int)&v23, 0, 0, 0, 0, 0, 0) )
    {
      sub_4B14A0((__int64)*(float *)&v22, (__int64)*(float *)&v23);
      v3 = 1;
    }
    else if ( sub_578220(aPos2Offset, (int)&v22, (int)&v24, (int)&v23, (int)&v25, 0, 0, 0, 0) )
    {
      sub_4B15D0((__int64)*(float *)&v22, (__int64)*(float *)&v24);
      sub_4B15D0((__int64)*(float *)&v23, (__int64)*(float *)&v25);
      v21 = 1;
    }
    else if ( sub_578220(aOffset, (int)&v22, (int)&v23, 0, 0, 0, 0, 0, 0) )
    {
      sub_4B15D0((__int64)*(float *)&v22, (__int64)*(float *)&v23);
    }
    else
    {
      if ( sub_577E50(byte_7656E8, aCaption1, (int)Buffer)
        || sub_577E50(byte_7656E8, aTooltip, (int)Buffer)
        || sub_577E50(byte_7656E8, aTooltip2, (int)Buffer)
        || sub_577E50(byte_7656E8, aTooltip3, (int)Buffer) )
      {
        goto LABEL_42;
      }
      if ( sub_578110(aTooltipbgcolor, (int)&v28, (int)&v26, (int)&v27, (int)&v29) )
      {
        v4[52] = (const char *)(v29 | ((v27 | ((v26 | (v28 << 8)) << 8)) << 8));
      }
      else if ( sub_577E50(byte_7656E8, aTooltipbgmap, (int)Buffer) )
      {
        if ( _strcmpi(Buffer, aNone) )
          goto LABEL_42;
        sub_578600(&byte_629120);
      }
      else if ( sub_578110(aTooltiptextjus, (int)&v30, 0, 0, 0) )
      {
        v4[55] = (const char *)v30;
      }
      else
      {
        if ( sub_577E50(byte_7656E8, aTooltipfont, (int)Buffer) )
          goto LABEL_42;
        if ( sub_578220(aTooltipfontsca, (int)&v32, (int)&v31, 0, 0, 0, 0, 0, 0) )
        {
          v4[58] = (const char *)v32;
          v4[59] = (const char *)v31;
        }
        else
        {
          if ( !sub_578110(aTooltipfontcol, (int)&v28, (int)&v26, (int)&v27, (int)&v29) )
          {
            if ( !sub_577E50(byte_7656E8, aCaption2, (int)Buffer) && !sub_577E50(byte_7656E8, aCaption3, (int)Buffer) )
            {
              if ( sub_577E50(byte_7656E8, aChild, (int)String1) )
              {
                v6 = (_DWORD *)sub_4A8E80(String1);
                if ( v6 )
                  sub_49CA40(v4, v6, 0);
              }
              else if ( sub_577E50(byte_7656E8, aActions, (int)String1) )
              {
                sub_4A9DB0((int)v4, String1);
              }
              else if ( sub_577E50(byte_7656E8, aAttributeset, (int)String1) )
              {
                v7 = sub_4B1220(String1);
                v4[61] = (const char *)v7;
                if ( v7 )
                {
                  LOBYTE(v7) = v21 == 0;
                  LOBYTE(v8) = v3 == 0;
                  sub_49C8A0(v8, v7);
                }
              }
              else if ( sub_577E50(byte_7656E8, aFriendgizmo, (int)Buffer) )
              {
                sub_49D070(v4, (int)Buffer);
              }
              else if ( sub_579060(Str, aCustomdata) )
              {
                (*((void (__thiscall **)(const char **, int))*v4 + 7))(v4, this);
              }
              continue;
            }
LABEL_42:
            sub_578600(Buffer);
            continue;
          }
          v4[60] = (const char *)(v29 | ((v27 | ((v26 | (v28 << 8)) << 8)) << 8));
        }
      }
    }
  }
  v9 = v4[40];
  v10 = v4 + 40;
  if ( !v9 )
    v9 = &byte_629120;
  if ( strlen(v9) )
  {
    v11 = *v10;
    if ( !*v10 )
      v11 = &byte_629120;
    if ( !sub_41F230(dword_62A170, v11, Buffer) )
      sub_578600(Buffer);
  }
  v12 = v4[46];
  v13 = v4 + 46;
  if ( !v12 )
    v12 = &byte_629120;
  if ( strlen(v12) )
  {
    v14 = *v13;
    if ( !*v13 )
      v14 = &byte_629120;
    if ( !sub_41F230(dword_62A170, v14, Buffer) )
      sub_578600(Buffer);
  }
  v15 = v4[48];
  v16 = v4 + 48;
  if ( !v15 )
    v15 = &byte_629120;
  if ( strlen(v15) )
  {
    v17 = *v16;
    if ( !*v16 )
      v17 = &byte_629120;
    if ( !sub_41F230(dword_62A170, v17, Buffer) )
      sub_578600(Buffer);
  }
  v18 = v4[50];
  v19 = v4 + 50;
  if ( !v18 )
    v18 = &byte_629120;
  if ( strlen(v18) )
  {
    v20 = *v19;
    if ( !*v19 )
      v20 = &byte_629120;
    if ( !sub_41F230(dword_62A170, v20, Buffer) )
      sub_578600(Buffer);
  }
  sub_49D450(v4);
  if ( v4[4] - v4[3] <= 0 || v4[4] - v4[3] + 1 <= 0 || v4[2] - v4[1] <= 0 || v4[2] - v4[1] + 1 <= 0 )
    sub_4B14A0(100, 100);
  --*(_DWORD *)(this + 476);
  return v4;
}
