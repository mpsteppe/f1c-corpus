int __thiscall sub_5F1930(_DWORD *this, int a2, char a3)
{
  int result; // eax
  int v4; // eax
  int v5; // [esp+Ch] [ebp-4h] BYREF

  result = 255;
  v5 = 255;
  if ( a2 == 16 )
  {
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, int *))(*this + 172))(this, this[2423], 0, &v5);
    return v5;
  }
  else if ( a2 == 32 )
  {
    v4 = *this;
    if ( a3 )
      (*(void (__stdcall **)(_DWORD, _DWORD, int *))(v4 + 172))(this[2419], 0, &v5);
    else
      (*(void (__stdcall **)(_DWORD, _DWORD, int *))(v4 + 172))(this[2418], 0, &v5);
    return v5;
  }
  return result;
}
