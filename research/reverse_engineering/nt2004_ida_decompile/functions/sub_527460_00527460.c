int __stdcall sub_527460(const char *a1, char a2)
{
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int v5; // esi
  int v7; // [esp+8h] [ebp-208h] BYREF
  bool v8; // [esp+Fh] [ebp-201h]
  char Buffer[512]; // [esp+10h] [ebp-200h] BYREF

  v2 = 1;
  v7 = 0;
  v3 = sub_405C90();
  sub_5A9070(&v7, a1, 1, v3[36]);
  if ( v7
    || (strcpy(Buffer, a1),
        sub_41E760(dword_62A060, Buffer, 512),
        v4 = sub_405C90(),
        sub_5A9070(&v7, Buffer, 1, v4[36]),
        v7) )
  {
    v2 = 0;
    sub_451B70();
    v8 = sub_4EF8E0();
    if ( v8 )
      sub_4EF900();
    v5 = sub_4AB450(*(_DWORD *)(v7 + 268), *(_DWORD *)(v7 + 272));
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    sub_4AB380();
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    if ( !sub_5A8910(v5, 0, 0, 192) )
    {
      while ( 1 )
      {
        sub_4AB380();
        sub_455D30((int)&ppvOut, 0.050000001);
        if ( a2 )
        {
          if ( (dword_761FF8 & 1) != 0 && dword_762A04 > 0 )
            break;
        }
        sub_4BB880();
        if ( sub_5A8910(v5, 0, 0, 192) )
          goto LABEL_12;
      }
      sub_455D30((int)&ppvOut, 0.050000001);
    }
LABEL_12:
    sub_4D20D0(2, 0, 1048576000, 1);
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    sub_4AB380();
    sub_5A0010(0.0, 0.0, 1.0, 1.0, 0);
    sub_4AB380();
    sub_4D20D0(0, 2, 1048576000, 1);
    sub_5A9130(v7);
    sub_4AB3C0();
    if ( v8 )
      sub_4EF920();
    sub_451B50();
  }
  return v2;
}
