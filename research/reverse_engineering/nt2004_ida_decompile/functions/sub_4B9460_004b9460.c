int sub_4B9460()
{
  bool v0; // bl
  _DWORD *v1; // eax
  _DWORD *v2; // ecx
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  signed int i; // esi
  int v7; // ecx
  char v8; // al
  int v9; // ecx

  sub_5AB0A0(dword_7DA9B8);
  sub_451B50();
  sub_465D20(dword_764D70);
  v0 = sub_42DBC0();
  if ( v0 )
  {
    sub_51F3D0(0, 8);
    sub_51BC20(0, 0);
  }
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 1:
    case 2:
    case 3:
      if ( dword_75CBB0 == 7 )
      {
        if ( !*(_DWORD *)(dword_75AACC + 20892) )
          sub_4DCC00(1, 0);
        if ( dword_7655CC )
        {
          v1 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 9);
          if ( v1 )
            sub_478EA0(v1);
          v2 = (_DWORD *)dword_7655CC;
          goto LABEL_24;
        }
      }
      goto LABEL_25;
    case 4:
      goto LABEL_13;
    case 5:
      if ( dword_75CBB0 == 7 )
      {
        if ( !*(_DWORD *)(dword_75AACC + 20892) )
          sub_4DCC00(1, 1);
        v2 = (_DWORD *)dword_7655CC;
        if ( dword_7655CC )
          goto LABEL_24;
      }
      goto LABEL_25;
    case 8:
      v3 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
      if ( v3 )
        sub_40F2B0(v3);
LABEL_13:
      if ( dword_75CBB0 != 7 )
        goto LABEL_25;
      if ( !*(_DWORD *)(dword_75AACC + 20892) )
        sub_4DCC00(1, 0);
      if ( !dword_7655CC )
        goto LABEL_25;
      v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 9);
      v5 = (_DWORD *)v4;
      if ( v4 )
      {
        sub_478850(v4, 0);
        sub_478EA0(v5);
      }
      v2 = (_DWORD *)dword_7655CC;
LABEL_24:
      sub_4AD720(v2, aPostRaceMonito, 1);
LABEL_25:
      sub_4BA5F0(1);
      if ( dword_7655CC )
        sub_4AD790((_DWORD *)dword_7655CC);
      sub_4FE670(&dword_7D78FC);
      if ( v0 )
      {
        sub_51C180(dword_75AACC + 84);
        sub_4EE160(0.0);
      }
      sub_4F01C0(&byte_7D6B78);
      sub_4EF1B0(&unk_7D6BA0);
      if ( v0 )
        sub_51F3D0(0, 8);
      sub_5074D0(0.0);
      sub_40C430(&dword_6291CC, 0);
      for ( i = 0; i < (int)NumOfElements; ++i )
      {
        v7 = dword_75AAD0[i];
        v8 = *(_BYTE *)(v7 + 2048);
        v9 = v7 + 1892;
        if ( !v8 )
          sub_50D370(v9);
      }
      sub_419110(byte_6292D0);
      return 0;
    default:
      goto LABEL_25;
  }
}
