int __thiscall sub_4DD1F0(int this, const char *a2)
{
  int v3; // ebx
  void *v4; // eax
  int v5; // eax
  void *v6; // eax
  int v7; // eax
  int *v8; // eax
  char v9; // cl
  bool v10; // zf
  int *v11; // eax
  char v12; // cl
  int v13; // eax
  int v15; // [esp+Ch] [ebp-94h] BYREF
  void *v16; // [esp+10h] [ebp-90h]
  char String1[125]; // [esp+14h] [ebp-8Ch] BYREF
  __int16 v18; // [esp+91h] [ebp-Fh]
  char v19; // [esp+93h] [ebp-Dh]
  int v20; // [esp+98h] [ebp-8h]
  int v21; // [esp+9Ch] [ebp-4h]

  v3 = 0;
  memset(String1, 0, sizeof(String1));
  v18 = 0;
  v19 = 0;
  if ( a2 )
  {
    strcpy(String1, a2);
    _strupr(String1);
  }
  ++*(_DWORD *)(this + 760);
  if ( !_stricmp(String1, "NORMAL") )
  {
    v4 = operator new(0xB0u);
    v16 = v4;
    v21 = 0;
    if ( v4 )
    {
      v5 = sub_4DF6C0(v4, 0);
      v20 = -1;
      v3 = v5;
      goto LABEL_11;
    }
    goto LABEL_6;
  }
  if ( !_stricmp(String1, "MODAL") )
  {
    v6 = operator new(0xB0u);
    v16 = v6;
    v21 = 1;
    if ( !v6 )
    {
LABEL_6:
      v21 = -1;
      v3 = 0;
      goto LABEL_11;
    }
    v7 = sub_4DF6C0(v6, 1);
    v20 = -1;
    v3 = v7;
  }
  else
  {
    sprintf(::String1, "undefined layer type %s", a2);
    sub_4DBB40((_DWORD *)this, 3, ::String1);
  }
LABEL_11:
  *(_DWORD *)(this + 780) = v3;
  sub_4E2A80(0, 599, 0, 799);
  sub_4DFF60(*(_DWORD *)(this + 776), v3);
  while ( sub_4DAC90((_DWORD *)this) )
  {
    if ( strstr(byte_75AF70, "}") )
      break;
    if ( sub_6131C0("NAME", (int)&v15) )
    {
      if ( *(_BYTE *)(this + 766) && *(_DWORD *)(this + 768) < 4u )
        sub_4DBCD0(this, (const char *)&v15);
      sub_4E2B70(v3, &v15);
    }
    else
    {
      if ( sub_6131C0("SOUND_FOCUS", (int)&v15) )
      {
        v8 = &v15;
        do
        {
          v9 = *(_BYTE *)v8;
          *((_BYTE *)v8 + v3 - (_DWORD)&v15 + 96) = *(_BYTE *)v8;
          v8 = (int *)((char *)v8 + 1);
        }
        while ( v9 );
      }
      else
      {
        v10 = sub_6131C0("SOUND_LOSTFOCUS", (int)&v15) == 0;
        v11 = &v15;
        if ( v10 )
        {
          if ( sub_6131C0("GIZMO", (int)&v15) )
          {
            v13 = sub_4DC3C0(this, (const char *)&v15);
            if ( v13 )
              sub_4DFF90(*(_DWORD *)(this + 776), v13, *(_DWORD *)(this + 780));
          }
          else if ( sub_6131C0("PAGE", (int)&v15) )
          {
            sub_4DCE40(this);
          }
          continue;
        }
        do
        {
          v12 = *(_BYTE *)v11;
          *((_BYTE *)v11 + v3 - (_DWORD)&v15 + 136) = *(_BYTE *)v11;
          v11 = (int *)((char *)v11 + 1);
        }
        while ( v12 );
      }
      sub_4E03A0(&v15);
    }
  }
  --*(_DWORD *)(this + 760);
  *(_DWORD *)(this + 780) = 0;
  return 0;
}
