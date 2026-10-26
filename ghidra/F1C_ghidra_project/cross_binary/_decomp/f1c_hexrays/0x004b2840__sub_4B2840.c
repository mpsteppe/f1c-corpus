// f1c  0x004b2840  size=175
int __thiscall sub_4B2840(_BYTE *this, int a2, float a3, float a4)
{
  char v4; // al
  int result; // eax
  float v6; // [esp+Ch] [ebp+8h]
  float v7; // [esp+Ch] [ebp+8h]
  int v8; // [esp+10h] [ebp+Ch]

  if ( a3 <= 0.49599999 )
  {
    if ( a3 >= -0.49599999 )
    {
      v6 = a3 * 256.0;
      v4 = (int)v6;
    }
    else
    {
      v4 = -127;
    }
  }
  else
  {
    v4 = 127;
  }
  this[a2 + 18] = v4;
  if ( a4 <= 327.67001 )
  {
    if ( a4 >= -327.67001 )
    {
      v7 = a4 * 100.0;
      v8 = (int)v7;
      result = (__int16)v8;
      *(_WORD *)&this[2 * a2 + 22] = v8;
    }
    else
    {
      result = -32767;
      *(_WORD *)&this[2 * a2 + 22] = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    *(_WORD *)&this[2 * a2 + 22] = 0x7FFF;
  }
  return result;
}
