int __thiscall sub_4F24F0(char *this, int a2)
{
  int v4; // eax
  int v5; // ebx
  char *v6; // edi
  int v7; // ebx
  char *v8; // edi
  char *v9; // ebp
  char *v10; // [esp+8h] [ebp-3B8h]
  _BYTE v11[28]; // [esp+Ch] [ebp-3B4h] BYREF
  _BYTE v12[64]; // [esp+28h] [ebp-398h] BYREF
  _BYTE v13[64]; // [esp+68h] [ebp-358h] BYREF
  _BYTE v14[384]; // [esp+A8h] [ebp-318h] BYREF
  int v15; // [esp+228h] [ebp-198h]
  char v16; // [esp+22Ch] [ebp-194h]
  int v17; // [esp+234h] [ebp-18Ch]
  int v18; // [esp+238h] [ebp-188h]
  int v19; // [esp+23Ch] [ebp-184h]
  _BYTE v20[384]; // [esp+240h] [ebp-180h] BYREF

  ZeroInitSmallStruct(v11);
  memset(v20, 0, sizeof(v20));
  v15 = 0;
  v19 = 0;
  v17 = 0;
  v18 = 0;
  v16 = 1;
  if ( (unsigned __int8)AudioStreamOpen(a2, 0) )
  {
    while ( ConditionalDispatchBasedOnFlag(v20, 384) )
    {
      if ( !sub_5651B0(v14) && sub_587C20(v20, aPhysical) && ConditionalDispatchBasedOnFlag(v20, 384) )
      {
        do
        {
          v4 = sub_5651B0(v14);
          if ( v4 == 1 )
            break;
          if ( !v4 )
          {
            sub_565870(aRadiusadd, this, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aRadiusmult, this + 4, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aRadiusmax, this + 8, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aEngine, this + 12, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aAerodiv, this + 16, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aAeromin, this + 20, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aVertmult, this + 24, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aFrontwingdetac, this + 28, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aFrontwingrando, this + 32, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aFrontwingpos, this + 36, this + 40, this + 44, 0, 0, 0, 0, 0);
            sub_565870(aFrontwingmassi, this + 48, this + 52, this + 56, this + 60, 0, 0, 0, 0);
            sub_565870(aFrontwingcollp, this + 64, this + 68, this + 72, 0, 0, 0, 0, 0);
            sub_565870(aRearwingdetach, this + 76, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aRearwingrandom, this + 80, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aRearwingpos, this + 84, this + 88, this + 92, 0, 0, 0, 0, 0);
            sub_565870(aRearwingmassin, this + 96, this + 100, this + 104, this + 108, 0, 0, 0, 0);
            sub_565870(aRearwingcollpa, this + 112, this + 116, this + 120, 0, 0, 0, 0, 0);
            sub_565870(aWheelbend, this + 124, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aWheeldetach, this + 128, 0, 0, 0, 0, 0, 0, 0);
            sub_565870(aWheelrandom, this + 132, 0, 0, 0, 0, 0, 0, 0);
            v5 = 0;
            v6 = this + 144;
            do
            {
              StringFormatWithBufferOverflowCheck(v13, "Wheel%dMassInertia", v5);
              sub_565870(v13, v6 - 8, v6 - 4, v6, v6 + 4, 0, 0, 0, 0);
              StringFormatWithBufferOverflowCheck(v13, "Wheel%dCollParams", v5);
              sub_565870(v13, v6 + 8, v6 + 12, v6 + 16, 0, 0, 0, 0, 0);
              ++v5;
              v6 += 28;
            }
            while ( v5 < 4 );
            v7 = 0;
            v8 = this + 416;
            v9 = this + 316;
            v10 = this + 280;
            do
            {
              StringFormatWithBufferOverflowCheck(v12, "Part%dDetach", v7);
              sub_565870(v12, v10 - 32, 0, 0, 0, 0, 0, 0, 0);
              StringFormatWithBufferOverflowCheck(v12, "Part%dRandom", v7);
              sub_565870(v12, v10, 0, 0, 0, 0, 0, 0, 0);
              StringFormatWithBufferOverflowCheck(v12, "Part%dPos", v7);
              sub_565870(v12, v9 - 4, v9, v9 + 4, 0, 0, 0, 0, 0);
              StringFormatWithBufferOverflowCheck(v12, "Part%dMassInertia", v7);
              sub_565870(v12, v8 - 8, v8 - 4, v8, v8 + 4, 0, 0, 0, 0);
              StringFormatWithBufferOverflowCheck(v12, "Part%dCollParams", v7);
              sub_565870(v12, v8 + 8, v8 + 12, v8 + 16, 0, 0, 0, 0, 0);
              ++v7;
              v9 += 12;
              v8 += 28;
              v10 += 4;
            }
            while ( v7 < 8 );
          }
        }
        while ( ConditionalDispatchBasedOnFlag(v20, 384) );
      }
    }
    ConditionalFileHandleCloseWithFlagDispatch(v11);
    SubCallWithConditionalFieldFree(v11);
    return 0;
  }
  else
  {
    SubCallWithConditionalFieldFree(v11);
    return -1;
  }
}
