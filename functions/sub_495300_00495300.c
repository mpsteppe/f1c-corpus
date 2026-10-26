int __thiscall sub_495300(char *this)
{
  int v2; // edi
  char *v3; // edi
  int v4; // ebp
  void *v5; // eax
  int v6; // edi
  int result; // eax
  int i; // edi
  _DWORD *v9; // ebp
  bool v10; // zf

  *(_DWORD *)this = &off_5AC998;
  LinkedListDestroy(this + 6364);
  LinkedListDestroy(this + 6348);
  LinkedListDestroy(this + 6332);
  v2 = *((_DWORD *)this + 1579);
  while ( v2 )
  {
    v2 = *(_DWORD *)(v2 + 4);
    ShortComputation_9620(1);
  }
  *((_DWORD *)this + 1579) = 0;
  *((_DWORD *)this + 1580) = 0;
  *((_DWORD *)this + 1581) = 0;
  *((_DWORD *)this + 1582) = 0;
  ListCleanupWithVTableDestructor(this + 6308);
  EmptyStub_0170(this + 5876);
  MultiListDestruction_a2f0(this + 5772);
  v3 = this + 5676;
  v4 = 4;
  do
  {
    v5 = (void *)*((_DWORD *)v3 - 3);
    v3 -= 12;
    if ( v5 )
      FreeWrapper_7bcf(v5);
    --v4;
  }
  while ( v4 );
  if ( *((_DWORD *)this + 1366) )
    FreeWrapper_7bcf(*((LPVOID *)this + 1366));
  v6 = *((_DWORD *)this + 60);
  while ( v6 )
  {
    v6 = *(_DWORD *)(v6 + 4);
    DestructorWithDataFree(1);
  }
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 63) = 0;
  result = *((_DWORD *)this + 15);
  if ( result )
    result = FreeWrapper_7bcf(*((LPVOID *)this + 15));
  for ( i = *((_DWORD *)this + 1); i; result = FreeWrapper_7bcf(v9) )
  {
    v9 = (_DWORD *)i;
    v10 = *(_BYTE *)(i + 12) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v10 && *v9 )
      (**(void (__thiscall ***)(_DWORD, int))*v9)(*v9, 1);
  }
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return result;
}
