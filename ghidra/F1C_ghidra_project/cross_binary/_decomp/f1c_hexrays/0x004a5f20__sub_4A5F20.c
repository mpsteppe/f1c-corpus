// f1c  0x004a5f20  size=128
char __thiscall sub_4A5F20(_BYTE *this)
{
  char result; // al
  int v3; // eax
  _DWORD *v4; // ecx

  result = this[384];
  if ( result )
  {
    sub_4A5C80((int)this, 0);
    v3 = *(_DWORD *)this + 16436;
    this[384] = 0;
    ++*(_DWORD *)(v3 + 56);
    sub_41A3A0(*(_DWORD **)this);
    result = dword_8ACFD4 - 2;
    if ( dword_8ACFD4 == 2 )
    {
      result = dword_7CEF84;
      if ( dword_7CEF84 )
      {
        if ( dword_7C56A4 == 7 )
          result = sub_4BC0E0(aExitingPitsUnd);
        else
          result = sub_4BBA90((int)aExitingPitsUnd, 1000.0);
      }
    }
  }
  v4 = (_DWORD *)*((_DWORD *)this + 5);
  if ( v4 )
    return sub_4A3FE0(v4);
  return result;
}
