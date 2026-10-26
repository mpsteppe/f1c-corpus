void sub_5206C0()
{
  int i; // esi
  char *v1; // eax

  for ( i = 0; i < ((dword_B698E8 & 1) != 0 ? dword_B6A2F4 : 0); ++i )
  {
    if ( word_B6A2F8[i] == 88
      && !sub_5E6FD0(0, 0, *(_DWORD *)(dword_FB27A4 + 9408), *(_DWORD *)(dword_FB27A4 + 9412), 0) )
    {
      v1 = sub_41D840(&byte_91CC38, "Screen Saved");
      sub_4730C0((int **)&dword_B6CB98, v1, 3, (int)&byte_1020304, 1084227584);
    }
  }
  nullsub_7(&unk_FB20EC);
  if ( *(_DWORD *)dword_B72314 != 6 && !(unsigned __int8)sub_521050(&dword_BE120C) )
    sub_5203C0();
  sub_46FD60(flt_B6C560);
  sub_5FC390(dword_FB1D04, 0);
  sub_46ECD0(flt_B6C560, 0.0);
}
