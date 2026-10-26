int __thiscall sub_4A4DF0(_BYTE *this)
{
  char v1; // dl
  int v2; // eax

  v1 = this[276];
  this[276] = v1 == 0;
  byte_B65C79 = v1 == 0;
  this[276] = v1 == 0;
  v2 = *(_DWORD *)this;
  if ( v1 )
    *((_DWORD *)this + 67) = 1;
  else
    *((_DWORD *)this + 67) = 0;
  (*(void (__stdcall **)(_DWORD))(v2 + 44))(*((_DWORD *)this + 67));
  return 0;
}
