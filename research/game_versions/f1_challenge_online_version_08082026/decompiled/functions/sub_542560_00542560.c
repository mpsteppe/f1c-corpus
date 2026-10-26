int __thiscall sub_542560(int *this, int a2)
{
  int result; // eax
  double v3; // st7
  float v4; // [esp+0h] [ebp-14h]
  float v5; // [esp+4h] [ebp-10h]
  float v6; // [esp+8h] [ebp-Ch]
  float v7; // [esp+Ch] [ebp-8h]

  result = a2;
  if ( a2 )
  {
    v3 = (double)this[22];
    this[103] = a2;
    v7 = v3;
    v6 = (float)this[21];
    v5 = (float)this[25];
    v4 = (float)this[26];
    return sub_542200((int)this, v4, v5, v6, v7, 1);
  }
  return result;
}
