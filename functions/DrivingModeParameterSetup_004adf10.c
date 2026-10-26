int __thiscall sub_4ADF10(int this)
{
  int v2; // edx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // edx
  int v19; // edx
  int v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int result; // eax
  float v31; // [esp-8h] [ebp-Ch]
  float v32; // [esp-8h] [ebp-Ch]
  int v33; // [esp-4h] [ebp-8h]
  int v34; // [esp-4h] [ebp-8h]
  int v35; // [esp-4h] [ebp-8h]
  int v36; // [esp-4h] [ebp-8h]
  int v37; // [esp-4h] [ebp-8h]
  int v38; // [esp-4h] [ebp-8h]
  int v39; // [esp-4h] [ebp-8h]
  int v40; // [esp-4h] [ebp-8h]
  int v41; // [esp-4h] [ebp-8h]
  int v42; // [esp-4h] [ebp-8h]
  int v43; // [esp-4h] [ebp-8h]
  float v44; // [esp-4h] [ebp-8h]
  int v45; // [esp-4h] [ebp-8h]
  int v46; // [esp-4h] [ebp-8h]
  int v47; // [esp-4h] [ebp-8h]
  int v48; // [esp-4h] [ebp-8h]
  int v49; // [esp-4h] [ebp-8h]
  int v50; // [esp-4h] [ebp-8h]
  int v51; // [esp-4h] [ebp-8h]
  int v52; // [esp-4h] [ebp-8h]
  int v53; // [esp-4h] [ebp-8h]
  int v54; // [esp-4h] [ebp-8h]
  int v55; // [esp-4h] [ebp-8h]
  float v56; // [esp-4h] [ebp-8h]
  int v57; // [esp-4h] [ebp-8h]
  int v58; // [esp-4h] [ebp-8h]
  int v59; // [esp-4h] [ebp-8h]
  int v60; // [esp-4h] [ebp-8h]
  int v61; // [esp-4h] [ebp-8h]
  int v62; // [esp-4h] [ebp-8h]

  switch ( *(_DWORD *)(this + 7360) )
  {
    case 0:
      break;
    case 1:
      v2 = *(_DWORD *)(this + 540);
      v33 = *(_DWORD *)(this + 544);
      *(_DWORD *)(this + 532) = 2;
      ClampByRange((int *)(this + 532), v2, v33);
      v34 = *(_DWORD *)(this + 832);
      v3 = *(_DWORD *)(this + 828);
      *(_DWORD *)(this + 820) = 1;
      ClampByRange((int *)(this + 820), v3, v34);
      v4 = *(_DWORD *)(this + 648);
      v35 = *(_DWORD *)(this + 652);
      *(_DWORD *)(this + 640) = 2;
      ClampByRange((int *)(this + 640), v4, v35);
      v36 = *(_DWORD *)(this + 868);
      v5 = *(_DWORD *)(this + 864);
      *(_DWORD *)(this + 856) = 2;
      ClampByRange((int *)(this + 856), v5, v36);
      v6 = *(_DWORD *)(this + 720);
      v37 = *(_DWORD *)(this + 724);
      *(_DWORD *)(this + 712) = 2;
      ClampByRange((int *)(this + 712), v6, v37);
      v38 = *(_DWORD *)(this + 760);
      v7 = *(_DWORD *)(this + 756);
      *(_DWORD *)(this + 748) = 1;
      ClampByRange((int *)(this + 748), v7, v38);
      v8 = *(_DWORD *)(this + 1044);
      v39 = *(_DWORD *)(this + 1048);
      *(_DWORD *)(this + 1036) = 3;
      ClampByRange((int *)(this + 1036), v8, v39);
      v40 = *(_DWORD *)(this + 616);
      v9 = *(_DWORD *)(this + 612);
      *(_DWORD *)(this + 604) = 2;
      ClampByRange((int *)(this + 604), v9, v40);
      v10 = *(_DWORD *)(this + 684);
      v41 = *(_DWORD *)(this + 688);
      *(_DWORD *)(this + 676) = 2;
      ClampByRange((int *)(this + 676), v10, v41);
      v42 = *(_DWORD *)(this + 796);
      v11 = *(_DWORD *)(this + 792);
      *(_DWORD *)(this + 784) = 1;
      ClampByRange((int *)(this + 784), v11, v42);
      v12 = *(_DWORD *)(this + 7440);
      v43 = *(_DWORD *)(this + 7444);
      *(_DWORD *)(this + 7432) = 75;
      ClampByRange((int *)(this + 7432), v12, v43);
      v44 = *(float *)(this + 7408);
      v31 = *(float *)(this + 7404);
      *(_DWORD *)(this + 7396) = 1048576000;
      FloatClamp((float *)(this + 7396), v31, v44);
      break;
    case 2:
      v45 = *(_DWORD *)(this + 544);
      v13 = *(_DWORD *)(this + 540);
      *(_DWORD *)(this + 532) = 2;
      ClampByRange((int *)(this + 532), v13, v45);
      v14 = *(_DWORD *)(this + 828);
      v46 = *(_DWORD *)(this + 832);
      *(_DWORD *)(this + 820) = 1;
      ClampByRange((int *)(this + 820), v14, v46);
      v47 = *(_DWORD *)(this + 652);
      v15 = *(_DWORD *)(this + 648);
      *(_DWORD *)(this + 640) = 1;
      ClampByRange((int *)(this + 640), v15, v47);
      v16 = *(_DWORD *)(this + 864);
      v48 = *(_DWORD *)(this + 868);
      *(_DWORD *)(this + 856) = 2;
      ClampByRange((int *)(this + 856), v16, v48);
      v49 = *(_DWORD *)(this + 724);
      v17 = *(_DWORD *)(this + 720);
      *(_DWORD *)(this + 712) = 1;
      ClampByRange((int *)(this + 712), v17, v49);
      v18 = *(_DWORD *)(this + 756);
      v50 = *(_DWORD *)(this + 760);
      *(_DWORD *)(this + 748) = 1;
      ClampByRange((int *)(this + 748), v18, v50);
      v51 = *(_DWORD *)(this + 1048);
      v19 = *(_DWORD *)(this + 1044);
      *(_DWORD *)(this + 1036) = 3;
      ClampByRange((int *)(this + 1036), v19, v51);
      v20 = *(_DWORD *)(this + 612);
      v52 = *(_DWORD *)(this + 616);
      *(_DWORD *)(this + 604) = 2;
      ClampByRange((int *)(this + 604), v20, v52);
      v53 = *(_DWORD *)(this + 688);
      v21 = *(_DWORD *)(this + 684);
      *(_DWORD *)(this + 676) = 2;
      ClampByRange((int *)(this + 676), v21, v53);
      v22 = *(_DWORD *)(this + 792);
      v54 = *(_DWORD *)(this + 796);
      *(_DWORD *)(this + 784) = 1;
      ClampByRange((int *)(this + 784), v22, v54);
      v55 = *(_DWORD *)(this + 7444);
      v23 = *(_DWORD *)(this + 7440);
      *(_DWORD *)(this + 7432) = 85;
      ClampByRange((int *)(this + 7432), v23, v55);
      v56 = *(float *)(this + 7408);
      v32 = *(float *)(this + 7404);
      *(_DWORD *)(this + 7396) = 1048576000;
      FloatClamp((float *)(this + 7396), v32, v56);
      break;
    case 3:
      v24 = *(_DWORD *)(this + 540);
      v57 = *(_DWORD *)(this + 544);
      *(_DWORD *)(this + 532) = 1;
      ClampByRange((int *)(this + 532), v24, v57);
      v58 = *(_DWORD *)(this + 832);
      v25 = *(_DWORD *)(this + 828);
      *(_DWORD *)(this + 820) = 0;
      ClampByRange((int *)(this + 820), v25, v58);
      v26 = *(_DWORD *)(this + 648);
      v59 = *(_DWORD *)(this + 652);
      *(_DWORD *)(this + 640) = 0;
      ClampByRange((int *)(this + 640), v26, v59);
      v60 = *(_DWORD *)(this + 868);
      v27 = *(_DWORD *)(this + 864);
      *(_DWORD *)(this + 856) = 1;
      ClampByRange((int *)(this + 856), v27, v60);
      v28 = *(_DWORD *)(this + 720);
      v61 = *(_DWORD *)(this + 724);
      *(_DWORD *)(this + 712) = 0;
      ClampByRange((int *)(this + 712), v28, v61);
      v62 = *(_DWORD *)(this + 760);
      v29 = *(_DWORD *)(this + 756);
      *(_DWORD *)(this + 748) = 1;
      ClampByRange((int *)(this + 748), v29, v62);
      ArithmeticComparison_20d0(3);
      ArithmeticComparison_20d0(2);
      ArithmeticComparison_20d0(2);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(95);
      goto LABEL_6;
    case 4:
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(3);
      ArithmeticComparison_20d0(2);
      ArithmeticComparison_20d0(2);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(100);
LABEL_6:
      ClampedFloatSetter_1de0(1048576000);
      break;
    case 5:
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(1);
      ArithmeticComparison_20d0(1);
      ArithmeticComparison_20d0(1);
      ArithmeticComparison_20d0(0);
      ArithmeticComparison_20d0(100);
      ClampedFloatSetter_1de0(1056964608);
      break;
    default:
      ArithmeticComparison_20d0(0);
      break;
  }
  result = *(_DWORD *)(this + 7360);
  if ( result )
  {
    ArithmeticComparison_20d0(1);
    return ArithmeticComparison_20d0(100);
  }
  return result;
}
