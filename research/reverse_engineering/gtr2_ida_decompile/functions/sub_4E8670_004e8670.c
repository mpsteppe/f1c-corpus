int __thiscall sub_4E8670(int *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ecx
  char *v3; // ecx
  int result; // eax
  int v6; // eax
  int v7; // edi
  double v8; // st7
  int v9; // eax
  char *v10; // [esp+0h] [ebp-24h] BYREF
  float v11; // [esp+4h] [ebp-20h]
  int v12; // [esp+10h] [ebp-14h]
  char Format[16]; // [esp+14h] [ebp-10h] BYREF

  result = this[114];
  if ( result )
  {
    if ( this[109] )
    {
      v6 = this[110];
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          v7 = this[1];
        }
        else if ( v6 == 2 )
        {
          v7 = *this;
        }
        else
        {
          v7 = v12;
        }
      }
      else
      {
        v7 = this[2];
      }
      sub_4E6210((int)"UV", this[112], this[113], v7, this[3], this[111]);
    }
    else
    {
      v7 = v12;
    }
    if ( byte_B72478 )
      v8 = sub_4E4DE0();
    else
      v8 = sub_4E4E20();
    v11 = v8;
    v11 = COERCE_FLOAT(sub_4015C0(v11));
    v10 = Format;
    v1 = __readeflags();
    v2 = dword_16C6F34 + 1413745333;
    __writeeflags(v1);
    v3 = (char *)_InterlockedExchange((volatile __int32 *)&v10, v2);
    sprintf(v3, v10);
    v9 = this[115];
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        v7 = this[1];
      }
      else if ( v9 == 2 )
      {
        v7 = *this;
      }
    }
    else
    {
      v7 = this[2];
    }
    return sub_4E6210((int)Format, this[117], this[118], v7, this[3], this[116]);
  }
  return result;
}
