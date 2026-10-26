int __thiscall sub_4B39F0(_BYTE *this)
{
  unsigned __int8 v1; // al
  char v2; // dl
  int v3; // eax

  v1 = this[276] == 0;
  this[276] = v1;
  v2 = byte_B73392;
  byte_B73390 = v1;
  if ( v1 < (unsigned __int8)byte_B73392 || (v2 = byte_B73393, v1 > (unsigned __int8)byte_B73393) )
    byte_B73390 = v2;
  v3 = *(_DWORD *)this;
  if ( this[276] )
    *((_DWORD *)this + 67) = 0;
  else
    *((_DWORD *)this + 67) = 1;
  (*(void (__stdcall **)(_DWORD))(v3 + 44))(*((_DWORD *)this + 67));
  return 0;
}
