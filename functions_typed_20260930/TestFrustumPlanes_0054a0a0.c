int __thiscall sub_54A0A0(float *this, int a2)
{
  unsigned int v3; // eax
  float *i; // edx
  int v5; // edi
  int v6; // ecx
  float *v7; // esi
  int v9; // ebp
  int v10; // [esp+10h] [ebp-4h]

  v3 = (_DWORD)this[1] & 0xFFFFFFF0;
  *((_DWORD *)this + 1) = v3;
  v10 = 0;
  for ( i = (float *)(a2 + 260); ; i += 4 )
  {
    v5 = 0;
    v6 = 0;
    v7 = this + 9;
    do
    {
      if ( -(*(i - 2) * *(v7 - 2)) - *(i - 1) * *(v7 - 1) - *i * *v7 > i[1] )
        v5 |= 1 << v6;
      ++v6;
      v7 += 3;
    }
    while ( v6 < 8 );
    if ( v5 )
      break;
    if ( ++v10 >= 6 )
    {
      *((_DWORD *)this + 1) = v3 | 1;
      return 0;
    }
  }
  if ( v5 == 255 )
    v9 = v3 | 2;
  else
    v9 = v3 | 4;
  *((_DWORD *)this + 1) = v9;
  return 0;
}

