// f1c  0x005818e0  size=89
void __thiscall sub_5818E0(void *this)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi

  if ( *((_BYTE *)this + 24) && CloseHandle(*((HANDLE *)this + 4)) )
    *((_DWORD *)this + 4) = 0;
  v2 = *(_DWORD **)this;
  if ( *(_DWORD *)this )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      if ( *((_BYTE *)v3 + 8) && *v3 )
        (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
      sub_587BCF(v3);
    }
    while ( v2 );
  }
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
}
