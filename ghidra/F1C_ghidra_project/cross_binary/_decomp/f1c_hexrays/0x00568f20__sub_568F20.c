// f1c  0x00568f20  size=131
void *__thiscall sub_568F20(int this)
{
  void *v2; // eax
  void *v3; // eax
  void *result; // eax

  if ( *(_DWORD *)this )
  {
    sub_587BCF(*(LPVOID *)this);
    *(_DWORD *)this = 0;
  }
  v2 = *(void **)(this + 560);
  *(_DWORD *)(this + 548) = 0;
  *(_DWORD *)(this + 552) = 0;
  *(_DWORD *)(this + 556) = 0;
  if ( v2 )
  {
    sub_587BCF(v2);
    *(_DWORD *)(this + 560) = 0;
  }
  v3 = *(void **)(this + 568);
  *(_DWORD *)(this + 564) = 0;
  if ( v3 )
  {
    sub_587BCF(v3);
    *(_DWORD *)(this + 568) = 0;
  }
  result = *(void **)(this + 576);
  *(_DWORD *)(this + 572) = 0;
  if ( result )
  {
    result = (void *)sub_587BCF(result);
    *(_DWORD *)(this + 576) = 0;
  }
  return result;
}
