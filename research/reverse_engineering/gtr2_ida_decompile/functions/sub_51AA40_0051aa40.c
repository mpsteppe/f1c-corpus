int __thiscall sub_51AA40(_BYTE *this, char a2, __int16 a3, float a4, float a5)
{
  __int16 v6; // si
  int result; // eax
  float v8; // [esp+0h] [ebp-Ch]
  float v9; // [esp+0h] [ebp-Ch]

  if ( a4 >= 0.0 )
  {
    if ( a4 <= 1.0 )
    {
      v8 = a4 * 31.0;
      v6 = sub_4015C0(v8);
    }
    else
    {
      v6 = 31;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( a5 >= 0.25 )
  {
    if ( a5 <= 4.0 )
    {
      v9 = (a5 - 0.25) * 136.26666;
      result = sub_4015C0(v9);
    }
    else
    {
      result = 511;
    }
  }
  else
  {
    result = 0;
  }
  *(_WORD *)this = result + ((v6 + 32 * a3) << 9);
  this[2] = a2;
  return result;
}
