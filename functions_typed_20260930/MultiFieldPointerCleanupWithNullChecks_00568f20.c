void *__thiscall sub_568F20(int this)
{
  void *v2; // eax
  void *v3; // eax
  void *result; // eax

  if ( *(_DWORD *)this )
  {
    FreeWrapper_7bcf(*(LPVOID *)this);
    *(_DWORD *)this = 0;
  }
  v2 = *(void **)(this + 560);
  *(_DWORD *)(this + 548) = 0;
  *(_DWORD *)(this + 552) = 0;
  *(_DWORD *)(this + 556) = 0;
  if ( v2 )
  {
    FreeWrapper_7bcf(v2);
    *(_DWORD *)(this + 560) = 0;
  }
  v3 = *(void **)(this + 568);
  *(_DWORD *)(this + 564) = 0;
  if ( v3 )
  {
    FreeWrapper_7bcf(v3);
    *(_DWORD *)(this + 568) = 0;
  }
  result = *(void **)(this + 576);
  *(_DWORD *)(this + 572) = 0;
  if ( result )
  {
    result = (void *)FreeWrapper_7bcf(result);
    *(_DWORD *)(this + 576) = 0;
  }
  return result;
}

