char __thiscall sub_478700(int *this)
{
  int v2; // ecx
  int v3; // eax
  float v5; // [esp+0h] [ebp-420h]
  _BYTE v6[4]; // [esp+10h] [ebp-410h] BYREF
  _BYTE v7[180]; // [esp+14h] [ebp-40Ch] BYREF
  _BYTE v8[856]; // [esp+C8h] [ebp-358h] BYREF

  sub_473460(v7);
  if ( !(unsigned __int8)sub_473900() )
    return 0;
  if ( *(_DWORD *)(*this + 113328) == 4 && *(_DWORD *)(*this + 113316) && sub_59B670(*(_DWORD *)(*this + 113316)) == 3 )
    *(_DWORD *)(*this + 113328) = 3;
  v2 = *this;
  v3 = *(_DWORD *)(*this + 113328);
  if ( v3 == 2 || v3 == 1 )
  {
    sub_4742B0(v2);
  }
  else
  {
    *(_DWORD *)(v2 + 1188) = -1082130432;
    *(_BYTE *)(v2 + 1185) = 0;
  }
  sub_477E20();
  sub_474770();
  v5 = dbl_FB1D18;
  sub_51B2A0(4, 5, 0, 0, LODWORD(v5), 3);
  sub_4745E0();
  sub_4EB8E0(&unk_B6F134, v8, 2, -1, -1, v6, v7);
  return 1;
}
