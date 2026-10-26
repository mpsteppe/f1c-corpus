_DWORD *__cdecl sub_516883(_DWORD *a1)
{
  int v1; // edi
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // edx

  a1[1] = 0;
  v1 = sub_58FB7E(a1);
  result = (_DWORD *)sub_519346(a1, 80);
  if ( result )
  {
    *result = sub_515F23;
    result[1] = sub_51601F;
    result[2] = sub_5160AD;
    result[3] = sub_51613F;
    result[4] = sub_5161DD;
    result[5] = sub_51623E;
    result[6] = sub_51629F;
    result[7] = sub_516531;
    result[8] = sub_51664F;
    result[9] = sub_516772;
    result[10] = sub_516853;
    result[11] = v1;
    v3 = result + 15;
    v4 = 2;
    do
    {
      *(v3 - 2) = 0;
      *v3-- = 0;
      --v4;
    }
    while ( v4 );
    result[16] = 0;
    result[17] = 0;
    result[18] = 80;
    a1[1] = result;
  }
  else
  {
    nullsub_8(a1);
    *(_DWORD *)(*a1 + 20) = 53;
    *(_DWORD *)(*a1 + 24) = 0;
    return (_DWORD *)(*(int (__cdecl **)(_DWORD *))*a1)(a1);
  }
  return result;
}
