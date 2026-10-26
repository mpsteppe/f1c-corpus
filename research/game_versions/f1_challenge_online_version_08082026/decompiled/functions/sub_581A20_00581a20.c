void __thiscall sub_581A20(int *this)
{
  int v2; // esi
  _BYTE *v3; // edi

  if ( *((_BYTE *)this + 24) && CloseHandle((HANDLE)this[4]) )
    this[4] = 0;
  v2 = *this;
  while ( v2 )
  {
    v3 = (_BYTE *)v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( v3[8] && *(_DWORD *)v3 )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)v3 + 4))(*(_DWORD *)v3, 1);
    sub_587BCF(v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
