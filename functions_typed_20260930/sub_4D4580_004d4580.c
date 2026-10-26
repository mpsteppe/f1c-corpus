void __usercall sub_4D4580(int a1@<ecx>, double a2@<st0>)
{
  int v2; // esi
  double v3; // st7
  bool v4; // bl
  bool v5; // al
  int *v7; // ecx
  int v8; // [esp+0h] [ebp-10h]
  float v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+8h] [ebp-8h]
  float v12; // [esp+Ch] [ebp-4h]
  float v13; // [esp+Ch] [ebp-4h]

  v7 = *(int **)(a1 + 164);
  if ( v7 )
  {
    a2 = dbl_8AFE98;
    v9 = dbl_8AFE98;
    F_3DDistanceCheckAccumulate(v7, v9);
  }
  if ( *(_DWORD *)(a1 + 168) )
  {
    if ( dword_8AB6E4 == 2 )
      Delegation(&dword_8AB6EC);
    else
      a2 = dbl_8AFEA0;
    v13 = a2;
    AudioDSPStateUpdate(*(float **)(a1 + 168), v13);
  }
  if ( !byte_7C56AC )
  {
    PitTimer(a1);
    if ( (dword_7C56A0 & 1) != 0 && dword_7C56A4 >= 0 )
    {
      if ( dword_7C56A4 <= 6 )
      {
        if ( (*(float *)(a1 + 180) + *(float *)(a1 + 176)) * 0.5 <= dbl_8AFEA0 )
          *(_BYTE *)(a1 + 192) = 1;
LABEL_56:
        sub_4D1D80(a1);
      }
      else if ( dword_7C56A4 == 7 )
      {
        if ( PackedFlagRead(byte_7CA594, 57) && !byte_7CE254 )
          *(_BYTE *)(a1 + 193) = 1;
        switch ( dword_7C56A8 )
        {
          case 0:
          case 1:
            if ( !*(_BYTE *)(a1 + 193) )
              return;
            CollisionProxyUnregister((unsigned __int16 *)byte_7CA594, 57, 1.0);
            ShortComputation_bde0((_DWORD **)&dword_7CD204, a0001, 0);
            if ( !dword_7CED8C )
              goto LABEL_30;
            *(float *)&v10 = dbl_8AFEA0 + 300.0;
            ProgressBarDataStore(2, v10);
            return;
          case 2:
            v4 = *(_BYTE *)(a1 + 193) && *(float *)(a1 + 152) > 1.5;
            v5 = !ModeValidationCheck((_DWORD *)a1) && *(float *)(a1 + 180) - 300.0 + 1.5 < dbl_8AFEA0;
            if ( !v4 && !v5 )
              return;
            CollisionProxyUnregister((unsigned __int16 *)byte_7CA594, 57, 1.0);
            TickUpdateDispatch(a1);
LABEL_30:
            if ( dword_7CEE88 )
            {
              *(float *)&v11 = dbl_8AFEA0;
              ProgressBarDataStore(3, v11);
            }
            else
            {
LABEL_11:
              if ( SessionStateCheckWrapper(dword_7CD25C) )
              {
                if ( dbl_8AFEA0 < 31.0 )
                  return;
                v12 = 2.5;
              }
              else
              {
                v12 = 3.0;
              }
              v2 = dword_8AAE64;
              if ( dword_83EE60 < 1023 )
              {
                ++dword_83EE60;
                dword_8AAE64 += 432;
              }
              *(float *)&v8 = dbl_8AFEA0;
              ProgressBarEventEncode((_DWORD *)v2, 4, 20, 8, 255, v8, 1);
              *(float *)(v2 + 8) = dbl_8AFEA0 + v12;
              v3 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
              *(float *)(v2 + 12) = dbl_8AFEA0 + v12 + v3 + v3 + 5.0;
            }
            break;
          case 3:
            if ( sub_4D2170((float *)a1) )
              goto LABEL_11;
            return;
          case 4:
            if ( *(_DWORD *)(a1 + 216) == 2139095039 )
              goto LABEL_11;
            return;
          case 5:
          case 6:
          case 7:
          case 8:
            if ( (*(float *)(a1 + 180) + *(float *)(a1 + 176)) * 0.5 <= dbl_8AFEA0 )
              *(_BYTE *)(a1 + 192) = 1;
            if ( !SessionStateCheck(dword_7CD25C) && dword_8AB6E4 != 2 && dword_7CC520 )
              GlobalFlagSetter();
            goto LABEL_56;
          default:
            return;
        }
      }
    }
  }
}

