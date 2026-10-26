// AIDriverStructInit: Initializes this[4430] (+0x4538)=999999.0f (abs max speed sentinel), this[4431] (+0x453C)=1.0f (speed multiplier). These are defaults, not runtime recalculations.
int __thiscall sub_424790(int *this, float a2)
{
  int v2; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  _DWORD *v12; // edi
  int v14; // [esp+10h] [ebp-1Ch]
  const char *v15; // [esp+10h] [ebp-1Ch]
  float v16[3]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v17[3]; // [esp+20h] [ebp-Ch] BYREF
  int v18; // [esp+30h] [ebp+4h]
  float v19; // [esp+30h] [ebp+4h]

  v2 = 0;
  *((_BYTE *)this + 17424) = 0;
  *((_BYTE *)this + 16704) = 0;
  this[4383] = 0;
  this[4418] = 0;
  this[4419] = 0;
  this[4360] = 0;
  this[4188] = 2139095039;
  v4 = this + 4278;
  v5 = this + 4205;
  v6 = 5;
  do
  {
    *(v5 - 3) = 1232348144;
    *(v4 - 3) = 0;
    *v5 = -1;
    *(v5 - 16) = 0;
    *v4 = -998653952;
    *(v4 - 4) = -1;
    *(v4 - 2) = -1;
    v5 += 17;
    v4 += 7;
    --v6;
  }
  while ( v6 );
  *((_BYTE *)this + 17784) = 1;
  this[4364] = 0;
  this[4425] = 0;
  this[4376] = -1082130432;
  this[4377] = 1065353216;
  this[4371] = 0;
  AIClearStateFlags(this);
  v14 = -this[1];
  this[4397] = this[3675];
  this[4431] = 1065353216;
  this[4437] = 1065353216;
  this[4414] = 1065353216;
  this[4403] = 1065353216;
  *((float *)this + 4373) = (double)v14 * 7.0;
  this[4479] = 0;
  this[4363] = 0;
  this[4385] = 1232348144;
  this[4430] = 1232348144;
  this[4432] = 1086324736;
  this[4433] = 1;
  *((_BYTE *)this + 17736) = 0;
  this[4439] = 0;
  this[4435] = 0;
  this[4436] = 0;
  this[4420] = 0;
  this[4438] = 50;
  this[4440] = 0;
  this[4441] = 0;
  this[4367] = 0;
  this[4353] = -1082130432;
  this[4374] = -1;
  this[4396] = -1;
  this[4379] = 0;
  this[4350] = 0;
  *((_BYTE *)this + 17908) = 0;
  this[4487] = 1232348144;
  if ( LOBYTE(a2) )
  {
    this[4429] = 0;
    v7 = this + 4177;
    v8 = 5;
    do
    {
      *v7 = -1;
      v7 += 2;
      --v8;
    }
    while ( v8 );
    sub_424080((char *)this);
    if ( this[4394] )
      FreeWrapper_7bcf((LPVOID)this[4394]);
    this[4395] = 10;
    this[4394] = OperatorNewNhMallocWrapper(80);
    AICommandMessageQueueDispatcher(0, 0);
    this[4371] = 0;
    this[4396] = -1;
    this[4478] = 0;
    v9 = 0;
    v18 = 0;
    if ( dword_5C329C > 0 )
    {
      v15 = (const char *)(*this + 18104);
      do
      {
        v10 = dword_7C54F0[v9];
        if ( !strcmp(v15, (const char *)(v10 + 18104)) && (int *)v10 != this )
          this[4478] = v10;
        v9 = ++v18;
      }
      while ( v18 < dword_5C329C );
    }
    v11 = *this;
    this[2] = dword_5EA2D0 + *(_DWORD *)(*this + 18596);
    ArrayOfStructIndexedFieldCopy(dword_5EA2C0, *(_DWORD *)(v11 + 18596), v16, v17);
    this[4352] = SpatialTreeNearestNeighborSearch(dword_5EA2C0, v16, 0, this[2], 0);
    sub_429960(this);
  }
  v12 = this + 4480;
  do
    *v12++ = GuardedCallWithCheck(v2++);
  while ( v2 < 7 );
  this[4175] = 2139095039;
  v19 = AIDifficultyInterpolation();
  if ( dword_7C56A4 != 3 && dword_7C56A4 != 4 && dword_7C56A4 != 5 )
    v19 = flt_5EA3E8 * v19;
  return ScaleAudioPitch(v19);
}
