bool __thiscall sub_5DAF80(float *this, int a2, float *a3)
{
  float v4; // eax
  int v5; // edx
  char v6; // bl
  float *v7; // ecx
  double v8; // st7
  float v9; // eax
  float v11; // eax
  float v12; // ecx
  float v13[3]; // [esp+Ch] [ebp-Ch] BYREF

  if ( a3 )
  {
    v11 = *a3;
    if ( ((unsigned int)&dword_1000000 & *(_DWORD *)a3) != 0 )
      goto LABEL_25;
    v12 = *this;
    if ( (*(_DWORD *)this & 0x10) != 0 )
    {
      if ( SBYTE1(v12) < 0 )
      {
        *(_DWORD *)a3 = LODWORD(v11) | 1;
        goto LABEL_25;
      }
      if ( (BYTE1(v11) & 0x20) == 0 )
      {
        *(_DWORD *)a3 = LODWORD(v11) | 0x2000;
        sub_5D7810(a3 + 54, a3 + 57, this + 46);
      }
      if ( (sub_5EC2F0(a2, a3 + 57, 0) & 2) == 0 )
        goto LABEL_25;
      sub_5EC2A0(0);
    }
    else if ( (sub_5EC2F0(a2, a3 + 57, 0) & 2) == 0 )
    {
      goto LABEL_25;
    }
    sub_5EC450(a2);
LABEL_25:
    if ( (*(_DWORD *)a3 & 0x8000004) == 0x8000004 )
    {
      sub_5D7810(a3 + 54, v13, this + 80);
      sub_5EC2F0(a2, v13, 0);
      if ( (*(_BYTE *)a3 & 2) != 0 )
      {
        sub_5EC2A0(this + 79);
        sub_5EC450(a2);
      }
    }
    return (*(_BYTE *)a3 & 3) != 0;
  }
  v4 = *this;
  if ( (*(_DWORD *)this & 8) != 0 )
  {
    if ( (LOBYTE(v4) & 0x90) == 0x10 )
    {
      *(_DWORD *)this = dword_16C99E0 | LODWORD(v4);
      sub_5D7810(this + 3, this + 6, this + 46);
    }
    v5 = 0;
    v6 = 1;
    v7 = (float *)(a2 + 252);
    do
    {
      v8 = *(v7 - 1) * this[6] + v7[1] * this[8] + *v7 * this[7] + v7[2];
      if ( v8 > this[9] )
      {
        *(_DWORD *)this &= 0xFFFF7FFE;
        return 0;
      }
      if ( v8 > -this[9] )
        v6 = 0;
      ++v5;
      v7 += 4;
    }
    while ( v5 < 6 );
    v9 = *this;
    if ( v6 )
    {
      *(_DWORD *)this = LODWORD(v9) | 0x8001;
      return 1;
    }
    *(_DWORD *)this = LODWORD(v9) | 1;
  }
  return 1;
}
