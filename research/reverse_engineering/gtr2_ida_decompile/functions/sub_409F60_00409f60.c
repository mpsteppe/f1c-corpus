void __thiscall sub_409F60(void *this)
{
  int v1; // ecx
  int v2; // eax
  int v4; // eax
  _DWORD *v5; // ecx

  sub_4EAD90(&unk_B6F135);
  sub_4EB100(&unk_B6F135);
  if ( *(_BYTE *)(*(_DWORD *)this + 20) )
  {
    v4 = *(_DWORD *)(*(_DWORD *)this + 32);
    if ( v4 > 0 && v4 <= 2 )
      sub_4E1810("MAIN MENU", 0);
  }
  v5 = *(_DWORD **)this;
  if ( *(_BYTE *)(*(_DWORD *)this + 20) )
  {
    if ( v5[8] == 1 )
    {
      dword_B698E8 = v5[22];
      dword_B763D8 = v5[20];
      v1 = v5[21];
      v2 = dword_B7231C;
      *(_DWORD *)dword_B72314 = v1;
      if ( v1 < dword_B7231C || (v2 = dword_B72320, v1 > dword_B72320) )
        *(_DWORD *)dword_B72314 = v2;
      byte_91BF5A = 0;
      if ( flt_B709FC > 0.0 )
        sub_5400B0(&unk_BE1D30);
    }
    else if ( v5[8] == 2 )
    {
      dword_B698E8 = v5[22];
    }
  }
}
