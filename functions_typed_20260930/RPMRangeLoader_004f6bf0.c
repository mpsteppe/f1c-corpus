int __thiscall sub_4F6BF0(float *this, int a2, unsigned int a3)
{
  int result; // eax
  float v5; // [esp+10h] [ebp-31Ch] BYREF
  _BYTE v6[384]; // [esp+14h] [ebp-318h] BYREF
  int v7; // [esp+194h] [ebp-198h]
  char v8; // [esp+198h] [ebp-194h]
  int v9; // [esp+1A0h] [ebp-18Ch]
  int v10; // [esp+1A4h] [ebp-188h]
  int v11; // [esp+1A8h] [ebp-184h]
  _BYTE v12[384]; // [esp+1ACh] [ebp-180h] BYREF

  result = 0;
  memset(v12, 0, sizeof(v12));
  v7 = 0;
  v11 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 1;
  if ( a3 <= 4 )
  {
    for ( result = ConditionalDispatchBasedOnFlag(v12, 384); result; result = ConditionalDispatchBasedOnFlag(v12, 384) )
    {
      result = sub_5651B0(v6);
      if ( result )
      {
        if ( result == 2 )
          return result;
      }
      else
      {
        if ( sub_565870(aMinimumrpm, &v5, 0, 0, 0, 0, 0, 0, 0) )
          this[3 * a3 + 1] = v5 * 0.1047197551196598;
        if ( sub_565870(aMaximumrpm, &v5, 0, 0, 0, 0, 0, 0, 0) )
          this[3 * a3 + 2] = v5 * 0.1047197551196598;
        if ( sub_565870(aNaturalrpm, &v5, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( v5 > 0.0 )
            this[3 * a3 + 3] = 1.0 / (v5 * 0.1047197551196598);
          else
            this[3 * a3 + 3] = 0.0;
        }
      }
    }
  }
  return result;
}

