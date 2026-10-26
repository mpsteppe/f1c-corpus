int __thiscall sub_5AB360(int *this, int a2)
{
  int result; // eax
  int v4; // eax

  if ( a2 || (result = this[1287]) == 0 )
  {
    v4 = this[1112];
    this[1287] = 1;
    result = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 136))(v4);
    *this = result;
  }
  return result;
}
