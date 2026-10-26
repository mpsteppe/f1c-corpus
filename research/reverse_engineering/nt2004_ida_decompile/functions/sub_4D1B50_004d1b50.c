bool __thiscall sub_4D1B50(int *this, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  int i; // ecx
  char v10; // [esp+0h] [ebp-2Ch]
  __int64 v12; // [esp+14h] [ebp-18h]
  double v13; // [esp+24h] [ebp-8h]
  float v14; // [esp+30h] [ebp+4h]
  int v15; // [esp+34h] [ebp+8h]

  if ( a2 > a3 || !a4 )
    return 0;
  v4 = a3 - a2 + 1;
  v5 = 0;
  v6 = 0;
  v15 = a3 - a2;
  if ( v4 <= 0 )
    return 1;
  v13 = (double)a2;
  while ( 1 )
  {
    v12 = (unsigned int)sub_4D1A80(this);
    v7 = 0;
    v14 = (double)v12 * 2.328306437080797e-10 * (double)v15 + v13;
    for ( i = (int)v14; v7 < v5; ++v7 )
    {
      if ( i == *(_DWORD *)(a4 + 4 * v7) )
        break;
    }
    if ( v7 == v5 )
    {
      *(_DWORD *)(a4 + 4 * v7) = i;
      ++v5;
    }
    if ( ++v6 > 1000 )
      break;
    if ( v5 >= v4 )
      return 1;
  }
  if ( dword_75CBA8 != 5 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_17, 144) )
      sub_500FE0((int)&unk_7D7920, aRandomGenerate, v10);
  }
  return v5 >= v4;
}
