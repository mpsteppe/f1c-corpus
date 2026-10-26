int __thiscall sub_5AB3A0(int *this, int a2)
{
  int result; // eax
  int v4; // eax

  result = a2;
  if ( a2 )
  {
    result = this[1287];
    if ( result )
    {
      v4 = this[1112];
      this[1287] = 0;
      result = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 140))(v4);
      *this = result;
    }
  }
  return result;
}
