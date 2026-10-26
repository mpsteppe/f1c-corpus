int __thiscall sub_54C880(int this, char a2)
{
  int v3; // ecx
  char v5; // [esp+10h] [ebp-278h]
  _BYTE v6[96]; // [esp+18h] [ebp-270h] BYREF
  char v7[253]; // [esp+78h] [ebp-210h] BYREF
  __int16 v8; // [esp+175h] [ebp-113h]
  char FileName[260]; // [esp+178h] [ebp-110h] BYREF
  int v10; // [esp+284h] [ebp-4h]

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\StateMan.cpp", 369) )
    sub_561210((int)byte_FAE910, "StateMan::ReadState()", v5);
  memset(v7, 0, sizeof(v7));
  v8 = 0;
  sub_54B870();
  if ( !(unsigned __int8)sub_54BE10((void *)this) )
    return 2;
  sub_613B30(v6);
  v10 = 0;
  sub_614460(v7, 0);
  sub_613CE0(this + 3978616 * *(_DWORD *)(this + 3978628), 3978616);
  sub_613C30(v6);
  v3 = 3978616 * *(_DWORD *)(this + 3978628) + this;
  if ( !*(_BYTE *)(v3 + 4) )
  {
    v10 = -1;
    sub_614140(v6);
    return 2;
  }
  if ( *(float *)v3 == *(float *)&dword_B64140 )
  {
    if ( a2 )
    {
      sub_54BFF0(v3 + 156);
      sub_54C3C0();
      if ( *(_DWORD *)dword_B72314 == 4 )
      {
        sub_501B50();
        sub_54B870();
        sub_40D7E0(v7);
        sub_632041(v7, 255, "%s%s", v7, "Chp.sve");
        sub_617680(FileName);
        sub_617D00(v7, FileName);
        sub_50FC40();
      }
      *(_BYTE *)(this + 3978616) = 1;
    }
    v10 = -1;
    sub_614140(v6);
    return 0;
  }
  else
  {
    v10 = -1;
    sub_614140(v6);
    return 1;
  }
}
