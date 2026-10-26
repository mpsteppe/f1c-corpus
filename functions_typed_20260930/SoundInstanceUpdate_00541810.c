int __thiscall sub_541810(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  int v7; // ebp
  _DWORD *v9; // edi
  int v10; // eax

  result = this[1270];
  if ( result )
  {
    v5 = 0;
    if ( (int)this[1367] > 0 )
    {
      v6 = this + 1368;
      do
      {
        *this = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 184))(this[1088], *v6, 0);
        ++v5;
        ++v6;
      }
      while ( v5 < this[1367] );
    }
    result = a2;
    v7 = 0;
    this[1367] = a2;
    if ( a2 > 0 )
    {
      v9 = this + 1368;
      do
      {
        v10 = *(_DWORD *)(*(_DWORD *)a3 + 4);
        *v9 = v10;
        *this = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)this[1088] + 184))(this[1088], v10, 1);
        result = this[1367];
        ++v7;
        ++v9;
        a3 += 56;
      }
      while ( v7 < result );
    }
  }
  return result;
}

