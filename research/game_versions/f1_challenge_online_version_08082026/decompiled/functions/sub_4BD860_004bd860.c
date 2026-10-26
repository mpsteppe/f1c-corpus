int __thiscall sub_4BD860(void *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int i; // eax
  int result; // eax

  if ( *((_DWORD *)this + 1) == *(_DWORD *)this )
  {
    v3 = *(_DWORD *)this + 8;
    *(_DWORD *)this = v3;
    v4 = sub_587C03(4 * v3);
    for ( i = 0; i < *((_DWORD *)this + 1); ++i )
      *(_DWORD *)(v4 + 4 * i) = *(_DWORD *)(*((_DWORD *)this + 2) + 4 * i);
    if ( *((_DWORD *)this + 2) )
      sub_587BCF(*((LPVOID *)this + 2));
    *((_DWORD *)this + 2) = v4;
  }
  result = *((_DWORD *)this + 1);
  *(_DWORD *)(*((_DWORD *)this + 2) + 4 * result) = a2;
  ++*((_DWORD *)this + 1);
  return result;
}
