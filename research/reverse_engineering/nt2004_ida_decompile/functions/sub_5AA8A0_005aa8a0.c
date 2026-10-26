int __thiscall sub_5AA8A0(int *this, _DWORD *a2)
{
  int v3; // eax
  int result; // eax
  int v5; // eax

  if ( a2 )
  {
    v3 = a2[8];
    if ( this[1278] != v3 )
    {
      this[1278] = v3;
      *this = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[1112] + 332))(
                this[1112],
                0,
                a2[8],
                a2[2]);
    }
    result = a2[1];
    if ( this[1279] != result && result != -1 )
    {
      this[1279] = result;
      result = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)this[1112] + 304))(this[1112], a2[1]);
      *this = result;
    }
  }
  else
  {
    v5 = this[1112];
    this[1278] = 0;
    result = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 332))(v5, 0, 0, 0);
    *this = result;
  }
  return result;
}
