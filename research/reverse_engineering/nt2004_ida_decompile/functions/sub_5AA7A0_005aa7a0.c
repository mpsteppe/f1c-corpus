int __thiscall sub_5AA7A0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx

  result = this[12];
  if ( a2 != result )
  {
    v4 = *(_DWORD *)dword_7E7CA8;
    if ( a2 )
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(v4 + 244))(
                 dword_7E7CA8,
                 *this,
                 *(_DWORD *)(*(_DWORD *)(a2 + 16) + 24));
      this[12] = a2;
    }
    else
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(v4 + 244))(dword_7E7CA8, *this, 0);
      this[12] = 0;
    }
  }
  return result;
}
