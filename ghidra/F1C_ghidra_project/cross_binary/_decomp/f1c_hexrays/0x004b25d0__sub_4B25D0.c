// f1c  0x004b25d0  size=242
int __thiscall sub_4B25D0(int this, float *a2)
{
  __int16 v3; // ax
  __int16 v4; // ax
  int result; // eax
  int v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]

  if ( *a2 <= 6.3499999 )
  {
    if ( *a2 >= -6.3499999 )
    {
      v7 = *a2 * 20.0;
      v3 = (int)v7;
    }
    else
    {
      LOBYTE(v3) = -127;
    }
  }
  else
  {
    LOBYTE(v3) = 127;
  }
  *(_BYTE *)(this + 36) = v3;
  if ( a2[1] <= 65.533997 )
  {
    if ( a2[1] >= -65.533997 )
    {
      v8 = a2[1] * 500.0;
      v4 = (int)v8;
    }
    else
    {
      v4 = -32767;
    }
  }
  else
  {
    v4 = 0x7FFF;
  }
  *(_WORD *)(this + 38) = v4;
  if ( a2[2] <= 6.3499999 )
  {
    if ( a2[2] >= -6.3499999 )
    {
      v9 = a2[2] * 20.0;
      v6 = (int)v9;
      result = (__int16)v6;
      *(_BYTE *)(this + 37) = v6;
    }
    else
    {
      result = -127;
      *(_BYTE *)(this + 37) = -127;
    }
  }
  else
  {
    result = 127;
    *(_BYTE *)(this + 37) = 127;
  }
  return result;
}
