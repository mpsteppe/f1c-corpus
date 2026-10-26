// f1c  0x00499280  size=87
int __thiscall sub_499280(void *this)
{
  _DWORD *v2; // esi
  int v3; // eax
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (_DWORD *)*((_DWORD *)this + 17);
  for ( *(_DWORD *)this = &off_5ACA74; v2; *((_DWORD *)this + 17) = v2 )
  {
    v3 = sub_486320(v2);
    v4 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 17);
    v2 = (_DWORD *)v3;
    if ( v4 )
      (**v4)(v4, 1);
  }
  if ( *((_DWORD *)this + 24) )
    sub_587BCF(*((LPVOID *)this + 24));
  if ( *((_DWORD *)this + 22) )
    sub_587BCF(*((LPVOID *)this + 22));
  return sub_49A990(this);
}
