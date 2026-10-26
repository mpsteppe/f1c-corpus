int __thiscall sub_55A500(void *this, int a2, _DWORD *a3)
{
  _DWORD *v3; // ebx
  int v4; // ebp
  float v6; // esi
  int v7; // [esp+10h] [ebp-58h]
  int v8; // [esp+14h] [ebp-54h] BYREF
  int v9; // [esp+18h] [ebp-50h] BYREF
  int v10; // [esp+1Ch] [ebp-4Ch] BYREF
  int v11; // [esp+20h] [ebp-48h] BYREF
  int v12; // [esp+24h] [ebp-44h] BYREF
  int v13; // [esp+28h] [ebp-40h] BYREF
  float v14; // [esp+2Ch] [ebp-3Ch] BYREF
  int v15; // [esp+30h] [ebp-38h] BYREF
  int v16; // [esp+34h] [ebp-34h] BYREF
  int v17; // [esp+38h] [ebp-30h] BYREF
  float v18[2]; // [esp+3Ch] [ebp-2Ch] BYREF
  float v19; // [esp+44h] [ebp-24h] BYREF
  char v20[16]; // [esp+48h] [ebp-20h] BYREF
  char v21[16]; // [esp+58h] [ebp-10h] BYREF

  v3 = a3;
  LODWORD(v18[1]) = this;
  v7 = 0;
  v4 = 1;
  v12 = 0;
  v13 = 0;
  v14 = 0.0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v11 = 1120403456;
  v18[0] = 1.0;
  while ( LineReaderFromBuffer(v3) != 1 )
  {
    if ( *v3 == 3 )
      break;
    if ( *v3 != 2 )
    {
      sub_559E20((int)v3, (int)aType, v20, 0);
      PRNG4UniformFloatsFromSeed(v3, (int)&off_5DC230, (float *)&v10, (float *)&v9, (float *)&v8, 0);
      PRNG4UniformFloatsFromSeed(v3, (int)aDir, &v14, (float *)&v13, (float *)&v12, 0);
      sub_559F00(v3, (int)aColor, &v15, &v16, &v17, 0);
      PRNG4UniformFloatsFromSeed(v3, (int)aRange, &v19, (float *)&v11, 0, 0);
      PRNG4UniformFloatsFromSeed(v3, (int)aIntensity, v18, 0, 0, 0);
      if ( sub_559E20((int)v3, (int)aActive, v21, 0) )
      {
        if ( !strcmp(v21, aTrue) )
        {
          v4 = 1;
        }
        else if ( !strcmp(v21, aFalse) )
        {
          v4 = 0;
        }
      }
    }
  }
  if ( !strcmp(v20, aDirectional) )
  {
    v7 = 1;
  }
  else if ( !strcmp(v20, aStaticomni) )
  {
    v7 = 4;
  }
  else if ( !strcmp(v20, aMovingomni) )
  {
    v7 = 2;
  }
  if ( sub_545430((int *)&a3, a2, v7) )
    return -1;
  if ( v7 == 1 )
  {
    sub_55D460(v14, v13, v12);
  }
  else if ( v7 == 2 || v7 == 4 )
  {
    SetUIPropertyGroupWithChainUpdate(v10, v9, v8);
    StateFieldSetterWithGlobalDirtyFlag(v11);
  }
  ByteExtractionFromUint(2, v17 | ((v16 | (v15 << 8)) << 8));
  v6 = v18[0];
  UIPropertyValueSetter(1, LODWORD(v18[0]));
  UIPropertyValueSetter(2, LODWORD(v6));
  UIPropertyValueSetter(3, LODWORD(v6));
  BitFlagSetterWithDXUpdate(v4);
  return 0;
}
