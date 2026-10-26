int __thiscall sub_554BE0(int *this, int a2)
{
  int result; // eax
  int v4; // eax

  result = a2;
  if ( a2 != this[1256] )
  {
    this[1256] = a2;
    v4 = this[1088];
    if ( a2 )
      result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 200))(v4, 14, 1);
    else
      result = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v4 + 200))(v4, 14, 0);
    *this = result;
  }
  return result;
}

