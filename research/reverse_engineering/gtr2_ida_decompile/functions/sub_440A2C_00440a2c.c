int __userpurge sub_440A2C@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        double a17,
        double a18,
        float a19,
        float a20,
        float a21,
        float a22,
        double a23,
        float a24,
        float a25,
        float a26,
        float a27,
        double a28)
{
  double v29; // kr00_8
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  double *v35; // ecx
  int result; // eax
  double v37; // kr10_8
  int v38; // eax
  int v39; // ecx
  int v40; // edx
  double *v41; // eax
  const void *v42; // esi
  char v43; // al
  double v44; // st7
  double *v45; // eax
  _DWORD *v46; // ecx

  if ( *(_BYTE *)(a1 + 456) )
  {
    a12 = 0.0;
    a13 = 0.0;
    a14 = 0.0;
    a15 = 0.0;
    a16 = 0.0;
    a17 = 0.0;
    a9 = 0.0;
    a10 = 0.0;
    a11 = 0.0;
    sub_61B860(&a15);
    v29 = a12;
    v30 = HIDWORD(a13);
    v31 = LODWORD(a13);
    v32 = *(_DWORD *)(a1 + 352) + 8;
    *(double *)v32 = a12;
    *(_DWORD *)(v32 + 8) = v31;
    v33 = LODWORD(a14);
    *(_DWORD *)(v32 + 12) = v30;
    v34 = HIDWORD(a14);
    *(_DWORD *)(v32 + 16) = v33;
    *(_DWORD *)(v32 + 20) = v34;
    v35 = (double *)(*(_DWORD *)(a1 + 352) + 104);
    *v35 = 0.0;
    v35[1] = 0.0;
    v35[2] = 0.0;
    sub_43A600(*(_DWORD **)(a1 + 352), &a18, &a9);
    result = *(_DWORD *)(a1 + 356);
    if ( result )
    {
      v37 = a13;
      v38 = result + 8;
      *(double *)v38 = v29;
      *(_DWORD *)(v38 + 8) = LODWORD(v37);
      v39 = LODWORD(a14);
      *(_DWORD *)(v38 + 12) = HIDWORD(v37);
      v40 = HIDWORD(a14);
      *(_DWORD *)(v38 + 16) = v39;
      *(_DWORD *)(v38 + 20) = v40;
      v41 = (double *)(*(_DWORD *)(a1 + 356) + 104);
      *v41 = 0.0;
      v41[1] = 0.0;
      v41[2] = 0.0;
      return sub_43A600(*(_DWORD **)(a1 + 356), &a18, &a9);
    }
  }
  else
  {
    result = *(_DWORD *)(a2 + 8);
    if ( result )
    {
      v42 = (const void *)(result + 32);
      v43 = *(_BYTE *)(a1 + 457);
      qmemcpy(&a18, v42, 0x48u);
      if ( v43 )
        sub_61B900(a1 + 464, 0);
      sub_61BD50(*(double *)(a1 + 176), 0);
      v44 = *(double *)(a1 + 192);
      v45 = *(double **)(a2 + 8);
      a10 = a23 * v44;
      a11 = a28 * v44;
      a9 = a18 * v44 + v45[16];
      a10 = a10 + v45[17];
      v46 = *(_DWORD **)(a1 + 352);
      a11 = a11 + v45[18];
      return sub_43A600(v46, &a18, &a9);
    }
  }
  return result;
}
