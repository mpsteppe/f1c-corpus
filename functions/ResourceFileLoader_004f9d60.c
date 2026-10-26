char __stdcall sub_4F9D60(const char *a1, float a2, char a3)
{
  char v3; // bl
  const char *v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-10h] [ebp-168h]
  int v9; // [esp-10h] [ebp-168h]
  int v10; // [esp-Ch] [ebp-164h]
  int v11; // [esp-Ch] [ebp-164h]
  int v12; // [esp+8h] [ebp-150h] BYREF
  _BYTE v13[76]; // [esp+Ch] [ebp-14Ch] BYREF
  _BYTE v14[253]; // [esp+58h] [ebp-100h] BYREF
  __int16 v15; // [esp+155h] [ebp-3h]
  char v16; // [esp+157h] [ebp-1h]

  v3 = 0;
  v12 = 0;
  StructZeroInit_8ba0(v13);
  if ( !ShortComputation_4fb0((int)&v12, (int)a1, 1) )
    goto LABEL_6;
  v14[0] = byte_5EA438[0];
  memset(&v14[1], 0, 0xFCu);
  v15 = 0;
  v16 = 0;
  v4 = (const char *)dword_5EC408;
  if ( !dword_5EC408 )
    v4 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v14, "%s%s", v4, a1);
  v12 = 0;
  if ( ShortComputation_4fb0((int)&v12, (int)v14, 1) )
  {
    EmptyStub_0170();
    return 0;
  }
  else
  {
LABEL_6:
    if ( v12 )
    {
      v10 = *(_DWORD *)(v12 + 32);
      v8 = *(_DWORD *)(v12 + 28);
      v6 = GlobalAccessor_5150();
      ClippedRenderRegion(0, 0, v6, 0, 0, v8, v10, -1, 0);
      sub_495080();
      v11 = *(_DWORD *)(v12 + 32);
      v9 = *(_DWORD *)(v12 + 28);
      v7 = GlobalAccessor_5150();
      ClippedRenderRegion(0, 0, v7, 0, 0, v9, v11, -1, 0);
      sub_495080();
      QPCTimerInitialization(1);
      while ( PerformanceCounterDiffWithScaling(v13) < a2 )
      {
        if ( a3 )
        {
          sub_4537B0((int)&ppvOut, 0.050000001);
          if ( dword_7CB218 > 0 )
            break;
        }
      }
      ThunkToFUN0053cb90(v12);
      ShortComputation_50c0();
      v12 = 0;
      v3 = 1;
    }
    EmptyStub_0170();
    return v3;
  }
}
