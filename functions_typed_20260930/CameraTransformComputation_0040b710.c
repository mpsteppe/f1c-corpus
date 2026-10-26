int __thiscall sub_40B710(_DWORD *this)
{
  int v2; // esi
  int v3; // ebp
  int result; // eax
  int v5; // [esp+14h] [ebp-50h]
  float v6; // [esp+18h] [ebp-4Ch]
  float v7; // [esp+18h] [ebp-4Ch]
  float v8; // [esp+1Ch] [ebp-48h]
  float v9; // [esp+30h] [ebp-34h] BYREF
  float v10; // [esp+34h] [ebp-30h] BYREF
  int v11; // [esp+38h] [ebp-2Ch] BYREF
  int v12; // [esp+3Ch] [ebp-28h] BYREF
  int v13; // [esp+40h] [ebp-24h] BYREF
  int v14; // [esp+44h] [ebp-20h]
  int v15; // [esp+48h] [ebp-1Ch]
  int v16; // [esp+4Ch] [ebp-18h] BYREF
  int v17; // [esp+50h] [ebp-14h]
  float v18; // [esp+54h] [ebp-10h]
  _DWORD v19[3]; // [esp+58h] [ebp-Ch] BYREF

  v2 = this[3] + 208 * this[5];
  if ( this[1] )
  {
    F_3DTransformPointByMatrixAndTranslation(&v16, &v13);
    v19[0] = *(_DWORD *)(dword_7C54E0 + 88);
    v19[1] = *(_DWORD *)(dword_7C54E0 + 92);
    v19[2] = *(_DWORD *)(dword_7C54E0 + 96);
    v3 = *(_DWORD *)v2;
    v8 = ScoringGateConditionCheck(this);
    v6 = ShortComputation_84a0();
    (*(void (__thiscall **)(int, int *, int *, _DWORD *, _DWORD, _DWORD))(v3 + 24))(
      v2,
      &v16,
      &v13,
      v19,
      LODWORD(v6),
      LODWORD(v8));
    v16 = *(_DWORD *)(v2 + 12);
    v17 = *(_DWORD *)(v2 + 16);
    v18 = *(float *)(v2 + 20);
    v13 = *(_DWORD *)(v2 + 24);
    v14 = *(_DWORD *)(v2 + 28);
    v15 = *(_DWORD *)(v2 + 32);
    UtilityFunction_1cd0(v16, v17, v18, v13, v14, v15);
    DualFieldGetter(&v10, &v9);
    ShortComputation_6080(&v12, &v11);
    v7 = v9 * 0.01745433;
    *(float *)&v5 = v10 * 0.01745433;
    sub_542050(v5, v7, 0);
    TwoFieldSetterCall(v12, v11);
    return ConditionalFloatSetter(*(float *)(v2 + 72));
  }
  return result;
}

