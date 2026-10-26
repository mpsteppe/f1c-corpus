__int16 __cdecl sub_58FAA0(int a1, int a2)
{
  int v2; // ebx
  unsigned int v3; // edi
  unsigned int v5; // esi
  int v6; // eax
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v8 = 0;
  v9 = 0;
  v2 = a1 / 2;
  v7 = -1;
  if ( a1 / 2 > 10 )
    v2 = 10;
  v3 = (a1 * ((unsigned int)sub_58F940() >> 16)) >> 16;
  if ( a2 == -1 )
    return v3;
  do
  {
    v5 = (a1 * ((unsigned int)sub_58F940() >> 16)) >> 16;
    v6 = sub_58FB60(v5, v2, a2);
    if ( v6 == -1 )
    {
      LOWORD(v3) = v5;
      v9 = 1;
    }
    else if ( v6 > v7 )
    {
      LOWORD(v3) = v5;
      v7 = v6;
    }
    ++v8;
  }
  while ( v8 < 32 && !v9 );
  sub_58FBF0(v3, a2);
  return v5;
}
