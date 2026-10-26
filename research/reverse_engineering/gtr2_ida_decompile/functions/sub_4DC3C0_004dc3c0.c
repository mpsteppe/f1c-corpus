int __thiscall sub_4DC3C0(int this, const char *a2)
{
  _DWORD *v3; // edi
  int v5; // eax
  float v6; // [esp+20h] [ebp-134h]
  int v7; // [esp+24h] [ebp-130h] BYREF
  int v8; // [esp+28h] [ebp-12Ch] BYREF
  int v9; // [esp+2Ch] [ebp-128h] BYREF
  int v10; // [esp+30h] [ebp-124h] BYREF
  int v11; // [esp+34h] [ebp-120h] BYREF
  int v12; // [esp+38h] [ebp-11Ch] BYREF
  int v13[2]; // [esp+3Ch] [ebp-118h] BYREF
  int v14; // [esp+44h] [ebp-110h] BYREF
  int v15; // [esp+48h] [ebp-10Ch] BYREF
  int v16; // [esp+4Ch] [ebp-108h] BYREF
  int v17; // [esp+50h] [ebp-104h] BYREF
  char String1[128]; // [esp+54h] [ebp-100h] BYREF
  char String[125]; // [esp+D4h] [ebp-80h] BYREF
  __int16 v20; // [esp+151h] [ebp-3h]
  char v21; // [esp+153h] [ebp-1h]

  memset(String1, 0, sizeof(String1));
  memset(String, 0, sizeof(String));
  v20 = 0;
  v21 = 0;
  *(float *)&v7 = 0.0;
  *(float *)&v9 = 0.0;
  *(float *)&v8 = 0.0;
  *(float *)&v10 = 0.0;
  HIBYTE(v6) = 0;
  if ( !a2 )
    sub_4DBB40((_DWORD *)this, 2, "Null gizmoName ptr passed to ::ReadGizmoObject");
  strcpy(String, a2);
  _strupr(String);
  ++*(_DWORD *)(this + 760);
  v3 = (_DWORD *)sub_4DBE00((_DWORD **)this, String);
  if ( !v3 )
  {
    sprintf(::String1, "undefined gizmo type %s", String);
    sub_4DAD10((_DWORD *)this);
    return 0;
  }
  v3[12] = *(_DWORD *)(this + 776);
  v3[38] = *(_DWORD *)(this + 780);
  v3[39] = *(_DWORD *)(this + 784);
  while ( sub_4DAC90((_DWORD *)this) )
  {
    if ( strstr(byte_75AF70, "}") )
      return off_16C96B0(a2);
    if ( sub_6131C0("NAME", (int)String1) )
    {
      if ( *(_BYTE *)(this + 766) )
      {
        if ( *(_DWORD *)(this + 768) < 4u )
          sub_4DBCD0(this, String1);
      }
      sub_4E2B70(v3, String1);
      continue;
    }
    if ( sub_6134B0("POS-W-H", (int)&v7, (int)&v9, (int)&v8, (int)&v10, 0, 0, 0, 0) )
    {
      sub_4E2A80(
        (unsigned __int64)*(float *)&v9,
        (unsigned __int64)(*(float *)&v10 + *(float *)&v9),
        (unsigned __int64)*(float *)&v7,
        (unsigned __int64)(*(float *)&v8 + *(float *)&v7));
    }
    else if ( sub_6134B0("POSITION", (int)&v8, (int)&v7, 0, 0, 0, 0, 0, 0) )
    {
      sub_4E2AF0((unsigned __int64)*(float *)&v8, (unsigned __int64)*(float *)&v7);
    }
    else if ( sub_6134B0("WIDTH_HEIGHT", (int)&v7, (int)&v8, 0, 0, 0, 0, 0, 0) )
    {
      sub_4E2B30((unsigned __int64)*(float *)&v7, (unsigned __int64)*(float *)&v8);
    }
    else if ( sub_6134B0("POS2-OFFSET", (int)&v7, (int)&v9, (int)&v8, (int)&v10, 0, 0, 0, 0) )
    {
      sub_4E3EE0(v3 + 28, (unsigned __int64)*(float *)&v7, (unsigned __int64)*(float *)&v9);
      sub_4E3EE0(v3 + 28, (unsigned __int64)v6, (unsigned __int64)*(float *)&v8);
    }
    else if ( sub_6134B0("OFFSET", (int)&v7, (int)&v8, 0, 0, 0, 0, 0, 0) )
    {
      sub_4E3EE0(v3 + 28, (unsigned __int64)*(float *)&v7, (unsigned __int64)*(float *)&v8);
    }
    else
    {
      if ( sub_6131C0("CAPTION1", (int)::String1)
        || sub_6131C0("TOOLTIP", (int)::String1)
        || sub_6131C0("TOOLTIP2", (int)::String1)
        || sub_6131C0("TOOLTIP3", (int)::String1) )
      {
        goto LABEL_42;
      }
      if ( sub_6133A0("ToolTipBGColorARGB", (int)&v12, (int)&v14, (int)&v11, (int)v13) )
      {
        v3[52] = v13[0] | ((v11 | ((v14 | (v12 << 8)) << 8)) << 8);
      }
      else if ( sub_6131C0("ToolTipBGMap", (int)::String1) )
      {
        if ( _stricmp(::String1, "none") )
          goto LABEL_42;
        sub_615860(WindowName);
      }
      else if ( sub_6133A0("ToolTipTextJustification", (int)&v16, 0, 0, 0) )
      {
        v3[55] = v16;
      }
      else
      {
        if ( sub_6131C0("ToolTipFont", (int)::String1) )
          goto LABEL_42;
        if ( sub_6134B0("ToolTipFontScale", (int)&v15, (int)&v17, 0, 0, 0, 0, 0, 0) )
        {
          v3[58] = v15;
          v3[59] = v17;
        }
        else
        {
          if ( !sub_6133A0("ToolTipFontColorARGB", (int)&v12, (int)&v14, (int)&v11, (int)v13) )
          {
            if ( !sub_6131C0("CAPTION2", (int)::String1) && !sub_6131C0("CAPTION3", (int)::String1) )
            {
              if ( sub_6131C0("CHILD", (int)String1) )
              {
                if ( sub_4DC3C0(String1) )
                  sub_4CD360();
              }
              else if ( sub_6131C0("ACTIONS", (int)String1) )
              {
                sub_4DADA0((_DWORD *)this, (int)v3, String1);
              }
              else if ( sub_6131C0("ATTRIBUTESET", (int)String1) )
              {
                v5 = sub_4E3AF0(*(_DWORD *)(this + 776) + 1380, String1);
                v3[61] = v5;
                if ( v5 )
                  sub_4CD2A0();
              }
              else if ( sub_6131C0("FRIENDGIZMO", (int)::String1) )
              {
                sub_4D3C70();
              }
              else if ( sub_616480(byte_75AF70, "CUSTOMDATA") )
              {
                (*(void (__thiscall **)(_DWORD *, int))(*v3 + 28))(v3, this);
              }
              continue;
            }
LABEL_42:
            sub_615860(::String1);
            continue;
          }
          v3[60] = v13[0] | ((v11 | ((v14 | (v12 << 8)) << 8)) << 8);
        }
      }
    }
  }
  return off_16C96B0(a2);
}
