int __thiscall sub_4FEAA0(double *this, double a2, double a3, double a4)
{
  double v5; // st7
  int v6; // eax
  _DWORD *v7; // ecx
  int result; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  _DWORD v15[8]; // [esp+0h] [ebp-B8h] BYREF
  int v16; // [esp+20h] [ebp-98h]
  int v17; // [esp+24h] [ebp-94h]
  int v18; // [esp+28h] [ebp-90h]
  int v19; // [esp+2Ch] [ebp-8Ch]
  int v20; // [esp+30h] [ebp-88h]
  int v21; // [esp+34h] [ebp-84h]
  int v22; // [esp+38h] [ebp-80h]
  int v23; // [esp+3Ch] [ebp-7Ch]
  int v24; // [esp+40h] [ebp-78h]
  int v25; // [esp+44h] [ebp-74h]
  double v26; // [esp+48h] [ebp-70h]
  double v27; // [esp+50h] [ebp-68h]
  double v28; // [esp+58h] [ebp-60h]
  double v29; // [esp+60h] [ebp-58h]
  int v30; // [esp+68h] [ebp-50h]
  int v31; // [esp+6Ch] [ebp-4Ch]
  double v32; // [esp+70h] [ebp-48h]
  double v33; // [esp+78h] [ebp-40h]
  double v34; // [esp+80h] [ebp-38h]
  int v35; // [esp+88h] [ebp-30h]
  int v36; // [esp+8Ch] [ebp-2Ch]
  int v37; // [esp+90h] [ebp-28h]
  int v38; // [esp+94h] [ebp-24h]
  int v39; // [esp+98h] [ebp-20h]
  int v40; // [esp+9Ch] [ebp-1Ch]
  double v41; // [esp+A0h] [ebp-18h]
  _DWORD v42[4]; // [esp+A8h] [ebp-10h] BYREF

  if ( a2 > 0.0 )
    a2 = -a2;
  v5 = a3;
  if ( a3 >= 0.0 )
  {
    if ( a3 > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  this[4] = a4;
  v6 = 0;
  v7 = v15;
  do
  {
    v42[v6++] = v7;
    v7 += 10;
  }
  while ( v6 < 4 );
  v41 = a4 * a4;
  memset(v15, 0, 28);
  v27 = v41 * a4;
  v28 = v41;
  v15[7] = 1072693248;
  v29 = a4;
  v16 = 0;
  v17 = 1072693248;
  v32 = v5;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v33 = v41 * 3.0;
  v23 = 1072693248;
  v24 = 0;
  v25 = 0;
  v26 = a2;
  v30 = 0;
  v34 = a4 + a4;
  v31 = 1072693248;
  v35 = 0;
  v36 = 1072693248;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  result = sub_579F40(v42, 4);
  if ( result )
  {
    *(_DWORD *)this = 0;
    *((_DWORD *)this + 1) = 0;
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 3) = 0;
    *((_DWORD *)this + 4) = 0;
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 7) = 1072693248;
  }
  else
  {
    v9 = v17;
    v10 = LODWORD(v26);
    *(_DWORD *)this = v16;
    v11 = HIDWORD(v26);
    *((_DWORD *)this + 1) = v9;
    v12 = LODWORD(v32);
    *((_DWORD *)this + 2) = v10;
    v13 = HIDWORD(v32);
    *((_DWORD *)this + 3) = v11;
    v14 = v39;
    *((_DWORD *)this + 4) = v12;
    result = v40;
    *((_DWORD *)this + 5) = v13;
    *((_DWORD *)this + 6) = v14;
    *((_DWORD *)this + 7) = result;
  }
  return result;
}
