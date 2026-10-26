int __thiscall sub_428C90(char *this, int a2)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // ebp
  int v8; // ecx
  _DWORD *v9; // edx
  int v10; // edx
  bool v11; // zf
  int v12; // ecx
  int v13; // edx
  char *v14; // eax
  _DWORD *v16; // edi
  double v17; // st7
  double v18; // st7
  double v19; // st7
  float v20[2]; // [esp+20h] [ebp-28h] BYREF
  float v21; // [esp+28h] [ebp-20h]
  int v22; // [esp+2Ch] [ebp-1Ch]
  float retaddr; // [esp+48h] [ebp+0h]

  v2 = 0;
  this[20416] = 0;
  this[19652] = 0;
  *((_DWORD *)this + 5141) = 0;
  *((_DWORD *)this + 5190) = 0;
  *((_DWORD *)this + 5189) = 0;
  dword_91DC44 = 0;
  *((_DWORD *)this + 5191) = 0;
  *((_DWORD *)this + 5110) = 0;
  *((_DWORD *)this + 4925) = 2139095039;
  *((_DWORD *)this + 5015) = -998653952;
  *((_DWORD *)this + 5022) = -998653952;
  *((_DWORD *)this + 5029) = -998653952;
  *((_DWORD *)this + 5036) = -998653952;
  *((_DWORD *)this + 5043) = -998653952;
  *((_DWORD *)this + 5012) = 0;
  *((_DWORD *)this + 4926) = 0;
  *((_DWORD *)this + 5019) = 0;
  *((_DWORD *)this + 4943) = 0;
  *((_DWORD *)this + 5026) = 0;
  *((_DWORD *)this + 4960) = 0;
  *((_DWORD *)this + 5033) = 0;
  *((_DWORD *)this + 4977) = 0;
  *((_DWORD *)this + 5040) = 0;
  *((_DWORD *)this + 4994) = 0;
  *((_DWORD *)this + 4939) = 1232348144;
  *((_DWORD *)this + 4956) = 1232348144;
  *((_DWORD *)this + 4973) = 1232348144;
  *((_DWORD *)this + 4990) = 1232348144;
  *((_DWORD *)this + 5007) = 1232348144;
  *((_DWORD *)this + 4942) = -1;
  *((_DWORD *)this + 5011) = -1;
  *((_DWORD *)this + 5013) = -1;
  *((_DWORD *)this + 4959) = -1;
  *((_DWORD *)this + 5018) = -1;
  *((_DWORD *)this + 5020) = -1;
  *((_DWORD *)this + 4976) = -1;
  *((_DWORD *)this + 5025) = -1;
  *((_DWORD *)this + 5027) = -1;
  *((_DWORD *)this + 4993) = -1;
  *((_DWORD *)this + 5032) = -1;
  *((_DWORD *)this + 5034) = -1;
  *((_DWORD *)this + 5010) = -1;
  *((_DWORD *)this + 5039) = -1;
  *((_DWORD *)this + 5041) = -1;
  *((_DWORD *)this + 5129) = 2139095039;
  *((_DWORD *)this + 5130) = 2139095039;
  this[20888] = 1;
  *((_DWORD *)this + 5114) = 0;
  *((_DWORD *)this + 5197) = 0;
  *((_DWORD *)this + 5128) = 0;
  *((_DWORD *)this + 5131) = 0;
  *((_DWORD *)this + 5132) = 0;
  *((_DWORD *)this + 5133) = 0;
  *((_DWORD *)this + 5122) = 0;
  *((_DWORD *)this + 5134) = 1065353216;
  *((_DWORD *)this + 5135) = 1065353216;
  *((_DWORD *)this + 5127) = -1082130432;
  *((_DWORD *)this + 5046) = 0;
  *((_DWORD *)this + 5047) = 0;
  *((_DWORD *)this + 5048) = 0;
  *((_DWORD *)this + 5049) = 0;
  *((_DWORD *)this + 5050) = 0;
  *((_DWORD *)this + 5051) = 0;
  *((_DWORD *)this + 5052) = 0;
  *((_DWORD *)this + 5053) = 0;
  *((_DWORD *)this + 5054) = 0;
  *((_DWORD *)this + 5055) = 0;
  *((_DWORD *)this + 5056) = 0;
  *((_DWORD *)this + 5057) = 0;
  *((_DWORD *)this + 5058) = 0;
  *((_DWORD *)this + 5059) = 0;
  *((_DWORD *)this + 5060) = 0;
  *((_DWORD *)this + 5061) = 0;
  *((_DWORD *)this + 5062) = 0;
  *((_DWORD *)this + 5063) = 0;
  *((_DWORD *)this + 5064) = 0;
  *((_DWORD *)this + 5065) = 0;
  v4 = *((_DWORD *)this + 4293);
  *((_DWORD *)this + 5208) = 1065353216;
  *((_DWORD *)this + 5177) = 1065353216;
  *((_DWORD *)this + 5166) = 1065353216;
  v5 = -*((_DWORD *)this + 1);
  v22 = v5;
  *((_DWORD *)this + 5144) = 1232348144;
  *((_DWORD *)this + 5207) = 1232348144;
  *((_DWORD *)this + 5390) = 1232348144;
  *((_DWORD *)this + 5381) = 0;
  *((float *)this + 5124) = (double)v5 * 7.0;
  *((_DWORD *)this + 5113) = 0;
  *((_DWORD *)this + 5209) = 1086324736;
  *((_DWORD *)this + 5210) = 1;
  this[20844] = 0;
  *((_DWORD *)this + 5215) = 0;
  *((_DWORD *)this + 5160) = v4;
  *((_DWORD *)this + 5212) = 0;
  *((_DWORD *)this + 5213) = 0;
  *((_DWORD *)this + 5192) = 0;
  *((_DWORD *)this + 5214) = 50;
  *((_DWORD *)this + 5216) = 0;
  *((_DWORD *)this + 5217) = 0;
  *((_DWORD *)this + 5118) = 0;
  *((_DWORD *)this + 5091) = -1082130432;
  *((_DWORD *)this + 5125) = -1;
  *((_DWORD *)this + 5155) = -1;
  *((_DWORD *)this + 5137) = 0;
  this[21516] = 0;
  if ( !(_BYTE)a2 )
  {
    v16 = this + 21528;
    do
      *v16++ = sub_4FC310(this + 14824, v2++);
    while ( v2 < 8 );
    *((_DWORD *)this + 4912) = 2139095039;
    v17 = flt_91BDC4;
    retaddr = *(float *)&dword_91BDC0;
    if ( dword_B71FD8 > 100 )
    {
      retaddr = (double)(dword_B71FD8 - 100) * 0.050000001 * (flt_91BDC8 - v17) + v17;
    }
    else
    {
      LODWORD(v21) = dword_B71FD8 - 70;
      retaddr = (double)(dword_B71FD8 - 70) * 0.033333335 * (v17 - retaddr) + retaddr;
    }
    v21 = 0.0;
    v18 = sub_552900(&unk_FADD40);
    if ( v18 > 72000.0 || v18 < 14400.0 )
      v21 = 0.02;
    if ( *(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4 )
    {
      v19 = flt_91BDCC;
    }
    else
    {
      if ( *(_DWORD *)dword_B640C8 != 6 )
        return sub_57EFB0(retaddr);
      v19 = flt_91BDD0;
    }
    retaddr = (v19 - v21) * retaddr;
    return sub_57EFB0(retaddr);
  }
  *((_DWORD *)this + 5201) = 0;
  *((_DWORD *)this + 4914) = -1;
  *((_DWORD *)this + 4916) = -1;
  *((_DWORD *)this + 4918) = -1;
  *((_DWORD *)this + 4920) = -1;
  *((_DWORD *)this + 4922) = -1;
  sub_423790();
  sub_420480();
  if ( *((_DWORD *)this + 5153) )
    j_j__free(*((void **)this + 5153));
  *((_DWORD *)this + 5154) = 10;
  v6 = operator new(0x50u);
  *((_DWORD *)this + 5153) = v6;
  if ( v6 )
  {
    v7 = *((_DWORD *)this + 5155);
    v8 = 0;
    if ( v7 < 0 )
    {
LABEL_9:
      v10 = *((_DWORD *)this + 5154);
      *((_DWORD *)this + 5155) = v7 + 1;
      if ( v7 + 1 < v10 )
      {
        v6[2 * v7 + 2] = 0;
        *(_DWORD *)(*((_DWORD *)this + 5153) + 8 * *((_DWORD *)this + 5155) + 4) = 0;
        sub_427710((int)this);
        v11 = *((_DWORD *)this + 4845) == 2;
        *((_DWORD *)this + 5155) = -1;
        if ( v11 )
          this[21516] = 0;
      }
      else
      {
        *((_DWORD *)this + 5155) = v7;
      }
    }
    else
    {
      v9 = v6;
      while ( *v9 )
      {
        ++v8;
        v9 += 2;
        if ( v8 > *((_DWORD *)this + 5155) )
          goto LABEL_9;
      }
    }
  }
  *((_DWORD *)this + 5122) = 0;
  *((_DWORD *)this + 5155) = -1;
  *((_DWORD *)this + 5380) = 0;
  v12 = 0;
  if ( dword_757C10 > 0 )
  {
    v13 = *(_DWORD *)this;
    do
    {
      v14 = (char *)*(&dword_91E088 + v12);
      if ( *(_DWORD *)(v13 + 22548) == *((_DWORD *)v14 + 5637) && v14 != this )
        *((_DWORD *)this + 5380) = v14;
      ++v12;
    }
    while ( v12 < dword_757C10 );
  }
  *((_DWORD *)this + 2) = dword_91BCB4 + *(_DWORD *)(*(_DWORD *)this + 22548);
  sub_401410();
  sub_403390(v20, 0, *((_DWORD *)this + 2), 0);
  return off_16C9238(a2);
}
