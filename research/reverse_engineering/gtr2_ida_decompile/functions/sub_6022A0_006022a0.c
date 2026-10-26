int __thiscall sub_6022A0(_DWORD *this, int a2)
{
  int result; // eax

  (*(void (__thiscall **)(_DWORD *))(*this + 364))(this);
  (*(void (__thiscall **)(_DWORD *))(*this + 240))(this);
  (*(void (__thiscall **)(_DWORD *))(*this + 600))(this);
  if ( dword_FB2790 && *((_DWORD *)dword_FB2790 + 29) )
    (*(void (__thiscall **)(_DWORD *, void *))(*this + 248))(this, dword_FB2790);
  result = this[2387];
  if ( result )
  {
    result = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)result + 8))(this[2387]);
    this[2] = result;
    this[2387] = 0;
  }
  return result;
}
