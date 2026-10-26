int __thiscall sub_4B4280(_DWORD *this)
{
  int v2; // esi
  int v4; // [esp+8h] [ebp-4h] BYREF

  if ( sub_491450(this, &v4) && v4 > 0 )
  {
    if ( (dword_B73348 & v4) != 0 )
    {
      v2 = ~v4 & dword_B73348;
      dword_B73348 = v2;
    }
    else
    {
      v2 = v4 | dword_B73348;
      dword_B73348 |= v4;
    }
  }
  else
  {
    v2 = dword_B73348;
  }
  if ( sub_491450(this, &v4) )
    this[67] = (v4 & v2) == 0;
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, this[67]);
  return 0;
}
