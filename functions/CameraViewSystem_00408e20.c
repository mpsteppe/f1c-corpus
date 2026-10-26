int __thiscall CameraViewSystem(int this, int a2)
{
  _DWORD *v3; // edi
  int v4; // ebx
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // edi
  _BYTE *v8; // edi
  void (__thiscall ***v9)(_DWORD, int); // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  void (__thiscall ***v12)(_DWORD, int); // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  void (__thiscall ***v15)(_DWORD, int); // ecx
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  void (__thiscall ***v18)(_DWORD, int); // ecx
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  void (__thiscall ***v21)(_DWORD, int); // ecx
  float *v22; // eax
  float v23; // ecx
  float *v24; // ebx
  _DWORD *v25; // edi
  float v26; // ebp
  float *v27; // eax
  int v28; // edi
  float v29; // ebx
  double v30; // st7
  int v31; // eax
  double v32; // st7
  int v33; // eax
  double v34; // st7
  int v35; // eax
  double v36; // st7
  int v37; // eax
  int v38; // ebx
  int v39; // edi
  double v40; // st7
  int v41; // eax
  double v42; // st7
  int v43; // eax
  double v44; // st7
  int v45; // eax
  double v46; // st7
  int v47; // eax
  double v48; // st7
  int v49; // esi
  _DWORD *v50; // esi
  int v51; // edi
  _DWORD *v53; // esi
  int v54; // edi
  float v55; // [esp+14h] [ebp-205Ch] BYREF
  float v56; // [esp+18h] [ebp-2058h] BYREF
  int v57[7]; // [esp+1Ch] [ebp-2054h] BYREF
  CHAR v58[256]; // [esp+38h] [ebp-2038h] BYREF
  _DWORD v59[50]; // [esp+138h] [ebp-1F38h] BYREF
  _DWORD v60[50]; // [esp+200h] [ebp-1E70h] BYREF
  _DWORD v61[50]; // [esp+2C8h] [ebp-1DA8h] BYREF
  _DWORD v62[50]; // [esp+390h] [ebp-1CE0h] BYREF
  char v63[384]; // [esp+458h] [ebp-1C18h] BYREF
  int v64; // [esp+5D8h] [ebp-1A98h]
  char v65; // [esp+5DCh] [ebp-1A94h]
  int v66; // [esp+5E4h] [ebp-1A8Ch]
  int v67; // [esp+5E8h] [ebp-1A88h]
  int v68; // [esp+5ECh] [ebp-1A84h]
  char v69[384]; // [esp+5F0h] [ebp-1A80h] BYREF
  _BYTE v70[6400]; // [esp+770h] [ebp-1900h] BYREF
  _UNKNOWN *retaddr; // [esp+2070h] [ebp+0h] BYREF

  if ( !a2 )
    return 1;
  ZeroInitSmallStruct(v57);
  memset(v69, 0, sizeof(v69));
  v64 = 0;
  v68 = 0;
  v66 = 0;
  v67 = 0;
  v65 = 1;
  F_3DSoundEmitter(v62);
  F_3DSoundEmitter(v61);
  F_3DSoundEmitter(v59);
  F_3DSoundEmitter(v60);
  v3 = v70;
  v4 = 32;
  do
  {
    F_3DSoundEmitter(v3);
    v3 += 50;
    --v4;
  }
  while ( v4 );
  v5 = 0;
  v56 = 0.0;
  if ( !AudioStreamOpen(v57, a2, 1) )
  {
    v6 = &retaddr;
    v7 = 32;
    do
    {
      v6 -= 50;
      ShortComputation_62a0(v6);
      --v7;
    }
    while ( v7 );
LABEL_78:
    ShortComputation_62a0(v60);
    ShortComputation_62a0(v59);
    ShortComputation_62a0(v61);
    ShortComputation_62a0(v62);
    SubCallWithConditionalFieldFree(v57);
    return 1;
  }
  if ( ConditionalDispatchBasedOnFlag(v57, v69, 384) )
  {
    v8 = v70;
    do
    {
      if ( !sub_5651B0(v63) && sub_565520((int)v63, (int)aLocalcam, v58, 0) )
      {
        if ( sub_588410(aSwingman, v58) )
        {
          if ( sub_588410(aCockpit_0, v58) )
          {
            if ( sub_588410(aTvcockpit, v58) )
            {
              if ( sub_588410(aNosecam, v58) )
              {
                if ( SLODWORD(v56) < 32 )
                {
                  sub_4562F0((int)v8, (int)v57, (int)v58);
                  ++LODWORD(v56);
                  v8 += 200;
                }
              }
              else
              {
                sub_4562F0((int)v62, (int)v57, (int)v58);
              }
            }
            else
            {
              sub_4562F0((int)v59, (int)v57, (int)v58);
            }
          }
          else
          {
            sub_4562F0((int)v61, (int)v57, (int)v58);
          }
        }
        else
        {
          sub_4562F0((int)v60, (int)v57, (int)v58);
        }
      }
    }
    while ( ConditionalDispatchBasedOnFlag(v57, v69, 384) );
    v5 = LODWORD(v56);
  }
  if ( !v57[0] )
  {
    v53 = &retaddr;
    v54 = 32;
    do
    {
      v53 -= 50;
      ShortComputation_62a0(v53);
      --v54;
    }
    while ( v54 );
    goto LABEL_78;
  }
  ConditionalFileHandleCloseWithFlagDispatch(v57);
  v9 = *(void (__thiscall ****)(_DWORD, int))(this + 28);
  if ( v9 )
    (**v9)(v9, 1);
  v10 = (_DWORD *)OperatorNewNhMallocWrapper(200);
  if ( v10 )
    v11 = F_3DSoundEmitter(v10);
  else
    v11 = 0;
  *(_DWORD *)(this + 28) = v11;
  if ( v11 )
    sub_457000((int)v11, COERCE_FLOAT(v60));
  v12 = *(void (__thiscall ****)(_DWORD, int))(this + 20);
  if ( v12 )
    (**v12)(v12, 1);
  v13 = (_DWORD *)OperatorNewNhMallocWrapper(200);
  if ( v13 )
    v14 = F_3DSoundEmitter(v13);
  else
    v14 = 0;
  *(_DWORD *)(this + 20) = v14;
  if ( v14 )
    sub_457000((int)v14, COERCE_FLOAT(v61));
  v15 = *(void (__thiscall ****)(_DWORD, int))(this + 24);
  if ( v15 )
    (**v15)(v15, 1);
  v16 = (_DWORD *)OperatorNewNhMallocWrapper(200);
  if ( v16 )
    v17 = F_3DSoundEmitter(v16);
  else
    v17 = 0;
  *(_DWORD *)(this + 24) = v17;
  if ( v17 )
    sub_457000((int)v17, COERCE_FLOAT(v59));
  v18 = *(void (__thiscall ****)(_DWORD, int))(this + 16);
  if ( v18 )
    (**v18)(v18, 1);
  v19 = (_DWORD *)OperatorNewNhMallocWrapper(200);
  if ( v19 )
    v20 = F_3DSoundEmitter(v19);
  else
    v20 = 0;
  *(_DWORD *)(this + 16) = v20;
  if ( v20 )
    sub_457000((int)v20, COERCE_FLOAT(v62));
  v21 = *(void (__thiscall ****)(_DWORD, int))(this + 32);
  if ( v21 )
    (**v21)(v21, 3);
  if ( v5 <= 0 )
  {
    *(_DWORD *)(this + 56) = 0;
    *(_DWORD *)(this + 60) = 0;
  }
  else
  {
    v22 = (float *)OperatorNewNhMallocWrapper(200 * v5 + 4);
    if ( v22 )
    {
      v23 = v56;
      v24 = v22 + 1;
      *v22 = v56;
      v25 = v22 + 1;
      if ( LODWORD(v23) - 1 >= 0 )
      {
        v26 = v23;
        do
        {
          F_3DSoundEmitter(v25);
          v25 += 50;
          --LODWORD(v26);
        }
        while ( v26 != 0.0 );
      }
      v27 = v24;
    }
    else
    {
      v27 = 0;
    }
    *(_DWORD *)(this + 32) = v27;
    if ( v27 )
    {
      if ( SLODWORD(v56) > 0 )
      {
        v28 = 0;
        v29 = v56;
        do
        {
          sub_457000(v28 + *(_DWORD *)(this + 32), COERCE_FLOAT(&v70[v28]));
          v28 += 200;
          --LODWORD(v29);
        }
        while ( v29 != 0.0 );
      }
      *(float *)(this + 56) = v56;
      *(_DWORD *)(this + 60) = 0;
    }
  }
  CameraPositionDefinitions((_DWORD *)this);
  if ( dword_5EA510 )
  {
    DoubleFieldGetter((_DWORD *)dword_5EA510, 0, &v56);
    ShortComputation_6080(*(_DWORD **)(this + 28), &v55, 0);
    v30 = v56;
    v31 = *(_DWORD *)(this + 28);
    *(float *)(v31 + 64) = v55;
    *(float *)(v31 + 68) = v30;
    ShortComputation_6080(*(_DWORD **)(this + 24), &v55, 0);
    v32 = v56;
    v33 = *(_DWORD *)(this + 24);
    *(float *)(v33 + 64) = v55;
    *(float *)(v33 + 68) = v32;
    ShortComputation_6080(*(_DWORD **)(this + 20), &v55, 0);
    v34 = v56;
    v35 = *(_DWORD *)(this + 20);
    *(float *)(v35 + 64) = v55;
    *(float *)(v35 + 68) = v34;
    ShortComputation_6080(*(_DWORD **)(this + 16), &v55, 0);
    v36 = v56;
    v37 = *(_DWORD *)(this + 16);
    *(float *)(v37 + 64) = v55;
    v38 = 0;
    *(float *)(v37 + 68) = v36;
    if ( *(int *)(this + 56) > 0 )
    {
      v39 = 0;
      do
      {
        ShortComputation_6080((_DWORD *)(v39 + *(_DWORD *)(this + 32)), &v55, 0);
        v40 = v56;
        v41 = v39 + *(_DWORD *)(this + 32);
        *(float *)(v41 + 64) = v55;
        ++v38;
        *(float *)(v41 + 68) = v40;
        v39 += 200;
      }
      while ( v38 < *(_DWORD *)(this + 56) );
    }
    ShortComputation_6080(*(_DWORD **)(this + 36), &v55, 0);
    v42 = v56;
    v43 = *(_DWORD *)(this + 36);
    *(float *)(v43 + 64) = v55;
    *(float *)(v43 + 68) = v42;
    ShortComputation_6080(*(_DWORD **)(this + 40), &v55, 0);
    v44 = v56;
    v45 = *(_DWORD *)(this + 40);
    *(float *)(v45 + 64) = v55;
    *(float *)(v45 + 68) = v44;
    ShortComputation_6080(*(_DWORD **)(this + 44), &v55, 0);
    v46 = v56;
    v47 = *(_DWORD *)(this + 44);
    *(float *)(v47 + 64) = v55;
    *(float *)(v47 + 68) = v46;
    ShortComputation_6080(*(_DWORD **)(this + 48), &v55, 0);
    v48 = v56;
    v49 = *(_DWORD *)(this + 48);
    *(float *)(v49 + 64) = v55;
    *(float *)(v49 + 68) = v48;
  }
  v50 = &retaddr;
  v51 = 32;
  do
  {
    v50 -= 50;
    ShortComputation_62a0(v50);
    --v51;
  }
  while ( v51 );
  ShortComputation_62a0(v60);
  ShortComputation_62a0(v59);
  ShortComputation_62a0(v61);
  ShortComputation_62a0(v62);
  SubCallWithConditionalFieldFree(v57);
  return 0;
}
