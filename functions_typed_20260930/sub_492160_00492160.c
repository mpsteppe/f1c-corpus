int __thiscall sub_492160(int this)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  char v11[4]; // [esp+Ch] [ebp-84h] BYREF
  char v12[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v13; // [esp+8Dh] [ebp-3h]
  char v14; // [esp+8Fh] [ebp-1h]

  if ( *(_DWORD *)(this + 420) )
  {
    if ( *(_BYTE *)(this + 410) )
      ResourcePathBuilder(aOptionsScreens);
    while ( sub_491FB0((_DWORD *)this) )
    {
      v12[0] = byte_5EA438[0];
      memset(&v12[1], 0, 0x7Cu);
      v13 = 0;
      v14 = 0;
      if ( sub_5654A0(aAttributeset, v12) )
      {
        sub_493060(v12);
      }
      else if ( sub_5654A0(aLayer, v12) )
      {
        sub_492460(v12);
      }
      else if ( sub_5654A0(aGizmo, v12) )
      {
        v3 = sub_492A40(v12);
        if ( v3 )
          sub_4975D0(v3, 0);
      }
      else if ( sub_5654A0(aDopage, v12) )
      {
        v4 = UIListSearchByName_76c0(v12);
        UtilityFunction_7890(v4, -1);
      }
      else if ( sub_5654A0(aLoadingscreenp, v12) )
      {
        v5 = UIListSearchByName_76c0(v12);
        if ( v5 )
          ConditionalSetter0x30(v5);
      }
      else if ( sub_5654A0(aSystemfont, v12) )
      {
        sub_498440(v12);
      }
      else
      {
        v6 = sub_5654A0(aTooltipfont, v12) == 0;
        v7 = *(_DWORD *)(this + 420);
        if ( v6 )
        {
          if ( !sub_565760(aTooltipColorFi, v7 + 180, 0, 0, 0)
            && !sub_565760(aTooltipColorEd, *(_DWORD *)(this + 420) + 184, 0, 0, 0) )
          {
            if ( sub_5654A0(aSetSymbol, v12) )
            {
              strcpy(v11, ":\t");
              v8 = sub_5897CA(v12, v11);
              v9 = sub_5897CA(0, v11);
              if ( v8 && v9 )
                StringReverseCopyLookup(v8, v9);
            }
            else if ( sub_5654A0(aDisableGizmo, v12) )
            {
              v10 = RenderingContextSetup(v12);
              if ( v10 )
                (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 56))(v10, 1);
            }
          }
        }
        else
        {
          strcpy((char *)(v7 + 5432), v12);
        }
      }
    }
    return 0;
  }
  else
  {
    strcpy(v12, "Invalid Options Pointer in Options_OSC_Reader::ReadOptionsObject()");
    sub_493C80(3, v12);
    return 0;
  }
}

