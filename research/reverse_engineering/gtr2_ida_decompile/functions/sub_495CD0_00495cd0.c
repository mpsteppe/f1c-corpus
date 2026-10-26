void __thiscall sub_495CD0(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  int v8; // esi
  const CHAR *v9; // eax
  const CHAR *v10; // eax
  const CHAR *v11; // eax
  bool v12; // zf
  int v13; // ecx
  int v14; // eax
  const char *v15; // eax
  const char *v16; // esi
  const CHAR *v17; // eax
  const CHAR *v18; // eax
  int v19; // esi
  const CHAR *v20; // eax

  v4 = this[149];
  switch ( v4 )
  {
    case 790:
      v11 = *(const CHAR **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v11 = WindowName;
      sub_615860(v11);
      v10 = dword_B7235C;
      if ( !dword_B7235C )
        v10 = WindowName;
      goto LABEL_10;
    case 791:
    case 792:
      v12 = v4 == 791;
      v13 = this[12];
      if ( v12 )
        v14 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v13 + 28))(v13, 65);
      else
        v14 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v13 + 28))(v13, 66);
      if ( v14 )
      {
        v15 = (const char *)sub_4CE1C0(v14);
        v16 = v15;
        if ( v15 )
        {
          if ( strlen(v15) )
          {
            v17 = *(const CHAR **)dword_91CA70;
            if ( !*(_DWORD *)dword_91CA70 )
              v17 = WindowName;
            sub_615860(v17);
            sub_615A50(v16);
          }
        }
      }
      break;
    case 793:
    case 794:
    case 795:
      v18 = dword_B6F708;
      if ( !dword_B6F708 )
        v18 = WindowName;
      sub_615860(v18);
      sub_40D7E0(WindowName);
      v19 = this[149];
      if ( v19 == 793 )
      {
        sub_615A50("_tech1");
      }
      else if ( v19 == 794 )
      {
        sub_615A50("_tech2");
      }
      else
      {
        sub_615A50("_graph");
      }
      break;
    case 862:
      v5 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 28))(this[12], 58);
      if ( v5 )
      {
        v6 = (const char *)sub_4CE1C0(v5);
        v7 = v6;
        if ( v6 )
        {
          if ( strlen(v6) )
          {
            sub_42A7F0();
            sub_408500(WindowName);
            sub_615A50(v7);
          }
        }
      }
      break;
    case 863:
      v8 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 28))(this[12], 57);
      if ( v8 )
      {
        v9 = *(const CHAR **)dword_91CAC8;
        if ( !*(_DWORD *)dword_91CAC8 )
          v9 = WindowName;
        sub_615860(v9);
        v10 = (const CHAR *)sub_4CE1C0(v8);
        if ( v10 )
LABEL_10:
          sub_615A50(v10);
      }
      break;
    default:
      break;
  }
  v20 = &WindowName[strlen(WindowName)];
  if ( v20 > WindowName )
  {
    while ( *v20 != 46 )
    {
      if ( --v20 <= WindowName )
        goto LABEL_37;
    }
    *v20 = 0;
  }
LABEL_37:
  sub_615A50(".txt");
  sub_630FE0(a2, WindowName, a3);
  *(_BYTE *)(a2 + a3) = 0;
}
