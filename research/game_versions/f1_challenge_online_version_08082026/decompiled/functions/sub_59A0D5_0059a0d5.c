__int16 __thiscall sub_59A0D5(int *this)
{
  unsigned int v2; // eax
  int v4; // edi
  int v5; // eax

  v2 = *(_DWORD *)this[7];
  if ( v2 && v2 < v2 + 2 * *(_DWORD *)this[11] )
    return *(_WORD *)v2;
  v4 = *this;
  v5 = (*(int (__thiscall **)(int *))(*this + 20))(this);
  return (*(int (__thiscall **)(int *, int))(v4 + 8))(this, v5);
}
