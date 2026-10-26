int __thiscall sub_4CDD80(int this, int a2, int a3)
{
  _DWORD *v4; // edi
  int v5; // eax
  int result; // eax
  char *v7; // edx
  char v8; // al
  char *v9; // eax
  char v10; // cl
  char *v11; // eax
  char v12; // cl
  float v13; // [esp+10h] [ebp-108h] BYREF
  int v14; // [esp+14h] [ebp-104h] BYREF
  CHAR SrcStr; // [esp+18h] [ebp-100h] BYREF
  char v16; // [esp+19h] [ebp-FFh] BYREF

  if ( sub_565520(aLegal, &SrcStr, 0) && !sub_588410(&SrcStr, aTrue) )
    *(_BYTE *)(this + 96) = 1;
  v4 = (_DWORD *)(this + 8);
  v13 = 0.0;
  if ( sub_4CDC70(a2, (int)&off_5D38EC, (float *)(this + 8), a3) )
    *(_DWORD *)(this + 12) = *v4;
  if ( sub_4CDC70(a2, (int)aWet, &v13, a3) )
    *(float *)(this + 12) = *(float *)v4 - v13;
  sub_4CDC70(a2, (int)aResistance, (float *)(this + 16), a3);
  if ( sub_4CDC70(a2, (int)aBumpamp, (float *)(this + 20), a3) )
    *(float *)(this + 20) = *(float *)(this + 20) * 0.25;
  if ( sub_4CDC70(a2, (int)aBumpwavelen, &v13, a3) )
  {
    if ( v13 < 3.0 )
      v13 = 3.0;
    *(float *)(this + 24) = 6.283185307179586 / v13;
  }
  sub_4CDC70(a2, (int)aSpring_0, (float *)(this + 28), a3);
  sub_4CDC70(a2, (int)aDamper, (float *)(this + 32), a3);
  sub_4CDC70(a2, (int)aCollfrict, (float *)(this + 36), a3);
  sub_565760(aSparks, this + 40, 0, 0, 0);
  if ( sub_565760(aScraping, &v14, 0, 0, 0) )
    *(_BYTE *)(this + 44) = v14 != 0;
  if ( sub_4CDC70(a2, (int)aSink, &v13, a3) )
    *(double *)(this + 100) = v13;
  if ( sub_565520(aSound, &SrcStr, 0) )
  {
    if ( !strcmp(&SrcStr, (const char *)&off_5D38EC) )
    {
      *(_DWORD *)(this + 48) = 6;
      *(_DWORD *)(this + 52) = 21;
      *(_DWORD *)(this + 56) = 27;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aWet) )
    {
      *(_DWORD *)(this + 48) = 7;
      *(_DWORD *)(this + 52) = 22;
      *(_DWORD *)(this + 56) = 27;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aDirt) )
    {
      *(_DWORD *)(this + 48) = 9;
      *(_DWORD *)(this + 52) = 24;
      *(_DWORD *)(this + 56) = 32;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aGrass) )
    {
      *(_DWORD *)(this + 48) = 8;
      *(_DWORD *)(this + 52) = 23;
      *(_DWORD *)(this + 56) = 32;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aGravel) )
    {
      *(_DWORD *)(this + 48) = 10;
      *(_DWORD *)(this + 52) = 25;
      *(_DWORD *)(this + 56) = 32;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aRumble) )
    {
      *(_DWORD *)(this + 48) = 11;
      *(_DWORD *)(this + 52) = 21;
      *(_DWORD *)(this + 56) = 27;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aTirewall) )
    {
      v5 = 32;
LABEL_36:
      *(_DWORD *)(this + 48) = v5;
      *(_DWORD *)(this + 52) = v5;
      *(_DWORD *)(this + 56) = v5;
      goto LABEL_37;
    }
    if ( !strcmp(&SrcStr, aSolidwall) || !strcmp(&SrcStr, aGuardrail) )
    {
      v5 = 27;
      goto LABEL_36;
    }
  }
LABEL_37:
  result = sub_5654A0(aMaterials, &SrcStr);
  if ( result )
  {
    sub_589901(&SrcStr);
    if ( SrcStr )
    {
      v7 = &v16;
      do
      {
        v8 = *(v7 - 1);
        if ( v8 == 32 )
        {
          v9 = v7;
          do
          {
            v10 = *v9;
            *(v9 - 1) = *v9;
            ++v9;
          }
          while ( v10 );
        }
        else if ( v8 == 44 && (*v7 == 44 || !*v7) )
        {
          v11 = v7;
          do
          {
            v12 = *v11;
            *(v11 - 1) = *v11;
            ++v11;
          }
          while ( v12 );
        }
        else
        {
          ++v7;
        }
      }
      while ( *(v7 - 1) );
    }
    return StringCopyWithBufferRealloc(&SrcStr);
  }
  return result;
}
