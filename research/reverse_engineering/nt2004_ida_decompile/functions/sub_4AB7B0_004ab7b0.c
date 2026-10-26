int __thiscall sub_4AB7B0(char *this)
{
  int v2; // eax
  char *v3; // edi
  int v4; // ebp
  void *v5; // eax
  int v6; // edi
  int v7; // edi
  int result; // eax
  int i; // edi
  _DWORD *v10; // ebp
  bool v11; // zf

  v2 = *((_DWORD *)this + 65);
  *(_DWORD *)this = &off_5EA21C;
  if ( v2 )
  {
    sub_592C40(v2);
    *((_DWORD *)this + 65) = 0;
  }
  sub_4AF860(this + 1116);
  sub_4DAEB0(this + 1100);
  sub_4B11A0(this + 1096);
  sub_4AA6C0(this + 592);
  v3 = this + 556;
  v4 = 4;
  do
  {
    v5 = (void *)*((_DWORD *)v3 - 3);
    v3 -= 12;
    if ( v5 )
      sub_5BE8AE(v5);
    --v4;
  }
  while ( v4 );
  if ( *((_DWORD *)this + 93) )
    sub_5BE8AE(*((LPVOID *)this + 93));
  v6 = *((_DWORD *)this + 87);
  while ( v6 )
  {
    v6 = *(_DWORD *)(v6 + 4);
    sub_4AF810(1);
  }
  *((_DWORD *)this + 87) = 0;
  *((_DWORD *)this + 88) = 0;
  *((_DWORD *)this + 89) = 0;
  *((_DWORD *)this + 90) = 0;
  v7 = *((_DWORD *)this + 78);
  while ( v7 )
  {
    v7 = *(_DWORD *)(v7 + 4);
    sub_4AF7D0(1);
  }
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 79) = 0;
  *((_DWORD *)this + 80) = 0;
  *((_DWORD *)this + 81) = 0;
  sub_506C70(this + 184);
  if ( *((_DWORD *)this + 58) )
    sub_5BE8AE(*((LPVOID *)this + 58));
  if ( *((_DWORD *)this + 56) )
    sub_5BE8AE(*((LPVOID *)this + 56));
  sub_506920(this + 184);
  result = *((_DWORD *)this + 14);
  if ( result )
    result = sub_5BE8AE(*((LPVOID *)this + 14));
  for ( i = *((_DWORD *)this + 1); i; result = sub_5BE8AE(v10) )
  {
    v10 = (_DWORD *)i;
    v11 = *(_BYTE *)(i + 12) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v11 && *v10 )
      (**(void (__thiscall ***)(_DWORD, int))*v10)(*v10, 1);
  }
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return result;
}
