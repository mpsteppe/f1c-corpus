int __thiscall StateResetConditionalVirtualCall(_DWORD *this)
{
  int v1; // edx
  int v2; // edx

  v1 = this[65];
  *((_BYTE *)this + 381) = 0;
  *((_BYTE *)this + 382) = 0;
  if ( v1 != 4 )
  {
    v2 = *this;
    this[65] = 0;
    (*(void (__stdcall **)(_DWORD))(v2 + 64))(0);
  }
  return 0;
}
