_DWORD *__cdecl sub_553816(_DWORD *a1)
{
  int v1; // edi
  _DWORD *result; // eax
  _DWORD *v3; // ecx
  int v4; // edx

  a1[1] = 0;
  v1 = sub_5BFE92(a1);
  result = (_DWORD *)sub_5562D4((int)a1, 0x50u);
  if ( result )
  {
    *result = sub_552EB6;
    result[1] = sub_552FB2;
    result[2] = sub_553040;
    result[3] = sub_5530D2;
    result[4] = sub_553170;
    result[5] = sub_5531D1;
    result[6] = sub_553232;
    result[7] = sub_5534C4;
    result[8] = sub_5535E2;
    result[9] = sub_553705;
    result[10] = sub_5537E6;
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
    nullsub_9(a1);
    *(_DWORD *)(*a1 + 20) = 53;
    *(_DWORD *)(*a1 + 24) = 0;
    return (_DWORD *)(*(int (__cdecl **)(_DWORD *))*a1)(a1);
  }
  return result;
}
