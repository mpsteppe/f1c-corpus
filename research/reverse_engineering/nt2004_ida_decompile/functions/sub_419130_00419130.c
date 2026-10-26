char __thiscall sub_419130(int this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  char result; // al

  v2 = *(void (__thiscall ****)(_DWORD, int))(this + 12);
  if ( v2 )
  {
    (**v2)(v2, 1);
    *(_DWORD *)(this + 12) = 0;
  }
  result = *(_BYTE *)(this + 8);
  if ( result )
  {
    sub_419200(this);
    sub_58D4D0();
    sub_4189D0((int)&unk_629248);
    if ( dword_629314 )
    {
      sub_5BE8AE((LPVOID)dword_629314);
      dword_629314 = 0;
    }
    result = dword_629318;
    dword_62931C = 0;
    if ( dword_629318 )
    {
      result = sub_5BE8AE((LPVOID)dword_629318);
      dword_629318 = 0;
    }
  }
  return result;
}
