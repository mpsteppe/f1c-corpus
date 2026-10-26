// f1c  0x004bba90  size=463
char __thiscall sub_4BBA90(float *this, const char *a2, float a3)
{
  int v4; // eax
  int v5; // eax
  char v6; // cl
  int v7; // eax
  int v8; // eax
  char v9; // cl
  char v11[63]; // [esp+8h] [ebp-140h] BYREF
  char v12; // [esp+47h] [ebp-101h]
  char v13[63]; // [esp+48h] [ebp-100h] BYREF
  char v14; // [esp+87h] [ebp-C1h]
  _BYTE v15[192]; // [esp+88h] [ebp-C0h] BYREF

  v4 = *((_DWORD *)this + 12);
  if ( !v4 )
  {
    if ( a2 )
    {
      v4 = *(_DWORD *)this;
      if ( !*(_DWORD *)(*(_DWORD *)this + 13000) )
      {
        if ( byte_7D0B10 )
        {
          if ( sub_423A00(byte_5EC4C0, aFinedUs, byte_5EC4CC) )
          {
            v5 = 0;
            do
            {
              v6 = aFinedUs[v5];
              byte_5EC4CC[v5++] = v6;
            }
            while ( v6 );
          }
          sub_587DD0(v11, byte_5EC4CC, 63);
          v12 = 0;
          if ( sub_423A00(byte_5EC4C0, a2, byte_5EC4CC) )
            strcpy(byte_5EC4CC, a2);
          sub_587DD0(v13, byte_5EC4CC, 63);
          v14 = 0;
          v7 = sub_587BDC(a3);
          sub_58815F(v15, "%s%d %s", v11, v7, v13);
        }
        else
        {
          if ( sub_423A00(byte_5EC4C0, aPenalty, byte_5EC4CC) )
          {
            v8 = 0;
            do
            {
              v9 = aPenalty[v8];
              byte_5EC4CC[v8++] = v9;
            }
            while ( v9 );
          }
          sub_587DD0(v11, byte_5EC4CC, 63);
          v12 = 0;
          if ( sub_423A00(byte_5EC4C0, a2, byte_5EC4CC) )
            strcpy(byte_5EC4CC, a2);
          sub_587DD0(v13, byte_5EC4CC, 63);
          v14 = 0;
          sub_58815F(v15, "%s %s", v11, v13);
        }
        LOBYTE(v4) = sub_45BD10(&dword_7CD204, (int)v15, 3, 16909060);
      }
    }
    this[41] = a3 + this[41];
  }
  return v4;
}
