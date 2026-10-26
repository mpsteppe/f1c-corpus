char __thiscall sub_478FC0(_DWORD *this, int ArgList)
{
  char *v2; // esi
  int v4; // edi
  int v5; // eax
  int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  const char *v9; // ebp
  const char **v10; // eax
  _DWORD *v11; // ebx
  const char *v12; // edi
  int v13; // eax
  const char **v14; // eax
  int v15; // edx
  int v16; // eax
  unsigned int v18; // kr00_4
  __int32 v19; // esi
  __int32 v20; // esi
  const char *v21; // [esp+8h] [ebp-98h] BYREF
  double v22; // [esp+Ch] [ebp-94h]
  int v23; // [esp+14h] [ebp-8Ch]
  int v24; // [esp+18h] [ebp-88h]
  int v25; // [esp+1Ch] [ebp-84h]
  char Buffer[128]; // [esp+20h] [ebp-80h] BYREF

  v2 = (char *)&unk_9204A0 + 22616 * ArgList;
  if ( *((_DWORD *)v2 + 3705) == -1 )
    return 0;
  v4 = (int)&v2[108 * *((_DWORD *)v2 + 5447) + 21568];
  v22 = COERCE_DOUBLE(__PAIR64__((unsigned int)sub_41D840(&byte_91CC38, "left the game."), v4));
  v21 = (char *)&unk_9204A0 + 22616 * ArgList;
  v18 = __readeflags();
  v19 = dword_16C6EF0 + 1584126465;
  __writeeflags(v18);
  v20 = _InterlockedExchange((volatile __int32 *)&v21, v19);
  sprintf(Buffer, v21);
  sub_4730C0((int **)&dword_B6CB98, Buffer, 3, (int)&byte_1020304, 1084227584);
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4709) )
  {
    v5 = *(_DWORD *)(v20 + 22468);
    v22 = dbl_FB1D18;
    sub_561210((int)byte_FAE910, "*** UNLOADING Slot (index %d) @ et=%8.4f", v5);
  }
  v6 = this[28332];
  if ( v6 == 2 || v6 == 1 )
  {
    v7 = v20 + 22084;
    v8 = strlen((const char *)(v20 + 22084));
    v9 = (const char *)(v8 + v20 + 22084);
    if ( v8 + v7 > v7 )
    {
      while ( *v9 != 92 )
      {
        if ( (unsigned int)--v9 <= v7 )
          goto LABEL_12;
      }
      ++v9;
    }
LABEL_12:
    v10 = (const char **)this[28333];
    v11 = this + 28333;
    v11[2] = v10;
    if ( v10 )
    {
      v12 = *v10;
      if ( *v10 )
      {
        while ( _stricmp(v12, v9) )
        {
          v13 = v11[2];
          if ( v13 )
            v11[2] = *(_DWORD *)(v13 + 4);
          v14 = (const char **)v11[2];
          if ( v14 )
          {
            v12 = *v14;
            if ( *v14 )
              continue;
          }
          goto LABEL_21;
        }
        sub_524660(v11, v12, 1);
      }
    }
  }
LABEL_21:
  if ( !*(_DWORD *)(v20 + 14820) )
  {
    sub_40DD50();
    sub_4E8410(&unk_B6E7A8, v23);
  }
  sub_53F7C0(v20);
  sub_53E6A0(v20, -1);
  sub_53F190(v20, 0, v24, v25);
  sub_573880(0.0);
  if ( *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) == ArgList )
  {
    v15 = *(&dword_91E088 + dword_91E080);
    if ( dword_923E84[5654 * *(_DWORD *)(v15 + 22468)] == -1 )
    {
      v16 = 0;
      if ( dword_757C10 > 0 )
      {
        while ( *(_DWORD *)(*(&dword_91E088 + v16) + 14820) == -1 )
        {
          if ( ++v16 >= dword_757C10 )
            goto LABEL_31;
        }
        dword_91E078 = v16;
        dword_91E07C = (char *)*(&dword_91E088 + v16);
      }
    }
    else
    {
      sub_42C8A0(*(_DWORD *)(v15 + 22468));
    }
  }
LABEL_31:
  if ( dword_B640C0 != 5 )
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4772) )
      sub_561210((int)byte_FAE910, "*** Unsetting Slot (index %d)", ArgList);
  }
  return 1;
}
