int __thiscall sub_4B7B50(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax

  sub_4CE8F0();
  sub_409FB0(this + 13);
  sub_4D3CF0("CURRENT", -1);
  sub_4D3CF0("TEST DAY", -1);
  sub_4D3CF0("QUICKRACE", -1);
  sub_4D3CF0("RACE", -1);
  sub_4D3CF0("CHAMPIONSHIP", -1);
  sub_4D3CF0("MULTIPLAYER", -1);
  sub_4D3CF0("TIME TRIAL", -1);
  sub_4D3CF0("DRIVING SCHOOL", -1);
  sub_4D3CF0("REPLAY PLAYBACK", -1);
  v2 = *(_DWORD *)dword_B72314;
  if ( !*(_DWORD *)dword_B72314 || *(_DWORD *)dword_B72314 == 2 || *(_DWORD *)dword_B72314 == 6 )
  {
    v3 = dword_B7231C;
    v2 = 3;
    *(_DWORD *)dword_B72314 = 3;
    if ( dword_B7231C > 3 || (v3 = dword_B72320, dword_B72320 < 3) )
    {
      v2 = v3;
      *(_DWORD *)dword_B72314 = v3;
    }
  }
  v4 = sub_4CFC00(v2);
  sub_615860(v4);
  this[211] = *(_DWORD *)dword_B72314;
  return 0;
}
