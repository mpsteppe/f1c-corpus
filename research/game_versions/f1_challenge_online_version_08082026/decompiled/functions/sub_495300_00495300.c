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
  sub_499580(this + 6364);
  sub_499580(this + 6348);
  sub_499580(this + 6332);
  v2 = *((_DWORD *)this + 1579);
  while ( v2 )
  {
    v2 = *(_DWORD *)(v2 + 4);
    sub_499620(1);
  }
  *((_DWORD *)this + 1579) = 0;
  *((_DWORD *)this + 1580) = 0;
  *((_DWORD *)this + 1581) = 0;
  *((_DWORD *)this + 1582) = 0;
  sub_49A190(this + 6308);
  nullsub_3(this + 5876);
  sub_49A2F0(this + 5772);
  v3 = this + 5676;
  v4 = 4;
  do
  {
    v5 = (void *)*((_DWORD *)v3 - 3);
    v3 -= 12;
    if ( v5 )
      sub_587BCF(v5);
    --v4;
  }
  while ( v4 );
  if ( *((_DWORD *)this + 1366) )
    sub_587BCF(*((LPVOID *)this + 1366));
  v6 = *((_DWORD *)this + 60);
  while ( v6 )
  {
    v6 = *(_DWORD *)(v6 + 4);
    sub_4995E0(1);
  }
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 63) = 0;
  result = *((_DWORD *)this + 15);
  if ( result )
    result = sub_587BCF(*((LPVOID *)this + 15));
  for ( i = *((_DWORD *)this + 1); i; result = sub_587BCF(v9) )
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
