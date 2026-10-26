int __cdecl sub_552EB6(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  _DWORD *v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // esi
  _DWORD *v8; // ecx
  int v9; // ecx
  int v11; // [esp+Ch] [ebp-4h]
  _DWORD *v12; // [esp+1Ch] [ebp+Ch]
  _DWORD *v13; // [esp+20h] [ebp+10h]

  v3 = a3;
  v11 = a1[1];
  if ( a3 > 0x3B9AC9F0 )
    sub_552EA1((int)a1, 1);
  if ( (a3 & 7) != 0 )
    v3 = 8 - (a3 & 7) + a3;
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*a1 + 20) = 12;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v13 = 0;
  v12 = (_DWORD *)(v11 + 4 * a2 + 48);
  v5 = (_DWORD *)*v12;
  if ( !*v12 )
    goto LABEL_11;
  do
  {
    if ( v5[2] >= v3 )
      break;
    v13 = v5;
    v5 = (_DWORD *)*v5;
  }
  while ( v5 );
  if ( !v5 )
  {
LABEL_11:
    v6 = v3 + 16;
    if ( v13 )
      v7 = dword_5F4E60[a2];
    else
      v7 = dword_5F4E58[a2];
    if ( v7 > 1000000000 - v6 )
      v7 = 1000000000 - v6;
    while ( 1 )
    {
      v5 = (_DWORD *)sub_5562D4((int)a1, v7 + v6);
      if ( v5 )
        break;
      v7 >>= 1;
      if ( v7 < 0x32 )
        sub_552EA1((int)a1, 2);
    }
    *(_DWORD *)(v11 + 72) += v7 + v6;
    v8 = v13;
    *v5 = 0;
    v5[1] = 0;
    v5[2] = v3 + v7;
    if ( !v13 )
      v8 = v12;
    *v8 = v5;
  }
  v9 = v5[1];
  v5[2] -= v3;
  v5[1] = v3 + v9;
  return (int)v5 + v9 + 16;
}
