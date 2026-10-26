void __fastcall sub_460DD0(int a1)
{
  int v1; // edi
  char *v2; // esi
  float *v3; // ebx
  bool v4; // al
  double v5; // st7
  float v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+14h] [ebp-4h] BYREF

  v7 = a1;
  v1 = 0;
  v2 = (char *)&stru_5EC6D8;
  v3 = (float *)(a1 + 107476);
  while ( 1 )
  {
    if ( *((_DWORD *)v2 + 3250) == 2 )
    {
      v4 = ShortArrayLookupAndZeroCheck((_WORD *)(a1 + 107456), v1, &v8);
      v5 = *v3 / flt_7D108C;
      if ( v5 > 2.0 || v4 )
      {
        VehicleAIControlFlag(0);
        v6 = v5;
        if ( v6 > 8.0 || fabs(v8) > 0.75 )
          SetDriverVisibility(0);
        else
          SetDriverVisibility(1);
      }
      else
      {
        VehicleAIControlFlag(1);
        SetDriverVisibility(1);
      }
    }
    v2 += 18624;
    ++v1;
    ++v3;
    if ( (int)v2 >= (int)byte_7C54D8 )
      break;
    a1 = v7;
  }
}

