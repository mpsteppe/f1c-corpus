int __userpurge sub_47186C@<eax>(
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
        int a15)
{
  int result; // eax
  double *v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // edx
  double *v20; // eax
  int v21; // edx
  int v22; // [esp+0h] [ebp-24h]
  int v23; // [esp+4h] [ebp-20h]
  int v24; // [esp+8h] [ebp-1Ch]
  float v25; // [esp+Ch] [ebp-18h]
  float v26; // [esp+10h] [ebp-14h]
  float v27; // [esp+14h] [ebp-10h]
  float retaddr; // [esp+24h] [ebp+0h]
  double v29; // [esp+28h] [ebp+4h]
  double v30; // [esp+30h] [ebp+Ch]
  double v31; // [esp+30h] [ebp+Ch]
  double v32; // [esp+38h] [ebp+14h]

  result = *(_DWORD *)(a1 + 216);
  if ( result )
  {
    retaddr = *(float *)(a2 + 8) - *(float *)(a1 + 40);
    v17 = sub_43A250((double *)(a1 + 328), &a12, retaddr);
    v30 = v17[1];
    v18 = *((_DWORD *)v17 + 4);
    v19 = *((_DWORD *)v17 + 5);
    a9 = *v17 + *(double *)(a1 + 232);
    a10 = v30 + *(double *)(a1 + 240);
    v29 = a9;
    a11 = COERCE_DOUBLE(__PAIR64__(v19, v18)) + *(double *)(a1 + 248);
    v31 = a10;
    v32 = a11;
    v20 = sub_43A250((double *)(a1 + 352), &a12, retaddr);
    a9 = *v20;
    a10 = v20[1];
    LODWORD(a11) = *((_DWORD *)v20 + 4);
    v21 = *((_DWORD *)v20 + 5);
    qmemcpy(&a15, (const void *)(a1 + 256), 0x48u);
    HIDWORD(a11) = v21;
    sub_61BAD0(&a9);
    sub_43A2B0((int)&a15, (int)&a12);
    v27 = a14;
    v26 = a13;
    v25 = a12;
    *(float *)&v24 = v32;
    *(float *)&v23 = v31;
    *(float *)&v22 = v29;
    return sub_5DB2B0(v22, v23, v24, v25, v26, v27);
  }
  return result;
}
