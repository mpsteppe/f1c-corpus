int __thiscall sub_524540(float *this, int a2, unsigned int a3)
{
  int result; // eax
  int v5; // [esp+10h] [ebp-31Ch] BYREF
  _BYTE v6[384]; // [esp+14h] [ebp-318h] BYREF
  int v7; // [esp+194h] [ebp-198h]
  char v8; // [esp+198h] [ebp-194h]
  int v9; // [esp+1A0h] [ebp-18Ch]
  int v10; // [esp+1A4h] [ebp-188h]
  int v11; // [esp+1A8h] [ebp-184h]
  char Buffer[384]; // [esp+1ACh] [ebp-180h] BYREF

  result = 0;
  memset(Buffer, 0, sizeof(Buffer));
  v7 = 0;
  v11 = 0;
  v9 = 0;
  v10 = 0;
  v8 = 1;
  if ( a3 <= 4 )
  {
    for ( result = sub_57A490(Buffer, 384); result; result = sub_57A490(Buffer, 384) )
    {
      result = sub_577B60(v6);
      if ( result )
      {
        if ( result == 2 )
          return result;
      }
      else
      {
        if ( sub_578220(aMinimumrpm, (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
          this[3 * a3 + 1] = *(float *)&v5 * 0.1047197551196598;
        if ( sub_578220(aMaximumrpm, (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
          this[3 * a3 + 2] = *(float *)&v5 * 0.1047197551196598;
        if ( sub_578220(aNaturalrpm, (int)&v5, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( *(float *)&v5 > 0.0 )
            this[3 * a3 + 3] = 1.0 / (*(float *)&v5 * 0.1047197551196598);
          else
            this[3 * a3 + 3] = 0.0;
        }
      }
    }
  }
  return result;
}
