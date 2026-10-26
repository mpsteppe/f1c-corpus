// f1c  0x0051601f  size=142
_DWORD *__cdecl sub_51601F(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int v4; // edi
  _DWORD *v5; // esi
  int *v6; // eax
  int v7; // ecx

  v3 = a1[1];
  v4 = a3;
  if ( a3 > 0x3B9AC9F0 )
    sub_515F0E((int)a1, 3);
  if ( (a3 & 7) != 0 )
    v4 = 8 - (a3 & 7) + a3;
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v5 = (_DWORD *)sub_519346(a1, v4 + 16);
  if ( !v5 )
    sub_515F0E((int)a1, 4);
  *(_DWORD *)(v3 + 72) += v4 + 16;
  v6 = (int *)(v3 + 4 * a2 + 56);
  v7 = *v6;
  v5[2] = 0;
  v5[1] = v4;
  *v5 = v7;
  *v6 = (int)v5;
  return v5 + 4;
}
