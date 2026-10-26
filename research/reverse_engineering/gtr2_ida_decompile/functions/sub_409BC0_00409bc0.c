int __thiscall sub_409BC0(int this)
{
  const char *v2; // eax
  const CHAR *v3; // eax
  int result; // eax
  int v5; // eax

  v2 = *(const char **)(this + 56);
  if ( !v2 )
    v2 = WindowName;
  if ( strlen(v2) )
  {
    v3 = *(const CHAR **)(this + 56);
    if ( !v3 )
      v3 = WindowName;
    sub_514EC0(v3, 1);
  }
  result = *(_DWORD *)(this + 32) - 1;
  if ( *(_DWORD *)(this + 32) == 1 )
  {
    *(_DWORD *)(this + 80) = dword_B763D8;
    dword_B763D8 = 1;
    *(_DWORD *)(this + 84) = *(_DWORD *)dword_B72314;
    v5 = dword_B7231C;
    *(_DWORD *)dword_B72314 = 2;
    if ( dword_B7231C > 2 || (v5 = dword_B72320, dword_B72320 < 2) )
      *(_DWORD *)dword_B72314 = v5;
    sub_4EA8E0(&unk_B6F134);
    sub_410C30(1, 15);
    flt_B728A4 = 0.050000001;
    if ( flt_B728AC <= 0.050000001 )
    {
      if ( flt_B728B0 < 0.050000001 )
        flt_B728A4 = flt_B728B0;
    }
    else
    {
      flt_B728A4 = flt_B728AC;
    }
    *(_DWORD *)(this + 88) = dword_B698E8;
    dword_B698E8 = 2;
    result = sub_4EA9D0(&unk_B6F135);
  }
  *(_BYTE *)(this + 20) = 1;
  *(_BYTE *)(this + 21) = 0;
  return result;
}
