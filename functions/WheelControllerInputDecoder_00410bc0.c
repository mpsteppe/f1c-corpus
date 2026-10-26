int __thiscall sub_410BC0(_DWORD *this, int a2)
{
  double v3; // st7
  __int16 v4; // dx
  int v6; // ecx
  int v7; // edx
  double v8; // st7
  int v9; // ecx
  unsigned int v10; // edx
  int v11; // edx
  double v12; // st7
  int v13; // ecx
  int v14; // edx
  int v15; // esi
  double v16; // st7
  int v17; // edx
  double v18; // st7
  int v19; // ecx
  double v20; // st7
  int v21; // edx
  double v22; // st7
  int v23; // ecx
  double v24; // st7
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  int result; // eax
  int v29; // eax
  int v30; // ebp
  _DWORD *v31; // ecx
  int v32; // ebx
  unsigned int v33; // ebp
  _DWORD *v34; // ecx
  int v35; // ebp
  _DWORD *v36; // ecx
  float v37[13]; // [esp+10h] [ebp-34h] BYREF
  int v38; // [esp+48h] [ebp+4h]
  int v39; // [esp+48h] [ebp+4h]
  int v40; // [esp+48h] [ebp+4h]
  int v41; // [esp+48h] [ebp+4h]
  int v42; // [esp+48h] [ebp+4h]
  int v43; // [esp+48h] [ebp+4h]
  int v44; // [esp+48h] [ebp+4h]
  int v45; // [esp+48h] [ebp+4h]

  v3 = *(float *)(a2 + 4);
  v4 = *(_WORD *)(a2 + 12);
  v38 = *(_DWORD *)(a2 + 10) << 8;
  v6 = *(_DWORD *)(a2 + 14);
  v37[0] = v3;
  v7 = (v6 << 16) + (v4 & 0xFF00);
  v8 = (double)v38 * 0.000030517578;
  v9 = *(unsigned __int8 *)(a2 + 18);
  v39 = v7;
  v10 = *(_DWORD *)(a2 + 14);
  v37[1] = v8;
  v11 = (v9 << 24) + ((v10 >> 8) & 0xFFFF00);
  v12 = (double)v39 * 0.000030517578;
  v13 = *(__int16 *)(a2 + 21);
  v40 = v11;
  v14 = *(__int16 *)(a2 + 19);
  v15 = *(__int16 *)(a2 + 8);
  v37[2] = v12;
  v16 = (double)v40;
  v41 = v14;
  v17 = *(__int16 *)(a2 + 23);
  v37[3] = v16 * 0.000030517578;
  v18 = (double)v41;
  v42 = v13;
  v19 = *(__int16 *)(a2 + 25);
  v37[4] = v18 * 0.00048828125;
  v20 = (double)v42;
  v43 = v17;
  v21 = *(__int16 *)(a2 + 27);
  v37[5] = v20 * 0.00048828125;
  v22 = (double)v43;
  v44 = v19;
  v23 = *(__int16 *)(a2 + 29);
  v37[6] = v22 * 0.00048828125;
  v37[7] = (double)v44 * 0.015625;
  v37[8] = (double)v21 * 0.015625;
  v24 = (double)v23 * 0.015625;
  v25 = *(__int16 *)(a2 + 33);
  v45 = *(__int16 *)(a2 + 31);
  v26 = *(__int16 *)(a2 + 35);
  v27 = *(_DWORD *)a2 >> 18;
  v37[9] = v24;
  result = (v27 & 0x3F) - 1;
  v37[10] = (double)v45 * 0.0078125;
  v37[11] = (double)v25 * 0.0078125;
  v37[12] = (double)v26 * 0.0078125;
  switch ( result )
  {
    case 0:
      if ( v15 >= 0 && v15 < this[9] )
      {
        v29 = this[10];
        goto LABEL_38;
      }
      return result;
    case 1:
      if ( v15 >= 0 && v15 < this[12] )
      {
        v29 = this[13];
        goto LABEL_38;
      }
      return result;
    case 2:
      if ( v15 >= 0 && v15 < this[15] )
      {
        v29 = this[16];
        goto LABEL_38;
      }
      return result;
    case 3:
      if ( v15 >= 0 && v15 < this[18] )
      {
        if ( v15 < 416 )
        {
          v30 = v15 & 3;
          v31 = (_DWORD *)(this[19] + 36 * v15);
          if ( *v31 == -1 )
          {
            result = dword_5ECF0C[4656 * (v15 / 4) + 74 * v30];
            if ( !result )
              return result;
            ShortComputation_e770(v31, result, 1);
          }
          RepairServiceStateDispatcher(v30);
        }
        return PhysicsStateVectorConversion((_DWORD *)(this[19] + 36 * v15), v37);
      }
      return result;
    case 4:
      if ( v15 < 0 || v15 >= this[21] )
        return result;
      if ( v15 >= 208 )
        return PhysicsStateVectorConversion((_DWORD *)(this[22] + 36 * v15), v37);
      v32 = v15 / 2;
      v33 = v15 & 0x80000001;
      v34 = (_DWORD *)(this[22] + 36 * v15);
      if ( *v34 != -1 )
        goto LABEL_28;
      if ( v33 )
        result = dword_5ED3F0[4656 * v32];
      else
        result = dword_5ED3AC[4656 * v32];
      if ( result )
      {
        ShortComputation_e770(v34, result, 1);
LABEL_28:
        RepairServiceStateDispatcher((v33 != 0) + 4);
        return PhysicsStateVectorConversion((_DWORD *)(this[22] + 36 * v15), v37);
      }
      break;
    case 5:
      if ( v15 < 0 || v15 >= this[24] )
        return result;
      if ( v15 >= 832 )
        goto LABEL_37;
      v35 = v15 & 7;
      v36 = (_DWORD *)(this[25] + 36 * v15);
      if ( *v36 != -1 )
        goto LABEL_36;
      result = dword_5ED434[4656 * (v15 / 8) + 17 * v35];
      if ( result )
      {
        ShortComputation_e770(v36, result, 1);
LABEL_36:
        RepairServiceStateDispatcher(v35 + 6);
LABEL_37:
        v29 = this[25];
LABEL_38:
        result = PhysicsStateVectorConversion((_DWORD *)(v29 + 36 * v15), v37);
      }
      break;
    default:
      return result;
  }
  return result;
}
