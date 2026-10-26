int __thiscall sub_4A78E0(int *this)
{
  int v2; // edi
  int v3; // eax

  if ( *(_DWORD *)dword_B72314 == 7 )
    (*(void (__thiscall **)(int *, _DWORD))(*this + 40))(this, 0);
  else
    (*(void (__thiscall **)(int *, int))(*this + 40))(this, 1);
  v2 = *this;
  v3 = sub_54BE10(&unk_BE27B0);
  LOBYTE(v3) = (_BYTE)v3 == 0;
  return (*(int (__thiscall **)(int *, int))(v2 + 36))(this, v3);
}
