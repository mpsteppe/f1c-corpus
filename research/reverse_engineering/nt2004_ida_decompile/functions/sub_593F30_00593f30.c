void __thiscall sub_593F30(int *this, int a2)
{
  double v2; // st7
  float v3; // [esp+0h] [ebp-14h]
  float v4; // [esp+4h] [ebp-10h]
  float v5; // [esp+8h] [ebp-Ch]
  float v6; // [esp+Ch] [ebp-8h]

  if ( a2 )
  {
    v2 = (double)this[22];
    this[151] = a2;
    v6 = v2;
    v5 = (float)this[21];
    v4 = (float)this[25];
    v3 = (float)this[26];
    sub_593B30((int)this, v3, v4, v5, v6, 1);
  }
}
