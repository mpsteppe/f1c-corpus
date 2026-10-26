int __thiscall sub_421180(_DWORD *this)
{
  int v1; // ebx
  int v3; // eax
  _DWORD *v4; // ebp
  double v5; // st7
  signed int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int result; // eax

  v1 = 0;
  v3 = this[20];
  this[6169] = -1082130432;
  *(_BYTE *)this = 0;
  this[3] = 0;
  this[6192] = -1082130432;
  this[5936] = 1056964608;
  this[1] = *(_DWORD *)(v3 + 16584);
  this[5907] = 1084227584;
  this[5909] = 1084227584;
  this[9] = 1120403456;
  this[5911] = 1120403456;
  this[5915] = 1120403456;
  this[5908] = -1063256064;
  this[5910] = -1063256064;
  this[5912] = -1027080192;
  this[5916] = -1027080192;
  v4 = this + 5314;
  this[5939] = 0;
  *((_BYTE *)this + 16) = 0;
  this[5900] = 0;
  this[6182] = -1082130432;
  *((_BYTE *)this + 23712) = 0;
  this[6074] = -1082130432;
  this[6189] = -1;
  this[6190] = -1082130432;
  this[6176] = 0;
  this[5932] = 0;
  *((_BYTE *)this + 32) = 0;
  this[6181] = 0;
  this[5314] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[6185] = -1082130432;
  this[6125] = 7;
  this[6172] = 0;
  this[5901] = 1176255488;
  flt_5FD0F0 = -1.0;
  this[5950] = 1;
  this[5951] = 1;
  this[5952] = 1;
  this[5953] = 1;
  this[15] = -1082130432;
  this[5948] = -1082130432;
  this[5949] = -1082130432;
  *((_BYTE *)this + 56) = 0;
  this[5926] = 0;
  this[2] = 0;
  this[6180] = 2139095039;
  this[6072] = -1;
  *((_BYTE *)this + 24293) = 0;
  this[6175] = 1065353216;
  this[6178] = 0;
  this[6179] = 0;
  this[5931] = 0;
  this[6174] = 0;
  this[6038] = 0;
  this[6039] = 1065353216;
  this[6040] = 1065353216;
  this[6033] = -1082130432;
  this[6034] = -1082130432;
  this[6035] = -1082130432;
  this[6036] = -1082130432;
  v5 = (double)(rand() % 30) + dbl_7DA9D0;
  this[16] = 2139095039;
  this[5959] = 0;
  this[5961] = 0;
  this[5960] = 1148829696;
  this[6159] = -1;
  *((float *)this + 6037) = v5 + 30.0;
  this[5938] = 0;
  this[5934] = 0;
  this[6053] = 0;
  this[5955] = 0;
  sub_428020(this);
  this[5933] = 0;
  v6 = 0;
  if ( (int)NumOfElements > 0 )
  {
    v7 = this + 5480;
    do
    {
      *(v7 - 6) = 0;
      *v7 = 0;
      ++v6;
      v7 += 8;
    }
    while ( v6 < (int)NumOfElements );
  }
  v8 = 5;
  do
  {
    *v4 = 0;
    v4 += 32;
    --v8;
  }
  while ( v8 );
  this[5967] = 1232348144;
  sub_427F60(999999);
  this[6058] = 3;
  *((_BYTE *)this + 24236) = 0;
  this[6060] = 0;
  if ( dword_75CBB0 == 7 || (v9 = this[5902]) == 0 )
  {
    this[6062] = 1;
    this[6061] = 1;
    this[5903] = 1;
  }
  else
  {
    v10 = *(_DWORD *)(v9 + 100);
    this[6062] = v10;
    this[6061] = v10;
    this[5903] = v10;
  }
  this[6063] = 1065353216;
  this[6064] = 50;
  *((float *)this + 6012) = (double)(rand() % 8) + 2.0;
  v11 = rand();
  this[6014] = 1048576000;
  this[6015] = 1048576000;
  this[5904] = -1082130432;
  this[5980] = -1;
  this[5958] = 0;
  this[5899] = 0;
  this[6006] = 0;
  *((float *)this + 6013) = (double)(v11 % 50) * 0.0099999998 + 0.1;
  sub_42C0F0(11);
  this[6168] = 1232348144;
  sub_421590(0, 0);
  sub_423870(this);
  *((_BYTE *)this + 24492) = 0;
  this[6007] = 1140457472;
  memset(this + 6016, 0xFFu, 0x20u);
  if ( dword_75CBB0 == 7
    || this[4146] != 1
    || (unsigned __int8)sub_42DBC0(&unk_62BF64) && (unsigned __int8)sub_4EED40(this[20]) )
  {
    sub_4EEC20(1);
    sub_4EEC50(1);
    result = sub_4EECE0(1);
  }
  else
  {
    sub_51C180(this + 21);
    sub_4EEC20(0);
    sub_4EEC50(0);
    result = sub_4EECE0(0);
  }
  do
  {
    HIWORD(this[v1 + 6075]) = 1;
    LOWORD(this[v1++ + 6075]) = 1;
  }
  while ( v1 < 48 );
  return result;
}
