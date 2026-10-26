int __thiscall sub_477070(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi
  int v9; // edx
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // edx
  int v14; // esi
  const char *v15; // esi
  const char *v16; // eax

  if ( *this != *a2 )
    return *this < *a2;
  v3 = this[1];
  v4 = a2[1];
  if ( v3 != v4 )
    return v3 > v4;
  v5 = this[2];
  v6 = a2[2];
  if ( v5 != v6 )
    return v5 > v6;
  v7 = this[3];
  v8 = a2[3];
  if ( v7 != v8 )
    return v7 > v8;
  v9 = this[4];
  v10 = a2[4];
  if ( v9 != v10 )
    return v9 > v10;
  v11 = this[5];
  v12 = a2[5];
  if ( v11 != v12 )
    return v11 > v12;
  v13 = this[6];
  v14 = a2[6];
  if ( v13 != v14 )
    return v13 > v14;
  v15 = (const char *)a2[9];
  if ( !v15 )
    v15 = &byte_629120;
  v16 = (const char *)this[9];
  if ( !v16 )
    v16 = &byte_629120;
  result = strcmp(v16, v15);
  if ( result )
    return -(result < 0) - ((result < 0) - 1) < 0;
  return result;
}
