char __thiscall sub_551110(int *this)
{
  int v1; // edx
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // ebx
  int *v6; // edi
  int v7; // esi
  int v8; // ebp
  char result; // al
  _BYTE v10[52]; // [esp+10h] [ebp-34h] BYREF

  v1 = dword_757C10;
  memset(v10, 0, sizeof(v10));
  v3 = 0;
  if ( dword_757C10 > 0 )
  {
    do
    {
      v4 = *(_DWORD *)(*(&dword_91E088 + v3) + 22548);
      if ( v4 < 0x34 )
        v10[v4] = 1;
      ++v3;
    }
    while ( v3 < v1 );
  }
  v5 = 0;
  v6 = this + 647;
  do
  {
    v7 = *(v6 - 52);
    v8 = *v6;
    if ( v6[52] )
      sub_5DB320(0, 0, 1);
    result = v10[v5];
    if ( result )
    {
      if ( v7 )
        result = sub_5DB320(0, 0, 1);
      if ( v8 )
        result = sub_5DB320(1, 1, 1);
    }
    else
    {
      if ( v7 )
        result = sub_5DB320(1, 1, 1);
      if ( v8 )
        result = sub_5DB320(0, 0, 1);
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 52 );
  return result;
}
