char __thiscall sub_454350(int this, char *a2, _DWORD *a3, int a4)
{
  int i; // eax
  double v6; // st7
  int j; // eax
  double v8; // st7

  if ( a4 )
  {
    for ( i = 96;
          i < 128;
          *(float *)((char *)&unk_7CD168 + i - 100) = (v6 - *(float *)(i + this + 3460)) * *(float *)(i + this + 3428) )
    {
      v6 = *(float *)(i + this + 4288);
      i += 4;
    }
    for ( j = 96;
          j < 128;
          *(float *)((char *)&unk_7CCA8C + j - 100) = (v8 - *(float *)(j + this + 4480)) * *(float *)(j + this + 4448) )
    {
      v8 = *(float *)(j + this + 5308);
      j += 4;
    }
  }
  *a3 = -1;
  if ( ConstraintForceEval((char *)this, 0, 0, (int)&unk_7CD168) )
    *a3 = 1;
  if ( SweptAABBOverlapDetection((char *)this, 0, 0, (int)&unk_7CD168) )
    *a3 = 2;
  if ( ConstraintForceEval((char *)this, 1, 0, (int)&unk_7CD168) )
    *a3 = 3;
  if ( SweptAABBOverlapDetection((char *)this, 1, 0, (int)&unk_7CD168) )
    *a3 = 4;
  if ( ConstraintForceEval((char *)this, 2, 0, (int)&unk_7CD168) )
    *a3 = 5;
  if ( SweptAABBOverlapDetection((char *)this, 2, 0, (int)&unk_7CD168) )
    *a3 = 6;
  if ( ConstraintForceEval((char *)this, 3, 0, (int)&unk_7CD168) )
    *a3 = 7;
  if ( SweptAABBOverlapDetection((char *)this, 3, 0, (int)&unk_7CD168) )
    *a3 = 8;
  if ( ConstraintForceEval((char *)this, 4, 0, (int)&unk_7CD168) )
    *a3 = 9;
  if ( SweptAABBOverlapDetection((char *)this, 4, 0, (int)&unk_7CD168) )
    *a3 = 10;
  if ( ConstraintForceEval((char *)this, 5, 0, (int)&unk_7CD168) )
    *a3 = 11;
  if ( SweptAABBOverlapDetection((char *)this, 5, 0, (int)&unk_7CD168) )
    *a3 = 12;
  if ( ConstraintForceEval((char *)this, 6, 0, (int)&unk_7CD168) )
    *a3 = 102;
  if ( SweptAABBOverlapDetection((char *)this, 6, 0, (int)&unk_7CD168) )
    *a3 = 103;
  if ( ConstraintForceEval((char *)this, 7, 0, (int)&unk_7CD168) )
    *a3 = 104;
  if ( SweptAABBOverlapDetection((char *)this, 7, 0, (int)&unk_7CD168) )
    *a3 = 105;
  if ( *(_BYTE *)(this + 4448) )
    *a3 = 13;
  if ( *(_BYTE *)(this + 4449) )
    *a3 = 14;
  if ( *(_BYTE *)(this + 4450) )
    *a3 = 15;
  if ( *(_BYTE *)(this + 4451) )
    *a3 = 16;
  if ( *(_BYTE *)(this + 4452) )
    *a3 = 17;
  if ( *(_BYTE *)(this + 4453) )
    *a3 = 18;
  if ( *(_BYTE *)(this + 4454) )
    *a3 = 19;
  if ( *(_BYTE *)(this + 4455) )
    *a3 = 20;
  if ( *(_BYTE *)(this + 4456) )
    *a3 = 21;
  if ( *(_BYTE *)(this + 4457) )
    *a3 = 22;
  if ( *(_BYTE *)(this + 4458) )
    *a3 = 23;
  if ( *(_BYTE *)(this + 4459) )
    *a3 = 24;
  if ( *(_BYTE *)(this + 4460) )
    *a3 = 25;
  if ( *(_BYTE *)(this + 4461) )
    *a3 = 26;
  if ( *(_BYTE *)(this + 4462) )
    *a3 = 27;
  if ( *(_BYTE *)(this + 4463) )
    *a3 = 28;
  if ( *(char *)(this + 4480) < 0 )
  {
    if ( *(_DWORD *)(this + 4464) == dword_7CD1BC )
      *a3 = 70;
    if ( *(_DWORD *)(this + 4464) == dword_7CD1D4 )
      *a3 = 71;
    if ( *(_DWORD *)(this + 4464) == dword_7CCF5C )
      *a3 = 72;
    if ( *(_DWORD *)(this + 4464) == dword_7CD1EC )
      *a3 = 73;
    if ( (*(_DWORD *)(this + 4480) & 0x100) != 0 )
    {
      if ( *(_DWORD *)(this + 4468) == dword_7CD0AC )
        *a3 = 74;
      if ( *(_DWORD *)(this + 4468) == dword_7CD0C4 )
        *a3 = 75;
      if ( *(_DWORD *)(this + 4468) == dword_7CD12C )
        *a3 = 76;
      if ( *(_DWORD *)(this + 4468) == dword_7CD144 )
        *a3 = 77;
      if ( (*(_DWORD *)(this + 4480) & 0x200) != 0 )
      {
        if ( *(_DWORD *)(this + 4472) == dword_7CD018 )
          *a3 = 78;
        if ( *(_DWORD *)(this + 4472) == dword_7CD048 )
          *a3 = 79;
        if ( *(_DWORD *)(this + 4472) == dword_7CD0DC )
          *a3 = 80;
        if ( *(_DWORD *)(this + 4472) == dword_7CD0F4 )
          *a3 = 81;
        if ( (*(_DWORD *)(this + 4480) & 0x400) != 0 )
        {
          if ( *(_DWORD *)(this + 4476) == dword_7CCA10 )
            *a3 = 82;
          if ( *(_DWORD *)(this + 4476) == dword_7CCA40 )
            *a3 = 83;
          if ( *(_DWORD *)(this + 4476) == dword_7CD060 )
            *a3 = 84;
          if ( *(_DWORD *)(this + 4476) == dword_7CD078 )
            *a3 = 85;
        }
      }
    }
  }
  if ( ConstraintForceEval((char *)this, 0, 1, (int)&unk_7CCA8C) )
    *a3 = 30;
  if ( SweptAABBOverlapDetection((char *)this, 0, 1, (int)&unk_7CCA8C) )
    *a3 = 31;
  if ( ConstraintForceEval((char *)this, 1, 1, (int)&unk_7CCA8C) )
    *a3 = 32;
  if ( SweptAABBOverlapDetection((char *)this, 1, 1, (int)&unk_7CCA8C) )
    *a3 = 33;
  if ( ConstraintForceEval((char *)this, 2, 1, (int)&unk_7CCA8C) )
    *a3 = 34;
  if ( SweptAABBOverlapDetection((char *)this, 2, 1, (int)&unk_7CCA8C) )
    *a3 = 35;
  if ( ConstraintForceEval((char *)this, 3, 1, (int)&unk_7CCA8C) )
    *a3 = 36;
  if ( SweptAABBOverlapDetection((char *)this, 3, 1, (int)&unk_7CCA8C) )
    *a3 = 37;
  if ( ConstraintForceEval((char *)this, 4, 1, (int)&unk_7CCA8C) )
    *a3 = 38;
  if ( SweptAABBOverlapDetection((char *)this, 4, 1, (int)&unk_7CCA8C) )
    *a3 = 39;
  if ( ConstraintForceEval((char *)this, 5, 1, (int)&unk_7CCA8C) )
    *a3 = 40;
  if ( SweptAABBOverlapDetection((char *)this, 5, 1, (int)&unk_7CCA8C) )
    *a3 = 41;
  if ( ConstraintForceEval((char *)this, 6, 1, (int)&unk_7CCA8C) )
    *a3 = 106;
  if ( SweptAABBOverlapDetection((char *)this, 6, 1, (int)&unk_7CCA8C) )
    *a3 = 107;
  if ( ConstraintForceEval((char *)this, 7, 1, (int)&unk_7CCA8C) )
    *a3 = 108;
  if ( SweptAABBOverlapDetection((char *)this, 7, 1, (int)&unk_7CCA8C) )
    *a3 = 109;
  if ( *(_BYTE *)(this + 5468) )
    *a3 = 42;
  if ( *(_BYTE *)(this + 5469) )
    *a3 = 43;
  if ( *(_BYTE *)(this + 5470) )
    *a3 = 44;
  if ( *(_BYTE *)(this + 5471) )
    *a3 = 45;
  if ( *(_BYTE *)(this + 5472) )
    *a3 = 46;
  if ( *(_BYTE *)(this + 5473) )
    *a3 = 47;
  if ( *(_BYTE *)(this + 5474) )
    *a3 = 48;
  if ( *(_BYTE *)(this + 5475) )
    *a3 = 49;
  if ( *(_BYTE *)(this + 5476) )
    *a3 = 50;
  if ( *(_BYTE *)(this + 5477) )
    *a3 = 51;
  if ( *(_BYTE *)(this + 5478) )
    *a3 = 52;
  if ( *(_BYTE *)(this + 5479) )
    *a3 = 53;
  if ( *(_BYTE *)(this + 5480) )
    *a3 = 54;
  if ( *(_BYTE *)(this + 5481) )
    *a3 = 55;
  if ( *(_BYTE *)(this + 5482) )
    *a3 = 56;
  if ( *(_BYTE *)(this + 5483) )
    *a3 = 57;
  if ( *(char *)(this + 5500) < 0 )
  {
    if ( *(_DWORD *)(this + 5484) == dword_7CCFD8 )
      *a3 = 86;
    if ( *(_DWORD *)(this + 5484) == dword_7CD000 )
      *a3 = 87;
    if ( *(_DWORD *)(this + 5484) == dword_7CD094 )
      *a3 = 88;
    if ( *(_DWORD *)(this + 5484) == dword_7CD030 )
      *a3 = 89;
    if ( (*(_DWORD *)(this + 5500) & 0x100) != 0 )
    {
      if ( *(_DWORD *)(this + 5488) == dword_7CA548 )
        *a3 = 90;
      if ( *(_DWORD *)(this + 5488) == dword_7CA578 )
        *a3 = 91;
      if ( *(_DWORD *)(this + 5488) == dword_7CCA28 )
        *a3 = 92;
      if ( *(_DWORD *)(this + 5488) == dword_7CCA68 )
        *a3 = 93;
      if ( (*(_DWORD *)(this + 5500) & 0x200) != 0 )
      {
        if ( *(_DWORD *)(this + 5492) == dword_7CA4CC )
          *a3 = 94;
        if ( *(_DWORD *)(this + 5492) == dword_7CA4F4 )
          *a3 = 95;
        if ( *(_DWORD *)(this + 5492) == dword_7CA560 )
          *a3 = 96;
        if ( *(_DWORD *)(this + 5492) == dword_7CA530 )
          *a3 = 97;
        if ( (*(_DWORD *)(this + 5500) & 0x400) != 0 )
        {
          if ( *(_DWORD *)(this + 5496) == dword_7CA434 )
            *a3 = 98;
          if ( *(_DWORD *)(this + 5496) == dword_7CA40C )
            *a3 = 99;
          if ( *(_DWORD *)(this + 5496) == dword_7CA4B4 )
            *a3 = 100;
          if ( *(_DWORD *)(this + 5496) == dword_7CA46C )
          {
            *a3 = 101;
LABEL_207:
            strcpy(a2, &aEmpty[9 * *a3]);
            return 1;
          }
        }
      }
    }
  }
  if ( *a3 != -1 )
    goto LABEL_207;
  return 0;
}
