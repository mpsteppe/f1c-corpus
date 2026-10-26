// f1c  0x00554700  size=142
int __thiscall sub_554700(int *this, _DWORD *a2)
{
  int v3; // eax
  int result; // eax
  int v5; // eax

  if ( a2 )
  {
    v3 = a2[8];
    if ( this[1254] != v3 )
    {
      this[1254] = v3;
      *this = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[1088] + 332))(
                this[1088],
                0,
                a2[8],
                a2[2]);
    }
    result = a2[1];
    if ( this[1255] != result && result != -1 )
    {
      this[1255] = result;
      result = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)this[1088] + 304))(this[1088], a2[1]);
      *this = result;
    }
  }
  else
  {
    v5 = this[1088];
    this[1254] = 0;
    result = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 332))(v5, 0, 0, 0);
    *this = result;
  }
  return result;
}
