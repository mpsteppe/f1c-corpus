// f1c  0x004c0cc0  size=234
char __thiscall sub_4C0CC0(int this, _DWORD *a2, int a3)
{
  int i; // ebx
  _BYTE v6[32]; // [esp+8h] [ebp-20h] BYREF

  if ( *a2 )
  {
    if ( a3 )
    {
      sub_566CF0(a3);
      sub_566CF0(&word_5C30B4);
    }
    sub_566C30(a2, aSeasonstatusD);
    sub_566C30(a2, aRacesessionD);
    sub_566C30(a2, aRaceoverD);
    sub_566C30(a2, aCurrentraceD);
    sub_4C0690((int *)(this + 44908), a2, (int)aPlayer);
    for ( i = 0; i < 103; ++i )
    {
      if ( *(_BYTE *)(this + 432) )
      {
        sub_58815F(v6, "%s%2.2d]", aOpponent, i);
        sub_4C0690((int *)this, a2, (int)v6);
      }
      this += 436;
    }
    sub_566C30(a2, &word_5C30B4);
  }
  return 0;
}
