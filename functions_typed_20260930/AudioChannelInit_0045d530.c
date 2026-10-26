_DWORD *__thiscall sub_45D530(_DWORD *this, int a2)
{
  char *v3; // edi
  int v4; // ebp
  char *v5; // edi
  int v6; // ebp

  FAILWRONGDESCRIPTION(this + 13);
  this[45] = 0;
  this[46] = -1;
  this[47] = 0;
  this[48] = -1;
  v3 = (char *)(this + 229);
  v4 = 104;
  do
  {
    ThunkToFUN00461480(v3);
    v3 += 140;
    --v4;
  }
  while ( v4 );
  this[4079] = off_59F0CC;
  this[4080] = 0;
  this[4082] = 0;
  this[4083] = 0;
  this[4084] = 0;
  this[4085] = 0;
  v5 = (char *)(this + 4192);
  v6 = 104;
  do
  {
    PassthroughWrapper_f670(v5);
    v5 += 872;
    --v6;
  }
  while ( v6 );
  WrapperWithConstant(this + 26864);
  ZeroInit5FloatStruct(this + 28117);
  this[28124] = 0;
  this[28125] = 0;
  this[28126] = 0;
  this[28127] = 0;
  this[28128] = 0;
  this[28129] = 0;
  this[28130] = 0;
  this[28131] = 0;
  StructInitializer_cd50((_BYTE *)this + 112528);
  *this = a2;
  this[2] = 0;
  *((float *)this + 1) = 1.0 / 24.0;
  this[3] = 1097859072;
  this[4] = 1097859072;
  *((_BYTE *)this + 20) = 0;
  this[6] = 0;
  this[7] = 0;
  *((_BYTE *)this + 32) = 0;
  *((_BYTE *)this + 33) = 0;
  this[9] = 1106247680;
  *((_BYTE *)this + 40) = 0;
  *((_BYTE *)this + 41) = 1;
  this[11] = -1082130432;
  *((_BYTE *)this + 48) = 0;
  *((_BYTE *)this + 196) = 1;
  *((_BYTE *)this + 197) = 0;
  *((_BYTE *)this + 198) = 0;
  *((_BYTE *)this + 199) = 0;
  *((_BYTE *)this + 200) = 0;
  *((_BYTE *)this + 284) = 0;
  *((_BYTE *)this + 364) = 0;
  this[107] = -1;
  *((_BYTE *)this + 432) = 0;
  this[116] = 0;
  BufferFillWith0xFFFFFFFF(this);
  *((_BYTE *)this + 884) = 0;
  this[222] = 0;
  this[223] = 0;
  this[224] = 0;
  this[225] = 0;
  this[226] = 0;
  this[227] = 0;
  this[228] = 0;
  this[3973] = 0;
  this[4078] = 0;
  this[4081] = 0;
  *((_BYTE *)this + 16345) = 0;
  *((_BYTE *)this + 112488) = 0;
  *((_BYTE *)this + 112489) = 0;
  *((_BYTE *)this + 112490) = 0;
  *((_BYTE *)this + 112491) = 0;
  *((_BYTE *)this + 112492) = 0;
  *((_BYTE *)this + 112493) = 0;
  *((_BYTE *)this + 112494) = 0;
  *((_BYTE *)this + 16344) = 8;
  return this;
}

