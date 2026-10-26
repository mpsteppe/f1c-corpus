int __thiscall sub_49B4D0(int this)
{
  int result; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  result = sub_48C270();
  v3 = result;
  if ( result > 0 )
  {
    sub_4DE540(v6, &v5);
    result = sub_4D0D20(v5);
    if ( result < 0 )
    {
      result = 0;
LABEL_7:
      dword_759F30 = result;
      byte_759F34 = *(_BYTE *)(this + 596);
      v4 = sub_4DF040(*(_DWORD *)(this + 48), off_759F24);
      return sub_4DE390(*(_DWORD *)(this + 48), off_759F20[0], &dword_759F30, 4, v4);
    }
    if ( result > v3 - 1 )
      result = v3 - 1;
    if ( result >= 0 )
      goto LABEL_7;
  }
  return result;
}
