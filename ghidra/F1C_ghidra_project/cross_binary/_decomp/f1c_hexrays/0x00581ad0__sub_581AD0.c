// f1c  0x00581ad0  size=88
void __thiscall sub_581AD0(int *this)
{
  int v2; // esi
  int v3; // edi

  if ( *((_BYTE *)this + 24) && CloseHandle((HANDLE)this[4]) )
    this[4] = 0;
  v2 = *this;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) )
      sub_587BCF(*(LPVOID *)v3);
    sub_587BCF((LPVOID)v3);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
}
