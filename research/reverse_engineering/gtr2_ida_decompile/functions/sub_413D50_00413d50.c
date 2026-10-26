char __thiscall sub_413D50(_DWORD **this, int a2, int a3)
{
  char result; // al
  int v5; // eax

  result = 0;
  if ( a2 )
  {
    v5 = (*(int (__thiscall **)(_DWORD *, int))(*this[8] + 28))(this[8], a2);
    if ( !v5 )
    {
      v5 = (*(int (__thiscall **)(_DWORD *, int))(*this[9] + 28))(this[9], a2);
      if ( !v5 )
      {
        v5 = (*(int (__thiscall **)(_DWORD *, int))(*this[10] + 28))(this[10], a2);
        if ( !v5 )
          v5 = (*(int (__thiscall **)(_DWORD *, int))(*this[11] + 28))(this[11], a2);
      }
    }
    return sub_413CB0((int)this, v5, a3);
  }
  return result;
}
