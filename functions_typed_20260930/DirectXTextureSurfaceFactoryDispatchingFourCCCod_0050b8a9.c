_DWORD *__usercall sub_50B8A9@<eax>(int a1@<ebp>)
{
  int v1; // edi
  int v2; // eax
  _DWORD *v3; // esi
  float *v4; // ecx
  _DWORD *v5; // eax
  float *v6; // ecx
  float *v7; // ecx
  float *v8; // ecx
  float *v9; // ecx
  float *v10; // ecx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // ecx
  float *v15; // ecx
  float *v16; // ecx
  float *v17; // ecx
  float *v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  float *v24; // ecx
  float *v25; // ecx
  float *v26; // ecx
  float *v27; // ecx
  float *v28; // ecx
  float *v29; // ecx
  float *v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  float *v35; // ecx
  float *v36; // ecx
  float *v37; // ecx
  float *v38; // ecx
  float *v39; // ecx
  _DWORD *v40; // ecx
  _DWORD *v41; // ecx
  _DWORD *v42; // ecx
  _DWORD *v43; // ecx
  _DWORD *v44; // ecx
  _DWORD *v45; // ecx
  float *v46; // ecx
  int v47; // eax
  int v48; // eax
  int v49; // eax
  _DWORD *v50; // ecx
  float *v51; // ecx
  float *v52; // ecx
  float *v53; // ecx

  SEHHandlerInit();
  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(_DWORD *)(v1 + 4);
  v3 = 0;
  if ( v2 > 827611204 )
  {
    if ( v2 > 909200416 )
    {
      v47 = v2 - 909200449;
      if ( v47 )
      {
        v48 = v47 - 1503;
        if ( v48 )
        {
          v49 = v48 - 33;
          if ( v49 )
          {
            if ( v49 != 589629204 )
              return v3;
            v50 = (_DWORD *)OperatorNewNhMallocWrapper(4252);
            *(_DWORD *)(a1 + 8) = v50;
            *(_DWORD *)(a1 - 4) = 30;
            if ( v50 )
            {
              v5 = ObjectConstructorWithSingleInit(v50, a1, v1);
              goto LABEL_105;
            }
          }
          else
          {
            v51 = (float *)OperatorNewNhMallocWrapper(4204);
            *(_DWORD *)(a1 + 8) = v51;
            *(_DWORD *)(a1 - 4) = 29;
            if ( v51 )
            {
              v5 = ObjectInitWithVTable_b77b(v51, (float *)v1);
              goto LABEL_105;
            }
          }
        }
        else
        {
          v52 = (float *)OperatorNewNhMallocWrapper(4204);
          *(_DWORD *)(a1 + 8) = v52;
          *(_DWORD *)(a1 - 4) = 28;
          if ( v52 )
          {
            v5 = ConstructorSize0x30(v52, (float *)v1);
            goto LABEL_105;
          }
        }
      }
      else
      {
        v53 = (float *)OperatorNewNhMallocWrapper(4204);
        *(_DWORD *)(a1 + 8) = v53;
        *(_DWORD *)(a1 - 4) = 27;
        if ( v53 )
        {
          v5 = Constructor_b727(v53, (float *)v1);
          goto LABEL_105;
        }
      }
    }
    else
    {
      switch ( v2 )
      {
        case 909200416:
          v46 = (float *)OperatorNewNhMallocWrapper(4204);
          *(_DWORD *)(a1 + 8) = v46;
          *(_DWORD *)(a1 - 4) = 26;
          if ( v46 )
          {
            v5 = InitWithClass0x10(v46, (float *)v1);
            goto LABEL_105;
          }
          break;
        case 844388420:
          v45 = (_DWORD *)OperatorNewNhMallocWrapper(4292);
          *(_DWORD *)(a1 + 8) = v45;
          *(_DWORD *)(a1 - 4) = 33;
          if ( v45 )
          {
            v5 = ObjectInit_b7cb(v45, v1);
            goto LABEL_105;
          }
          break;
        case 844715353:
          v44 = (_DWORD *)OperatorNewNhMallocWrapper(4252);
          *(_DWORD *)(a1 + 8) = v44;
          *(_DWORD *)(a1 - 4) = 31;
          if ( v44 )
          {
            v5 = RenderObjectConstructor_b891(v44, a1, v1);
            goto LABEL_105;
          }
          break;
        case 861165636:
          v43 = (_DWORD *)OperatorNewNhMallocWrapper(4292);
          *(_DWORD *)(a1 + 8) = v43;
          *(_DWORD *)(a1 - 4) = 34;
          if ( v43 )
          {
            v5 = ConstructorWithInit_b7e3(v43, v1);
            goto LABEL_105;
          }
          break;
        case 877942852:
          v42 = (_DWORD *)OperatorNewNhMallocWrapper(4292);
          *(_DWORD *)(a1 + 8) = v42;
          *(_DWORD *)(a1 - 4) = 35;
          if ( v42 )
          {
            v5 = ShortComputation_b7fb(v42, v1);
            goto LABEL_105;
          }
          break;
        case 894720068:
          v41 = (_DWORD *)OperatorNewNhMallocWrapper(4292);
          *(_DWORD *)(a1 + 8) = v41;
          *(_DWORD *)(a1 - 4) = 36;
          if ( v41 )
          {
            v5 = ShortComputation_b813(v41, v1);
            goto LABEL_105;
          }
          break;
        default:
          return v3;
      }
    }
    goto LABEL_104;
  }
  if ( v2 == 827611204 )
  {
    v40 = (_DWORD *)OperatorNewNhMallocWrapper(4292);
    *(_DWORD *)(a1 + 8) = v40;
    *(_DWORD *)(a1 - 4) = 32;
    if ( v40 )
    {
      v5 = sub_50B797(v40, v1);
      goto LABEL_105;
    }
    goto LABEL_104;
  }
  if ( v2 > 40 )
  {
    if ( v2 > 62 )
    {
      v31 = v2 - 63;
      if ( v31 )
      {
        v32 = v31 - 1;
        if ( v32 )
        {
          v33 = v32 - 1;
          if ( v33 )
          {
            v34 = v33 - 2;
            if ( v34 )
            {
              if ( v34 != 3 )
                return v3;
              v35 = (float *)OperatorNewNhMallocWrapper(4204);
              *(_DWORD *)(a1 + 8) = v35;
              *(_DWORD *)(a1 - 4) = 25;
              if ( v35 )
              {
                v5 = ConstructorWithVTableSubInit_b446(v35, (float *)v1);
                goto LABEL_105;
              }
            }
            else
            {
              v36 = (float *)OperatorNewNhMallocWrapper(4204);
              *(_DWORD *)(a1 + 8) = v36;
              *(_DWORD *)(a1 - 4) = 24;
              if ( v36 )
              {
                v5 = sub_50B42A(v36, (float *)v1);
                goto LABEL_105;
              }
            }
          }
          else
          {
            v37 = (float *)OperatorNewNhMallocWrapper(4204);
            *(_DWORD *)(a1 + 8) = v37;
            *(_DWORD *)(a1 - 4) = 23;
            if ( v37 )
            {
              v5 = ShortComputation_b409(v37, (float *)v1);
              goto LABEL_105;
            }
          }
        }
        else
        {
          v38 = (float *)OperatorNewNhMallocWrapper(4204);
          *(_DWORD *)(a1 + 8) = v38;
          *(_DWORD *)(a1 - 4) = 22;
          if ( v38 )
          {
            v5 = sub_50B3ED(v38, (float *)v1);
            goto LABEL_105;
          }
        }
      }
      else
      {
        v39 = (float *)OperatorNewNhMallocWrapper(4204);
        *(_DWORD *)(a1 + 8) = v39;
        *(_DWORD *)(a1 - 4) = 21;
        if ( v39 )
        {
          v5 = VTableSetterWithSubInit_b3d1(v39, (float *)v1);
          goto LABEL_105;
        }
      }
    }
    else if ( v2 == 62 )
    {
      v30 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v30;
      *(_DWORD *)(a1 - 4) = 20;
      if ( v30 )
      {
        v5 = RenderFormatConstructor2(v30, (float *)v1);
        goto LABEL_105;
      }
    }
    else
    {
      v19 = v2 - 41;
      if ( v19 )
      {
        v20 = v19 - 9;
        if ( v20 )
        {
          v21 = v20 - 1;
          if ( v21 )
          {
            v22 = v21 - 1;
            if ( v22 )
            {
              v23 = v22 - 8;
              if ( v23 )
              {
                if ( v23 != 1 )
                  return v3;
                v24 = (float *)OperatorNewNhMallocWrapper(4204);
                *(_DWORD *)(a1 + 8) = v24;
                *(_DWORD *)(a1 - 4) = 19;
                if ( v24 )
                {
                  v5 = RenderObjectConstructor_b399(v24, (float *)v1);
                  goto LABEL_105;
                }
              }
              else
              {
                v25 = (float *)OperatorNewNhMallocWrapper(4204);
                *(_DWORD *)(a1 + 8) = v25;
                *(_DWORD *)(a1 - 4) = 18;
                if ( v25 )
                {
                  v5 = ObjectConstructor_b37d(v25, (float *)v1);
                  goto LABEL_105;
                }
              }
            }
            else
            {
              v26 = (float *)OperatorNewNhMallocWrapper(4204);
              *(_DWORD *)(a1 + 8) = v26;
              *(_DWORD *)(a1 - 4) = 17;
              if ( v26 )
              {
                v5 = sub_50B260(v26, (float *)v1);
                goto LABEL_105;
              }
            }
          }
          else
          {
            v27 = (float *)OperatorNewNhMallocWrapper(4204);
            *(_DWORD *)(a1 + 8) = v27;
            *(_DWORD *)(a1 - 4) = 16;
            if ( v27 )
            {
              v5 = ShortComputation_b228(v27, (float *)v1);
              goto LABEL_105;
            }
          }
        }
        else
        {
          v28 = (float *)OperatorNewNhMallocWrapper(4204);
          *(_DWORD *)(a1 + 8) = v28;
          *(_DWORD *)(a1 - 4) = 15;
          if ( v28 )
          {
            v5 = ConstructorWithInit(v28, (float *)v1);
            goto LABEL_105;
          }
        }
      }
      else
      {
        v29 = (float *)OperatorNewNhMallocWrapper(4204);
        *(_DWORD *)(a1 + 8) = v29;
        *(_DWORD *)(a1 - 4) = 14;
        if ( v29 )
        {
          v5 = ObjectInit_b1f0(v29, (float *)v1);
          goto LABEL_105;
        }
      }
    }
LABEL_104:
    v5 = 0;
    goto LABEL_105;
  }
  if ( v2 == 40 )
  {
    v18 = (float *)OperatorNewNhMallocWrapper(4204);
    *(_DWORD *)(a1 + 8) = v18;
    *(_DWORD *)(a1 - 4) = 13;
    if ( v18 )
    {
      v5 = InitVTableSet_b1d4(v18, (float *)v1);
LABEL_105:
      *(_DWORD *)(a1 - 4) = -1;
      v3 = v5;
      if ( v5 && v5[4] )
        (*(void (__thiscall **)(_DWORD *))(*v5 + 12))(v5);
      return v3;
    }
    goto LABEL_104;
  }
  switch ( v2 )
  {
    case 20:
      v4 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v4;
      *(_DWORD *)(a1 - 4) = 0;
      if ( !v4 )
        goto LABEL_104;
      v5 = ObjectConstructorWithSizeCountInit(v4, (float *)v1);
      goto LABEL_105;
    case 21:
      v6 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v6;
      *(_DWORD *)(a1 - 4) = 1;
      if ( !v6 )
        goto LABEL_104;
      v5 = RenderFormatConstructor(v6, (float *)v1);
      goto LABEL_105;
    case 22:
      v7 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v7;
      *(_DWORD *)(a1 - 4) = 2;
      if ( !v7 )
        goto LABEL_104;
      v5 = VTableSetterWithSubInit(v7, (float *)v1);
      goto LABEL_105;
    case 23:
      v8 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v8;
      *(_DWORD *)(a1 - 4) = 3;
      if ( !v8 )
        goto LABEL_104;
      v5 = sub_50A911(v8, (float *)v1);
      goto LABEL_105;
    case 24:
      v9 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v9;
      *(_DWORD *)(a1 - 4) = 4;
      if ( !v9 )
        goto LABEL_104;
      v5 = ShortComputation_ab19(v9, (float *)v1);
      goto LABEL_105;
    case 25:
      v10 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v10;
      *(_DWORD *)(a1 - 4) = 5;
      if ( !v10 )
        goto LABEL_104;
      v5 = sub_50AB35(v10, (float *)v1);
      goto LABEL_105;
    case 26:
      v11 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v11;
      *(_DWORD *)(a1 - 4) = 6;
      if ( !v11 )
        goto LABEL_104;
      v5 = ConstructorWithVTableSubInit(v11, (float *)v1);
      goto LABEL_105;
    case 27:
      v12 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v12;
      *(_DWORD *)(a1 - 4) = 7;
      if ( !v12 )
        goto LABEL_104;
      v5 = InitWithClass8(v12, (float *)v1);
      goto LABEL_105;
    case 28:
      v13 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v13;
      *(_DWORD *)(a1 - 4) = 8;
      if ( !v13 )
        goto LABEL_104;
      v5 = Constructor_ae5a(v13, (float *)v1);
      goto LABEL_105;
    case 29:
      v14 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v14;
      *(_DWORD *)(a1 - 4) = 9;
      if ( !v14 )
        goto LABEL_104;
      v5 = ConstructorSize0x10(v14, (float *)v1);
      goto LABEL_105;
    case 30:
      v15 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v15;
      *(_DWORD *)(a1 - 4) = 10;
      if ( !v15 )
        goto LABEL_104;
      v5 = RenderObjectConstructor(v15, (float *)v1);
      goto LABEL_105;
    case 31:
      v16 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v16;
      *(_DWORD *)(a1 - 4) = 11;
      if ( !v16 )
        goto LABEL_104;
      v5 = ObjectInitWithVTable_af3b(v16, (float *)v1);
      goto LABEL_105;
    case 34:
      v17 = (float *)OperatorNewNhMallocWrapper(4204);
      *(_DWORD *)(a1 + 8) = v17;
      *(_DWORD *)(a1 - 4) = 12;
      if ( !v17 )
        goto LABEL_104;
      v5 = sub_50AFC6(v17, (float *)v1);
      goto LABEL_105;
    default:
      return v3;
  }
  return v3;
}

