int __thiscall sub_5D9070(void *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  void *v5; // eax
  void *v6; // eax
  void *v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  void *v13; // eax
  void *v14; // eax
  int v15; // eax

  dword_FB2318 = -1;
  dword_FB2750 = -1;
  byte_FB2740 = 1;
  byte_FB2754 = 1;
  byte_FB231C = 0;
  dword_FB272C = 0;
  dword_FB2760 = 0;
  byte_FB231D = 1;
  byte_FB230C = 0;
  dword_FB2738 = 0;
  dword_FB2728 = 0;
  dword_FB2734 = 0;
  dword_FB2720 = 0;
  dword_FB2730 = 0;
  dword_FB2724 = 0;
  dword_FB2314 = 0;
  dword_FB273C = 0;
  dword_FB2310 = 0;
  dword_FB2744 = 0;
  dword_FB2308 = 0;
  dword_FB274C = 0;
  v3 = operator new(0x48u);
  if ( v3 )
    v4 = sub_5D8BD0(v3);
  else
    v4 = 0;
  dword_FB27A8 = v4;
  if ( (*(_DWORD *)a2 & 4) == 0 )
    sub_5F5D60(this);
  if ( (*(_BYTE *)a2 & 8) == 0 )
  {
    v5 = operator new(0x340u);
    if ( v5 )
      v6 = (void *)sub_6056E0(v5);
    else
      v6 = 0;
    dword_FB2774 = v6;
    sub_6057A0(this);
  }
  if ( (*(_DWORD *)a2 & 1) != 0 )
  {
    v7 = operator new(0x2548u);
    if ( v7 )
    {
      v8 = (_DWORD *)sub_606840(v7);
      dword_FB27A4 = (int)v8;
      v9 = v8[1] | 0x40000000;
    }
    else
    {
      v8 = 0;
      dword_FB27A4 = 0;
      v9 = MEMORY[4] | 0x40000000;
    }
  }
  else
  {
    v10 = operator new(0x2600u);
    if ( v10 )
      v8 = (_DWORD *)sub_600FE0(v10);
    else
      v8 = 0;
    dword_FB40FC = v8;
    dword_FB27A4 = (int)v8;
    v9 = v8[1] & 0xBFFFFFFF;
  }
  v8[1] = v9;
  v11 = operator new(0x88u);
  if ( v11 )
    v12 = (void *)sub_5E70C0(v11);
  else
    v12 = 0;
  dword_FB2790 = v12;
  v13 = operator new(0x88u);
  if ( v13 )
    v14 = (void *)sub_5E70C0(v13);
  else
    v14 = 0;
  dword_FB2794 = v14;
  *(_BYTE *)(dword_FB27A4 + 124) = (*(_BYTE *)a2 & 0x10) == 0;
  if ( strcmp((const char *)(a2 + 288), WindowName) )
    sub_5D8F50((char *)dword_FB27A4, (const char *)(a2 + 288));
  if ( strcmp((const char *)(a2 + 32), WindowName) )
    sub_5D8FB0((char *)dword_FB27A4, (const char *)(a2 + 32));
  if ( (*(_BYTE *)a2 & 2) != 0 )
    byte_FB231D = 0;
  if ( (*(_DWORD *)a2 & 0x20) != 0 )
  {
    *(_DWORD *)(dword_FB27A4 + 8980) = 2;
    *(_DWORD *)(dword_FB27A4 + 8984) = 1056964608;
    *(_DWORD *)(dword_FB27A4 + 8988) = 1056964608;
  }
  else if ( (*(_DWORD *)a2 & 0x40) != 0 )
  {
    *(_DWORD *)(dword_FB27A4 + 8980) = 3;
    *(_DWORD *)(dword_FB27A4 + 8984) = 1051374440;
    *(_DWORD *)(dword_FB27A4 + 8988) = 1051374440;
    (*(void (__thiscall **)(int, int, int, int, int))(*(_DWORD *)dword_FB27A4 + 132))(
      dword_FB27A4,
      -1,
      -1,
      16000,
      12000);
    goto LABEL_36;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 132))(dword_FB27A4);
LABEL_36:
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 92))(dword_FB27A4);
  sub_5FB900(0, *(_DWORD *)a2);
  if ( !sub_5E8FA0("GHOSTHOOK", &dword_FB27AC) )
  {
    sub_5E9620(5, 6);
    sub_5E8460(2, 63);
    v15 = sub_5E8830(0);
    sub_5E8870(v15 | 0x800, 0);
  }
  return 0;
}
