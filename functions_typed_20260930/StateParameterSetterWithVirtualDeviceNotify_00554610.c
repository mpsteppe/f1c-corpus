int __thiscall sub_554610(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx

  result = this[12];
  if ( a2 != result )
  {
    v4 = *(_DWORD *)dword_8B89A0;
    if ( a2 )
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(v4 + 244))(
                 dword_8B89A0,
                 *this,
                 *(_DWORD *)(*(_DWORD *)(a2 + 84) + 20));
      this[12] = a2;
    }
    else
    {
      result = (*(int (__stdcall **)(int, _DWORD, _DWORD))(v4 + 244))(dword_8B89A0, *this, 0);
      this[12] = 0;
    }
  }
  return result;
}

