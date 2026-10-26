int __thiscall sub_4C85D0(int this)
{
  int result; // eax

  result = dword_8AC4C8;
  if ( dword_8AC4C8
    || dword_8AC4C4
    && (dword_8AC4C8 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C4 + 96))(dword_8AC4C4),
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_8AC4C8 + 28))(dword_8AC4C8, LODWORD(flt_7CF380)),
        (result = dword_8AC4C8) != 0) )
  {
    *(_BYTE *)(this + 16) = 1;
    *(_DWORD *)(this + 20) = 0;
    return (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_8AC4C8 + 28))(dword_8AC4C8, LODWORD(flt_7CF380));
  }
  return result;
}
