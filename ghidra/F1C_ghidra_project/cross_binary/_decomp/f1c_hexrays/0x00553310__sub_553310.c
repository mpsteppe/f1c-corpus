// f1c  0x00553310  size=85
void __thiscall sub_553310(void *this)
{
  if ( (*(_DWORD *)this & 1) != 0 || (*(_DWORD *)this & 2) != 0 )
  {
    if ( *((_DWORD *)this + 6) )
      sub_587BCF(*((LPVOID *)this + 6));
    *((_DWORD *)this + 6) = 0;
  }
  if ( *((_DWORD *)this + 5) )
  {
    sub_540EB0(dword_8B78A0, *((_DWORD *)this + 5));
    if ( *((_DWORD *)this + 5) )
      sub_587BCF(*((LPVOID *)this + 5));
    *((_DWORD *)this + 5) = 0;
  }
  nullsub_3();
}
