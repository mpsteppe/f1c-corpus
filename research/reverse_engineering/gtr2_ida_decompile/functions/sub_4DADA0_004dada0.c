int __thiscall sub_4DADA0(_DWORD *this, int a2, char *String1)
{
  _DWORD *v3; // esi
  void *v4; // eax
  _DWORD *v5; // eax
  int v6; // ecx
  void *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  void *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v18; // [esp+1Ch] [ebp-94h]
  int v19[34]; // [esp+24h] [ebp-8Ch] BYREF
  int v20; // [esp+ACh] [ebp-4h]

  v3 = this;
  memset(v19, 0, 128);
  if ( !a2 || !String1 )
    return -1;
  ++this[190];
  if ( sub_4DAC90(this) )
  {
    while ( 1 )
    {
      if ( strstr(byte_75AF70, "}") )
        goto LABEL_40;
      if ( sub_6131C0("DO_PAGE", (int)v19) )
      {
        v4 = operator new(0x1Cu);
        v20 = 0;
        if ( v4 )
        {
          v5 = (_DWORD *)sub_4E3B40(v4);
          *v5 = 1;
          v6 = (int)(v5 + 1);
        }
        else
        {
          MEMORY[0] = 1;
          v6 = 4;
        }
        return off_16C9484(v6, a2, String1);
      }
      if ( sub_6131C0("DO_LAYER", (int)v19) )
      {
        v7 = operator new(0x1Cu);
        v20 = 1;
        if ( v7 )
        {
          v8 = (_DWORD *)sub_4E3B40(v7);
          *v8 = 2;
          v6 = (int)(v8 + 1);
        }
        else
        {
          MEMORY[0] = 2;
          v6 = 4;
        }
        return off_16C9484(v6, a2, String1);
      }
      if ( sub_6131C0("DROP_POPUPS", (int)v19) )
      {
        v9 = operator new(0x1Cu);
        v18 = v9;
        v20 = 2;
        if ( v9 )
        {
          v10 = (_DWORD *)sub_4E3B40(v9);
          v20 = -1;
          *v10 = 4;
        }
        else
        {
          v20 = -1;
          MEMORY[0] = 4;
        }
        goto LABEL_31;
      }
      if ( sub_6131C0("DO_LAST_PAGE", (int)v19) )
        break;
      if ( sub_6131C0("EXIT_GAME", (int)v19) )
      {
        v13 = operator new(0x1Cu);
        v18 = v13;
        v20 = 4;
        if ( v13 )
        {
          v14 = (_DWORD *)sub_4E3B40(v13);
          v20 = -1;
          *v14 = 5;
        }
        else
        {
          v20 = -1;
          MEMORY[0] = 5;
        }
LABEL_31:
        if ( !_stricmp(String1, "CLICK") )
        {
          sub_4CD470();
        }
        else if ( !_stricmp(String1, "RELEASE") )
        {
          sub_4CD4B0();
        }
        else if ( !_stricmp(String1, "FOCUS") )
        {
          sub_4CD4F0();
        }
        else if ( !_stricmp(String1, "LOSTFOCUS") )
        {
          sub_4CD530();
        }
        goto LABEL_39;
      }
      if ( sub_6131C0("SIMULATECLICK", (int)v19) )
      {
        v15 = operator new(0x1Cu);
        v20 = 5;
        if ( v15 )
          v16 = (_DWORD *)sub_4E3B40(v15);
        else
          v16 = 0;
        *v16 = 6;
        v6 = (int)(v16 + 3);
        return off_16C9484(v6, a2, String1);
      }
LABEL_39:
      v3 = v18;
      if ( !sub_4DAC90(v18) )
        goto LABEL_40;
    }
    v11 = operator new(0x1Cu);
    v18 = v11;
    v20 = 3;
    if ( v11 )
    {
      v12 = (_DWORD *)sub_4E3B40(v11);
      v20 = -1;
      *v12 = 7;
    }
    else
    {
      v20 = -1;
      MEMORY[0] = 7;
    }
    goto LABEL_31;
  }
LABEL_40:
  --v3[190];
  return 0;
}
