int __thiscall sub_413DC0(int this)
{
  int result; // eax

  if ( *(_BYTE *)(this + 24) == 1 )
  {
    result = sub_412EB0((_DWORD *)this, *(_DWORD *)(this + 20), 0);
    *(_BYTE *)(this + 48) = 0;
    dword_91BF70 = 0;
    dword_91BF74 = 0;
    dword_91BF78 = 0;
    dword_91BF7C = 0;
    if ( dword_91BF28 )
      result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_91BF28 + 16))(dword_91BF28);
    if ( dword_B6E4D0 == 1 )
      result = sub_4E5FC0(&dword_B6E4D0, 0);
  }
  *(_BYTE *)(this + 24) = 0;
  return result;
}
