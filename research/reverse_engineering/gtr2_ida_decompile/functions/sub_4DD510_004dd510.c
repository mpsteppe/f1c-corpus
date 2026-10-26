int __thiscall sub_4DD510(int this)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-94h]
  char v8[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v9; // [esp+8Dh] [ebp-3h]
  char v10; // [esp+8Fh] [ebp-1h]

  if ( *(_DWORD *)(this + 776) )
  {
    if ( *(_BYTE *)(this + 766) )
      sub_4DBCD0(this, "Options Screens Hierarchy\n");
    while ( sub_4DAC90((_DWORD *)this) )
    {
      memset(v8, 0, sizeof(v8));
      v9 = 0;
      v10 = 0;
      if ( sub_6131C0("OPTIONSFONT", (int)v8) )
      {
        sub_4DCC40((_DWORD *)this, v8);
      }
      else if ( sub_6131C0("ATTRIBUTESET", (int)v8) )
      {
        sub_4DB690((_DWORD *)this, v8);
      }
      else if ( sub_6131C0("LAYER", (int)v8) )
      {
        sub_4DD1F0(this, v8);
      }
      else if ( sub_6131C0("GIZMO", (int)v8) )
      {
        v3 = sub_4DC3C0(this, v8);
        if ( v3 )
          sub_4DE270(*(_DWORD *)(this + 776), v3, 0);
      }
      else if ( sub_6131C0("DOPAGE", (int)v8) )
      {
        v4 = sub_4DEE80(*(_DWORD *)(this + 776), "MAIN MENU");
        sub_4E1670(v4, 1, 0);
      }
      else if ( sub_6131C0("LOADINGSCREENPAGE", (int)v8) )
      {
        v5 = sub_4DEE80(*(_DWORD *)(this + 776), v8);
        if ( v5 )
          sub_4DE380(v5);
      }
      else if ( sub_6131C0("SYSTEMFONT", (int)v8) )
      {
        sub_4E0930(*(_DWORD *)(this + 776), v8);
      }
      else if ( sub_6131C0("DISABLE_GIZMO", (int)v8) )
      {
        v6 = sub_4DEF00(*(_DWORD *)(this + 776), v8);
        if ( v6 )
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 36))(v6, 1, v7);
      }
    }
    return 0;
  }
  else
  {
    strcpy(v8, "Invalid Options Pointer in Options_OSC_Reader::ReadOptionsObject()");
    sub_4DBB40((_DWORD *)this, 3, v8);
    return 0;
  }
}
